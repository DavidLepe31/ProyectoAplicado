#include "mostrar.h"

string rellenador;
bool play=true;
int x = 0;




int mostrar::mostrarCD(vector<ALBUM*> mdiscos) {
	
	//imprimiendo el CD
	for (int i = 0; i < mdiscos.size(); i++) {
		cout << i<<" " << mdiscos[i]->nombreDelCD << endl;
		
	}
	return 1;
}

void mostrar::mostrarCanciones(int CDselect, string nombreCD, vector<CD*>canciones, int iInicio, int iFinal) {
	
	//dando un disco a seleccionar
	cout << nombreCD<<endl;
	//imprimiendo las canciones
	for (int i =iInicio; i <= iFinal; i++) {
		cout << i<<" " << canciones[i]->nombre << " " << canciones[i]->artista <<" "<< canciones[i]->duracion << endl;
	}

}

void mostrar::agregarCancion(vector<ALBUM*>discos, vector<CD*>canciones, vector<CD*>&lReproduccion) {
	string vali;
	int x = 0;
	int z = 0;
	int y = 0;
	bool banse = true;
	bool banse2 = true;
	//objeto de CD
	CD* tmpCancion = new CD();
	
		cout << "Ingrese el numero del CD que desea mostrar" << endl;
		y=mostrarCD(discos);
	while (banse)
	{
			while (!(cin >> x)) 
			{
				cin.clear();
				cin.ignore(discos.size(), '\n');
				//cout << "Valor incorrecto: ";
			}
		if (x >= 0 && x < discos.size())
			banse = false;
	}
	while (banse2) {
		system("cls");
		mostrarCanciones(x, discos[x]->nombreDelCD, canciones, discos[x]->inicio, discos[x]->final);
		cout << "Ingrese el numero de la cancion que desea agreagar a la cola" << endl;
		banse = true;
		while (banse)
		{
			while (!(cin >> z))
			{
				cin.clear();
				cin.ignore(discos[x]->final, '\n');
				//cout << "Valor incorrecto: ";
			}
			if (z >= discos[x]->inicio && z <= discos[x]->final)
				banse = false;
		}
		tmpCancion->nombre = canciones[z]->nombre;
		tmpCancion->artista = canciones[z]->artista;
		tmpCancion->duracion = canciones[z]->duracion;
		tmpCancion->duracionS = canciones[z]->duracionS;
		tmpCancion->nombreDelCD = canciones[z]->nombreDelCD;
		lReproduccion.insert(lReproduccion.begin(), tmpCancion);
		cout << "Desea continuar agregando canciones de este disco?si(ingrese cualquier letra)/no(escriba no)" << endl;
		cin >> vali;
		if (vali == "no") {
			banse2 = false;
		}

	}
}

