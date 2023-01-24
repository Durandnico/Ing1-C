/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TD6 : Tableau 1D
*/

/*! 
 *  \file TD6.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 10:00:11
 *
 *  \brief Functions to answer (1) Tableau 1D of TD6 
 *
 *
 */

//librairies
#include "TD6.h"

/*------------------------------------------------------------------------------------------------------------------*/

void
inversion(int tint_arr[M])
{
    int int_tmp; //temp variable to switch arr's value
    int i; //loop variable

    /*loop to inverte the array*/
    for ( i = (M+1)/2; i > 0; i--) {
        int_tmp = tint_arr[i-1];
        tint_arr[i-1] = tint_arr[M-i];
        tint_arr[M-i] = int_tmp; 
    }
}

/*------------------------------------------------------------------------------------------------------------------*/

void
somme(int tint_arr1[M], int tint_arr2[M], int int_res[M])
{
    int i; //loop variable

    /*Loop through the arrays, sums their value and affect it to a new arr*/
    for ( i = 0; i < M; i++){
        int_res[i] = tint_arr1[i] + tint_arr2[i];
    }
}

/*------------------------------------------------------------------------------------------------------------------*/

int
traversable(int tint_arr[M])
{
    int int_alreadyVisite[M]; //To check if do not loop (like +1 -1 +1 -1 .....)
    int int_index; //track of where we are in the array
    int i; //loop variable

    /*Init index = 0 (start of the array) & alreadyVisit {0,0,0...} cause non of the value have been visited*/
    int_index = 0;
    for( i = 0; i < M; i++){
        int_alreadyVisite[i] = 0;
    }

    /*Do it's job*/
    while(int_index < (M-1) &&  int_index >= 0 && int_alreadyVisite[int_index] == 0){
        int_alreadyVisite[int_index] = 1;
        int_index += tint_arr[int_index];
    }

    
    if( int_index > (M-1) || int_index < 0 || int_alreadyVisite[int_index] == 1) {
        return 0;
    }

    return 1;
}

/*------------------------------------------------------------------------------------------------------------------*/

int
palindrome(char* str_text)
{
    int int_beg; //loop from left to right
    int int_end; //loop from right to left
    int int_res; //store the answer (bool)

    int_res = 1;
    int_beg = 0;
    int_end = strlen(str_text) - 1;

    /*Loop through all caractères*/
    while(int_beg < int_end && int_res){

        /*Skip all spaces*/
        while(str_text[int_beg] == ' '){
            int_beg++;
        }
        while(str_text[int_end] == ' '){
            int_end--;
        }

        /*Check if char are not the same*/
        if( int_beg < int_end && str_text[int_beg] != str_text[int_end]){
            int_res = 0;
        }
        
        int_beg++;
        int_end--;
    }
    
    return int_res;
}