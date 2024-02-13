#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

long long int n, N, num, Nu1, Nu2, lim;
string T;
priority_queue <long long int> Col;
vector <long long int> Num;

int main() {
    cin>>n;
    for(long long int i=0; i<n; i++){
        cin>>T;
        if(T == "R"){
            cin>>N;
            N = N * (-1);
            Col.push(N);
        }
        else{
            if(T == "S"){
                if(Col.size() >= 3){
                    cout<<abs(Col.top())<<" ";
                    Nu1 = Col.top();
                    Col.pop();
                    cout<<abs(Col.top())<<" ";
                    Nu2 = Col.top();
                    Col.pop();
                    cout<<abs(Col.top())<<endl,
                    Col.push(Nu2);
                    Col.push(Nu1);
                }
                else{
                    cout<<"NO HAY SUFICIENTES PUNTAJES"<<endl;
                }
            }
            else{
                if(Col.empty() == false && T == "B"){
                    Col.pop();
                }
            }
        }
    }
    if(Col.empty()){
        cout<<"NO HUBO GANADOR";
    }
    else{
        lim=Col.size();
        for(long long int i=0; i<lim-1; i++){
            Col.pop();
        }
        cout<<"El PUNTAJE MAS ALTO FUE "<<abs(Col.top());
    }
    return 0;
}