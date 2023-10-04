#include "adminCD.h"
void adminCD::ArchivosL(string carpeta) {
	struct dirent* d;
	DIR* dr;
	int count4=0;
	dr = opendir("C:\\Users\\dalco\\OneDrive\\Escritorio\\ProyectoAplicado\\pruebas1");

	if (dr != NULL)
	{
		
		while ((d = readdir(dr)) != NULL) {
			if (count4 != 0 && count4 != 1) {
				llenarCDS(carpeta, d->d_name);
			}
			count4++;
		}

		closedir(dr);
	}
	else
		cout << "\nError Occurred!";
	cout << endl;
}
void adminCD::llenarCDS(string adress,string nombre) {
	//asignando direccion de archivo
	string archivotxt;
	archivotxt = adress + "\\" + nombre;

	//abriendo el archivo
	ifstream file(archivotxt);
	string album=nombre;//pendiente de implementear codigo que extraiga el nombre
	string strline = "";
	
	CD* prueba1 = new CD();
	int fpos;
	int i;
	int col;
	int psn=0;
	int ibande = 0;
	string strparte = "";
	prueba1->inicio= lineCount;//alamenando donde inicia el disco
	
	while (!file.eof()) {
		CD* tmpCanciones = new CD();
		getline(file, strline);
		fpos = 0;
		i = 0;
		col = 0;

		//buscar el ||
		while (i <= strline.size()) {

			//entonces si es un | o el final del archivo
			if ((strline[i] == '|') || (i == (strline.size()))) {

				//guardamos la informacion
				strparte = strline.substr(fpos, i - fpos);
				switch (col)
				{
				case 0:
					tmpCanciones->nombre = strparte;
					break;
				case 1:
					tmpCanciones->artista = strparte;
					break;
				case 2:
				
					tmpCanciones->duracion = strparte;

					//buscamos los : en duracion
					ibande = 0;
					psn = 0;
					while (ibande == 0 && psn <= strparte.size())
					{
						if (strparte[psn] == ':')
							ibande = 1;
						++psn;
					}

					//convertimos a segundos
					tmpCanciones->duracionS = stoi(strparte.substr(0, psn)) * 60 + stoi(strparte.substr(psn + 1, strparte.size()));
				
					break;
				}
				fpos= i + 2;
				++i;
				++col;
			}
			++i;
		}
		canciones.push_back(tmpCanciones);
		
		lineCount++;
		
	}
	
	
	prueba1->nombreDelCD = album;
	prueba1->final = lineCount;
	

	//almacenando el nombre del disco y donde termina
	
	
	discos.push_back(prueba1);
	cdscount++;
	
	

}