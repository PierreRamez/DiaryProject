#include "FileHandler.h"

using namespace std;


string fileName = "test.csv";


ifstream input(fileName);
ofstream output(fileName, ios::app);



void FileHandler::saveToFile(RecordManager recordManager) {
    output << recordManager.getTaskDur() << ',' << recordManager.getName() << ',' << recordManager.getAddress() <<
    ',' << recordManager.getDateTime() << '\n';
}

vector<RecordManager> FileHandler::readFromFile() {
    string line;
    vector<RecordManager> records;

    while(getline(input, line)){
        stringstream ss(line);
        vector<string> fields;

        string field;
        while(getline(ss, field, ',')){
            fields.push_back(field);
        }

        RecordManager record;
        record.setTaskDur(fields.at(0));
        record.setName(fields.at(1));
        record.setAddress(fields.at(2));
        record.setDateTime(fields.at(3));
        records.push_back(record);
    }
    return records;
}

void FileHandler::updateFile(const vector<RecordManager>& records) {
    ofstream update(fileName);
    for(const auto& record : records){
        saveToFile(record);
    }
}


void FileHandler::setPassword(string password) {
    ofstream createPass("password.txt",ios::out);
    createPass << password;
    createPass.close();
}
