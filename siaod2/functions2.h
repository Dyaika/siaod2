#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Patient.h"

using namespace std;
void createTextFile(string fname);
void textToBinary(string fname);
void binaryToText(string fname);
void printAllBinary(string fname);
void printRowBinary(string fname, int row);
void deleteByKey(string fname, int key);
void onlyPatientsWith(string fname, int illness);
void newDoctorFor(string fname, int* cards, char* doctor);