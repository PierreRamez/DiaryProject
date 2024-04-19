#pragma once
#include<iostream>
#include <string>

using namespace std;

class PasswordManager
{
		string password;
	public:
		string getPassword();
		void setPassword(string newPassword);
};

