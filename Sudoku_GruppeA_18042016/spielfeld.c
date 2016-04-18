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
Funktion getFormattedTime()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void getFormattedTime(char formattedTime[9], int elapsedSeconds)
{
	int hour = elapsedSeconds / 3600;
	int minutes = (elapsedSeconds / 60) % 60;
	int seconds = elapsedSeconds % 60;
	
	sprintf(formattedTime, "%02d:%02d:%02d", hour, minutes, seconds);
}