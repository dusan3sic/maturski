#include "scheduler.h"
#include <stdio.h>

int main() {
    Scheduler scheduler;
    initScheduler(&scheduler);

    Task task1 = {1, 5}; // id, execution_time
    Task task2 = {2, 3};
    Task task3 = {3, 4};


    addTask(&scheduler, task1);
    addTask(&scheduler, task2);
    addTask(&scheduler, task3);

    while (scheduler.size > 0) {
        Task nextTask = getNextTask(&scheduler);
        printf("Pokrecem pid %d\n", nextTask.id);
    }

    return 0;
}