#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define LIM 100

int main(void) {
  int *x;
  float *x2;
  x = malloc(TAM * sizeof(int));
  x2 = malloc(TAM * sizeof(int));
  srand(time(NULL));

  printf("Vetor X: \n");
  for (int i = 0; i < TAM; i++) {
    *(x + i) = rand() % LIM;
    printf("%d ", *(x + i));
  }

  int menor = *x, maior = *x;
  for (int i = 0; i < TAM; i++) {
    if (maior < *(x + i)) {
      maior = *(x + i);
    }
    if (menor > *(x + i)) {
      menor = *(x + i);
    }
  }

  printf("\n\nVetor X normalizado (Menor %d, Maior %d): \n", menor, maior);
  for (int i = 0; i < TAM; i++) {
    *(x2 + i) = (float)(*(x + i) - menor) / (maior - menor);
    printf("%.2f ", *(x2 + i));
  }

  free(x);
  free(x2);
  return 0;
}