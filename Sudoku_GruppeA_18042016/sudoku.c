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

    ZeicheKommandos(kommandoFenster);

    time(&startTime);

    while(gedrueckteTaste != 'L' && gedrueckteTaste != 'l')
    {
        gedrueckteTaste = VerarbeiteEingabe(&cursor, spielfelder);

        time(&currentTime);
        elapsedSeconds = (int) difftime(currentTime, startTime);
        getFormattedTime(formattedElapsedTime, elapsedSeconds);

        ZeichneInfo(infoFenster, formattedElapsedTime);
        ZeicheSpielfeld(spielfeldFenster);

        doupdate();
    }

    delwin(infoFenster);
    delwin(spielfeldFenster);
    delwin(kommandoFenster);
}

WINDOW *ErstelleNeuesSpielfeldFenster(void)
{
    int iHoehe = 38, iBreite = 78, iPositionY = 1, iPositionX = 1;
    WINDOW *spielfeldFenster = newwin(iHoehe, iBreite, iPositionY, iPositionX);

    return spielfeldFenster;
}

WINDOW *ErstelleNeuesInfoFenster(void)
{
    int iHoehe = 2, iBreite = 24, iPositionY = 1, iPositionX = 85;
    WINDOW *infoFenster = newwin(iHoehe, iBreite, iPositionY, iPositionX);

    return infoFenster;
}

WINDOW *ErstelleNeuesKommandoFenster(void)
{
    int iHoehe = 4, iBreite = 24, iPositionY = 4, iPositionX = 85;
    WINDOW *infoFenster = newwin(iHoehe, iBreite, iPositionY, iPositionX);

    return infoFenster;
}

void ZeicheSpielfeld(WINDOW *spielfeldFenster)
{
    wclear(spielfeldFenster);

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

    wnoutrefresh(spielfeldFenster);
}

void ZeichneInfo(WINDOW *infoFenster, char formattedElapsedTime[9])
{
    wclear(infoFenster);

    wprintw(infoFenster, "Zeit:          %s\n", formattedElapsedTime);
    wprintw(infoFenster, "Hilfe genutzt: 0");

    wnoutrefresh(infoFenster);
}

void ZeicheKommandos(WINDOW *kommandoFenster)
{
    wclear(kommandoFenster);

    wprintw(kommandoFenster, "[H] Hilfe (Feld füllen)\n");
    wprintw(kommandoFenster, "[K] Kandidaten anzeigen\n");
    wprintw(kommandoFenster, "[L] Lösung\n");
    wprintw(kommandoFenster, "[R] Spielregeln\n");

    wnoutrefresh(kommandoFenster);
}