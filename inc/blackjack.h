/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 26/12/2022 20:34:39 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 28/11/2022 18:42:14 by Durandnico   ########     ###              */
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
#include <string.h>
#include <time.h>
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
    #define WINDOW_HEIGHT 720

    /*! 
     *  \def ENTER
     *  \brief keycode of ENTER
     */
    #define ENTER 65293
    

    /*! 
     *  \def TOKEN_INIT
     *  \brief number of token the player as at first
     */
    #define TOKEN_INIT 700
    
    
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
     DIAMOND = 0, HEART, CLUB, SPADE
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
 *  \param coord            : position of the img
 *  \param width            : width of the image
 *  \param height           ; height of the image
 */
typedef struct      s_img
{
    void        *img;
    char	    *addr;
	int		    bits_per_pixel;
	int		    line_length;
	int		    endian;
    t_point     coord;
    int         width;
    int         height;
}                   t_img;


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
}                   t_card;


/*!
 *  \struct t_player
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 21:41:55
 *  \brief Data for a player
 *  \param token        : quantity of tokens the player has
 *  \param card_in_hand : number of card the player has
 *  \param hand         : hand of the player
 *  \param total_value  : points of the player
 *  \param base_x       : x value where the first card will spawn
 *  \param base_y       : y value where the first card will spawn
 *  \param dx           : gap x between 2 cards
 *  \param dy           : gap y between 2 cards
 */

typedef struct      s_player
{
    int         token;
    int         card_in_hand;
    t_card      *hand; 
    int         total_value;
    int         base_x;
    int         base_y;
    int         dx;
    int         dy;
}                   t_player;


/*!
 *  \struct t_key
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 15:31:08
 *  \brief 
 *  \param enter    : bool, true if enter key is press
 */

typedef struct      s_key 
{
    int     enter;
}                   t_key;

/*!
 *  \struct t_recup
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 21:10:17
 *  \brief All data for the window
 *  \param mlx              : pointeur to the mlx
 *  \param win              : pointeur to the window of mlx
 *  \param ingame           : players in game (dealer include as [0])
 *  \param background       : image of the board
 *  \param bet_background   : image of the board with betting chips
 *  \param state            : 0 == betting state | 1 == playing state | -1 == waiting state
 *  \param button           : image of the different button
 *  \param special          : if player can do special plays as double and split
 *  \param datakey          : contain if key are press of not 
 *  \param current_bet      : current bet of the player
 */
typedef struct      s_recup
{
    void	    *mlx;
	void	    *win;
    t_player    *ingame;
    t_img       background;
    t_img       bet_background;
    int         state;
    t_img       *button;
    int         special;
    t_key       datakey;
    int         current_bet;
}                   t_recup;


/*--------------------                CARD.C                 --------------------*/


/*!
 *  \fn t_card create_card(int int_value, t_flush color, t_cardname name)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 22:40:19
 *  \brief create a card with given intels
 *  \param color    : kind of the card
 *  \param name     : name of the card (queen / king)
 *  \param hdie     : if the card is hide or not
 *  \return a card with given value
 */
t_card create_card(t_flush color, t_cardname name, int int_hide);

/*!
 *  \fn int rand_int(int int_target)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 22:58:46
 *  \brief generate a random int between [[0:target]]
 *  \param int_target max value to return
 *  \return random int between 0 and targer
 */
int rand_int(int int_target);

/*!
 *  \fn t_card generate_random_card(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 22:54:13
 *  \brief generate a random card (pick a card)
 *  \param hide     : if the card will be show (== 0) or hide (==1)
 *  \return a random card
 */
t_card generate_random_card(int int_hide);

/*!
 *  \fn char* ccolor_to_string(t_card stru_card)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:55:03
 *  \brief get the correct directory for the card
 *  \param card     : card to get the color of
 *  \return the color of the card in a string
 */
char* ccolor_to_string(t_card stru_card);

/*!
 *  \fn char* cname_to_string(t_card stru_card)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 00:18:15
 *  \brief get the correct NAME.xpm for the card
 *  \param card     : card to get the name of
 *  \return the name of the card in a string
 */
char* cname_to_string(t_card stru_card);


