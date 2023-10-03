

#include <iostream>
#include"CD.h"
#include"adminCD.h"
#include"mostrar.h"
#include<vector>
#include <algorithm>
string adres;

using namespace std;

int main()
{
    /*string prueba;
  
    cout << "ingrese el testo"<<endl;
    cin >> prueba;*/
    
    adres="C:\\pruebas\\100 Greatest Hits of All Time.txt";
    adminCD* vs = new adminCD();
    vs->ArchivosL("C:\\flippy");

    mostrar * test1 = new mostrar();
    test1->rellenado(adres);
    test1->mostrarCanciones(0);
    test1->mostrarCD();
    bool ciclo = true;
    string srguir;
    while (ciclo) {
        test1->agregarCancion();
        cout << "desea seguir?" << endl;
        cin >> srguir;
        if (srguir == "no") {
            ciclo = false;
        }
    }
    test1->ordenar(4);
}


