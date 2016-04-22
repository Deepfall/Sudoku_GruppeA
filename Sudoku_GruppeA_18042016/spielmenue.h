#ifndef SPIELMENUE_H
#define SPIELMENUE_H
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
#include "helpers.h"

#define TEXTLAENGE                 20
#define NACHNAME				"Nachname"
#define VORNAME				    "Vorname"
#define NICKNAME				"Nickname"
#define PASSWORT				"Passwort"

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
WINDOW *ErstelleNeuesMenueFenster(void);
void Startmenue(void);
void Spielmenue(const char Nickname[]);
void Schwierigkeitsstufenmenue(const char ccNickname[]);
void HighscoreSchwierigkeitsStufenMenue();
void Loginmenue(void);
void Registrierungsmenue(void);
void SpielGewonnenMenue(char cZeit[]);
InBestenlisteEintragenDialog(int iSchwierigkeit, const char ccNickname[], char cZeit[]);

#endif
