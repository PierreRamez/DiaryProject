#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

void Menu::displayMainMenu() {
    cout << "\tMAIN MENU"<<endl<<"________________________" <<
         endl<<"ADD DIARY       [1]" << endl<<
         "VIEW DIARY      [2]" << endl<<
         "EDIT DIARY      [3]" << endl<<
         "DELETE DIARY    [4]" << endl<<
         "EDIT PASSWORD   [5]" << endl<<
         "EXIT            [6]" << endl;
}

void Menu::getUserChoice(int, RecordManager recordManager, PasswordManager passwordManager) {
    int userChoice;
    do {
        cin >> userChoice;

        if (1 > userChoice || userChoice > 6) {
            cout << "Please enter a valid choice!\n";
        }

    } while (1 > userChoice || userChoice > 6);
    string newPassword;
    switch(userChoice){
        case 1:
            recordManager.addRecord();
            break;
        case 2:
            displayMainMenu();
            break;
        case 3:
            char editChoice;

            do {
                cout << "Please choose the record you want to edit:\n(N : name)\n(A : address)\n(T : duration)\n(D : date & time)\n";
                cin >> editChoice;

                if (editChoice != 'N' && editChoice != 'n' && editChoice != 'A' && editChoice != 'a' && editChoice != 'T' && editChoice != 't' && editChoice != 'D' && editChoice != 'd')
                {
                    cout << "Please enter a valid choice!\n";
                }

            } while (editChoice != 'N' && editChoice != 'n' && editChoice != 'A' && editChoice != 'a' && editChoice != 'T' && editChoice != 't' && editChoice != 'D' && editChoice != 'd');


            recordManager.editRecord(editChoice);
            break;
        case 4:
            recordManager.deleteRecord();
            break;
        case 5:
            cout << "Please enter a new password:\n";

            getline(cin, newPassword);
            passwordManager.setPassword(newPassword);
            break;
        case 6:
            break;
    }
}
void Menu::displayRecordList(RecordManager recordManager) {
    recordManager.viewRecord();
}
