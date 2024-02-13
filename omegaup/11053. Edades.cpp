#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int N, num, num2, A=0, B=1, pri, acum=0, pos=0;
	cin>>N;
	int arr[N];
	for(int i=0; i<N; i++){
		arr[i] = 0;
	}
	for(int i=0; i<N; i++){
		num = 0;
		for(int e=0; e<N; e++){
			num2 = arr[e];
			arr[e] = num;
			num = num2;	
		}
		cin>>num;
		arr[0] = num;
		while(arr[A] > arr[B] && arr[A] !=0 && arr[B] != 0){
			num = arr[A];
			arr[A] = arr[B];
			arr[B] = num;
			A++;
			B++;
		}
		A=0;
		B=1;
	}
	for(int i=0; i<N; i++){
		if(arr[i] != 0){
			pri = arr[i];
			arr[i] = 0;
			pos = i +1;
			while(arr[pos] == pri){
				arr[pos] = 0;
				acum++;
				pos++;
			}
			cout<<pri<<" "<<acum+1<<endl;
			acum = 0;
		}
		
	}
    return 0;
}