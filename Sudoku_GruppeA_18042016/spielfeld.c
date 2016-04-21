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
#include "spielfeld.h"

void SchreibeZahlInFeld(SUDOKUFELD sudokufeld, CURSOR *cursor, int iZahl)
{
    if(!sudokufeld.iIstVorbefuellt)
    {
        sudokufeld.iWert = iZahl;
        mvprintw(cursor->iY, cursor->iX, "%i", iZahl);
    }
}

void LoescheZahlAusFeld(SUDOKUFELD sudokufeld, CURSOR *cursor)
{
    if(!sudokufeld.iIstVorbefuellt)
    {
        sudokufeld.iWert = 0;
        mvprintw(cursor->iY, cursor->iX, " ");
    }
}