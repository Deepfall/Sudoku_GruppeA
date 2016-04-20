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
    CURSOR cursor = { CURSOR_START_POSITION_SPALTE, CURSOR_START_POSITION_ZEILE, 
        START_ZEILE, START_SPALTE };
    SUDOKUFELD spielfelder[ANZAHL_SPIELFELDER];
    int elapsedSeconds, gedrueckteTaste = -1, i;
    char formattedElapsedTime[9];
    time_t startTime, currentTime;

    curs_set(1);
    timeout(33);

    spielfeldFenster = ErstelleNeuesSpielfeldFenster();
    infoFenster = ErstelleNeuesInfoFenster();
    kommandoFenster = ErstelleNeuesKommandoFenster();

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        if(i % 10 == 0)
        {
            spielfelder[i].iWert = 1;
            spielfelder[i].iIstVorbefuellt = TRUE;
        }
        else
        {
            spielfelder[i].iWert = 0;
            spielfelder[i].iIstVorbefuellt = FALSE;
        }
    }

    ZeicheSpielfeld(spielfeldFenster);
    ZeicheSpielfelder(spielfeldFenster, spielfelder);
    ZeicheKommandos(kommandoFenster);

    time(&startTime);

    while(gedrueckteTaste != 'L' && gedrueckteTaste != 'l')
    {
        gedrueckteTaste = VerarbeiteEingabe(&cursor, spielfelder);

        time(&currentTime);
        elapsedSeconds = (int) difftime(currentTime, startTime);
        getFormattedTime(formattedElapsedTime, elapsedSeconds);

        ZeichneInfo(infoFenster, formattedElapsedTime);

        doupdate();
    }

    delwin(infoFenster);
    delwin(spielfeldFenster);
    delwin(kommandoFenster);
    timeout(-1);
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
    WINDOW *kommandoFenster = newwin(iHoehe, iBreite, iPositionY, iPositionX);

    return kommandoFenster;
}

void ZeicheSpielfeld(WINDOW *spielfeldFenster)
{
    wclear(spielfeldFenster);

    wprintw(spielfeldFenster, "      A       B       C        D       E       F        G       H      I\n");
    wprintw(spielfeldFenster, "  +-------+-------+-------++-------+-------+-------++-------+-------+-------+\n");
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
    wprintw(spielfeldFenster, "  +-------+-------+-------++-------+-------+-------++-------+-------+-------+\n");

    wnoutrefresh(spielfeldFenster);
}

void ZeicheSpielfelder(WINDOW *spielfeldFenster, SUDOKUFELD spielfelder[ANZAHL_SPIELFELDER])
{
    int i = 0, x = START_POSITION_SPALTE, y = START_POSITION_ZEILE;
    char cSpielfeldWertString[11];

    for(i = 0; i <= ANZAHL_SPIELFELDER; i++)
    {
        if(i > 0)
        {
            if(i % 9 == 0)
            {
                x = START_POSITION_SPALTE;
                y += OFFSET_ZEILE;
            }
            else if(i % 3 == 0)
            {
                x += OFFSET_SPALTE + 1;
            }
            else
            {
                x += OFFSET_SPALTE;
            }
        }

        if(spielfelder[i].iWert >= 1 && spielfelder[i].iWert <= 9)
        {
            sprintf(cSpielfeldWertString, "%i", spielfelder[i].iWert);
        }
        else
        {
            strcpy(cSpielfeldWertString, "");
        }

        mvwprintw(spielfeldFenster, y, x, cSpielfeldWertString);
    }

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