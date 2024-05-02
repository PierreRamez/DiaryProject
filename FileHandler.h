#ifndef DIARYPROJECT_FILEHANDLER_H
#define DIARYPROJECT_FILEHANDLER_H


#include "RecordManager.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

class FileHandler {
    string directory;
public:
    FileHandler();
    void saveToFile(RecordManager);
    std::vector<RecordManager> readFromFile();
    void updateFile(std::vector<RecordManager>);
    void clearFile();
    void setDirectory(const string &);
};


#endif //DIARYPROJECT_FILEHANDLER_H
