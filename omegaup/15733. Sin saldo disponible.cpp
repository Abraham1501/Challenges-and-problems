#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, M, num;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>num;
        if(M>=num){
            M = M - num;
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    return 0;
}