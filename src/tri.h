#ifndef __TRI_H
#define __TRI_H

/*! 
 *  \file tri.h
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 05 December 2022 - 10:41:29
 *
 *  \brief Headers of tri.c
 *
 *
 */

// librairies
#include <stdlib.h>
#include <stdio.h>

/*! 
 *  \def MAX(a,b)
 *  \brief return max between a and b
 */
#define MAX(a,b) (a<b)? b : a

/*! 
 *  \def MIN(a,b)
 *  \brief return min between a and b
 */
#define MIN(a,b) (a<b)? a : b

/*!
 *  \fn void triInsertion(int* pint_arr, int int_lenght)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 05 December 2022 - 10:54:49
 *  \brief sort the array by insertion
 *  \param pint_arr dynamique array
 *  \param int_lenght lenght of the array
 *  \return sorted array
 */
void triInsertion(int* pint_arr, int int_lenght);

/*!
 *  \fn int*  copierSousTableau(int* pint_arr, int int_beg, int int_end)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 05 December 2022 - 11:03:05
 *  \brief copy a port of the array into an other new one 
 *  \param pint_arr dynamique array
 *  \param int_beg index where we start the copy
 *  \param int_end index where we end the copy
 *  \return an dynamique array of lenght (int_end - int_beg + 1), the copy of pint_arr from index beg to end
 */
int*  copierSousTableau(int* pint_arr, int int_beg, int int_end);

/*!
 *  \fn void fusion(int* pint_arr1, int int_lenght1, int* pint_arr2, int int_lenght2, int* pint_arrRes)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 05 December 2022 - 11:07:34
 *  \brief merge 2 array and sort them.
 *  \param pint_arr1 dynamique array of int
 *  \param int_lenght1 lenght of the array 1
 *  \param pint_arr2 dynamique array of int
 *  \param int_lenght2 lenght of the array 2
 *  \param pint_arrRes dynamique array of int
 *  \return an sorted merged array
 */
void fusion(int* pint_arr1, int int_lenght1, int* pint_arr2, int int_lenght2, int* pint_arrRes);

/*!
 *  \fn void triFusion(int* pint_arr, int int_lenght);
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 05 December 2022 - 11:12:13
 *  \brief merge sort the array
 *  \param pint_arr dynamique array
 *  \param int_lenght lenght of the array
 *  \return a array sorted
 */
void triFusion(int* pint_arr, int int_lenght);

/*!
 *  \fn void triDenombrement(int* pint_arr, int int_lenght)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 06 December 2022 - 10:40:58
 *  \brief sort the array by frequency check
 *  \param pint_arr dynamique array
 *  \param int_lenght lenght of the array
 *  \return a sorted array
 */
void triDenombrement(int* pint_arr, int int_lenght);

/*!
 *  \fn void MinMaxArray(int* pint_arr, int int_lenght, int* int_min, int* int_max)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 06 December 2022 - 10:49:17
 *  \brief find the min and max of an array
 *  \param pint_arr dynamique array
 *  \param int_lenght lenght of the array
 *  \param pint_min adress a of a variable that gonna store the min
 *  \param pint_max adress a of a variable that gonna store the max
 *  \return affcte the min and max of the array at the adress pint_min/max
 */
void MinMaxArray(int* pint_arr, int int_lenght, int* pint_min, int* pint_max);

/*!
 *  \fn void histogramme(int* pint_arr, int int_lenght, int* pint_histo, int int_lenghtH, int int_min)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 06 December 2022 - 10:53:55
 *  \brief calc the frequency of each value of the array
 *  \param pint_arr dynamique array
 *  \param int_lenght lenght of the array
 *  \param pint_histo dynamique array of the histogram
 *  \param int_lenghtH lenght of the histogram
 *  \param int_min value minimun in the array
 *  \return an histogram with the frenquency of each value of the array
 */
void histogramme(int* pint_arr, int int_lenght, int* pint_histo, int int_lenghtH, int int_min);

#endif