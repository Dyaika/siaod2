//functions2.h
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Patient.h"

using namespace std;
void createTextFile(string fname, int length);
void textToBinary(string fname, fstream& be);
void binaryToText(fstream& b, string fname);
void printAllBinary(fstream& b);
Patient* getRowBinary(fstream& b, int row);
bool deleteByKey(fstream& b, int key);
void onlyPatientsWith(fstream& b, string fname, int illness);
void newDoctorFor(fstream& b, int* cards, int n, char doctor[16]);