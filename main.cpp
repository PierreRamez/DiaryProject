#include "main.h"
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
    system(CLEAR);
    if(!menu.authenticateUser()) return 0; //if user authentication fails, quit program
    records = fileHandler.readFromFile();
    system(CLEAR);
    menu.displayMainMenu();

    menu.getUserChoice(records);
    do{
        menu.displayMainMenu();
    }while(!menu.getUserChoice(records));
    fileHandler.updateFile(records);
}


