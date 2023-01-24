/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   BlackJack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 26/12/2022 19:51:54 by Durandnico   #+#    #+#    #+#             */
/*   Updated: 29/11/2022 06:14:14 by Durandnico   ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file card.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 19:51:54
 *
 *  \brief Function to use card
 * 
 */

//librairies
#include "../inc/blackjack.h"

t_card
create_card(t_flush flush_color, t_cardname cdname_name, int int_hide)
{
    t_card res; //card to create

    /*init all value*/
    res.value   =   NAMETOVALUE(cdname_name);
    res.color   =   flush_color;
    res.name    =   cdname_name;
    res.hide    =   int_hide;


    return res;
}


t_card
generate_random_card(int int_hide)
{
    static int int_first = 1;

    /*In case of first call*/
    if( int_first ){
        srand(time(NULL));
        int_first = 0;
    }     
    /* rand_int(12) + 1 cause value start at 1 and not 0*/
    return create_card(rand_int(3), rand_int(12) + 1, int_hide);
}


char*
ccolor_to_string(t_card cd_card)
{
     
    /*No need to explain*/
    switch (cd_card.color)
    {
    case DIAMOND:
        return "diamond/";
        break;
    
    case HEART:
        return "heart/";
        break;
    
    case CLUB:
        return "club/";
        break;

    case SPADE:
        return "spade/";
        break;

    default:
        fprintf(stderr, "ERROR COLOR %d\n", cd_card.color);
        break;
    }

    return NULL;
}


char*
cname_to_string(t_card cd_card)
{
    
    /*No need to explain*/
    switch (cd_card.name)
    {
    case AS:
        return "ace.xpm";
        break;
    case TWO:
        return "2.xpm";
        break;
    case THREE:
        return "3.xpm";
        break;
    case FOUR:
        return "4.xpm";
        break;
    case FIVE:
        return "5.xpm";
        break;
    case SIX:
        return "6.xpm";
        break;
    case SEVEN:
        return "7.xpm";
        break;
    case EIGHT:
        return "8.xpm";
        break;
    case NINE:
        return "9.xpm";
        break;
    case T:
        return "10.xpm";
        break;
    case J:
        return "jack.xpm";
        break;
    case Q:
        return "queen.xpm";
        break;
    case K:
        return "king.xpm";
        break;
    default:
        fprintf(stderr, "ERROR cname_to_string %d\n", cd_card.name);
        break;
    }

    return NULL;
}


void
draw_card(t_player* ptr_pl_player, int int_hide)
{   
    /*malloc the first card*/
    if(ptr_pl_player->card_in_hand == 0)
        ptr_pl_player->hand = malloc(1 * sizeof(t_card));
    
    /*realloc to add a card*/
    else
       ptr_pl_player->hand = realloc(ptr_pl_player->hand, (ptr_pl_player->card_in_hand + 1) * sizeof(t_card));
    
    /*add a card to the player and set the coord*/
    ptr_pl_player->hand[ptr_pl_player->card_in_hand] = generate_random_card(int_hide);
    ptr_pl_player->hand[ptr_pl_player->card_in_hand].img.coord.x = ptr_pl_player->base_x + ptr_pl_player->card_in_hand * ptr_pl_player->dx;
    ptr_pl_player->hand[ptr_pl_player->card_in_hand].img.coord.y = ptr_pl_player->base_y + ptr_pl_player->card_in_hand * ptr_pl_player->dy;
    ptr_pl_player->card_in_hand++;  
}