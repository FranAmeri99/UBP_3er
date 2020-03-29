#include <iostream>

using namespace std;

int fin = 99999 ;
void mostrar(int vector[], int tamano){
    cout<<endl;
    cout<<endl;

    for (int i = 0; i < tamano ; ++i) {
        if(vector[i]!=fin){
            cout<<"["<<vector[i]<<"] ";
        }
    }
    cout<<endl;
}

void ordenar(int vector[], int x){
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


/*
 void mostrar(int vector[], int tamano);
void ordenar(int vector[], int tamano);
*/
int main() {
    int x;
    cout<<"ingrese cuantos numeros va a cargar: \n";
    cin>>x;
    int vector[x];
    for (int i = 0; i < x ; ++i) {
        vector[i]=fin;

    }
    int y;
    for (int i = 0; i < x ; ++i) {
        cout<<"posisicon ["<<i<<"]\n";
        cin>>y;
        vector[i]=y;
        ordenar(vector,x);
    }
    cout<<"\n----------------------------------------------\n";
       return 0;
}


