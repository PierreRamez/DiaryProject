#ifndef DIARYPROJECT_MENU_H
#define DIARYPROJECT_MENU_H
#include<iostream>
#include<fstream>
#include<string>
#include "RecordManager.h"
#include "PasswordManager.h"

using namespace std;

class Menu
{
public:
    void displayMainMenu(RecordManager);
    void getUserChoice(int, RecordManager, PasswordManager);
    void displayRecordList(RecordManager);

};
#endif