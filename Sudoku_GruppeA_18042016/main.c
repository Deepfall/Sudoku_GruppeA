/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Wels, David Fischer,
Jennifer Hermanns
Klasse                  : FA11
Programmname            : main.c
Datum                   : 18.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE    1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <string.h>
#include "spielmenue.h"
#include "allgemeineDefines.h"

/*******************************************************************************
Funktion main()
*******************************************************************************/
int main(void)
{
    system("MODE CON: COLS=109 LINES=40"); // Festsetzen der Groesse vom Konsolenfenster
    initscr(); 
    cbreak(); // evtl noch rauspacken
    noecho(); // evtl noch rauspacken
    keypad(stdscr, TRUE);
    refresh();

    StartMenue();

    endwin();

    return EXIT_SUCCESS;
}