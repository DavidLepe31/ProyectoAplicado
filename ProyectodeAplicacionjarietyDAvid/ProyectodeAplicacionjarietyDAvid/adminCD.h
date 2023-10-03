#pragma once
#include <iostream>
#include"CD.h"
#include<vector>
#include<fstream>
#include<string>
#include<dirent.h>

class adminCD
{
public:
	vector<string>listaArch;
	vector<CD*> canciones;
	vector<CD*> discos;
	int lineCount = 0;
	int cdscount = 0;
	

	string CDNAME;
	void ArchivosL(string carpeta);
	void llenarCDS(string adress);
	void borrarcds();
	//creando vector para almacenar los objetos
	

	adminCD() {
		

		

	}
};

