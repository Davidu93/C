#include <stdlib.h>
#include <stdio.h>

#define N 4 /* Taille de la matrice */

float * creer_matrice (int);
void    liberer_memoire(float * M);
void    inic_matrice (float *M, int);
void    afficher_matrice (float *M, int);
float * sous_matrice (float * M, int, int, int, int);
void    addition_matrices (float * X, float *Y, float * R, int);
void    soustraction_matrices (float * X, float *Y, float * R, int);
void    composer_matrices(float * C, int, float *T1, int, int, int);
float * strassen (float * A, float * B, int);

/************************************************************************/
int main ()
{
  float *A;
  float *B;
  float *C;

  A = creer_matrice(N);
  B = creer_matrice(N);

  /* remplisage de A */

  A[0*N + 0] = 2.0; A[0*N + 1] = 3.0; A[0*N + 2] = 1.0; A[0*N + 3] = 4.0;
  A[1*N + 0] = 2.0; A[1*N + 1] = 6.0; A[1*N + 2] = 1.0; A[1*N + 3] = 7.0;
  A[2*N + 0] = 4.0; A[2*N + 1] = 8.0; A[2*N + 2] = 1.0; A[2*N + 3] = 9.0;
  A[3*N + 0] = 9.0; A[3*N + 1] = 6.0; A[3*N + 2] = 1.0; A[3*N + 3] = 8.0;

  /* remplisage de B */

  B[0*N + 0] = 1.0; B[0*N + 1] = 2.0; B[0*N + 2] = 1.0; B[0*N + 3] = 2.0;
  B[1*N + 0] = 3.0; B[1*N + 1] = 1.0; B[1*N + 2] = 2.0; B[1*N + 3] = 1.0;
  B[2*N + 0] = 1.0; B[2*N + 1] = 1.0; B[2*N + 2] = 1.0; B[2*N + 3] = 1.0;
  B[3*N + 0] = 4.0; B[3*N + 1] = 3.0; B[3*N + 2] = 3.0; B[3*N + 3] = 4.0;

  C = strassen (A, B, N);

  printf("Matrice A\n");
  afficher_matrice (A, N);
  printf("Matrice B\n");
  afficher_matrice (B, N);
  printf("Matrice C\n");
  afficher_matrice (C, N);

  liberer_memoire(A); liberer_memoire(B); liberer_memoire(C);
 return EXIT_SUCCESS;
}

/************************************************************************/

float * creer_matrice (int n)
{
  float * T = (float *) malloc (n*n*sizeof(float));
  return(T);
}

/************************************************************************/

void liberer_memoire(float * M)
{
   free(M);
}


/************************************************************************/

void inic_matrice (float * T, int n) /* Initialise tous les coefficients de la matrice T à 0.0 */
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            T[i*n+j] = 0.0;
        }
    }
}

/************************************************************************/

void afficher_matrice (float * M, int n) /* Afficher les coefficients de la matrice M */
{
  int i,j;
  for(i=0;i<n;i++)
  {
      for(j=0;j<n;j++)
      {
          printf("%f ",M[i*n+j]);
      }
      printf("\n");
  }
  printf("\n");
}


/************************************************************************/

float * sous_matrice (float * M, int l, int c, int n, int n2)
{
   float * S = creer_matrice(n2); /* Creer une sous matrice de taille n/2 */
   int i,j;
   for(i=0;i<n2;i++)
   {
       for(j=0;j<n2;j++)
       {
           S[i*n2+j] = M[(i+n2*l)*n+(j+n2*c)];
       }
   }
   return S;
}

/************************************************************************/

void addition_matrices (float * X, float *Y, float * R, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            R[i*n+j] = X[i*n+j] + Y[i*n+j]; /* La matrice R = matrice X + matrice Y */
        }
    }
}

/************************************************************************/

void soustraction_matrices (float * X, float *Y, float * R, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            R[i*n+j] = X[i*n+j] - Y[i*n+j]; /* La matrice R = matrice X - matrice Y */
        }
    }
}

/************************************************************************/

void composer_matrices(float * C, int n, float *T, int n2, int l, int c)
{
    int i,j;
    for(i=0;i<n2;i++)
    {
        for(j=0;j<n2;j++)
        {
            C[(i+n2*l)*n+(j+n2*c)] = T[i*n2+j];
        }
    }
}

/************************************************************************/

