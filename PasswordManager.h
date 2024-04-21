#ifndef DIARYPROJECT_PASSWORDMANAGER_H
#define DIARYPROJECT_PASSWORDMANAGER_H
#include <iostream>
#include <string>

using namespace std;

class PasswordManager
{
		string password;
	public:
		string getPassword();
		void setPassword(string newPassword);
};

#endif