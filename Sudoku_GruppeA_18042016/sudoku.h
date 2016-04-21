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
#include <string.h>
#include "spielfeld.h"
#include "eingabeverarbeitung.h"
#include "allgemeineDefines.h"
#include "datenbankanbindung.h"
#include "zeitmessung.h"
#include "cursor.h"

#define START_POSITION_SPALTE               6
#define START_POSITION_ZEILE                3
#define OFFSET_SPALTE                       8
#define OFFSET_ZEILE                        4

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void NeuesSpiel(int iSchwierigkeit,char *cNickname);
WINDOW *ErstelleNeuesInfoFenster(void);
WINDOW *ErstelleNeuesSpielfeldFenster(void);
WINDOW *ErstelleNeuesKommandoFenster(void);
void ZeichneSpielfeld(WINDOW *spielfeldFenster);
void ZeichneSpielfelder(WINDOW *spielfeldFenster, SUDOKUFELD spielfelder[ANZAHL_SPIELFELDER]);
void ZeichneLoesung(WINDOW *spielfeldFenster, SUDOKUFELD spielfelder[ANZAHL_SPIELFELDER]);
void ZeichneInfo(WINDOW *infoFenster);
void ZeichneKommandos(WINDOW *kommandoFenster);
void ZeichneVerstricheneZeit(WINDOW *infoFenster, time_t Startzeit);
void ZeichneAnzahlGenutzterHilfe(WINDOW *infoFenster, int iAnzahlGenutzterHilfe);

#endif
