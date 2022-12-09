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
#include "cryptage.h"

/*-------------------------------Functions--------------------------------------------------------------------------------------*/

int upper(char str_text[]) {
    char *p; //loop variable
    int int_gap; //ascii gap between capital and lowercase letter
    int int_res; //check if string is alphabetic only

    int_res = 1;
    int_gap = 'A' - 'a';

    for( p = str_text; *p; p++){
        if( (*p < 'a' || *p > 'z') && (*p < 'A' && *p > 'Z') && *p != ' '){
            int_res = 0;
        }

        if (*p <= 'z' && *p >= 'a'){
            *p = (*p) + int_gap;    
        };
    }
    return int_res;
}

/*------------------------------------------------------------------------------------------------------------------------------------*/

int* createRotor(int int_gap) {
     
    int* pint_rotor; //array that gonna serve as rotor (A->C && B->D ... if gap == 2)
    int i; //loop variable

    /*init array (26 letters of the alphabet)*/
    pint_rotor = malloc(26 * sizeof(int));

    /*
    *Affect each letter to the correct position
    *   if A => C then C will be index 0
    */
    for (i = 0; i < 26 ; i++){
        pint_rotor[i] = i + (int_gap % 26);
    }

    return pint_rotor;
}

/*------------------------------------------------------------------------------------------------------------------------------------*/

int cesar(char* str_msg, const int int_gap) {
    char *p; //loop variable
    char char_c; //current character
    int* pint_rotor; //similar at Alberti's dial (cadran d'alberti)

    /*init the rotor*/
    pint_rotor = createRotor(int_gap);

    /*change each letter for it's equivalent in the rotor*/
    for( p = str_msg; *p; p++){
        if(*p != ' '){
            *p = pint_rotor[*p];
        }
    }    

    return 1;
}

/*------------------------------------------------------------------------------------------------------------------------------------*/

int vigenere(char* str_msg, const char* str_key) {
    int i; //loop variable 
    char *p; //loop variable
    int int_len; //lenght of the key
    char** ppchar_rotors; //array of rotors (en: Alberti's dial | fr: cadran d'alberti)

    /*Put all letter in capital letter and check if string is alphabetic only*/
    if (upper(str_msg) == 0){
        return 0;
    }

    /*number of rotor that have to be create (= key's lenght)*/
    int_len = strlen(str_key);
    ppchar_rotors = malloc(int_len * sizeof(char*));

    /*Create a rotor for each letter of the key*/
    i = 0;
    for( p = str_key; *p; p++){
        ppchar_rotors[i++] = createRotor(*p - 'A');
    }

    /*for each letter of the msg:
    *   -change it by the corresponding letter of the rotor
    *   -change to next rotor
    */
    i = 0;
    for( p = str_msg; *p; p++){
        *p = ppchar_rotors[i++][*p - 'A'];
        i %= int_len;
    }

    return 1;
}

/*------------------------------------------------------------------------------------------------------------------------------------*/

int scytale(char* str_msg) {
    int i; //loop variable
    int j; //loop varialle
    char** ppchar_matrix; //bloc of N*N to crypt the message
    int int_len; //lenght of the message
    int int_N; //lenght N of the matrix
    int int_pos; //position in the message
    char char_tmp; //temp var to swap in the matrix

    /*Put all letter in capital letter and check if string is alphabetic only*/
    if (upper(str_msg) == 0){
        return 0;
    }

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
        for( j = 0; j < int_N; j++){
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

    return 1;
}


