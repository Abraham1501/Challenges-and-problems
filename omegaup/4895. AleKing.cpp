#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	int N, T, may=0;
	cin>>N;
	int arr[N];
	for(int i=0; i<N; i++){
		cin>>arr[i];
	}
	cin>>T;
	if(T == 1){
		for(int i=N-1; i>-1; i--){
			cout<<arr[i]<<" ";
		}
	}
	else{
		if(T==2){
			for(int i=0; i<N; i++){
				cout<<arr[i]<<" ";
			}	
		}
		else{
			for(int e=0; e<N; e++){
				for(int i=0; i<N; i++){
					if(may < arr[i] && arr[i] != 0){
						may = arr[i];
					}
				}
				cout<<may<<" ";
				for(int i=0; i<N; i++){
					if(may == arr[i]){
						arr[i] = 0;
					}
				}
				may=0;
			}
		}
	}
    return 0;
}