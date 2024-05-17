#ifndef DIARYPROJECT_MENU_H
#define DIARYPROJECT_MENU_H
#include<iostream>
#include<fstream>
#include<string>
#include "RecordManager.h"
#include "PasswordManager.h"
#include "FileHandler.h"

using namespace std;

class Menu
{
public:
    void displayMainMenu();
    bool getUserChoice(vector<RecordManager> &);
    int getUserChoice();
    void displayRecordList(vector<RecordManager>);
    void editRecord(vector<RecordManager>&);
    void deleteRecord(vector<RecordManager>&);
    bool authenticateUser();
};
#endif