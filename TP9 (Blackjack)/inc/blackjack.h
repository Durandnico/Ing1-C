/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 26/12/2022 20:34:39 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 30/11/2022 06:41:05 by Durandnico   ########     ###              */
/*                                                                              */
/* **************************************************************************** */


/*! 
 *  \file blackjack.h
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
#include <unistd.h>
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
     *  \def TOKEN_INIT
     *  \brief number of token the player as at first
     */
    #define TOKEN_INIT 700
    
    /*! 
     *  \def LEFT_CLICK
     *  \brief keycode of LEFT_CLICK
     */
    #define LEFT_CLICK 1
    
    /*! 
     *  \def RIGHT_CLICK
     *  \brief keycode RIGHT_CLICK
     */
    #define RIGHT_CLICK 3
    
    
/*----------                MACRO                  ----------*/

/*! 
 *  \def NAMETOVALUE
 *  \brief 
 */
#define NAMETOVALUE(a) (a > 10) ? 10: (a == 1) ? 11 : a


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
 *  \param
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
    t_img       score;
}                   t_player;


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
 *  \param x2               : if player can do a double
 *  \param split            : if player can do a split
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
    int         x2;
    int         split;
    int         current_bet;
}                   t_recup;


/*--------------------                CARD.C                 --------------------*/


/*!
 *  \fn t_card create_card(t_flush flush_color, t_cardname cdname_name, int int_hide)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 22:40:19
 *  \brief create a card with given intels
 *  \param flush_color      : kind of the card
 *  \param cdname_name      : name of the card (queen / king)
 *  \param int_hide         : if the card is hide or not
 *  \return a card with given value
 */
t_card create_card(t_flush flush_color, t_cardname cdname_name, int int_hide);


/*!
 *  \fn t_card generate_random_card(int int_hide)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 22:54:13
 *  \brief generate a random card (pick a card)
 *  \param hide     : if the card will be show (== 0) or hide (==1)
 *  \return a random card
 */
t_card generate_random_card(int int_hide);

/*!
 *  \fn char* ccolor_to_string(t_card cd_card)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:55:03
 *  \brief get the correct directory for the card
 *  \param cd_card     : card to get the color of
 *  \return the color of the card in a string
 */
char* ccolor_to_string(t_card cd_card);

/*!
 *  \fn char* cname_to_string(t_card cd_card)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 00:18:15
 *  \brief get the correct NAME.xpm for the card
 *  \param cd_card     : card to get the name of
 *  \return the name of the card in a string
 */
char* cname_to_string(t_card cd_card);


/*!
 *  \proc void draw_card(t_player* ptr_pl_player, int int_hide)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 04:02:35
 *  \brief make the player hit a card
 *  \param ptr_pl_player    : pointeur to a player
 *  \param int_hide         : if the card will be show (== 0) or hide (==1)
 */
void draw_card(t_player* ptr_pl_player, int int_hide);


/*--------------------                INIT.C                 --------------------*/


/*!
 *  \proc void init(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 23:38:32
 *  \brief loads images, create board, malloc players, init hook functs, (do a bunch of thing)  
 *  \param ptr_rcp_recup    : contain all data of the window
 */
void init(t_recup* ptr_rcp_recup);


/*!
 *  \proc void inti_button(t_recup* ptr_rcp_recup )
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 23:48:40
 *  \brief init all button, ( load images, set coordà ready to summon
 *  \param ptr_rcp_recup    : contain all data of the window
 */
void init_button(t_recup* ptr_rcp_recup);


/*!
 *  \proc void init_hook(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 16:01:13
 *  \brief init all hook func
 *  \param ptr_rcp_recup    : contain all data of the window
 */
void init_hook(t_recup* ptr_rcp_recup);


/*!
 *  \proc void init_bets(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 23:20:36
 *  \brief init all chip button
 *  \param ptr_rcp_recup    : pointeur to recup of all data for the window
 */
void init_bets_background(t_recup* ptr_rcp_recup);


/*!
 *  \proc void init_bet_money_score(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 30 December 2022 - 02:37:53
 *  \brief draw the money square on both background and draw score zone on background
 *  \param ptr_rcp_recup    : all data of the window 
 */
void init_bet_money_score(t_recup* ptr_rcp_recup);


/*--------------------              KEY_DRAW.C               --------------------*/


/*!
 *  \fn int mouse_press(int int_button, int int_x, int int_y, t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 18:37:56
 *  \brief 
 *  \param int_button       : code of the pressed button
 *  \param int_x            : x pos of the mouse
 *  \param int_y            : y pos of the mouse     
 *  \param ptr_rcp_recup    : data for mlx
 *  \return 0 mandatory fo mlx_hook 
 */
