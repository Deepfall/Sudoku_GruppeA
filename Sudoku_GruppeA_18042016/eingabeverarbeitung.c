/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : eingabeverarbeitung.c
Datum                   : 19.04.2016
Beschreibung            : Modul fuer die Eingabeverarbeitung im Spiel.
                          Verarbeitet die Tastatureingabe und fuehrt Operationen
                          aus.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "eingabeverarbeitung.h"

/*******************************************************************************
Funktion VerarbeiteEingabe()
Uebergabe Parameter:    sudokufelder[], *iStrafSekunden, *iAnzahlHilfeGenutzt
Rueckgabe:              iGedrueckteTaste, sudokufelder,
                        *iStrafSekunden, *iAnzahlHilfeGenutzt
Beschreibung:           Verarbeitet die allgemeine Benutzereingabe im Spiel.
                        Kapsellung weiterer Methoden der Benutzereingabe.
*******************************************************************************/
int VerarbeiteEingabe(SUDOKUFELD sudokufelder[], int *iStrafSekunden,
                      int *iAnzahlHilfeGenutzt)
{
    static CURSOR cursor = { CURSOR_START_POSITION_SPALTE,
                             CURSOR_START_POSITION_ZEILE,
                             CURSOR_START_ZEILE, CURSOR_START_SPALTE };

    int iGedrueckteTaste = getch();

    VerarbeiteCursorBewegung(iGedrueckteTaste, &cursor);
    VerarbeiteFeldEingabe(iGedrueckteTaste, cursor, sudokufelder);
    VerarbeiteKommandos(iGedrueckteTaste, cursor, sudokufelder, iStrafSekunden,
                        iAnzahlHilfeGenutzt);

    return iGedrueckteTaste;
}

/*******************************************************************************
Funktion VerarbeiteCursorBewegung()
Uebergabe Parameter:    iGedrueckteTaste, *cursor
Rueckgabe:              *cursor
Beschreibung:           Verarbeitet die Cursorbewegung mit den
                        Pfeiltasten im Spiel.
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
Uebergabe Parameter:    iGedrueckteTaste, cursor, sudokufelder[]
Rueckgabe:              sudokufelder[]
Beschreibung:           Prueft ob eine Taste von 1 bis 9 gedrueckt wurde und
                        schreibt diese an die aktuelle Cursorposition.
                        Prueft ob die "Entf"-Taste oder die "Backspace"-Taste
                        gedrueckt wurde und loescht den Wert an der aktuellen
                        Cursorpostition.
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
            SchreibeZahlInFeld(&sudokufelder[iFeld], cursor, iZahl);
            break;
        case KEY_DC:
        case KEY_BACKSPACE:
            LoescheZahlAusFeld(&sudokufelder[iFeld], cursor);
            break;
    }
}

/*******************************************************************************
Funktion VerarbeiteKommandos()
Uebergabe Parameter:    iGedrueckteTaste, cursor, sudokufelder[],
                        *iStrafSekunden, *iAnzahlHilfeGenutzt
Rueckgabe:              sudokufelder[], *iStrafSekunden, *iAnzahlHilfeGenutzt
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
        case 'L':
        case 'l':
            break;
        case 'R':
        case 'r':
            SpielregelnAnzeigen();
            break;
    }
}