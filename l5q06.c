#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 6
#define LIM 4

int main(void) {
  int *x;
  x = malloc(TAM * sizeof(int));
  srand(time(NULL));

  // media
  float media = 0;
  printf("Vetor X: \n");
  for (int i = 0; i < TAM; i++) {
    *(x + i) = rand() % LIM;
    printf("%d ", *(x + i));
    media += *(x + i);
  }

  printf("\n\nMedia de X: %.2f\n", media / TAM);

  // mediana
  for (int i = 1; i < TAM; i++) {

    if (*(x + i) < *(x + i - 1)) {
      *(x + i) = *(x + i) ^ *(x + i - 1);
      *(x + i - 1) = *(x + i) ^ *(x + i - 1);
      *(x + i) = *(x + i) ^ *(x + i - 1);
      i = 0;
    }
  }
  for (int i = 0; i < TAM; i++) {
    printf("%d ", *(x + i));
  }
  printf("\n\nMediana  de X: %.2f\n",
         (TAM % 2) ? *(x + TAM / 2)
                   : (float)(*(x + TAM / 2) + *(x + TAM / 2 - 1)) / 2);

  // moda
  int qtemp = 0, qtd = 0, modatemp, moda;
  for (int i = 0; i < TAM; i++) {
    if (i == 0) {
      modatemp = *(x + i);
    }
    if (modatemp == *(x + i)) {
      qtemp++;
    }
    if (qtemp > qtd) {
      qtd = qtemp;
      qtemp = 1;
      moda = modatemp;
      modatemp = *(x + i);
    } else if (modatemp != *(x + i)) {
      qtemp = 1;
      modatemp = *(x + i);
    }
  }
  printf("\n\nModa de X: %d", moda);

  free(x);

  return 0;
}