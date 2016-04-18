/*
Autor(en)               : David Fischer
Klasse                  : FA11
Programmname            : sudoku.c
Datum                   : 18.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "sudoku.h"
#include "spielfeld.h"

/*******************************************************************************
Funktion NeuesSpiel()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void NeuesSpiel(void)
{
    int elapsedSeconds, pressedKey;
	char formattedElapsedTime[9];
	time_t startTime, currentTime;
	
    

	
	
	time(&startTime);
	
	while(1) {
		pressedKey = getch();
	
		clear();
		time(&currentTime);
		elapsedSeconds = (int) difftime(currentTime, startTime);
		getFormattedTime(formattedElapsedTime, elapsedSeconds);
		
		printw("      A       B       C        D       E       F        G       H      I                                      \n");
		printw("  +-------+-------+----------------+-------+----------------+-------+-------+                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |     Zeit:          %s     \n", formattedElapsedTime);
        printw("1 |       |       |       ||       |       |       ||       |       |       |     Hilfe genutzt: 0            \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  +-------+-------+-------++-------+-------+-------++-------+-------+-------+     [H] Hilfe (Feld füllen)     \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |     [K] Kandidaten anzeigen     \n");
        printw("2 |       |       |       ||       |       |       ||       |       |       |     [L] Lösung                  \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |     [R] Spielregeln             \n");
        printw("  +-------+-------+-------++-------+-------+-------++-------+-------+-------+                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("3 |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  |=========================================================================|                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("4 |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  +-------+-------+-------++-------+-------+-------++-------+-------+-------+                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("5 |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  +-------+-------+-------++-------+-------+-------++-------+-------+-------+                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("6 |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  |=========================================================================|                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("7 |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  +-------+-------+-------++-------+-------+-------++-------+-------+-------+                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("8 |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  +-------+-------+-------++-------+-------+-------++-------+-------+-------+                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("9 |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  |       |       |       ||       |       |       ||       |       |       |                                 \n");
        printw("  +-------+-------+----------------+-------+----------------+-------+-------+                                 \n");

        printw("Pressed key: %d", pressedKey);

        refresh();
    }

    
}