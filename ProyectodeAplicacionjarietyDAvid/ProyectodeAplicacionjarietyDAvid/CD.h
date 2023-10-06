#pragma once
#include<iostream>
using namespace std;
class CD
{
public://declarando las varibles del objeto que almacena canciones
	string nombreDelCD;
	string nombre;
	string artista;
	string duracion;
	int duracionS;
	CD() {
		nombreDelCD = "";
		nombre = "";
		duracion = "";
		artista = "";
	}
};

class ALBUM
{
public://declarando las variables para el objeto que almacena los abums
	string nombreDelCD;
	int inicio;
	int final;
	ALBUM()
	{
		nombreDelCD = "";
		inicio = 0;
		final = 0;
	}
};

