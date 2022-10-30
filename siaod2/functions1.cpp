#include "functions1.h"
//�������� � ���������� �����
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

//������ �����������
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

//���������� ������� � �����
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

//��������� �� ������
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

//������� ���������� �����
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

//����� ����� (���� �������)
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

//��������� ����� �� ��������� ������
void var5(string fname) {
    ifstream fin(fname + ".txt");
    ofstream fout(fname + "_multiplied.txt");
    int n = 0;
    int last;
    int cur;
    string cur_str;
    //������ ��������� �����
    while (fin >> last) {
        n++;
    }
    int* rows = new int[n];//�� ������������ ��������� ���������� �����
    fin.clear();
    if (fin.good()) {
        fin.close();
    }
    else {
        exit(6);
    }

    fin.open(fname + ".txt");
    //���������� �������� � ������
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
    //������ � ����� ���� ����������� �����
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