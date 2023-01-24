/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section INFO
*  \brief TD4 : Approximation de Pi
*/

/*! 
 *  \file ApproximationDeSqrt2.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 16 November 2022 - 14:23:13
 *
 *  \brief functions to make an approximation of Sqrt(2)
 *
 *
 */

//librairies
#include "ApproximationDeSqrt2.h"

/*---------------------------------------------------------------------------------------------------*/

double
Newton(long ld_n)
{
    double db_res; //Approx of sqrt(2)
    
    /* Initialize U0 = 1 */
    db_res = 1; 

    /*
     *Loop to reach Un 
     *
     * Un+1 = Un/2 + 1/Un
     */
    while (ld_n-- >= 0)
    {
        db_res = (db_res/2.) + (1./db_res);
    }
    
    return db_res;
}

/*---------------------------------------------------------------------------------------------------*/

double
Halley(long ld_n)
{
    double db_res; //Approx of sqrt(2);
    double db_Xn2; //Use to store Xn²

    /* Initialize X0 = 1 */
    db_res = 1; 
    
    /*
     *Loop to reach Xn
     *
     * Xn+1 = Xn * (Xn² + 6) / (3X²n + 2)
     */
    while (ld_n-- > 0)
    {
        db_Xn2 = db_res * db_res;

        db_res = db_res * (db_Xn2 + 6.) / ((3. * db_Xn2) + 2.); 
    }
    
    return db_res;
}

/*---------------------------------------------------------------------------------------------------*/

double
Smyrne(double db_pn, double db_qn, long ld_n)
{

    /*Exit condition : */
    if(ld_n <= 0){
        return (double) db_pn / db_qn;
    }
    
    /*
     *Recursion to reach Pn and Qn
     *
     * Pn+1 = Pn + 2Qn
     * Qn+1 = Pn + Qn 
     */
    return Smyrne(db_pn + (2 * db_qn), db_pn + db_qn, ld_n - 1);
}

