/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   BlackJack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 27/12/2022 23:25:29 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 29/11/2022 06:14:14 by Durandnico   ########     ###              */
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


//int
//next_frame(t_recup* rcp_recup)
//{
//    int i; //loop variable
//    static int int_previous_bet = 0;
//
//    /*if betting stade*/
//    //if(rcp_recup->state == 0){
//    //    if(rcp_recup->current_bet == int_previous_bet){
//    //        /*Update bet + total*/
//    //        printf("oui");
//    //    }
//    //}
//    
//    /*if in playing state, show buttons*/
//    if (rcp_recup->state == 1) {
//        /*show button HIT and STAY*/
//        mlx_put_image_to_window(rcp_recup->mlx, rcp_recup->win, rcp_recup->button[0].img, rcp_recup->button[0].coord.x, rcp_recup->button[0].coord.y);
//        mlx_put_image_to_window(rcp_recup->mlx, rcp_recup->win, rcp_recup->button[1].img, rcp_recup->button[1].coord.x, rcp_recup->button[1].coord.y);
//        
//        /*if card just been hit*/
//        if(rcp_recup->ingame[1].card_in_hand == 2){
//            /*show button double*/
//            mlx_put_image_to_window(rcp_recup->mlx, rcp_recup->win, rcp_recup->button[2].img, rcp_recup->button[2].coord.x, rcp_recup->button[2].coord.y);    
//            /*if splittable*/
//            if(rcp_recup->ingame[1].hand[0].value == rcp_recup->ingame[1].hand[1].value){
//                mlx_put_image_to_window(rcp_recup->mlx, rcp_recup->win, rcp_recup->button[3].img, rcp_recup->button[3].coord.x, rcp_recup->button[3].coord.y);
//            }
//        } 
//    }
//    
//    return 0;
//}


int
show_card(t_recup* rcp_recup, t_card* cd_card)
{

    char img_dir[33];
    char* tmp; 
    
    /*Get correct texture path*/
    strcpy(img_dir, "texture/cards/");
    if(cd_card->hide){
        strcat(img_dir, "hide.xpm");
    }
    else{
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
    }
    
    /*Load image*/
    cd_card->img.img = mlx_xpm_file_to_image(rcp_recup->mlx, img_dir, &cd_card->img.width, &cd_card->img.height);
    cd_card->img.addr = mlx_get_data_addr(cd_card->img.img, &cd_card->img.bits_per_pixel, &cd_card->img.line_length, &cd_card->img.endian);

    /*Show image*/
    mlx_put_image_to_window(rcp_recup->mlx, rcp_recup->win, cd_card->img.img, cd_card->img.coord.x, cd_card->img.coord.y);
    
    return 0;
}   


void
drawn_sprite(t_recup* recup, t_img img)
{
     
    int     i; //loop variable
    int     j; //loop variable
    char*   p_img; //pointeur to a pixel of the img
    char*   p_bg; //pointeur to a pixel of the background

    for(i = 0; i < img.height; i++){
        for(j = 0; j < img.width; j++){
            p_img = img.addr + (i * img.line_length + j * (img.bits_per_pixel / 8));
            
            if(*(int*)p_img != -16777216){
                p_bg = recup->bet_background.addr + ((i + img.coord.y) * recup->bet_background.line_length + (j + img.coord.x) * (recup->bet_background.bits_per_pixel / 8));
                
                *(unsigned int*) p_bg = *(unsigned int*) p_img;
            }
        }
    }
}