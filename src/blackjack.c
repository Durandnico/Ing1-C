/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Blackjack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 28/12/2022 14:16:26 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file blackjack.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 14:16:26
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/blackjack.h"

int
exit_prog(void)
{
    exit(0);
    return 0;
}



void
state_switch(t_recup* prcp_recup) 
{
    int i; //loop variable
    int j; //loop variable

    /*If betting state, switch to playing*/
    if(prcp_recup->state == 0) {
        prcp_recup->state = 1;

        /*clear the window*/
        mlx_clear_window(prcp_recup->mlx, prcp_recup->win);
        
        /*put the correct background*/
        mlx_put_image_to_window(prcp_recup->mlx, prcp_recup->win, prcp_recup->background.img, 0, 0);

        /*draw cards*/
        draw_card(&prcp_recup->ingame[1], 1);
        draw_card(&prcp_recup->ingame[0], 1);
        draw_card(&prcp_recup->ingame[1], 1);
        draw_card(&prcp_recup->ingame[0], 0);

        /*show cards*/
        for( j = 0; j < 2; j++){
            for( i = 0; i < 2; i++){
                show_card(prcp_recup, &prcp_recup->ingame[j].hand[i]);
            }
        }

        /*show button HIT and STAY*/
        //mlx_put_image_to_window(prcp_recup->mlx, prcp_recup->win, prcp_recup->button[0].img, prcp_recup->button[0].coord.x, prcp_recup->button[0].coord.y);
        //mlx_put_image_to_window(prcp_recup->mlx, prcp_recup->win, prcp_recup->button[1].img, prcp_recup->button[1].coord.x, prcp_recup->button[1].coord.y);
        
        /*if card just been hit, show double button*/
        if(prcp_recup->ingame[1].card_in_hand == 2){
            //mlx_put_image_to_window(prcp_recup->mlx, prcp_recup->win, prcp_recup->button[2].img, prcp_recup->button[2].coord.x, prcp_recup->button[2].coord.y);    
            
            /*if splittable show split button*/
            if(prcp_recup->ingame[1].hand[0].value == prcp_recup->ingame[1].hand[1].value){
                //mlx_put_image_to_window(prcp_recup->mlx, prcp_recup->win, prcp_recup->button[3].img, prcp_recup->button[3].coord.x, prcp_recup->button[3].coord.y);
            }
        }   
    }

    /*else switch from playing to betting*/
    else{

    }
}

/*!
 *  \proc void blackjack(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 18:49:58
 *  \brief start the blackjack
 *  \param void
 */
void blackjack(void) {
    
    t_recup rcp_recup;

    init(&rcp_recup);

    rcp_recup.state = 0;
    
}


/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 14:32:50
 *  \brief function call yeah programme start
 *  \param void
 *  \return 0 if no error, -1 otherwise
 */
int main (void) {
     
    t_recup recup;
    init(&recup);

    
    //char c;
    //t_card test = create_card( 2, rand_int(8), 1);
    //test.img.coord.x = 600;
    //test.img.coord.y = 350;
    //show_card(&recup, &test);
    //recup.state = 0;
    //t_img testt;
    //testt.img = mlx_xpm_file_to_image(recup.mlx, "texture/chip1.xpm", &testt.width, &testt.height);
    //testt.addr = mlx_get_data_addr(testt.img, &testt.bits_per_pixel, &testt.line_length, &testt.endian);
    //testt.coord.x = 600;
    //testt.coord.y = 350;
    ////char *dst = testt.addr + (2 * testt.line_length + 2 * (testt.bits_per_pixel / 8));
	////printf("%d %d %d %d\n", get_t((int*) dst[0]), get_r((int*) dst[0]), get_g((int*) dst[0]), get_b((int*) dst[0]));
    ////my_mlx_pixel_put(&recup.background, 2,2,0x00FF0000);
    //mlx_clear_window(recup.mlx, recup.win);
    ////mlx_put_image_to_window(recup.mlx, recup.win, recup.background.img, 0, 0);
    ////mlx_put_image_to_window(recup.mlx, recup.win, testt.img, 101, 325);
    //drawn_sprite(&recup, testt);
    //mlx_put_image_to_window(recup.mlx, recup.win, recup.background.img, 0, 0);
    //file = fopen("m.xpm", "r");
    //printf("%d %d\n",fgetc(file), fgetc(file));

    mlx_loop(recup.mlx);

    return 0;
}

