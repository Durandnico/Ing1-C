/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 26/12/2022 23:36:41 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 30/12/2022 01:50:57 by Durandnico   ########     ###              */
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
init(t_recup *ptr_rcp_recup)
{   
    int i; //loop variable

    /*create the main window*/
    ptr_rcp_recup->mlx = mlx_init();
    ptr_rcp_recup->win =mlx_new_window(ptr_rcp_recup->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Blackjack !");

    /*init state to false*/
    ptr_rcp_recup->state = 0;
    ptr_rcp_recup->x2 = 0;
    ptr_rcp_recup->split = 0;
    ptr_rcp_recup->current_bet = 0;

    /*load background image*/
    ptr_rcp_recup->background.img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/BJ_board.xpm", &ptr_rcp_recup->background.width, &ptr_rcp_recup->background.height);
    ptr_rcp_recup->background.addr = mlx_get_data_addr(ptr_rcp_recup->background.img, &ptr_rcp_recup->background.bits_per_pixel, &ptr_rcp_recup->background.line_length, &ptr_rcp_recup->background.endian);
   
    /*load bet_backgroune images */
    ptr_rcp_recup->bet_background.img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/BJ_board.xpm", &ptr_rcp_recup->bet_background.width, &ptr_rcp_recup->bet_background.height);
    ptr_rcp_recup->bet_background.addr = mlx_get_data_addr(ptr_rcp_recup->bet_background.img, &ptr_rcp_recup->bet_background.bits_per_pixel, &ptr_rcp_recup->bet_background.line_length, &ptr_rcp_recup->bet_background.endian);
    
    /*draw money's rectangle*/
    init_bet_money_score(ptr_rcp_recup);

    /*load all button images*/
    init_button(ptr_rcp_recup);

    /*load all bets images*/
    init_bets_background(ptr_rcp_recup);

    /*create all hook func*/
    init_hook(ptr_rcp_recup);

    /*malloc dealer and player*/
    ptr_rcp_recup->ingame = malloc( 2 * sizeof(t_player));

    /*init dealer and player*/
    for(i = 0; i < 2; i++){
        ptr_rcp_recup->ingame[i].card_in_hand = 0;
        ptr_rcp_recup->ingame[i].hand = NULL;
        ptr_rcp_recup->ingame[i].token = -1;
        ptr_rcp_recup->ingame[i].total_value = 0;
        ptr_rcp_recup->ingame[i].base_x = 575;
        ptr_rcp_recup->ingame[i].dx = 40;
        ptr_rcp_recup->ingame[i].dy = 40;
        ptr_rcp_recup->ingame[i].score.coord.x = 555;
    }
    
    /*set player tokens to TOKEN_INIT*/
    ptr_rcp_recup->ingame[1].token = TOKEN_INIT;

    /*set base_pos*/
    ptr_rcp_recup->ingame[0].base_y = 75;
    ptr_rcp_recup->ingame[1].base_y = 475;
    ptr_rcp_recup->ingame[1].dy *= -1;
    ptr_rcp_recup->ingame[0].dx *= -1;
    ptr_rcp_recup->ingame[0].score.coord.x -= 30;
    ptr_rcp_recup->ingame[0].score.coord.y = -8;
    ptr_rcp_recup->ingame[1].score.coord.y = 475 + 145 + 5;
    
    /*betting state*/
    mlx_put_image_to_window(ptr_rcp_recup->mlx, ptr_rcp_recup->win, ptr_rcp_recup->bet_background.img, 0, 0);

    /*show wallet and bet*/
    show_bet_wallet(ptr_rcp_recup, ptr_rcp_recup->ingame[1]);
}


void
init_button(t_recup* ptr_rcp_recup)
{
    int i; //loop variable
    int int_x; //to affect x value
    int int_y; //to affect y value
    int int_dy; //gep between to image
    
    /*init variable*/
    int_y = (WINDOW_HEIGHT / 9);
    int_dy = 2 * int_y;
    int_x = WINDOW_WIDTH - 125 - 169;
    ptr_rcp_recup->button = malloc(6 * sizeof(t_img));
    
    /*load all images*/
    ptr_rcp_recup->button[0].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/X2.xpm", &ptr_rcp_recup->button[0].width, &ptr_rcp_recup->button[0].height);
    ptr_rcp_recup->button[1].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/HIT.xpm", &ptr_rcp_recup->button[1].width, &ptr_rcp_recup->button[1].height);
    ptr_rcp_recup->button[2].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/STAY.xpm", &ptr_rcp_recup->button[2].width, &ptr_rcp_recup->button[2].height);
    ptr_rcp_recup->button[3].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/SPLIT.xpm", &ptr_rcp_recup->button[3].width, &ptr_rcp_recup->button[3].height);
    ptr_rcp_recup->button[4].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/VALIDER.xpm", &ptr_rcp_recup->button[4].width, &ptr_rcp_recup->button[4].height);
    ptr_rcp_recup->button[5].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/RESTART.xpm", &ptr_rcp_recup->button[5].width, &ptr_rcp_recup->button[5].height);

    for( i = 0; i < 5; i++){
        /*get data.*/
        ptr_rcp_recup->button[i].addr = mlx_get_data_addr(ptr_rcp_recup->button[i].img, &ptr_rcp_recup->button[i].bits_per_pixel, &ptr_rcp_recup->button[i].line_length, &ptr_rcp_recup->button[i].endian);

        /*set coord*/
        ptr_rcp_recup->button[i].coord.x = int_x;
        ptr_rcp_recup->button[i].coord.y = int_y;

        int_y += int_dy;
    }

    ptr_rcp_recup->button[4].coord.x = 550;
    ptr_rcp_recup->button[4].coord.y = 525;
    ptr_rcp_recup->button[5].coord.x = int_x;
    ptr_rcp_recup->button[5].coord.y = 325;
}


void init_bets_background(t_recup* ptr_rcp_recup) {
    int i; //loop variable
    int int_x; //to affect x value
    t_img bet_img[7];

    /*first chip start at 101*/
    int_x = 101;
    
    
    /*It's horrible but have to change each file_name so...*/
    bet_img[0].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/chip1.xpm", &bet_img[0].width, &bet_img[0].height);
    bet_img[1].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/chip2.xpm", &bet_img[1].width, &bet_img[1].height);
    bet_img[2].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/chip5.xpm", &bet_img[2].width, &bet_img[2].height);
    bet_img[3].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/chip10.xpm", &bet_img[3].width, &bet_img[3].height);
    bet_img[4].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/chip25.xpm", &bet_img[4].width, &bet_img[4].height);
    bet_img[5].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/chip100.xpm", &bet_img[5].width, &bet_img[5].height);
    bet_img[6].img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/chip500.xpm", &bet_img[6].width, &bet_img[6].height);

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
        drawn_sprite(&ptr_rcp_recup->bet_background, bet_img[i], bet_img[i].coord.x, bet_img[i].coord.y);
    }
}


