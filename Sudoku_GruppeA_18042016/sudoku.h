#ifndef SUDOKU_H
#define SUDOKU_H
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
#include "spielfeld.h"
#include "eingabeverarbeitung.h"

// Allgemein
#define TRUE                        1
#define FALSE                       0

#define START_POSITION_SPALTE       7
#define START_POSITION_ZEILE        4
#define START_ZEILE                 1
#define START_SPALTE                1

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void NeuesSpiel(void);
WINDOW *ErstelleNeuesInfoFenster(void);
WINDOW *ErstelleNeuesSpielfeldFenster(void);
WINDOW *ErstelleNeuesKommandoFenster(void);
void ZeicheSpielfeld(WINDOW *spielfeldFenster);
void ZeichneInfo(WINDOW *infoFenster, char formattedElapsedTime[9]);
void ZeicheKommandos(WINDOW *kommandoFenster);

#endif
