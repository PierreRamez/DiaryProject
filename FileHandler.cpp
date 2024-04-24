#include "FileHandler.h"
#include <fstream>
#include <filesystem>

using namespace std;
using namespace filesystem;

string targetDir = "/home/ms/Documents/Records/";
ifstream input;
ofstream output;
string fileName;

FileHandler::FileHandler() {
    create_directory(targetDir);
}

void FileHandler::saveToFile(RecordManager recordManager) {
    output << recordManager.getName() << '\n' << recordManager.getDateTime() << '\n' << recordManager.getAddress()
    << '\n' << recordManager.getTaskDur();
}

void FileHandler::readFromFile() {

}

void FileHandler::updateFile() {

}

void FileHandler::deleteFile(){

}
