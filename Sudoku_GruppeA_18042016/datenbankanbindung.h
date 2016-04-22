#ifndef DATENBANKANBINDUNG_H
#define DATENBANKANBINDUNG_H
/*
Autor(en)               : Jennifer Hermanns
Klasse                  : FA11
Programmname            : datenbankanbindung.h
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
#include <string.h>
#include <time.h>
#include <curses.h>
#include "sqlite3.h"
#include "helpers.h"
#include "spielfeld.h"

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
int loginDatenGefuellt(char *cNickname, char *cPasswort);
int felderGefuellt(char *cNachname, char *cVorname,
                   char *cNickname, char *cPasswort);
int SudokuBereitstellen(char *cSudoku, char *cLoesung, int iSchwierigkeit);
void DatenbankOeffnen(sqlite3 **db_handle);

#endif
