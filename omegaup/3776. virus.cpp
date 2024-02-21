#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int pos=0;
    string vir, dan;
    string A = {'a','b','c','d','e','f','g','h','i','j','k','l',
    'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cin>>dan>>vir;
    int virN[vir.size()];
    int danN[dan.size()];
    for(int i=0; i<vir.size(); i++){
        for(int e=0; e<A.size(); e++){
           if(vir[i] == A[e]){
                virN[i] = e+1;
                break;
           }
        }
    }
    for(int i=0; i<dan.size(); i++){
        for(int e=0; e<A.size(); e++){
           if(dan[i] == A[e]){
                danN[i] = e+1;
                break;
           }
        }
    }
    for(int i=0; i<dan.size(); i++){
            danN[i] = danN[i] - virN[pos];
            if(danN[i] < 1){
                danN[i] = 26 + (danN[i]);
            }
            pos++;
            if(pos > vir.size()- 1){
                pos=0;
            }
    }
    for(int i=0; i<dan.size(); i++){
        dan[i] = A[danN[i] - 1];
    }
    cout<<dan;
    return 0;
}