#include "FileHandler.h"
#include <fstream>
using namespace std;

ifstream input;
ofstream output("/home/ms/Documents/Records/TestRecord.txt");

void FileHandler::saveToFile(RecordManager recordManager) {
    output << recordManager.getName() << '\n' << recordManager.getDateTime() << '\n' << recordManager.getAddress()
    << '\n' << recordManager.getTaskDur();
}

void FileHandler::readFromFile() {

}

void FileHandler::updateFile() {

}
