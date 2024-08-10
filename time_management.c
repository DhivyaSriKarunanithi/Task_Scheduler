#include "time_management.h"

time_t systemTime;

void initTime() {
    systemTime = time(NULL);
}

void updateTime() {
    systemTime = time(NULL);
}

time_t getTime() {
    return systemTime;
}
