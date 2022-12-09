#ifndef __CRYPTAGE_H
#define __CRYPTAGE_H

/*! 
 *  \file cryptage.h
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 09 December 2022 - 10:46:23
 *
 *  \brief headers of cryptage.c
 *
 *
 */

// librairies
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*! 
 \def ERREUR
 \brief Write an error message in stderr
*/
#define ERROR(err) fprintf(stderr, '%s\n', err)


/*!
 *  \fn int* createRotor(int int_gap)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 09 December 2022 - 10:54:36
 *  \brief create a rotor that gonna transform letter in others
 *  \param int_gap the gap between 2 letter, if A => C then gap must be 2
 *  \return rotor with a gap of int_gap 
 */
int* createRotor(int int_gap);

/*!
 *  \fn void cesar(char* str_msg, int int_gap)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 09 December 2022 - 10:49:56
 *  \brief crypt a message with cesar's methode
 *  \param str_msg message to encrypt
 *  \param int_gap key for cesar's cryptage. 
 *  \return crypted message
 */
void cesar(char* str_msg, const int int_gap);

/*!
 *  \fn void vigenere(char* str_msg, char* str_key)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 09 December 2022 - 11:11:57
 *  \brief crypt a message with vigenere's methode
 *  \param str_msg message to encrypt
 *  \param int_gap key for vigenere's cryptage. 
 *  \return crypted message
 */
void vigenere(char* str_msg, const char* str_key);

/*!
 *  \fn void scytale(char str_msg)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 09 December 2022 - 11:34:45
 *  \brief crypt a message with scytale's methode
 *  \param str_msg message to encrypt
 *  \return crypted message (lenght may be greater)
 */
void scytale(char* str_msg);

#endif