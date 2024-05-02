#include <iostream>
#include <string>
#include "RecordManager.h"
#include "FileHandler.h"
#include "PasswordManager.h"

using namespace std;

int main(){
    RecordManager recordManager;
    FileHandler fileHandler;
    PasswordManager passwordManager;

    vector<RecordManager> records = fileHandler.readFromFile();
}


