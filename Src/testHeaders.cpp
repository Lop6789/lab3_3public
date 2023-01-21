#include <iostream>
#include "../Headers/AVLTree.hpp"
#include "../Headers/Pair.hpp"
#include "../Headers/AVLMap.hpp"
#include "../Headers/Range.hpp"

// using namespace std;

int cmp (const int& a, const int& b){
    return a - b;
}

int cmp1 (const Pair<int, int>& p1, const Pair<int, int>& p2){
    return p1.GetKey() - p2.GetKey();
    }
int cmps (const string& s1, const string& s2){
    return s1.length() - s2.length();
}

class Person{
    private:
        int age;
        string name;

    public:
        Person(){}
        Person(int age, string name){
            this->age = age; this->name = name;
        }
        ~Person(){}

        int GetAge() const {
            return age;
        }

        string GetName() const {
            return name;
        }
        
};
int cmpp(const Person& p1, const Person& p2){
    return p1.GetAge() - p2.GetAge();
}

int cmpp1 (const Pair<Person, Person>& p1, const Pair<Person, Person>& p2){
    return cmpp(p1.GetKey(), p2.GetKey());
    }

bool operator < (const Person& p1, const Person& p2){
        return cmpp(p1, p2);
    }


int test(){
    //AVLTREE//
    
    // AVLTree<Pair<int, int>> pairtree(cmp1);
    // Pair<int, int> p (1, 13);
    // pairtree.Add(p);
    // cout << pairtree.Get(p).GetElement() << endl;


    // AVLTree<Pair<Person, Person>> pirtree(cmpp1);
    // Person Iv(109, "Iv");
    // Person Da(18, "Da");
    // Person La(909, "La");
    // Person Kl(99, "kl");
    // Pair<Person, Person> p1 (Iv, Da);
    // Pair<Person, Person> p2 (La, Kl);
    // pirtree.Add(p1);
    // pirtree.Add(p2);
    // Sequence<Pair<Person, Person>>* pirseq = pirtree.ToSequence();
    // cout << "////////////////////////////////////////////////" << endl;
    // for(int i = 0; i<pirseq->GetLength(); i++){
    //     cout << pirseq->Get(i).GetKey().GetAge() << " " << pirseq->Get(i).GetKey().GetName() << " --- " << pirseq->Get(i).GetElement().GetAge() << " " << pirseq->Get(i).GetElement().GetName() << endl;  
    // }
    // cout << "///////////////////////////////////////////////////" << endl;
    // cout << pirtree.Get(p1).GetElement().GetName() << pirtree.Get(p2).GetElement().GetName() << endl;





    // AVLTree<int> tree = AVLTree<int>(cmp);
    // AVLTree<string> stree(cmps);
    // stree.Add("lol");
    // stree.Add("l");
    // stree.Add("coutcout");
    // Sequence<string>* sseq = stree.ToSequence();
    // sseq->print();

    // AVLTree<Person> ptree(cmpp);
    // Person Ivan(13, "Ivan");
    // Person Daniel(18, "Daniel");
    // ptree.Add(Ivan);
    // ptree.Add(Ivan);
    // ptree.Add(Daniel);
    // ptree.Remove(Ivan);
    // cout <<"\n\n\n"<< ptree.GetSize() << "\n\n\n" ;
    // Sequence<Person>* pseq = ptree.ToSequence();
    // cout << "Length: " <<pseq->GetLength() << endl;
    // cout << pseq->GetLast().GetAge() << endl;
    // string s = pseq->GetFirst().GetName();
    // string ss = pseq->GetLast().GetName();
    // cout << s << " "<<ss << pseq->Get(1).GetName() << endl; 
    // int s1 = pseq->GetFirst().GetAge();
    // int s2 = pseq->GetLast().GetAge();
    // cout <<"\t\t\t\t\t\t HERE IS AGES" << s1<< "\t" <<s2 << endl;
    

    // tree.Add(1);
    // tree.Add(2);
    // tree.Add(1000);
    // // for (int i =999 ; i < 9999; i++) tree.Add(i);
    // cout << tree.GetSize() << endl;
    // cout << tree.Get(1) << endl;
    // tree.Remove(1);
    // cout << tree.GetSize() << endl;
    // Sequence<int>* seq = tree.ToSequence();
    // seq->print();
    
    //Pair//
    // Pair<int, int> pair(1234348, 7327531);
    // Pair<int, int> pair1(123);
    // Pair<int, int> pair1 = Pair<int, int>(123);
    // cout << pair.GetKey() << " - " << pair.GetElement() << endl;
    // cout << pair1.GetKey() << endl;
    //
    //AVLMAP//
    // AVLMap<int, int> map(&cmp1);
    // map.Add(1,1);
    // map.Add(3,2);
    // map.Remove(1);
    // cout << map.GetSize() << endl;
    // cout << map.Get(3) << endl;
    //

    // IMap//
    IMap<int, int>* imap = new AVLMap<int, int>(&cmp1);
    cout << "\nAVLMap test" << endl;
    cout << "Creating pairs(13,133) and (31,100)" << endl;
    imap->Add(13,133);
    imap->Add(31,100);
    cout <<"Size: "<<imap->GetSize() << endl;
    cout << "Getting element with key=13:   " <<imap->Get(13) << endl;
    cout << "Getting element with key=31:   " <<imap->Get(31) << endl;


    //  
 
    //RANGE//
    // Range<int> rng1 (1, 2);
    // Range<int> rng2 (3, 5);
    // Range<int> rng3 (7, 9);
    // Sequence<Range<int>> *ptrng = new ArraySequence<Range<int>>;
    // ptrng->Append(rng1);
    // ptrng->Append(rng2);
    // ptrng->Append(rng3);

    // for (int i = 0; i < ptrng->GetLength(); i++)
    //     cout << ptrng->Get(i).GetStart() << "-" << ptrng->Get(i).GetEnd() << endl;  
    // delete ptrng;
    //OK//
    /////////
    



    return 0;
}