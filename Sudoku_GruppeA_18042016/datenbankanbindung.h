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
#include <time.h>
#include "sqlite3.h"


// Allgemein
#define _CRT_SECURE_NO_DEPRECATE    1

#define TRUE                        1
#define FALSE                       0
#define PASSWORTLAENGE              6
#define TEXTLAENGE                 20

// Datenbank
#define DATENBANK_SUDOKU  "Sudoku.db"

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int Registrieren(char *cNachname, char *cVorname,
                 char *cNickname, char *cPasswort);

/*******************************************************************************
Globale Variablen
*******************************************************************************/
sqlite3 *db_handle;