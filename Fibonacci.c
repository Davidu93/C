/* Davidu93 */
#include <stdlib.h>
#include <stdio.h>

unsigned int fibonacci_rec(unsigned n);
unsigned int fibonacci_it(unsigned n);
unsigned int fibo(unsigned int n);

int main()
{
    int n;
    do{
        printf("Entrer un entier n : ");
        scanf("%d",&n);
    }while(n<0);
    printf("Vous avez entré l'entier %d\n",n);

    printf("Fibonacci Itérative : F[%d] = %u\n",n,fibonacci_it(n));
    printf("Fibonacci Récursive : F[%d] = %u\n",n,fibonacci_rec(n));

    return EXIT_SUCCESS;

}

/* FIBONACCI RÉCURSIVE */
unsigned int fibonacci_rec(unsigned int n)
{
    if(n==1)
        return 1;
    if(n==0)
        return 0;
    return fibonacci_rec(n-2) + fibonacci_rec(n-1);
}

/* FIBONACCI ITÉRATIVE */
unsigned int fibonacci_it(unsigned int n)
{
    int i;
    unsigned int F[n];
    F[0] = 0 , F[1] = 1;
    if(n==0)
        return 0;
    for(i=2;i<=n;i++)
    {
        F[i] = F[i-2] + F[i-1];
        if(i==n)
            return F[i];
    }
}
