/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief 
*      Question 5 du TP2
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
 *  \date Wed 26 October 2022 - 19:01:47
 *  \brief Programme principal
 *             Demande 2 entier et affiche le résultat de la division
 *  \param void
 *  \return 0 si tout s'est bien passé 1 sinon
 */
int main (void) {
    int int_check; //Pour check le scanf
    int int_n; //Pour le numérateur
    int int_d; //Pour le dénumérateur

    /*On demande au USER d'entrer un numérateur */
    printf("Veuillez saisir le numérateur et le dénominateur (2 entiers): ");
    int_check = scanf("%d", &int_n);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf numérateur");
        return 1;
    }

    /*On demande au USER d'entrer un dénominateur */
    int_check = scanf("%d", &int_d);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf dénominateur");
        return 1;
    }
    
    /* On vérifie que le dénominateur n'est pas égale à 0 
     * Si non égale on affiche le résultat de la division
     * Sinon on retourne une erreur
     */
    if( int_d != 0) {
        printf("\n%d / %d = %d !\n", int_n, int_d, int_n/int_d);
        return 0;
    }else{
        ERROR("Division impossible");
        return 1;
    }
}