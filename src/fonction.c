/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 07/01/2023 01:20:28 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file fonction.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Sat 07 January 2023 - 01:20:28
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/minesweeper.h"


void
show_everything(t_recup* ptr_rcp_recup)
{
    int i;  //loop variable
    int j;  //loop variable

    /*clear*/
    mlx_clear_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_void_win);

    /*put background*/
    mlx_put_image_to_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_void_win, ptr_rcp_recup->img_background.ptr_void_img, 0, 0);

    /*put every button*/     
    for(i = 0; i < ptr_rcp_recup->int_window_height; i++)
        for(j = 0; j < ptr_rcp_recup->int_window_width; j++)
            mlx_put_image_to_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_void_win, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite.ptr_void_img, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite.pt_coord.int_x, ptr_rcp_recup->pptr_btn_board[i][j].img_sprite.pt_coord.int_y);
}


void change_button_image(t_button* ptr_btn_button, t_img img_new) {
    t_point     pt_tmp; //tmp variable

    /*store current pos in tmp*/
    pt_tmp.int_x = ptr_btn_button->img_sprite.pt_coord.int_x;
    pt_tmp.int_y = ptr_btn_button->img_sprite.pt_coord.int_y;

    /*change image and reset coord*/
    ptr_btn_button->img_sprite = img_new;
    ptr_btn_button->img_sprite.pt_coord.int_x = pt_tmp.int_x;
    ptr_btn_button->img_sprite.pt_coord.int_y = pt_tmp.int_y;
}


t_img get_correct_xpm(t_recup* ptr_rcp_recup, t_button btn_tochange) {
    t_img img_res;  //image to return
    
    if(btn_tochange.int_isBombe)
        return (ptr_rcp_recup->ptr_img_sprites[10]);

    if(btn_tochange.int_flaged)
        return (ptr_rcp_recup->ptr_img_sprites[9]);

    return (ptr_rcp_recup->ptr_img_sprites[1 + btn_tochange.int_neighbor]);
}