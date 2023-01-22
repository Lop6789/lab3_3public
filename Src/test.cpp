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

    Graph <int, int> g (cmp);

    Vertex<int> v1(1);
    Vertex<int> v2(2);
    Vertex<int> v3(3);
    Vertex<int> v4(4);

    Edge<int> e1(1, 1, 2, 0);
    Edge<int> e2(2, 2, 3, 0);
    Edge<int> e3(3, 3, 4, 0);
    Edge<int> e4(4, 4, 1, 0);

    g.AddSingleVertex(v1);
    g.AddSingleVertex(v2);
    g.AddSingleVertex(v3);
    g.AddSingleVertex(v4);
    g.AddEdge(1, e1);
    g.AddEdge(2, e2);
    g.AddEdge(3, e3);
    g.AddEdge(4, e4);

    print_int_graph(g);


    Sequence<int>* seq = g.GetVertexesIds();

    // for (int i = 0; i < seq->GetLength(); i++){
    //     cout << seq->Get(i) << endl;
    // }

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

// void init (int Vert){
    // for 
// }
// Sequence<int>* s;
// Sequence<int>* p;
// Sequence<bool>* used;
// // int s[] = {}
// // int d[] = {}; // расстояния 
// const int INF = 1000000;

// void Dijkstra(int vertexesQty, int vertexStartId){

//     s = new ArraySequence<int>();
//     p = new ArraySequence<int>();
//     used = new ArraySequence<bool>();
//     //INIT:
//     for (int i = 0; i < vertexesQty; i++){
//         s->Append(INF);
//         p->Append(-1);
//         used->Append(false);
//     }
//     s->Set(vertexStartId, 0);
//     p->Set(vertexStartId, vertexStartId);
//     //ALGO:

//     for (int i = 0; i < vertexesQty; i++){
//         int v = -1;
//         for (int j = 0; j < vertexesQty; j++){
//            if (!(used->Get(j)) && (v == -1 || (s->Get(j) < s->Get(v)))){
//                 v = j;
//            } 

//            if (s->Get(v) == INF) break;
//            used->Set(v, true);
//            //смежные вершины
//            //

//         }
//     }


// Sequence<int>* dist;
// Sequence<int>* p;
// Sequence<bool>* use;

// void  Dekstra(int vertexesQty, int vertexStartId, const Graph<int,int>& graph) {
//     dist = new ArraySequence<int>();
//     use = new ArraySequence<bool>();

//     for (int i = 0; i < vertexesQty; i++){
//         dist->Append(INF);
//         use->Append(false);
//     }

//     dist->Set(vertexStartId, 0);

//     for (int i = 0; i < vertexesQty; i++){
//         v = -1;
//         for (int j = 0; j < vertexesQty; j++){
//             if (!(use->Get(j)) && v==-1 || (dist->Get(j) < dist->Get(v)));
//                 v = j;
//         }
//         if (dist->Get(v) == INF) break;
//         use->Set(v, true);
        
        
//         Sequence<int>* adjVertexes = graph.GetAdjVert
//     }


// }