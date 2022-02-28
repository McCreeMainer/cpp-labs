#include "Task.h"

Task::Task(int difficulty, string description, double cost) {
    _difficulty = difficulty;
    _description.assign(description);
    _cost = cost;
}
