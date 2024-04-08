#include <iostream>
#include "fun_console.h"
#include "ASDList.h"

using namespace std;

void printMenu() {
    cls();
    SetColor(White, Blue);
    GotoXY(2, 1);
    cout << "====== Menu ======";
    SetColor(LightGray, Black);
    GotoXY(2, 3);
    cout << "1. Add Element";
    GotoXY(2, 4);
    cout << "2. Count Even/Odd/Negative";
    GotoXY(2, 5);
    cout << "3. Exit";
    GotoXY(2, 8);
    cout << "Choose an option: ";
}

int main() {
    ASDList<int> myList;
    int option;
    bool exitMenu = false;

    do {
        printMenu();
        cin >> option;

        switch (option) {
        case 1: {
            int num;
            cout << "Enter a number to add: ";
            cin >> num;
            myList.addElement(num);
            break;
        }
        case 2: {
            int evenCount, oddCount, negativeCount;
            myList.countEvenOddNegative(evenCount, oddCount, negativeCount);
            GotoXY(2, 9);
            cout << "Even: " << evenCount << endl;
            GotoXY(2, 10);
            cout << "Odd: " << oddCount << endl;
            GotoXY(2, 11);
            cout << "Negative: " << negativeCount << endl;
            break;
        }
        case 3: {
            exitMenu = true;
            break;
        }
        default:
            break;
        }

        system("pause");
    } while (!exitMenu);

    return 0;
}
