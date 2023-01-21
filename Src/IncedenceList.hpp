#pragma once
#include "../Headers/AVLMap.hpp"
#include "../Headers/Sequence/LinkedList.hpp"

template <class T>
class Edge{
    private:
        // int id
        T weight;
        T data; 
        Edge* start,
        Edge* end;
};

template <class T>
class Vertex{
    private:
        // int id;

};

template <class TVertex, class TEdge >
class IncList{
    private:
        Sequence<IMap<TVertex, LinkedListSeq<TEdge>>> map;
    public:

};

template<class TVertex, class TEdge>
class OrGrapgh{
    private:
        IncList<TVertex, TEdge> inclist;

    public:


};

