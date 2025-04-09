#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task {
    char *name;
    struct Task *next;
};


struct Task *head = NULL;
struct Task *tail = NULL;


struct Task *task_new(const char *name) {
    struct Task *task = malloc(sizeof(struct Task));
    task -> name = strdup(name);
    task -> next = NULL;
};


void task_free(struct Task *task) {
    free(task -> name);
    free(task);
};


void queue(const char *name) {
    struct Task *task = task_new(name);
    if(head == NULL) {
        head = task;
        tail = task;
    } else {
        tail -> next = task;
        tail = task;
    }
};


void display() {
    for(struct Task *ptr = head; ptr != NULL; ptr = ptr -> next) {
        printf("%s\n", ptr -> name);
    }
};


void remove2() {
    if(head == NULL) {
        struct Task *next = head -> next;
        task_free(head);
        head = next;
        if(head == NULL) {
            tail = NULL;
        }
    }    
};


int main() {
    task_free(task_new("abc"));
    display();
    remove2();
};