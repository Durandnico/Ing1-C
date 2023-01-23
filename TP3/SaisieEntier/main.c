/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TP3 : question 1
*/

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 14:32:12
 *
 *  \brief  This is the main program
 *
 *
 */

// librairies
#include <stdio.h>
#include <stdlib.h>

/*! 
 *  \def ERROR(msgErreur)
 *  \brief write an error message in stderr
 */
#define ERROR(err) fprintf(stderr, "%s\n", err)

/*---------------------------------------------------------------------------------------*/

/*!
 *  \fn int saisieEntier(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 14:37:43
 *  \brief ask the USER an integer 
 *  \param void
 *  \return the integer write by the USER
 */
int saisieEntier(void) {
    int int_number; //Var to store the USER's entry
    int int_cscanf; //Var to check the scanf's output

    /* ask the USER to type an integer */
    printf("Please enter an integer between %d and %d : ", -__INT_MAX__-1, __INT_MAX__);
    int_cscanf = scanf("%d", &int_number);
    if(int_cscanf == 0){
        ERROR("Wrong argument in scanf");
        exit(1);
    }

    return int_number;
}

/*---------------------------------------------------------------------------------------*/

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 14:34:41
 *  \brief Programme principal
 *  \param void
 *  \return 0 si tout s'est bien passé
 */
int main (void) {
    int int_number; //Var to store the USER's entry
    
    /*ask the USER to write an integer then print it */
    int_number = saisieEntier();
    printf("%d\n", int_number);
    
    return 0;
}

