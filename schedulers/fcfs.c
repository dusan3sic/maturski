#include <stdlib.h>
#include "scheduler.h"

void initScheduler(Scheduler *scheduler) {
    scheduler->front = NULL;
    scheduler->rear = NULL;
    scheduler->size = 0;
}


void addTask(Scheduler *scheduler, Task task) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }
    newNode->task = task;
    newNode->next = NULL;
    
    if (scheduler->rear == NULL) {
        scheduler->front = newNode;
        scheduler->rear = newNode;
    } else {
        scheduler->rear->next = newNode;
        scheduler->rear = newNode;
    }
    scheduler->size++;
}

Task getNextTask(Scheduler *scheduler) {
    if (scheduler->front == NULL) {
        Task emptyTask = {0, 0, 0};
        return emptyTask;
    }

    Node *frontNode = scheduler->front;
    Task nextTask = frontNode->task;

    scheduler->front = frontNode->next;
    free(frontNode);

    if (scheduler->front == NULL) {
        scheduler->rear = NULL;
    }

    scheduler->size--;
    return nextTask;
}