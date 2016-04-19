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
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
int VerarbeiteEingabe(CURSOR *cursor, SUDOKUFELD sudokufeld[81])
{
    int gedrueckteTaste = getch();

    VerarbeiteCursorBewegung(gedrueckteTaste, cursor);
    VerarbeiteFeldEingabe(gedrueckteTaste, cursor, sudokufeld);

    return gedrueckteTaste;
}

/*******************************************************************************
Funktion VerarbeiteCursorBewegung()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void VerarbeiteCursorBewegung(int gedrueckteTaste, CURSOR *cursor)
{
    switch(gedrueckteTaste)
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
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void VerarbeiteFeldEingabe(int gedrueckteTaste, CURSOR *cursor, SUDOKUFELD sudokufeld[81])
{
    switch(gedrueckteTaste)
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
        if(!sudokufeld[cursor->iY * cursor->iX].iIstVorbefuellt)
        {
            sudokufeld[cursor->iY * cursor->iX].iWert = gedrueckteTaste - 48;
            mvprintw(cursor->iY, cursor->iX, "%c", gedrueckteTaste);
        }
        break;
    }
}