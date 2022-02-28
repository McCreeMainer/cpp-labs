#ifndef LAB1_TASK_H
#define LAB1_TASK_H


#include <string>
#include <utility>
using namespace std;

class Task {
public:
    int _difficulty;
    string _description;
    double _cost;

    Task(int difficulty, string description, double cost);
};


#endif //LAB1_TASK_H
