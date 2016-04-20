/*
Autor(en)               : Jennifer Hermanns
Klasse                  : FA11
Programmname            : datenbankanbindung.h
Datum                   : 20.04.2016
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
#include "datenbankanbindung.h"
#include "sudoku.h"


// Allgemein
#define _CRT_SECURE_NO_DEPRECATE    1

#define TRUE                        1
#define FALSE                       0
#define TEXTLAENGE                 20

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void StartMenue(void);
void Spielmenue(void);
void SchwierigkeitsStufenMenue(void);
void LoggInmenue(void);
void Registrierungsmenue(void);

void SpielregelnAnzeigen(void);