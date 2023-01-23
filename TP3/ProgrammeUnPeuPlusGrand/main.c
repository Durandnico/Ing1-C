/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TP3 : question 4
*/

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 15:35:20
 *
 *  \brief This is the main program
 *
 *
 */

//librairies
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*! 
 *  \def ERROR(msgErreur)
 *  \brief write an error message in stderr
 */
#define ERROR(err) fprintf(stderr, "%s\n", err)

/*! 
 *  \def EMPTYBUFFER()
 *  \brief 
 */
#define EMPTYBUFFER while (fgetc(stdin) != '\n') 

/*---------------------------------------------------------------------*/

/*!
 *  \fn void AffichageTriangle(int int_n)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 15:35:56
 *  \brief print a triangle of height n and width 2n-1
 *  \param int_n height of the triangle (n > 0)
 *  \return print a triangle of height n and width 2n-1
 */
void AffichageTriangle(int int_n) {
    /*Check if triangle is possible*/
    if(int_n <= 0){
        ERROR("Can not print a triangle of height <= 0 !");
        exit(1);
    }

    for(int i = 0; i < int_n; i++){
        /*Print the number of spaces*/
        for(int j = int_n - i - 1; j > 0; j--){
            putchar(' ');
        }

        /*Print the number of stars*/
        for(int j = (2*i) + 1; j > 0; j--){
            putchar('*');
        }

        /*end of the line*/
        putchar('\n');
    }    
}

/*---------------------------------------------------------------------*/

/*!
 *  \fn void MultiplicationTable(int int_n)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 15:43:51
 *  \brief print the Multiplication table of n
 *  \param int_n show all multiple of n from 1 time n to 10 times n
 *  \return print the Multiplication table of n
 */
void MultiplicationTable(int int_n) {
    
    printf("Multiplication table of %d : \n", int_n);

    for(int i = 1; i < 11; i++){
        printf("%d x %d = %d\n", i, int_n, (i * int_n));
    }

}

/*---------------------------------------------------------------------*/

/*!
 *  \fn int power(int , int)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 16:25:07
 *  \brief calcul int_n at the power of int_pow
 *  \param int_n inital value
 *  \param int_pow power to reach
 *  \return int_n at the power of int_pow
 */
int power(int int_n, int int_pow) {    
    /*Check if ask to calul a negative power*/
    if(int_pow < 0){
        ERROR("Do not calcul negative power");
        exit(1);
    }
    /*stop case*/
    else if( int_pow == 0) {
        return 1;
    }
    /*recursivity*/
    else{
        return int_n * power(int_n, int_pow - 1);
    }
}

/*---------------------------------------------------------------------*/

/*!
 *  \fn void armstrong(int)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 16:07:25
 *  \brief calculate the Armstrong number of int_n
 *  \param int_n Number we will calcule Armstrong's number of (int_n >= 0)
 *  \return if int_n is an Armstrong number or not
 */
void armstrong(int int_n) {
    char str_number[10]; //Var to store int_n as str 
    int int_res; //Var to store the result
    int int_len; //Var to store the len of str_number;
    
    /*Affect str_number, ld_res, int_len*/
    sprintf(str_number, "%d", int_n);
    int_res = 0; 
    int_len = strlen(str_number);

    /*calcul of Armstrong number*/
    for(int i = 0; i < int_len; i++){
        int_res += power((str_number[i] - '0'), int_len);
    }

    /*Is or is not an Armstrong number*/
    if(int_res == int_n) {
        printf("%d is ",int_n);
    }
    else{
        printf("%d is not ",int_n);
    }

    printf("an Armstrong number\n");
}

/*---------------------------------------------------------------------*/

/*!
 *  \fn void menu(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 17:13:59
 *  \brief menu to choose which function use
 *  \param void
 *  \return print a menu in stdout
 */
void menu(void) {
    int int_n; //Var to store the USER's entry
    int int_n2; //Var to store the USER's entry
    int int_cscanf; //Var to check the scanf's output

    /*Print the menu*/
    printf("*****************************\n");
    printf("* 0 - Exit                  *\n");
    printf("* 1 - Draw a triangle       *\n");
    printf("* 2 - Multiplication table  *\n");
    printf("* 3 - Armstrong number      *\n");
    printf("*****************************\n");
    
    /*ask USER which function he want to use*/
    do
    {
        printf("\nplease enter your choice : ");

        int_cscanf = scanf("%d", &int_n);
        if(int_cscanf == 0 || int_n < 0 || int_n > 3) {
            printf("Wrong input, please enter a number between 0 and 3\n");
        }
        EMPTYBUFFER;
    } while (int_cscanf == 0 || int_n < 0 || int_n > 3);
    
    /*Call the right function*/
    switch (int_n)
    {
    case 0:
        exit(1);
        break;
    
    case 1:
        printf("\nYou just choose Draw a triangle,\nPlease enter a the height of it : ");
        int_cscanf = scanf("%d", &int_n2);
        if(int_cscanf == 0) {
            ERROR("Wrong argument in scanf");
            exit(1);
        }
        AffichageTriangle(int_n2);
        break;

    case 2:
        printf("\nYou just choose Multiplication table,\nPlease enter a the number you want the table of : ");
        int_cscanf = scanf("%d", &int_n2);
        if(int_cscanf == 0) {
            ERROR("Wrong argument in scanf");
            exit(1);
        }
        MultiplicationTable(int_n2);
        break;

    case 3:
        printf("\nYou just choose armstrong number,\nPlease enter a number : ");
        int_cscanf = scanf("%d", &int_n2);
        if(int_cscanf == 0) {
            ERROR("Wrong argument in scanf");
            exit(1);
        }
        armstrong(int_n2);
        break;

    default:
        break;
    }
}
/*---------------------------------------------------------------------*/

/*!
 *  \fn int main (void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 07 November 2022 - 15:40:54
 *  \brief Main program 
 *  \param void
 *  \return 0 if no error, -1 otherwise
 */
int main (void) {
    
   
	printf("%d %d \n", rand()%9, RAND_MAX);
    return 0;
}
