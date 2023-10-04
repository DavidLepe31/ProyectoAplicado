

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
    string sn,out;
    int x0, x1, x2, x3, x4,x5,v;
    bool bande0 = true;
    bool bande1 = true;
    bool bande2= true;
    bool bande3 = true;
    bool bande4 = true;

    while (bande0) {
        mostrar* operador = new mostrar();
        cout << "ingrese la carpeta que desea respaldar" << endl;
        cin >> adres;
        bande1 = true;
        system("cls");
        while (bande1) {
            system("cls");
            cout << "ingrese el numero del a opcion que desea seleccionar" << endl;
            cout << "1. reiniciar archivos." << endl;
            cout << "2. reproductor de canciones." << endl;
            cin >> x0;
            switch (x0) {
            case 1:
                system("cls");
                bande1 = false;
                break;
            case 2:
                while (bande2)
                {
                    system("cls");
                    cout << "ingrese el numero de la opcion que desaea seleccionar" << endl;
                    cout << "1. agregar cancion" << endl;
                    cout << "2. ver lista de reproduccion" << endl;
                    cout << "3. reproducion actual" << endl;
                    cout << "4. reproducir siguiente" << endl;
                    cout << "5. ordenar" << endl;
                    cout << "6. salir" << endl;
                    cin >> x1;
                    switch (x1) {
                    case 1:
                        bande3 = true;
                        while (bande3) {
                            operador->agregarCancion();
                            cout << "¿Desea continuar agregando canciones?si/no" << endl;
                            if (sn=="no") {
                                bande3 = false;
                            }
                        }
                        break;
                    case 2:
                        while (bande4) {
                            system("cls");
                            cout << "ingrese el numero de la opcion de visualizacion que desea ver" << endl;
                            cout << "1. Nobre de la cancion" << endl;
                            cout << "2. Nombre del artista" << endl;
                            cout << "3. Duracion de la cancion" << endl;
                            cin >> x2;
                            operador->ordenar(x2);
                            cout << "1. visualizar de distinta manera" << endl;
                            cout << "2. Volver al menu" << endl;
                            cin >> x3;
                            if (x3 == 2) {
                                bande4 = false;
                            }


                        }
                        break;
                    case 3:
                        operador->chowlista(operador->listaReproduccion, 5);
                        cout << "ingrese cualquier letra para salir" << endl;
                        cin >> out;

                        break;
                    case 4:
                        operador->reproducirN();
                        cout << "ingrese cualquier letra para salir" << endl;
                        cin >> out;
                        break;
                    case 5:
                        cout << "esta opcion ordena de manera permanente la lista de reproducion segun la opcion seleccionada" << endl;
                        cout << "1. Ordenar por nombre de la cancion" << endl;
                        cout << "2. Ordenar por nombre del artista" << endl;
                        cout << "3. Ordenar por duracion de la cancion" << endl;
                        cin >> x4;
                        switch (x4) {
                        case 1:
                            cout << "¿En que direccion desea ordenar la lista de reproduccion?" << endl;
                            cout << "1. Acendente" << endl;
                            cout << "2. Desendente" << endl;
                            cin >> x5;

                            switch (x5)
                            {
                            case 1:
                                operador->ordenPA(1);
                                cout << "ingrese cualquier letra para salir" << endl;
                                cin >> out;
                                break;
                            case 2:
                                operador->ordenPD(1);
                                cout << "ingrese cualquier letra para salir" << endl;
                                cin >> out;
                                break;
                            }
                            break;
                        case 2:
                            cout << "¿En que direccion desea ordenar la lista de reproduccion?" << endl;
                            cout << "1. Acendente" << endl;
                            cout << "2. Desendente" << endl;
                            cin >> x5;
                            switch (x5)
                            {
                            case 1:
                                operador->ordenPA(2);
                                cout << "ingrese cualquier letra para salir" << endl;
                                cin >> out;
                                break;
                            case 2:
                                operador->ordenPD(2);
                                cout << "ingrese cualquier letra para salir" << endl;
                                cin >> out;
                                break;
                            }
                            break;
                        case 3:
                            cout << "¿En que direccion desea ordenar la lista de reproduccion?" << endl;
                            cout << "1. Acendente" << endl;
                            cout << "2. Desendente" << endl;
                            cin >> x5;
                            switch (x5)
                            {
                            case 1:
                                operador->ordenPA(3);
                                cout << "ingrese cualquier letra para salir" << endl;
                                cin >> out;
                                break;
                            case 2:
                                operador->ordenPD(3);
                                cout << "ingrese cualquier letra para salir" << endl;
                                cin >> out;
                                break;
                            }
                            break;
                        }


                        break;
                    case 6:
                        bande2 = false;
                        break;
                    }

                }
                break;
            }

        }
}

   
    system("cls");
   
}


