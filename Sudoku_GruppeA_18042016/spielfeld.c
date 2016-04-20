/*
Autor(en)               : David Fischer
Klasse                  : FA11
Programmname            : sudoku.c
Datum                   : 18.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "spielfeld.h"

/*******************************************************************************
Funktion getformatierteZeit()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void getformatierteZeit(char cformatierteZeit[9], int ivergangeneSekunden)
{
	int iStunde = ivergangeneSekunden/ 3600;
	int iMinute = (ivergangeneSekunden / 60) % 60;
	int iSekunden = ivergangeneSekunden % 60;
	
	sprintf(cformatierteZeit, "%02d:%02d:%02d", iStunde, iMinute, iSekunden);
}