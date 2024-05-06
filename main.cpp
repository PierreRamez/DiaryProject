#include <iostream>
#include <string>
#include "RecordManager.h"
#include "FileHandler.h"
#include "PasswordManager.h"
#include "Menu.h"

using namespace std;

int main(){
    RecordManager recordManager;
    FileHandler fileHandler;
    PasswordManager passwordManager;
    Menu menu;
    string password = fileHandler.getPassword();
    int i = 0;

    menu.authenticateUser(passwordManager,fileHandler);
    menu.displayMainMenu();
    vector<RecordManager> records = fileHandler.readFromFile();
    menu.getUserChoice(recordManager, passwordManager, fileHandler, records);

    string pass;
    getline(cin,pass);
    passwordManager.setPassword(password,fileHandler);
}


