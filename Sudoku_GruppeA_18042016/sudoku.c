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
    WINDOW *spielfeldFenster, *infoFenster;
    CURSOR cursor = { START_POSITION_SPALTE, START_POSITION_ZEILE, 
                      START_ZEILE, START_SPALTE };
    int elapsedSeconds, gedrueckteTaste;
    char formattedElapsedTime[9];
    time_t startTime, currentTime;

    curs_set(1);
    time(&startTime);

    do
    {
        gedrueckteTaste = getch();

        switch(gedrueckteTaste)
        {
        case KEY_LEFT:
            BewegeCursorLinks(&cursor);
            break;
        case KEY_RIGHT:
            BewegeCursorRechts(&cursor);
            break;
        case KEY_UP:
            BewegeCursorHoch(&cursor);
            break;
        case KEY_DOWN:
            BewegeCursorRunter(&cursor);
            break;
        }

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
        printw("\nX: %i\n", cursor.x);
        printw("\nY: %i\n", cursor.y);
        printw("\nZeile: %i\n", cursor.aktuelleSpielfeldZeile);
        printw("\nSpalte: %i\n", cursor.aktuelleSpielfeldSpalte);

        move(cursor.y, cursor.x);
        refresh();
    }
    while(gedrueckteTaste != 'L' && gedrueckteTaste != 'l');

    clear();
}

void BewegeCursorLinks(CURSOR *cursor)
{
    if(cursor->aktuelleSpielfeldSpalte > 1)
    {
        cursor->x -= OFFSET_SPALTE;

        if(cursor->aktuelleSpielfeldSpalte % 3 == 1)
        {
            cursor->x--;
        }

        cursor->aktuelleSpielfeldSpalte--;
    }
}

void BewegeCursorRechts(CURSOR *cursor)
{
    if(cursor->aktuelleSpielfeldSpalte < 9)
    {
        cursor->x += OFFSET_SPALTE;

        if(cursor->aktuelleSpielfeldSpalte % 3 == 0)
        {
            cursor->x++;
        }

        cursor->aktuelleSpielfeldSpalte++;
    }
}

void BewegeCursorHoch(CURSOR *cursor)
{
    if(cursor->aktuelleSpielfeldZeile > 1)
    {
        cursor->y -= OFFSET_ZEILE;
        cursor->aktuelleSpielfeldZeile--;
    }
}

void BewegeCursorRunter(CURSOR *cursor)
{
    if(cursor->aktuelleSpielfeldZeile < 9)
    {
        cursor->y += OFFSET_ZEILE;
        cursor->aktuelleSpielfeldZeile++;
    }
}