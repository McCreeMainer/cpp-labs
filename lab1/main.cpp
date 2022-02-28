#include <windows.h>
#include "Worker.h"
#include <list>

using namespace std;

void fillTestData(vector<Worker> &);

void task1(vector<Worker> &);

void task2(vector<Worker> &);

void task3(vector<Worker> &);

int main() {

    SetConsoleOutputCP(CP_UTF8);

    vector<Worker> testData;
    fillTestData(testData);

    task1(testData);
    printf("\n----------------------------------------------------------------------------\n");
    task2(testData);
    printf("\n----------------------------------------------------------------------------\n");
    task3(testData);
    printf("\n----------------------------------------------------------------------------\n");

    return 0;
}

void fillTestData(vector<Worker> &testData) {

    Worker temp1("Михаил", "Зубенко", 34, "м",
                 {
                         {1, "Представиться",                 0},
                         {1, "Попасть в Шумиловский городок", 5},
                 },
                 {
                         {2, "Получить специальность", 0},
                         {3, "Стать Мафиозником",      100000000},
                 });
    testData.push_back(temp1);

    Worker temp2("Михал Палыч", "Терентьев", 15, "м",
                 {
                         {1, "Внести деньги в капитал прожиточного минимума", 10000},
                 },
                 {
                         {3, "Узнать, как там с деньгами",            40},
                         {3, "Узнать, как обстоит вопрос с деньгами", 40},
                         {3, "Узнать, что с деньгами",                40},
                 });
    testData.push_back(temp2);

    Worker temp3("Эрнест", "Хеммингуэй", 123, "м",
                 {
                         {3, "Поспорить", 0},
                 },
                 {
                         {3, "Написать самый короткий рассказ, способный растрогать любого", 6},
                 });
    testData.push_back(temp3);

    Worker temp4("Биг", "Босс", 79, "м",
                 {
                         {3, "Создать ЧВК",      1488},
                         {3, "Продать мир",      100000000000},
                         {2, "Спасти Ядовитого", 9},
                         {2, "Восстановить ЧВК", 1488},
                 },
                 {
                         {2, "Найти Твердого", 1995},
                         {2, "Найти Жидкого",  1999},
                         {3, "Найти Нулевого", 2014},
                 });
    testData.push_back(temp4);
}

void task1(vector<Worker> &workers) {
    printf("1. Вывести работника, с самым большим количеством сложных задач, при \n"
           "условии наличия нескольких работников с одинаковым максимальным количеством \n"
           "сложных задач, необходимо вывести всех этих сотрудников.\n\n");

    int maxTasks = 0;
    list<Worker> result;

    for (Worker &worker: workers) {
        int hardTasks = 0;
        for (Task &task: worker._active) {
            if (task._difficulty == 3) hardTasks++;
        }
        for (Task &task: worker._completed) {
            if (task._difficulty == 3) hardTasks++;
        }

        if (hardTasks > maxTasks) {
            maxTasks = hardTasks;
            result.clear();
        }

        if (hardTasks == maxTasks) {
            result.push_back(worker);
        }
    }

    printf("Максимальное количество сложных задач - %d:\n", maxTasks);

    for (Worker &worker: result) {
        printf("%s %s, %d, %s\n",
               worker._firstName.c_str(),
               worker._secondName.c_str(),
               worker._age,
               worker._gender.c_str());
    }
}

void task2(vector<Worker> &workers) {
    printf("2. Вывести работника, с самым большим количеством выполненных задач, \n"
           "при условии наличия нескольких работников с одинаковым максимальным \n"
           "количеством сложных задач, необходимо вывести всех этих сотрудников.\n\n");

    size_t maxCompleted = 0;
    list<Worker> result;

    for (Worker &worker: workers) {
        size_t completedTasks = worker.completedCount();

        if (completedTasks > maxCompleted) {
            maxCompleted = completedTasks;
            result.clear();
        }

        if (completedTasks == maxCompleted) {
            result.push_back(worker);
        }
    }

    printf("Максимальное количество выполненных задач - %d:\n", maxCompleted);

    for (Worker &worker: result) {
        printf("%s %s, %d, %s\n",
               worker._firstName.c_str(),
               worker._secondName.c_str(),
               worker._age,
               worker._gender.c_str());
    }
}

void task3(vector<Worker> &workers) {
    printf("3. Для каждого сотрудника вывести количество текущих задач со средним \n"
           "уровнем сложности.\n\n");

    for (Worker &worker: workers) {
        size_t activeTasks = worker.activeCount();
        printf("%s %s, %d, %s\n"
               "\tActive tasks: %d\n"
               "\tAVG difficulty: %f\n\n",
               worker._firstName.c_str(),
               worker._secondName.c_str(),
               worker._age,
               worker._gender.c_str(),
               worker.activeCount(),
               worker.activeAvgDifficulty());
    }
}