int mouse_press(int int_button, int int_x, int int_y, t_recup* ptr_rcp_recup);


/*--------------------             MY_MLX_FUNC.C             --------------------*/


/*!
 *  \fn int show_card(t_recup* ptr_rcp_recup, t_card* ptr_cd_card)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:44:33
 *  \brief show in the windows a card
 *  \param ptr_rcp_recup    : pointeur to recup of all data for the window
 *  \param ptr_cd_card      : pointeur to a card
 *  \return load and show the card in the screen (0 => fail, 1 => sucess)
 */
int show_card(t_recup* ptr_rcp_recup, t_card* ptr_cd_card);


/*!
 *  \proc void drawn_sprite(t_img* ptr_img_base, t_img img_to_add, int int_x, int int_y)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 00:36:36
 *  \brief draw pixel by pixel the sprite on the board (to make chips board transparent)
 *  \param ptr_img_base         : base image
 *  \param img_to_add           : image to copy on the other one
 *  \param int_x                : x pos where to draw the sprite
 *  \param int_y                : y pos where to draw the sprite
 */
void drawn_sprite(t_img* ptr_img_base, t_img img_to_add, int int_x, int int_y);


/*!
 *  \proc void show_everything(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 23:29:23
 *  \brief update the window for playing
 *  \param ptr_rcp_recup    : all data for the window
 */
void show_everything(t_recup* ptr_rcp_recup);


/*!
 *  \proc void show_betting(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 30 December 2022 - 04:03:50
 *  \brief refresh the betting window
 *  \param ptr_rcp_recup    : all the data for the window
 */
void show_betting(t_recup* ptr_rcp_recup);


/*!
 *  \proc void show_score(t_recup* ptr_rcp_recup, t_player* ptr_pl_player)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 19:52:58
 *  \brief print score of the player
 *  \param ptr_recup    : all the data for the window
 *  \param ptr_player   : pointeur to a player 
 */
void show_score(t_recup* ptr_rcp_recup, t_player* ptr_pl_player);


/*!
 *  \proc void show_bet_wallet(t_recup* ptr_rcp_recup, t_player ptr_player)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 30 December 2022 - 03:52:51
 *  \brief print wallet and current bet of the player
 *  \param ptr_rcp_recup    : all the data for the window
 *  \param pl_player        : main player 
 */
void show_bet_wallet(t_recup* ptr_rcp_recup, t_player ptr_player);


/*----------              BLACKJACK.C              ----------*/


/*!
 *  \fn int exit_prog(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 17:33:02
 *  \brief exit the prog 
 *  \return exit the program
 */
int exit_prog(void);

/*!
 *  \proc void state_switch(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 03:51:36
 *  \brief change from betting to playing state and vis-versa
 *  \param ptr_rcp_recup    : all data for the window
 */
void state_switch(t_recup* ptr_rcp_recup);


/*----------              BJ_BUTTON.C              ----------*/


/*!
 *  \proc void hit(t_recup* ptr_rcp_recup, t_player* ptr_pl_player)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 18:54:20
 *  \brief hit a card for a player
 *  \param ptr_rcp_recup    : all data dor the window
 *  \param ptr_pl_player    : pointeur to a player 
 */
void hit(t_recup* ptr_rcp_recup, t_player* ptr_pl_player);


/*!
 *  \proc void calc_score(t_recup* ptr_rcp_recup, t_player* ptr_pl_player)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 19:15:39
 *  \brief check score and update the window 
 *  \param ptr_rcp_recup    : all data dor the window
 *  \param ptr_pl_player    : pointeur to a player 
 */
void calc_score(t_recup* ptr_rcp_recup, t_player* ptr_pl_player);


/*!
 *  \proc void double_hit(t_recup* ptr_rcp_recup, t_player* ptr_pl_player)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 30 December 2022 - 05:01:47
 *  \brief make a double !
 *  \param ptr_rcp_recup    : all data dor the window
 *  \param ptr_pl_player    : pointeur to a player 
 */
void double_hit(t_recup* ptr_rcp_recup, t_player* ptr_pl_player);


/*!
 *  \proc void stay(t_recup* ptr_rcp_recup, int int_cas)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 30 December 2022 - 05:16:56
 *  \brief change the turn to the dealer
 *  \param ptr_rcp_recup    : all data dor the window
 *  \param int_cas          : type de stay (0 : classic, 1 : blackJack / overpass 21)
 */
void stay(t_recup* ptr_rcp_recup, int int_cas);


/*----------              MY_FUNC.C              ----------*/


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
 *  \fn char* itoa(int int_value)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 30 December 2022 - 00:16:04
 *  \brief transform int to string
 *  \param int_value    : int to transform in char
 *  \return char*
 */
char* itoa(int int_value);


#endif