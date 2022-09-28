// siaod2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <Windows.h>
void zadanie1();
using namespace std;
void createFile(string& fname);
void printFile(string& fname);
void addLine(string& fname);
string getByNumber(string& fname, int number);
int numberCounter(string& fname);
void var5(string& fname);


int main()
{
    zadanie1();
    return 0;
}

//создание и заполнение файла
void createFile(string& fname) {
    ofstream fout(fname + ".txt");
    short n = rand() % 5 + 3;
    short rowN;
    for (short i = 0; i < n; i++) {
        rowN = rand() % 5 + 1;
        while (rowN > 1) {
            rowN--;
            fout << rand() % 1000;
            fout << " ";
        }
        fout << rand() % 1000 << "\n";
    }
    fout.close();
}

//печать содержимого
void printFile(string& fname) {
    ifstream fin(fname + ".txt");
    string str;
    while (getline(fin, str)) {
        cout << str << "\n";
    }
    fin.close();
}

//добавление строчки в конец
void addLine(string& fname) {
    ofstream fout;
    fout.open(fname + ".txt", ios::app);
    string str;
    cin.get();
    getline(cin, str);
    fout << str << "\n";
    fout.close();
}

//получение по номеру
string getByNumber(string& fname, int number) {
    ifstream fin(fname + ".txt");
    string str;
    for (int i = 0; i < number; i++) {
        fin >> str;
    }
    fin.close();
    return str;
}

//считает количество чисел
int numberCounter(string& fname) {
    ifstream fin(fname + ".txt");
    int n = 0;
    string str;
    while (fin >> str) {
        n++;
    }
    fin.close();
    return n;
}

//умножение файла на последнюю запись
void var5(string& fname) {
    ifstream fin(fname + ".txt");
    ofstream fout(fname + "_multipied.txt");
    int n = 0;
    int last;
    int cur;
    while (fin >> last) {
        n++;
    }
    fin.close();
    fin.open(fname + ".txt");
    for (int i = 0; i < n; i++) {
        fin >> cur;
        fout << cur * last << "\n";
    }
    fin.close();
    fout.close();
}

//приложение
void zadanie1() {
    string str;
    cout << "Enter file name: ";
    cin >> str;
    createFile(str);
    int data;
    int task = 1;
    cout << "File " << str << ".txt was created and filled with random numbers. ";
    while (task > 0 and task < 6) {
        cout << "Choose task:\n1) Print file\n2) Add new row\n3) Get value by number\n4) Get number count\n5) Multiply all values\n";
        cin >> task;
        switch (task)
        {
        case 1:
            printFile(str);
            cout << "---end of file---\n\n";
            break;
        case 2:
            cout << "Enter new line: ";
            addLine(str);
            cout << "---line added successfully---\n\n";
            break;
        case 3:
            cout << "Enter number: ";
            cin >> data;
            cout << "Number is: " << getByNumber(str, data);
            cout << "\n---completed---\n\n";
            break;
        case 4:
            cout << "Number count: " << numberCounter(str);
            cout << "\n---completed---\n\n";
            break;
        case 5:
            var5(str);
            cout << "File " << str << "_multiplied.txt was created\n";
            cout << "\n---completed---\n\n";
            break;
        default:
            break;
        }
    }
    cout << "---exit---";
}