/*!
 *  \proc void draw_card(t_player* ptr_pl_player)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 04:02:35
 *  \brief make the player hit a card
 *  \param player   : pointeur to a player
 *  \param hide     : if the card will be show (== 0) or hide (==1)
 */
void draw_card(t_player* ptr_pl_player, int int_hide);


/*--------------------                INIT.C                 --------------------*/


/*!
 *  \proc void init(t_recup recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 23:38:32
 *  \brief loads images, create board, malloc players, init hook functs, (do a bunch of thing)  
 *  \param recup    : contain all data of the window
 */
void init(t_recup* recup);


/*!
 *  \proc void inti_button(t_recup* rcp_recup )
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 23:48:40
 *  \brief init all button, ( load images, set coordà ready to summon
 *  \param recup    : contain all data of the window
 */
void inti_button(t_recup* rcp_recup);

/*!
 *  \proc void init_key(t_recup* rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 15:40:07
 *  \brief init all key to false (not press)
 *  \param recup    : contain all data of the window
 */
void init_key(t_recup* rcp_recup);

/*!
 *  \proc void init_hook(t_recup* rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 16:01:13
 *  \brief init all hook func
 *  \param recup    : contain all data of the window
 */
void init_hook(t_recup* rcp_recup);


/*!
 *  \proc void init_bets(t_recup* prcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 23:20:36
 *  \brief init all chip button
 *  \param recup    : pointeur to recup of all data for the window
 */
void init_bets_background(t_recup* prcp_recup);


/*--------------------              KEY_DRAW.C               --------------------*/


/*!
 *  \fn int key_release(int int_keycode, t_recup* rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 15:37:12
 *  \brief if a key is release, set it value to false
 *  \param keycode      : code of the pressed key 
 *  \param recup        : data for mlx
 *  \return 0 mandatory fo mlx_hook
 */
int key_release(int int_keycode, t_recup* rcp_recup);

/*!
 *  \fn int key_press(int int_keycode, t_recup* rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 15:14:57
 *  \brief if a key is press, set it value to true
 *  \param keycode      : code of the pressed key 
 *  \param recup        : data for mlx
 *  \return 0 mandatory fo mlx_hook 
 */
int key_press(int int_keycode, t_recup* rcp_recup);

/*!
 *  \fn int mouse_press(int int_button, int int_x, int int_y, t_recup* rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 18:37:56
 *  \brief 
 *  \param button   : code of the pressed button
 *  \param x        : x pos of the mouse
 *  \param y        ; y pos of the mouse     
 *  \param recup    : data for mlx
 *  \return 0 mandatory fo mlx_hook 
 */
int mouse_press(int int_button, int int_x, int int_y, t_recup* rcp_recup);


/*--------------------             MY_MLX_FUNC.C             --------------------*/


/*!
 *  \fn int next_frame(t_recup* recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:27:25
 *  \brief how will be generate each frame
 *  \param recup    : pointeur to recup of all data for the window
 *  \return 0 mandatory fo mlx_hook 
 */
int next_frame(t_recup* recup);


/*!
 *  \fn int show_card(t_recup* recup, t_card* card)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:44:33
 *  \brief show in the windows a card
 *  \param recup    : pointeur to recup of all data for the window
 *  \param card     : pointeur to a card
 *  \return load and show the card in the screen (0 => fail, 1 => sucess)
 */
int show_card(t_recup* recup, t_card* card);


/*!
 *  \proc void drawn_sprite(t_recup* recup, t_img img)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 00:36:36
 *  \brief draw pixel by pixel the sprite on the board (to make chips board transparent)
 *  \param recup    : contain all data of the window
 *  \param img      : image to copy on the background
 */
void drawn_sprite(t_recup* recup, t_img img);


/*----------              BLACKJACK.C              ----------*/


/*!
 *  \fn int exit_prog(t_recup* rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 17:33:02
 *  \brief exit the prog 
 *  \return exit the program
 */
int exit_prog(void);

/*!
 *  \proc void state_switch(t_recup* prcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 03:51:36
 *  \brief change from betting to playing state and vis-versa
 *  \param recup    : all data for the window
 */
void state_switch(t_recup* prcp_recup);


/*----------              BJ_BUTTON.C              ----------*/



/*              END             */
#endif