#ifndef TASK_MANAGEMENT_H
#define TASK_MANAGEMENT_H

typedef struct Task {
    int id;
    char name[50];
    int executionTime;
    int deadline;
    int period;
    int priority;
    struct Task* next;
} Task;

void createTask(char* name, int executionTime, int deadline, int period);
void deleteTask(int id);
void displayTasks();

#endif
