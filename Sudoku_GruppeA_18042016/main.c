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

// Allgemein
#define OK                          0
#define TRUE                        1
#define FALSE                       0

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void getFormattedTime(char formattedTime[9], int elapsedSeconds);
int startMenu();


/*******************************************************************************
Globale Variablen
*******************************************************************************/


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
    clear();
    Spielfeld();

    //system("pause");

    //endwin();
}

/*******************************************************************************
Funktion getFormattedTime()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void getFormattedTime(char formattedTime[9], int elapsedSeconds)
{
	int hour = elapsedSeconds / 3600;
	int minutes = (elapsedSeconds / 60) % 60;
	int seconds = elapsedSeconds % 60;
	
	sprintf(formattedTime, "%02d:%02d:%02d", hour, minutes, seconds);
}

/*******************************************************************************
Funktion Spielfeld()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
int Spielfeld(void)
{
	int elapsedSeconds, pressedKey;
	char formattedElapsedTime[9];
	time_t startTime, currentTime;
	
    //system("MODE CON: COLS=160");

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

        move(10, 10);

        refresh();
    }

    endwin();

    return OK;
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