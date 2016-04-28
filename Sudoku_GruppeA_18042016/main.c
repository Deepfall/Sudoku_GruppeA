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
#include "allgemeineDefines.h"
#include <stdlib.h>
#pragma warning(push, 0) // Vermeide Warnungen ab hier
#include <curses.h> // Muss unter Unix-System durch ncurses.h ersetzt werden
#pragma warning(pop) // Vermeide Warnungen bis hier
#include "spielmenue.h"

/*******************************************************************************
Funktion main()
Beschreibung:           Startet das Spielmenue fuer das Sudokuspiel und
                        initialisiert die curses Biliothek.
*******************************************************************************/
int main(void)
{
    // Initialisiere curses.h
    initscr();

    // Initialisiere Farbmodus, wenn moeglich
    if(has_colors())
    {
        start_color();
        init_pair(1, COLOR_GREEN, COLOR_BLACK); // Vorbefuellte Felder
        init_pair(2, COLOR_YELLOW, COLOR_BLACK); // Mit Hilfe befuellte Felder
    }

    // Aktiviere "Entf"-Taste
    keypad(stdscr, TRUE);

    // Festsetzen der Groesse des Konsolenfensters
    resize_term(40, 109);

    // Initiales aktualisieren des Outputs
    refresh();

    Startmenue();

    // Aufraeumen der curses.h Fenster
    endwin();

    return EXIT_SUCCESS;
}