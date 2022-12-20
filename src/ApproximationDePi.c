/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TD4 : Approximation de Pi
*/

/*! 
 *  \file ApproximationDePi.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 15 November 2022 - 09:55:36
 *
 *  \brief Fonction to make an approximation of Pi
 *
 *
 */

// librairies
#include "ApproximationDePi.h"

/*---------------------------------------------------------------------------------------------------*/


float
rnd(float fl_val)
{
    static int int_first = 1; //Use to initialize the seed the first time the func is call     
    float fl_res; //To store the answer

    /*Set a seed if first call*/
    if(int_first == 1){
        srand(time(NULL));
        int_first = 0;
    }
    
    fl_res = (float) rand();
    return (float)(fl_res/RAND_MAX)*fl_val ;
}

/*---------------------------------------------------------------------------------------------------*/


double
Quadrillage(long ld_n)
{
    long ld_in; //number of dots in the cercle
    float fl_x; //Stores the dot's x value
    float fl_y; //Stores the dot's y value
    double db_pi; //Approx of Pi

    ld_in = 0;
    /*Generate n dots between [0,1] to estimate the 1/4 of the cercle Area (Radius 1, Center : 0)*/
    for(long i = 0; i < ld_n; i++){
        fl_x = rnd(1);
        fl_y = rnd(1);

        /*If distance from center <= 1 (in the cercle)*/
        if(sqrt((fl_x * fl_x) + (fl_y * fl_y)) <= 1) {
            ld_in++;
        }
    }

    /*dots in / total = Area / 4 */
    db_pi = (double) ld_in / ld_n;
    
    return db_pi * 4;
}

/*---------------------------------------------------------------------------------------------------*/

double
Madhava(long ld_n)
{
    double db_pi; //Approx of Pi
    int int_signe; //is -1 or 1 only

    db_pi = 0;
    int_signe = 1;
    
    /*
     *Loop to reach Un
     * 
     * Un = Un-1 + (-1)^n / (2*n + 1)
     * U0 = 0
     */
    for(long i = 0; i < ld_n; i++) {
        db_pi += (double) int_signe *  (1. / ((2*i) + 1));
        int_signe *= -1;

    }
    return db_pi * 4;
}

/*---------------------------------------------------------------------------------------------------*/

double 
JohnWallis(long ld_n) 
{
    double db_pi; //Approx of Pi
    double db_pow; //Store (2k)²
    
    db_pi = 1;

    /*
     *Loop to reach Un
     * 
     * Un = Un-1 * [ n² / (n² - 1) ]
     * U0 = 1
     */
    for(long i = 1; i < ld_n; i++){
        db_pow = pow(2*i, 2);
        db_pi *= (double) db_pow / (db_pow - 1);
    }
    
    return db_pi * 2;
}


