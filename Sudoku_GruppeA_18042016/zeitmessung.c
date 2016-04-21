/*
Autor(en)               : David Fischer
Klasse                  : FA11
Programmname            : zeitmessung.c
Datum                   : 21.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "zeitmessung.h"

/*******************************************************************************
Funktion BerechneVerstricheneZeit()
Uebergabe Parameter:    cVerstricheneZeit[]
Rueckgabe:              cVerstricheneZeit[]
Beschreibung:           Berechnet die Differenz zwischen der aktuellen Zeit und
                        der Startzeit und speichert diese formatiert in 
                        cVerstricheneZeit[].
*******************************************************************************/
void BerechneVerstricheneZeit(char cVerstricheneZeit[], time_t Startzeit)
{
    time_t AktuelleZeit;
    int iVerstricheneSekunden;

    time(&AktuelleZeit);

    iVerstricheneSekunden = (int) difftime(AktuelleZeit, Startzeit);

    SchreibeFormatierteZeit(cVerstricheneZeit, iVerstricheneSekunden);
}

/*******************************************************************************
Funktion SchreibeFormatierteZeit()
Uebergabe Parameter:    cFormatierteZeit[], int iVerstricheneSekunden
Rueckgabe:              cFormatierteZeit[]
Beschreibung:           Formatiert Sekunden in das Format HH:MM:SS und speichert
                        es in cFormatierteZeit[].
*******************************************************************************/
void SchreibeFormatierteZeit(char cFormatierteZeit[], int iVerstricheneSekunden)
{
	int iStunden = iVerstricheneSekunden/ 3600;
	int iMinuten = (iVerstricheneSekunden / 60) % 60;
	int iSekunden = iVerstricheneSekunden % 60;
	
	sprintf(cFormatierteZeit, "%02d:%02d:%02d", iStunden, iMinuten, iSekunden);
}