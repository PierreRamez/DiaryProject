#include<iostream>
#include<string>
#include<fstream>
#include "PasswordManager.h"
using namespace std;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnreachableCode"
void PasswordManager::setPassword(string newPassword,FileHandler fileHandler) {
	string pass1, pass2;
	bool doubleCheck = false, passwordExists = false;
	char choice;

	if (passwordExists == true) { // to check if there's old password already set
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
					doubleCheck = true;

                    fileHandler.setPassword(password); // passing the password to the file if it matches

                    cout << "Your password is: " << newPassword << "\nremember it well!\n";
				}
				else {
					cout << "Passwords don't match, please re-enter your password:\n";
				}
			} while (doubleCheck == 0);
		}
		else {
			cout << "Password won't be changed!" << endl;
		}
	}

	else { // if this is the first password to be set

		do {
			cout << "Please enter your password:\n";
			getline(cin, pass1);

			cout << "Please enter your password again:\n"; // password checker
			getline(cin, pass2);

			if (pass1 == pass2) {
				cout << "Your password was set successfully!\n";
				newPassword= pass2;
				password = newPassword;
				doubleCheck = true;

                fileHandler.setPassword(password); // passing the password to the file if it matches

                cout << "Your password is: " << newPassword << "\nremember it well!\n";
                passwordExists = true;

            }

			else {
				cout << "Passwords don't match, please re-enter your password:\n";
			}
		} while (doubleCheck == 0);
	}
	}

bool PasswordManager::getPassword(string pass) {
    bool passwordMatches;
    if(pass==password){
    passwordMatches = true;
    }
    else
    {
     passwordMatches=false;
    }
    return passwordMatches; /* to check if the password entered is the
    same as the one stored in the file */
}

#pragma clang diagnostic pop