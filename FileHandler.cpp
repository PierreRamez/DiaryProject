#include "FileHandler.h"

using namespace std;

string targetDir = "/home/ms/Documents/Records/";
string fileName = "test.csv";


ifstream input(fileName);
ofstream output(fileName, ios::app);



void FileHandler::saveToFile(RecordManager recordManager) {
    output << recordManager.getName() << ',' << recordManager.getDateTime() << ','  << recordManager.getAddress()
    << ',' << recordManager.getTaskDur() << '\n';
}

vector<RecordManager> FileHandler::readFromFile() {

    string line;
    vector<RecordManager> records;

    int idx = 0;

    while(getline(input, line)){
        stringstream ss(line);
        vector<string> fields;

        string field;
        while(getline(ss, field, ',')){
            fields.push_back(field);
        }

        RecordManager record;
        record.setName(fields.at(0));
        record.setDateTime(fields.at(1));
        record.setAddress(fields.at(2));
        record.setTaskDur(fields.at(3));
        records.push_back(record);
        idx++;
    }
    return records;
}

void FileHandler::updateFile(const vector<RecordManager>& records) {
    ofstream update(fileName, ios::trunc);
    for(const auto& record : records){
        saveToFile(record);
    }
}

void FileHandler::setDirectory(const string &dir) {
    targetDir = dir;
}

void FileHandler::setPassword(string password) {
    ofstream createPass("password.txt",ios::out);
    createPass << password;
    createPass.close();
}
