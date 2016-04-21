#ifndef EINGABEVERARBEITUNG_H
#define EINGABEVERARBEITUNG_H
/*
Autor(en)               : David Fischer
Klasse                  : FA11
Programmname            : eingabeverarbeitung.h
Datum                   : 19.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include <curses.h>
#include "cursor.h"
#include "spielfeld.h"
#include "spielmenue.h"

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int VerarbeiteEingabe(SUDOKUFELD sudokufelder[], int *iStrafSekunden,
                      int *iAnzahlHilfeGenutzt);
void VerarbeiteCursorBewegung(int iGedrueckteTaste, CURSOR *cursor);
void VerarbeiteFeldEingabe(int iGedrueckteTaste, CURSOR cursor,
                           SUDOKUFELD sudokufelder[]);
void VerarbeiteKommandos(int iGedrueckteTaste, CURSOR cursor,
                         SUDOKUFELD sudokufelder[], int *iStrafSekunden,
                         int *iAnzahlHilfeGenutzt);

#endif
