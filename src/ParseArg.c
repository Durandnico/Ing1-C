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
#include "../inc/cryptage.h"


void
help(void)
{
    printf("HELP FOR DA PROG");
}


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


int
IsANumber (char* str_arg)
{
    /*Return 0 if str_arg is NAN*/
    return atoi(str_arg) > 0 || (strlen(str_arg) == 1 && str_arg[0] == '0');
}


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


int*
parsingArgv(int argc, char** argv)
{
    int i; //loop variable
    int int_stop; //stop the process
    int* pint_output; //Output of different parsing funct 
    
    /*Init all output value to 0*/
    pint_output = malloc(4 * sizeof(int));
    for( i = 0; i < 4; i++){
        pint_output[i] = 0;
    }

    int_stop = 1;
    i = 1;
    while ( i < argc && int_stop ){
        if( argv[i][0] == '-'){
            switch (argv[i][1])
            {
            case 'k':
                if(i + 1 != argc){
                    pint_output[3] = IsAString(argv[i + 1]);
                }
                if(pint_output[3] == 1){
                    pint_output[3] = ++i;
                    
                    if(pint_output[2] != 0){
                        int_stop = 0;
                        printf("Ne peut pas avoir option 'Key (-k)' et option 'decalage(-d)' ensemble!\n");
                    }
                }
                break;

            case 'm':
                if(i + 1 != argc){
                    pint_output[1] = 1;
                }
                if(pint_output[1] == 1){
                    pint_output[1] = ++i;
                }
                break;

            case 'd':
                if(i + 1 != argc){
                    pint_output[2] = IsANumber(argv[i + 1]);
                }
                if(pint_output[2] == 1){
                    pint_output[2] = ++i;
                
                    if(pint_output[3] != 0){
                        int_stop = 0;
                        printf("Ne peut pas avoir option 'Key (-k)' et option 'decalage(-d)' ensemble!\n");
                    }
                }

                break;

            case 'c':
                if(i + 1 != argc){
                    pint_output[0] = methode(argv[i + 1]);
                }
                if(pint_output[0] == 0) {
                    int_stop = 0;
                }
                i++;
                break;

            default:
                int_stop = 0;
                break;
            }
        }
        i++;
    }
    printf("%d %d %d %d\n", pint_output[0], pint_output[1], pint_output[2], pint_output[3]);
    
    if( !int_stop )
        return NULL;

    return pint_output;
}


int mainProcess(int argc, char** argv) {
     
    int* pint_output; //Outplut of different parsing func
    char* str_key; //output of -k
    int int_decalage; //output of -d
    char str_msg[2048]; //output of -m

    pint_output = parsingArgv(argc, argv);
    if(pint_output == NULL){
        help();
        return 1;
    }

    /*-c is mendatory*/
    if( pint_output[0] == 0 ){
        help();
        return 1;
    }

    /*Cannot have both -d and -k*/
    if( pint_output[3] != 0 && pint_output[2] != 0 ){
        help();
        return 1;
    }

    /*Check for message*/
    if( pint_output [1] == 0 ){
        printf("Please enter the message to crypt : ");
        scanf("%[^\n]", str_msg);
        fgetc(stdin);
    }
    else{
        strcpy(str_msg, argv[pint_output[1]]);
    }

    /*Check for cesar*/
    if( pint_output[0] == 1 ){
        if( pint_output[2] == 0 ){
            printf("\nPlease enter the decalage (int): ");
            scanf("%d", &int_decalage);
        } else {
            int_decalage = atoi(argv[pint_output[2]]);
        }

        cesar(str_msg, int_decalage);
    }

    /*check for vigenere*/
    else if( pint_output[0] == 2 ){
        if( pint_output[3] == 0 ){
            str_key = malloc(sizeof(char*));
            printf("\nPlease enter the key for vigenere (string): ");
            scanf("%s", str_key);
        } else {
            str_key = argv[pint_output[3]];
        }

        vigenere(str_msg, str_key);
    }

    /*Do scytale*/
    else{
        scytale(str_msg);
    }
    
    printf("\nCrypted message : %s\n", str_msg);
    return 0;
}