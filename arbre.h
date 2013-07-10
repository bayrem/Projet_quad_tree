// #################################################
//                    ISTY
//
// INI1
//
// Bayrem JRIDI -- bayrem.jridi@isty.uvsq.fr
// Adli MLIK    -- adli.mlik@isty.uvsq.fr
//
// Dans ce fichier on trouve les fonctions qu'on utilise
// pour la creation des arbre ainsi que les example
//
// ##################################################


#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

/**
 * La structure arbre
 **/
 
typedef struct NOEUD* ARBRE;

struct NOEUD {
	COULEUR c;
	ARBRE f1,f2,f3,f4;
	POINT x,y;
} NOEUD;

/**
 * Fonction qui crée les points
 * @parametre : entier 
 * @retoure : structure point
 * */
POINT creer_point(int x, int y);

/**
 * Fonction qui crée les arbre
 * @parametre : point,point, couleur
 * @retoure : structure arbre
 * */
ARBRE creer_arbre(POINT x, POINT y, COULEUR c);

/**
 * Fonction qui qui prend en parametre un arbre et un point
 * retour d'un clique et qui cherche le sous-arbre en question
 * @parametre : structure arbre, structure point
 * @retoure : structure arbre
 * */
ARBRE chercher_arbre(ARBRE A, POINT a);

/**
 * Procedure qui devise un arbre en 4 sous-arbres
 * @parametre : structure arbre
 * */
void deviser(ARBRE A);

/**
 * Fonction qui indique si un arbre est un noeud ou une feuille
 * @parametre : structure arbre
 * @retoure : true si noeud / false si feuille
 * */
BOOL est_noeud(ARBRE A);

/**
 * Procedure qui affiche l'arbre sur l'ecran
 * @parametre : structure arbre 
 * */
void afficher(ARBRE A);

/**
 * Fonction qui crée l'example A1
 * @retoure : structure arbre
 * */
ARBRE example1();

/**
 * Fonction qui crée l'example A2
 * @retoure : structure arbre
 * */
ARBRE example2();

/**
 * Fonction qui crée l'example A3
 * @retoure : structure arbre
 * */
ARBRE example3();

/**
 * Fonction qui crée l'example A4
 * @retoure : structure arbre
 * */
ARBRE example4();

#endif
