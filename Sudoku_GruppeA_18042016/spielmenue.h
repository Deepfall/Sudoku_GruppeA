#ifndef SPIELMENUE_H
#define SPIELMENUE_H
/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : spielmenue.h
Datum                   : 20.04.2016
Beschreibung            : Eine Sammlung der im Projekt verwendeteten
                          Spielmenues.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "allgemeineDefines.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(push, 0) // Vermeide Warnungen ab hier
#include <curses.h> // Muss unter Unix-System durch ncurses.h ersetzt werden
#pragma warning(pop) // Vermeide Warnungen bis hier
#include "datenbankanbindung.h"
#include "sudoku.h"
#include "helpers.h"

#define TEXTLAENGE                      20
#define NACHNAME                "Nachname"
#define VORNAME                  "Vorname"
#define NICKNAME                "Nickname"
#define PASSWORT                "Passwort"

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void Startmenue(void);
void Spielmenue(char cNickname[]);
void Schwierigkeitsstufenmenue(const char ccNickname[]);
void HighscoreSchwierigkeitsStufenMenue(void);
void Loginmenue(void);
void Registrierungsmenue(void);
void SpielGewonnenMenue(const char ccZeit[]);
void InBestenlisteEintragenDialog(int iSchwierigkeit, const char ccNickname[],
                                  const char ccZeit[]);

#endif
