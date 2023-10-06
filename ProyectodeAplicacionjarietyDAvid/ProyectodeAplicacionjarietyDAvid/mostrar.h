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
		
		
		vector<CD*>lOrden;
	

		int hola;
		void chowlista(vector<CD*>&orden, int r);
		void agregarCancion(vector<ALBUM*>discos, vector<CD*>canciones, vector<CD*>&lReproduccion);
		int mostrarCD(vector<ALBUM*>mdiscos);
		void mostrarCanciones(int CDselect, string nombreCD, vector<CD*>canciones, int iInicio, int iFinal);
		void ordenar(int sele, vector<CD*>lReproduccion);
		
		void reproducirN(vector<CD*>lReproduccion);
		void ordenPA(int permenente, vector<CD*>&lReproduccion);
		void ordenPD(int permenente, vector<CD*>&lReproduccion);
		void muetraerrores(vector<string>lerrores);

		mostrar() 
		{
			
		}
		
};

