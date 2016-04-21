/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
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

#include <curses.h>
#include "spielmenue.h"
#include "allgemeineDefines.h"

/*******************************************************************************
Funktion main()
*******************************************************************************/
int main(void)
{
    // Festsetzen der Groesse des Konsolenfensters
    system("MODE CON: COLS=109 LINES=40");
    
    // Initialisiere curses.h
    initscr();

    // Starte Farbmodus
    start_color();

    cbreak(); // evtl noch rauspacken
    noecho(); // evtl noch rauspacken

    // Aktiviere Tasten wie "Entf" und F-Tasten
    keypad(stdscr, TRUE);

    // Initiales aktualisieren des Outputs
    refresh();

    StartMenue();

    // Aufraeumen der curses.h Fenster
    endwin();

    return EXIT_SUCCESS;
}