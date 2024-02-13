#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, posT=0, posA=0, pA=0, pT=0;
	cin>>N;
	string pri,seg, nombre;
	vector <string> T;
	vector <string> A;
	for(int i=0; i<N; i++){
		cin>>pri;
		if(pri == "LLEGA"){
			cin>>seg;
			if(seg == "ALUMNO"){
				cin>>nombre;
				A.push_back(nombre);
				pA++;
				
			}
			else{
				cin>>nombre;
				T.push_back(nombre);
				pT++;
			}
		}
		else{
			if(posT == pT){
				cout<<A.at(posA)<<endl;
				posA++;
			}
			else{
				cout<<T.at(posT)<<endl;
				posT++;
			}
		}
	}
    return 0;
}