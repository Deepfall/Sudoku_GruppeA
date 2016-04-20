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

#define TEXTLAENGE                 20

// Datenbank
#define DATENBANK_SUDOKU  "Sudoku.db"

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int Registrieren(char *cNachname, char *cVorname,
                 char *cNickname, char *cPasswort);
int Einloggen(char *cNickname, char *Passwort);

/*******************************************************************************
Globale Variablen
*******************************************************************************/
sqlite3 *db_handle;