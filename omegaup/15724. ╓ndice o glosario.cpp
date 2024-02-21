#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int N, Y, n;
string T;
vector <string> P;
vector <int> Nu;
string abecedario = "abcdefghijklmnopqrstuvwxyz";

int main() {
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>T;
        P.push_back(T);
        cin>>Y;
        Nu.push_back(Y);
    }
    cin>>T;
    if(T == "g"){
        vector <string> P2(P);
        sort(P2.begin(), P2.end());
        for (int i=0; i<P2.size(); i++){
            cout<<P2[i]<<" ";
            for (int e=0; e<P.size(); e++){
                if(P2.at(i) == P.at(e)){
                    cout<<Nu[e]<<endl;
                    break;
                }
            }
        }
    }
    else{
        vector <int> Nu2(Nu);
        sort(Nu2.begin(), Nu2.end());
        for (int i=0; i<Nu2.size(); i++){
            for (int e=0; e<Nu.size(); e++){
                if(Nu2.at(i) == Nu.at(e)){
                    cout<<P[e]<<" ";
                    cout<<Nu2[i]<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}