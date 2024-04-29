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

    //fileHandler.saveToFile(recordManager);
    vector<RecordManager> records = fileHandler.readFromFile();
    for(auto record : records){
        cout << record.getName() << '\n';
        cout << record.getAddress() << '\n';
        cout << record.getDateTime() << '\n';
        cout << record.getTaskDur() << '\n';
    }
}


