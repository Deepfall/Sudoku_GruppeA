/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : sudoku.c
Datum                   : 18.04.2016
Beschreibung            : Das eigentliche Spiel wird hier gestartet und
                          auf den Bildschirm ausgegeben.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "sudoku.h"

/*******************************************************************************
Funktion NeuesSpiel()
Uebergabe Parameter:    iSchwierigkeit, ccNickname[]
Rueckgabe:              -
Beschreibung:           Startet ein neues Spiel und initialisiert die dafuer
                        notwendigen Komponenten.
                        Verarbeitet in einer dauerschleife die Benutzereingaben.
                        Verwaltet die Spielelemente.
*******************************************************************************/
void NeuesSpiel(int iSchwierigkeit, const char ccNickname[])
{
    WINDOW *spielfeldFenster, *infoFenster, *kommandoFenster;
    SUDOKUFELD spielfelder[ANZAHL_SPIELFELDER];
    time_t Startzeit;
    int iGedrueckteTaste = -1, iStrafSekunden = 0, iAnzahlHilfeGenutzt = 0;
    int i = 0, iSpielGeloest = FALSE;
    char cZeit[20];
    timeout(33);

    spielfeldFenster = ErstelleNeuesSpielfeldFenster();
    infoFenster = ErstelleNeuesInfoFenster();
    kommandoFenster = ErstelleNeuesKommandoFenster();

    InitialisiereCursor();
    BefuelleSpielfelder(spielfelder, iSchwierigkeit);

    ZeichneSpielfeld(spielfeldFenster);
    ZeichneSpielfelder(spielfeldFenster, spielfelder);
    ZeichneInfo(infoFenster);
    ZeichneKommandos(kommandoFenster);

    time(&Startzeit);

    while(!iSpielGeloest
          && (iGedrueckteTaste != 'L' && iGedrueckteTaste != 'l'))
    {
        iGedrueckteTaste = VerarbeiteEingabe(spielfelder, &iStrafSekunden,
                           &iAnzahlHilfeGenutzt);

        ZeichneVerstricheneZeit(infoFenster, Startzeit, iStrafSekunden);
        ZeichneAnzahlGenutzterHilfe(infoFenster, iAnzahlHilfeGenutzt);

        doupdate();

        if(AlleFelderGefuellt(spielfelder))
        {
            if(!PruefeFelderManuell(spielfelder))
            {
                BerechneVerstricheneZeit(cZeit, Startzeit, iStrafSekunden);
                SpielGewonnenMenue(cZeit);

                if(strlen(ccNickname) > 0)
                {
                    InBestenlisteEintragenDialog(iSchwierigkeit,
                                                 ccNickname, cZeit);
                }

                iSpielGeloest = TRUE;
            }
            else
            {
                mvwprintw(kommandoFenster, 5, 0,"Im Sudoku befindet");
                mvwprintw(kommandoFenster, 6, 0, "sich ein Fehler!");
                wnoutrefresh(kommandoFenster);
            }
        }
    }

    timeout(-1);

    if(!iSpielGeloest)
    {
        ZeichneLoesung(spielfeldFenster, spielfelder);
    }

    delwin(infoFenster);
    delwin(spielfeldFenster);
    delwin(kommandoFenster);
    clear();
}

/*******************************************************************************
Funktion ErstelleNeuesSpielfeldFenster()
Uebergabe Parameter:    -
Rueckgabe:              *spielfeldFenster
Beschreibung:           Erstellt ein neues Fenster fuer das Spielfeld.
*******************************************************************************/
WINDOW *ErstelleNeuesSpielfeldFenster(void)
{
    int iHoehe = 38, iBreite = 78, iPositionY = 1, iPositionX = 1;
    WINDOW *spielfeldFenster = newwin(iHoehe, iBreite, iPositionY, iPositionX);

    return spielfeldFenster;
}

/*******************************************************************************
Funktion ErstelleNeuesInfoFenster()
Uebergabe Parameter:    -
Rueckgabe:              *infoFenster
Beschreibung:           Erstellt ein neues Fenster fuer das Spielfeld.
*******************************************************************************/
WINDOW *ErstelleNeuesInfoFenster(void)
{
    int iHoehe = 2, iBreite = 24, iPositionY = 1, iPositionX = 85;
    WINDOW *infoFenster = newwin(iHoehe, iBreite, iPositionY, iPositionX);

    return infoFenster;
}

/*******************************************************************************
Funktion ErstelleNeuesKommandoFenster()
Uebergabe Parameter:    -
Rueckgabe:              *kommandoFenster
Beschreibung:           Erstellt ein neues Fenster fuer das Spielfeld.
*******************************************************************************/
WINDOW *ErstelleNeuesKommandoFenster(void)
{
    int iHoehe = 30, iBreite = 24, iPositionY = 4, iPositionX = 85;
    WINDOW *kommandoFenster = newwin(iHoehe, iBreite, iPositionY, iPositionX);

    return kommandoFenster;
}