float * strassen (float * A, float * B, int n)
{
  float * C = creer_matrice(n);

  inic_matrice(C, n);

  if (n == 2)
  {
     float p1,p2,p3,p4,p5,p6,p7;

     p1 = (A[0*n + 0] + A[1*n + 1])*(B[0*n + 0] + B[1*n + 1]); /* (a11 + a22)*(b11 + b22) */
     p2 = (A[1*n + 0] + A[1*n + 1])*(B[0*n + 0]);              /* (a21 + a22)*(b11) */
     p3 = (A[0*n + 0])*(B[0*n + 1] - B[1*n + 1]);              /* (a11)*(b12 - b22) */
     p4 = (A[1*n + 1])*(B[1*n + 0] - B[0*n + 0]);              /* (a22)*(b21 - b11) */
     p5 = (A[0*n + 0] + A[0*n + 1])*(B[1*n + 1]);              /* (a11 + a12)*(b22) */
     p6 = (A[1*n + 0] - A[0*n + 0])*(B[0*n + 0] + B[0*n + 1]); /* (a21 - a11)*(b11 + b12) */
     p7 = (A[0*n + 1] - A[1*n + 1])*(B[1*n + 0] + B[1*n + 1]); /* (a12 - a22)*(b21 + b22) */

     C[0*n + 0] = p1 + p4 - p5 + p7;
     C[0*n + 1] = p3 + p5;
     C[1*n + 0] = p2 + p4;
     C[1*n + 1] = p1 - p2 + p3 + p6;
  }
  else
  {
     int n2 = n/2;
     float *A11; float * A12; float * A21; float * A22;
     float *B11; float * B12; float * B21; float * B22;

     float *P1; float *P2; float *P3; float *P4; float *P5; float *P6; float *P7;

     float * T1 = creer_matrice(n2);
     float * T2 = creer_matrice(n2); /* matrices auxlieres */

     A11 = sous_matrice (A, 0, 0, n, n2);
     A12 = sous_matrice (A, 0, 1, n, n2);
     A21 = sous_matrice (A, 1, 0, n, n2);
     A22 = sous_matrice (A, 1, 1, n, n2);

     B11 = sous_matrice (B, 0, 0, n, n2);
     B12 = sous_matrice (B, 0, 1, n, n2);
     B21 = sous_matrice (B, 1, 0, n, n2);
     B22 = sous_matrice (B, 1, 1, n, n2);

     addition_matrices(A11, A22, T1, n2); addition_matrices(B11, B22, T2, n2);
     P1 = strassen (T1, T2, n2);

     addition_matrices(A21,A22, T1, n2);
     P2 = strassen (T1, B11, n2);

     soustraction_matrices (B12, B22, T1, n2);
     P3 = strassen (A11, T1, n2);

     soustraction_matrices (B21, B11, T1, n2);
     P4 = strassen (A22, T1, n2);

     addition_matrices(A11,A12, T1, n2);
     P5 = strassen (T1, B22, n2);

     soustraction_matrices(A21, A11, T1, n2); addition_matrices(B11, B12, T2, n2);
     P6 = strassen (T1, T2, n2);

     soustraction_matrices(A12, A22, T1, n2); addition_matrices(B21, B22, T2, n2);
     P7 = strassen (T1, T2, n2);

     addition_matrices(P1, P4, T1, n2); soustraction_matrices(T1, P5, T2, n2);
     addition_matrices(T2, P7, T1, n2); composer_matrices(C,n,T1,n2,0,0);

     addition_matrices(P3, P5, T1, n2); composer_matrices(C,n,T1,n2,0,1);

     addition_matrices(P2, P4, T1, n2); composer_matrices(C,n,T1,n2,1,0);

     soustraction_matrices(P1, P2, T1, n2); addition_matrices(T1, P3, T2, n2);
     addition_matrices(T2, P6, T1, n2); composer_matrices(C,n,T1,n2,1,1);

     liberer_memoire(A11); liberer_memoire(A12); liberer_memoire(A21); liberer_memoire(A22);
     liberer_memoire(B11); liberer_memoire(B12); liberer_memoire(B21); liberer_memoire(B22);
     liberer_memoire(P1);  liberer_memoire(P2);  liberer_memoire(P3);  liberer_memoire(P4);
     liberer_memoire(P5);  liberer_memoire(P6);  liberer_memoire(P7);
     liberer_memoire(T1);  liberer_memoire(T2);
  }
  return (C);
}
