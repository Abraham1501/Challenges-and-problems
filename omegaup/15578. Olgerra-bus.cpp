#include <iostream>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  int N=0, D=0, E=0, E2 = 0, posicion=0, subarr=0, Reu=0, D2=0;
  posicion = 0;
  N=0;
  D=0;
  std::cin>>N>>D;
  int Arr1[N];
  for(int i=0; i<N; i++){
    std::cin>>Arr1[i];
  }
  Reu % N / D;
  subarr=((N - Reu)/D) + 1;
  E2 = N;
  for(int e=0; e<subarr; e++){
    E = 0;
    for(int i =0; i < D; i++){
      if(E2 != 0){
        E2--;
        E++;
      }
      else{
        break;
      }
    }

    int ArrFinal[E];
    int ArrV[E];
    for(int i=0; i<E; i++){
        ArrFinal[i] = Arr1[posicion];
      posicion++;
    }
    for(int i=0; i<E; i++){
      ArrV[i]=ArrFinal[i];
    }
    D2 = E - 1;
    for(int i=0; i<E; i++){
      ArrFinal[i]=ArrV[D2];
      D2--;
    }
    for(int i= 0; i<E; i++){
        std::cout<<ArrFinal[i]<<" ";
    }
    for(int i=0; i<E; i++){
        ArrFinal[i] = 0;
        ArrV[i] = 0;
    }
  }

  return 0;
}