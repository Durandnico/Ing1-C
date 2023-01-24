/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Minesweeper                                        :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 07/01/2023 00:06:37 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file key_draw.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 00:06:37
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/minesweeper.h"


int
mouse_press(int int_keycode, int int_x, int int_y, t_recup* ptr_rcp_recup)
{
    int int_line;   //variable to stock actual line
    int int_row;    //variable to stock actual row

    /*if click is outsite the board : return*/
    if(int_x <= LENGHT_CASE / 2 || int_x > ptr_rcp_recup->img_background.int_width - (LENGHT_CASE/2) || int_y < LENGHT_CASE/2 || int_y > ptr_rcp_recup->img_background.int_height - (LENGHT_CASE/2))
        return (0);

    /*calcul on which case player clicked*/
    int_line    = (int_y - 10) / LENGHT_CASE;
    int_row     = (int_x - 10) / LENGHT_CASE;
    
    /*if is hide, reveal*/
    if(ptr_rcp_recup->pptr_btn_board[int_line][int_row].int_state == 0)
        ptr_rcp_recup->pptr_btn_board[int_line][int_row].ptr_intf_func(int_keycode, int_row, int_line, ptr_rcp_recup);

    return (0);
}