#include "task_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Task* head = NULL;
int taskId = 0;

void createTask(char* name, int executionTime, int deadline, int period) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    newTask->id = taskId++;
    strcpy(newTask->name, name);
    newTask->executionTime = executionTime;
    newTask->deadline = deadline;
    newTask->period = period;
    newTask->priority = 0;
    newTask->next = head;
    head = newTask;
}

void deleteTask(int id) {
    Task** current = &head;
    while (*current != NULL) {
        Task* entry = *current;
        if (entry->id == id) {
            *current = entry->next;
            free(entry);
            return;
        }
        current = &entry->next;
    }
}

void displayTasks() {
    Task* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Execution Time: %d, Deadline: %d, Period: %d, Priority: %d\n", 
               current->id, current->name, current->executionTime, current->deadline, current->period, current->priority);
        current = current->next;
    }
}
