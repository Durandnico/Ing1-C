/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 26/12/2022 23:36:41 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
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
    recup->mlx = mlx_init();
    recup->win =mlx_new_window(recup->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Blackjack !");

    recup->state = 0;
    recup->special = 0;

    //recup->button = init_button(recup);
    //recup->bet_img = init_bets();
}

/*!
 *  \proc void inti_button(t_recup )
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 23:48:40
 *  \brief 
 *  \param 
 */
void inti_button(t_recup *recup) {
    int i; //loop variable
    
    recup->button = malloc(4 * sizeof(t_img));

    for( i = 0; i < 4 ; i++){
        //recup->button[0] = mlx_xpm_file_to_image(recup->mlx, "")
    }   
}