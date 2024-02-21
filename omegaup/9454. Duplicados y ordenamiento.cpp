#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, pos = 0, A = 0, B = 1, num = 0, num2, Num;
	cin>>n;
	int arr[n];
	int arr2[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		arr2[i] = 0;
	}
	for(int i=0; i<n; i++){
		num = arr[i];
		for(int e=0; e<n; e++){
			num2 = arr2[e];
			arr2[e] = num;
			num = num2;
		}
		A = 0;
		B = 1;
		while(arr2[A] > arr2[B]){
			if(arr2[A] == 0 || arr2[B] == 0){
				break;
			}
			Num = arr2[A];
			arr2[A] = arr2[B];
			arr2[B] = Num;
			B++;
			A++;
		}
	}
	for(int i=0; i<n; i++){
		if(arr2[i] ==  -1){
			pos = 1;
			break;
		}
		for(int e=i + 1; e<n; e++){
			if(arr2[i] == arr2[e]){
				arr2[e] = -2;
			}
		}
	}
	if(pos == 0){
		for(int i=0; i<n; i++){
			if(arr2[i] != -2){
				cout<<arr2[i]<<endl;
			}
		}
	}
    return 0;
}