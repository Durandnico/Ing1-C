/*!
*  \mainpage Programme
*  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
*  \section Programme-Procédural
*  \brief 
*       Programme qui affiche Hello World dans le terminal
*/

/*! 
 *  \file main.c
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 1.0
 *  \date Wed 19 October 2022 - 10:58:25
 *
 *  \brief 
 *      Ceci est le programme principal
 *
 */

// Inclusion des entetes de librairies
#include <stdio.h>
/*! 


/*!
 *  \fn void helloWorld(void)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \date Wed 19 October 2022 - 10:09:10
 *  \brief affiche "Hello World" dans le terminal
 *  \param none 
 *  \return "Hello World" dans stdout
 */
void helloWorld(void) {
    printf("Hello World\n");
}

/*!
 *  \fn int main (int argc, char** argv)
 *  \author DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
 *  \version 0.1
 *  \date Wed 19 October 2022 - 10:07:38
 *  \brief Programme principal
 *  \param argc : Nombre de paramètres à l'exécution
 *  \param argv : Valeur des paramètres 
 *  \return 0 si tout s'est bien passé
 */
int main (int argc, char** argv) {
    helloWorld () ;
    return 0;
}

 
/*
------------------------QUESTION 3 vous deviene fous---------------------

Détermination des séquences d'échappement:
* \n : nouvelle ligne
* \t : tabulation horizontale
* \v : Tabulation verticale
* \b : retour arrière
* \r : retour chariot
* \f : saut de page
* \' : guillement simple
* \\ : barre oblique inverse
* \nnn : correspond à un caractère ascii en hexadécimal qui se compose de 2 ou 3 chiffres
* \xnn : correspond à un caractère ascii en hexadécimal qui se compose de 2 chiffres

*/

