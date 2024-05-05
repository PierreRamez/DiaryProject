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
    void getUserChoice(RecordManager, PasswordManager, FileHandler, vector<RecordManager>);
    void displayRecordList(vector<RecordManager>);
    bool authenticateUser(PasswordManager,FileHandler);
};
#endif