/* Davidu93 */
#include<stdlib.h>
#include<stdio.h>

#define TAILLE_MAX 101 /* Taille max du mots */

int main()
{
    int i = 0;
    int taille_du_mots = 0;
    char mots[TAILLE_MAX];
    printf("Entrer un mots : ");
    scanf("%s",&mots);

    /* On compte la taille du mots entré par l'utilisateur */
    do{
        taille_du_mots++;
        i++;
    }while(mots[i]!='\0');

    for(i=0;i<taille_du_mots/2;i++){
        if(mots[i] != mots[taille_du_mots-1-i]){
            printf("%s n'est pas un palindrome\n",mots);
            return EXIT_SUCCESS;
        }
    }
    printf("%s est un palindrome\n",mots);

    return EXIT_SUCCESS;
}
