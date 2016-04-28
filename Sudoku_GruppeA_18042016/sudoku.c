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
                        Verarbeitet in einer Dauerschleife die Benutzereingaben.
                        Verwaltet die Spielelemente.
*******************************************************************************/
void NeuesSpiel(int iSchwierigkeit, const char ccNickname[])
{
    WINDOW *spielfeldFenster, *infoFenster, *kommandoFenster;
    SUDOKUFELD spielfelder[ANZAHL_SPIELFELDER];
    CURSOR cursor = { CURSOR_START_POSITION_SPALTE, CURSOR_START_POSITION_ZEILE,
                      CURSOR_START_ZEILE, CURSOR_START_SPALTE };
    time_t Startzeit;
    int iGedrueckteTaste = -1, iAnzahlHilfeGenutzt = 0;
    int iSpielGeloest = FALSE;
    char cZeit[9];
    timeout(33);

    // Erstellen der einzelnen Fenster
    spielfeldFenster = ErstelleNeuesSpielfeldFenster();
    infoFenster = ErstelleNeuesInfoFenster();
    kommandoFenster = ErstelleNeuesKommandoFenster();

    // Initialisierung vom Cursor sowie die Befuellung der Spielfelder
    InitialisiereCursor(&cursor);
    BefuelleSpielfelder(spielfelder, iSchwierigkeit);

    // Zeichnen der einzelnen Fenster
    ZeichneSpielfeld(spielfeldFenster);
    ZeichneSpielfelder(spielfeldFenster, spielfelder);
    ZeichneInfo(infoFenster);
    ZeichneKommandos(kommandoFenster);

    // Holen der Startzeit
    time(&Startzeit);

    // Loesungsanzeige oder ein geloestes Spiel als Abbruchbedingung
    while(!iSpielGeloest
          && (iGedrueckteTaste != 'L' && iGedrueckteTaste != 'l'))
    {
        // Entgegennehmen und verarbeiten der gedrueckten Tasten
        iGedrueckteTaste = VerarbeiteEingabe(spielfelder, &cursor,
                                             &iAnzahlHilfeGenutzt);

        ZeichneVerstricheneZeit(infoFenster, Startzeit, iAnzahlHilfeGenutzt);
        ZeichneAnzahlGenutzterHilfe(infoFenster, iAnzahlHilfeGenutzt);

        doupdate(); // Zeichne alles auf einmal neu

        // Ueberpruefung, ob das Sudoku komplett ausgefuellt ist
        if(AlleFelderGefuellt(spielfelder))
        {
            /* Ueberpruefung, ob das ausgefuellte Sudoku mit der Loesung
               uebereinstimmt */
            if(FelderKorrektAusgefuellt(spielfelder))
            {
                // Endzeit berechnen
                BerechneVerstricheneZeit(cZeit, Startzeit, iAnzahlHilfeGenutzt);

                SpielGewonnenMenue(cZeit);

                // Nur wenn eingeloggter Benutzer
                if(strlen(ccNickname) > 0)
                {
                    InBestenlisteEintragenDialog(iSchwierigkeit,
                                                 ccNickname, cZeit);
                }

                iSpielGeloest = TRUE;
            }
            else
            {
                /* Hinweis, dass sich ein Fehler im 
                   ausgefuellten Sudoku befindet */
                mvwprintw(kommandoFenster, 5, 0, "Im Sudoku befindet");
                mvwprintw(kommandoFenster, 6, 0, "sich ein Fehler!");
                wnoutrefresh(kommandoFenster);
            }
        }
    }

    timeout(-1); // Timeout deaktivieren

    // Zeichne die Loesung nur wenn das Spiel nicht vom Benutzer geloest wurde
    if(!iSpielGeloest)
    {
        ZeichneLoesung(spielfeldFenster, spielfelder);
    }

    // Schließen der zuvor erstellten Fenster
    delwin(infoFenster);
    delwin(spielfeldFenster);
    delwin(kommandoFenster);

    clear(); // Bildschirm leeren
}



/*******************************************************************************
Funktion ErstelleNeuesInfoFenster()
Uebergabe Parameter:    -
Rueckgabe:              *infoFenster
Beschreibung:           Erstellt ein neues Fenster fuer die Spielinformationen.
*******************************************************************************/
WINDOW *ErstelleNeuesInfoFenster(void)
{
    int iHoehe = 2, iBreite = 24, iPositionY = 1, iPositionX = 85;
    WINDOW *infoFenster = newwin(iHoehe, iBreite, iPositionY, iPositionX);

    return infoFenster;
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
Funktion ErstelleNeuesKommandoFenster()
Uebergabe Parameter:    -
Rueckgabe:              *kommandoFenster
Beschreibung:           Erstellt ein neues Fenster fuer die Kommandos.
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
Rueckgabe:              -
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

    wrefresh(spielfeldFenster);
}

