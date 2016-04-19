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

/*******************************************************************************
Funktion NeuesSpiel()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void NeuesSpiel(void)
{
    WINDOW *spielfeldFenster, *infoFenster, *kommandoFenster;
    CURSOR cursor = { START_POSITION_SPALTE, START_POSITION_ZEILE, 
                      START_ZEILE, START_SPALTE };
    SUDOKUFELD spielfelder[81];
    int elapsedSeconds, gedrueckteTaste = -1;
    char formattedElapsedTime[9];
    time_t startTime, currentTime;

    curs_set(2);
    timeout(33);

    spielfeldFenster = ErstelleNeuesSpielfeldFenster();
    infoFenster = ErstelleNeuesInfoFenster();
    kommandoFenster = ErstelleNeuesKommandoFenster();

    wclear(kommandoFenster);
    wprintw(kommandoFenster, "[H] Hilfe (Feld füllen)\n");
    wprintw(kommandoFenster, "[K] Kandidaten anzeigen\n");
    wprintw(kommandoFenster, "[L] Lösung\n");
    wprintw(kommandoFenster, "[R] Spielregeln\n");
    wnoutrefresh(kommandoFenster);

    time(&startTime);

    while(gedrueckteTaste != 'L' && gedrueckteTaste != 'l')
    {
        gedrueckteTaste = VerarbeiteEingabe(&cursor, spielfelder);

        time(&currentTime);
        elapsedSeconds = (int) difftime(currentTime, startTime);
        getFormattedTime(formattedElapsedTime, elapsedSeconds);

        wprintw(infoFenster, "Zeit:          %s\n", formattedElapsedTime);
        wprintw(infoFenster, "Hilfe genutzt: 0\n\n");
        wnoutrefresh(infoFenster);

        wprintw(spielfeldFenster, "      A       B       C        D       E       F        G       H      I\n");
        wprintw(spielfeldFenster, "  +-------+-------+----------------+-------+----------------+-------+-------+\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "1 |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  +-------+-------+-------++-------+-------+-------++-------+-------+-------+\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "2 |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  +-------+-------+-------++-------+-------+-------++-------+-------+-------+\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "3 |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |=========================================================================|\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "4 |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  +-------+-------+-------++-------+-------+-------++-------+-------+-------+\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "5 |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  +-------+-------+-------++-------+-------+-------++-------+-------+-------+\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "6 |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |=========================================================================|\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "7 |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  +-------+-------+-------++-------+-------+-------++-------+-------+-------+\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "8 |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  +-------+-------+-------++-------+-------+-------++-------+-------+-------+\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "9 |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  |       |       |       ||       |       |       ||       |       |       |\n");
        wprintw(spielfeldFenster, "  +-------+-------+----------------+-------+----------------+-------+-------+\n");
        wprintw(spielfeldFenster, "X: %i\n", cursor.iX);
        wprintw(spielfeldFenster, "Y: %i\n", cursor.iY);
        wprintw(spielfeldFenster, "Zeile: %i\n", cursor.iAktuelleSpielfeldZeile);
        wprintw(spielfeldFenster, "Spalte: %i\n", cursor.iAktuelleSpielfeldSpalte);
        wnoutrefresh(spielfeldFenster);

        wclear(spielfeldFenster);
        wclear(infoFenster);
        doupdate();
    }
}

WINDOW *ErstelleNeuesSpielfeldFenster(void)
{
    int iHoehe = 47, iBreite = 78, 
        iStartY = 1, iStartX = 1;
    WINDOW *spielfeldFenster = newwin(iHoehe, iBreite, iStartY, iStartX);

    return spielfeldFenster;
}

WINDOW *ErstelleNeuesInfoFenster(void)
{
    int iHoehe = 2, iBreite = 24, 
        iStartY = 1, iStartX = 85;
    WINDOW *infoFenster = newwin(iHoehe, iBreite, iStartY, iStartX);

    return infoFenster;
}

WINDOW *ErstelleNeuesKommandoFenster(void)
{
    int iHoehe = 44, iBreite = 24, 
        iStartY = 4, iStartX = 85;
    WINDOW *infoFenster = newwin(iHoehe, iBreite, iStartY, iStartX);

    return infoFenster;
}