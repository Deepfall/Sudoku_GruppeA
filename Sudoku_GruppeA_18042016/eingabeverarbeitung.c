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
int VerarbeiteEingabe(SUDOKUFELD sudokufelder[])
{
    static CURSOR cursor = { CURSOR_START_POSITION_SPALTE,
                             CURSOR_START_POSITION_ZEILE,
                             CURSOR_START_ZEILE, CURSOR_START_SPALTE };

    int gedrueckteTaste = getch();

    VerarbeiteCursorBewegung(gedrueckteTaste, &cursor);
    VerarbeiteFeldEingabe(gedrueckteTaste, &cursor, sudokufelder);
    VerarbeiteKommandos(gedrueckteTaste);

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

    move(cursor->iY, cursor->iX);
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
void VerarbeiteFeldEingabe(int iGedrueckteTaste, CURSOR *cursor,
                           SUDOKUFELD sudokufeld[])
{
    int iFeld = cursor->iAktuelleSpielfeldSpalte
                + ((cursor->iAktuelleSpielfeldZeile - 1) * 9) - 1;

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
            if(!sudokufeld[iFeld].iIstVorbefuellt)
            {
                sudokufeld[iFeld].iWert = iGedrueckteTaste - 48;
                mvprintw(cursor->iY, cursor->iX, "%c", iGedrueckteTaste);
            }
            break;
        case KEY_DC:
            if(!sudokufeld[iFeld].iIstVorbefuellt)
            {
                sudokufeld[iFeld].iWert = 0;
                mvprintw(cursor->iY, cursor->iX, " ");
            }
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
void VerarbeiteKommandos(int iGedrueckteTaste)
{
    switch(iGedrueckteTaste)
    {
        case 'H':
        case 'h':
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