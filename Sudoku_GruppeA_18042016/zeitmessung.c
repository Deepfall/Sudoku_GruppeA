/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : zeitmessung.c
Datum                   : 21.04.2016
Beschreibung            : Dieses Modul berechnet die verstrichenen Zeit im Spiel
                          und beinhaltet dafuer notwendige Funktionen.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "zeitmessung.h"

/*******************************************************************************
Funktion BerechneVerstricheneZeit()
Uebergabe Parameter:    cVerstricheneZeit[], Startzeit, iStrafSekunden
Rueckgabe:              -
Beschreibung:           Berechnet die Differenz zwischen der aktuellen Zeit und
                        der Startzeit und addiert anschliessend die Strafzeit.
                        Speichert diese formatiert in cVerstricheneZeit[].
*******************************************************************************/
void BerechneVerstricheneZeit(char cVerstricheneZeit[], time_t Startzeit,
                              int iStrafSekunden)
{
    time_t AktuelleZeit;
    int iVerstricheneSekunden;

    time(&AktuelleZeit);

    iVerstricheneSekunden = (int) difftime(AktuelleZeit, Startzeit);
    iVerstricheneSekunden += iStrafSekunden;

    SchreibeFormatierteZeit(cVerstricheneZeit, iVerstricheneSekunden);
}

/*******************************************************************************
Funktion SchreibeFormatierteZeit()
Uebergabe Parameter:    cFormatierteZeit[], int iVerstricheneSekunden
Rueckgabe:              -
Beschreibung:           Formatiert Sekunden in das Format HH:MM:SS und speichert
                        es in cFormatierteZeit[].
*******************************************************************************/
void SchreibeFormatierteZeit(char cFormatierteZeit[], int iVerstricheneSekunden)
{
    int iStunden = iVerstricheneSekunden / 3600;
    int iMinuten = (iVerstricheneSekunden / 60) % 60;
    int iSekunden = iVerstricheneSekunden % 60;
    
    sprintf(cFormatierteZeit, "%02d:%02d:%02d", iStunden, iMinuten, iSekunden);
}