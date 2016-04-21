#ifndef HELPERS_H
#define HELPERS_H
/*
Autor(en)               : Robin Grahl
Klasse                  : FA11
Programmname            : helpers.h
Datum                   : 20.04.2016
Beschreibung            : Hilfsfunktionen für das Sudokuprojekt
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

#include <time.h>
#include <stdlib.h>

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
int generiereZufallsZahl(int min_n, int max_n);
int generiereSudokuId(int iSchwierigkeit);
void entferneLeerzeichen(char* source);
int isValid(char * cUeberprüfungsText,int iMin,int iMax);
void Fehlermeldung(int iFehlerID, char *cFeldname);
void AusgabeAbsoulterPfad(char cZielPfad[],char cDateiname[]);
void anpassenDateipfad(char cangepassterPfad[], char cQuellpfad[]);
void SpielregelnAnzeigen(void);


#endif
