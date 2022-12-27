/*!
/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 26/12/2022 20:34:39 by Durandnico   #+#    #+#    #+#             */
/*   Updated: None                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */


/*! 
 *  \file blackJack.h
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 20:34:39
 *
 *  \brief Structures and headers of all functions
 * 
 */

#ifndef __BLACKJACK_H
#define __BLACKJACK_H

// librairies
#include <stdlib.h>
#include <stdio.h>
#include "../minilibx-linux/mlx.h"


/*----------                DEFINE                 ----------*/

    /*! 
     *  \def WINDOW_WIDTH
     *  \brief 
     */
    #define WINDOW_WIDTH 1280

    /*! 
     *  \def WINDOW_HEIGHT
     *  \brief 
     */
    #define WINDOW_HEIGHT 800
    
    /*! 
     *  \def ALT
     *  \brief keycode of ALT
     */
    #define ALT 1

    /*! 
     *  \def F4
     *  \brief keycode of F4
     */
    #define F4 2

/*----------                MACRO                  ----------*/

/*! 
 *  \def NAMETOVALUE
 *  \brief 
 */
#define NAMETOVALUE(a) (a > 10) ? 10: a


/*----------          STRUCTURES & ENUMS           ----------*/

/*!
 *  \struct t_point
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 20:42:30
 *  \brief coord of a point (x and y) 
 *  \param x : x value of the point
 *  \param y : y value of the point
 */
typedef struct      s_point
{
    int x;  
    int y;
}                   t_point;


/*!
 *  \enum t_flush
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 20:39:52
 *  \brief kind of the card (Diamond, hearth, club or spade)
 */
typedef enum    s_flush
{
     DIAMOND = 0, HEARTH, CLUB, SPADE
}               t_flush;


/*!
 *  \enum t_cardname
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 20:49:16
 *  \brief Name of all card
 */
typedef enum    s_cardname
{
    AS = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, T, J, Q, K
}               t_cardname;


/*!
 *  \struct t_card
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 20:38:20
 *  \brief every data mandatory for a card
 *  \param value    : value (in point) of the card
 *  \param color    : kind of the card
 *  \param name     : name of the card
 *  \param img      : img of the card
 *  \param hide     : boolean, card visible or not
 */
typedef struct      s_card
{
    int             value;
    t_flush         color;
    t_cardname      name;
    t_img           img;
    int             hide;
}t_card;


/*!
 *  \struct t_player
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 21:41:55
 *  \brief Data for a player
 *  \param token        : quantity of tokens the player has
 *  \param hand         : hand of the player
 *  \param total_value  : points of the player
 */

typedef struct      s_player
{
    int         token;
    t_card      *hand; 
    int         total_value;
}                   t_player;


/*!
 *  \struct t_img
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 21:11:20
 *  \brief All data mandatory for an image in mlx
 *  \param img              : pointeur to the img
 *  \param addr             : pointeur to memory adress of the image
 *  \param bits_per_pixel   : mandatory for mlx
 *  \param line_length      : mandatory for mlx
 *  \param endian           : mandatory for mlx
 *  \param spricte_link     : link to the sprite to use
 *  \param coord            : position of the img
 */
typedef struct      s_img
{
    void        *img;
    char	    *addr;
	int		    bits_per_pixel;
	int		    line_length;
	int		    endian;
    char        *sprite_link;
    t_point     coord;
}                   t_img;


/*!
 *  \struct t_recup
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 21:10:17
 *  \brief All data for the window
 *  \param mlx      : pointeur to the mlx
 *  \param win      : pointeur to the window of mlx
 *  \param cards    : cards on the board
 *  \param state    : 0 == betting state | 1 == playing state   
 *  \param bet_img  : image of betting chips (betting phase)
 *  \param button   : image of the different button
 *  \param special  : if player can do special plays as double and split 
 */
typedef struct      s_recup
{
    void	*mlx;
	void	*win;
    t_card  *cards;
    int     state;
    t_img   *bet_img;
    t_img   *button;
    int     special;
}                   t_recup;

/*----------                CARD.C                 ----------*/



/*----------                INIT.C                 ----------*/



/*----------              KEY_DRAW.C               ----------*/



/*----------             MY_MLX_FUNC.C             ----------*/



/*----------              BLACKJACK.C              ----------*/



/*----------              BJ_BUTTON.C              ----------*/

#endif