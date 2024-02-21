#include <iostream>
#include <queue>
using namespace std;

int main(){
	int N, M, total, num, num2, x, y, inix, iniy, col, row, pos, p;
	bool stop = true;
	cin>>N>>M;
	total = N*M;
	int arry[total];
	int arryF[total];
	for(int i=0; i<total; i++){
		cin>>arry[i];
	}
	inix = 0;
	iniy = 0;
	col = M - 1;
	row = N - 1;
	x=inix;
	y=iniy;
	num=arry[0];
	while(stop){
		while(x<=col){
			pos = (y * M) + x;
			num2 = arry[pos];
			arry[pos] = num;
			num = num2;
			x++;
		}
		x--;
		y++;
		while(y<=row){
			pos = (y * M) + x;
			num2 = arry[pos];
			arry[pos] = num;
			num = num2;
			y++; 
		}
		y--;
		x--;
		while(x>=inix){
			pos = (y * M) + x;
			num2 = arry[pos];
			arry[pos] = num;
			num = num2;
			x--; 
		}
		x++;
		y--;
		while(y>=iniy){
			pos = (y * M) + x;
			num2 = arry[pos];
			arry[pos] = num;
			num = num2;
			y--; 
		}
		inix++;
		iniy++;
		col--;
		row--;
		x=inix;
		y=iniy;
		if(col <= inix || row <= iniy){
			break;
		}
		else{
			if(col == inix && row == iniy){
				break;
			}
		}
		num=arry[(y * N) + x];
	}
	p = 0;
	for(int i=0; i<N; i++){
		for(int e=0; e<M; e++){
			cout<<arry[p]<<" ";
			p++;
		}
		cout<<endl;
	}
    return 0;
}