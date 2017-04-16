#include <iostream>
#include <cmath>
#include "inversa.h"
using namespace std;

int main() {
    Inversa inv;
             // LLENADO DEL JACOBIANO

for (int i =1; i<=3; i++){//NUMERO DE ITERACIONES
    inv.jacob();
    cout <<"Iteracion  : "<<i<<endl;
    cout << "-----------------------"<<endl;
    inv.todo();          // CALCULOS DE INVERSA
    cout << "-----------------------"<<endl;
    inv.ecuacion_o();    // SUSTITUCION DEL VECTOR INICIAL
    cout << "-----------------------"<<endl;
    inv.multiplicacion();// INVERSA * EC.Or CON VECTOR INICIAL
    cout << "-----------------------"<<endl;
    inv.resta();         // VECTOR INCIAL - LA MULTIPLICACION
    cout << "-----------------------"<<endl;
}

return 0;
}
