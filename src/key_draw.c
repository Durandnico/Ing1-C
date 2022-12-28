/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   blackjack                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 28/12/2022 15:14:12 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
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

/*!
 *  \fn int key_press(int int_keycode, t_recup* rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 15:14:57
 *  \brief if a key is press, set it value to true
 *  \param keycode      : code of the pressed key 
 *  \param recup        : data for mlx
 *  \return 0 mandatory fo mlx_hook 
 */
int key_press(int int_keycode, t_recup* rcp_recup) {
     
    switch (int_keycode)
    {
    case ALT:
        rcp_recup->datakey.alt = 1;
        break;
    
    case F4:
        rcp_recup->datakey.f4 = 1;
        break;
    
    default:
        /*No use of this key*/
        break;
    }

    return 1;
}


/*!
 *  \fn int key_release(int int_keycode, t_recup* rcp_recup)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 28 December 2022 - 15:37:12
 *  \brief if a key is release, set it value to false
 *  \param keycode      : code of the pressed key 
 *  \param recup        : data for mlx
 *  \return 0 mandatory fo mlx_hook
 */
int key_release(int int_keycode, t_recup* rcp_recup) {
     
     switch (int_keycode)
    {
    case ALT:
        rcp_recup->datakey.alt = 0;
        break;
    
    case F4:
        rcp_recup->datakey.f4 = 0;
        break;
    
    default:
        /*No use of this key*/
        break;
    }

    return 0;
}