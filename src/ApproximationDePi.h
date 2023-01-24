#ifndef __APPROXIMATIONDEPI_H
#define __APPROXIMATIONDEPI_H

/*! 
 *  \file ApproximationDePi.h
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 15 November 2022 - 10:06:49
 *
 *  \brief Headers of ApproximationDePi.c
 *
 *
 */

// librairies
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*Headers*/

/*!
 *  \fn float rnd(float float_val)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 15 November 2022 - 10:13:14
 *  \brief Use rand() func to generate a float between 0 and fl_val
 *  \param float_val the generate number must be lower or equal than it
 *  \return an random number in [0 , val]
 */
float rnd(float float_val);


/*!
 *  \fn double Quadrillage (long ld_n)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 15 November 2022 - 10:08:03
 *  \brief Calcul an approximation of Pi by using the forme of a cercle
 *  \param ld_n number of dot generate(even to precison)
 *  \return an approximation of Pi
 */
double Quadrillage(long ld_n);


/*!
 *  \fn double Madhava(long ld_n)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 15 November 2022 - 10:56:20
 *  \brief estimate Pi with Madhava method
 *  \param ld_n number of iteration (aka precision)
 *  \return an approximation of pi
 */
double Madhava(long ld_n);

/*!
 *  \fn double JohnWallis(long ld_n)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Tue 15 November 2022 - 13:21:04
 *  \brief estimate Pi with JohnWallis's method
 *  \param ld_n number of iteration (aka precision)
 *  \return an approximation of Pi
 */
double JohnWallis(long ld_n);

 
#endif