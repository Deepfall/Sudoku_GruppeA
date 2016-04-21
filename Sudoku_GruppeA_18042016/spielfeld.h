#ifndef SPIELFELD_H
#define SPIELFELD_H
/*
Autor(en)               : David Fischer
Klasse                  : FA11
Programmname            : sudoku.h
Datum                   : 18.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include <curses.h>
#include "cursor.h"
#include "datenbankanbindung.h"

#define ANZAHL_SPIELFELDER                 81

typedef struct
{
    int iWert;
    int iLoesung;
    int iIstVorbefuellt;
    int iKandiaten[9];
}
SUDOKUFELD;

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void BefuelleSpielfelder(SUDOKUFELD spielfelder[], int iSchwierigkeit);
void SchreibeZahlInFeld(SUDOKUFELD sudokufeld, CURSOR *cursor, int iZahl);
void LoescheZahlAusFeld(SUDOKUFELD sudokufeld, CURSOR *cursor);

#endif
