/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TD4
*/

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 16 November 2022 - 16:33:44
 *
 *  \brief This is the main Program
 *
 *
 */

//librairies
#include "ApproximationDePi.h"
#include "ApproximationDeSqrt2.h"
#include <stdio.h>

/*! 
 *  \def EMPTYBUFFER()
 *  \brief Empty the buffer
 */
#define EMPTYBUFFER while (fgetc(stdin) != '\n') 

/*! 
 *  \def ERROR(msgErreur)
 *  \brief write an error message in stderr
 */
#define ERROR(err) fprintf(stderr, "%s\n", err)


/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 16 November 2022 - 16:35:17
 *  \brief Main program
 *  \param void
 *  \return 0 if no error, -1 otherwise
 */
int main (void) {
    
    int int_n; //Var to store the USER's entry
    long ld_n2; //Var to store the USER's entry
    int int_cscanf; //Var to check the scanf's output

    /*Print the menu*/
    printf("*****************************\n");
    printf("* 0 - Exit                  *\n");
    printf("*****************************\n");
    printf("*    Approximation of Pi    *\n");
    printf("*                           *\n");
    printf("* 1 - Quadrillage Disque    *\n");
    printf("* 2 - Madhava Sangamagrama  *\n");
    printf("* 3 - John Wallis           *\n");
    printf("*****************************\n");
    printf("*  Approximation of sqrt(2) *\n");
    printf("*                           *\n");
    printf("* 4 - Isaac Newton          *\n");
    printf("* 5 - Edmund Halley         *\n");
    printf("* 6 - Théon de Smyrne       *\n");
    printf("*****************************\n");
    
    /*ask USER which function he want to use*/
    do
    {
        printf("\nplease enter your choice : ");

        int_cscanf = scanf("%d", &int_n);
        if(int_cscanf == 0 || int_n < 0 || int_n > 6) {
            printf("Wrong input, please enter a number between 0 and 3\n");
        }
        EMPTYBUFFER;
    } while (int_cscanf == 0 || int_n < 0 || int_n > 6);
    
    /*Call the right function*/
    switch (int_n)
    {
    case 0:
        exit(1);
        break;
    
    case 1:
        printf("\nApproximation of Pi : Quadrillage disque\nPlease enter the number of dots we'll generate\n/!\\ Do not exceed %ld\n your entry :", __LONG_MAX__);
        int_cscanf = scanf("%ld", &ld_n2);
        if(int_cscanf == 0) {
            ERROR("Wrong argument in scanf");
            exit(1);
        }
        printf("Approx of Pi : %f\n", Quadrillage(ld_n2));
        break;

    case 2:
        printf("\nApproximation of Pi : Madhava Sangamagrama\nPlease enter a number of iteration (greater the number is, the better it will be)\n/!\\ Do not exceed %ld\n your entry :", __LONG_MAX__);
        int_cscanf = scanf("%ld", &ld_n2);
        if(int_cscanf == 0) {
            ERROR("Wrong argument in scanf");
            exit(1);
        }
        printf("Approx of Pi : %f\n", Madhava(ld_n2));
        break;

    case 3:
        printf("\nApproximation of Pi : John Wallis\nPlease enter a number of iteration (greater the number is, the better it will be)\n/!\\ Do not exceed %ld\n your entry :", __LONG_MAX__);
        int_cscanf = scanf("%ld", &ld_n2);
        if(int_cscanf == 0) {
            ERROR("Wrong argument in scanf");
            exit(1);
        }
        printf("Approx of Pi : %f\n", JohnWallis(ld_n2));
        break;

    case 4:
        printf("\nApproximation of sqrt(2) : Isaac Newton\nPlease enter a number of iteration (greater the number is, the better it will be)\n/!\\ Do not exceed %ld\n your entry :", __LONG_MAX__);
        int_cscanf = scanf("%ld", &ld_n2);
        if(int_cscanf == 0) {
            ERROR("Wrong argument in scanf");
            exit(1);
        }
        printf("Approx of sqrt(2) : %f\n", Newton(ld_n2));
        break;
    
    case 5:
        printf("\nApproximation of sqrt(2) : Edmund Halley\nPlease enter a number of iteration (greater the number is, the better it will be)\n/!\\ Do not exceed %ld\n your entry :", __LONG_MAX__);
        int_cscanf = scanf("%ld", &ld_n2);
        if(int_cscanf == 0) {
            ERROR("Wrong argument in scanf");
            exit(1);
        }
        printf("Approx of sqrt(2) : %f\n", Halley(ld_n2));
        break;

    case 6:
        printf("\nApproximation of sqrt(2) : Théon de Smyrne\nPlease enter a number of iteration (greater the number is, the better it will be)\n/!\\ Do not exceed 807 or we cannot compute\n your entry :");
        int_cscanf = scanf("%ld", &ld_n2);
        if(int_cscanf == 0) {
            ERROR("Wrong argument in scanf");
            exit(1);
        }
        printf("Approx of sqrt(2) : %f\n", Smyrne(1,1,ld_n2));
        break;

    default:
        break;
    }
    return 0;

}

