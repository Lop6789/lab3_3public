#include <iostream>
#include "../Headers/testHeaders.hpp"
#include "../Headers/test.hpp"

using namespace std;

int main(){
    int flag = 0;
    int res = 0;
    while (!flag){
        cout << "\nChoose action:\n1)Print Incedent Matrix\n2)Get Conneceted Components\n3)Find the shortest way by Dijkstra\n0)Exit\n\n";
        cin >> res;
        switch (res){
            case 1:{
                test1();
                break;
            }
            case 2:{
                test2();
                break;
            }
            case 3:{
                int startId, endId;
                cout << "Enter index of start Vertex: ";
                cin >> startId;
                cout << "Enter index of end Vertex: ";
                cin >> endId;
                test3(startId, endId);
                break;
            }

            case 0:{
                flag = 1;
                break;
            }
        }
    }
    return 0;
}
