#ifndef DIARYPROJECT_FILEHANDLER_H
#define DIARYPROJECT_FILEHANDLER_H


#include "RecordManager.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

class FileHandler {
public:
    FileHandler();
    void saveToFile(RecordManager);
    std::vector<RecordManager> readFromFile();
    void updateFile();
};


#endif //DIARYPROJECT_FILEHANDLER_H
