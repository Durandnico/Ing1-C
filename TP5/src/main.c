/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief Main program
*/

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 10:17:57
 *
 *  \brief 
 *
 *
 */

//librairies
#include "TD6.h"
#include "puissance4.h"
#include "tri.h"
#include <time.h>
#include <string.h>

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 10:18:10
 *  \brief Main program
 *  \param argc : number of parameters
 *  \param argv : Values of the parameters 
 *  \return 0 if no error, -1 otherwise
 */
int main (int argc, char** argv) {
    
    int int_n; //Var to store the USER's entry
    int tint_tab[M]; //Static array for exercice;
    int tint_tab2[M]; //Static array for exercice;
    int tint_tab3[M]; //Static array for exercice;
    int ttint_board[N][N]; //Static array for Connect4
    char str_text[1024]; //string for palindrome
    int int_cscanf; //Var to check the scanf's output
    int i; //loop variable
    float fl_tmp; //to generate random number
    int* pint_arr; //dynamique array for exercice

    (void)argc;
    (void)argv;

    /*Set a seed*/
    srand(time(NULL));
    
    /*Init all value*/
    for( i = 0; i < M; i++){
        fl_tmp = (float) rand();
        tint_tab[i] = (fl_tmp/RAND_MAX)*1000;
    
        fl_tmp = (float) rand();
        tint_tab2[i] = (fl_tmp/RAND_MAX)*1000;

        tint_tab3[i] = 0;
    }
    init(ttint_board);

    /*Print the menu*/
    printf("*****************************\n");
    printf("* 0 - Exit                  *\n");
    printf("*****************************\n");
    printf("*  manip tableau static     *\n");
    printf("*                           *\n");
    printf("* 1 - inversion             *\n");
    printf("* 2 - somme 2 tableaux      *\n");
    printf("* 3 - traversable ?         *\n");
    printf("* 4 - est un palindrome     *\n");
    printf("* 5 - Puissance 4           *\n");
    printf("*****************************\n");
    printf("*   Algorithme de tri       *\n");
    printf("*                           *\n");
    printf("* 6 - tri insertion         *\n");
    printf("* 7 - tri fusion            *\n");
    printf("* 8 - tri dénombrement      *\n");
    printf("*****************************\n");
    
    /*ask USER which function he want to use*/
    do
    {
        printf("\nplease enter your choice : ");

        int_cscanf = scanf("%d", &int_n);
        if(int_cscanf == 0 || int_n < 0 || int_n > 8) {
            printf("Wrong input, please enter a number between 0 and 8\n");
        }
        EMPTYBUFFER;
    } while (int_cscanf == 0 || int_n < 0 || int_n > 8);
    printf("\n\n");

    /*Call the right function*/
    switch (int_n)
    {
    case 1:
        printf("Tableau initial : ");
        
        for( i = 0; i < M; i++)
            {printf("%d |", tint_tab[i]);}
        putchar('\n');

        inversion(tint_tab);

        printf("Tableau inversé");
        for( i = 0; i < M; i++)
            {printf("%d |", tint_tab[i]);}
        putchar('\n');
        break;
    
    case 2:
        printf("Tableaux initiaux :\n");
        
        for( i = 0; i < M; i++)
            {printf("%d |", tint_tab[i]);}
        putchar('\n');

        for( i = 0; i < M; i++)
            {printf("%d |", tint_tab2[i]);}
        putchar('\n');

        somme(tint_tab, tint_tab2, tint_tab3);

        printf("Somme des 2 tableaux :\n");
        for( i = 0; i < M; i++)
            {printf("%d |", tint_tab3[i]);}
        putchar('\n');
        break;

    case 3:
        printf("Tableau initial : ");
        
        for( i = 0; i < M; i++)
            {printf("%d |", tint_tab[i]);}
        putchar('\n');

        printf("le tableau %s traversable !\n", (traversable(tint_tab) == 1)? "est" : "n'est pas");
        break;
        
    case 4:
        printf("Rentrez un mot/phrase a test :");
        int_cscanf = scanf("%[^\n]", str_text);
        printf("\n\nle text %s palindrome !\n", (palindrome(str_text)==1)? "est" : "n'est pas");
        break;

    case 5:
        tourDeJeu(ttint_board);
        break;

    case 6:
        printf("Quel est la taille du tab voulu ? : ");
        do {
            
            int_cscanf = scanf("%d", &int_n);
            if(int_cscanf == 0) {
                printf("Wrong input, please enter a number\n");
            }
            EMPTYBUFFER;
         } while (int_cscanf == 0);
    
        pint_arr = malloc(int_n * sizeof(int));
        for (i = 0; i < int_n; i++){
            fl_tmp = (float) rand();
            pint_arr[i] = (fl_tmp/RAND_MAX)*1000;
        }

        printf("Tableau initial : ");
        
        for( i = 0; i < int_n; i++)
            {printf("%d |", pint_arr[i]);}
        putchar('\n');
    
        triInsertion(pint_arr, int_n);

        printf("Tableau trié : ");
        for( i = 0; i < int_n; i++)
            {printf("%d |", pint_arr[i]);}
        putchar('\n');

        break;

    case 7:
        printf("Quel est la taille du tab voulu ? : ");
        do {
            
            int_cscanf = scanf("%d", &int_n);
            if(int_cscanf == 0) {
                printf("Wrong input, please enter a number\n");
            }
            EMPTYBUFFER;
         } while (int_cscanf == 0);
        
        printf("%d\n", int_n);
        pint_arr = malloc(int_n * sizeof(int));
        for (i = 0; i < int_n; i++){
            fl_tmp = (float) rand();
            pint_arr[i] = (fl_tmp/RAND_MAX)*1000;
        }

        printf("Tableau initial : ");
        
        for( i = 0; i < int_n; i++)
            {printf("%d |", pint_arr[i]);}
        putchar('\n');
    
        triFusion(pint_arr, int_n);

        printf("Tableau trié : ");
        for( i = 0; i < int_n; i++)
            {printf("%d |", pint_arr[i]);}
        putchar('\n');
        
        break;

    case 8:
        printf("Quel est la taille du tab voulu ? : ");
        do {
            
            int_cscanf = scanf("%d", &int_n);
            if(int_cscanf == 0) {
                printf("Wrong input, please enter a number\n");
            }
            EMPTYBUFFER;
         } while (int_cscanf == 0);
    
        pint_arr = malloc(int_n * sizeof(int));
        for (i = 0; i < int_n; i++){
            fl_tmp = (float) rand();
            pint_arr[i] = (fl_tmp/RAND_MAX)*1000;
        }

        printf("Tableau initial : ");
        
        for( i = 0; i < int_n; i++)
            {printf("%d |", pint_arr[i]);}
        putchar('\n');
    
        triDenombrement(pint_arr, int_n);

        printf("Tableau trié : ");
        for( i = 0; i < int_n; i++)
            {printf("%d |", pint_arr[i]);}
        putchar('\n');
        
        break;
    default:
        break;
    }
    return 0;
}