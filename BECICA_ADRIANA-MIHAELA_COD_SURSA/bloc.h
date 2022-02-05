#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <conio.h>
#ifndef BLOC_H_INCLUDED
#define BLOC_H_INCLUDED
typedef char LOGIC;
#define ADEVARAT 1
#define FALS 0

typedef struct persoane{
        int cnp;
        char *nume;
        char *prenume;
}PERSOANE; // utilizare rapida a lui typedef

typedef struct bloc BLOC;
LOGIC adaugarepersoane (char *numeFisier, PERSOANE *p, int m);
LOGIC schimbare (char *numeFisier, BLOC *b, int n,int a,int x,int y);
BLOC* citire_informatii_bloc(int *n);

void afisare(BLOC *p, int n);
void afis(BLOC *p, int n);
void harta();
void mainmenu();


void afisareMeniu();
PERSOANE citirepersoana ();

PERSOANE* citirepersoane (char *numeFisier, int *m);


void afisarepersoane(PERSOANE *p, int m);


PERSOANE* adaugarepersoanamemorie(PERSOANE *p, int *n, PERSOANE p1);
#endif // BLOC_H_INCLUDED
