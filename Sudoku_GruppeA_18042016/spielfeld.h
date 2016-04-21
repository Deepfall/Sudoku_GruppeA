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
#define ANZAHL_SPIELFELDER                 81

typedef struct
{
    int iWert;
    int iIstVorbefuellt;
    int iKandiaten[9];
}
SUDOKUFELD;

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/


#endif
