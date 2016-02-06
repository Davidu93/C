/* Davidu93 */
#include <stdlib.h>
#include <stdio.h>

#define N 3

int gauss(float A[N][N],float B[N][N]);

int min_pivot_ligne (float A[N][N], int i);

void interchange_lignes (float A[N][N], float B[N][N], int i, int j);

void normaliser (float A[N][N], float B[N][N], int i, float k);

void annuler_colonnes (float A[N][N], float B[N][N], int i);

void imprimer_matrice (float C[N][N]);

/********* Principale ********/

int main()
{
  /*float A[N][N] = {{1.0,2.0,0.0},{3.0,4.0,2.0},{1.0,1.0,-1.0}};*/
  float A[N][N] = {{3.0,4.0,2.0},{1.0,2.0,0.0},{1.0,1.0,-1.0}};
  float B[N][N] = {{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0}};

  printf("Matrice A\n");
  imprimer_matrice(A);
  printf("Matrice B\n");
  imprimer_matrice(B);

  if (gauss(A,B) != -1)
  {
      printf("Matrice inverse de A\n");
      imprimer_matrice(B);
  }

  else
    printf("La matrice A est singuliere\n");

  return EXIT_SUCCESS;
}

/******************************************************************/

int gauss (float A[N][N], float B[N][N])
{
  int i,j;
  float k;

  for (i=0; i < N; i++)
    {
       j = min_pivot_ligne (A, i);
       if (j == -1) return (-1);
       if (i != j) interchange_lignes(A,B,i,j);
       k = A[i][i];
       normaliser (A,B,i,k);
       annuler_colonnes(A,B,i);
    }
  return (1);
}

/******************************************************************/

int min_pivot_ligne (float A[N][N], int i)
{
    int j;
    for(j=0;j<N;j++)
    {
        if(A[i][j]!=0.0)
        {
            return j;
        }
    }
    return -1;
}

/******************************************************************/

void interchange_lignes (float A[N][N], float B[N][N], int i, int j)
{
    int k;
    float tmp;
    for(k=0;k<N;k++)
    {
        tmp = A[i][k];
        A[i][k] = A[j][k];
        A[j][k] = tmp;

        tmp = B[i][k];
        B[i][k] = B[j][k];
        B[j][k] = tmp;
    }
}

/******************************************************************/

void normaliser (float A[N][N], float B[N][N], int i, float k)
{
    int j;
    for(j=0;j<N;j++)
    {
        A[i][j] = A[i][j]/k;
        B[i][j] = B[i][j]/k;
    }
}

/******************************************************************/

void annuler_colonnes (float A[N][N], float B[N][N], int i)
{
    int j,k;
    for(j=0;j<N;j++)
    {
        float t = A[j][i];
        if(j!=i)
        {
            if(A[j][i]!=0.0)
            {
                for(k=0;k<N;k++)
                {
                   A[j][k] = A[j][k] + ((-t)*A[i][k]);
                   B[j][k] = B[j][k] + ((-t)*B[i][k]);
                }
            }
        }
    }
}

/******************************************************************/

void imprimer_matrice (float C[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%f ",C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/******************************************************************/
