#ifndef DIARYPROJECT_PASSWORDMANAGER_H
#define DIARYPROJECT_PASSWORDMANAGER_H
#include <iostream>
#include <string>
#include "FileHandler.h"

using namespace std;

class PasswordManager
{
		string password;
	public:
		bool getPassword(string);
		void setPassword(string newPassword,FileHandler fileHandler);
};

#endif