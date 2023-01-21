#pragma once
#include "../Headers/AVLMap.hpp"
#include "../Headers/Sequence/LinkedList.hpp"

template <class T>
class Edge{
    private:
        int id
        T weight;
        T data; 
        Edge* start,
        Edge* end;

    public:
        int GetId() const {
            return id;
        }

        const T& GetData() const {
            return data;
        }

};

template <class T>
class Vertex{
    private:
        int id;

    public:

    int GetId() const {
        return id;
    }


};

template <class TVertex, class TEdge >
class IncList{
    private:
        IMap<TVertex, LinkedListSeq<TEdge>> map;
    public:

};

template<class TVertex, class TEdge>
class OrGrapgh{
    private:
        IncList<TVertex, TEdge> inclist;

    public:
        OrGrapgh(){
            
        }


};

