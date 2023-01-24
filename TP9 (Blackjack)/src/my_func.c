/* **************************************************************************** */
/*                                                                              */
/*                                                       ::::::::  :::   :::    */
/*   Proj_Name                                          :+:    :+: :+:   :+:    */
/*                                                    +:+         +:+ +:+       */
/*   By: Durandnico <durandnico@cy-tech.fr>          +#+          +#++:         */
/*                                                 +#+           +#+            */
/*   Created: 30/12/2022 00:15:40 by Durandnico   #+#    #+#    #+#             */
/*                                                ########     ###              */
/*                                                                              */
/* **************************************************************************** */

/*! 
 *  \file my_func.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Fri 30 December 2022 - 00:15:40
 *
 *  \brief bunch of usefull func
 *
 *
 */

//librairies
#include "../inc/blackjack.h"

int
rand_int(int int_target)
{     
    float flt_tmp = (float) rand()/RAND_MAX;

    /*To make even the chance to get target*/
    if(flt_tmp == 1)
        flt_tmp -= 0.01;
    
    return (int) (flt_tmp * ++int_target);
}

char*
itoa(int int_value)
{
    
    int i; //loop variable
    int int_tmp;    //tmp variable
    size_t sz_length; //lenght of the score string
    char* str_res;  //var which's return

    /*specific case*/
    if(int_value == 0) 
        return "0";

    /*initalisation*/
    sz_length = 1;
    int_tmp = int_value;
    i = 0;

    while( int_tmp != 0){
        int_tmp /= 10;
        sz_length++;
    }

    str_res = malloc(sz_length);
    for( i = sz_length - 2; i > -1 ; i--){
        str_res[i] = (int_value % 10) + '0';
        int_value /= 10;
    }
    str_res[sz_length - 1] = '\0';

    return str_res;
}