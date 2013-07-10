#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphics.h"
#include "arbre.h"
#include "mode_creation.h"
#include "mode_manipulation.h"

//fonction de test
char* cououleur(ARBRE A)
{
	switch(A->c)
	{
		case(noir) : return "noir";
		case(blanc) : return"blanc";
	}
	return "erreur";
}

void menu()
{
	POINT x,y,p;
	
	//creation de option1
	x = creer_point(10*1.2,580*1.2);
	y = creer_point(110*1.2,630*1.2);
	p = creer_point(13*1.2,620*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("NOUVEAU", 19, p, rouge);
	
	//creation de option2
	x = creer_point(150*1.2,580*1.2);
	y = creer_point(250*1.2,630*1.2);
	p = creer_point(175*1.2,620*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("A1", 30, p, rouge);
	
	//creation de option3
	x = creer_point(290*1.2,580*1.2);
	y = creer_point(390*1.2,630*1.2);
	p = creer_point(315*1.2,620*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("A2", 30, p, rouge);
	
	//creation de option4
	x = creer_point(430*1.2,580*1.2);
	y = creer_point(530*1.2,630*1.2);
	p = creer_point(455*1.2,620*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("A3", 30, p, rouge);
	
	//creation de option5
	x = creer_point(580*1.2,580*1.2);
	y = creer_point(680*1.2,630*1.2);
	p = creer_point(605*1.2,620*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("A4", 30, p, rouge);
	
	//creation de option6
	x = creer_point(580*1.2,500*1.2);
	y = creer_point(680*1.2,550*1.2);
	p = creer_point(585*1.2,540*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("TO STRING", 16, p, rouge);
	
	//creation de option7
	x = creer_point(580*1.2,400*1.2);
	y = creer_point(680*1.2,450*1.2);
	p = creer_point(587*1.2,440*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("ROTATION", 16, p, rouge);
	
	//creation de option8
	x = creer_point(580*1.2,300*1.2);
	y = creer_point(680*1.2,350*1.2);
	p = creer_point(583*1.2,340*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("INVERSION", 16, p, rouge);
	
	//creation de option9
	x = creer_point(580*1.2,200*1.2);
	y = creer_point(680*1.2,250*1.2);
	p = creer_point(597*1.2,240*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("FUSION", 16, p, rouge);
	
	//creation de option10
	x = creer_point(580*1.2,100*1.2);
	y = creer_point(680*1.2,150*1.2);
	p = creer_point(603*1.2,140*1.2);
	draw_rectangle(x,y, rouge);
	aff_pol("CHUTE", 16, p, rouge);
}

void chute(ARBRE* A)
{
	ARBRE tmp;
	if(est_noeud(*A))
	{
		
		//Manipulation f1 f3
		if(!est_noeud((*A)->f1) && !est_noeud((*A)->f3))
		{
			if((*A)->f3->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f1));
				copier_arbre(&((*A)->f1),&((*A)->f3));
				copier_arbre(&((*A)->f3),&tmp);
			}
		}
		
		if(est_noeud((*A)->f1) && !est_noeud((*A)->f3))
		{
			chute(&((*A)->f1));
			if((*A)->f3->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f1));
				copier_arbre(&((*A)->f1),&((*A)->f3));
				copier_arbre(&((*A)->f3),&tmp);
			}
		}
		
		if(!est_noeud((*A)->f1) && est_noeud((*A)->f3))
		{
			chute(&((*A)->f3));
			
			if((*A)->f1->c == noir)
			{
				copier_arbre(&tmp,&((*A)->f1));
				copier_arbre(&((*A)->f1),&((*A)->f3));
				copier_arbre(&((*A)->f3),&tmp);
			}
			
		}
		
		if(est_noeud((*A)->f1) && est_noeud((*A)->f3))
		{
			chute(&((*A)->f1));
			chute(&((*A)->f3));
			
			if((*A)->f3->f3->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f1->f3));
				copier_arbre(&((*A)->f1->f3),&((*A)->f3->f3));
				copier_arbre(&((*A)->f3->f3),&tmp);
				
				copier_arbre(&tmp,&((*A)->f1->f1));
				copier_arbre(&((*A)->f1->f1),&((*A)->f3->f1));
				copier_arbre(&((*A)->f3->f1),&tmp);
			}
			
			if((*A)->f3->f3->c == noir && (*A)->f3->f1->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f1->f3));
				copier_arbre(&((*A)->f1->f3),&((*A)->f3->f1));
				copier_arbre(&((*A)->f3->f1),&tmp);
			}
			
			if((*A)->f3->f4->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f1->f4));
				copier_arbre(&((*A)->f1->f4),&((*A)->f3->f4));
				copier_arbre(&((*A)->f3->f4),&tmp);
				
				copier_arbre(&tmp,&((*A)->f1->f2));
				copier_arbre(&((*A)->f1->f2),&((*A)->f3->f2));
				copier_arbre(&((*A)->f3->f2),&tmp);
			}
			
			if((*A)->f3->f4->c == noir && (*A)->f3->f2->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f1->f4));
				copier_arbre(&((*A)->f1->f4),&((*A)->f3->f2));
				copier_arbre(&((*A)->f3->f2),&tmp);
			}
			chute(&((*A)->f1));
			chute(&((*A)->f3));
		}
		
		//Manipulation f2 f4
		if(!est_noeud((*A)->f2) && !est_noeud((*A)->f4))
		{
			if((*A)->f4->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f2));
				copier_arbre(&((*A)->f2),&((*A)->f4));
				copier_arbre(&((*A)->f4),&tmp);
			}
		}
		
		if(est_noeud((*A)->f2) && !est_noeud((*A)->f4))
		{
			chute(&((*A)->f2));
			if((*A)->f4->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f2));
				copier_arbre(&((*A)->f2),&((*A)->f4));
				copier_arbre(&((*A)->f4),&tmp);
			}
		}
		
		if(!est_noeud((*A)->f2) && est_noeud((*A)->f4))
		{
			chute(&((*A)->f4));
			
			if((*A)->f2->c == noir)
			{
				copier_arbre(&tmp,&((*A)->f2));
				copier_arbre(&((*A)->f2),&((*A)->f4));
				copier_arbre(&((*A)->f4),&tmp);
			}
			
		}
		
		if(est_noeud((*A)->f2) && est_noeud((*A)->f4))
		{
			chute(&((*A)->f2));
			chute(&((*A)->f4));
			
			if((*A)->f4->f3->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f2->f3));
				copier_arbre(&((*A)->f2->f3),&((*A)->f4->f3));
				copier_arbre(&((*A)->f4->f3),&tmp);
				
				copier_arbre(&tmp,&((*A)->f2->f1));
				copier_arbre(&((*A)->f2->f1),&((*A)->f4->f1));
				copier_arbre(&((*A)->f4->f1),&tmp);
			}
			
			if((*A)->f4->f3->c == noir && (*A)->f4->f1->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f2->f3));
				copier_arbre(&((*A)->f2->f3),&((*A)->f4->f1));
				copier_arbre(&((*A)->f4->f1),&tmp);
			}
			
			if((*A)->f4->f4->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f2->f4));
				copier_arbre(&((*A)->f2->f4),&((*A)->f4->f4));
				copier_arbre(&((*A)->f4->f4),&tmp);
				
				copier_arbre(&tmp,&((*A)->f2->f2));
				copier_arbre(&((*A)->f2->f2),&((*A)->f4->f2));
				copier_arbre(&((*A)->f4->f2),&tmp);
			}
			
			if((*A)->f4->f4->c == noir && (*A)->f4->f2->c != noir)
			{
				copier_arbre(&tmp,&((*A)->f2->f4));
				copier_arbre(&((*A)->f2->f4),&((*A)->f4->f2));
				copier_arbre(&((*A)->f4->f2),&tmp);
			}
			chute(&((*A)->f2));
			chute(&((*A)->f4));
		}
		
	}
	fusion(A);
}

