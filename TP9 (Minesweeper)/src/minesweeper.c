/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 06/01/2023 18:39:25 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file minesweeper.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 18:39:25
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/minesweeper.h"


int
exit_prog(t_recup* ptr_rcp_recup)
{
    mlx_destroy_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->img_background.ptr_void_img);

    /*free button*/
    for(int i = 0; i < ptr_rcp_recup->int_window_height;i++)
        free(ptr_rcp_recup->pptr_btn_board[i]);
    free(ptr_rcp_recup->pptr_btn_board);

    /*free images*/
    for(int i = 0; i < 11; i++)
        mlx_destroy_image(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_img_sprites[i].ptr_void_img);
    free(ptr_rcp_recup->ptr_img_sprites);

    mlx_destroy_window(ptr_rcp_recup->ptr_void_mlx, ptr_rcp_recup->ptr_void_win);
    mlx_destroy_display(ptr_rcp_recup->ptr_void_mlx);

    exit(0);
    return (0);
}


void
parsing(t_recup* ptr_rcp_recup, char** argv)
{
    ptr_rcp_recup->int_window_width     =   atoi(argv[1]);
    ptr_rcp_recup->int_window_height    =   atoi(argv[2]);
    ptr_rcp_recup->int_bombe            =   atoi(argv[3]);
    
    if(ptr_rcp_recup->int_window_width == 0 || ptr_rcp_recup->int_window_width >= 1280 / LENGHT_CASE){
        fprintf(stderr, "Wrong width ! 0 < Width < %d\n", 1280/LENGHT_CASE);
        exit(0);
    }

    if(ptr_rcp_recup->int_window_height == 0 || ptr_rcp_recup->int_window_height >= 800 / LENGHT_CASE) {
        fprintf(stderr, "Wrong height ! 0 < Height < %d\n", 800/LENGHT_CASE);
        exit(0);
    }

    if(ptr_rcp_recup->int_bombe == 0 || ptr_rcp_recup->int_bombe > ptr_rcp_recup->int_window_width * ptr_rcp_recup->int_window_height - 9){
        fprintf(stderr, "Wrong bombe ! 0 < Bombe <= Width * Height - 9 (%d)\n", ptr_rcp_recup->int_window_width * ptr_rcp_recup->int_window_height - 9);
        exit(0);
    }

}

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 06 January 2023 - 18:40:41
 *  \brief Main program
 *  \param argc : number of parameters
 *  \param argv : Values of the parameters 
 *  \return 0 if no error, -1 otherwise
 */
int main (int argc, char** argv) {
    
    t_recup rcp_recup;

    if(argc != 4)
        fprintf(stderr, "Wrong number of argument\n");

    else{
        parsing(&rcp_recup, argv);
    
        initialization(&rcp_recup);

        show_everything(&rcp_recup);

        mlx_loop(rcp_recup.ptr_void_mlx);
    }

    return 0;
}
