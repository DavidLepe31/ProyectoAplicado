#include "adminCD.h"
//funcion que lee los archivos dentro de una carpeta
void adminCD::ArchivosL(string carpeta, vector<string>&lerrores, vector<CD*>&canciones, vector<ALBUM*>&discos, int *cdscount) {
	struct dirent* d;
	DIR* dr;
	int count4=0;
	//enviando direccion de la carpeta dada por el usuario.
	const char* ccarpeta = carpeta.c_str();
	cdscount = 0;
	//abriendo la carpeta
	dr = opendir(ccarpeta);
	//validando que no se encuentre vacio.
	if (dr != NULL)
	{
		//lee la carpeta linea por linea
		while ((d = readdir(dr)) != NULL) {
			if (count4 != 0 && count4 != 1) {
				//llamando a la funcion que lee el archivo txt encontrado 
				llenarCDS(carpeta, d->d_name,lerrores,canciones,discos, cdscount);
				
			}
			count4++;
		}

		closedir(dr);
	}
	else
		lerrores.push_back("Error en la carpeta indicada " + carpeta);
	cout << endl;
}
//funcion que crea una lista sobre las canciones encontradas en el archivo txt
void adminCD::llenarCDS(string adress,string nombre, vector<string> &lerrores, vector<CD*> &canciones, vector<ALBUM*> &discos, int *cdscount) {
	//asignando direccion de archivo
	string archivotxt;
	string nalbum;

	archivotxt = adress + "\\" + nombre;

	//abriendo el archivo
	ifstream file(archivotxt);
	string strline = "";
	
	ALBUM* tmpDiscos = new ALBUM();
	
	int i;
	int col;
	int psn=0;
	int ibande = 0;
	int vcol = 0;
	int cdcount = 0;
	int xbusca = 0;
	int j = 0;
	string strparte = "";
	string csep = "||";
	string strlinet="";

	//obtenemos el nombre del album sin la extensión del archivo
	size_t csep_pos = nombre.find(".");
	if (csep_pos != string::npos)
	{
		tmpDiscos->nombreDelCD = nombre.substr(0, csep_pos);
	}
	else
		tmpDiscos->nombreDelCD = nombre;
	//guardando en	que parte del vector se encuentra este txt
	tmpDiscos->inicio = lineCount;
		
// validadno que no este cerrado el archivo
	while (!file.eof()) {
		getline(file, strline);
		i = 0;
		col = 0;
		vcol = 0;
		CD* tmpCanciones = new CD();
		//buscar el ||
		if (strline.size()<=0)
			//validando errores
			lerrores.push_back("Fila vacía " + to_string(cdcount) + " del album " + nombre);
		else {
			size_t csep_pos = strline.find(csep);
			if (csep_pos != string::npos)
			{
				//asignando el parametro corespondiente segun lo encontrado
				tmpCanciones->nombre = strline.substr(0, csep_pos);

				strlinet = strline.substr(csep_pos + 2, strline.size() - csep_pos);
				csep_pos = strlinet.find(csep);
				if (csep_pos != string::npos)
				{
					tmpCanciones->artista = strlinet.substr(0, csep_pos);
					if (tmpCanciones->artista.empty())
					{
						lerrores.push_back("No hay datos de Artista en el album "+nombre+" linea "+ to_string(cdcount));
					}
					else {
						strparte = strlinet.substr(csep_pos + 2, strlinet.size() - csep_pos);
						tmpCanciones->duracion = strparte;
						if (strparte.empty())
						{
							lerrores.push_back("No hay datos en la duracion  en el album " + nombre + " linea " + to_string(cdcount));
						}
						else
						{
							csep_pos = strparte.find(":");
							if (csep_pos != string::npos)
							{
								tmpCanciones->duracionS = stoi(strparte.substr(0, csep_pos)) * 60 + stoi(strparte.substr(csep_pos + 1, strparte.size()));
							}

						}
					}
				}
				else
				{
					tmpCanciones->artista = strlinet;
					tmpCanciones->duracion = "";
					//guardadno todos los datos de errores
					if (tmpCanciones->artista.empty())
					{
						lerrores.push_back("No hay datos de Artista  en el album " + nombre + " linea " + to_string(cdcount));
						lerrores.push_back("No hay datos en la duracion en el album " + nombre + " linea " + to_string(cdcount));
					}
					else
					{
						lerrores.push_back("No hay datos en la duracion en el album " + nombre + " linea " + to_string(cdcount));
					}
					
				}
				//guardando parametros del album
				tmpCanciones->nombreDelCD = tmpDiscos->nombreDelCD;
				string strnombre;
				string strartista;
				strnombre = tmpCanciones->nombre;
				strartista = tmpCanciones->artista;
				xbusca = 0;
				j = 0;
				//validando que no este vacio
				if (canciones.size() > 0)
				{
					while (xbusca == 0)
					{
						if (j >= canciones.size())
							break;
						else
						{
							if (canciones[j]->nombre == strnombre && canciones[j]->artista == strartista)
								xbusca = 1;
						}
						++j;
					}
				}
				if (xbusca == 0)
				{
					canciones.push_back(tmpCanciones);
					++cdcount;
				}
				else
					lerrores.push_back("Cancion repetida en el album " + tmpDiscos->nombreDelCD + " " + tmpCanciones->nombre);
			}
		}
		//++lineCount;
		
	} 
	if (lineCount == 0)
	{
		tmpDiscos->final = lineCount + cdcount - 1;
	}
	else
	{
		tmpDiscos->final = lineCount - 1 + cdcount;
	}
	lineCount += cdcount;
	discos.push_back(tmpDiscos);
	
	
}

