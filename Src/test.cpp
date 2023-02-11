#include <iostream>
#include "../Headers/Graph.hpp"
#include "../Headers/AVLMap.hpp"
#include "../Headers/Sequence/LinkedListSeq.hpp"

using namespace std;

void print_int_graph(const Graph<int, int>& graph);
void print_list(const LinkedListSequence<Edge<int>>& lseq);
void print_list_int(const LinkedListSequence<int>& lseq);
void print_seq(Sequence<int>* seq);
void print_seqseq(const Sequence<Sequence<int>*>* seq);

int cmp (const Pair<Vertex<int>, LinkedListSequence<Edge<int>>>& p1, const Pair<Vertex<int>, LinkedListSequence<Edge<int>>>& p2){
    return p1.GetKey().GetId() - p2.GetKey().GetId();
}

int cmpTE(const int& i1, const int& i2){
    return i1 - i2;
}

int test2(){

    Graph <int, int> graph (cmp);

    Vertex<int> v1(1);
    Vertex<int> v2(2);
    Vertex<int> v3(3);
    Vertex<int> v4(4);
    Vertex<int> v5(5);

    Edge<int> e1(1, 1, 2, 1);
    Edge<int> e2(2, 2, 3, 2);
    Edge<int> e3(3, 3, 4, 1);
    Edge<int> e4(4, 4, 1, 1);
    Edge<int> e5(5, 1, 5, 100);

    graph.AddSingleVertex(v1);
    graph.AddSingleVertex(v2);
    graph.AddSingleVertex(v3);
    graph.AddSingleVertex(v4);
    graph.AddSingleVertex(v5);
    graph.AddEdge(1, e1);
    graph.AddEdge(2, e2);
    graph.AddEdge(3, e3);
    graph.AddEdge(4, e4);
    // graph.AddEdge(1, e5);

    print_int_graph(graph);


    Sequence<int>* seq = graph.GetVertexesIds();

    Sequence<Sequence<int>*>*  cc = graph.GetConnectedComponents();
    print_seqseq(cc);

    for (int i = 0; i < cc->GetLength(); i++){
        delete  cc->Get(i);
    }
    delete cc;
    // delete way;
    delete seq;
    return 0;
}

int test1(){
    Graph <int, int> graph (cmp);

    Vertex<int> v1(1);
    Vertex<int> v2(2);
    Vertex<int> v3(3);
    Vertex<int> v4(4);
    Vertex<int> v5(5);

    Edge<int> e1(1, 1, 2, 1);
    Edge<int> e2(2, 2, 3, 2);
    Edge<int> e3(3, 3, 4, 1);
    Edge<int> e4(4, 4, 1, 1);
    Edge<int> e5(5, 1, 5, 100);

    graph.AddSingleVertex(v1);
    graph.AddSingleVertex(v2);
    graph.AddSingleVertex(v3);
    graph.AddSingleVertex(v4);
    graph.AddSingleVertex(v5);
    graph.AddEdge(1, e1);
    graph.AddEdge(2, e2);
    graph.AddEdge(3, e3);
    graph.AddEdge(4, e4);
    graph.AddEdge(1, e5);

    print_int_graph(graph);

    return 0;
}


int test3(int startId, int endId){

    Graph <int, int> graph (cmp);

    Vertex<int> v1(1);
    Vertex<int> v2(2);
    Vertex<int> v3(3);
    Vertex<int> v4(4);
    Vertex<int> v5(5);

    Edge<int> e1(1, 1, 2, 1);
    Edge<int> e2(2, 2, 3, 2);
    Edge<int> e3(3, 3, 4, 1);
    Edge<int> e4(4, 4, 1, 1);
    Edge<int> e5(5, 1, 5, 100);

    graph.AddSingleVertex(v1);
    graph.AddSingleVertex(v2);
    graph.AddSingleVertex(v3);
    graph.AddSingleVertex(v4);
    graph.AddSingleVertex(v5);
    graph.AddEdge(1, e1);
    graph.AddEdge(2, e2);
    graph.AddEdge(3, e3);
    graph.AddEdge(4, e4);
    graph.AddEdge(1, e5);

    print_int_graph(graph);

    OptimalPath<int>* way = graph.Dijkstra(startId, endId, 0, 1000000, cmpTE);

    cout << "Length: " << way->GetLength() << endl;
    cout << "Route: ";
    print_seq(way->GetWay());


    delete way;
    return 0;
}


void print_int_graph(const Graph<int, int>& graph){
    Sequence<int>* vId = graph.GetVertexesIds();
    cout << endl;
    for (int i = 0; i < vId->GetLength(); i++){
        cout << "[" << vId->Get(i) << "]";
        cout << "--->";
        print_list(graph.GetEdges(vId->Get(i)));
        cout << endl << endl;
    }
    delete vId;
}

void print_list(const LinkedListSequence<Edge<int>>& lseq){
    // cout << lseq.GetLength() << endl;
    if (lseq.GetLength() == 0) {cout << "[NULL]"; return;}





    else {
        cout << "[ ";
            for (int i = 0; i < lseq.GetLength(); i++) {
                cout << "(" << lseq.Get(i).GetStartId() << ","<< lseq.Get(i).GetEndId() << "," << lseq.Get(i).GetData() << ") " ;
            }
        cout << "]" << endl;
    }
}

void print_list_int(const LinkedListSequence<int>& lseq){
    // cout << lseq.GetLength() << endl;
    if (lseq.GetLength() == 0) {cout << "[NULL]"; return;}
    else {
        cout << "[ ";
            for (int i = 0; i < lseq.GetLength(); i++) {
                cout <<lseq.Get(i)  << " " ;
            }
        cout << "]" << endl;
    }
}

void print_seq(Sequence<int>* seq) {
    if (seq->GetLength() == 0) {
        cout << "NULL" << endl;
        return;
    }
        cout << "{";
        for (int i = 0; i < seq->GetLength(); i++){
            cout << seq->Get(i) << " ";
        }
        cout << "}" << endl;
}
void print_seqseq(const Sequence<Sequence<int>*>* seq) {
    if (seq->GetLength() == 0) {
        cout << "NULL" << endl;
        return;
    }
    for (int i = 0; i < seq->GetLength(); i++){
        print_seq(seq->Get(i));
    }
}

