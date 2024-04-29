#include "FileHandler.h"
#include <fstream>
#include <filesystem>

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

void FileHandler::readFromFile() {

}

void FileHandler::updateFile() {

}

