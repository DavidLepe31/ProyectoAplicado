#pragma once
#include <iostream>
#include"CD.h"
#include"adminCD.h"
#include<vector>
#include<algorithm>


using namespace std;
class mostrar
{
	public:
		
		vector<CD*>listaReproduccion;
		vector<CD*>pornombre;
		vector<CD*>porartista;
		vector<CD*>portiempo;
		int hola;
		void chowlista(vector<CD*>& orden, int r);
		void agregarCancion();
		void mostrarCD();
		void mostrarCanciones(int cdselect);
		void ordenar(int sele);
		void rellenado(string relleno);
		mostrar() {
			
		}
		
};

