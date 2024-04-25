#include "Menu.h"
#include "RecordManager.h"
#include "PasswordManager.h"
#include<iostream>
#include<string>

using namespace std;


void Menu::displayMainMenu() {
	cout << "\tMAIN MENU"<<endl<<"________________________" <<
		endl<<"ADD DIARY       [1]" << endl<<
		"VIEW DIARY      [2]" << endl<<
		"EDIT DIARY      [3]" << endl<<
		"DELETE DIARY    [4]" << endl<<
		"EDIT PASSWORD   [5]" << endl<<
		"EXIT            [6]" << endl;
}

void Menu::getUserChoice(int) {
	int userChoice;

		do {
			cin >> userChoice;

			if (1 > userChoice || userChoice > 6) {
				cout << "Please enter a valid choice!\n";
			}

		} while (1 > userChoice || userChoice > 6);

		if (userChoice == 1) {
			RecordManager::addRecord();
		}

		if (userChoice == 2) {
			Menu::displayRecordList();
		}

		else if (userChoice == 3) {
			char editChoice;

			do {
				cout << "Please choose the record you want to edit:\n(N : name)\n(A : address)\n(T : duration)\n(D : date & time)\n";
				cin >> editChoice;

				if (editChoice != 'N' || 'n' || 'A' || 'a' || 'T' || 't' || 'D' || 'd') {
					cout << "Please enter a valid choice!\n";
				}

			} while (editChoice != 'N' || 'n' || 'A' || 'a' || 'T' || 't' || 'D' || 'd');

			RecordManager::editRecord(editChoice);
		}

		else if (userChoice == 4) {
			RecordManager::deleteRecord();
		}

		else if (userChoice == 5) {
			string newPassword;

			cout << "Please enter a new password:\n";
			getline(cin, newPassword);

			PasswordManager::setPassword(newPassword);
		}

		else if (userChoice == 6) {
			break;		// not sure if this is right to be done this way
		}
}
void Menu::displayRecordList() {
	RecordManager::viewRecord();
}