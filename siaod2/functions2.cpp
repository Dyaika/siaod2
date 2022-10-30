#include "functions2.h"

//создает текстовый файл со строками
void createTextFile(string fname, int length = 0)
{
	ofstream tout;
	if (!tout.is_open()) {
		tout.open(fname);
	}
	string doctors[5] = { "Ivanov", "Petrov", "Razshildyaev", "Archipov", "Shabalov" };
	int n = length;
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
void textToBinary(string fname, fstream& b)
{

	ifstream tin;
	tin.open(fname);
	b.clear();
	if (!b.is_open() or !tin.is_open()) {
		exit(2);
	}
	b.seekg(0, ios::beg);//ставим в начало
	Patient temp;
	while (tin >> temp.card >> temp.illness >> temp.doctor) {

		b.write((char*)&temp, sizeof(Patient));
	}
	b.seekg(0, ios::beg);//возвращаем в начало
	b.clear();
	tin.clear();
	if (b.good() and tin.good()) {
		tin.close();
	}
	else {
		exit(3);
	}
}

//создает текстовый файл по бинарному
void binaryToText(fstream& b, string fname)
{
	ofstream tout;
	tout.open(fname);
	b.clear();
	if (!tout.is_open() or !b.is_open()) {
		exit(4);
	}
	b.seekg(0, ios::beg);//ставим в начало
	Patient temp;
	b.read((char*)&temp, sizeof(Patient));
	while (!b.eof()) {
		tout << temp.card << " " << temp.illness << " " << temp.doctor << "\n";
		b.read((char*)&temp, sizeof(Patient));
	}
	tout.clear();
	b.seekg(0, ios::beg);//возвращаем в начало
	b.clear();
	if (tout.good() and b.good()) {
		tout.close();
	}
	else {
		exit(5);
	}
}

//печатает из бинарного файла
void printAllBinary(fstream& b)
{
	b.clear();
	if (!b.is_open()) {
		exit(6);
	}
	b.seekg(0, ios::beg);//ставим в начало
	Patient temp;
	b.read((char*)&temp, sizeof(Patient));
	while (!b.eof()) {
		cout << temp.card << " " << temp.illness << " " << temp.doctor << "\n";
		b.read((char*)&temp, sizeof(Patient));
	}
	b.seekg(0, ios::beg);//возвращаем в начало
	b.clear();
	if (!b.good()) {
		exit(7);
	}
}

//возвращает из бинарного файла 1 запись
Patient* getRowBinary(fstream& b, int row) {
	b.clear();
	if (!b.is_open()) {
		exit(20);
	}
	Patient temp;
	bool flag = false;
	b.seekg((row - 1) * sizeof(Patient), ios::beg);
	b.read((char*)&temp, sizeof(Patient));
	if (b.eof() or row < 1) {
		flag = true;
	}
	b.seekg(0, ios::beg);//возвращаем в начало
	b.clear();
	if (!b.good()) {
		exit(21);
	}
	if (flag) {
		return nullptr;
	}
	Patient* res = new Patient;
	res->card = temp.card;
	for (int i = 0; i < 16; i++) {
		res->doctor[i] = temp.doctor[i];
	}
	res->illness = temp.illness;
	return res;
}

//заменяет на последнюю запись
bool deleteByKey(fstream& b, int key)
{
	b.clear();
	if (!b.is_open()) {
		exit(10);
	}
	b.seekg(0, ios::beg);//ставим в начало
	Patient last;
	int i = 0;
	int pos = -1;
	while (b.read((char*)&last, sizeof(Patient))) {
		if (last.card == key) {
			pos = i;
		}
		i++;
	}
	if (pos == -1) {
		return false;
	}
	else {
		b.clear();
		b.seekp(pos * sizeof(Patient), ios::beg);
		b.write((char*)&last, sizeof(Patient));
	}
	b.seekg(0, ios::beg);//возвращаем в начало
	b.clear();
	if (!b.good()) {
		exit(11);
	}
	return true;
}

//выбирает определенных больных
void onlyPatientsWith(fstream& b, string fname, int illness)
{
	b.clear();
	ofstream bout;
	bout.open(fname, ios::binary);
	if (!bout.is_open() or !b.is_open()) {
		exit(14);
	}
	b.seekg(0, ios::beg);//ставим в начало
	Patient temp;
	while (b.read((char*)&temp, sizeof(Patient))) {
		if (temp.illness == illness) {
			bout.write((char*)&temp, sizeof(Patient));
		}
	}
	bout.clear();
	b.clear();
	if (bout.good() and b.good()) {
		bout.close();
	}
	else {
		exit(15);
	}
	b.seekg(0, ios::beg);//возвращаем в начало
}

//назначает доктора
void newDoctorFor(fstream& b, int* cards, int n, char doctor[16])
{
	b.clear();
	if (!b.is_open()) {
		exit(16);
	}
	b.seekg(0, ios::beg);//ставим в начало
	Patient temp;
	int count = 0;
	while (b.read((char*)&temp, sizeof(Patient)))
	{
		for (int i = 0; i < n; i++) {
			if (temp.card == cards[i]) {
				for (int j = 0; j < 16; j++) {
					temp.doctor[j] = doctor[j];
				}
				break;
			}
		}
		b.seekg(sizeof(Patient) * (count), ios::beg);
		b.write((char*)&temp, sizeof(Patient));
		count++;
		b.clear();
		b.seekg(sizeof(Patient) * (count), ios::beg);

	}

	b.seekg(0, ios::beg);//возвращаем в начало
	b.clear();
	if (!b.good()) {
		exit(17);
	}
}

