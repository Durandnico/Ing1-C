# README
## Project : Ing1-TP9 
### Table des matières
1. [Pré-requis](#Pré-requis)
2. [Compiler](#compiler)
3. [Lancer l'exécutable](#exe)
4. [Comment jouer](#tuto)
5. [Supprimer les fichiers en .exe et .o](#suppr)
6. [Documentation Doxygen](#doxy)

#### Pré-requis
***
need to install the following dependencies: xorg, libxext-dev and zlib1g-dev. On Ubuntu this is the commande
```sh
sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
```
#### Compiler
***
Pour compiler :
```sh
make
```
Cela créera aussi l'éxecutable.
#### Lancer l'exécutable
***
Pour lancer l'exécutable :
```sh
./bin/TP9
```
#### Comment jouer
Tutoriel :
***
```
right-click : révèle la case
left-click  : flag la case (j'ai pas de sprites malheureusement)

si tu click sur une bombe ou révèle toutes les cases non bombe, la partie est terminé
```
#### Supprimer les dossiers bin (executable), obj (fichiers .o) et doc (DoxyFile)
***
Pour supprimer les dossiers bin (executable), obj (fichiers .o) et doc (DoxyFile) :
```sh
make clean
```
#### Documentation Doxygen
***
En lançant cette commande :
```sh
make doc
```
La documentation Doxygen sera créée ou mise à jour si elle existe déjà.

Pour l'ouvrir dans Firefox faire :
```sh
make docHtml
```

### Crédits
***
Auteur : DURAND Nicolas Erich Pierre <nicolas.durand@cy-tech.fr>
