#pragma once
#include <iostream>
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

    public:
        Edge(){}

        Edge(int index, int startId, int endId){
            this->id = index;
            this->startId = startId;
            this->endId = endId;
        }

         Edge(int index, int startId, int endId, const T& data){
            this->id = index;
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
class OptimalPath{
    private:
        TE length;
        Sequence<int>* way;

    public:
        OptimalPath(){}

        OptimalPath(Sequence<int>* way, TE length){
            this->length = length;
            this->way = way;

        }

        ~OptimalPath(){
            delete way;
        }

        const TE& GetLength() const {
           return length; 
        }
        
        Sequence<int>* GetWay(){
            return way;
        }
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
                adjVertSeq->Append(map->Get(vertex).Get(i).GetEndId());

            return adjVertSeq;
        }

        const TE& GetEdgeData(int startVertexId, int endVertexId){
            Vertex<TV> vertex(startVertexId);
            int res = 0;
            for (int i = 0; i < map->Get(vertex).GetLength(); i++){
                if (endVertexId == map->Get(vertex).Get(i).GetEndId()){
                    res = i;
                }
            }
            return map->Get(vertex).Get(res).GetData();
        }



        void relax(Sequence<TE>* s, Sequence<int>* p,int u, int v, int w, int (*cmpTE)(const TE&, const TE&)){
            if (cmpTE(s->Get(v), s->Get(u) + w) > 0){
                s->Set(v, s->Get(u) + w);
                p->Set(v, u);
            }
        }

        OptimalPath<TE>* Dijkstra(int vertexStartId, int vertexEndId ,const TE& NILL ,const TE& INF, int (*cmpTE)(const TE&, const TE&)){   
            int vertexesQty = GetVertexesQty();

            Sequence<TE>* s = new ArraySequence<TE>();
            Sequence<int>* p = new ArraySequence<int>();
            Sequence<bool>* used = new ArraySequence<bool>();

            //INIT
            for (int i = 0; i < vertexesQty; i++){
                s->Append(INF);
                p->Append(-1);
                used->Append(false);
            }

            s->Set(vertexStartId - 1, NILL); //Start point
            p->Set(vertexStartId-1, vertexStartId-1);
            //
            int v = 0;
            for (int i = 0; i < vertexesQty; i++){
                v = -1;
                for (int j = 0; j < vertexesQty; j++){
                    if (!(used->Get(j)) && (v==-1 || cmpTE(s->Get(j), s->Get(v)) < 0))
                        v = j;
                }

                if (s->Get(v) == INF) break;
                used->Set(v, true);

                Sequence<int>* adjVertexes = GetAdjVertIds(v+1);
                for (int i = 0; i < adjVertexes->GetLength(); i++){
                    relax(s, p, v, adjVertexes->Get(i) - 1, GetEdgeData(v+1, adjVertexes->Get(i)), cmpTE);
                }
            delete adjVertexes;
            }

            int curr = vertexEndId - 1;
            Sequence<int>* out = new ArraySequence<int>;

            while (curr != vertexStartId - 1){

        
                out->Append(curr+1);
                curr = p->Get(curr);

            }
            out->Append(vertexStartId);

            

            OptimalPath<TE>* res = new OptimalPath<TE>(out, s->Get(vertexEndId-1));

            delete p; 
            delete s; 
            delete used;

            return res;
}

    Sequence<Sequence<int>*>* GetConnectedComponents(){

        Sequence<Sequence<int>*>* result = new ArraySequence<Sequence<int>*>();
        Sequence<bool>* checkedVertexesIds = new ArraySequence<bool>();

        for (int i = 0; i < GetVertexesQty(); i++){
            checkedVertexesIds->Append(false);
        }

        while(checkedVertexesIds->Contains(false)){
            Sequence<int>* conComponent = new ArraySequence<int>();

            int uncheckedVertexId = checkedVertexesIds->IndexOf(false) + 1;
            checkedVertexesIds->Set(uncheckedVertexId-1, true);

            LinkedListSequence<int> queue;
            queue.Append(uncheckedVertexId);
            
            while(queue.GetLength()){

                Sequence<int>* adjVertexes = GetAdjVertIds(queue.Get(0));
                for (int i = 0; i < adjVertexes->GetLength(); i++){
                    if (!checkedVertexesIds->Get(adjVertexes->Get(i) - 1)){
                        queue.Append(adjVertexes->Get(i));
                        checkedVertexesIds->Set(adjVertexes->Get(i)-1, true);
                    }
                }
                conComponent->Append(queue.Get(0));
                queue.Delete(0);
                delete adjVertexes;

            }

            result->Append(conComponent);
        }
        delete checkedVertexesIds;
        return result;

        
        

    }

    

};

