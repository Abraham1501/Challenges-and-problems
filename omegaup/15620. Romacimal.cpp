#include <iostream>
#include <queue>
using namespace std;

int main() {
  	int acum = 0, num = 0, A, B;
	acum = 0;
	string Letras;
	Letras = "IVXLCDM";
	int arrLetras[7] = {1, 5, 10, 50, 100, 500, 1000};
	string Numero;
	cin>>Numero;
	int arrNumero[Numero.size()];
	for(int i=0; i<Numero.size(); i++){
		for(int e=0; e<7; e++){
			if(Numero[i] == Letras[e]){
				arrNumero[i] = arrLetras[e];
				break;
			}
		}
	}
	for(int i=Numero.size()-1; i>=0; i--){
		if(arrNumero[i] < num){
			acum = acum - arrNumero[i];
		}
		else{
			num = arrNumero[i];
			acum = acum + arrNumero[i];
		}
	}
	cout<<acum;
  return 0;
}