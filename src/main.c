/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TD8-9
*/

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:00:46
 *
 *  \brief Main program
 *
 *
 */

//librairies
#include <stdio.h>
#include "../inc/cryptage.h"
#include "../inc/ParseArg.h"

/*! 
 \def ERREUR
 \brief Write an error message in stderr
*/
#define ERROR(err) fprintf(stderr, '%s\n', err)

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:01:40
 *  \brief Main program
 *  \param argc : number of parameters
 *  \param argv : Values of the parameters 
 *  \return 0 if no error, -1 otherwise
 */
int main (int argc, char** argv) {

    mainProcess(argc, argv);
    /*
    char tset[1028];
    strcpy(tset, "ABCD");
    //printf("%d\n", atoi(tset));

    //upper(tset);
    printf("\n%s", tset);
    //cesar(tset,1);
    //vigenere(tset, "ab");
    scytale(tset);
    printf("\n: %s\n", tset);
    */
    return 0;
}