void
init_hook(t_recup* ptr_rcp_recup)
{
    /*key press*/
    //mlx_hook(ptr_rcp_recup->win, 2, 1L<<0,  key_press, ptr_rcp_recup);    

    /*key release*/
    //mlx_hook(ptr_rcp_recup->win, 3, 1L<<1,  key_release, ptr_rcp_recup);    

    /*red cross to exit*/
    mlx_hook(ptr_rcp_recup->win, 17, 0L, exit_prog, 0);

    /*mouse click*/
    mlx_hook(ptr_rcp_recup->win, 4, 1L<<2, mouse_press, ptr_rcp_recup);
}


void init_bet_money_score(t_recup* ptr_rcp_recup) {
     
    t_img   wallet; //image for the bet / wallet
    t_img   score;  //image for the score  

    /*init wallet image */
    wallet.img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/bet_total.xpm", &wallet.width, &wallet.height);
    wallet.addr = mlx_get_data_addr(wallet.img, &wallet.bits_per_pixel, &wallet.line_length,&wallet.endian);
    
    /*init score image*/
    score.img = mlx_xpm_file_to_image(ptr_rcp_recup->mlx, "texture/score.xpm", &score.width, &score.height);
    score.addr = mlx_get_data_addr(score.img, &score.bits_per_pixel, &score.line_length, &score.endian);

    /*draw wallet image on backgrounds*/
    drawn_sprite(&ptr_rcp_recup->background, wallet, 0, 0);
    drawn_sprite(&ptr_rcp_recup->bet_background, wallet, 0, 0);

    /*draw score on playing background*/
    drawn_sprite(&ptr_rcp_recup->background, score, 525, -8);
    drawn_sprite(&ptr_rcp_recup->background, score, 555, 475 + 145 + 5);
}