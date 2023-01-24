/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TD7 in C
*/

/*! 
 *  \file tri.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 05 December 2022 - 10:52:16
 *
 *  \brief 
 *      code different sorting function
 *
 */

//librairies
#include "tri.h"

void triInsertion(int* pint_arr, int int_lenght) {
     
    int i; //loop variable
    int j; //loop variable
    int int_tmp; //variable to swap
    int int_elt; //variable tmp

    for( i = 1; i < int_lenght; i++){
        int_elt = pint_arr[i];
        j = i;
        
        /*While the precedent value is greater, swap them and repeat*/
        while( j > -1 && pint_arr[j - 1] > int_elt){
            int_tmp = pint_arr[j];
            pint_arr[j] = pint_arr[j - 1];
            pint_arr[j - 1] = int_tmp;   
            j--;     
        }
    }
}


int*  copierSousTableau(int* pint_arr, int int_beg, int int_end) {
    
    int int_maxi; //lenght of the new tab
    int* pint_arrCopy; //Copied array
    int i; //loop variable

    /*create the new array*/
    int_maxi = (int_end - int_beg);
    pint_arrCopy = malloc(int_maxi * sizeof(int));

    /*Copy all the value in the new array*/
    for(i = 0; i < int_maxi; i++){
        pint_arrCopy[i] = pint_arr[i + int_beg];
    }

    return pint_arrCopy;
}
 

void fusion(int* pint_arr1, int int_lenght1, int* pint_arr2, int int_lenght2, int* pint_arrRes) {
     
    int i; //loop variable
    int j; //loop variable
    int k; //loop variable
  
    i = 0;
    j = 0;
    k = 0;

    /*merge them into pint_arrRes by ascending order*/
    while(i < int_lenght1 && j < int_lenght2){
        if(pint_arr1[i] < pint_arr2[j]){
            pint_arrRes[k] = pint_arr1[i++];
        }
        else{
            pint_arrRes[k] = pint_arr2[j++];
        }
        k++;
    }

    while ( i < int_lenght1 ){
        pint_arrRes[k++] = pint_arr1[i++];
    }

    while ( j < int_lenght2){
        pint_arrRes[k++] = pint_arr2[j++];
    }
    
}


void triFusion(int* pint_arr, int int_lenght) {

    if(int_lenght > 1 ){ 
        int int_mid = int_lenght / 2; //Split the array in 2
        int* pint_arr1; //Tmp array
        int* pint_arr2; //Tmp array

        /*Each array copy half of the initial array*/
        pint_arr1 = copierSousTableau(pint_arr, 0, int_mid);
        pint_arr2 = copierSousTableau(pint_arr, int_mid , int_lenght);
        
        /*Call the function with the splited array*/
        triFusion(pint_arr1, int_mid);
        triFusion(pint_arr2, int_lenght - int_mid);

        /*Merge them and sort them*/
        fusion(pint_arr1, int_mid, pint_arr2, int_lenght - int_mid, pint_arr);

        free(pint_arr1);
        free(pint_arr2);
    }
}


void triDenombrement(int* pint_arr, int int_lenght) {
    int int_lenghtH; //Lenght of the histogram
    int int_min; //min of the array
    int int_max; //max of the array
    int* pint_histo; //dynamique array for the histogram
    int i; //loop variable
    int j; //loop variable
    int k; //loop variable

    /*get the min and max*/
    MinMaxArray(pint_arr, int_lenght, &int_min, &int_max);

    /*Create and affecte the histogram with all value frequency*/
    int_lenghtH = (int_max - int_min + 1);
    pint_histo = malloc(int_lenghtH * sizeof(int));
    histogramme(pint_arr, int_lenght, pint_histo, int_lenghtH, int_min);

    /*Sort the array*/
    k = 0;
    for( i = 0; i < int_lenghtH; i++){
        for( j = pint_histo[i]; j > 0; j--){
            pint_arr[k++] = int_min + i;
        }
    }
}


void
MinMaxArray(int* pint_arr, int int_lenght, int* pint_min, int* pint_max)
{
    int i; //loop variable; 
    
    *pint_min = pint_arr[0];
    *pint_max = pint_arr[0];

    /*search the min and max of the array*/
    for( i = 1; i < int_lenght; i++){
        *pint_max = MAX(*pint_max, pint_arr[i]);
        *pint_min = MIN(*pint_min, pint_arr[i]);
    }
}


void
histogramme(int* pint_arr, int int_lenght, int* pint_histo, int int_lenghtH, int int_min)
{
    int i; //loop variable
    
    /*Set all value to 0*/
    for( i = 0; i < int_lenghtH; i++){
        pint_histo[i] = 0;
    }

    /*Compt each number apparition*/
    for( i = 0; i < int_lenght; i++){
        pint_histo[ pint_arr[i] - int_min ]++;
    }
}