/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TP3 : question 3
*/

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 15:10:50
 *
 *  \brief This is the main program
 *
 *
 */

//librairies
#include <stdio.h>
#include <stdlib.h>

/*! 
 *  \def ERROR(msgErreur)
 *  \brief write an error message in stderr
 */
#define ERROR(err) fprintf(stderr, "%s\n", err)

/*---------------------------------------------------------------------*/

/*!
 *  \fn void echange(int , int )
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 15:12:52
 *  \brief swap 2 value
 *  \param int_nb1 1st value to swap
 *  \param int_nb2 2nd value to swap
 *  \return the 2 value are swapped
 */
void echange(int int_nb1, int int_nb2) {
    int int_tmp; //Var tampon to swap

    printf("Before swapping : Nb1 = %d, Nb2 = %d\n", int_nb1, int_nb2);

    /*Swap the 2 values */
    int_tmp = int_nb1;
    int_nb1 = int_nb2;
    int_nb2 = int_tmp;

    printf("After swapping : Nb1 = %d, Nb2 = %d\n", int_nb1, int_nb2);   
}

/*!
 *  \fn int main (void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 15:21:11
 *  \brief Main program
 *  \param void
 *  \return 0 if no error, -1 otherwise
 */
int main (void) {
    int int_nb1; //Var test
    int int_nb2; //Var test
    int_nb1 = 5;
    int_nb2 = 7;

    printf("Before echange() : Nb1 = %d, Nb2 = %d\n", int_nb1, int_nb2);
    
    printf("\nCall of echange() :\n");
    echange(int_nb1, int_nb2);

    printf("\nAfter echange() : Nb1 = %d, Nb2 = %d\n", int_nb1, int_nb2);
     
    return 0;
}

