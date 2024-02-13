#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int p = 0, a, b;
    char l;
    char cadI[10] = {'0','1','2','3','4','5','6','7','8','9',};
    vector <int> arr;
    vector <int> arrP;
    arr.push_back(0);
    arrP.push_back(0);
    arr.push_back(0);
    arrP.push_back(0);
    while(cin>>l){
        if(l == '('){
            arr.push_back(0);
            arrP.push_back(0);
        }
        else{
            if(l == ')'){
                a = arr.back()/arrP.back();
                arr.pop_back();
                b = arr.back();
                arr.pop_back();
                arr.push_back(a + b);
                arrP.pop_back();
                b = arrP.back();
                arrP.pop_back();
                arrP.push_back(b+1);
            }
            else{
                for(int i=0; i<10; i++){
                    if(l == cadI[i]){
                        a = arr.back() + i;
                        arr.pop_back();
                        arr.push_back(a);
                        a = arrP.back() + 1;
                        arrP.pop_back();
                        arrP.push_back(a);
                    }
                }
            }
        }
    }
    a = arr.back()/arrP.back();
    cout<<a;
    return 0;
}