#ifndef CURSOR_H
#define CURSOR_H
/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : cursor.h
Datum                   : 19.04.2016
Beschreibung            : Stellt den Cursor zur Verfuegung und fuert Operationen
                          darauf aus.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include <curses.h>

#define CURSOR_START_POSITION_SPALTE        5
#define CURSOR_START_POSITION_ZEILE         3
#define CURSOR_OFFSET_SPALTE                8
#define CURSOR_OFFSET_ZEILE                 4
#define CURSOR_START_ZEILE                  1
#define CURSOR_START_SPALTE                 1

/*******************************************************************************
Typdefinitionen
*******************************************************************************/
typedef struct
{
    int iX;
    int iY;
    int iAktuelleSpielfeldZeile;
    int iAktuelleSpielfeldSpalte;
}
CURSOR;

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void InitialisiereCursor(CURSOR *cursor);
void BewegeCursorLinks(CURSOR *cursor);
void BewegeCursorRechts(CURSOR *cursor);
void BewegeCursorHoch(CURSOR *cursor);
void BewegeCursorRunter(CURSOR *cursor);

#endif
