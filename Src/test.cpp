#include <iostream>
#include "../Headers/Graph.hpp"
#include "../Headers/AVLMap.hpp"
#include "../Headers/Sequence/LinkedListSeq.hpp"

using namespace std;

void print_int_graph(const Graph<int, int>& g);
void print_list(const LinkedListSequence<Edge<int>>& lseq);

int cmp (const Pair<Vertex<int>, LinkedListSequence<Edge<int>>>& p1, const Pair<Vertex<int>, LinkedListSequence<Edge<int>>>& p2){
    return p1.GetKey().GetId() - p2.GetKey().GetId();
}

int cmpTE(const int& i1, const int& i2){
    return i1 - i2;
}

int main(){
    int a[] ={1,2,3,4,5,6,7,8,9};
    LinkedListSequence list(a, 9);

    Graph <int, int> g (cmp);

    Vertex<int> v1(1);
    Vertex<int> v2(2);
    Vertex<int> v3(3);
    Vertex<int> v4(4);
    Vertex<int> v5(5);

    Edge<int> e1(1, 1, 2, 1);
    Edge<int> e2(2, 2, 3, 1);
    Edge<int> e3(3, 3, 4, 1);
    Edge<int> e4(4, 4, 1, 1);
    Edge<int> e5(5, 1, 5, 100);

    g.AddSingleVertex(v1);
    g.AddSingleVertex(v2);
    g.AddSingleVertex(v3);
    g.AddSingleVertex(v4);
    g.AddSingleVertex(v5);
    g.AddEdge(1, e1);
    g.AddEdge(2, e2);
    g.AddEdge(3, e3);
    g.AddEdge(4, e4);
    g.AddEdge(1, e5);

    print_int_graph(g);


    Sequence<int>* seq = g.GetVertexesIds();

    // for (int i = 0; i < seq->GetLength(); i++){
    //     cout << seq->Get(i) << endl;
    // }

    // g.Dijkstra(1, 5, 0, 999, cmpTE);
    OptimalWay<int>* way = g.Dijkstra(1, 5, 0, 999, cmpTE);
    // cout << "Length:" << g.Dijkstra(1, 5, 0, 999, cmpTE)->GetLength() << endl;
    // for (int i = 0; i < g.Dijkstra(1, 5, 0, 999, cmpTE)->GetWay()->GetLength(); i++){
    //     cout << g.Dijkstra(1, 5, 0, 999, cmpTE)->GetWay()->Get(i) << '-';
    // }

    cout << way->GetLength() << endl;
    cout << way->GetWay()->GetLength() << endl;
    for (int i = 0; i < way->GetWay()->GetLength(); i++){
        cout << way->GetWay()->Get(i) <<  "-" ;
    }
    
    delete way;
    delete seq;
    return 0;
}

void print_int_graph(const Graph<int, int>& g){
    Sequence<int>* vId = g.GetVertexesIds();
    for (int i = 0; i < vId->GetLength(); i++){
        cout << "[" << vId->Get(i) << "]";
        cout << "--->";
        print_list(g.GetEdges(vId->Get(i)));
        cout << endl;
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

