#include <iostream>
#include <string>
#include <fstream>
#include "RecordManager.h"
#include "FileHandler.h"
#include "PasswordManager.h"

using namespace std;

int main(){
    RecordManager recordManager;
    FileHandler fileHandler;
    PasswordManager passwordManager;

    fileHandler.saveToFile(recordManager);
}


