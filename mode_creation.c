#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "arbre.h"
#include "mode_creation.h"

void menu2()
{
	POINT x,y,p;
	
	//creation de option1
	x = creer_point(10*1.2,580*1.2);
	y = creer_point(110*1.2,630*1.2);
	p = creer_point(23*1.2,620*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("BLANC", 22, p, rouge);
	
	//creation de option2
	x = creer_point(200*1.2,580*1.2);
	y = creer_point(300*1.2,630*1.2);
	p = creer_point(220*1.2,620*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("NOIR", 22, p, rouge);
	
	//creation de option3
	x = creer_point(390*1.2,580*1.2);
	y = creer_point(490*1.2,630*1.2);
	p = creer_point(390*1.2,620*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("DEVISER", 22, p, rouge);
	
	//creation de option4
	x = creer_point(580*1.2,580*1.2);
	y = creer_point(680*1.2,630*1.2);
	p = creer_point(582*1.2,620*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("VALIDER", 22, p, rouge);
	
	//creation de option6
	x = creer_point(580*1.2,500*1.2);
	y = creer_point(680*1.2,550*1.2);
	p = creer_point(585*1.2,540*1.2);
	draw_rectangle(x,y, gris);
	aff_pol("TO STRING", 16, p, gris);
	
	//creation de option7
	x = creer_point(580*1.2,400*1.2);
	y = creer_point(680*1.2,450*1.2);
	p = creer_point(587*1.2,440*1.2);
	draw_rectangle(x,y, gris);
	aff_pol("ROTATION", 16, p, gris);
	
	//creation de option8
	x = creer_point(580*1.2,300*1.2);
	y = creer_point(680*1.2,350*1.2);
	p = creer_point(583*1.2,340*1.2);
	draw_rectangle(x,y, gris);
	aff_pol("INVERSION", 16, p, gris);
	
	//creation de option9
	x = creer_point(580*1.2,200*1.2);
	y = creer_point(680*1.2,250*1.2);
	p = creer_point(597*1.2,240*1.2);
	draw_rectangle(x,y, gris);
	aff_pol("FUSION", 16, p, gris);
	
	//creation de option10
	x = creer_point(580*1.2,100*1.2);
	y = creer_point(680*1.2,150*1.2);
	p = creer_point(603*1.2,140*1.2);
	draw_rectangle(x,y, gris);
	aff_pol("CHUTE", 16, p, gris);
}


int choisir_menu2(ARBRE* A, int i,POINT a)
{

	if (a.x < 110*1.2 && a.y < 630*1.2 && a.x > 10*1.2 && a.y > 580*1.2) {printf("%s\n","BLANC"); i = 0;}
	else if (a.x < 300*1.2 && a.y < 630*1.2 && a.x > 200*1.2 && a.y > 580*1.2) {printf("%s\n","NOIR");i = 1;}
	else if (a.x < 490*1.2 && a.y < 630*1.2 && a.x > 390*1.2 && a.y > 580*1.2) {printf("%s\n","DEVISER"); i = 2;}
	else if (a.x < 680*1.2 && a.y < 630*1.2 && a.x > 580*1.2 && a.y > 580*1.2) {printf("%s\n","VALIDER"); mode_manipulation(A);}
	
	return i;
}

void mode_creation(ARBRE* A)
{
	POINT x,y,p;
	int i=2;
	fill_screen(noir);
	menu2();
	//creation de la fenetre grise
	x = creer_point(0,0);
	y = creer_point(560*1.2,560*1.2);
	draw_fill_rectangle(x,y, gris);
	
	//creation de l'arbre vierge
	x = creer_point(10,10);
	y = creer_point(550*1.2,550*1.2);
	*A = creer_arbre(x,y,blanc);
	afficher(*A);
	
	while(true)
	{
		p = wait_clic();
		if(p.y > 550*1.2)
		{
			i = choisir_menu2(A,i,p); printf("%d \n",i);
		}
		else 
		{
			switch(i) {
			
				case (0) : chercher_arbre(*A,p)->c = blanc; break;
				case (1) : chercher_arbre(*A,p)->c = noir; break;
				case (2) :deviser(chercher_arbre(*A,p)); break;
			}
		}
		afficher(*A);
	}
	
}

