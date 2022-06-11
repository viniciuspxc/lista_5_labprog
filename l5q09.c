#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 6
#define COL 6
#define LIM 10

int main(void) {
  int *x;
  int soma = 0;
  x = malloc(LIN * COL * sizeof(int));
  srand(time(NULL));

  printf("Matriz X: \n");
  for (int i = 0; i < LIN * COL; i++) {
    if (!(i % COL))
      printf("\n");
    *(x + i) = rand() % LIM;
    printf("%d ", *(x + i));
  }

  for (int i = 0; i < LIN * COL; i += COL + 1) {
    soma = *(x + i);
  }

  (soma % 2) ? printf("\n\nA soma da diagonal principal (%d) é impar. \n", soma)
             : printf("\n\nA soma da diagonal principal (%d) é par. \n", soma);

  free(x);

  return 0;
}