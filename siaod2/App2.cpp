#include "App2.h"

App2::App2()
{
	zadanie2();
}

void App2::zadanie2()
{
	Patient* temp = nullptr;
	string str;
	cout << "Enter file name: ";
	cin >> str;
	int* arr;
	int data;
	cout << "How much notes? ";
	cin >> data;
	createTextFile(str + ".txt", data);
	int task = 1;
	//создаем бинарник
	ofstream b0;
	b0.open(str + "_bin.dat", ios::binary);
	b0.close();
	fstream b, btemp;
	//открываем для записи и чтения
	b.open(str + "_bin.dat", ios::binary | ios::out | ios::in);
	cout << "File " << str << ".txt was created and filled with random notes. Empty file " << str << "_bin.dat was created.";
	while (task > 0 and task < 8) {
		cout << "Choose task:\n1) To binary\n2) To text\n3) Print from binary file\n4) Print row\n5) Delete by key\n6) Create new file with only illness\n7) New doctor to\n";
		cin >> task;
		switch (task)
		{
		case 1:
			textToBinary(str + ".txt", b);
			cout << "Binary file is " << str << "_bin.dat\n";
			cout << "---completed---\n\n";
			break;
		case 2:
			binaryToText(b, str + "_text.txt");
			cout << "Text file is " << str << "_text.txt\n";
			cout << "---completet---\n\n";
			break;
		case 3:
			printAllBinary(b);
			cout << "---completed---\n\n";
			break;
		case 4:
			cout << "Row = ";
			cin >> data;
			cout << "Row " << data << ": ";
			temp = getRowBinary(b, data);
			if (temp) {
				cout << temp->card << " " << temp->illness << " " << temp->doctor;
			}
			else {
				cout << "no data";
			}
			cout << "\n---completed---\n\n";
			break;
		case 5:
			cout << "Key to delete = ";
			cin >> data;
			if (deleteByKey(b, data)) {
				cout << "removed";
			}
			else {
				cout << "not found";
			}
			cout << "\n---completed---\n\n";
			break;
		case 6:
			cout << "Illness = ";
			cin >> data;
			onlyPatientsWith(b, str + "_" + to_string(data) + ".dat", data);
			cout << str << "_" << data << ".dat:\n";
			btemp.open(str + "_" + to_string(data) + ".dat", ios::binary | ios::out | ios::in);
			printAllBinary(btemp);
			btemp.close();
			cout << "---completed---\n\n";
			break;
		case 7:
			cout << "How much patients? ";
			cin >> data;
			arr = new int[data];
			for (int i = 0; i < data; i++) {
				cout << i + 1 << ") ";
				cin >> arr[i];
			}
			cout << "Who is new doctor? ";
			char doc[16];
			cin >> doc;
			newDoctorFor(b, arr, data, doc);
			cout << "---completed---\n\n";
			delete[] arr;
			break;
		default:
			break;
		}
	}
	b.close();
	cout << "---exit---\n";
}
