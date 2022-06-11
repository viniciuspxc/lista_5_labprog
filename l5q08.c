#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 6
#define COL 6
#define LIM 10

int main(void) {
  int *x, *y;
  int t = 5;
  x = malloc(LIN * COL * sizeof(int));
  y = malloc(LIN * COL * sizeof(int));
  srand(time(NULL));

  printf("Matriz X: \n");
  for (int i = 0; i < LIN * COL; i++) {
    if (!(i % COL))
      printf("\n");
    *(x + i) = rand() % LIM;
    printf("%d ", *(x + i));
  }

  printf("\n\nMatriz Binarizada: \n");
  for (int i = 0; i < LIN * COL; i++) {
    if (!(i % COL))
      printf("\n");
    *(y + i) = (*(x + i) > t ? 1 : 0);
    printf("%d ", *(y + i));
  }

  free(x);
  free(y);

  return 0;
}