/*******************************************************************************
Funktion ZeichneSpielfeld()
Uebergabe Parameter:    *spielfeldFenster
Rueckgabe:              *spielfeldFenster
Beschreibung:           Gibt das Spielfeld im uebergebenen Fenster aus.
*******************************************************************************/
void ZeichneSpielfeld(WINDOW *spielfeldFenster)
{
    wclear(spielfeldFenster);

    wprintw(spielfeldFenster, "+-------+-------+-------++-------+-------+------"
                              "-++-------+-------+-------+\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "+-------+-------+-------++-------+-------+------"
                              "-++-------+-------+-------+\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "+-------+-------+-------++-------+-------+------"
                              "-++-------+-------+-------+\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|==============================================="
                              "==========================|\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "+-------+-------+-------++-------+-------+------"
                              "-++-------+-------+-------+\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "+-------+-------+-------++-------+-------+------"
                              "-++-------+-------+-------+\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|==============================================="
                              "==========================|\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "+-------+-------+-------++-------+-------+------"
                              "-++-------+-------+-------+\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "+-------+-------+-------++-------+-------+------"
                              "-++-------+-------+-------+\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "|       |       |       ||       |       |      "
                              " ||       |       |       |\n");
    wprintw(spielfeldFenster, "+-------+-------+-------++-------+-------+------"
                              "-++-------+-------+-------+\n");

    wnoutrefresh(spielfeldFenster);
}

/*******************************************************************************
Funktion ZeichneSpielfelder()
Uebergabe Parameter:    *spielfeldFenster, spielfelder[]
Rueckgabe:              *spielfeldFenster, spielfelder[]
Beschreibung:           Gibt die Spielfelder im uebergebenen Fenster aus.
*******************************************************************************/
void ZeichneSpielfelder(WINDOW *spielfeldFenster, SUDOKUFELD spielfelder[])
{
    int i = 0, x = START_POSITION_SPALTE, y = START_POSITION_ZEILE;
    char cSpielfeldWertString[11];

    wattron(spielfeldFenster, A_BOLD);

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
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

/*******************************************************************************
Funktion ZeichneLoesung()
Uebergabe Parameter:    *spielfeldFenster, spielfelder[]
Rueckgabe:              *spielfeldFenster, spielfelder[]
Beschreibung:           Gibt die Loesung der Spielfelder im uebergebenen 
Fenster aus.
*******************************************************************************/
void ZeichneLoesung(WINDOW *spielfeldFenster, SUDOKUFELD spielfelder[])
{
    int i = 0, x = START_POSITION_SPALTE, y = START_POSITION_ZEILE;
    char cSpielfeldWertString[11];

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
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

        if(!spielfelder[i].iIstVorbefuellt)
        {
            sprintf(cSpielfeldWertString, "%i", spielfelder[i].iLoesung);
            mvwprintw(spielfeldFenster, y, x, cSpielfeldWertString);
        }
    }

    wnoutrefresh(spielfeldFenster);

    getch();
}

/*******************************************************************************
Funktion ZeichneInfo()
Uebergabe Parameter:    *infoFenster
Rueckgabe:              *infoFenster
Beschreibung:           Gibt die Informationen zum Spiel im uebergebenen
                        Fenster aus.
*******************************************************************************/
void ZeichneInfo(WINDOW *infoFenster)
{
    wclear(infoFenster);

    wprintw(infoFenster, "Zeit:          \n");
    wprintw(infoFenster, "Hilfe genutzt: 0");

    wnoutrefresh(infoFenster);
}

/*******************************************************************************
Funktion ZeichneKommandos()
Uebergabe Parameter:    *kommandoFenster
Rueckgabe:              *kommandoFenster
Beschreibung:           Gibt die waehrend des Spiels verfuegbaren Kommandos 
                        im uebergebenen Fenster aus.
*******************************************************************************/
void ZeichneKommandos(WINDOW *kommandoFenster)
{
    wclear(kommandoFenster);

    wprintw(kommandoFenster, "[H] Hilfe (Feld füllen)\n");
    wprintw(kommandoFenster, "[L] Lösung\n");
    wprintw(kommandoFenster, "[R] Spielregeln\n");

    wnoutrefresh(kommandoFenster);
}

/*******************************************************************************
Funktion ZeichneVerstricheneZeit()
Uebergabe Parameter:    *infoFenster, Startzeit, iStrafSekunden
Rueckgabe:              *infoFenster
Beschreibung:           Gibt die waehrend des Spiels verstrichene Zeit im
                        uebergebenen Fenster aus.
*******************************************************************************/
void ZeichneVerstricheneZeit(WINDOW *infoFenster, time_t Startzeit,
                             int iStrafSekunden)
{
    char cformatierteVerstricheneZeit[9];

    BerechneVerstricheneZeit(cformatierteVerstricheneZeit, Startzeit,
                             iStrafSekunden);

    mvwprintw(infoFenster, 0, 15, cformatierteVerstricheneZeit);

    wnoutrefresh(infoFenster);
}

/*******************************************************************************
Funktion ZeichneAnzahlGenutzterHilfe()
Uebergabe Parameter:    *infoFenster, iAnzahlGenutzterHilfe
Rueckgabe:              *infoFenster
Beschreibung:           Gibt die Anzahl der waehrend des Spiels genutzte Hilfe
                        im uebergebenen Fenster aus.
*******************************************************************************/
void ZeichneAnzahlGenutzterHilfe(WINDOW *infoFenster, int iAnzahlGenutzterHilfe)
{
    mvwprintw(infoFenster, 1, 15, "%i", iAnzahlGenutzterHilfe);

    wnoutrefresh(infoFenster);
}
