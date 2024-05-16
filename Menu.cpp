#include "Menu.h"
#include "main.h"
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

bool Menu::getUserChoice(PasswordManager passwordManager, FileHandler fileHandler, vector<RecordManager> &records) {
    int userChoice;
    bool exit;
    RecordManager record;
//    do {
//        cin >> userChoice;
//        if (1 > userChoice || userChoice > 6) {
//            cout << "Please enter a valid choice!\n";
//        }
//
//    } while (1 > userChoice || userChoice > 6);
    cin >> userChoice;
    string newPassword;
    switch(userChoice){
        case 1:
            record.addRecord(fileHandler);
            records.push_back(record);
            exit = false;
            break;
        case 2:
            if(!records.empty())
                displayRecordList(records);
            else
                cout << "\nThere are no records available.\n";
            exit = false;
            break;
        case 3:
            editRecord(records);
            exit = false;
            break;
        case 4:
            deleteRecord(records);
            exit = false;
            break;
        case 5:
            passwordManager.setPassword(newPassword, fileHandler);
            exit = false;
            break;
        case 6:
            exit = true;
            break;
        default:
            exit = false;
            cout << "Please enter a valid option\n";
            break;
    }
    system(CLEAR);
    return exit;
}

void Menu::displayRecordList(vector<RecordManager> records) {
    for(int i = 0; i < records.size(); i++){
        cout << '[' << i+1 << "] ";
        records.at(i).viewRecord();
    }
}

bool Menu::authenticateUser(PasswordManager passwordManager,FileHandler fileHandler) {
    string password;
    bool passExist = passwordManager.checkPasswordAvailability();

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

void Menu::editRecord(vector<RecordManager> &records) {
    char editChoice;
    displayRecordList(records);
    int diaryChoice = getUserChoice();
    do {
        cout << "Please choose the record you want to edit:\n(N : name)\n(A : address)\n(T : duration)\n(D : date & time)\n";
        cin >> editChoice;

        if (editChoice != 'N' && editChoice != 'n' && editChoice != 'A' && editChoice != 'a' && editChoice != 'T' && editChoice != 't' && editChoice != 'D' && editChoice != 'd')
        {
            cout << "Please enter a valid choice!\n";
        }

    } while (editChoice != 'N' && editChoice != 'n' && editChoice != 'A' && editChoice != 'a' && editChoice != 'T' && editChoice != 't' && editChoice != 'D' && editChoice != 'd');


    records.at(diaryChoice - 1).editRecord(editChoice);
}

void Menu::deleteRecord(vector<RecordManager> &records) {
    displayRecordList(records);
    int diaryChoice = getUserChoice();
    auto itr = records.begin() + diaryChoice;
    records.erase(itr);
}

int Menu::getUserChoice() {
    int diaryChoice;
    cout << "\nPlease select a diary.\n";
    cin >> diaryChoice;
    return diaryChoice;
}
