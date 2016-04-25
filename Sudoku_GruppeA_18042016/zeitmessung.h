#ifndef ZEITMESSUNG_H
#define ZEITMESSUNG_H
/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : zeitmessung.h
Datum                   : 21.04.2016
Beschreibung            : Dieses Modul berechnet die verstrichene Zeit im Spiel
                          und beinhaltet die dafuer notwendigen Funktionen.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "allgemeineDefines.h"
#include <stdio.h>
#pragma warning(push, 0) // Vermeide Warnungen ab hier
#include <time.h>
#pragma warning(pop) // Vermeide Warnungen bis hier
#include "spielfeld.h"

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void BerechneVerstricheneZeit(char cVerstricheneZeit[], time_t Startzeit,
                              int iAnzahlHilfeGenutzt);
void SchreibeFormatierteZeit(char cFormatierteZeit[],
                             int iVerstricheneSekunden);

#endif
