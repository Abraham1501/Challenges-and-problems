#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	int n, m, T;
	cin>>n>>m;
	int arr[m];
	for(int i=0; i<m; i++){
		arr[i] = 0;
	}
	for(int i=0; i<n; i++){
		cin>>T;
		arr[T-1] = arr[T-1] + 1;
	}
	for(int i=0; i<m; i++){
		cout<<i+1<<": "<<arr[i]<<endl;
	}
    return 0;
}