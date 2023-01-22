#pragma once
#include <iostream>
#include "../Headers/Graph.hpp"
#include "../Headers/AVLMap.hpp"
#include "../Headers/Sequence/LinkedListSeq.hpp"


void print_int_graph(const Graph<int, int>& graph);
void print_list(const LinkedListSequence<Edge<int>>& lseq);
void print_list_int(const LinkedListSequence<int>& lseq);
void print_seq(Sequence<int>* seq);
void print_seqseq(const Sequence<Sequence<int>*>* seq);
int cmp (const Pair<Vertex<int>, LinkedListSequence<Edge<int>>>& p1, const Pair<Vertex<int>, LinkedListSequence<Edge<int>>>& p2);
int cmpTE(const int& i1, const int& i2);
int test2();
int test1();
int test3(int startId, int endId);