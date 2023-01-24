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
 *  \brief function for the traitment of user's inputs
 *
 *
 */

//librairies
#include "../inc/blackjack.h"

int
mouse_press(int int_button, int int_x, int int_y, t_recup* ptr_rcp_recup)
{   
    int             int_dy; //to store a little calcul
    static int      sint_change_button = 0;  //if the change button is clickable

    /*If betting state*/
    if(ptr_rcp_recup->state == 0){
        
        if(int_button == LEFT_CLICK && sint_change_button && int_y >= 525 && int_y <= 697 && int_x >= 550 && int_x <= 719){
            state_switch(ptr_rcp_recup);
            sint_change_button = 0;
            return 0;
        }
        
        if (int_y <= 350 && int_y >= 0)
        {
            /*1 chip*/
            if (int_x >= 101 && int_x <= 251){
                ptr_rcp_recup->current_bet += (int_button == LEFT_CLICK) ? 1 : -1;
            }

            /*2 chip*/
            else if (int_x >= 255 && int_x <= 405){
                ptr_rcp_recup->current_bet += (int_button == LEFT_CLICK) ? 2 : -2;
            }

            /*5 chips*/
            else if (int_x >= 409 && int_x <= 559){
                ptr_rcp_recup->current_bet += (int_button == LEFT_CLICK) ? 5 : -5;
            }

            /*10 chip*/
            else if (int_x >= 563 && int_x <= 713){
                ptr_rcp_recup->current_bet += (int_button == LEFT_CLICK) ? 10 : -10;
            }

            /*25 chips*/
            else if (int_x >= 717 && int_x <= 867){
                ptr_rcp_recup->current_bet += (int_button == LEFT_CLICK) ? 25 : -25;
            }

            /*100 chip*/
            else if (int_x >= 871 && int_x <= 1025){
                ptr_rcp_recup->current_bet += (int_button == LEFT_CLICK) ? 100 : -100;
            } 

            /*500 chip*/
            else if (int_x >= 1029 && int_x <= 1179){
                ptr_rcp_recup->current_bet += (int_button == LEFT_CLICK) ? 500 : -500;
            }

            if( !sint_change_button && ptr_rcp_recup->current_bet != 0){
                sint_change_button = 1;
            }
        }

        if(ptr_rcp_recup->current_bet > ptr_rcp_recup->ingame[1].token)
            ptr_rcp_recup->current_bet = ptr_rcp_recup->ingame[1].token;

        if(ptr_rcp_recup->current_bet < 0)
            ptr_rcp_recup->current_bet = 0;

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
    
    /*waiting to reload match*/
    else if(int_y >= ptr_rcp_recup->button[5].coord.y && int_y <= (ptr_rcp_recup->button[5].coord.y + 72) && int_x >= ptr_rcp_recup->button[5].coord.x && int_x <= (ptr_rcp_recup->button[5].coord.x + 169) ){
        ptr_rcp_recup->state = 1;
        state_switch(ptr_rcp_recup);
    }
    return 0;
}