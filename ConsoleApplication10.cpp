#include<iostream>
#include <string>
using namespace std;
class RecordManager {
private:
	string taskDuration;
	string name;
	string address;
	string dateTime;
	
public:
	void addRecord(); 
	void viewRecord(); 
	void editRecord(); 
	void deleteRecord();
};

void RecordManager::addRecord() {
	cout << "Please enter the task duration: \n";
	cin >> taskDuration;
	cin.sync();

	cout << "Please enter the name:\n";
	getline(cin, name);

	cout << "Please enter the address: \n";
	getline(cin, address);

	cout << "Please enter the date and time (ex. time, DD//MM//YYYY): \n";
	getline(cin, dateTime); 
}

void RecordManager::viewRecord() {

	cout << "The task duration for the diary is: " << taskDuration << endl;
	cout << "The title of the diary is: " << name << endl;
	cout << "The address for the diary is: " << address << endl;
	cout << "The time of the diary is (" << dateTime << ")\n";

}

void RecordManager::editRecord() {
	char edit;
	bool correct = 0;
	do {
		cout << "If you want to edit the name enter N/n" << endl << "If you want to edit the address enter A/a" << endl
			<< "If you want to edit the task duration enter T/t" << endl <<
			"If you want to edit the date and time enter D/d\n";
		cin >> edit;
		if (edit == 'N' || edit == 'n') {
			cout << "Please enter a new name for the diary:\n";
			getline(cin, name);
			correct = 1;
		}
		else if (edit == 'A' || edit == 'a') {
			cout << "Please enter a new address for the diary:\n";
			getline(cin, address);
			correct = 1;
		}
		else if (edit == 'T' || edit == 't') {
			cout << "Please enter a new duration for the diary:\n";
			getline(cin, taskDuration);
			correct = 1;
		}
		else if (edit == 'D' || edit == 'd') {
			cout << "Please enter a new date and time for the diary:\n";
			getline(cin, dateTime);
			correct = 1;
		}
		else {
			cout << "Please enter a valid letter!\n";
		}
	} while (correct == 0);
}

void RecordManager::deleteRecord() {
	char del;
	bool correct = 0;
	cout << "Please select the record you want to delete\n";
	cout << "If you want to delete the name enter N/n" << endl << "If you want to delete the address enter A/a" << endl
		<< "If you want to delete the task duration enter T/t" << endl <<
		"If you want to delet the date and time enter D/d\n";
	cin >> del;
	if (del == 'N' || del == 'n') {
		cout << "The name of the diary is deleted successfully!\n";
		
		correct = 1;
	}
	else if (del == 'A' || del == 'a') {
		cout << "Please enter a new address for the diary:\n";
		getline(cin, address);
		correct = 1;
	}
	else if (del == 'T' || del == 't') {
		cout << "Please enter a new duration for the diary:\n";
		getline(cin, taskDuration);
		correct = 1;
	}
	else if (del == 'D' || del == 'd') {
		cout << "Please enter a new date and time for the diary:\n";
		getline(cin, dateTime);
		correct = 1;
	}
	else {
		cout << "Please enter a valid letter!\n";
	}
} while (correct == 0);
}