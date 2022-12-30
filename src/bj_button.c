/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 29/12/2022 18:53:52 by Durandnico   #+#    #+#    #+#             */
/*   Created: 30/12/2022 06:40:24 by Durandnico   ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file bj_button.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Thu 29 December 2022 - 18:53:52
 *
 *  \brief 
 *
 *
 */

//librairies
#include "../inc/blackjack.h"


void
hit(t_recup* ptr_rcp_recup, t_player* ptr_pl_player)
{
    draw_card(ptr_pl_player, 0);
    
    ptr_pl_player->total_value += ptr_pl_player->hand[ptr_pl_player->card_in_hand - 1].value ;    
    calc_score(ptr_rcp_recup, ptr_pl_player);

    show_everything(ptr_rcp_recup);

    /*disable special move*/
    ptr_rcp_recup->x2 = 0;
    ptr_rcp_recup->split = 0;

    /*if hit 21, automatic stay*/
    if(ptr_pl_player->total_value == 21){
        stay(ptr_rcp_recup, 0);
    }

    /*if hit more than 21, loose stay*/
    else if(ptr_pl_player->total_value > 21){
        stay(ptr_rcp_recup, 1);
    }
}


void calc_score(t_recup* ptr_rcp_recup, t_player* ptr_pl_player) {
    int i; //loop variable
    int int_ace_found;

    int_ace_found = 0;

    /*If overpass 21, check for aces*/
    if(ptr_pl_player->total_value > 21){
        
        /*check if their is any aces*/
        ptr_pl_player->total_value = 0;
        for(i = 0; i < ptr_pl_player->card_in_hand; i++){

            /* if we found an ace that value 11, put it down to 1*/
            if( ptr_pl_player->hand[i].value == 11 && !int_ace_found){
                ptr_pl_player->hand[i].value = 1;
                int_ace_found = 1;
            }
            ptr_pl_player->total_value += ptr_pl_player->hand[i].value;
        }

        /*if we found an ace but still > 21, check for more aces*/
        if( int_ace_found && ptr_pl_player->total_value > 21){
            calc_score(ptr_rcp_recup, ptr_pl_player);
            return ;
        }
    }

    /*Update on screen*/
    show_score(ptr_rcp_recup, ptr_pl_player);
}


void double_hit(t_recup* ptr_rcp_recup, t_player* ptr_pl_player)
{
    ptr_rcp_recup->current_bet *= 2;

    hit(ptr_rcp_recup, ptr_pl_player);

    if(ptr_pl_player->total_value > 21){
        stay(ptr_rcp_recup, 1);
    }
    else{
        stay(ptr_rcp_recup, 0);
    }
}


void stay(t_recup* ptr_rcp_recup, int int_cas) {
    /*disable special move*/
    ptr_rcp_recup->x2 = 0;
    ptr_rcp_recup->split = 0;

    /*waiting state*/
    ptr_rcp_recup->state = -1;

    /*un-hide the dealer card*/
    ptr_rcp_recup->ingame[0].hand[1].hide = 0;
    ptr_rcp_recup->ingame[0].total_value += ptr_rcp_recup->ingame[0].hand[ptr_rcp_recup->ingame[0].card_in_hand - 1].value; 
    
    /*classic stay*/
    if(int_cas ==  0){
        while(ptr_rcp_recup->ingame[0].total_value < 17){
            draw_card(&ptr_rcp_recup->ingame[0], 0);
            ptr_rcp_recup->ingame[0].total_value += ptr_rcp_recup->ingame[0].hand[ptr_rcp_recup->ingame[0].card_in_hand - 1].value; 
        }
    }

    /*show dealers card*/
    show_everything(ptr_rcp_recup);    

    state_switch(ptr_rcp_recup);
}