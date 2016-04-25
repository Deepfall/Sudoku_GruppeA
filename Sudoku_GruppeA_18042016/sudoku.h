#ifndef SUDOKU_H
#define SUDOKU_H
/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : sudoku.h
Datum                   : 18.04.2016
Beschreibung            : Das eigentliche Spiel wird hier gestartet und
                          auf den Bildschirm ausgegeben.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "allgemeineDefines.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning(push, 0) // Vermeide Warnungen ab hier
#include <curses.h> // Muss unter Unix-System durch ncurses.h ersetzt werden
#pragma warning(pop) // Vermeide Warnungen bis hier
#include <string.h>
#include "spielfeld.h"
#include "eingabeverarbeitung.h"
#include "datenbankanbindung.h"
#include "zeitmessung.h"
#include "cursor.h"

#define START_POSITION_SPALTE               4
#define START_POSITION_ZEILE                2
#define OFFSET_SPALTE                       8
#define OFFSET_ZEILE                        4

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void NeuesSpiel(int iSchwierigkeit, const char ccNickname[]);
WINDOW *ErstelleNeuesInfoFenster(void);
WINDOW *ErstelleNeuesSpielfeldFenster(void);
WINDOW *ErstelleNeuesKommandoFenster(void);
void ZeichneSpielfeld(WINDOW *spielfeldFenster);
void ZeichneSpielfelder(WINDOW *spielfeldFenster, SUDOKUFELD spielfelder[]);
void ZeichneLoesung(WINDOW *spielfeldFenster, SUDOKUFELD spielfelder[]);
void ZeichneInfo(WINDOW *infoFenster);
void ZeichneKommandos(WINDOW *kommandoFenster);
void ZeichneVerstricheneZeit(WINDOW *infoFenster, time_t Startzeit,
                             int iAnzahlHilfeGenutzt);
void ZeichneAnzahlGenutzterHilfe(WINDOW *infoFenster, int iAnzahlHilfeGenutzt);

#endif
