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
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TD9-Blackjack
*/

/*! 
 *  \file blackjack.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 14:16:26
 *
 *  \brief equivalent to main.c
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
state_switch(t_recup* ptr_rcp_recup) 
{
    int i; //loop variable
    int j; //loop variable

    /*If betting state, switch to playing*/
    if(ptr_rcp_recup->state == 0) {
        ptr_rcp_recup->state = 1;

        /*draw cards*/
        draw_card(&ptr_rcp_recup->ingame[1], 0);
        draw_card(&ptr_rcp_recup->ingame[0], 0);
        draw_card(&ptr_rcp_recup->ingame[1], 0);
        draw_card(&ptr_rcp_recup->ingame[0], 1);

        /*add card value to the score*/
        for( j = 0; j < 2; j++){
            for( i = 0; i < 2; i++){
                ptr_rcp_recup->ingame[j].total_value += ptr_rcp_recup->ingame[j].hand[i].value;
            }     
        }
        /*the hiden card must not be count in tha dealer score*/
        ptr_rcp_recup->ingame[0].total_value -= ptr_rcp_recup->ingame[0].hand[1].value;    
        
        /*show board, card, button, score*/
        show_everything(ptr_rcp_recup);


        /*if got 21 skip plays*/
        if( ptr_rcp_recup->ingame[1].total_value == 21 || ( ptr_rcp_recup->ingame[0].hand[0].value + ptr_rcp_recup->ingame[0].hand[1].value) == 21 ){
            stay(ptr_rcp_recup, 1);
        }
    }

    /*else switch from playing to betting*/
    else{

        /*checks who win*/
        /*if win, give token*/
        if( (ptr_rcp_recup->ingame[0].total_value < ptr_rcp_recup->ingame[1].total_value && ptr_rcp_recup->ingame[1].total_value < 22) || ptr_rcp_recup->ingame[0].total_value > 21){
            ptr_rcp_recup->ingame[1].token += ptr_rcp_recup->current_bet;
        }

        /*if loose*/
        else if(ptr_rcp_recup->ingame[0].total_value > ptr_rcp_recup->ingame[1].total_value || ptr_rcp_recup->ingame[1].total_value > 21){
            ptr_rcp_recup->ingame[1].token -= ptr_rcp_recup->current_bet;
        }

        /*reset variable*/
        ptr_rcp_recup->state = 0;
        ptr_rcp_recup->current_bet = 0;


        /*liberer les cartes*/
        for( i = 0; i < 2; i++){
            free(ptr_rcp_recup->ingame[i].hand);
            ptr_rcp_recup->ingame[i].card_in_hand = 0;
            ptr_rcp_recup->ingame[i].total_value = 0;
        }
        
        /*show betting state*/
        show_betting(ptr_rcp_recup);
    }
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
    mlx_loop(recup.mlx);

    return 0;
}

