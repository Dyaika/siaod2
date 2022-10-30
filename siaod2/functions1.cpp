#include "functions1.h"
//создание и заполнение файла
void createFile(string fname) {
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
    fout.clear();
    if (fout.good()) {
        fout.close();
    }
    else {
        exit(1);
    }

}

//печать содержимого
void printFile(string fname) {
    ifstream fin(fname + ".txt");
    string str;
    while (getline(fin, str)) {
        cout << str << "\n";
    }
    fin.clear();
    if (fin.good()) {
        fin.close();
    }
    else {
        exit(2);
    }
}

//добавление строчки в конец
void addLine(string fname) {
    ofstream fout;
    fout.open(fname + ".txt", ios::app);
    string str;
    cin.get();
    getline(cin, str);
    fout << str << "\n";
    fout.clear();
    if (fout.good()) {
        fout.close();
    }
    else {
        exit(3);
    }
}

//получение по номеру
string getByNumber(string fname, int number) {
    if (numberCounter(fname) < number or number <= 0) {
        return "does not exist";
    }
    ifstream fin(fname + ".txt");
    string str;
    for (int i = 0; i < number; i++) {
        fin >> str;
    }
    fin.clear();
    if (fin.good()) {
        fin.close();
    }
    else {
        exit(4);
    }
    return str;
}

//считает количество чисел
int numberCounter(string fname) {
    ifstream fin(fname + ".txt");
    int n = 0;
    string str;
    while (fin >> str) {
        n++;
    }
    fin.clear();
    if (fin.good()) {
        fin.close();
    }
    else {
        exit(5);
    }
    return n;
}

//длина числа (своя функция)
int lengthOfNumber(int num) {
    int n = 0;
    if (num == 0) {
        return 1;
    }
    while (num > 0) {
        num /= 10;
        n++;
    }
    return n;
}

//умножение файла на последнюю запись
void var5(string fname) {
    ifstream fin(fname + ".txt");
    ofstream fout(fname + "_multiplied.txt");
    int n = 0;
    int last;
    int cur;
    string cur_str;
    //узнаем последнее число
    while (fin >> last) {
        n++;
    }
    int* rows = new int[n];//на максимальное возможное количество строк
    fin.clear();
    if (fin.good()) {
        fin.close();
    }
    else {
        exit(6);
    }

    fin.open(fname + ".txt");
    //количество символов в строке
    n = 0;
    while (getline(fin, cur_str)) {
        rows[n] = cur_str.length();
        n++;
    }
    fin.clear();
    if (fin.good()) {
        fin.close();
    }
    else {
        exit(7);
    }
    //запись в новый файл помноженных чисел
    fin.open(fname + ".txt");
    for (int i = 0; i < n; i++) {
        while (rows[i] > 0) {
            fin >> cur;
            rows[i] -= lengthOfNumber(cur) + 1;
            fout << cur * last;
            if (rows[i] > 0) {
                fout << " ";
            }
        }
        fout << "\n";
    }
    fin.clear();
    fout.clear();
    if (fin.good() and fout.good()) {
        fin.close();
    }
    else {
        exit(8);
    }
}