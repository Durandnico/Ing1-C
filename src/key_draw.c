/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   blackjack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 28/12/2022 15:14:12 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 30/11/2022 03:45:14 by Durandnico   ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file key_draw.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 15:14:12
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/blackjack.h"


int key_press(int int_keycode, t_recup* prcp_recup) {
     
    switch (int_keycode)
    {
    case ENTER:
        if (prcp_recup->current_bet != 0 && prcp_recup->datakey.enter == 0 && prcp_recup->state == 0){
            prcp_recup->datakey.enter = 1;
            state_switch(prcp_recup);
        }

        break;
    default:
        /*No use of this key*/
        break;
    }

    return 1;
}


int key_release(int int_keycode, t_recup* rcp_recup) {
     
     switch (int_keycode)
    {
        case ENTER:
            rcp_recup->datakey.enter = 0;
            break;

        default:
            /*No use of this key*/
            break;
    }

    return 0;
}


int
mouse_press(int int_button, int int_x, int int_y, t_recup* ptr_rcp_recup)
{   
    int             int_dy; //to store a little calcul
    static int      sint_change_button = 0;  //if the change button is clickable
    
    /*If betting state*/
    if(int_button && ptr_rcp_recup->state == 0){
        if (int_y <= 350 && int_y >= 0)
        {
            /*1 chip*/
            if (int_x >= 101 && int_x <= 251){
                ptr_rcp_recup->current_bet += 1;
                sint_change_button = 1;
            }

            /*2 chip*/
            else if (int_x >= 255 && int_x <= 405){
                ptr_rcp_recup->current_bet += 2;
                sint_change_button = 1;
            }

            /*5 chips*/
            else if (int_x >= 409 && int_x <= 559){
                ptr_rcp_recup->current_bet += 5;
                sint_change_button = 1;
            }

            /*10 chip*/
            else if (int_x >= 563 && int_x <= 713){
                ptr_rcp_recup->current_bet += 10;
                sint_change_button = 1;
            }

            /*25 chips*/
            else if (int_x >= 717 && int_x <= 867){
                ptr_rcp_recup->current_bet += 25;
                sint_change_button = 1;
            }

            /*100 chip*/
            else if (int_x >= 871 && int_x <= 1025){
                ptr_rcp_recup->current_bet += 100;
                sint_change_button = 1;
            } 

            /*500 chip*/
            else if (int_x >= 1029 && int_x <= 1179){
                ptr_rcp_recup->current_bet += 500;
                sint_change_button = 1;
            }

            else if( sint_change_button ){
                printf("ngro");
                sint_change_button = 0;
                state_switch(ptr_rcp_recup);
                return 0;
            }
        }

        if(ptr_rcp_recup->current_bet > ptr_rcp_recup->ingame[1].token)
            ptr_rcp_recup->current_bet = ptr_rcp_recup->ingame[1].token;

        show_betting(ptr_rcp_recup);
    }

    /*If playing state*/
    else if (ptr_rcp_recup->state == 1){
        if(int_x <= WINDOW_WIDTH - 125 && int_x >= WINDOW_WIDTH - 125 - 169){

            int_dy = (WINDOW_HEIGHT / 9);

            /*Double button, if possible*/
            if(ptr_rcp_recup->x2 == 1 && int_y >= int_dy  && int_y <= 2 * int_dy){
                double_hit(ptr_rcp_recup, &ptr_rcp_recup->ingame[1]);
            }

            /*Hit button*/
            else if( int_y >= 3 * int_dy  && int_y <= 4 * int_dy){
                hit(ptr_rcp_recup, &ptr_rcp_recup->ingame[1]);
            }

            /*Stay button*/
            else if( int_y >= 5 * int_dy  && int_y <= 6 * int_dy){
                stay(ptr_rcp_recup, 0);
            }

            /*split button, if possible*/
            else if( int_y >= 7 * int_dy  && int_y <= 8 * int_dy){
                //split
                return 0;
            }
        }
    }
    
    return 0;
}