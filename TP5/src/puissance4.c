/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief Puissance4 of TD6
*/

/*! 
 *  \file puissance4.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 15:24:58
 *
 *  \brief Program that run an line 4
 *
 *
 */

//librairies
#include "puissance4.h"
#include "TD6.h"

void
init(int ttint_board[N][N])
{
    int i; //loop variable
    int j; //loop variable

    /*set all value of the array to -1*/
    for( i = 0; i < N; i++ ){
        for( j = 0; j < N; j++ ){
            ttint_board[i][j] = -1;
        }
    }

}


char drawCase(int cas) {
     
    if (cas == -1)
        {return ' ';}
    
    if (cas == 1)
        {return 'O';}

    return 'X';
}


void
affichage (int ttint_board[N][N]) 
{
    int i;
    int j;

    
    putchar('\n');

    for( i = -1; i < N; i++)
    {   
        if( i == -1 ){ 
            for( j = -1; j < N; j++){
                printf(" %c |", j < 0 ? ' ' : j + '0');
            }
        }
        else{
            for( j = -1; j < N; j++){
                printf(" %c |", j < 0 ? i+'0' : drawCase(ttint_board[i][j]));
            }
        }
        putchar('\n');

        
        for( j = -1; j < N; j++)
            {printf("%s", j < 0 ? "   +" : "---+");}

        putchar('\n');  
    } 
}


int
jouer(int ttint_board[N][N], int int_player, int int_x)
{
    int int_y; //var to check each row
    
    if(ttint_board[0][int_x] != -1)
        {return 0;}

    /* init att the bottom.*/
    int_y = N-1;
    
    /*start from the bottom to the top of the grid, stop when empty spot*/
    while (ttint_board[int_y][int_x] != -1)
        {int_y--;}


    ttint_board[int_y][int_x] = int_player;

    return 1;   
}


int
aGagner(int ttint_board[N][N])
{
    int i;
    int j;
    int int_res;

    int_res = -1;

    /*Boucle through every combo possible*/
    i = 0;
    while( int_res == -1 && i < N ){
        
        j = 0;
        while( int_res == -1 && j < N ){
            /*Check lines*/
            if(i < (N-3) && ttint_board[j][i] != -1 && ttint_board[j][i] == ttint_board[j][i + 1] && ttint_board[j][i] == ttint_board[j][i + 2] && ttint_board[j][i] == ttint_board[j][i + 3])
                {int_res = ttint_board[j][i];}
            
            /*Check column*/
            if(j > 2 && ttint_board[j][i] != -1 && ttint_board[j][i] == ttint_board[j - 1][i] && ttint_board[j][i] == ttint_board[j - 2][i] && ttint_board[j][i] == ttint_board[j - 3][i])
                {int_res = ttint_board[j][i];}

            /*Check Bottom left to top right diag*/
            if(i < (N-3) && j > 2 && ttint_board[j][i] != -1 && ttint_board[j][i] == ttint_board[j - 1][i + 1] && ttint_board[j][i] == ttint_board[j - 2][i + 2] && ttint_board[j][i] == ttint_board[j - 3][i + 3])
                {int_res = ttint_board[j][i];}

            /*Check top left to bottom right diag*/
            if(i < (N-3) && j < (N-3) && ttint_board[j][i] != -1 && ttint_board[j][i] == ttint_board[j + 1][i + 1] && ttint_board[j][i] == ttint_board[j + 2][i + 2] && ttint_board[j][i] == ttint_board[j + 3][i + 3])
                {int_res = ttint_board[j + 3][i];}

            j++;
        }
        i++;
    }
    
    /*If a player have win return who*/
    if(int_res != -1)
        {return int_res;}
    
    /*Check if there is still a open spot (aka check all top of column)*/
    i = 0;
    while(i < N && ttint_board[0][i] != -1) 
        {i++;}

    /*If so return -1 else is even so return 0*/
    if(i < N)
        {return -1;}


    return 0;
}


void
tourDeJeu(int ttint_board[N][N])
{
    int int_player;
    int int_win;
    int int_cible;
    int int_check;
    char char_tourne;

    int_player = 1;

    /*Game loop*/
    while( (int_win = aGagner(ttint_board)) == -1){
        
        /*show the board*/
        printf("\e[H\e[J");
        affichage(ttint_board);
        
        /*Player move*/
        do{

            printf("\nDans quel colonne veux tu jouer ? : ");
            int_check = scanf("%d", &int_cible);
            if(int_check == 0){
                printf("Erreur de saisie OU colonne remplis !\n\n");
            }

        } while(int_check == 0 || int_cible < 0 || int_cible >= N || jouer(ttint_board, int_player, int_cible) == 0);

        /*Do a tricky aff aff*/
        printf("\e[H\e[J");
        affichage(ttint_board);
        printf("\nDans quel colonne veux tu jouer ? : %d", int_cible);        
    
        EMPTYBUFFER;
        /*Ask for rotation*/
        do{
            printf("\nVeux tu tourner le tableau ? (Y/N): ");
            int_check = scanf("%c", &char_tourne);
            if(int_check == 0){
                printf("Erreur de saisie ! merci de rentrer Y ou N !\n\n");
            }
        } while(int_check == 0 || (char_tourne != 'Y' && char_tourne != 'N'));

        /*Do the rotation*/
        if(char_tourne == 'Y')
            {  
                Rotation90D(ttint_board);
                gravity(ttint_board);
        }

        /*change current player*/
        int_player = (int_player == 1)? 2 : 1;
    }

    /*Show the winner*/
    printf("\e[H\e[J");
    affichage(ttint_board);
    if (int_win == 0){
        printf("Il y a égalité !!\n");
    }else{
        printf("GG au joueur %c qui a gagné !\n", int_win == 1 ? 'O' : 'X');
    }
}


void 
Rotation90D(int ttint_board[N][N])
{
    int i; //loop variabl
    int j; //loop variable
    int int_tmp; //use to swap value

    /*tanspose array column = line*/
    for( i = 0; i < N; i++ ){
        for ( j = i; j < N; j++) {
            int_tmp = ttint_board[i][j];
            ttint_board[i][j] = ttint_board[j][i];
            ttint_board[j][i] = int_tmp; 
        }
    }

    /*flip horizontaly*/
    for( i = 0; i < N; i++){
        for( j = 0; j < N/2; j++){
            int_tmp = ttint_board[i][j];
            ttint_board[i][j] = ttint_board[i][N-j-1];
            ttint_board[i][N-j-1] = int_tmp;
        }
    }   
}



void
gravity(int ttint_board[N][N])
{
     
    int i; //loop variable
    int j; //loop variable
    int int_tmp; //use to swap variable
    int int_bot; //use to save the bottom of the board

    for( i = N-1; i > -1; i--){
        int_bot = N - 1;

        for ( j = N-1; j > -1; j--){
            if(ttint_board[j][i] != -1){
                int_tmp = ttint_board[j][i];
                ttint_board[j][i] = ttint_board[int_bot][i];
                ttint_board[int_bot][i] = int_tmp;
                int_bot--;
            }    
        }
    }
}