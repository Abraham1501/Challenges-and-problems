#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <stdio.h>
#include <algorithm>
using namespace std;

int row, col, num, exi=0;
vector <vector<int>> matriz;
vector <int> zapatos;
stack <pair<int,int>> pila;
pair <int, int> pos;
pair <int, int> poc;
vector<int>::iterator it;
bool matbool[52][52];

int mo[4][2]{
    {1,0},
    {-1,0},
    {0,1},
    {0,-1},
};

void allfalse(){
    for(int i=0; i<52; i++){
        for(int e=0; e<52; e++){
            matbool[i][e]=false;
        }
    }
};

void buscar(){
    pila.push(pos);
    while(pila.empty() != true){
        pos = pila.top();
        if(pos.first == row-1 && pos.second == col-1){
            break;
        }
        pila.pop();
        matbool[pos.first][pos.second] = true;
        for (it = zapatos.begin(); it!=zapatos.end(); ++it){
            for(int i=0; i<4; i++){
                poc.first = pos.first + mo[i][0];
                poc.second = pos.second + mo[i][1];
                if(poc.first > -1 && poc.first < row
                   && poc.second > -1 && poc.second <col){
                    if(matbool[poc.first][poc.second] == false
                       && matriz[poc.first][poc.second] == *it
                       && matriz[poc.first][poc.second] != exi){
                        matbool[poc.first][poc.second] = true;
                        pila.push(poc);
                    }
                }
            }
        }
    }
};

int main(){
    cin>>row>>col;
    for(int i=0; i<row; i++){
        vector<int> ma;
        for(int e=0; e<col; e++){
            cin>>num;
            ma.push_back(num);
        }
        matriz.push_back(ma);
    }
    pos.first = 0;
    pos.second = 0;
    allfalse();
    zapatos.push_back(matriz[pos.first][pos.second]);
    if(zapatos.at(0) != matriz[row-1][col-1]){
        zapatos.push_back(matriz[row-1][col-1]);
    }
    buscar();
    if(pos.first == row-1 && pos.second == col-1){
        cout<<zapatos.size();
        return 0;
    }
    else{
        if(zapatos.size() == 2){
            cout<<3;
        }
        else{
            allfalse();
            pos.first = 0;
            pos.second = 0;
            for(int i=1; i<=3; i++){
                if(i != zapatos.at(0)){
                    zapatos.push_back(i);
                    break;
                }
            }
            buscar();
            if(pos.first == row-1 && pos.second == col-1){
                cout<<zapatos.size();
                return 0;
            }
            else{
                allfalse();
                pos.first = 0;
                pos.second = 0;
                for(int i=1; i<=3; i++){
                    if(i != zapatos.at(0) && i != zapatos.at(1)){
                        zapatos.pop_back();
                        zapatos.push_back(i);
                        break;
                    }
                }
                buscar();
                if(pos.first == row-1 && pos.second == col-1){
                    cout<<zapatos.size();
                    return 0;
                }
                else{
                    cout<<3;
                }
            }
        }
    }
    return 0;
}