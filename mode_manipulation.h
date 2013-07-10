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



#ifndef MODE_MANIPULATION_H
#define MODE_MANIPULATION_H

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "arbre.h"
#include "mode_creation.h"

/**
 * Procedure qui affiche le menu de creation d'arbre
 * */
void menu();

/**
 * Procedure qui fusion les fils d'un arbre s'il sont de même couleur
 * @parametre : pointeur sur la structure arbre
 * */
void fusion(ARBRE* A);

/**
 * Procedure qui inverse les fils d'un arbre
 * @parametre : pointeur sur la structure arbre
 * */
void inverser(ARBRE* A);

/**
 * Procedure qui appliques la notion de gravité à notre arbre
 * le fils le plus important en masse tombera en premier
 * @parametre : pointeur sur la structure arbre
 * */
void chute(ARBRE* A);

/**
 * Procedure qui fait la rotation 90° vers l'east des fils d'un arbre 
 * @parametre : pointeur sur la structure arbre, structure point
 * */
void rotation90(ARBRE* A);

/**
 * Procedure qui copie un arbre dans un autre
 * @parametre : 2 pointeurs sur la structure arbre
 * */
void copier_arbre(ARBRE* A, ARBRE* B);

/**
 * Procedure qui manipule les clique pour assurer les fonction de 
 * manipulation
 * @parametre : pointeur sur la structure arbre, structure point
 * */
void choisir_menu(ARBRE* A,POINT a);

/**
 * Procedure qui lance le mode manipulation
 * @parametre : pointeur sur la structure arbre
 * */
void mode_manipulation(ARBRE* A);

/**
 * Fonction qui transforme un arbre en une chaine de caracteres
 * @parametre : pointeur sur la structure arbre
 * */
char* toString(ARBRE A);


# endif
