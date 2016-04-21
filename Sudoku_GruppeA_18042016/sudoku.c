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
Uebergabe Parameter:    iSchwierigkeit
Rueckgabe:              -
Beschreibung:           
*******************************************************************************/
void NeuesSpiel(int iSchwierigkeit)
{
    WINDOW *spielfeldFenster, *infoFenster, *kommandoFenster;
    SUDOKUFELD spielfelder[ANZAHL_SPIELFELDER];
    time_t Startzeit;
    int iGedrueckteTaste = -1, i, iWert;
    char cDaten[1000], *cToken;
    const char *ccTrenner = ";";

    timeout(33);

    spielfeldFenster = ErstelleNeuesSpielfeldFenster();
    infoFenster = ErstelleNeuesInfoFenster();
    kommandoFenster = ErstelleNeuesKommandoFenster();

    SudokuBereitstellen(cDaten, iSchwierigkeit);
    cToken = strtok(cDaten, ccTrenner);

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        if(cToken != NULL && cToken[0] >= '1' && cToken[0] <= '9')
        {
            iWert = (int) cToken[0] - 48;
            spielfelder[i].iWert = iWert;
            spielfelder[i].iIstVorbefuellt = TRUE;
        }
        else
        {
            spielfelder[i].iWert = 0;
            spielfelder[i].iIstVorbefuellt = FALSE;
        }

        cToken = strtok(NULL, ccTrenner);
    }

    InitialisiereCursor();
    ZeicheSpielfeld(spielfeldFenster);
    ZeicheSpielfelder(spielfeldFenster, spielfelder);
    ZeichneInfo(infoFenster);
    ZeicheKommandos(kommandoFenster);

    time(&Startzeit);

    while(iGedrueckteTaste != 'L' && iGedrueckteTaste != 'l')
    {
        iGedrueckteTaste = VerarbeiteEingabe(spielfelder);

        ZeicheVerstricheneZeit(infoFenster, Startzeit);

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

    wattron(spielfeldFenster, A_BOLD);

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

    wattroff(spielfeldFenster, A_BOLD);

    wnoutrefresh(spielfeldFenster);
}

void ZeichneInfo(WINDOW *infoFenster)
{
    wclear(infoFenster);

    wprintw(infoFenster, "Zeit:          \n");
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

void ZeicheVerstricheneZeit(WINDOW *infoFenster, time_t Startzeit)
{
    char cformatierteVerstricheneZeit[9];

    BerechneVerstricheneZeit(cformatierteVerstricheneZeit, Startzeit);

    mvwprintw(infoFenster, 0, 15, cformatierteVerstricheneZeit);

    wnoutrefresh(infoFenster);
}