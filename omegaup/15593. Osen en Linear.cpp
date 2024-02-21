#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int N, X, A, may, may2;
	cin>>N>>X;
	int arry[N];
	for(int i=0; i<N; i++){
		cin>>A;
		arry[i] = abs(X - A);
	}
	may=0;
	may2=0;
	for(int i=0; i<N; i++){
		if(arry[i] > may){
			if(may > may2){
				may2 = may;
			}
			may = arry[i];
		}
		else{
			if(arry[i] > may2){
				may2 = arry[i];
			}
		}
	}
	cout<<may + may2;
    return 0;
}