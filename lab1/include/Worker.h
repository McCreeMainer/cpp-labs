#ifndef LAB1_WORKER_H
#define LAB1_WORKER_H


#include <string>
#include <utility>
#include <vector>
#include "Task.h"

using namespace std;

class Worker {
public:
    string _firstName;
    string _secondName;
    int _age;
    string _gender;
    vector<Task> _completed;
    vector<Task> _active;

    Worker(const string &firstName,
           const string &secondName,
           int age,
           const string &gender,
           vector<Task> completed,
           vector<Task> active);

    int completedCount() const;

    int activeCount() const;

    double activeAvgDifficulty() const;
};

#endif //LAB1_WORKER_H