/*******************************************************************************
Funktion ZeichneSpielfelder()
Uebergabe Parameter:    *spielfeldFenster, spielfelder[]
Rueckgabe:              -
Beschreibung:           Gibt die Spielfelder im uebergebenen Fenster aus.
*******************************************************************************/
void ZeichneSpielfelder(WINDOW *spielfeldFenster, SUDOKUFELD spielfelder[])
{
    int i = 0, x = START_POSITION_SPALTE, y = START_POSITION_ZEILE;
    char cSpielfeldWertString[11];

    // Wenn Farbmodus aktiv
    if(has_colors())
    {
        wattron(spielfeldFenster, COLOR_PAIR(1)); // Faerbe Wert Gruen - Start
    }

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        if(i > 0)
        {
            if(i % 9 == 0)
            {
                // Geh in die naechste Zeile
                x = START_POSITION_SPALTE;
                y += OFFSET_ZEILE;
            }
            else if(i % 3 == 0)
            {
                // Ueberspringe alle 3 Spalten ein zeichen mehr
                x += OFFSET_SPALTE + 1;
            }
            else
            {
                // Geh in die naechste Spalte
                x += OFFSET_SPALTE;
            }
        }

        // Zeichne den Wert in das Feld
        if(spielfelder[i].iWert >= 1 && spielfelder[i].iWert <= 9)
        {
            sprintf(cSpielfeldWertString, "%i", spielfelder[i].iWert);
        }
        else
        {
            strcpy(cSpielfeldWertString, " ");
        }

        mvwprintw(spielfeldFenster, y, x, cSpielfeldWertString);
    }

    wrefresh(spielfeldFenster);

    // Wenn Farbmodus aktiv
    if(has_colors())
    {
        wattroff(spielfeldFenster, COLOR_PAIR(1)); // Faerbe Wert Gruen - Ende
    }
}

/*******************************************************************************
Funktion ZeichneLoesung()
Uebergabe Parameter:    *spielfeldFenster, spielfelder[]
Rueckgabe:              -
Beschreibung:           Gibt die Loesung der Spielfelder im uebergebenen 
                        Fenster aus.
*******************************************************************************/
void ZeichneLoesung(WINDOW *spielfeldFenster, SUDOKUFELD spielfelder[])
{
    int i = 0, x = START_POSITION_SPALTE, y = START_POSITION_ZEILE;

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        if(i > 0)
        {
            if(i % 9 == 0)
            {
                // Geh in die naechste Spalte
                x = START_POSITION_SPALTE;
                y += OFFSET_ZEILE;
            }
            else if(i % 3 == 0)
            {
                // Ueberspringe alle 3 Spalten ein zeichen mehr
                x += OFFSET_SPALTE + 1;
            }
            else
            {
                // Geh in die naechste Spalte
                x += OFFSET_SPALTE;
            }
        }

        // Zeichne den Wert in das Feld
        if(!spielfelder[i].iIstVorbefuellt)
        {
            mvwprintw(spielfeldFenster, y, x, "%i", spielfelder[i].iLoesung);

            wnoutrefresh(spielfeldFenster);
        }
    }

    doupdate();

    getch();
}

/*******************************************************************************
Funktion ZeichneInfo()
Uebergabe Parameter:    *infoFenster
Rueckgabe:              -
Beschreibung:           Gibt die Informationen zum Spiel im uebergebenen
                        Fenster aus.
*******************************************************************************/
void ZeichneInfo(WINDOW *infoFenster)
{
    wclear(infoFenster);

    wprintw(infoFenster, "Zeit:         \n");
    wprintw(infoFenster, "Hilfe genutzt:");

    wrefresh(infoFenster);
}

/*******************************************************************************
Funktion ZeichneKommandos()
Uebergabe Parameter:    *kommandoFenster
Rueckgabe:              -
Beschreibung:           Gibt die waehrend des Spiels verfuegbaren Kommandos 
                        im uebergebenen Fenster aus.
*******************************************************************************/
void ZeichneKommandos(WINDOW *kommandoFenster)
{
    wclear(kommandoFenster);

    wprintw(kommandoFenster, "[H] Hilfe (Feld füllen)\n");
    wprintw(kommandoFenster, "[L] Lösung\n");
    wprintw(kommandoFenster, "[R] Spielregeln\n");

    wrefresh(kommandoFenster);
}

/*******************************************************************************
Funktion ZeichneVerstricheneZeit()
Uebergabe Parameter:    *infoFenster, Startzeit, iAnzahlHilfeGenutzt
Rueckgabe:              -
Beschreibung:           Gibt die waehrend des Spiels verstrichene Zeit im
                        uebergebenen Fenster aus.
*******************************************************************************/
void ZeichneVerstricheneZeit(WINDOW *infoFenster, time_t Startzeit,
                             int iAnzahlHilfeGenutzt)
{
    char cformatierteVerstricheneZeit[9];

    BerechneVerstricheneZeit(cformatierteVerstricheneZeit, Startzeit,
                             iAnzahlHilfeGenutzt);

    // Zeichne den Wert in das Feld
    mvwprintw(infoFenster, 0, 15, cformatierteVerstricheneZeit);

    wnoutrefresh(infoFenster);
}

/*******************************************************************************
Funktion ZeichneAnzahlGenutzterHilfe()
Uebergabe Parameter:    *infoFenster, iAnzahlHilfeGenutzt
Rueckgabe:              -
Beschreibung:           Gibt die Anzahl der waehrend des Spiels genutzte Hilfe
                        im uebergebenen Fenster aus.
*******************************************************************************/
void ZeichneAnzahlGenutzterHilfe(WINDOW *infoFenster, int iAnzahlHilfeGenutzt)
{
    // Zeichne den Wert in das Feld
    mvwprintw(infoFenster, 1, 15, "%i", iAnzahlHilfeGenutzt);

    wnoutrefresh(infoFenster);
}
