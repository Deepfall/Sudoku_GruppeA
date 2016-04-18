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
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>

// Allgemein
#define TRUE                        1
#define FALSE                       0

#define START_POSITION_SPALTE       6
#define START_POSITION_ZEILE        3
#define OFFSET_SPALTE               8
#define OFFSET_ZEILE                4
#define START_ZEILE                 1
#define START_SPALTE                1

typedef struct
{
    int x;
    int y;
    int aktuelleSpielfeldZeile;
    int aktuelleSpielfeldSpalte;
}
CURSOR;

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void NeuesSpiel(void);
void BewegeCursorLinks(CURSOR *cursor);
void BewegeCursorRechts(CURSOR *cursor);
void BewegeCursorHoch(CURSOR *cursor);
void BewegeCursorRunter(CURSOR *cursor);