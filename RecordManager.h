#ifndef DIARYPROJECT_RECORDMANAGER_H
#define DIARYPROJECT_RECORDMANAGER_H
#include <string>
using std::string;

class RecordManager {

    string taskDuration;
    string name;
    string address;
    string dateTime;
public:
    void addRecord();
    void viewRecord();
    void editRecord(char);
    void deleteRecord();

    void setTaskDur(string);
    void setName(string);
    void setAddress(string);
    void setDateTime(string);

    string getTaskDur();
    string getName();
    string getAddress();
    string getDateTime();
};


#endif //DIARYPROJECT_RECORDMANAGER_H
