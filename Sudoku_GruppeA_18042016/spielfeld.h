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
#include <stdio.h>

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
void getformatierteZeit(char cformatierteZeit[9], int ivergangeneSekunden);

#endif
