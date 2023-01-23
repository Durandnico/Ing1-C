/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief 
*      Question 3 du TP2
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
 *  \def EMPTYBUFFER 
 *  \brief vide le tampon 
 */
#define EMPTYBUFFER while (fgetc(stdin) != '\n') 

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 26 October 2022 - 18:52:32
 *  \brief Programme principal
 *         Affiche les entiers entrés par le USER
 *  \param void
 *  \return 0 si tout s'est bien passé 1 sinon
 */
int main (void) {
    int int_check; //Variable pour check la sortie du scanf
    int int_nb1; //nombre à afficher
    int int_nb2; //nombre à afficher
    
    /* On demande au USER d'entrer un entier */
    printf("Entrez 2 nombres entre %d et %d : ", -__INT_MAX__-1, __INT_MAX__);
    int_check = scanf("%d", &int_nb1);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 1");
        return 1;
    }
    
    /* On demande au USER d'entrer un entier */
    EMPTYBUFFER;
    int_check = scanf("%d", &int_nb2);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 2");
        return 1;
    }

    /* On affiche les 2 entiers rentré */
    printf("Les nombres entrés par le USER sont : %d et %d\n", int_nb1, int_nb2);
     
    return 0;
}
/*
 * Que se passe-t-il si vous saisissez un réel ? => sort du scanf, 2ème variable non assigné
 * Comment pouvez vous vous apercevoir pendant l’éxecution ? => On fait 2 scanf
 */