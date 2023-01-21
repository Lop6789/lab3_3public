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

int main(){
    int a[] ={1,2,3,4,5,6,7,8,9};
    LinkedListSequence list(a, 9);
    // }
    // list.Delete(8);
    // list.Append(100);
    // list.print();
    // for (int i = 0; i < list.GetLength(); i++){
    //     cout << list.Get(i) << endl;
    // }


    //  IMap<int, LinkedList<int>>* imap = new AVLMap<int, int>(&cmp1);
    //  imap->Add(1,3);
    //  imap->Add(13,31);
    //  imap->Add(100,300);

    Graph <int, int> g (cmp);

    Vertex<int> v1(1);
    Vertex<int> v2(2);
    Vertex<int> v3(3);
    Vertex<int> v4(4);

    Edge<int> e1(1,2);
    Edge<int> e2(2,3);
    Edge<int> e3(3,4);
    Edge<int> e4(4,1);

    g.AddSingleVertex(1);
    g.AddSingleVertex(2);
    g.AddSingleVertex(3);
    g.AddSingleVertex(4);
    g.AddEdge(1, e1);
    g.AddEdge(1, e2);
    g.AddEdge(2, e3);
    g.AddEdge(2, e4);

    print_int_graph(g);


    // g.AddSingleVertex(v1);

    Sequence<int>* seq = g.GetVertexesIds();

    for (int i = 0; i < seq->GetLength(); i++){
        cout << seq->Get(i) << endl;
    }




    // IncList<int, int> graph(imap);
    

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
    if (lseq.GetLength() == 0) {cout << "[NULL]"; return;}
    else {
        cout << "[ ";
            for (int i = 0; i < lseq.GetLength(); i++) {
                cout << lseq.Get(i).GetStartId() << " "<< lseq.Get(i).GetEndId() << " ";
            }
        cout << "]" << endl;
    }
}