/*
Autor(en)               : 
Klasse                  : FA11
Programmname            : .c
Datum                   : ..2016
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

// Allgemein
#define OK                          0
#define TRUE                        1
#define FALSE                       0

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/


/*******************************************************************************
Globale Variablen
*******************************************************************************/


/*******************************************************************************
Funktion main()
*******************************************************************************/
void getFormattedTime(char formattedTime[9], int elapsedSeconds)
{
	int hour = elapsedSeconds / 3600;
	int minutes = (elapsedSeconds / 60) % 60;
	int seconds = elapsedSeconds % 60;
	
	sprintf(formattedTime, "%02d:%02d:%02d", hour, minutes, seconds);
}

int main(void)
{
	int elapsedSeconds, pressedKey;
	char formattedElapsedTime[9];
	time_t startTime, currentTime;
	
    system("MODE CON: COLS=160");
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	timeout(1000);
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
		printw("  +-------+-------+-------++-------+-------+-------++-------+-------+-------+     [H] Hilfe (Feld f�llen)     \n");
		printw("  |       |       |       ||       |       |       ||       |       |       |     [K] Kandidaten anzeigen     \n");
		printw("2 |       |       |       ||       |       |       ||       |       |       |     [L] L�sung                  \n");
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

        move(10, 10);
		
		refresh();
	}
	
	endwin();
	
	return OK;
}

/*******************************************************************************
Funktion ()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/