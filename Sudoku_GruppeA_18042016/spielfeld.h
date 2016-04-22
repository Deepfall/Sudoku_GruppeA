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
#include "allgemeineDefines.h"

#define ANZAHL_SPIELFELDER                 81
#define HILFE_STRAFZEIT                    30

/*******************************************************************************
Typdefinitionen
*******************************************************************************/
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
void SchreibeZahlInFeld(SUDOKUFELD *sudokufeld, CURSOR cursor, int iZahl);
void LoescheZahlAusFeld(SUDOKUFELD *sudokufeld, CURSOR cursor);
void HilfeBenutzen(CURSOR cursor, SUDOKUFELD sudokufelder[],
                   int *iStrafSekunden, int *iAnzahlHilfeGenutzt);
int PruefeFelderManuell(SUDOKUFELD sudokufelder[]);

#endif
