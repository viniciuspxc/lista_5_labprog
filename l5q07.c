#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6
#define LIM 4

int main(void) {
  int *x, *y;
  float emq = 0;
  x = malloc(TAM * sizeof(int));
  y = malloc(TAM * sizeof(int));
  srand(time(NULL));

  // media
  float media = 0;
  printf("Vetor X: \n");
  for (int i = 0; i < TAM; i++) {
    *(x + i) = rand() % LIM;
    printf("%d ", *(x + i));
  }
  printf("\n\nVetor Y: \n");
  for (int i = 0; i < TAM; i++) {
    *(y + i) = rand() % LIM;
    printf("%d ", *(y + i));
  }

  for (int i = 0; i < TAM; i++) {
    emq += (*(x + i) - *(y + i)) * (*(x + i) - *(y + i));
  }
  emq = emq * 1 / TAM;

  printf("\n\nErro Médio Quadrático: %.2f", emq);
  free(x);
  free(y);

  return 0;
}