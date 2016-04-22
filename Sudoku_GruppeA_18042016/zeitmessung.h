#ifndef ZEITMESSUNG_H
#define ZEITMESSUNG_H
/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : zeitmessung.h
Datum                   : 21.04.2016
Beschreibung            : Dieses Modul berechnet die verstrichenen Zeit im Spiel
                          und beinhaltet dafuer notwendige Funktionen.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include <stdio.h>
#include <time.h>

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void BerechneVerstricheneZeit(char cVerstricheneZeit[], time_t Startzeit,
                              int iStrafSekunden);
void SchreibeFormatierteZeit(char cFormatierteZeit[],
                             int iVerstricheneSekunden);

#endif
