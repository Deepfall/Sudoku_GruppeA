#ifndef CURSOR_H
#define CURSOR_H
/*
Autor(en)               : David Fischer
Klasse                  : FA11
Programmname            : cursor.h
Datum                   : 19.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#define OFFSET_SPALTE               8
#define OFFSET_ZEILE                4

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
void BewegeCursorLinks(CURSOR *cursor);
void BewegeCursorRechts(CURSOR *cursor);
void BewegeCursorHoch(CURSOR *cursor);
void BewegeCursorRunter(CURSOR *cursor);

#endif
