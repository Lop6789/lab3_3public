#include <iostream>
#include "../Headers/testHeaders.hpp"
#include "../Headers/IncedenceList.hpp"

using namespace std;

int main(){
    int flag = 0;
    int res = 0;
    while (!flag){
        cout << "\nChoose action:\n1)Print Incedent Matrix\n2)Find Conneceted Components\n3)Find the shortest way by Dijkstra\n0)Exit\n\n";
        cin >> res;
        switch (res){
            case 1:{
                
                break;
            }
            case 2:{
                break;
            }
            case 3:{

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
