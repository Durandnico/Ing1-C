/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TP8
*/

/*! 
 *  \file cryptage.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 09 December 2022 - 10:46:41
 *
 *  \brief different function to crypt message
 *
 *
 */

//Librairies
#include "../inc/cryptage.h"

/*-------------------------------Functions--------------------------------------------------------------------------------------*/

int* createRotor(int int_gap) {
     
    int* pint_rotor; //array that gonna serve as rotor (A->C && B->D ... if gap == 2)
    int i; //loop variable

    /*init array (128 char of the ascii table)*/
    pint_rotor = malloc(128 * sizeof(int));

    /*
    *Affect each ascii char the value of the translate one
    */
    for (i = 0; i < 128 ; i++){
        pint_rotor[i] = i;

        if((i <= 'Z' && i >= 'A') || (i <= 'z' && i >= 'a')){
            pint_rotor[i] += ((i + int_gap)%26 < int_gap)? 26 - int_gap : int_gap ;
        }
    }
    return pint_rotor;
}

/*------------------------------------------------------------------------------------------------------------------------------------*/

void cesar(char* str_msg, const int int_gap) {
    char *p; //loop variable
    char char_c; //current character
    int* pint_rotor; //similar at Alberti's dial (cadran d'alberti) but for all the ascii Table

    /*init the rotor*/
    pint_rotor = createRotor(int_gap);

    /*change each letter for it's equivalent in the rotor*/
    for( p = str_msg; *p; p++){
        *p = pint_rotor[*p];
    }
}

/*------------------------------------------------------------------------------------------------------------------------------------*/

void vigenere(char* str_msg, const char* str_key) {
    int i; //loop variable 
    char *p; //loop variable
    int int_len; //lenght of the key
    int** ppchar_rotors; //array of rotors (en: Alberti's dial | fr: cadran d'alberti)
    int int_gap; //find the gap of each letter

    /*number of rotor that have to be create (= key's lenght)*/
    int_len = strlen(str_key);
    ppchar_rotors = malloc(int_len * sizeof(int*));

    /*Create a rotor for each letter of the key*/
    i = 0;
    for( p = str_key; *p; p++){
        int_gap = (*p <= 'z' && *p >= 'a')? *p - 'a' + 1: (*p <= 'Z' && *p >= 'A')? *p - 'A' + 1 : 1;
        ppchar_rotors[i++] = createRotor(int_gap);
    }

    /*for each letter of the msg:
    *   -change it by the corresponding letter of the rotor
    *   -change to next rotor
    */
    i = 0;
    for( p = str_msg; *p; p++){
        *p = ppchar_rotors[i++][*p];
        i %= int_len;
    }
}

/*------------------------------------------------------------------------------------------------------------------------------------*/

void scytale(char* str_msg) {
    int i; //loop variable
    int j; //loop varialle
    char** ppchar_matrix; //bloc of N*N to crypt the message
    int int_len; //lenght of the message
    int int_N; //lenght N of the matrix
    int int_pos; //position in the message
    char char_tmp; //temp var to swap in the matrix

    /*Calc the lenght of the matrix*/
    int_len = strlen(str_msg);
    int_N = ceil(sqrt(int_len));

    /*malloc the matrix and init all char*/
    int_pos = 0;
    ppchar_matrix = malloc(int_N * sizeof(char*));
    for( i = 0; i < int_N; i++){
        ppchar_matrix[i] = malloc(int_N * sizeof(char));
        for( j = 0; j < int_N; j++){
            ppchar_matrix[i][j] = (int_pos < int_len)? str_msg[int_pos] : ' ';
            int_pos++;
        }
    }

    /*transpose the matrix (line => column)*/
    for( i = 0; i < int_N; i++){
        for( j = i; j < int_N; j++){
            char_tmp = ppchar_matrix[i][j];
            ppchar_matrix[i][j] = ppchar_matrix[j][i];
            ppchar_matrix[j][i] = char_tmp;
        }
    }

    /*Crypt the message (read line by line)*/
    int_pos = 0;
    for( i = 0; i < int_N; i++){
        for( j = 0; j < int_N; j++){
                str_msg[int_pos++] = ppchar_matrix[i][j];
        }
    }
}


