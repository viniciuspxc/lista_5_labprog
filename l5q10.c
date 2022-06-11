#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LIM 4
#define TAM 10

void criarvetor(int *v, int tam, int lim) {
  for (int i = 0; i < tam; i++) {
    *(v + i) = rand() % lim;
  }
}

void printvetor(int *v, int tam) {
  for (int i = 0; i < tam; i++) {
    printf("[%d] ", *(v + i));
  }
}

void printmatriz(int *m, int lin, int col) {
  for (int i = 0; i < lin * col; i++) {
    if (i % col == 0) {
      printf("\n");
    }
    printf("[%d] ", *(m + i));
  }
}

void coordenada(int *x, int *y, int *m, int tam, int lim) {
  for (int i = 0; i < tam; i++) {
    *(m + (*(x + i) * lim) + (*(y + i))) += 1;
  }
}

int main(void) {
  srand(time(NULL));

  int *x = (int *)malloc(sizeof(int) * TAM);
  int *y = (int *)malloc(sizeof(int) * TAM);
  int *pm = (int *)calloc(LIM * LIM, sizeof(int));

  printf("X: \n");
  criarvetor(x, TAM, LIM);
  printvetor(x, TAM);

  printf("\nF: \n");
  criarvetor(y, TAM, LIM);
  printvetor(y, TAM);
  coordenada(x, y, pm, TAM, LIM);

  printf("\nM:");
  printmatriz(pm, LIM, LIM);

  free(x);
  free(y);
  free(pm);
  return 0;
}
