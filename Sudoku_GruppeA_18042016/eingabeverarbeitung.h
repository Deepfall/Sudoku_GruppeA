#ifndef EINGABEVERARBEITUNG_H
#define EINGABEVERARBEITUNG_H
/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : eingabeverarbeitung.h
Datum                   : 19.04.2016
Beschreibung            : Modul fuer die Eingabeverarbeitung im Spiel.
                          Verarbeitet die Tastatureingabe und fuehrt Operationen
                          aus.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#pragma warning(push, 0)
#include <curses.h>
#pragma warning(pop)
#include "cursor.h"
#include "spielfeld.h"
#include "spielmenue.h"

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int VerarbeiteEingabe(SUDOKUFELD sudokufelder[], CURSOR *cursor,
                      int *iStrafSekunden, int *iAnzahlHilfeGenutzt);
void VerarbeiteCursorBewegung(int iGedrueckteTaste, CURSOR *cursor);
void VerarbeiteFeldEingabe(int iGedrueckteTaste, CURSOR cursor,
                           SUDOKUFELD sudokufelder[]);
void VerarbeiteKommandos(int iGedrueckteTaste, CURSOR cursor,
                         SUDOKUFELD sudokufelder[], int *iStrafSekunden,
                         int *iAnzahlHilfeGenutzt);

#endif
