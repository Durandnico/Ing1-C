/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief 
*      Question 1 du TP2
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
 *  \date Wed 26 October 2022 - 14:49:29
 *  \brief Programme principal
 *  \param void
 *  \return 0 si tout s'est bien passé 1 sinon
 */
int main (void){
    int int_check; //Variable pour check la sortie du scanf
    int int_nb; //nombre à afficher

    /* On demande au USER d'entrer un entier */
    printf("Entrez un nombre entre %d et %d :", -__INT_MAX__-1, __INT_MAX__);
    int_check = scanf("%d", &int_nb);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf");
        return 1;
    }

    /* On affiche le nombre saisie */
    printf("Le nombre entré par le USER est : %d\n", int_nb);
    return 0;
}
/*
 *Que se passe-t-il si vous entrez une lettre, à la place d’un nombre ? :=> scanf return 0
 *Pour une chaine ? => la même chose
 *Pour un réel ? => n'affecte que la partie entière
 *
 */