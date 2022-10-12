#include "App2.h"

App2::App2()
{
	zadanie2();
}

void App2::zadanie2()
{
    string str;
    cout << "Enter file name: ";
    cin >> str;
    int* arr;
    createTextFile(str);
    int data;
    int task = 1;
    cout << "File " << str << ".txt was created and filled with random nodes. ";
    
    while (task > 0 and task < 8) {
        cout << "Choose task:\n1) To binary\n2) To text\n3) Print from binary file\n4) Print row\n5) Delete by key\n6) Create new file with only illness\n7) New doctor to\n";
        cin >> task;
        switch (task)
        {
        case 1:
            textToBinary(str);
            cout << "Binary file is " << str << "_bin.dat\n";
            cout << "---completed---\n\n";
            break;
        case 2:
            binaryToText(str);
            cout << "Text file is " << str << "_text.txt\n";
            cout << "---completet---\n\n";
            break;
        case 3:
            printAllBinary(str);
            cout << "\n---completed---\n\n";
            break;
        case 4:
            cout << "Row = ";
            cin >> data;
            cout << "Row " << data << ": ";
            printRowBinary(str, data);
            cout << "\n---completed---\n\n";
            break;
        case 5:
            cout << "Key = ";
            cin >> data;
            deleteByKey(str, data);
            cout << "\n---completed---\n\n";
            break;
        case 6:
            cout << "Illness = ";
            cin >> data;
            onlyPatientsWith(str, data);
            cout << str << data << "_bin.dat:\n";
            printAllBinary(str + to_string(data));
            cout << "\n---completed---\n\n";
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
            newDoctorFor(str, arr, data, doc);
            cout << "\n---completed---\n\n";
            delete [] arr;
            break;
        default:
            break;
        }
    }
    cout << "---exit---";
}
