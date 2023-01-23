/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief 
*      Question 8 et 9 du TP2
*/

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 26 October 2022 - 14:22:41
 *
 *  \brief 
 *        Ceci est le programme principal
 *
 */

// Inclusion des entetes de librairies
#include <stdio.h>

/*! 
 *  \def ERROR
 *  \brief affiche un message d'erreur
 */
#define ERROR(msgErr) fprintf(stderr, "%s\n", msgErr) 

/*! 
 *  \def EMPTYBUFFER () (while (()))
 *  \brief vide le tampon 
 */
#define EMPTYBUFFER while (fgetc(stdin) != '\n') 

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sun 30 October 2022 - 14:05:32
 *  \brief Programme principal
 *          Fait un compte a rebours dans le terminal
 *  \param void
 *  \return 0 si tout s'est bien passé 1 sinon
 */
int main (void) {
    int int_n; //compte à rebours
    int int_check; //pour la sortie du scanf 
    int int_i; //Variable pour les boucles

    /*On demande au USER d'entrer un entier */
    printf("Compte a rebours de n : ");
    int_check = scanf("%d", &int_n);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 1");
        return 1;
    }

    /* On vérifie que le nombre ne soit pas négatif */
    if(int_n < 0) {
        printf("Compte à rebours négatif impossible !\n");
        return 1;
    }

    /* Compte à rebours avec une boucle for */
    printf("Compte a rebours avec un for :\n");
    for( int_i = int_n; int_i >= 0; int_i--) {
        printf("%d\n", int_i);
    }

    /* Compte à rebours avec une boucle while */
    printf("\n\nCompte à rebours avec un while\n");
    int_i = int_n;
    do{
        printf("%d\n", int_i);
    }while( int_i-- > 0);

    return 0;
}