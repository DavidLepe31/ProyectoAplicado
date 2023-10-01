

#include <iostream>
#include"CD.h"
#include"adminCD.h"
#include<vector>
using namespace std;



int main()
{
    string prueba;

    cout << "ingrese el testo";
    cin >> prueba;
     adminCD* lector = new adminCD();
     lector->llenarCDS(prueba);


}

