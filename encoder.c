/*************************************************
    N Queens Puzzle encoder in CNF-SAT DIMACS

       Copyright 2020 Borja González Seoane

               LICENSE BSD 2-Clause
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef N
#define N 8 // Default value
#endif
#define queen(x, y) ((x)*N + (y) + 1)
#define row(c) ((c - 1) / N)
#define col(c) ((c - 1) % N)

int clauses = 0;
char board[N][N];
FILE *f;

void diagonal_down(int x, int y) {
  int i, j;
  for (; x < N - 1 && y < N - 1; x++, y++)
    for (i = x + 1, j = y + 1; i < N && j < N; i++, j++) {
      fprintf(f, "-%d -%d 0\n", queen(x, y), queen(i, j));
      clauses++;
    }
}

void diagonal_up(int x, int y) {
  int i, j;
  for (; x > 0 && y < N - 1; x--, y++)
    for (i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++) {
      fprintf(f, "-%d -%d 0\n", queen(x, y), queen(i, j));
      clauses++;
    }
}

int main() {
  int i, j, c, q, k;
  f = fopen("clauses.txt", "w");

  for (k = 0; k < N; k++) {
    for (i = 0; i < N - 1; i++)
      for (j = i + 1; j < N; j++) {
        fprintf(f, "-%d -%d 0\n", queen(k, i), queen(k, j));
        clauses++;
        fprintf(f, "-%d -%d 0\n", queen(i, k), queen(j, k));
        clauses++;
      }

    for (i = 0; i < N; i++)
      fprintf(f, "%d ", queen(k, i));
    fprintf(f, "0\n");
    clauses++;
  }

  for (i = 0; i < N - 1; i++)
    diagonal_down(0, i);
  for (i = 1; i < N - 1; i++)
    diagonal_down(i, 0);
  for (i = 1; i < N; i++)
    diagonal_up(i, 0);
  for (i = 1; i < N - 1; i++)
    diagonal_up(N - 1, i);
  fclose(f);
  f = fopen("coding.cnf", "w");
  fprintf(f, "p cnf %d %d\n", N * N, clauses);
  fclose(f);
  system("cat clauses.txt >> coding.cnf");
  system("clasp --verbose=0 coding.cnf > result.txt");

  f = fopen("result.txt", "r");
  if ((c = fgetc(f)) == EOF || c != 'v')
    exit(1);

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      board[i][j] = '.';
  while ((c = fscanf(f, "%d", &q)) != EOF) {
    if (c == 0) {
      fgetc(f);
      continue;
    }
    if (q > 0)
      board[row(q)][col(q)] = 'Q';
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%c ", board[i][j]);
    printf("\n");
  }

  fclose(f);
}
