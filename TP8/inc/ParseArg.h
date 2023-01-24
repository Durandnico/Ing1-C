#ifndef __PARSEARG_H
#define __PARSEARG_H

/*! 
 *  \file ParseArg.h
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:02:29
 *
 *  \brief Headers of ParseArg.c
 *
 *
 */

// librairies
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*! 
 \def ERREUR
 \brief Write an error message in stderr
*/
#define ERROR(err) fprintf(stderr, '%s\n', err)



/*!
 *  \fn int* parsingArgv(int int_argc, char** pstr_argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:30:27
 *  \brief parse argument
 *  \param argc : number of argument
 *  \param argv : value of the argument
 *  \return array of output
 */
int* parsingArgv(int int_argc, char** pstr_argv);


/*!
 *  \fn int IsAString(char* str_arg)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:30:57
 *  \brief verify if str_arg is a word (letter only)
 *  \param str_arg: string to verify
 *  \return 1 if contains only letter, 0 otherwise
 */
int IsAString(char* str_arg);


/*!
 *  \fn int IsANumber (char* str_arg)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:31:07
 *  \brief verify if str_arg is a number
 *  \param str_arg: string to verify
 *  \return 1 if contains only number, 0 otherwise
 */
int IsANumber (char* str_arg);


/*!
 *  \fn int methode(char* str_arg)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:31:15
 *  \brief Verify if the string is one of the methodes
 *  \param str_arg: string to verify
 *  \return the index of the correct methode, 0 if it's not one
 */
int methode(char* str_arg);


/*!
 *  \fn void help(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:31:23
 *  \brief print the help in stdout
 *  \param void
 *  \return show the help menu
 */
void help(void);

/*!
 *  \fn int mainProcess(int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 21 December 2022 - 02:35:25
 *  \brief process through argument and start correct crypt
 *  \param argc : number of argument
 *  \param argv : value of the argument
 *  \return crypt the message (if possible)
 */
int mainProcess(int argc, char** argv);
#endif