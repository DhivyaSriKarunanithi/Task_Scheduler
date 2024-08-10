#include "scheduling_algorithms.h"
#include <limits.h>

Task* findEDFTask() {
    Task* current = head;
    Task* earliestDeadlineTask = NULL;
    int minDeadline = INT_MAX;

    while (current != NULL) {
        if (current->deadline < minDeadline) {
            minDeadline = current->deadline;
            earliestDeadlineTask = current;
        }
        current = current->next;
    }
    return earliestDeadlineTask;
}

Task* findRMSTask() {
    Task* current = head;
    Task* highestPriorityTask = NULL;
    int minPeriod = INT_MAX;

    while (current != NULL) {
        if (current->period < minPeriod) {
            minPeriod = current->period;
            highestPriorityTask = current;
        }
        current = current->next;
    }
    return highestPriorityTask;
}
