/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief 
*      Question 6 du TP2
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
 *  \date Thu 27 October 2022 - 12:52:10
 *  \brief Programme principal
 *          Demande 2 entiers et dit si leur multipication va etre postif ou négatif 
 *  \param void
 *  \return 0 si tout s'est bien passé 1 sinon
 */
int main (void) {
    int int_check; //Pour check le scanf
    int int_n; //Pour la valeur1
    int int_d; //Pour la valeur2

    /* On demande au USER d'entrer un entier */
    printf("Veuillez saisir les 2 entiers: ");
    int_check = scanf("%d", &int_n);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 1");
        return 1;
    }

    /* On demande au USER d'entrer un entier */
    int_check = scanf("%d", &int_d);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 2");
        return 1;
    }
    
    /* On affiche le résultat */
    printf("La multiplication va etre %s\n", ( ( int_n <= 0) == (int_d <= 0 ) ) ? "Positif" : "Negatif" );
    
    return 0;
}