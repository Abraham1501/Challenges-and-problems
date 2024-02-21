#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int acum = 0, n=0;
    int abeacum[26];
    string abecedario = "abcdefghijklmnopqrstuvwxyz";
    string abecedarioMayus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string palabra;
    vector <string> frase;
    for(int i=0; i<26; i++){
        abeacum[i] = 0;
    }
    while(cin>>palabra){
        acum = acum + palabra.size();
        frase.push_back(palabra);
    }
    for(int i=0; i<frase.size(); i++){
        palabra = frase.at(i);
        for(int e=0; e<palabra.size(); e++){
            for(int r=0; r<26; r++){
                if(abecedario[r] == palabra.at(e) || abecedarioMayus[r] == palabra.at(e)){
                    abeacum[r] = abeacum[r] + 1;
                }
            }
        }
    }
    for(int i=0; i<26; i++){
        cout<<abecedario[i]<<": "<<abeacum[i]<<endl;
    }
    return 0;
}