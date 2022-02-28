#include "Worker.h"

Worker::Worker(const string& firstName, const string& secondName, int age, const string& gender, vector<Task> completed, vector<Task> active) {
    _firstName.assign(firstName);
    _secondName.assign(secondName);
    _age = age;
    _gender.assign(gender);
    _completed = move(completed);
    _active = move(active);
}

int Worker::completedCount() const {
    return _completed.size();
}

int Worker::activeCount() const {
    return _active.size();
}

double Worker::activeAvgDifficulty() const {
    double difficultySum = 0.0;

    for (const Task& task: _active) {
        difficultySum += task._difficulty;
    }

    return difficultySum / activeCount();
}
