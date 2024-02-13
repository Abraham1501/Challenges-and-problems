#include <iostream>
#include <queue>
#include <bits/stdc++.h>
#include <vector>
#include<algorithm>


using namespace std;

long long int n, m, T, acum=0, i;
bool pas = true;
vector<long long int> A;
vector<long long int> B;

int main(){
    cin>>n>>m;
    for(i=0; i<n; i++){
        cin>>T;
        A.push_back(T);
    }
    for(i=0; i<m; i++){
        cin>>T;
        B.push_back(T);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(i=0; i<m; i++){
        if(binary_search(A.begin(), A.end(), B.at(i))){
            pas = true;
        }
        else{
            pas = false;
            break;
        }
    }
    if(pas == true){
        cout<<"Si";
    }
    else{
        cout<<"No";
    }
    return 0;
}