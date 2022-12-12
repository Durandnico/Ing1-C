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
    if( strcmp(str_arg, "-m") == 0){
        return 0;
    }

    if( strcmp(str_arg, "-k") == 0){
        return 0;
    }

    if( strcmp(str_arg, "-d") == 0){
        return 0;
    }

    if( strcmp(str_arg, "--help") == 0){
        return 0;
    }
    return 1;
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
parsingArgv(int argc, char** argv)
{
    int i; //loop variable
    int int_stop; //stop the process
    int int_output; //check the output of parsing funct

    int_stop = 1;
    i = 1;
    while ( i < argc && int_stop ){
        if( argv[i][0] == '-'){
            switch (argv[i][1])
            {
            case 'k':
                if(i + 1 != argc){
                    int_output = key(argv[i + 1]);
                }
                break;
            case 'm':
                if(i + 1 != argc){
                    int_output = message(argv[i + 1]);
                }
                break;
            case 'd':
                if(i + 1 != argc){
                    int_output = decalage(argv[i + 1]);
                }
                break;
            default:
                help();
                int_stop = 0;
                break;
            }
        }
    }
}
