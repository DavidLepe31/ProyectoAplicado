#include "mostrar.h"
string rellenador;
bool play=true;
int x = 0;
void mostrar::rellenado(string h) {
	rellenador = h;

}


void mostrar::mostrarCD() {
	//creando objeto igual al que tenemos en main
	adminCD* vs = new adminCD();
	vs->ArchivosL(rellenador);//cambiar por archivol cuando ya funcione
	//imprimiendo el CD
	for (int i = 0; i < vs->cdscount; i++) {
		cout << i<<" " << vs->discos[i]->nombreDelCD << endl;
		
	}
}

void mostrar::mostrarCanciones(int CDselect) {
	//creando objeto igual al que tenemos en main
	adminCD* vs1 = new adminCD();
	vs1->ArchivosL(rellenador);
	//dando un disco a seleccionar
	cout << vs1->discos[CDselect]->nombreDelCD<<endl;
	//imprimiendo las canciones
	for (int i = vs1->discos[CDselect]->inicio; i < vs1->discos[CDselect]->final; i++) {
		cout << i<<" " << vs1->canciones[i]->nombre << endl;
	}

}

void mostrar::agregarCancion() {
	//creando objeto igual al que tenemos en main
	adminCD* vs2 = new adminCD();
	vs2->ArchivosL(rellenador);
	int x = 0;
	int z = 0;
	CD* prueba2 = new CD();
	cout << "ingrese el numero del CD que desea mostrar" << endl;
	mostrarCD();
	cin >> x;
	mostrarCanciones(x);
	cout << "ingrese el numero de la cancion que desea agreagar a la cola" << endl;

	cin >> z;
	prueba2->nombre=vs2->canciones[z]->nombre;
	prueba2->artista = vs2->canciones[z]->artista;
	prueba2->duracion = vs2->canciones[z]->duracion;
	prueba2->duracionS = vs2->canciones[z]->duracionS;
	listaReproduccion.insert(listaReproduccion.begin(), prueba2);
}

void mostrar::chowlista(vector<CD*>& orden, int r) {
	switch (r)
	{
	case 1:
		//ciclo de impresion de la lista
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " << "Nombre"<<orden[i]->nombre << endl;
		}
		
		break;
	case 2:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " "<<"Nombre" << orden[i]->nombre << endl;
			cout << " " << endl;

		}
		break;
	case 3:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " <<"Nombre"<< orden[i]->nombre << endl;
			cout <<"artista" << " " << orden[i]->artista << endl;
			cout << " " << endl;

		}
		break;
	case 4:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " <<"Nombre"<< orden[i]->nombre << endl;
			cout <<"duracion" << " " << orden[i]->duracion << endl;
			cout << " " << endl;
		}
		break;
	case 5:
		cout << "la cancion actual es: "<<endl;
		int j = orden.size();
		cout << "CD: " << orden[j - 1]->nombreDelCD << endl;
		cout << "Cancnion: "<<orden[j - 1]->nombre << endl;
		cout << "Artista: " << orden[j - 1]->artista << endl;
		cout << "Duracion: " << orden[j - 1]->duracion << endl;
		x++;
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
			chowlista(porartista, 3);
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
		chowlista(portiempo, 4);
		break;
	}

}


//mostrar cancion actual
void mostrar::reproducirN() {
	//validando si hay una cancion en reproduccion o no
	if (x == 0 || x == listaReproduccion.size() + 1) {
		cout << "Reproducion en pausa" << endl;
		
	}
	//obteniendo tamaño actual de la lista
	int tama = listaReproduccion.size();
	//insertando el ultimo valor al inicio de la cola
	listaReproduccion.insert(listaReproduccion.begin(), listaReproduccion[tama]);
	//borrando el ultimo registro
	listaReproduccion.erase(listaReproduccion.end() - 1);
	chowlista(listaReproduccion, 5);

	
}
void mostrar::ordenPA(int permenente) {
	switch (permenente)
	{
	case 1:
		ordenar(2);
		for (int i = 0; i < pornombre.size(); i++) {
			listaReproduccion[i] = pornombre[i];
	}
		chowlista(listaReproduccion, 5);
		break;
	case 2:
		ordenar(3);
		for (int i = 0; i < porartista.size(); i++) {
			listaReproduccion[i] = porartista[i];
		}
		chowlista(listaReproduccion, 5);
		break;
	case 3:
		ordenar(4);
		for (int i = 0; i < portiempo.size(); i++) {
			listaReproduccion[i] = portiempo[i];
		}
		chowlista(listaReproduccion, 5);
		break;
	}
}

void mostrar::ordenPD(int permenente) {
	switch (permenente)
	{
	case 1:
		ordenar(2);
		for (int i = 0; i < pornombre.size(); i++) {
			listaReproduccion[i] = pornombre[(pornombre.size()-1)-i];
		}
		chowlista(listaReproduccion, 5);
		break;
	case 2:
		ordenar(3);
		for (int i = 0; i < porartista.size(); i++) {
			listaReproduccion[i] = porartista[(porartista.size() - 1) - i];

		}
		chowlista(listaReproduccion, 5);
		break;
	case 3:
		ordenar(4);
		for (int i = 0; i < portiempo.size(); i++) {
			listaReproduccion[i] = portiempo[(portiempo.size() - 1) - i];

		}
		chowlista(listaReproduccion, 5);
		break;
	}
}


