#ifndef DATENBANKANBINDUNG_H
#define DATENBANKANBINDUNG_H
/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : datenbankanbindung.h
Datum                   : 18.04.2016
Beschreibung            : Beinhaltet alle Funktionen die mit der Datenbank
                          kommunizieren.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "allgemeineDefines.h"
#include <string.h>
#pragma warning(push, 0) // Vermeide Warnungen ab hier
#include <curses.h> // Muss unter Unix-System durch ncurses.h ersetzt werden
#include <sqlite3.h>
#pragma warning(pop) // Vermeide Warnungen bis hier
#include "helpers.h"

#define TEXTLAENGE                              20
#define DATENBANK_SUDOKU   "Datenbanken/Sudoku.db"

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int Einloggen(const char ccNickname[], const char ccPasswort[]);
int Registrieren(const char ccNachname[], const char ccVorname[],
                 const char ccNickname[], const char ccPasswort[]);
int SudokuBereitstellen(char cSudoku[], char cLoesung[], int iSchwierigkeit);
int HighscoreAusgeben(int iSchwierigkeit);
int HighscoreEintragen(int iSchwierigkeit, const char ccNickname[],
                       const char ccZeit[]);
void DatenbankOeffnen(sqlite3 **db_handle);

#endif
