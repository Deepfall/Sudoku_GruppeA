#ifndef ZEITMESSUNG_H
#define ZEITMESSUNG_H
/*
Autor(en)               : David Fischer
Klasse                  : FA11
Programmname            : zeitmessung.h
Datum                   : 21.04.2016
Beschreibung            : 
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
void BerechneVerstricheneZeit(char cVerstricheneZeit[], time_t Startzeit);
void SchreibeFormatierteZeit(char cFormatierteZeit[], 
                             int iVerstricheneSekunden);

#endif
