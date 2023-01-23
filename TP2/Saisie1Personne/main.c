/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief 
*      Question 4 du TP2
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
 *  \date Wed 26 October 2022 - 14:55:22
 *  \brief Programme principal
 *         Demande nom,prénom,date de naissance puis les affiches
 *  \param void
 *  \return 0 si tout s'est bien passé 1 sinon
 */
int main (void) {
    int int_check; //Pour check le retour du scanf
    char str_nom[1024]; //Pour stocker le nom
    char str_prenom[1024]; //Pour stocker le prénom
    char str_naissance[1024]; //Pour stocker la date de naissance

    printf("Entrez votre nom (seul le 1er mot sera retenu): ");
    int_check = scanf("%s", str_nom);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 1");
    }

    printf("\nEntrez votre prénom (seul le 1er prénom sera retenu): ");
    EMPTYBUFFER;
    int_check = scanf("%s", str_prenom); 
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 2" );
        return 1;
    }

    printf("\nEntrez votre date de naissance (JJ MM YYYY): ");
    EMPTYBUFFER;
    int_check = scanf("%[^\n]", str_naissance);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 3");
        return 1;
    }

    printf("Voici ce que vous avez entré :\nNom : %s\nPrenom : %s\nDate de naissance : %s\n", str_nom, str_prenom, str_naissance);

    return 0;
}