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
	//*vector<string>listaArch;
	//*vector<CD*> canciones;
	//**vector<CD*> discos;
	int lineCount = 0;
	/*int cdscount = 0;
	vector<string> lerrores;*/

	string CDNAME;
	void ArchivosL(string carpeta, vector<string>& lerrores, vector<CD*>& canciones, vector<ALBUM*>& discos, int* cdscount);
    void llenarCDS(string adress, string nombre, vector<string>&lerrores, vector<CD*>&canciones, vector<ALBUM*>&discos,int *cdscount);
	//creando vector para almacenar los objetos
	

	adminCD() {
		

		

	}
};

