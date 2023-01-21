#include <iostream>
#include "../Headers/IncedenceList.hpp"
#include "../Headers/AVLMap.hpp"
#include "../Headers/Sequence/LinkedListSeq.hpp"

using namespace std;

int cmp1 (const Pair<int, int>& p1, const Pair<int, int>& p2){
    return p1.GetKey() - p2.GetKey();
    }

int main(){
    int a[] ={1,2,3,4,5,6,7,8,9};
    LinkedListSequence list(a, 9);


    //  IMap<int, LinkedList<int>>* imap = new AVLMap<int, int>(&cmp1);
    //  imap->Add(1,3);
    //  imap->Add(13,31);
    //  imap->Add(100,300);

    

    // IncList<int, int> graph(imap);
    

    // delete imap;
    return 0;
}