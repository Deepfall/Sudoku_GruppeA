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
#pragma warning(push, 0)
#include <curses.h>
#include "sqlite3.h"
#pragma warning(pop)
#include "helpers.h"

#define TEXTLAENGE                 20
#define DATENBANK_SUDOKU  "Sudoku.db"

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int Einloggen(char *cNickname, char *Passwort);
int Registrieren(char cNachname[], char cVorname[],
                 char cNickname[], char cPasswort[]);
int SudokuBereitstellen(char cSudoku[], char cLoesung[], int iSchwierigkeit);
int HighscoreAusgeben(int iSchwierigkeit);
int HighscoreEintragen(int iSchwierigkeit, const char ccNickname[],
                       char cZeit[]);
void DatenbankOeffnen(sqlite3 **db_handle);

#endif
