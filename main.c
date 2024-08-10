#include "task_management.h"
#include "scheduling_algorithms.h"
#include "time_management.h"
#include "priority_management.h"
#include "interrupt_handling.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    initTime();
    initInterrupts();
    
    char taskName[50];
    int executionTime, deadline, period;
    int choice;
        
    while (1) {
        printf("\n1. Create Task\n2. Delete Task\n3. Display Tasks\n4. Run EDF\n5. Run RMS\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", taskName);
                printf("Enter execution time: ");
                scanf("%d", &executionTime);
                printf("Enter deadline: ");
                scanf("%d", &deadline);
                printf("Enter period: ");
                scanf("%d", &period);
                createTask(taskName, executionTime, deadline, period);
                break;
            case 2:
                printf("Enter task ID to delete: ");
                int id;
                scanf("%d", &id);
                deleteTask(id);
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                updateTime();
                Task* edfTask = findEDFTask();
                if (edfTask) {
                    printf("EDF Task: ID: %d, Name: %s\n", edfTask->id, edfTask->name);
                } else {
                    printf("No tasks available for EDF scheduling.\n");
                }
                break;
            case 5:
                assignPriorities();
                Task* rmsTask = findRMSTask();
                if (rmsTask) {
                    printf("RMS Task: ID: %d, Name: %s\n", rmsTask->id, rmsTask->name);
                } else {
                    printf("No tasks available for RMS scheduling.\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
