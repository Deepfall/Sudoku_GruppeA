#ifndef SPIELFELD_H
#define SPIELFELD_H
/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : spielfeld.h
Datum                   : 18.04.2016
Beschreibung            : Dieses Modul enthaelt alle Funktionen die mit dem
                          Spielfeld zu tun haben.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "allgemeineDefines.h"
#pragma warning(push, 0) // Vermeide Warnungen ab hier
#include <curses.h> // Muss unter Unix-System durch ncurses.h ersetzt werden
#pragma warning(pop) // Vermeide Warnungen bis hier
#include "cursor.h"
#include "datenbankanbindung.h"

#define ANZAHL_SPIELFELDER                 81
#define HILFE_STRAFSEKUNDEN                30

/*******************************************************************************
Typdefinitionen
*******************************************************************************/
typedef struct
{
    int iWert;
    int iLoesung;
    int iIstVorbefuellt;
}
SUDOKUFELD;

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void BefuelleSpielfelder(SUDOKUFELD spielfelder[], int iSchwierigkeit);
void SchreibeZahlInFeld(SUDOKUFELD *sudokufeld, CURSOR cursor, int iZahl);
void LoescheZahlAusFeld(SUDOKUFELD *sudokufeld, CURSOR cursor);
void HilfeBenutzen(CURSOR cursor, SUDOKUFELD sudokufelder[],
                   int *iAnzahlHilfeGenutzt);
int FelderKorrektAusgefuellt(SUDOKUFELD sudokufelder[]);
int AlleFelderGefuellt(SUDOKUFELD sudokufelder[]);

#endif
