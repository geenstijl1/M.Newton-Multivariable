#ifndef inversa_h
#define inversa_h

using namespace std;
class Inversa {
    public:
        float piv, a[50][50], b[50][50], matriz_o[5][5],res_multi[5][5];;
        float x1=1,y1=1; //VECTORI INCIAL
        int i, j, n, k, l, m, x, y,z = 2, z1,z2;
        void jacob();//VECTOR Y JACOBIANO
        void ecuacion_o();
        void multiplicacion();
        void resta();
        void f_piv();
        void c_piv();
        void op();
        void matriz();
        void imprimir();
        void todo();
};
void Inversa::jacob(){
    n = 2;
    a[0][0] = 4 * x1;
    a[0][1] = 2 * y1*x1;
    a[1][0] = 6 * x1;
    a[1][1] = -12*x1;

}
//SELECION DE LA FILA piv PARA REALIZAR EL METODO
void Inversa::f_piv(){
    for(m = 0; m < n; m++)
        if(m != i)
            b[i][m] = a[i][m] / piv;
}
//SELECCION DE LA COLUMNA piv PARA REALIZAR EL METODO
void Inversa::c_piv() {
    for(m = 0; m < n; m++){
        if(m != j){
            b[m][j] = -a[m][j] / piv;
        }
    }
}
//OPERACIONES
void Inversa::op() {
    for(x = 0 ;x < n; x ++) 
        for(y = 0; y < n; y++)
            if(x != i && y != j)
                b[x][y] = a[x][y] - (a[i][y] * a[x][j]) / piv;
}

//IMPRESION DE LA MATRIZ INVERSA
void Inversa::imprimir() {
    cout <<"Matriz Inversa: " << endl;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            cout << a[i][j] << "   ";
        }
        cout <<" \n";
    }
}

//EJECUCION DE tODO EL METODO
void Inversa::todo(){
    for(i = 0; i < n; i++) {
        j = i;
        piv = a[i][j];
        b[i][j] = 1 / piv;
        f_piv();
        c_piv();
        op();
        for(k = 0 ; k < n; k++) {
            for(l = 0; l < n; l++) {
                a[k][l] = b[k][l];
            }
        }
    }
    imprimir();

}
//SISTEMA DE ECUACIONES, SUSTITUCION CON EL VECTOR
void Inversa::ecuacion_o() {
    matriz_o[0][0] = (pow(x1,2) + (4 * pow(y1,2)) - 9);
    matriz_o[1][0] = (14 * pow(x1,2) - 18 * y1 - 45);
    cout << "Ec. Orig. con vector inicial:  " << endl;
    cout << "[" << matriz_o[0][0] << "]" << endl;
    cout << "[" << matriz_o[1][0] << "]" << endl;
}

void Inversa::multiplicacion() {
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            //CAMBIA "z" CON RESPECTO AL NUMERO DE ECUACIONES EN EL SISTEMA
            res_multi[i][j] = 0;
            for(k = 0; k < z; k++) {
                res_multi[i][j] = res_multi[i][j] + (a[i][k] * matriz_o[k][k-k]);
            }
        }
    }
    cout << "Multiplicacion: "<<endl;
    cout << res_multi[0][0]<<endl;
    cout << res_multi[1][0]<<endl;
}

void Inversa::resta() {
    cout << "Resta: " <<endl;
    x1 = x1 - res_multi[0][0];
    y1 = y1 - res_multi[1][0];
    cout << x1 <<endl;
    cout << y1 <<endl;


}

#endif
