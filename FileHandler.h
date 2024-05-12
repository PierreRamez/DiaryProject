#ifndef DIARYPROJECT_FILEHANDLER_H
#define DIARYPROJECT_FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include "RecordManager.h"

class FileHandler {
public:
    void saveToFile(RecordManager);
    std::vector<RecordManager> readFromFile();
    void updateFile(const std::vector<RecordManager>&);
    void setPassword(string);
};


#endif //DIARYPROJECT_FILEHANDLER_H
