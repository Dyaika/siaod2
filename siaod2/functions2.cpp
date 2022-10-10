#include "functions2.h"

void createTextFile(string fname)
{
	ofstream fout;
	if (!fout.is_open()) {
		fout.open(fname + ".txt");
	}
	string doctors[5] = { "Ivanov", "Petrov", "Razshildyeav", "Archipov", "Shabalov"};

	int n = rand() % 50 + 250;
	//карточка код фамилия
	for (int i = 0; i < n; i++) {
		fout << (int)rand() % 10 + i * 10 + 1000 << " " << (int)rand() % 15 + 1 << " " << doctors[rand() % 5] << "\n";
	}
	fout.clear();
	if (fout.good()) {
		fout.close();
	}
	else {
		exit(1);
	}
}

void textToBinary(string fname)
{
}

void binaryToText(string fname)
{
}

void printAllBinary(string fname)
{
}

void printRowBinary(string fname, int row)
{
}

void deleteByKey(string fname, int key)
{
}

void onlyPatientsWith(string fname, int illness)
{
}

void newDoctorFor(string fname, int* cards, char* doctor)
{
}

