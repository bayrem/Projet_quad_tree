#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"
#include "arbre.h"

POINT creer_point(int x, int y)
{
	POINT p;
	p.x = x;
	p.y = y;
	return p;
}

ARBRE creer_arbre(POINT x, POINT y, COULEUR c)
{
	ARBRE A = (ARBRE) malloc(sizeof(NOEUD));
	A->c = c;
	A->x = x;
	A->y = y;
	A->f1 = NULL;
	A->f2 = NULL;
	A->f3 = NULL;
	A->f4 = NULL;
	
	return A;
}

ARBRE chercher_arbre(ARBRE A, POINT a)
{
	ARBRE Ab = A;
	if(est_noeud(A))
	{
		if(a.x < A->f2->x.x && a.x > A->f1->x.x && a.y > A->f1->x.y && a.y < A->f1->y.y) Ab = chercher_arbre(A->f1,a);
		if(a.x < A->f4->x.x && a.x > A->f3->x.x && a.y < A->f1->x.y && a.y > A->f3->x.y) Ab = chercher_arbre(A->f3,a);
		if(a.x > A->f2->x.x && a.x < A->f2->y.x && a.y > A->f2->x.y && a.y < A->f2->y.y) Ab = chercher_arbre(A->f2,a);
		if(a.x > A->f2->x.x && a.x > A->f1->x.x && a.y < A->f2->x.y && a.y > A->f4->x.y) Ab = chercher_arbre(A->f4,a);
	}
	
	return Ab;
}

BOOL est_noeud(ARBRE A)
{
	if (A->f1 != NULL) return true;
	
	return false;
}

void afficher(ARBRE A)
{
	if(A != NULL)
		draw_fill_rectangle(A->x,A->y, A->c);
	
	if(est_noeud(A))
	{
		draw_fill_rectangle(A->x,A->y,A->c);
		afficher(A->f1);
		afficher(A->f2);
		afficher(A->f3);
		afficher(A->f4);
		draw_line(A->f1->y,A->f4->x,gris);
		draw_line(A->f1->x,A->f4->y,gris);
	}
	
}

void deviser(ARBRE A)
{
	POINT x,y;
	// creation de f1
	x = creer_point(A->x.x, (A->y.y-A->x.y)/2 + A->x.y);
	y = creer_point((A->y.x-A->x.x)/2 + A->x.x, A->y.y);
	A->f1 = creer_arbre(x,y,A->c);
	
	// creation de f2
	x = creer_point((A->y.x-A->x.x)/2 + A->x.x, (A->y.y-A->x.y)/2 + A->x.y);
	y = creer_point(A->y.x, A->y.y);
	A->f2 = creer_arbre(x,y,A->c);
	
	// creation de f3
	x = creer_point(A->x.x, A->x.y);
	y = creer_point((A->y.x-A->x.x)/2 + A->x.x, (A->y.y-A->x.y)/2 + A->x.y);
	A->f3 = creer_arbre(x,y,A->c);
	
	// creation de f4
	x = creer_point((A->y.x-A->x.x)/2 + A->x.x,A->x.y);
	y = creer_point(A->y.x, (A->y.y-A->x.y)/2 + A->x.y);
	A->f4 = creer_arbre(x,y,A->c);
	
}

ARBRE example1()
{
	ARBRE A;
	POINT x,y;
	
	//la creation de la racine
	x = creer_point(10,10);
	y = creer_point(550*1.2,550*1.2);
	A = creer_arbre(x,y,blanc);
	
	//devision
	deviser(A);
	A->f1->c = noir;
	A->f4->c = noir;
	
	return A;
}

ARBRE example2()
{
	
	ARBRE A;
	POINT x,y;
	
	//la creation de la racine
	x = creer_point(10,10);
	y = creer_point(550*1.2,550*1.2);
	A = creer_arbre(x,y,blanc);
	
	//devision
	deviser(A);
	deviser(A->f1);
	A->f1->f2->c = noir;
	A->f1->f3->c = noir;
	A->f2->c = noir;
	deviser(A->f4);
	A->f4->f2->c = noir;
	
	return A;
	
}

ARBRE example3()
{
	
	ARBRE A;
	POINT x,y;
	
	//la creation de la racine
	x = creer_point(10,10);
	y = creer_point(550*1.2,550*1.2);
	A = creer_arbre(x,y,blanc);
	
	//devision
	deviser(A);
	A->f3->c = noir;
	deviser(A->f2);
	A->f2->f2->c = noir;
	deviser(A->f2->f3);
	A->f2->f3->f1->c = noir;
	deviser(A->f4);
	A->f4->f1->c = noir;
	A->f4->f4->c = noir;
	
	return A;
	
}

ARBRE example4()
{
	
	ARBRE A;
	POINT x,y;
	
	//la creation de la racine
	x = creer_point(10,10);
	y = creer_point(550*1.2,550*1.2);
	A = creer_arbre(x,y,blanc);
	
	//devision
	deviser(A);
	A->f3->c = noir;
	deviser(A->f2);
	deviser(A->f2->f1);
	A->f2->f1->f1->c = noir;
	A->f2->f1->f2->c = noir;
	A->f2->f2->c = noir;
	deviser(A->f2->f3);
	A->f2->f3->f1->c = noir;
	deviser(A->f2->f3->f2);
	A->f2->f3->f2->f2->c = noir;
	A->f2->f3->f2->f4->c = noir;
	deviser(A->f2->f3->f4);
	A->f2->f3->f4->f1->c = noir;
	A->f2->f3->f4->f3->c = noir;
	deviser(A->f4);
	A->f4->f2->c = noir;
	A->f4->f3->c = noir;
	
	return A;
	
}
