/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   BlackJack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 27/12/2022 23:25:29 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file my_mlx_func.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:25:29
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/blackjack.h"

/*!
 *  \fn int next_frame(t_recup* recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:27:25
 *  \brief 
 *  \param 
 *  \return 
 */
int next_frame(t_recup* recup) {
     

    

    return 0;
}


/*!
 *  \fn int show_card(t_recup* recup, t_card card)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:44:33
 *  \brief show in the windows a card
 *  \param recup    : pointeur to recup of all data for the window
 *  \param card     : pointeur to a card
 *  \return load and show the card in the screen (0 => fail, 1 => sucess)
 */
int show_card(t_recup* rcp_recup, t_card* cd_card) {

    char img_dir[33];
    char* tmp; 
    
    /*Get correct texture path*/
    strcpy(img_dir, "texture/cards/");

    /*Get correct color folder*/   
    tmp = ccolor_to_string(*cd_card);
    /*Cas d'erreur*/
    if( tmp == NULL ){
        return 1;
    }
    strcat(img_dir, tmp);
    tmp = NULL;

    /*Get correct card*/
    tmp = cname_to_string(*cd_card);
    /*Case d'erreur*/
    if( tmp == NULL){
        return 1;
    }
    strcat(img_dir, tmp);


    /*Load image*/
    cd_card->img.img = mlx_xpm_file_to_image(rcp_recup->mlx, img_dir, &cd_card->img.width, &cd_card->img.height);
    cd_card->img.addr = mlx_get_data_addr(&cd_card->img.img, &cd_card->img.bits_per_pixel, &cd_card->img.line_length, &cd_card->img.endian);

    /*Show image*/
    mlx_put_image_to_window(rcp_recup->mlx, rcp_recup->win, cd_card->img.img, cd_card->img.coord.x, cd_card->img.coord.y);
    return 0;
}   