void copier_arbre(ARBRE* A, ARBRE* B)
{
	POINT x,y;
	x = (*A)->x;
	y = (*A)->y;
	
	if(!est_noeud(*A) && !est_noeud(*B))
	{
		(*A)->c = (*B)->c;
	}
	
	else if(est_noeud(*A) && !est_noeud(*B))
	{
		*A = creer_arbre(x,y,(*B)->c);
	}
	
	else
	{
		*A = creer_arbre(x,y,(*B)->c);
		deviser(*A);
		copier_arbre(&((*A)->f1),&((*B)->f1));
		copier_arbre(&((*A)->f2),&((*B)->f2));
		copier_arbre(&((*A)->f3),&((*B)->f3));
		copier_arbre(&((*A)->f4),&((*B)->f4));
	}

}

void fusion(ARBRE* A)
{

if(est_noeud(*A))
{
	
	if(est_noeud((*A)->f1) || est_noeud((*A)->f2) || est_noeud((*A)->f3) || 
	est_noeud((*A)->f4))
	{
		fusion(&(*A)->f1);
		fusion(&(*A)->f2);
		fusion(&(*A)->f3);
		fusion(&(*A)->f4);
	}
	
	if(!est_noeud((*A)->f1) && !est_noeud((*A)->f2) && !est_noeud((*A)->f3) && 
	!est_noeud((*A)->f4))
	{
		if((*A)->f1->c == (*A)->f2->c && (*A)->f1->c == (*A)->f3->c && 
		(*A)->f1->c == (*A)->f4->c)
		{
			(*A)->c = (*A)->f1->c;
			free((*A)->f1);
			free((*A)->f2);
			free((*A)->f3);
			free((*A)->f4);
			(*A)->f1 = NULL;
			(*A)->f2 = NULL;
			(*A)->f3 = NULL;
			(*A)->f4 = NULL;
		}
	}
	}
}


