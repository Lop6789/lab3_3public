#pragma once
#include "../Headers/AVLMap.hpp"
#include "../Headers/Pair.hpp"
#include "../Headers/Sequence/LinkedListSeq.hpp"

using namespace std;

template <class T>
class Edge{
    private:
        int id;
        T data; 
        int startId; 
        int endId;
        // Vertex* start;
        // Vertex* end;

    public:
        Edge(){}

        Edge(int index, int startId, int endId){
            this->id = id;
            this->startId = startId;
            this->endId = endId;
        }

         Edge(int index, int startId, int endId, const T& data){
            this->id = id;
            this->startId = startId;
            this->endId = endId;
            this->data = data;
        }

        int GetId() const {
            return id;
        }
        int GetStartId() const {
            return startId;
        }
        int GetEndId() const {
            return endId;
        }

        const T& GetData() const {
            return data;
        }

        bool operator ==(const Edge<T>& edge){
            if (id == edge.id) return true;
            else return false;
        }

        Edge& operator =(const Edge<T>& edge){
            id = edge.id;
            data = edge.data;
            startId = edge.startId; 
            endId = edge.endId;
            return *this;
        }

};

template <class T>
class Vertex{
    private:
        int id;
        T data;

    public:
    
    Vertex(){}

    Vertex(int id){this->id = id;}

    Vertex(int id, const T& data){
        this->id = id;
        this->data = data;
    }

    int GetId() const {
        return id;
    }

    bool operator ==(const Vertex& vertex){
        if (id == vertex.id) return true;
        else return false;
    }

    Vertex& operator =(const Vertex<T>& vertex){
        id = vertex.id;
        data = vertex.data;
        return *this;
    }

};

template<class TE>
class OptimalWay{
    private:
        TE weight;
        Sequence<int>* way;
};


template<class TV, class TE>
class Graph{
    private:
        IMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>* map;

    public:
        Graph(){}
        ~Graph(){delete map;}
        //Copying constructor;

        Graph(int(*cmp)(const Pair<Vertex<TV>, LinkedListSequence<Edge<TE>>>&, const Pair<Vertex<TV>, LinkedListSequence<Edge<TE>>>&)){
            map = new AVLMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>(cmp);
        }

        void AddSingleVertex(const Vertex<TV>& vertex){
            LinkedListSequence<Edge<TE>> clearlist;
            map->Add(vertex, clearlist);
        }

        void AddEdge(int vertexId, const Edge<TE>& edge){
            Vertex<TV> vertex(vertexId);
            map->Get(vertex).Append(edge);

            int startId = edge.GetEndId();
            int endId = edge.GetStartId();
            TE data = edge.GetData();

            Edge<TE> opposite_edge(vertexId ,startId, endId, data);
            Vertex<TV> opposite_vertex (opposite_edge.GetStartId());
            map->Get(opposite_vertex).Append(opposite_edge);
            
        }

        void Add(Pair<TV, TE> pair){
            map->Add(pair);
        }

        Sequence<int>* GetVertexesIds() const {
            Sequence<Vertex<TV>>* vertexes = map->GetKeys();
            Sequence<int>* vertexesIds = new ArraySequence<int>();
            
            for (int i = 0; i < vertexes->GetLength(); i++){
                vertexesIds->Append(vertexes->Get(i).GetId());
            }

            delete vertexes;
            return vertexesIds;
        }

        LinkedListSequence<Edge<TE>>& GetEdges(int vertexId) const {
            Vertex<TV> vertex(vertexId);
            return map->Get(vertex);
        }

        int GetVertexesQty() const {
            return map->GetSize();
        }



        Sequence<int>* GetAdjVertIds(int vertexId) const {
            Sequence<int>* adjVertSeq = new ArraySequence<int>;
            Vertex<TV> vertex(vertexId);
            
            for (int i = 0; i < map->Get(vertex).GetLength(); i++)
                adjVertSeq->Append(map->Get(vertex).Get(i).GetEdgeEndVertexId());

            return adjVertSeq;
        }

        const TE* GetEdgeData(int startVertexId, int endVertexId){
            Vertex<TV> vertex(startVertexId);
            int res = 0;
            for (int i = 0; i < map->Get(vertex).GetLength(); i++){
                if (endVertexId == map->Get(vertex).Get(i).GetEdgeVertexId()){
                    res = i;
                }
            }
            return map->Get(vertex).Get(res).GetEdgeData();
        }


        void relax(Sequence<int>* s, Sequence<int>* p,int u, int v, int w){
            if (s->Get(v) > s->Get(u) + w){
                s->Set(v, s->Get(u) + w);
                p->Set(v, u);
            }
        }

        OptimalWay<TE>* Dijkstra(int vertexStartId, const TE& INF){   
            int vertexesQty = GetVertexesQty();

            Sequence<int>* s = new ArraySequence<int>();
            Sequence<int>* p = new ArraySequence<int>();
            Sequence<int>* used = new ArraySequence<bool>();

            //INIT
            for (int i = 0; i < vertexesQty; i++){
                s->Append(INF);
                p->Append(-1);
                used->Append(false);
            }

            s->Set(vertexStartId - 1, 0); //Start point
            p->Set(vertexStartId-1, vertexStartId);
            //
            int v = 0;
            for (int i = 0; i < vertexesQty; i++){
                v = -1;
                for (int j = 0; j < vertexesQty; j++){
                    if (!(used->Get(j)) && (v==-1 || (s->Get(j) < s->Get(v))))
                        v = j;
                }

                if (s->Get(v) == INF) break;
                used->Set(v, true);

                Sequence<int>* adjVertexes = GetAdjVertIds(v+1);
                for (int i = 0; i < adjVertexes->GetLength(); i++){
                    relax(s, p, v, adjVertexes->Get(i) - 1, GetEdgeData(v+1, adjVertexes->Get(i)));
                }
    }


}
};

