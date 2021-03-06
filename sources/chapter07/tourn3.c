#include <stdio.h>
#define MAX 100

unsigned m[MAX][MAX];

void copyMatrix(unsigned stX, unsigned stY, unsigned cnt, unsigned add)
{ unsigned i, j;
  for (i = 0; i < cnt; i++)
    for (j = 0; j < cnt; j++)
	  m[i + stX][j + stY] = m[i + 1][j + 1] + add;
}

void findSolution(unsigned n) /* Построява таблицата */
{ unsigned i, j;
  if (n % 2 == 0) /* Ако n е четно, задачата се свежда към n-1 */
	n--;

  /* Попълване на таблицата за n - тук е гарантирано нечетно. */
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
	  m[i][j] = i + j < n ? i + j + 1 : i + j + 1 - n;

  /* Възстановяване на стойността на n */
  if (n % 2 == 1) n++;

  for (i = 0; i < n; i++) {
    if (n % 2 == 0)     /* Запълване на последния стълб и ред при четно n */
      m[i][n - 1] = m[n - 1][i] = m[i][i];
    m[i][i] = 0;        /* Запълване с 0 на главния диагонал */
  }
}

void print(unsigned n)        /* Извежда резултата */
{ unsigned i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
	  printf("%3u", m[i][j]);
    printf("\n");
  }
}

int main(void) {
  const unsigned n = 5;
  findSolution(n);
  print(n);
  return 0;
}