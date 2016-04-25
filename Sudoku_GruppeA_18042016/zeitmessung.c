/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : zeitmessung.c
Datum                   : 21.04.2016
Beschreibung            : Dieses Modul berechnet die verstrichene Zeit im Spiel
                          und beinhaltet die dafuer notwendigen Funktionen.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "zeitmessung.h"

/*******************************************************************************
Funktion BerechneVerstricheneZeit()
Uebergabe Parameter:    cVerstricheneZeit[], Startzeit, iAnzahlHilfeGenutzt
Rueckgabe:              -
Beschreibung:           Berechnet die Differenz zwischen der aktuellen Zeit und
                        der Startzeit und addiert anschliessend die Strafzeit.
                        Abschliessend wird die Zeit formatiert.
*******************************************************************************/
void BerechneVerstricheneZeit(char cVerstricheneZeit[], time_t Startzeit,
                              int iAnzahlHilfeGenutzt)
{
    time_t AktuelleZeit;
    int iVerstricheneSekunden;

    // Hole aktuelle Zeit
    time(&AktuelleZeit);

    // Berechne die Differenz der aktuellen und der Startzeit, addiere Strafzeit
    iVerstricheneSekunden = (int) difftime(AktuelleZeit, Startzeit);
    iVerstricheneSekunden += iAnzahlHilfeGenutzt * HILFE_STRAFSEKUNDEN;

    SchreibeFormatierteZeit(cVerstricheneZeit, iVerstricheneSekunden);
}

/*******************************************************************************
Funktion SchreibeFormatierteZeit()
Uebergabe Parameter:    cFormatierteZeit[], iVerstricheneSekunden
Rueckgabe:              -
Beschreibung:           Formatiert Sekunden in das Format HH:MM:SS.
*******************************************************************************/
void SchreibeFormatierteZeit(char cFormatierteZeit[], int iVerstricheneSekunden)
{
    int iStunden = iVerstricheneSekunden / 3600;
    int iMinuten = (iVerstricheneSekunden / 60) % 60;
    int iSekunden = iVerstricheneSekunden % 60;
    
    sprintf(cFormatierteZeit, "%02d:%02d:%02d", iStunden, iMinuten, iSekunden);
}