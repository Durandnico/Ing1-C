/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief 
*      Question 7 du TP2
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
 *  \date Thu 27 October 2022 - 12:54:14
 *  \brief Programme principal
 *              Demande une date et prédit la date du prochain jour
 *  \param void
 *  \return 0 si tout s'est bien passé 1 sinon
 */
int main (void) {
    int int_jour; //pour le jour
    int int_mois; //pour le mois
    int int_annee; //pour l'annee
    int int_check; //pour la sortie du scanf
    int int_jour_par_mois[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 }; //Nombre de jour par mois
    
    /*On demande au USER d'entrer un jour */
    printf("entrez le jour : ");
    int_check = scanf("%d", &int_jour);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 1");
        return 1;
    }

    /*On demande au USER d'entrer un mois */
    printf("\nentrez le mois : ");
    EMPTYBUFFER;
    int_check = scanf("%d", &int_mois);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 2");
        return 1;
    }

    /*On demande au USER d'entrer une année */
    printf("\nentrez l'annee : ");
    EMPTYBUFFER;
    int_check = scanf("%d", &int_annee);
    if(int_check == 0){
        ERROR("Erreur dans l'entré du scanf 2");
        return 1;
    }


    /* Si le mois et Février ET l'année bissextile, on ajoute 1 jour au nombre de jour de Février */
    if ( int_mois == 2 && ((int_annee % 4 == 0 && int_annee % 100 != 0) || int_annee % 400 == 0 )) {
        int_jour_par_mois[2]++;
    }

    /*On vérifie que le jour et le mois existe */
    if( int_mois < 1 || int_mois > 12 || int_jour > int_jour_par_mois[int_mois] || int_jour < 1){
        ERROR("date inexistante !");
        return 1;
    }


    /*On ajoute un jour*/
    int_jour++;

    /* Si le jour dépasse le nombre de jour du mois, on incremente les mois et mets jour à 1*/
    if( int_jour > int_jour_par_mois[int_mois]) {
        int_jour = 1;
        int_mois++;
        /* Si le mois dépasse 12, on incremente année et on mets mois à 1 */
        if(int_mois > 12){
            int_mois = 1;
            int_annee++;
        }
    }

    /* On affiche le jour prédit */
    printf("Dans un jour, on sera %c%d/%c%d/%d\n", int_jour<10?'0':0, int_jour, int_mois<10?'0':0, int_mois, int_annee);

    return 0;
}