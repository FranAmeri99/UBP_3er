#include <iostream>
#include <vector>
using namespace std;

int fin = 99999 ;


void mostrar(vector<int> vector, int tamano);
void ordenar(vector<int> vector, int tamano);
int ran();

int main() {
    int x;
    cout<<"ingrese cuantos numeros va a cargar: \n";
    cin>>x;
    vector<int> vector(x);
    for (int i = 0; i < x ; ++i) {
        int aux =ran();
        vector[i]=aux;
        ordenar(vector,x);
  
    }
     
    return 0;
}

int ran(){

    int v2 = rand() % 10 + 1;

    return v2;
}

void mostrar(vector<int> vector, int tamano){
    cout<<endl;
    cout<<endl;

    for (int i = 0; i < tamano ; ++i) {
        if(vector[i]!=fin){
            cout<<"["<<vector[i]<<"] ";
        }
    }
    cout<<endl;
}

void ordenar(vector<int> vector, int x){
    int pos, aux;

    for (int i = 0; i < x ; ++i) {
        pos=i;
        aux=vector[i];
        while ((pos>0)&&(vector[pos-1]>aux)){
            vector[pos]=vector[pos-1];
            pos--;
        }
        vector[pos]=aux;
    }
    mostrar(vector,x);
}
