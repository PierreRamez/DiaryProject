#ifndef DIARYPROJECT_RECORDMANAGER_H
#define DIARYPROJECT_RECORDMANAGER_H

using std::string;

class RecordManager {

    string taskDuration;
    string name;
    string address;
    string dateTime;
public:
    void addRecord();
    void viewRecord();
    void editRecord();
    void deleteRecord();
};


#endif //DIARYPROJECT_RECORDMANAGER_H
