#include <iostream>
#include "../Headers/Graph.hpp"
#include "../Headers/AVLMap.hpp"
#include "../Headers/Sequence/LinkedListSeq.hpp"

using namespace std;

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

    // IncList<int, int> graph(imap);
    

    // delete imap;
    return 0;
}