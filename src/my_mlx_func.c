/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   BlackJack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 27/12/2022 23:25:29 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 30/11/2022 04:48:36 by Durandnico   ########     ###              */
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


int
show_card(t_recup* rcp_recup, t_card* cd_card)
{

    char* img_dir = malloc(35);
    char* tmp; 
    
    /*Get correct texture path*/
    strcpy(img_dir, "texture/cards/");
    //if(cd_card->hide){
    //    strcat(img_dir, "hide.xpm");
    //}
    ////else{
        /*Get correct color folder*/   
        tmp = ccolor_to_string(*cd_card);
        /*Cas d'erreur*/
        if( tmp == NULL ){
            return 1;
        }
        img_dir = strcat(img_dir, tmp);
        tmp = NULL;

        /*Get correct card*/
        tmp = cname_to_string(*cd_card);
        /*Case d'erreur*/
        if( tmp == NULL){
            return 1;
        }
        img_dir = strcat(img_dir, tmp); 
    //}
    
    /*Load image*/
    cd_card->img.img = mlx_xpm_file_to_image(rcp_recup->mlx, img_dir, &cd_card->img.width, &cd_card->img.height);
    cd_card->img.addr = mlx_get_data_addr(cd_card->img.img, &cd_card->img.bits_per_pixel, &cd_card->img.line_length, &cd_card->img.endian);

    /*Show image*/
    if(cd_card->hide){
        mlx_put_image_to_window(rcp_recup->mlx, rcp_recup->win, cd_card->img.img, cd_card->img.coord.x + 150, cd_card->img.coord.y - 40 );
    }else{
        mlx_put_image_to_window(rcp_recup->mlx, rcp_recup->win, cd_card->img.img, cd_card->img.coord.x , cd_card->img.coord.y );
    }
    return 0;
}   


void
drawn_sprite(t_img* ptr_img_base, t_img img_to_add, int int_x, int int_y)
{
     
    int     i; //loop variable
    int     j; //loop variable
    char*   p_img; //pointeur to a pixel of the img
    char*   p_bg; //pointeur to a pixel of the background

    for(i = 0; i < img_to_add.height; i++){
        for(j = 0; j < img_to_add.width; j++){
            p_img = img_to_add.addr + (i * img_to_add.line_length + j * (img_to_add.bits_per_pixel / 8));
            
            if(*(int*)p_img != -16777216){
                p_bg = ptr_img_base->addr + ((i + int_y) * ptr_img_base->line_length + (j + int_x) * (ptr_img_base->bits_per_pixel / 8));
                
                *(unsigned int*) p_bg = *(unsigned int*) p_img;
            }
        }
    }
}


void show_everything(t_recup* ptr_rcp_recup)
{
    int i; //loop variable
    int j; //loop variable

    /*clear the window*/
    mlx_clear_window(ptr_rcp_recup->mlx, ptr_rcp_recup->win);
        
    /*put the correct background*/
    mlx_put_image_to_window(ptr_rcp_recup->mlx, ptr_rcp_recup->win, ptr_rcp_recup->background.img, 0, 0);
    
    for(i = 0; i < 2; i++){
        for(j = 0; j < ptr_rcp_recup->ingame[i].card_in_hand; j++){
            show_card(ptr_rcp_recup, &ptr_rcp_recup->ingame[i].hand[j]);
        }
        calc_score(ptr_rcp_recup, &ptr_rcp_recup->ingame[i]);
    }

    if(ptr_rcp_recup -> state == 1){
        /*show button HIT and STAY*/
        mlx_put_image_to_window(ptr_rcp_recup->mlx, ptr_rcp_recup->win, ptr_rcp_recup->button[1].img, ptr_rcp_recup->button[1].coord.x, ptr_rcp_recup->button[1].coord.y);
        mlx_put_image_to_window(ptr_rcp_recup->mlx, ptr_rcp_recup->win, ptr_rcp_recup->button[2].img, ptr_rcp_recup->button[2].coord.x, ptr_rcp_recup->button[2].coord.y);

        /*if card just been hit and have enough chips, show double button*/
        if(ptr_rcp_recup->ingame[1].card_in_hand == 2 && ptr_rcp_recup->ingame[1].token >= 2 * ptr_rcp_recup->current_bet){

            mlx_put_image_to_window(ptr_rcp_recup->mlx, ptr_rcp_recup->win, ptr_rcp_recup->button[0].img, ptr_rcp_recup->button[0].coord.x, ptr_rcp_recup->button[0].coord.y);    
            ptr_rcp_recup->x2 = 1;

            /*if splittable show split button*/
            if(ptr_rcp_recup->ingame[1].hand[0].value == ptr_rcp_recup->ingame[1].hand[1].value){
                mlx_put_image_to_window(ptr_rcp_recup->mlx, ptr_rcp_recup->win, ptr_rcp_recup->button[3].img, ptr_rcp_recup->button[3].coord.x, ptr_rcp_recup->button[3].coord.y);
                ptr_rcp_recup->split = 1;
            }
        }
    }

    /*re print wallet and bet*/
    show_bet_wallet(ptr_rcp_recup, ptr_rcp_recup->ingame[1]);
}

void show_betting(t_recup* ptr_rcp_recup) {
     
     /*clear the window*/
    mlx_clear_window(ptr_rcp_recup->mlx, ptr_rcp_recup->win);
        
    /*put the correct background*/
    mlx_put_image_to_window(ptr_rcp_recup->mlx, ptr_rcp_recup->win, ptr_rcp_recup->bet_background.img, 0, 0);
    
    /*show correct bet and wallet*/
    show_bet_wallet(ptr_rcp_recup, ptr_rcp_recup->ingame[1]);
}


void
show_score(t_recup* ptr_rcp_recup, t_player* ptr_pl_player)
{
    mlx_string_put(ptr_rcp_recup->mlx, ptr_rcp_recup->win, ptr_pl_player->score.coord.x + 90 , ptr_pl_player->score.coord.y + 45 , 0x00FF0000, itoa(ptr_pl_player->total_value));
}


void
show_bet_wallet(t_recup* ptr_rcp_recup, t_player pl_player)
{
    mlx_string_put(ptr_rcp_recup->mlx, ptr_rcp_recup->win,  140 , 38 , 0x00000000, itoa(ptr_rcp_recup->current_bet));
    mlx_string_put(ptr_rcp_recup->mlx, ptr_rcp_recup->win, 140 , 80 , 0x00000000, itoa(pl_player.token));     
}