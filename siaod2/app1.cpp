#include "App1.h"
App1::App1() {
    zadanie1();
}

//приложение
void App1::zadanie1() {
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
            cout << "File " << str << "_multiplied.txt was created:\n";
            printFile(str + "_multiplied");
            cout << "\n---completed---\n\n";
            break;
        default:
            break;
        }
    }
    cout << "---exit---";
}
