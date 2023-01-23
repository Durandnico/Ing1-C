/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TP3 : question 2
*/

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 14:58:37
 *
 *  \brief This is the main program
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

/*-------------------------------------------------------------------*/

/*!
 *  \fn void bidon(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 15:01:21
 *  \brief ask the USER to write an integer then print it
 *  \param void
 *  \return write in stdout the USER's entry
 */
void bidon(void) {
    int int_number; //Var to store the USER's entry
    int int_cscanf; //Var to check the scanf's output

    printf("(bidon) : before asking : %d\n", int_number);

    /* ask the USER to type an integer */
    printf("Please enter an integer between %d and %d : ", -__INT_MAX__-1, __INT_MAX__);
    int_cscanf = scanf("%d", &int_number);
    if(int_cscanf == 0){
        ERROR("Wrong argument in scanf");
        exit(1);
    }

    printf("(bidon) : after asking : %d\n", int_number);

}

/*-------------------------------------------------------------------*/

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 15:04:30
 *  \brief Main program 
 *  \param void
 *  \return 0 if no error, -1 otherwise
 */
int main (void) {
    int int_number; //Var to store the USER's entry
    int int_cscanf; //Var to check the scanf's output

    printf("before asking : %d\n", int_number);

    /* ask the USER to type an integer */
    printf("Please enter an integer between %d and %d : ", -__INT_MAX__-1, __INT_MAX__);
    int_cscanf = scanf("%d", &int_number);
    if(int_cscanf == 0){
        ERROR("Wrong argument in scanf");
        exit(1);
    }

    /*Show int_number before and after function bidon()*/
    printf("after asking but before bidon(): %d\n", int_number);
    bidon();
    printf("after bidon : %d\n", int_number);

    return 0;
}