/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief 
*/

/*! 
 *  \file ParseArg.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:05:42
 *
 *  \brief 
 *
 *
 */

//librairies
#include "ParseArg.h"

/*! 
 \def ERREUR
 \brief Write an error message in stderr
*/
#define ERROR(err) fprintf(stderr, '%s\n', err)

/*!
 *  \fn void help(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:31:23
 *  \brief 
 *  \param 
 *  \return 
 */
void
help(void)
{
    printf("HELP FOR DA PROG");
}

/*!
 *  \fn int methode(char* str_arg)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:31:15
 *  \brief 
 *  \param 
 *  \return 
 */
int
methode(char* str_arg)
{
    if( strcmp(str_arg, "cesar") == 0){
        return 1;
    }

    if( strcmp(str_arg, "vigenere") == 0){
        return 2;
    }

    if( strcmp(str_arg, "scytale") == 0){
        return 3;
    }

    return 0;
}

/*!
 *  \fn int decalage (char* str_arg)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:31:07
 *  \brief 
 *  \param 
 *  \return 
 */
int
decalage (char* str_arg)
{
    /*Return 0 if str_arg is NAN*/
    return atoi(str_arg) <= 0;
}

/*!
 *  \fn int message(char* str_arg)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:30:57
 *  \brief 
 *  \param 
 *  \return 
 */
int
message(char* str_arg)
{
    
}

/*!
 *  \fn int parsingArgv(int int_argc, char** pstr_argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:30:27
 *  \brief 
 *  \param 
 *  \return 
 */
int
parsingArgv(int int_argc, char** pstr_argv)
{

}
