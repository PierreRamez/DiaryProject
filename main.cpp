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

    if(!menu.authenticateUser(passwordManager,fileHandler)) return 0; //if user authentication fails, quit program
    menu.displayMainMenu();
    vector<RecordManager> records = fileHandler.readFromFile();
    menu.getUserChoice(recordManager, passwordManager, fileHandler, records);
    fileHandler.updateFile(records);
}


