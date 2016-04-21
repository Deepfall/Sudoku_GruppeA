/*
Autor(en)               : Robin grahl, Dustin Welz
Klasse                  : FA11
Programmname            : helpers.c
Datum                   : 20.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <curses.h>

int generiereSudokuId(int stufe) {
    int sudokuId = -1;

    switch(stufe) {
    case 1: sudokuId = generiereZufallsZahl(1, 10);
        break;
    case 2: sudokuId = generiereZufallsZahl(11, 20);
        break;
    case 3: sudokuId = generiereZufallsZahl(21, 30);
        break;
    }

    return sudokuId;
}

int generiereZufallsZahl(int min_n, int max_n)
{
    srand(time(NULL));
    return rand() % (max_n - min_n + 1) + min_n;
}

void entferneLeerzeichen(char* source)
{
    char* i = source;
    char* j = source;

    while(*j != 0)
    {
        *i = *j++;

        if(*i != ' ')
        {
            i++;
        }
    }

    *i = 0;
}

/*******************************************************************************
Funktion felderGefuellt()
Uebergabe Parameter:    ueberprüfungsText

Rueckgabe:              0 - Feld is ok
                        -2 - Feld ist zu lang
                        -3 - Feld ist zu kurz
						-1 - Feld ist nicht ok
Beschreibung:           
*******************************************************************************/
int isValid(char * cUeberprüfungsText,int iMin,int iMax)
{
    entferneLeerzeichen(cUeberprüfungsText);
	
	if(strlen(cUeberprüfungsText) > iMax) {
		return -2;
	}

	if(strlen(cUeberprüfungsText) < iMin) {
		return -3;
	}

	if(strlen(cUeberprüfungsText) >= iMin && strlen(cUeberprüfungsText) < iMax) {
		return 0;
	}

	return -1;
}

/*******************************************************************************
Funktion feldPlausi()
Uebergabe Parameter:    ueberprüfungsText
Rueckgabe:              0 - Felder sind gefüllt und Länge in Ordnung
1 - Felder sind leer
2 - Felder sind zu lang
Beschreibung:           
*******************************************************************************/
int feldPlausi(char *cUeberprüfungsText, int iMin, int iMax)
{
    entferneLeerzeichen(cUeberprüfungsText);

    if(strlen(cUeberprüfungsText) == 0  || (strlen(cUeberprüfungsText) < iMin
        && strlen(cUeberprüfungsText) > iMax))
    {
        return 1;
    }

    return 0;
}

/*******************************************************************************
Funktion Fehlermeldung()
Uebergabe Parameter:    FehlerID
Rueckgabe:              0 - Felder sind gefüllt und Länge in Ordnung
1 - Felder sind leer
2 - Felder sind zu lang
Beschreibung:           
*******************************************************************************/
void Fehlermeldung(int iFehlerID, char *cFeldname)
{
    switch(iFehlerID)
	{
	case -3:
		printw("\n\t\t\t%s ist zu kurz!", cFeldname);
		break;
	case -2:
		printw("\n\t\t\t%s ist zu lang!", cFeldname);
		break;
	case -1:
		printw("\n\t\t\t%s ist falsch!", cFeldname);
		break;
	case 0:
		break;
	}
}
