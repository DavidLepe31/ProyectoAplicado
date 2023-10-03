#include "mostrar.h"
string rellenador;

void mostrar::rellenado(string h) {
	rellenador = h;

}


void mostrar::mostrarCD() {
	//creando objeto igual al que tenemos en main
	adminCD* vs = new adminCD();
	vs->llenarCDS(rellenador);
	//imprimiendo el CD
	for (int i = 0; i < vs->cdscount; i++) {
		cout << i<<" " << vs->discos[i]->nombreDelCD << endl;
		
	}
}

void mostrar::mostrarCanciones(int CDselect) {
	//creando objeto igual al que tenemos en main
	adminCD* vs1 = new adminCD();
	vs1->llenarCDS(rellenador);
	//dando un disco a seleccionar
	cout << vs1->discos[0]->nombreDelCD<<endl;
	//imprimiendo las canciones
	for (int i = vs1->discos[CDselect]->inicio; i < vs1->discos[CDselect]->final; i++) {
		cout << i<<" " << vs1->canciones[i]->nombre << endl;
	}

}

void mostrar::agregarCancion() {
	//creando objeto igual al que tenemos en main
	adminCD* vs2 = new adminCD();
	vs2->llenarCDS(rellenador);
	int x = 0;
	int z = 0;
	CD* prueba2 = new CD();
	cout << "ingrese el CD que desea mostrar" << endl;
	mostrarCD();
	cin >> x;
	cout << "ingrese la cancion que desea agreagar a la cola" << endl;
	mostrarCanciones(x);
	cin >> z;
	prueba2->nombre=vs2->canciones[z]->nombre;
	prueba2->artista = vs2->canciones[z]->artista;
	prueba2->duracion = vs2->canciones[z]->duracion;
	prueba2->duracionS = vs2->canciones[z]->duracionS;
	listaReproduccion.push_back(prueba2);
}

void mostrar::chowlista(vector<CD*>& orden, int r) {
	switch (r)
	{
	case 1:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " << orden[i]->nombre << endl;
		}
		
		break;
	case 2:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " << orden[i]->nombre << endl;
		}
		break;
	case 3:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " << orden[i]->artista << endl;
		}
		break;
	case 4:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " << orden[i]->duracion << endl;
		}
		break;
	}
}

void mostrar::ordenar(int sele) {
	vector<string>tmpLista;
	vector<string>tmpLista2;
	vector<int>tmpLista1;
	
	int c;
	int bandera;

	switch (sele)
	{
	case 1:
		chowlista(listaReproduccion, 1);
		break;
	case 2:
		//pasando a verctor para ordenar
		for (int i = 0; i < listaReproduccion.size(); i++)
		{
			tmpLista.push_back(listaReproduccion[i]->nombre);
		}
		//ordenando
		sort(tmpLista.begin(), tmpLista.end());
		//reasignando vector
		for (int i = 0; i<tmpLista.size(); i++) {
			bandera = 0;
			c = 0;
			while (bandera == 0) {
				if (listaReproduccion[c]->nombre == tmpLista[i]) {
					pornombre.push_back(listaReproduccion[c]);
					bandera = 1;

				}
				c++;
			}
		}
		//impromiendo la lista
		chowlista(pornombre, 2);
		break;
	case 3:

			for (int i = 0; i < listaReproduccion.size(); i++)
			{
				tmpLista2.push_back(listaReproduccion[i]->artista);

			}
			sort(tmpLista2.begin(), tmpLista2.end());

			for (int i = 0; i<tmpLista2.size(); i++) {
				bandera = 0;
				c = 0;
				while (bandera == 0) {
					if (listaReproduccion[c]->artista == tmpLista2[i]) {
						porartista.push_back(listaReproduccion[c]);
						bandera = 1;
					}
					c++;
				}
			}
			chowlista(porartista, 2);
			break;
	case 4:
		for (int i = 0; i < listaReproduccion.size(); i++)
		{
			tmpLista1.push_back(listaReproduccion[i]->duracionS);
		}

		sort(tmpLista1.begin(), tmpLista1.end());

		for (int i = 0; i<tmpLista1.size(); i++) {
			bandera = 0;
			c = 0;
			while (bandera == 0) {
				if (listaReproduccion[c]->duracionS == tmpLista1[i]) {
					portiempo.push_back(listaReproduccion[c]);
					bandera = 1;
				}
				c++;
			}
		}
		chowlista(portiempo, 2);
		break;
	}

}



