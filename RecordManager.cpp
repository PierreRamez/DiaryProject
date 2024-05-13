#include <string>
#include <iostream>
#include "RecordManager.h"
#include "FileHandler.h"
using namespace std;


void RecordManager::addRecord(FileHandler fileHandler) {
    cin.ignore();
    cout << "Please enter the task duration: \n";
    getline (cin,taskDuration);

    cout << "Please enter the name:\n";
    getline(cin, name);

    cout << "Please enter the address: \n";
    getline(cin, address);

    cout << "Please enter the date and time (ex. time, DD//MM//YYYY): \n";
    getline(cin, dateTime);


    fileHandler.saveToFile(*this);
}

void RecordManager::viewRecord() {
    cout << "The task duration for the diary is: " << taskDuration << endl;
    cout << "The title of the diary is: " << name << endl;
    cout << "The address for the diary is: " << address << endl;
    cout << "The time of the diary is (" << dateTime << ")\n";
}

void RecordManager::editRecord(char edit) {
    cin.ignore();
    if (edit == 'N' || edit == 'n') {
        cout << "Please enter a new name for the diary:\n";
        getline(cin, name);
    }
    else if (edit == 'A' || edit == 'a') {
        cout << "Please enter a new address for the diary:\n";
        getline(cin, address);
    }
    else if (edit == 'T' || edit == 't') {
        cout << "Please enter a new duration for the diary:\n";
        getline(cin, taskDuration);
    }
    else if (edit == 'D' || edit == 'd') {
        cout << "Please enter a new date and time for the diary:\n";
        getline(cin, dateTime);
    }
}

string RecordManager::getTaskDur(){
    return taskDuration;
}

string RecordManager::getAddress(){
    return address;
}

string RecordManager::getName(){
    return name;
}

string RecordManager::getDateTime(){
    return dateTime;
}

void RecordManager::setTaskDur(string dur) {
    taskDuration = dur;
}

void RecordManager::setName(string nam) {
    name = nam;
}

void RecordManager::setAddress(string addr) {
    address = addr;
}

void RecordManager::setDateTime(string time) {
    dateTime = time;
}
