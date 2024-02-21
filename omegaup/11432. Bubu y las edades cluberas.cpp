#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	int n, pos=0, A = 0, B= 1, num, num2, pa=5;
	bool pas = true;
	vector <int> arry;
	arry.push_back(0);
	string a;
	while(cin>>n){
		pas = true;
		for(int i=0; i<arry.size(); i++){
			if(n == arry.at(i)){
				pas = false;
				break;
			}
		}
		if(pas == true){
			arry.push_back(n);
		}
	}
	int arrf[arry.size()];
	arrf[0] = 0;
	num = 0;
	for(int i=0; i<arry.size(); i++){
		for(int e=0; e<arry.size(); e++){
			num2 = arrf[e];
			arrf[e] = num;
			num = num2;
		}
		arrf[0] = arry.at(i);
		while(arrf[A] < arrf[B]){
			num = arrf[A];
			arrf[A] = arrf[B];
			arrf[B] = num;
			A++;
			B++;
		}
		A=0;
		B=1;
	}
	cout<<"[";
	for(int i=0; i<arry.size() - 2; i++){
		cout<<"'"<<arrf[i]<<"', ";
	}
	cout<<"'"<<arrf[arry.size() - 2]<<"']";
    return 0;
}