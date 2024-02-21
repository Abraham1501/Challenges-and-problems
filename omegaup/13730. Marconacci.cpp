#include <iostream>
#include <queue>

using namespace std;

int main()
{
    long long int f1, f2, pos, can1, can2, N, total, reu;
    cin>>N;
    long long int sec[1000002];
    sec[0] = 0;
    sec[1] = 1;
    for(long long int i=2; i<1000002; i++){
        sec[i] = sec[i-1] + sec[i-2];
        sec[i] = sec[i]%1000000007;
    }
    for(long long int i=0; i<N; i++){
        cin>>f1>>f2>>pos;
        if(pos == 1){
            cout<<f1;
        }
        else{
            if(pos == 2){
                cout<<f2;
            }
            else{
                can1 = (sec[pos - 2] * f1);
                can2 = (sec[pos - 1] * f2);
                total = can1 + can2;
                reu = total%1000000007;
                cout<<reu<<endl;
            }
        }
    }
    return 0;
}