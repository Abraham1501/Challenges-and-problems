#include <iostream>
#include <queue>
using namespace std;


int main()
{
  int n, acum =0, pos = 1;
  cin>>n;
  while(pos <= n){
    acum = acum + ((pos * (pos+1))/2);
    pos++;
  }
  cout<<acum;
  return 0;
}