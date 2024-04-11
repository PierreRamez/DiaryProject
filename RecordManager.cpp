#include <string>
#include <iostream>
#include "RecordManager.h"

using namespace std;

void RecordManager::addRecord() {
	cout << "Please enter the task duration: \n";
	cin >> taskDuration;
	cin.ignore();

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
	bool correct = true;
	do {
		cout << "If you want to edit the name enter N/n" << endl << "If you want to edit the address enter A/a" << endl
                  << "If you want to edit the task duration enter T/t" << endl <<
                  "If you want to edit the date and time enter D/d\n";
		cin >> edit;
		if (edit == 'N' || edit == 'n') {
			cout << "Please enter a new name for the diary:\n";
			getline(cin, name);
		}
		else if (edit == 'A' || edit == 'a') {
			cout << "Please enter a new address for the diary:\n";
			getline(cin, address);
		}
		else if (edit == 'T' || edit == 't') {
			cout << "Please enter a new duration for the diary:\n";
			getline(cin, taskDuration);
		}
		else if (edit == 'D' || edit == 'd') {
			cout << "Please enter a new date and time for the diary:\n";
			getline(cin, dateTime);
		}
		else {
			cout << "Please enter a valid letter!\n";
            correct = false;
		}
	} while (!correct);
}

void RecordManager::deleteRecord() {
	char del;
	bool correct = true;
    do{
	    cout << "Please select the record you want to delete\n";
    	cout << "If you want to delete the name enter N/n" << endl << "If you want to delete the address enter A/a" << endl
                  << "If you want to delete the task duration enter T/t" << endl <<
                 "If you want to delete the date and time enter D/d\n";
    	cin >> del;
    	if (del == 'N' || del == 'n') {
    		cout << "The name of the diary is deleted successfully!\n";
            //@todo:implement deleting
	    }
    	else if (del == 'A' || del == 'a') {
    		cout << "Please enter a new address for the diary:\n";
            getline(cin, address);
    	}
    	else if (del == 'T' || del == 't') {
    		cout << "Please enter a new duration for the diary:\n";
    		getline(cin, taskDuration);
	    }
	    else if (del == 'D' || del == 'd') {
		    cout << "Please enter a new date and time for the diary:\n";
		    getline(cin, dateTime);
    	}
	    else {
		    cout << "Please enter a valid letter!\n";
            correct = false;
	    }
    }while (!correct);
}
