#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

int main(){
  Queue queue1, queue2, queue3, queue4;

  newQueue(&queue1);
  newQueue(&queue2);
  newQueue(&queue3);
  newQueue(&queue4);

  int op = 0, age;
  char name[100];
  char saude, comorbidade;
  Person p;
  

  do {
    printf("\t\tFILA VACINACAO COVID-19\n\n");

    printf("Menu de opcoes:\n");
    printf("1 - Inserir na fila de vacinacao;\n");
    printf("2 - Remover da fila de vacinacao;\n");
    printf("3 - Verificar o tamanho da fila de vacinacao;\n");
    printf("4 - Exibir a fila de vacinacao;\n");
    printf("0 - SAIR;\n");
    printf("Digite a opcao desejada: ");
    scanf("%i", &op);
    printf("\n\n");

      switch (op) {
          case 1:
          printf("Digite o nome: ");
          scanf("%s", p.name);

          printf("Digite a idade: ");
          scanf("%d", &p.age);

          printf("Eh profissional da saude?(S/N) ");
          scanf("%s", &saude);

          printf("Possui comorbidades?(S/N) ");
          scanf("%s", &comorbidade);

          if(p.age >= 75 || saude == 's') {
            enqueue(&queue1, p);
          } else if(p.age >= 60 && p.age <=74) {
            enqueue(&queue2, p);
          }else if(p.age < 60 && comorbidade == 's'){
            enqueue(&queue3, p);
          } else {
            enqueue(&queue4, p);
          }
          printf("\n\n");
          break;

          case 2:
          if (sizeQueue(&queue1) > 0) {
            p = dequeue(&queue1);
          } else if (sizeQueue(&queue2) > 0) {
            p = dequeue(&queue2);
          } else if(sizeQueue(&queue3) > 0) {
            p = dequeue(&queue3);
          } else {
            p = dequeue(&queue4);
          }
          printf("PESSOA REMOVIDA: ");
          printPerson(p);
          break;

          case 3:
          printf("Tamanho da fila 1a fase: %d\n", sizeQueue(&queue1));
          printf("Tamanho da fila 2a fase: %d\n", sizeQueue(&queue2));
          printf("Tamanho da fila 3a fase: %d\n", sizeQueue(&queue3));
          printf("Tamanho da fila 4a fase: %d\n\n", sizeQueue(&queue4));
          break;

          case 4:
          printf("1a FASE: \n");
          printQueue(&queue1);

          printf("\n2a FASE: \n");
          printQueue(&queue2);

          printf("\n3a FASE: \n");
          printQueue(&queue3);

          printf("\n4a FASE: \n");
          printQueue(&queue4);
 
          printf("\n\n");
          break;
      }
  } while(op != 0);

  return 0;
}