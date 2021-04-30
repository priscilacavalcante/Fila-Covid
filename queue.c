#include "queue.h"

void printPerson(Person p) {
  printf("Nome: %s, Idade: %d\n", p.name, p.age);
}

Cell *newCell() {
  Cell *temp = (Cell*) malloc(sizeof(Cell));
  temp -> next = NULL;
  return temp;
}

void newQueue(Queue *q) {
  Cell *create = newCell();
  q -> start = create;
  q -> end = create;
  q -> size = 0;
}

void enqueue(Queue *q, Person data) {
   Cell *create = newCell();
   create -> data = data;
   q -> end -> next = create;
   q -> end = create;
   q -> size++;
}

void printQueue(Queue *q) {
  Cell *temp = q -> start -> next;
  while (temp != NULL) {
    printPerson(temp -> data);
    temp = temp -> next;
  }
}

int sizeQueue(Queue *q) {
  return q -> size;
}

Person dequeue(Queue *q) {
  if(q -> size == 0) {
    Person p = {"Erro", -1};
    return p;
  }
  Cell *temp = q -> start;
  q -> start = q -> start -> next;
  free(temp);
  q -> size--;
  return q -> start -> data;
}