#ifndef DIARYPROJECT_MENU_H
#define DIARYPROJECT_MENU_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Menu
{
public:
	void displayMainMenu();
	void displayRecordList();
	void getUserChoice(string);
};
#endif