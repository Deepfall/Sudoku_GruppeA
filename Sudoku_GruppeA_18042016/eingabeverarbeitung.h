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

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int VerarbeiteEingabe(CURSOR *cursor, SUDOKUFELD sudokufeld[81]);
void VerarbeiteCursorBewegung(int gedrueckteTaste, CURSOR *cursor);
void VerarbeiteFeldEingabe(int gedrueckteTaste, CURSOR *cursor, SUDOKUFELD sudokufelder[81]);

#endif
