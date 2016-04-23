/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : main.c
Datum                   : 18.04.2016
Beschreibung            : Startet das Spielmenue fuer das Sudokuspiel und
                          initialisiert die curses Biliothek.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE    1

#include <stdlib.h>
#pragma warning(push, 0)
#include <curses.h>
#pragma warning(pop)
#include "allgemeineDefines.h"
#include "spielmenue.h"

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
    
    // Aktiviere Tasten wie "Esc", "Entf" und F-Tasten
    keypad(stdscr, TRUE);

    // Initiales aktualisieren des Outputs
    refresh();

    Startmenue();

    // Aufraeumen der curses.h Fenster
    endwin();

    return EXIT_SUCCESS;
}