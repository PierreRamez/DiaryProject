#include "FileHandler.h"

using namespace std;
using namespace filesystem;

string targetDir = "/home/ms/Documents/Records/";
string fileName = "Test.csv";


ifstream input(targetDir + fileName);
ofstream output(targetDir + fileName, ios::app);


FileHandler::FileHandler() {
    create_directory(targetDir);
}

void FileHandler::saveToFile(RecordManager recordManager) {
    if(input.peek() != ifstream::traits_type::eof())
        output << '\n';
    output << recordManager.getName() << ',' << recordManager.getDateTime() << ','  << recordManager.getAddress()
    << ',' << recordManager.getTaskDur();
}

vector<RecordManager> FileHandler::readFromFile() {
    vector<string> fields;
    string line;
    vector<RecordManager> records;
    RecordManager record;
    int idx = 0;

    while(getline(input, line)){
        stringstream ss(line);

        string field;
        while(getline(ss, field, ',')){
            fields.push_back(field);
        }

        record.setName(fields.at(0));
        record.setDateTime(fields.at(1));
        record.setAddress(fields.at(2));
        record.setTaskDur(fields.at(3));
        records.push_back(record);
        idx++;
    }
    return records;
}

void FileHandler::updateFile() {

}
