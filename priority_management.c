#include "priority_management.h"

void assignPriorities() {
    Task* current = head;
    while (current != NULL) {
        current->priority = current->period;
        current = current->next;
    }
}