void mostrar::chowlista(vector<CD*>&orden, int r ) {
	switch (r)
	{
	case 1:
		//ciclo de impresion de la lista
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " << "Nombre "<<orden[i]->nombre << " artista "<< orden[i]->artista <<" duracion "<< orden[i]->duracion<<"  CD "<<orden[i]->nombreDelCD << endl;
		}
		
		break;
	case 2:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " << "Nombre " << orden[i]->nombre << " artista " << orden[i]->artista << " duracion " << orden[i]->duracion << "  CD " << orden[i]->nombreDelCD << endl;

		}
		break;
	case 3:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " << "Artista " << orden[i]->artista << " Nombre " << orden[i]->nombre << " duracion " << orden[i]->duracion << "  " << orden[i]->nombreDelCD << endl;


		}
		break;
	case 4:
		for (int i = 0; i < orden.size(); i++)
		{
			cout << i << " " << "Duracion " << orden[i]->duracion << " nombre " << orden[i]->nombre << " artista " << orden[i]->artista << "  CD " << orden[i]->nombreDelCD << endl;

		}
		break;
	case 5:
		cout << "la cancion actual es: "<<endl;
		int j = orden.size();
		cout << "CD: " << orden[j - 1]->nombreDelCD << "Cancion: " << orden[j - 1]->nombre << "Artista: " << orden[j - 1]->artista << "Duracion: " << orden[j - 1]->duracion << endl;
		break;
	}
}
//funcion que ordena la lista de manera temporal
void mostrar::ordenar(int sele, vector<CD*>lReproduccion) {
	vector<string>tmpLista;
	vector<string>tmpLista2;
	vector<int>tmpLista1;
	
	int c;
	int bandera;
	//limpiando el vector que guarda el nuevo orden
	lOrden.clear();
	switch (sele)
	{
	case 1:
		chowlista(lReproduccion, 1);
		break;
	case 2:
		//pasando a verctor para ordenar
		for (int i = 0; i < lReproduccion.size(); i++)
		{
			tmpLista.push_back(lReproduccion[i]->nombre);
		}
		//ordenando
		sort(tmpLista.begin(), tmpLista.end());
		//reasignando vector
		for (int i = 0; i<tmpLista.size(); i++) {
			bandera = 0;
			c = 0;
			while (bandera == 0) {
				if (lReproduccion[c]->nombre == tmpLista[i]) {
					lOrden.push_back(lReproduccion[c]);
					bandera = 1;

				}
				c++;
			}
		}
		//impromiendo la lista
		chowlista(lOrden, 2);
		break;
	case 3:

			for (int i = 0; i < lReproduccion.size(); i++)
			{
				tmpLista2.push_back(lReproduccion[i]->artista);

			}
			sort(tmpLista2.begin(), tmpLista2.end());

			for (int i = 0; i<tmpLista2.size(); i++) {
				bandera = 0;
				c = 0;
				while (bandera == 0) {
					if (lReproduccion[c]->artista == tmpLista2[i]) {
						lOrden.push_back(lReproduccion[c]);
						bandera = 1;
					}
					c++;
				}
			}
			chowlista(lOrden, 3);
			break;
	case 4:
		for (int i = 0; i < lReproduccion.size(); i++)
		{
			tmpLista1.push_back(lReproduccion[i]->duracionS);
		}

		sort(tmpLista1.begin(), tmpLista1.end());

		for (int i = 0; i<tmpLista1.size(); i++) {
			bandera = 0;
			c = 0;
			while (bandera == 0) {
				if (lReproduccion[c]->duracionS == tmpLista1[i]) {
					lOrden.push_back(lReproduccion[c]);
					bandera = 1;
				}
				c++;
			}
		}
		chowlista(lOrden, 4);
		break;
	}

}


//mostrar cancion actual
void mostrar::reproducirN(vector<CD*>lReproduccion) {
	//validando si hay una cancion en reproduccion o no
	if (x == 0 || x == lReproduccion.size() + 1) {
		cout << "Reproducion en pausa" << endl;
		x++;

	}
	//obteniendo tamaño actual de la lista
	int tama = lReproduccion.size();
	//insertando el ultimo valor al inicio de la cola
	lReproduccion.insert(lReproduccion.begin(), lReproduccion[tama-1]);
	//borrando el ultimo registro
	lReproduccion.erase(lReproduccion.end() - 1);
	x++;
	chowlista(lReproduccion, 5);

	
}
//funcion que ordena la lista de manera permanente en orden acendente
void mostrar::ordenPA(int permanente, vector<CD*>&lReproduccion) {
	// llamando a la funcion ordenar
		ordenar(permanente,lReproduccion);
		//ingresando el nuevo orden a la lista permanentemente
		for (int i = 0; i < lOrden.size(); i++) {
			lReproduccion[i] = lOrden[i];
	}
	
}
//ordenado decendente de manera permanente

void mostrar::ordenPD(int permanente, vector<CD*>&lReproduccion) {
	//llamando a la funcion ordenar
	    ordenar(permanente, lReproduccion);
		//ingresando el nuevo orden a la lista de reproduccion 
		for (int i = 0; i < lOrden.size(); i++) {
			lReproduccion[i] = lOrden[(lOrden.size() - 1) - i];
		}
		
}
//funcion para mostrar los errores
void mostrar::muetraerrores(vector<string> lerrores) {
	//imprimiendo el vector que almacena los errores
		for (int i = 0; i < lerrores.size();i++) {
		cout << lerrores[i] << endl;
	}
}



