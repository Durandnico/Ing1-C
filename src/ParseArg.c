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
#include "../inc/ParseArg.h"

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
 *  \fn int IsANumber (char* str_arg)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:31:07
 *  \brief 
 *  \param 
 *  \return 
 */
int
IsANumber (char* str_arg)
{
    /*Return 0 if str_arg is NAN*/
    return atoi(str_arg) <= 0;
}

/*!
 *  \fn int IsAString(char* str_arg)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 07 December 2022 - 10:30:57
 *  \brief 
 *  \param 
 *  \return 
 */
int
IsAString(char* str_arg)
{
    int bool_is_a_str; //bool to check if str_arg is a string
    char *p; //loop variable

    bool_is_a_str = 1;
    
    for(p = str_arg; *p; p++){
        if ((*p < 'a' || *p > 'z') && (*p < 'A' || *p > 'Z')){
            bool_is_a_str = 0;
        }
    }

    return bool_is_a_str;
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
    int tint_output[4] = {0}; //Output of different parsing funct 
    
    int_stop = 1;
    i = 1;
    while ( i < argc && int_stop ){
        if( argv[i][0] == '-'){
            switch (argv[i][1])
            {
            case 'k':
                if(i + 1 != argc){
                    tint_output[3] = IsAString(argv[i + 1]);
                }
                if(tint_output[3] == 1){
                    i++;
                }
                break;

            case 'm':
                if(i + 1 != argc){
                    tint_output[1] = 1;
                }
                if(tint_output[1] == 1){
                    i++;
                }
                break;

            case 'd':
                if(i + 1 != argc){
                    tint_output[2] = IsANumber(argv[i + 1]);
                }
                if(tint_output[2] == 1){
                    i++;
                }
                break;

            case 'c':
                if(i + 1 != argc){
                    tint_output[0] = methode(argv[i + 1]);
                }
                if(tint_output[0] == 0) {
                    int_stop = 0;
                }
                i++;
                break;

            default:
                help();
                int_stop = 0;
                break;
            }
        }
        i++;
    }
    return 1;
}
