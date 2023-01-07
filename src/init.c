/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 06/01/2023 21:23:54 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file init.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 21:23:54
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/minesweeper.h"


void initialization(t_recup* ptr_rcp_recup)
{
    /*Create the main window*/
    ptr_rcp_recup->ptr_void_mlx = mlx_init();
    ptr_rcp_recup->ptr_void_win = mlx_new_window(ptr_rcp_recup->ptr_void_mlx, (ptr_rcp_recup->int_window_width + 1) * LENGHT_CASE, (ptr_rcp_recup->int_window_height + 1) * LENGHT_CASE, "Minesweeper");

    /*create background*/
    init_background(ptr_rcp_recup);

    /*load image*/
    init_sprites(ptr_rcp_recup);

    /*create and init board*/
    init_board(ptr_rcp_recup);

    /*create all hook func*/
    init_hook(ptr_rcp_recup);
}


void 
init_background(t_recup* ptr_rcp_recup)
{
    int i; //loop variable
    int j;

    /*affect value, just in case we need to use it later*/
    ptr_rcp_recup->img_background.int_width     = (ptr_rcp_recup->int_window_width + 1)* LENGHT_CASE;
    ptr_rcp_recup->img_background.int_height    = (ptr_rcp_recup->int_window_height + 1) * LENGHT_CASE;

    /*create image and set addr*/
    ptr_rcp_recup->img_background.ptr_void_img  = mlx_new_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->img_background.int_width, ptr_rcp_recup->img_background.int_height);
    ptr_rcp_recup->img_background.ptr_char_addr = mlx_get_data_addr(ptr_rcp_recup->img_background.ptr_void_img, &ptr_rcp_recup->img_background.int_bits_per_pixel, &ptr_rcp_recup->img_background.int_line_length, &ptr_rcp_recup->img_background.int_endian);

    /*draw top and bottom border*/
    for(i = 0; i < ptr_rcp_recup->img_background.int_width ; i++){
        for(j = 0; j < LENGHT_CASE / 8; j++){
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, j, 0x007f7f7f);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, ptr_rcp_recup->img_background.int_height - 1 - j, 0x007f7f7f);
        }

        for(j = LENGHT_CASE / 8; j < LENGHT_CASE/3; j++){
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, j, 0x00ffffff);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, ptr_rcp_recup->img_background.int_height - 1 - j, 0x00ffffff);
        }

        for(j = LENGHT_CASE/3; j < LENGHT_CASE/2; j++){
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, j, 0x00bfbfbf);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, ptr_rcp_recup->img_background.int_height - 1 - j, 0x00bfbfbf);
        }
    }

    /*draw left and right border*/
    for(i = 0; i < ptr_rcp_recup->img_background.int_height; i++){
        for(j = 0; j < LENGHT_CASE / 8; j++){
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, j, i,0x007f7f7f);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, ptr_rcp_recup->img_background.int_width - 1 - j, i,0x007f7f7f);
        }

        for(j = LENGHT_CASE / 8; j < LENGHT_CASE/3; j++){
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, j, i,0x00ffffff);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, ptr_rcp_recup->img_background.int_width - 1 - j, i, 0x00ffffff);
        }

        for(j = LENGHT_CASE/3; j < LENGHT_CASE/2; j++){
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, j, i,  0x00bfbfbf);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, ptr_rcp_recup->img_background.int_width - 1 - j, i, 0x00bfbfbf);
        }
    }

    for(i = 2; i < LENGHT_CASE/2 ; i++){
        for(j = 0; j < LENGHT_CASE / 8; j++){
            /*letf corners*/
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, j, 0x007f7f7f);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, ptr_rcp_recup->img_background.int_height - 1 - j, 0x007f7f7f);
        
            /*right corners*/
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, ptr_rcp_recup->img_background.int_width - 1 - i, j,0x007f7f7f);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, ptr_rcp_recup->img_background.int_width - 1 - i, ptr_rcp_recup->img_background.int_height - 1 - j,0x007f7f7f);
        }

        for(j = LENGHT_CASE / 8; j < LENGHT_CASE/3; j++){
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, j, 0x00ffffff);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, i, ptr_rcp_recup->img_background.int_height - 1 - j, 0x00ffffff);
        
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, ptr_rcp_recup->img_background.int_width - 1 - i, j,0x00ffffff);
            my_mlx_pixel_put(&ptr_rcp_recup->img_background, ptr_rcp_recup->img_background.int_width - 1 - i, ptr_rcp_recup->img_background.int_height - 1 - j,0x00ffffff);
        }
    }

}


void
init_sprites(t_recup* ptr_rcp_recup)
{
    int i; //loop variable

    /*allocate memory size*/
    ptr_rcp_recup->ptr_img_sprites = malloc(2 * sizeof(t_img));

    /*load image*/
    ptr_rcp_recup->ptr_img_sprites[0].ptr_void_img = mlx_xpm_file_to_image(ptr_rcp_recup->ptr_void_mlx, "texture/hide.xpm", &ptr_rcp_recup->ptr_img_sprites[0].int_width, &ptr_rcp_recup->ptr_img_sprites[0].int_height);
    ptr_rcp_recup->ptr_img_sprites[1].ptr_void_img = mlx_xpm_file_to_image(ptr_rcp_recup->ptr_void_mlx, "texture/empty.xpm", &ptr_rcp_recup->ptr_img_sprites[1].int_width, &ptr_rcp_recup->ptr_img_sprites[1].int_height);

    /*get data*/
    for(i = 0; i < 2; i++){ 
        ptr_rcp_recup->ptr_img_sprites[i].ptr_char_addr = mlx_get_data_addr( ptr_rcp_recup->ptr_img_sprites[i].ptr_void_img, &ptr_rcp_recup->ptr_img_sprites[i].int_bits_per_pixel, &ptr_rcp_recup->ptr_img_sprites[i].int_line_length, &ptr_rcp_recup->ptr_img_sprites[i].int_endian);
    }
}


void
init_hook(t_recup* ptr_rcp_recup)
{
    /*red cross to exit*/
    mlx_hook(ptr_rcp_recup->ptr_void_win, 17, 0L, exit_prog, 0);

    /*mouse click*/
    mlx_hook(ptr_rcp_recup->ptr_void_win, 4, 1L<<2, mouse_press, ptr_rcp_recup);
}


void
init_board(t_recup* ptr_rcp_recup)
{
    int i;  //loop variable
    int j;  //loop variable

    /*allocate lines*/
    ptr_rcp_recup->pptr_btn_board = malloc(ptr_rcp_recup->int_window_height * sizeof(t_button*));
    for(i = 0; i < ptr_rcp_recup->int_window_height; i++){
        /*allocate row*/
        ptr_rcp_recup->pptr_btn_board[i] = malloc(ptr_rcp_recup->int_window_width * sizeof(t_button));
        
        /*affect all button to an hide image + set their pos*/
        for(j = 0; j < ptr_rcp_recup->int_window_width; j++){
            ptr_rcp_recup->pptr_btn_board[i][j] = create_button( ptr_rcp_recup->ptr_img_sprites[0], case_clicked, j*LENGHT_CASE + LENGHT_CASE/2, i*LENGHT_CASE + LENGHT_CASE/2);
            ptr_rcp_recup->pptr_btn_board[i][j].int_state = 0;
            ptr_rcp_recup->pptr_btn_board[i][j].int_isBombe = 0;
            ptr_rcp_recup->pptr_btn_board[i][j].int_flaged = 0;
        }
    }
}