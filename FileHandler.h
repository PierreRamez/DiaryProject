#ifndef DIARYPROJECT_FILEHANDLER_H
#define DIARYPROJECT_FILEHANDLER_H


#include "RecordManager.h"

class FileHandler {

public:
    void saveToFile(RecordManager);
    void readFromFile();
    void updateFile();
};


#endif //DIARYPROJECT_FILEHANDLER_H
