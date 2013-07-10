#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "arbre.h"
#include "mode_creation.h"
#include "mode_manipulation.h"

int main()
{
	POINT x,y;
	ARBRE A = NULL;
	
	//creation de la fenêtre
	init_graphics(700*1.2,650*1.2);
	
	//creation de l'arbre principal
	x = creer_point(10,10);
	y = creer_point(550*1.2,550*1.2);
	A = creer_arbre(x,y,blanc);
	
	mode_manipulation(&A);
	
	wait_escape();
	return 0;
}
