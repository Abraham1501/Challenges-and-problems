#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N,A, B, acum;
	std::cin>>N;
	int arr[N];
	for(int i=0; i<N; i++){
		std::cin>>arr[i];
	}
	std::cin>>A>>B;
	for(int i=0; i<N; i++){
		if(arr[i]<B || arr[i] == B){
			if(arr[i]>A || arr[i] == A)
				acum++;
		}
	}
	std::cout<<acum;

  return 0;
}