#pragma once
#include <iostream>
#include"CD.h"
#include<vector>
#include<fstream>
class adminCD
{
public:
	int lineCount = 0;
	int cdscount = 0;
	void llenarCDS(string adress);
	void borrarcds();

	adminCD() {

	}
};

