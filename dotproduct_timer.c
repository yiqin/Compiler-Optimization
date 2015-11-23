#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2000


void init_matrix(int (*a)[N], int init_value)
{
  clock_t start_time, end_time;
  float elapsed_time;

  start_time = clock();

  int i,j;
    for (i=0;i<N;i++)
      for (j=0;j<N;j++)
        a[i][j] = 1;

  end_time = clock();
  elapsed_time = ((float)(end_time - start_time)) / CLOCKS_PER_SEC;

  printf("elapsed time: %f second\n", elapsed_time);
}

void dot_product(int (*a)[N], int (*b)[N], int (*c)[N], int fixi, int fixj)
{
   int i,j,k;
   i=fixi;
   j=fixj;
   for (k=0;k<N;k++)
      c[i][j] += a[i][k] * b[k][j] ;
}

int main()
{
    int i,j,k;
    int res = 0;
    int (*a)[N] = (int (*)[N]) calloc(N*N, sizeof(int));
    int (*b)[N] = (int (*)[N]) calloc(N*N, sizeof(int));
    int (*c)[N] = (int (*)[N]) calloc(N*N, sizeof(int));
    
    init_matrix(a,1) ; init_matrix(b,2) ; init_matrix(c,0);
    
    dot_product(a,b,c,10,10);
    
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            res+=c[i][j] % 2;
    return res;
}
