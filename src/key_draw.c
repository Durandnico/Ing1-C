/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   blackjack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 28/12/2022 15:14:12 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 29/11/2022 03:45:14 by Durandnico   ########     ###              */
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
        if (prcp_recup->datakey.enter == 0 && prcp_recup->state == 0){
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
mouse_press(int int_button, int int_x, int int_y, t_recup* rcp_recup)
{   

    /*If betting state*/
    if(int_button && rcp_recup->state == 0){
        if (int_y <= 350 && int_y >= 200)
        {
            if (int_x >= 101 && int_x <= 251){
                rcp_recup->current_bet += 1;
            }

            else if (int_x >= 255 && int_x <= 405){
                rcp_recup->current_bet += 2;
            }

            else if (int_x >= 409 && int_x <= 559){
                rcp_recup->current_bet += 5;
            }

            else if (int_x >= 563 && int_x <= 713){
                rcp_recup->current_bet += 10;
            }

            else if (int_x >= 717 && int_x <= 867){
                rcp_recup->current_bet += 25;
            }

            else if (int_x >= 871 && int_x <= 1025){
                rcp_recup->current_bet += 100;
            } 

            else if (int_x >= 1029 && int_x <= 1179){
                rcp_recup->current_bet += 500;
            }
        }

        if(rcp_recup->current_bet > rcp_recup->ingame[1].token)
            rcp_recup->current_bet = rcp_recup->ingame[1].token;

        printf("current bet : %d\n", rcp_recup->current_bet);
    }

    /*If playing state*/
    return 0;
}