/*
Autor(en)               : David Fischer
Klasse                  : FA11
Programmname            : cursor.c
Datum                   : 19.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "cursor.h"

/*******************************************************************************
Funktion BewegeCursorLinks()
Uebergabe Parameter:    *cursor
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void BewegeCursorLinks(CURSOR *cursor)
{
    if(cursor->iAktuelleSpielfeldSpalte > 1)
    {
        cursor->iX -= CURSOR_OFFSET_SPALTE;

        if(cursor->iAktuelleSpielfeldSpalte % 3 == 1)
        {
            cursor->iX--;
        }

        cursor->iAktuelleSpielfeldSpalte--;
    }
}

/*******************************************************************************
Funktion BewegeCursorRechts()
Uebergabe Parameter:    *cursor
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void BewegeCursorRechts(CURSOR *cursor)
{
    if(cursor->iAktuelleSpielfeldSpalte < 9)
    {
        cursor->iX += CURSOR_OFFSET_SPALTE;

        if(cursor->iAktuelleSpielfeldSpalte % 3 == 0)
        {
            cursor->iX++;
        }

        cursor->iAktuelleSpielfeldSpalte++;
    }
}

/*******************************************************************************
Funktion BewegeCursorHoch()
Uebergabe Parameter:    *cursor
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void BewegeCursorHoch(CURSOR *cursor)
{
    if(cursor->iAktuelleSpielfeldZeile > 1)
    {
        cursor->iY -= CURSOR_OFFSET_ZEILE;
        cursor->iAktuelleSpielfeldZeile--;
    }
}

/*******************************************************************************
Funktion BewegeCursorRunter()
Uebergabe Parameter:    *cursor
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
void BewegeCursorRunter(CURSOR *cursor)
{
    if(cursor->iAktuelleSpielfeldZeile < 9)
    {
        cursor->iY += CURSOR_OFFSET_ZEILE;
        cursor->iAktuelleSpielfeldZeile++;
    }
}