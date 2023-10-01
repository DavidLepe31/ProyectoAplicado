#include "adminCD.h"
void adminCD::llenarCDS(string adress) {
	//abriendo el archivo
	ifstream file(adress);

	//creando vector para almacenar los objetos
	vector<CD*> canciones;
	vector<CD*> discos;
	CD* prueba1 = new CD();
	prueba1->inicio= lineCount;//alamenando donde inicia el disco

	//llenando el vector con cada grupo de caniones
	for (prueba1; file >> prueba1->nombre >> prueba1->artista >> prueba1->duracion;) {
	canciones.push_back(prueba1);
	lineCount++;
	}


	//almacenando el nombre del disco y donde termina
	prueba1->nombreDelCD = adress;
	prueba1->final = lineCount;
	discos.push_back(prueba1);
	cdscount++;
	for (int i = 0; i < lineCount; i++)
	{
		cout << canciones[i]->nombre << " ";
		cout << canciones[i]->artista << " ";
		cout << canciones[i]->duracion << " ";

	}
	cout << "inicio"<<discos[cdscount]->inicio;
	cout << "final" << discos[cdscount]->final;


}