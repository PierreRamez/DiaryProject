#ifndef DIARYPROJECT_FILEHANDLER_H
#define DIARYPROJECT_FILEHANDLER_H


#include "RecordManager.h"

class FileHandler {
public:
    FileHandler();
    void saveToFile(RecordManager);
    void readFromFile();
    void updateFile();
    void deleteFile();
};


#endif //DIARYPROJECT_FILEHANDLER_H
