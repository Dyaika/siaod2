#include "functions2.h"

//создает текстовый файл со строками
void createTextFile(string fname)
{
	ofstream tout;
	if (!tout.is_open()) {
		tout.open(fname + ".txt");
	}
	string doctors[5] = { "Ivanov", "Petrov", "Razshildyeav", "Archipov", "Shabalov"};

	int n = rand() % 10 + 50;
	//карточка код фамилия
	for (int i = 0; i < n; i++) {
		tout << (int)rand() % 10 + i * 10 + 1000 << " " << (int)rand() % 15 + 1 << " " << doctors[rand() % 5] << "\n";
	}
	tout.clear();
	if (tout.good()) {
		tout.close();
	}
	else {
		exit(1);
	}
}

//создает бинарный файл по текстовому
void textToBinary(string fname)
{
	ofstream bout;
	bout.open(fname + "_bin.dat", ios::binary);
	ifstream tin;
	tin.open(fname + ".txt");
	if (!bout.is_open() or !tin.is_open()) {
		exit(2);
	}
	Patient temp;
	tin >> temp.card >> temp.illness >> temp.doctor;
	while (!tin.eof()) {
		bout.write((char*)&temp, sizeof(Patient));
		tin >> temp.card >> temp.illness >> temp.doctor;
	}
	bout.clear();
	tin.clear();
	if (bout.good() and tin.good()) {
		bout.close();
		tin.close();
	}
	else {
		exit(3);
	}
}

//создает текстовый файл по бинарному
void binaryToText(string fname)
{
	ifstream bin;
	bin.open(fname + "_bin.dat", ios::binary);
	ofstream tout;
	tout.open(fname + "_text.txt");
	if (!tout.is_open() or !bin.is_open()) {
		exit(4);
	}
	Patient temp;
	bin.read((char*)&temp, sizeof(Patient));
	while (!bin.eof()) {
		tout << temp.card << " " << temp.illness << " " << temp.doctor << "\n";
		bin.read((char*)&temp, sizeof(Patient));
	}
	tout.clear();
	bin.clear();
	if (tout.good() and bin.good()) {
		tout.close();
		bin.close();
	}
	else {
		exit(5);
	}
}

//печатает из бинарного файла
void printAllBinary(string fname)
{
	ifstream bin;
	bin.open(fname + "_bin.dat", ios::binary);
	if (!bin.is_open()) {
		exit(6);
	}
	Patient temp;
	bin.read((char*)&temp, sizeof(Patient));
	while (!bin.eof()) {
		cout << temp.card << " " << temp.illness << " " << temp.doctor << "\n";
		bin.read((char*)&temp, sizeof(Patient));
	}
	bin.clear();
	if (bin.good()) {
		bin.close();
	}
	else {
		exit(7);
	}
}

//печатает из бинарного файла 1 запись
void printRowBinary(string fname, int row)
{
	ifstream bin;
	bin.open(fname + "_bin.dat", ios::binary);
	if (!bin.is_open()) {
		exit(8);
	}
	Patient temp;
	bin.seekg((row - 1) * sizeof(Patient), ios::beg);
	bin.read((char*)&temp, sizeof(Patient));
	if (bin.eof() or row < 1) {
		cout << "out of range\n";
	}
	else {
		cout << temp.card << " " << temp.illness << " " << temp.doctor << "\n";
	}
	bin.clear();
	if (bin.good()) {
		bin.close();
	}
	else {
		exit(9);
	}
}

//заменяет на последнюю запись
void deleteByKey(string fname, int key)
{
	ifstream bin;
	bin.open(fname + "_bin.dat", ios::binary);
	if (!bin.is_open()) {
		exit(10);
	}
	Patient last;
	int i = 0;
	int pos = -1;
	bin.read((char*)&last, sizeof(Patient));
	if (last.card == key) {
		pos = i;
	}
	i++;
	while (!bin.eof()) {
		bin.read((char*)&last, sizeof(Patient));
		if (last.card == key) {
			pos = i;
		}
		i++;
	}
	bin.clear();
	if (bin.good()) {
		bin.close();
	}
	else {
		exit(11);
	}
	if (pos == -1) {
		cout << "No such patient\n";
	}
	else {
		fstream bout;
		bout.open(fname + "_bin.dat", ios::binary | ios::out | ios::in);
		if (!bout.is_open()) {
			exit(12);
		}

		bout.seekg(pos * sizeof(Patient), ios::beg);
		bout.write((char*)&last, sizeof(Patient));

		//bout.flush();
		bout.clear();
		if (bout.good()) {
			bout.close();
		}
		else {
			exit(13);
		}
	}
	
}

//выбирает определенных больных
void onlyPatientsWith(string fname, int illness)
{
	ofstream bout;
	bout.open(fname + to_string(illness) + "_bin.dat", ios::binary);
	ifstream bin;
	bin.open(fname + "_bin.dat", ios::binary);
	if (!bout.is_open() or !bin.is_open()) {
		exit(14);
	}
	Patient temp;
	bin.read((char*)&temp, sizeof(Patient));
	while (!bin.eof()) {
		if (temp.illness == illness) {
			bout.write((char*)&temp, sizeof(Patient));
		}
		bin.read((char*)&temp, sizeof(Patient));
	}
	bout.clear();
	bin.clear();
	if (bout.good() and bin.good()) {
		bout.close();
		bin.close();
	}
	else {
		exit(15);
	}
}

//назначает доктора, не готова
void newDoctorFor(string fname, int* cards, int n, char doctor[16])
{
	fstream b;
	b.open(fname + "_bin.dat", ios::binary | ios::out | ios::in);
	if (!b.is_open()) {
		exit(16);
	}
	Patient temp;
	int count = 0;
	b.read((char*)&temp, sizeof(Patient));
	while (!b.eof())
	{
		for (int i = 0; i < n; i++) {
			if (temp.card == cards[i]) {
				for (int j = 0; j < 16; j++) {
					temp.doctor[j] = doctor[j];
				}
				break;
			}
		}
		//шагнули назад и переписали
		b.seekg(sizeof(Patient) * (count), ios::beg);
		b.write((char*)&temp, sizeof(Patient));
		//cout << temp.card << " " << temp.illness << " " << temp.doctor << " " << count << "\n";
		count++;
		b.clear();
		//шагаем дальше и читаем для будущего раза
		b.seekg(sizeof(Patient) * (count), ios::beg);
		b.read((char*)&temp, sizeof(Patient));
	}
	b.clear();
	if (b.good()) {
		b.close();
	}
	else {
		exit(17);
	}
}

