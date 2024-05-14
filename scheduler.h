#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX_TASKS 100

typedef struct {
    int id;
    int execution_time;
} Task;

typedef struct Node {
    Task task;
    struct Node *next;
} Node;


typedef struct {
    Node *front;  
    Node *rear;   
    int size;
} Scheduler;

void initScheduler(Scheduler *scheduler);
void addTask(Scheduler *scheduler, Task task);
Task getNextTask(Scheduler *scheduler);

#endif
