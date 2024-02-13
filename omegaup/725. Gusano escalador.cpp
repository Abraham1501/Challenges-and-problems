#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, u, d, acum = 0;
    cin>>n>>u>>d;
    while(n != 0){
        n = n - u;
        acum++;
        if(n <= 0){
            break;
        }
        else{
          n = n + d;
          acum++;
        }
    }
    cout<<acum;
    return 0;
}