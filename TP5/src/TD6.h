#ifndef __TD6_H
#define __TD6_H

// librairies
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*! 
 *  \def N
 *  \brief Taille global des tableaux statiques
 */
#define M 10

/*! 
 \def ERREUR
 \brief Write an error message in stderr
*/
#define ERROR(err) fprintf(stderr, '%s\n', err)


/*!
 *  \fn void inversion(int int_tab[M])
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 10:01:47
 *  \brief Proc that inverte the array
 *  \param tint_arr[M], array of M int
 *  \return initial arr but inverted
 */
void inversion(int tint_tab[M]);

/*!
 *  \fn void somme(int int_arr1[M], int int_arr2[M], int int_res[M])
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 10:07:45
 *  \brief sum int_arr1 & int_arr2 values to create a new array
 *  \param tint_arr1[M] array of lenght M
 *  \param tint_arr2[M] array of lenght M
 *  \param tint_res[M] array of lenght M that will be our output
 *  \return each value of int_arr1 & int_arr2 are sum up to create int_res
 */
void somme(int tint_arr1[M], int tint_arr2[M], int tint_res[M]);


/*!
 *  \fn int traversable(int int_arr[M])
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 10:13:32
 *  \brief go through the array to check if it's traversable
 *  \param tint_array[M], array of N integer
 *  \return 1 if traversable, 0 otherwiser
 */
int traversable(int tint_arr[M]);

/*!
 *  \fn int palindrome(char* str_text)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 10:54:41
 *  \brief check if is a palindrome
 *  \param str_text text to check
 *  \return 1 if palindrome, 0 if not
 */
int palindrome(char* str_text);

#endif
