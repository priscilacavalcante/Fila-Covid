#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
  char name[100];
  int age;
} Person;

void printPerson(Person p);

typedef struct Cell {
  Person data;
  struct Cell *next;
} Cell;

typedef struct Queue {
  Cell *start;
  Cell *end;
  int size;
} Queue;

Cell *newCell();

void newQueue(Queue *q);

void enqueue(Queue *q, Person data);

void printQueue(Queue *q);

int sizeQueue(Queue *q);

Person dequeue(Queue *q);