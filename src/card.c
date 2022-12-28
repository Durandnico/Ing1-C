/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   BlackJack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 26/12/2022 19:51:54 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
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

/*!
 *  \fn t_card create_card(int int_value, t_flush color, t_cardname name)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 22:40:19
 *  \brief 
 *  \param 
 *  \return 
 */
t_card
create_card(int int_value, t_flush color, t_cardname name)
{
    t_card res; //card to create

    res.value = int_value;
    res.color = color;
    res.name  = name;

    return res;
}


/*!
 *  \fn int rand_int(int int_target)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 22:58:46
 *  \brief generate a random int between [[0:target]]
 *  \param int_target max value to return
 *  \return random int  
 */
int
rand_int(int int_target)
{     
    float flt_tmp = (rand()/RAND_MAX);

    /*To make even the chance to get target*/
    if(flt_tmp == 1)
        flt_tmp -= 0.01;
    
    return (int) (flt_tmp * ++int_target);
}

/*!
 *  \fn t_card generate_random_card(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Mon 26 December 2022 - 22:54:13
 *  \brief generate a random card (pick a card)
 *  \param void
 *  \return a random card
 */
t_card
generate_random_card(void)
{
    static int int_first = 1;
    t_cardname stru_name;

    /*In case of first call*/
    if( int_first ){
        srand(time(NULL));
        int_first = 0;
    }     

    stru_name = rand_int(13);
    return (create_card(NAMETOVALUE(stru_name), rand_int(3), stru_name));
}

/*!
 *  \fn char* ccolor_to_string(t_card stru_card)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 27 December 2022 - 23:55:03
 *  \brief get the correct directory for the card
 *  \param card     : card to get the color of
 *  \return the color of the card in a string
 */
char* ccolor_to_string(t_card stru_card) {
     
    /*No need to explain*/
    switch (stru_card.color)
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
        fprintf(stderr, "ERROR COLOR\n");
        break;
    }

    return NULL;
}


/*!
 *  \fn char* cname_to_string(t_card stru_card)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 00:18:15
 *  \brief 
 *  \param 
 *  \return 
 */
char* cname_to_string(t_card stru_card) {
    
    /*No need to explain*/
    switch (stru_card.name)
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
        fprintf(stderr, "ERROR cname_to_string\n");
        break;
    }

    return NULL;
}