// #################################################
//                    ISTY
//
// INI1
//
// Bayrem JRIDI -- bayrem.jridi@isty.uvsq.fr
// Adli MLIK    -- adli.mlik@isty.uvsq.fr
//
// Dans ce fichier on trouve les fonctions et le menu qu'on utilise
// pour la creation des arbre
//
// ##################################################



#ifndef MODE_CREATION_H
#define MODE_CREATION_H

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "arbre.h"
#include "mode_manipulation.h"

/**
 * Procedure qui affiche le menu de creation d'arbre
 * */
void menu2();

/**
 * Fonction qui manipule les clique pour assurer les fonction de creation
 * de l'arbre
 * @parametre : pointeur sur la structure arbre, structure point
 * @retoure : entier
 * */
int choisir_menu2(ARBRE* A, int i,POINT a);

/**
 * Procedure qui lance le mode creation
 * @parametre : pointeur sur la structure arbre
 * */
void mode_creation(ARBRE* A);


# endif
