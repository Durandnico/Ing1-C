/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 26/12/2022 23:36:41 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 29/11/2022 04:30:14 by Durandnico   ########     ###              */
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


void
init(t_recup *recup)
{   
    int i; //loop variable

    /*create the main window*/
    recup->mlx = mlx_init();
    recup->win =mlx_new_window(recup->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Blackjack !");

    /*init state to false*/
    recup->state = 0;
    recup->special = 0;
    recup->current_bet = 0;

    /*load background image*/
    recup->background.img = mlx_xpm_file_to_image(recup->mlx, "texture/BJ_board.xpm", &recup->background.width, &recup->background.height);
    recup->background.addr = mlx_get_data_addr(recup->background.img, &recup->background.bits_per_pixel, &recup->background.line_length, &recup->background.endian);
   
    /*load bet_backgroune images */
    recup->bet_background.img = mlx_xpm_file_to_image(recup->mlx, "texture/BJ_board.xpm", &recup->bet_background.width, &recup->bet_background.height);
    recup->bet_background.addr = mlx_get_data_addr(recup->bet_background.img, &recup->bet_background.bits_per_pixel, &recup->bet_background.line_length, &recup->bet_background.endian);
    
    /*load all button images*/
    //init_button(recup);

    /*load all bets images*/
    init_bets_background(recup);

    /*set all key to not press*/
    init_key(recup);

    /*create all hook func*/
    init_hook(recup);

    /*malloc dealer and player*/
    recup->ingame = malloc( 2 * sizeof(t_player));

    /*init dealer and player*/
    for(i = 0; i < 2; i++){
        recup->ingame[i].card_in_hand = 0;
        recup->ingame[i].hand = NULL;
        recup->ingame[i].token = -1;
        recup->ingame[i].total_value = 0;
        recup->ingame[i].base_x = 575;
        recup->ingame[i].dx = 40;
        recup->ingame[i].dy = 40;
    }

    /*set player tokens to TOKEN_INIT*/
    recup->ingame[1].token = TOKEN_INIT;

    /*set base_pos*/
    recup->ingame[0].base_y = 75;
    recup->ingame[1].base_y = 475;
    recup->ingame[1].dy *= -1;
    recup->ingame[0].dx *= -1;
    
    /*betting state*/
    mlx_put_image_to_window(recup->mlx, recup->win, recup->bet_background.img, 0, 0);
}


void
inti_button(t_recup *recup)
{
    int i; //loop variable
    
    //recup->button = malloc(4 * sizeof(t_img));

    for( i = 0; i < 4 ; i++){
        //recup->button[0] = mlx_xpm_file_to_image(recup->mlx, "")
    }   
}


void init_bets_background(t_recup* prcp_recup) {
    int i; //loop variable
    int int_x; //to affect x value
    t_img bet_img[7];

    /*first chip start at 101*/
    int_x = 101;
    
    
    /*It's horrible but have to change each file_name so...*/
    bet_img[0].img = mlx_xpm_file_to_image(prcp_recup->mlx, "texture/chip1.xpm", &bet_img[0].width, &bet_img[0].height);
    bet_img[1].img = mlx_xpm_file_to_image(prcp_recup->mlx, "texture/chip2.xpm", &bet_img[1].width, &bet_img[1].height);
    bet_img[2].img = mlx_xpm_file_to_image(prcp_recup->mlx, "texture/chip5.xpm", &bet_img[2].width, &bet_img[2].height);
    bet_img[3].img = mlx_xpm_file_to_image(prcp_recup->mlx, "texture/chip10.xpm", &bet_img[3].width, &bet_img[3].height);
    bet_img[4].img = mlx_xpm_file_to_image(prcp_recup->mlx, "texture/chip25.xpm", &bet_img[4].width, &bet_img[4].height);
    bet_img[5].img = mlx_xpm_file_to_image(prcp_recup->mlx, "texture/chip100.xpm", &bet_img[5].width, &bet_img[5].height);
    bet_img[6].img = mlx_xpm_file_to_image(prcp_recup->mlx, "texture/chip500.xpm", &bet_img[6].width, &bet_img[6].height);

    /*set all other value*/
    for( i = 0; i < 7; i++){
        /*set addr*/    
        bet_img[i].addr = mlx_get_data_addr(bet_img[i].img, &bet_img[i].bits_per_pixel, &bet_img[i].line_length, &bet_img[i].endian);

        /*set position*/
        bet_img[i].coord.x = int_x;
        bet_img[i].coord.y = 200;

        /*increase to next pos*/
        int_x += 154;

        /*print it on the bet_background*/
        drawn_sprite(prcp_recup, bet_img[i]);
    }
}


void
init_key(t_recup* rcp_recup) 
{
    /*Set all data key to 0 (false)*/
    rcp_recup->datakey.enter = 0;    
}


void
init_hook(t_recup* rcp_recup)
{
    /*key press*/
    mlx_hook(rcp_recup->win, 2, 1L<<0,  key_press, rcp_recup);    

    /*key release*/
    mlx_hook(rcp_recup->win, 3, 1L<<1,  key_release, rcp_recup);    

    /*red cross to exit*/
    mlx_hook(rcp_recup->win, 17, 0L, exit_prog, 0);

    /*mouse click*/
    mlx_hook(rcp_recup->win, 4, 1L<<2, mouse_press, rcp_recup);

    /*frame update*/
    //mlx_loop_hook(rcp_recup->mlx, next_frame, rcp_recup);
}