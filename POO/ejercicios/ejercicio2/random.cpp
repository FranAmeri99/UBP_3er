#include <iostream>

using namespace std;
int ran();


int main(){



        for(int i=0; i<20; i++){

            int v2 = ran();
            cout<<v2<<" - ";


    }


return 0;


}


int ran(){



    int v2 = rand() % 10 + 1;

    return v2;
}