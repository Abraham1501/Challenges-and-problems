#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n, may = 0, pos;
    bool pas = true;
    cin>>n;
    int arr[n];
    vector <int> arry;
    arry.push_back(0);
    for(int i=0; i<n; i++){
    	cin>>arr[i];
    	pas=true;
    	for(int e=0; e<arry.size(); e++){
    		if(arr[i] == arry.at(e)){
    			pas = false;
    			break;
			}
		}
		if(pas == true){
			arry.push_back(arr[i]);
		}
	}
	int arrf[arry.size()];
	for(int i=0; i<arry.size(); i++){
		arrf[i] = 0;
		for(int e=0; e<n; e++){
			if(arry.at(i) == arr[e]){
				arrf[i] = arrf[i] + 1;
			}
		}
	}
	for(int i=0; i<arry.size(); i++){
		if(arrf[i] > may){
			may = arrf[i];
			pos=i;
		}
	}
	cout<<arry.at(pos);
    return 0;
}