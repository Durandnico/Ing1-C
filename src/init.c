/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 26/12/2022 23:36:41 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 28/11/2022 16:30:14 by Durandnico   ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file init.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 23:36:41
 *
 *  \brief bunch of init function
 *
 *
 */

//librairies
#include "../inc/blackjack.h"

/*!
 *  \proc void init(t_recup recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 23:38:32
 *  \brief 
 *  \param recup init all
 */
void
init(t_recup *recup)
{   
    /*create the main window*/
    recup->mlx = mlx_init();
    recup->win =mlx_new_window(recup->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Blackjack !");

    /*init state to false*/
    recup->state = 0;
    recup->special = 0;

    /*load and show background image*/
    recup->background.img = mlx_xpm_file_to_image(recup->mlx, "texture/BJ_board.xpm", &recup->background.width, &recup->background.height);
    recup->background.addr = mlx_get_data_addr(&recup->background, &recup->background.bits_per_pixel, &recup->background.line_length, &recup->background.endian);
    mlx_put_image_to_window(recup->mlx, recup->win, recup->background.img, 0, 0);
    
    /*load all button images*/
    //recup->button = init_button(recup);

    /*load all bets images*/
    //recup->bet_img = init_bets();

    /*set all key to not press*/
    init_key(recup);

    recup->ingame = malloc( 2 * sizeof(t_player));
}


void
inti_button(t_recup *recup)
{
    int i; //loop variable
    
    recup->button = malloc(4 * sizeof(t_img));

    for( i = 0; i < 4 ; i++){
        //recup->button[0] = mlx_xpm_file_to_image(recup->mlx, "")
    }   
}


void
init_key(t_recup* rcp_recup) 
{
    /*Set all data key to 0 (false)*/
    rcp_recup->datakey.alt = 0;
    rcp_recup->datakey.f4 = 0;    
}


void
init_hook(t_recup* rcp_recup)
{
    /*key press*/
    mlx_hook(rcp_recup->win, 2, 1L<<0,  key_press(), rcp_recup);    

    /*key release*/
    mlx_hook(rcp_recup->win, 3, 1L<<1,  key_release(), rcp_recup);    

    /*red cross to exit*/
    //mlx_hook(rcp_recup->win, 17, 0L,  exit_prog(), rcp_recup);

    /*mouse click*/
    //mlx_hook(rcp_recup->win, 4, 1L<<2, mouse_press(), rcp_recup);
    
}