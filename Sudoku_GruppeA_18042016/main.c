/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Wels, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : .c
Datum                   : 18.04.2016
Beschreibung            : 
Version                 : 
Aenderungen             : 
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE    1

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include "sudoku.h"

// Allgemein
#define TRUE                        1
#define FALSE                       0

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int startMenu();

/*******************************************************************************
Funktion main()
*******************************************************************************/
int main(void)
{
    //initscr();
    system("MODE CON: COLS=80");
    Spielmenue();
    system("pause");

    system("MODE CON: COLS=180");
    NeuesSpiel();

    //system("pause");

    //endwin();

    return EXIT_SUCCESS;
}

/*******************************************************************************
Funktion Spielmenue()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
int Spielmenue(void)
{
    system("MODE CON: COLS=80");
    
    printf("\t\t\t\t\t\t\tS U D O K U\n");
    printf("\t\t\t\t(C) HHBK Tendo Research Center\n");
    printf("\t\t\t\t[N]\tNeues Spiel\n\n");
    printf("\t\t\t\t[R]\tSpielregeln\n\n");
    printf("\t\t\t\t[B]\tBestenregeln\n\n");
    printf("\t\t\t\t[L]\Logout\n\n");
}

/*******************************************************************************
Funktion startMenu()
Uebergabe Parameter:    void
Rueckgabe:              int
Beschreibung:           Erstellt das Startmenü und gibt die Auswahl als Integer
						zurück.
*******************************************************************************/
int startMenu()
{
	printf("\n");
	printf("\t\t\t\tS U D O K U\n\n");
	printf("\t\t\t(C) HHBK Tendo Research Center\n\n");
	printf("\t\t============================================\n\n");
	printf("\t\t\t[E]\tEinloggen\n\n");
	printf("\t\t\t[N]\tNicht einloggen\n\n");
	printf("\t\t\t[R]\tRegistrieren\n\n");
	printf("\t\t\t[X]\tBeenden\n\n");
	printf("\t\t============================================\n\n");

	while(1) {

	};

    return 0;
}