#pragma once
#include "../Headers/AVLMap.hpp"
#include "../Headers/Pair.hpp"
#include "../Headers/Sequence/LinkedListSeq.hpp"

using namespace std;

template <class T>
class Edge{
    private:
        int id;
        T weight;
        T data; 
        // Vertex* start;
        // Vertex* end;
        int startId; int endId;

    public:
        int GetId() const {
            return id;
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
            weight = edge.weight;
            data = edge.data;
            startId = edge.startId; endId = edge.endId;
            return *this;
        }

};

template <class T>
class Vertex{
    private:
        int id;

    public:
    
    Vertex(){}

    Vertex(int id){this->id = id;}

    int GetId() const {
        return id;
    }

    bool operator ==(const Vertex& vertex){
        if (id == vertex.id) return true;
        else return false;
    }

    Vertex& operator =(const Vertex<T>& vertex){
        id = vertex.id;
        return *this;
    }

};

// template <class TV, class TE>
// class IncList{
//     private:
//         IMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>* map;
//     public:

//         IncList(){map=nullptr;}

//         IncList(IMap<Vertex<TV>, LinkedListSequence<TE>>* map){
//             this->map = map;
//         }

//         void Add(const Pair<TV, TE>& pair){
//             map->Add(pair);
//         }

// };
// template<class TV, class TE>
// class OrGrapgh{
//     private:
//         IncList<TV, TE> inclist;

//     public:
//         // OrGrapgh(IMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>* map) : inclist(map) {}
//         OrGrapgh();

//         void Add(Pair<TV, TE> pair){
//             inclist->Add(pair);
//         }
// };

template<class TV, class TE>
class Graph{
    private:
        IMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>* map;

    public:
        Graph(){}
        ~Graph(){delete map;}
        //Copying constructor;


      // OrGrapgh(IMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>* map) : inclist(map) {}
        Graph(int(*cmp)(const Pair<Vertex<TV>, LinkedListSequence<Edge<TE>>>&, const Pair<Vertex<TV>, LinkedListSequence<Edge<TE>>>&)){
            map = new AVLMap<Vertex<TV>, LinkedListSequence<Edge<TE>>>(cmp);
        }

        void AddVertex(const Vertex<TV>&){
            // Pair<>
        }

        void Add(Pair<TV, TE> pair){
            map->Add(pair);
        }
};
