/*!
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

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 14:32:50
 *  \brief Main program
 *  \param argc : number of parameters
 *  \param argv : Values of the parameters 
 *  \return 0 if no error, -1 otherwise
 */
int main (int argc, char** argv) {
     
    t_recup recup;

    init(&recup);

    t_card test = create_card(10, DIAMOND, Q);
    test.img.coord.x = 200;
    test.img.coord.y = 200;
    show_card(&recup, &test);
    mlx_loop(recup.mlx);
    return 0;
}

