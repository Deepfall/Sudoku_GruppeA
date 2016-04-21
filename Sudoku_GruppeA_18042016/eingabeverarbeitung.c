/*
Autor(en)               : David Fischer
Klasse                  : FA11
Programmname            : eingabeverarbeitung.c
Datum                   : 19.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "eingabeverarbeitung.h"

/*******************************************************************************
Funktion VerarbeiteEingabe()
Uebergabe Parameter:    sudokufeld[]
Rueckgabe:              -
Beschreibung:           
*******************************************************************************/
int VerarbeiteEingabe(SUDOKUFELD sudokufelder[], int *iStrafSekunden,
                      int *iAnzahlHilfeGenutzt)
{
    static CURSOR cursor = { CURSOR_START_POSITION_SPALTE,
                             CURSOR_START_POSITION_ZEILE,
                             CURSOR_START_ZEILE, CURSOR_START_SPALTE };

    int gedrueckteTaste = getch();

    VerarbeiteCursorBewegung(gedrueckteTaste, &cursor);
    VerarbeiteFeldEingabe(gedrueckteTaste, cursor, sudokufelder);
    VerarbeiteKommandos(gedrueckteTaste, cursor, sudokufelder, iStrafSekunden,
                        iAnzahlHilfeGenutzt);

    return gedrueckteTaste;
}

/*******************************************************************************
Funktion VerarbeiteCursorBewegung()
Uebergabe Parameter:    iGedrueckteTaste, cursor
Rueckgabe:              -
Beschreibung:           
*******************************************************************************/
void VerarbeiteCursorBewegung(int iGedrueckteTaste, CURSOR *cursor)
{
    switch(iGedrueckteTaste)
    {
        case KEY_LEFT:
            BewegeCursorLinks(cursor);
            break;
        case KEY_RIGHT:
            BewegeCursorRechts(cursor);
            break;
        case KEY_UP:
            BewegeCursorHoch(cursor);
            break;
        case KEY_DOWN:
            BewegeCursorRunter(cursor);
            break;
    }
}

/*******************************************************************************
Funktion VerarbeiteFeldEingabe()
Uebergabe Parameter:    iGedrueckteTaste, *cursor, sudokufeld[]
Rueckgabe:              -
Beschreibung:           Prueft ob eine Taste von 1 bis 9 gedrueckt wurde und
                        schreibt diese an die aktuelle Cursorposition.
                        Prueft ob die "Entf"-Taste gedrueckt wurde und loescht
                        den Wert an der aktuellen Cursorpostition.
*******************************************************************************/
void VerarbeiteFeldEingabe(int iGedrueckteTaste, CURSOR cursor,
                           SUDOKUFELD sudokufelder[])
{
    int iFeld = cursor.iAktuelleSpielfeldSpalte
                + ((cursor.iAktuelleSpielfeldZeile - 1) * 9) - 1;
    int iZahl;

    switch(iGedrueckteTaste)
    {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            iZahl = iGedrueckteTaste - 48;
            SchreibeZahlInFeld(sudokufelder[iFeld], cursor, iZahl);
            break;
        case KEY_DC:
            LoescheZahlAusFeld(sudokufelder[iFeld], cursor);
            break;
    }
}

/*******************************************************************************
Funktion VerarbeiteKommandos()
Uebergabe Parameter:    iGedrueckteTaste
Rueckgabe:              -
Beschreibung:           Prüft ob eine Kommandotaste im Spiel gedrueckt wurde und
                        delegiert an die entsprechende Funktion.
*******************************************************************************/
void VerarbeiteKommandos(int iGedrueckteTaste, CURSOR cursor,
                         SUDOKUFELD sudokufelder[], int *iStrafSekunden,
                         int *iAnzahlHilfeGenutzt)
{
    switch(iGedrueckteTaste)
    {
        case 'H':
        case 'h':
            HilfeBenutzen(cursor, sudokufelder, iStrafSekunden, 
                          iAnzahlHilfeGenutzt);
            break;
        case 'K':
        case 'k':
            break;
        case 'L':
        case 'l':
            break;
        case 'R':
        case 'r':
            SpielregelnAnzeigen();
            break;
    }
}