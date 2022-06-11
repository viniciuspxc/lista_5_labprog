#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM 100

int main(int argc, char *argv[]) {
  float *x,soma;
  int tam;
  tam = atoi(argv[1]);
  x = malloc(tam * sizeof(int));

  srand(time(NULL));

  printf("Vetor X: \n");
  for (int i = 0; i < tam; i++) {
    *(x + i) = (rand() % LIM - 1 + (float)(rand() % 101) / 100);
    printf("%.2f ", *(x + i));
    soma+=*(x + i);
  }

  printf("\n\nSoma = %.2f ", soma);
  free(x);
  return 0;
}