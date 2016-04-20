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
#include <curses.h>
#include "datenbankanbindung.h"
#include "sudoku.h"
#include "allgemeineDefines.h"

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