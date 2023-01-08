/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 06/01/2023 18:37:39 by Durandnico   #+#    #+#    #+#             */
/*   Updated: None                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */


/*! 
 *  \file Minesweeper.h
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 18:37:39
 *
 *  \brief Headers of Minesweeper.c
 *
 *
 */

#ifndef __MINESWEEPER_H
#define __MINESWEEPER_H

// librairies
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../minilibx-linux/mlx.h"

#define LENGHT_CASE 20

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
    int int_x;  
    int int_y;
}                   t_point;


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
    void*       ptr_void_img;
    char*       ptr_char_addr;
	int		    int_bits_per_pixel;
	int		    int_line_length;
	int		    int_endian;

    t_point     pt_coord;
    int         int_width;
    int         int_height;
}                   t_img;

/*!
 *  \struct t_button
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 21:45:44
 *  \brief 
 *  \param 
 */

typedef struct      t_button
{
    t_img           img_sprite;
    int             (*ptr_intf_func)(int, int, int, void*);
    int             int_state;
    int             int_isBombe;
    int             int_flaged;
    int             int_neighbor;
}                   t_button;
/*!
 *  \struct t_recup
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 21:10:17
 *  \brief All data for the window
 *  \param mlx              : pointeur to the mlx
 *  \param win              : pointeur to the window of mlx
 *  \param background       : image of the board
 */
typedef struct      s_recup
{
    void*           ptr_void_mlx;
	void*           ptr_void_win;

    t_img           img_background;
    t_img*          ptr_img_sprites;

    int             int_window_width;
    int             int_window_height;
    int             int_bombe;

    t_button**      pptr_btn_board;
}                   t_recup;

/*!
 *  \fn int exit_prog(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 00:09:08
 *  \brief 
 *  \param 
 *  \return 
 */
int exit_prog(void*, void*);

/*!
 *  \proc void parsing(t_recup* ptr_rcp_recup, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 18:55:59
 *  \brief 
 *  \param 
 */
void parsing(t_recup* ptr_rcp_recup, char** argv);

/*!
 *  \proc void initialization(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 21:23:59
 *  \brief 
 *  \param 
 */
void initialization(t_recup* ptr_rcp_recup);

/*!
 *  \proc void init_background(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 23:01:19
 *  \brief 
 *  \param 
 */
void init_background(t_recup* ptr_rcp_recup);

/*!
 *  \proc void init_sprites(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 23:37:50
 *  \brief 
 *  \param 
 */
void init_sprites(t_recup* ptr_rcp_recup);

/*!
 *  \proc void init_hook(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 00:02:28
 *  \brief 
 *  \param 
 */
void init_hook(t_recup* ptr_rcp_recup);

/*!
 *  \proc void init_board(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 01:27:18
 *  \brief 
 *  \param 
 */
void init_board(t_recup* ptr_rcp_recup);

/*!
 *  \fn int mouse_press(int int_keycode, int int_x, int int_y, t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 00:06:50
 *  \brief 
 *  \param 
 *  \return 
 */
int mouse_press(int int_keycode, int int_x, int int_y, t_recup* ptr_rcp_recup);

/*!
 *  \proc void show_everything(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 01:20:43
 *  \brief 
 *  \param 
 */
void show_everything(t_recup* ptr_rcp_recup);

/*!
 *  \proc void change_button_image(t_button* ptr_btn_button, t_img img_new)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 20:03:45
 *  \brief 
 *  \param 
 */
void change_button_image(t_button* ptr_btn_button, t_img img_new);

/*!
 *  \fn t_img get_correct_xpm(int int_target)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sun 08 January 2023 - 00:02:47
 *  \brief 
 *  \param 
 *  \return 
 */
t_img get_correct_xpm(t_recup*, t_button);

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
 *  \proc void generate_bombe(t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 02:22:18
 *  \brief 
 *  \param 
 */
void generate_bombe(t_recup* ptr_rcp_recup, int int_x, int int_y);

/*!
 *  \fn int case_clicked(int keycode, int int_x, int int_y, t_recup* ptr_rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 02:36:15
 *  \brief 
 *  \param 
 *  \return 
 */
int case_clicked(int keycode, int int_x, int int_y, void* ptr_rcp_recup);


/*!
 *  \fn int reveal(t_recup* ptr_rcp_recup, int int_x, int int_y)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 02:51:44
 *  \brief 
 *  \param 
 *  \return 
 */
int reveal(t_recup* ptr_rcp_recup, int int_x, int int_y);

/*!
 *  \fn t_button create_button(t_img img_sprite, int (*ptr_intf_func)(void*), int int_x, int int_y)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 21:45:27
 *  \brief 
 *  \param 
 *  \return 
 */
t_button create_button(t_img img_sprite, int (*ptr_intf_func)(int, int, int, void*), int int_x, int int_y);

/*!
 *  \fn t_img my_xpm_file_trans(void*  ptr_void_mlx, char* str_filename, int* ptr_int_width, int* ptr_int_height)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 22:34:08
 *  \brief 
 *  \param 
 *  \return 
 */
t_img my_xpm_file_trans(void*  ptr_void_mlx, char* str_filename, int* ptr_int_width, int* ptr_int_height);

/*!
 *  \fn void my_mlx_pixel_put(t_img* ptr_img_base, int int_x, int int_y, int int_color)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 23:11:32
 *  \brief 
 *  \param 
 *  \return 
 */
void my_mlx_pixel_put(t_img* ptr_img_base, int int_x, int int_y, int int_color);


#endif