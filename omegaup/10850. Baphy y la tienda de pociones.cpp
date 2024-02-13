#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
    int n, k, a, N = 0;
    cin>>n>>k;
    priority_queue <long long int> arr;
    for(int i=0; i<n; i++){
        cin>>a;
        a = a * (-1);
        arr.push(a);
    }
    while(arr.size() != 0 && ((-1) * (arr.top())) <= k){
        k = k + arr.top();
        arr.pop();
        N++;
    }
    cout<<N;
    return 0;
}