#ifndef HELPERS_H
#define HELPERS_H
/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : helpers.h
Datum                   : 20.04.2016
Beschreibung            : Hilfsfunktionen für das Sudokuprojekt.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int GeneriereSudokuId(int iSchwierigkeit);
int GeneriereZufallszahlReichweite(int iMinimum, int iMaximum);
void EntferneLeerzeichenAusString(char cString[]);
int PruefeAufValideStringlaenge(char cString[],
                                unsigned int uiMindestLaenge,
                                unsigned int uiMaximalLaenge);
void AusgabeFehlermeldungValideTextlaenge(int iFehlerId,
                                          const char ccFeldname[]);
void SpielregelnAnzeigen(void);
void AusgabeAbsoulterPfad(char cAusgabe[], const char ccDateiname[]);

#endif
