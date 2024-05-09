#include "Menu.h"
#include <iostream>
#include <string>

using namespace std;

void Menu::displayMainMenu() {
    cout << "\tMAIN MENU" << endl << "__________________________" <<
    endl << "ADD DIARY       [1]" << endl <<
    "VIEW DIARY      [2]" << endl <<
    "EDIT DIARY      [3]" << endl <<
    "DELETE DIARY    [4]" << endl <<
    "EDIT PASSWORD   [5]" << endl <<
    "EXIT            [6]" << endl;
}

void Menu::getUserChoice(RecordManager recordManager, PasswordManager passwordManager, FileHandler fileHandler, vector<RecordManager> records) {
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
            recordManager.addRecord(fileHandler);
            break;
        case 2:
            if(records.size() !=0 )
                displayRecordList(records);
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
//            cout << "Please enter a new password:\n";
//            cin.ignore();
//            getline(cin, newPassword);
            passwordManager.setPassword(newPassword, fileHandler);
            break;
        case 6:
            break;
    }
}
void Menu::displayRecordList(vector<RecordManager> records) {
    for(int i = 0; i < records.size(); i++){
        cout << '[' << i+1 << "] ";
        records.at(i).viewRecord();
    }
}

bool Menu::authenticateUser(PasswordManager passwordManager,FileHandler fileHandler) {
    string password;
    bool passExist = !passwordManager.checkPasswordAvailability(); //for some reason this works in reverse so ! lol

    if (passExist) {
        cout << "Please enter your password to access your records:\n";
        cin >> password;
        bool auth = passwordManager.getPassword(password);

        if (auth) {
            cout << "User authenticated\n";
        } else
            cout << "Incorrect password\n";
        return auth;
    } else {
        passwordManager.setPassword(password,fileHandler);
        return true;
    }
}


