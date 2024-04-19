#include<iostream>
#include<string>
#include "PasswordManager.h"
using namespace std;

void PasswordManager::setPassword(string newPassword) {
	string pass1, pass2;
	bool doubleCheck = 0, passwordExist = 0;
	char choice;

	if (passwordExist = true) { // to check if there's old password already set
		cout << "Do you want to change your password? (Y/N)\n";
		cin >> choice;

		if (choice == 'Y' || 'y') {

			do {
				cout << "Please enter a new password:\n";
				getline(cin, pass1);

				cout << "Please enter your password again:\n";
				getline(cin, pass2);

				if (pass1 == pass2) {
					cout << "Your password was changed successfully!\n";
					newPassword = pass2;
					password = newPassword;
					doubleCheck = 1;

					cout << "Your password is: " << newPassword << "\nremember it well!\n";

				}
				else {
					cout << "Passwords don't match, please re-enter your password:\n";
				}
			} while (doubleCheck = 0);
		}
		else {
			cout << "Password won't be changed!" << endl;
		}
	}

	else { // if this is the first password to be set

		do {
			cout << "Please enter a your password:\n";
			getline(cin, pass1);

			cout << "Please enter your password again:\n"; // password checker
			getline(cin, pass2);

			if (pass1 == pass2) {
				cout << "Your password was set successfully!\n";
				newPassword= pass2;
				password = newPassword;
				doubleCheck = 1;

				cout << "Your password is: " << newPassword << "\nremember it well!\n";
			}

			else {
				cout << "Passwords don't match, please re-enter your password:\n";
			}
		} while (doubleCheck = 0);
	}
	}


string PasswordManager::getPassword() {
	cout << "Please enter ";
}