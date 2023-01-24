#ifndef __APPROXIMATIONDESQRT2_H
#define __APPROXIMATIONDESQRT2_H

/*! 
 *  \file ApproximationDeSqrt2.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 16 November 2022 - 14:33:42
 *
 *  \brief Headers of ApproximationDeSqrt2.c
 *
 *
 */

// librairies
#include <stdlib.h>
#include <math.h>

/*!
 *  \fn double Newton(long ld_n)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 16 November 2022 - 14:55:03
 *  \brief estimate sqrt(2) with Isaac Newton's method
 *  \param ld_n number of iteration (aka precision)
 *  \return an approximation of sqrt(2)
 */
double Newton(long ld_n) ;


/*!
 *  \fn double Halley(long ld_n)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 16 November 2022 - 15:07:51
 *  \brief estimate sqrt(2) with Edmund Halley's method
 *  \param ld_n number of iteration (aka precision)
 *  \return an approximation of sqrt(2)
 */
double Halley(long ld_n);


/*!
 *  \fn double Smyrne(long ld_pn, long ld_qn, long ld_n)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 16 November 2022 - 15:23:02
 *  \brief estimate sqrt(2) with Théon de Smyrne's method
 *  \pre first call : ld_pn = 1, ld_qn = 1
 *  \param db_pn is an acc 
 *  \param db_qn is an acc
 *  \param ld_n number of iteration (aka precision)
 *  \return an approximation of sqrt(2)
 */
double Smyrne(double db_pn, double db_qn, long ld_n);

#endif