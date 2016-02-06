/* Davidu93 */
#include<stdlib.h>
#include<stdio.h>

#define N 2

void initialiser_matrice(float A[N][N]);
void afficher_matrice(float A[N][N]);
void inverse(float A[N][N] , float det);

int main()
{
  float A[N][N]; /* Matrice 2*2 */
  int i,j;
  int det;
  initialiser_matrice(A);
  printf("Matrice A\n");
  afficher_matrice(A);
  det = A[0][0] * A[1][1] - A[0][1] * A[1][0]; /* Calcul du déterminant */
  
  if(det==0)
  {
    printf("A n'est pas inversible\n");
  }
  
  else
  {
    printf("A est inversible et son inverse est : \n");
    inverse(A,det);
  }
  
  return EXIT_SUCCESS;

}

void initialiser_matrice(float A[N][N]) /* L'utilisateur entre les valeurs de la matrice A */
{
  int i,j;
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      printf("A[%d][%d] = ",i,j);
      scanf("%f",&A[i][j]);
    }
  }
}

void afficher_matrice(float A[N][N]) /* Affiche les coefficients de la matrice A */
{
  int i,j;
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      printf("%f ",A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void inverse(float A[N][N] , float det) /* Calcul l'inverse de la matrice A */
{
  float tmp = A[0][0];
  A[0][1] = -A[0][1]/det;
  A[1][0] = -A[1][0]/det;
  A[0][0] = A[1][1]/det;
  A[1][1] = tmp/det;
  afficher_matrice(A);
}
