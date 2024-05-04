#include "FileHandler.h"

using namespace std;

string targetDir = "/home/ms/Documents/Records/";
string fileName = "Test.csv";


ifstream input(targetDir + fileName);
ofstream createPass("password.txt",ios::out);
ifstream checkPass("password.txt");
ofstream output(targetDir + fileName, ios::app);


FileHandler::FileHandler() {
    filesystem::create_directory(targetDir);
}

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

void FileHandler::updateFile(vector<RecordManager>) {

}

void FileHandler::clearFile() {
    filesystem::remove(targetDir + fileName);
}

void FileHandler::setDirectory(const string &dir) {
    directory = dir;
}

void FileHandler::setPassword(string password) {
    createPass<<password;
}

string FileHandler::getPassword(PasswordManager passwordManager) {
    string pass;
    getline (checkPass,pass);
    passwordManager.getPassword(pass);
}