// a verifier
void rotation90(ARBRE* A)
{
	ARBRE tmp;
	
	if(est_noeud(*A))
	{
		if(est_noeud((*A)->f1) || est_noeud((*A)->f2) || est_noeud((*A)->f3) || 
		est_noeud((*A)->f4))
		{
			rotation90(&(*A)->f1);
			rotation90(&(*A)->f2);
			rotation90(&(*A)->f3);
			rotation90(&(*A)->f4);
		}
		
		copier_arbre(&tmp,&((*A)->f1));
		copier_arbre(&((*A)->f1),&((*A)->f3));
		copier_arbre(&((*A)->f3),&((*A)->f4));
		copier_arbre(&((*A)->f4),&((*A)->f2));
		copier_arbre(&((*A)->f2),&tmp);
		
	}
}


//a verifier
void inverser(ARBRE* A)
{
	ARBRE tmp;
	//POINT x,y,x1,y1;
	
	if(est_noeud(*A))
	{
		
		if(est_noeud((*A)->f1) || est_noeud((*A)->f2) || est_noeud((*A)->f3) || 
		est_noeud((*A)->f4))
		{
			inverser(&(*A)->f1);
			inverser(&(*A)->f2);
			inverser(&(*A)->f3);
			inverser(&(*A)->f4);
		}
		
		copier_arbre(&tmp,&((*A)->f1));
		copier_arbre(&((*A)->f1),&((*A)->f3));
		copier_arbre(&((*A)->f3),&tmp);
		
		copier_arbre(&tmp,&((*A)->f2));
		copier_arbre(&((*A)->f2),&((*A)->f4));
		copier_arbre(&((*A)->f4),&tmp);
		
	}
}

char* toString(ARBRE A)
{
	char c[250] = "";
	char* b;
	
	if(!est_noeud(A))
	{
		switch(A->c) 
		{
			case(noir) : strcat(c,"n"); break;
			case(blanc) : strcat(c,"b"); break;
		}
	}
	
	else if (est_noeud(A))
	{
		strcat(c,"D");
		strcat(c,toString(A->f1));
		strcat(c,toString(A->f2));
		strcat(c,toString(A->f3));
		strcat(c,toString(A->f4));
	}
	
	b = c;
	
	return b;
}

void choisir_menu(ARBRE* A,POINT a)
{
	
	if (a.x < 110*1.2 && a.y < 630*1.2 && a.x > 10*1.2 && a.y > 580*1.2) {printf("%s\n","menu1 Nouveau"); mode_creation(A); }
	else if (a.x < 250*1.2 && a.y < 630*1.2 && a.x > 150*1.2 && a.y > 580*1.2) {printf("%s\n","Example 1"); *A = example1();}
	else if (a.x < 390*1.2 && a.y < 630*1.2 && a.x > 290*1.2 && a.y > 580*1.2) {printf("%s\n","Example 2");*A = example2();}
	else if (a.x < 530*1.2 && a.y < 630*1.2 && a.x > 430*1.2 && a.y > 580*1.2) {printf("%s\n","Example 3");*A = example3();}
	else if (a.x < 680*1.2 && a.y < 630*1.2 && a.x > 580*1.2 && a.y > 580*1.2) {printf("%s\n","Example 4");*A = example4();}
	else if (a.x < 680*1.2 && a.y < 550*1.2 && a.x > 580*1.2 && a.y > 500*1.2) {printf("%s\n","TO String");printf("%s\n",toString(*A));}
	else if (a.x < 680*1.2 && a.y < 450*1.2 && a.x > 580*1.2 && a.y > 400*1.2) {printf("%s\n","Rotation90");rotation90(A);}
	else if (a.x < 680*1.2 && a.y < 350*1.2 && a.x > 580*1.2 && a.y > 300*1.2) {printf("%s\n","Inversion"); inverser(A);}
	else if (a.x < 680*1.2 && a.y < 250*1.2 && a.x > 580*1.2 && a.y > 200*1.2) {printf("%s\n","Fusion"); fusion(A);}
	else if (a.x < 680*1.2 && a.y < 150*1.2 && a.x > 580*1.2 && a.y > 100*1.2) {printf("%s\n","Chute"); chute(A);}
	
}

void mode_manipulation(ARBRE* A)
{
	POINT x,y,p;
	fill_screen(noir);
	menu();
	
	//creation de la fenetre grise
	x = creer_point(0,0);
	y = creer_point(560*1.2,560*1.2);
	draw_fill_rectangle(x,y, gris);
	
	afficher(*A);
	
	
	while(true)
	{
		p = wait_clic();
		choisir_menu(A,p);
		afficher(*A);
	}
}
