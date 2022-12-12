#ifndef __PUISSANCE4_H
#define __PUISSANCE4_H

/*! 
 *  \file puissance4.h
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 15:18:46
 *
 *  \brief Headers of puissance4.c
 *
 *
 */

// librairies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*! 
 *  \def N 
 *  \brief lenght of grid
 */
#define N 7

/*! 
 *  \def EMPTYBUFFER
 *  \brief empty the stdin buffer
 */
#define EMPTYBUFFER while(getchar() != '\n')

/*!
 *  \fn void init(int ttint_plateau[N][N])
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 15:33:34
 *  \brief set all value to -1
 *  \param  ttint_plateau[N][N] static array N*N of int (actual board of the game)
 *  \return all the value of the array are set to -1
 */
void init(int ttint_plateau[N][N]);


/*!
 *  \fn char drawCase(int cas)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 15:53:23
 *  \brief link a value with a symbole
 *  \param int_cas value of the current case of the board
 *  \return ' ' if -1 | 'O' if 1 | 'X' otherwise
 */
char drawCase(int int_cas);


/*!
 *  \fn void affichage (int ttint_plateau[N][N])
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 15:39:39
 *  \brief print the board in stdout
 *  \param ttint_plateau[N][N] static array N*N of int (actual board of the game)
 *  \return the board is show to the user
 */
void affichage (int ttint_plateau[N][N]);

/*!
 *  \fn int jouer(int ttint_plateau[N][N], int int_joueur, int in_x)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 30 November 2022 - 21:39:44
 *  \brief play the move of the player at column x
 *  \param ttint_plateau[N][N] static array N*N of int (actual board of the game)
 *  \param int_joueur value of the player (1 or 2 only)
 *  \param int_x column where the player want to play
 *  \return 1 if playable, 0 if not
 */
int jouer(int ttint_plateau[N][N], int int_joueur, int int_x);

/*!
 *  \fn int aGagner(int ttint_plateau[N][N])
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 05 December 2022 - 02:31:26
 *  \brief Check if someone has win the game
 *  \param ttint_plateau[N][N] static array N*N of int (actual board of the game)
 *  \return 0 if even, winner player's value or -1 otherwise
 */
int aGagner(int ttint_plateau[N][N]);

/*!
 *  \fn void tourDeJeu(int ttint_plateau[N][N])
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 05 December 2022 - 10:01:53
 *  \brief Game loop
 *  \param ttint_plateau[N][N] static array N*N of int (actual board of the game)
 *  \return Start the game
 */
void tourDeJeu(int ttint_plateau[N][N]);

/*!
 *  \fn void Rotation90D(int ttint_plateau[N][N])
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 06 December 2022 - 09:13:48
 *  \brief rotate the board by 90° clockwise
 *  \param ttint_plateau[N][N] static array N*N of int (actual board of the game)
 *  \return the array as been rotated by 90° clockwise
 */
void Rotation90D(int ttint_plateau[N][N]);

/*!
 *  \fn void gravity(int ttint_plateau[N][N])
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 06 December 2022 - 09:24:54
 *  \brief reposition all the current token of the game
 *  \param ttint_plateau[N][N] static array N*N of int (actual board of the game)
 *  \return make gravity in the board (all flying token fall down)
 */
void gravity(int ttint_plateau[N][N]);
#endif