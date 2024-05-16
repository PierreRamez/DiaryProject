#include "RecordManager.h"
#include "FileHandler.h"
#include "PasswordManager.h"
#include "Menu.h"

using namespace std;

int main(){
    FileHandler fileHandler;
    PasswordManager passwordManager;
    Menu menu;
    vector<RecordManager> records;
    if(!menu.authenticateUser(passwordManager,fileHandler)) return 0; //if user authentication fails, quit program
    records = fileHandler.readFromFile();
    menu.displayMainMenu();

    menu.getUserChoice(passwordManager, fileHandler, records);
    do{
        menu.displayMainMenu();
    }while(!menu.getUserChoice(passwordManager, fileHandler, records));
    fileHandler.updateFile(records);
}


