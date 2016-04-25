/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : cursor.c
Datum                   : 19.04.2016
Beschreibung            : Stellt den Cursor zur Verfuegung und fuert Operationen
                          darauf aus.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "cursor.h"

/*******************************************************************************
Funktion InitialisiereCursor()
Uebergabe Parameter:    *cursor
Rueckgabe:              -
Beschreibung:           Setzt die Startposition und das Aussehen des Cursors.
*******************************************************************************/
void InitialisiereCursor(CURSOR *cursor)
{
    // Mache den Cursor sehr sichtbar
    curs_set(2);

    // Setzen der Startposition
    cursor->iAktuelleSpielfeldSpalte = CURSOR_START_SPALTE;
    cursor->iAktuelleSpielfeldZeile = CURSOR_START_ZEILE;
    cursor->iX = CURSOR_START_POSITION_SPALTE;
    cursor->iY = CURSOR_START_POSITION_ZEILE;

    // Bewege den Cursor an die Startposition
    move(cursor->iY, cursor->iX);
}

/*******************************************************************************
Funktion BewegeCursorLinks()
Uebergabe Parameter:    *cursor
Rueckgabe:              -
Beschreibung:           Bewegt den Cursor ein Spielfeld und den entsprechenden
                        Wert der x-Koordinate nach links, wenn dieser in der
                        Grenze bleibt.
*******************************************************************************/
void BewegeCursorLinks(CURSOR *cursor)
{
    if(cursor->iAktuelleSpielfeldSpalte > 1)
    {
        // Speichern der aktuellen Cursorposition
        cursor->iX -= CURSOR_OFFSET_SPALTE;

        /* Nach je 3 Spielfeldern ist der Block durch zwei Zeichen getrennt,
           daher muss {cursor->iX} noch einmal um 1 verringert werden. */
        if(cursor->iAktuelleSpielfeldSpalte % 3 == 1)
        {
            cursor->iX--;
        }

        cursor->iAktuelleSpielfeldSpalte--;

        // Bewege den cursor an die gewuenschte Stelle
        move(cursor->iY, cursor->iX);
    }
}

/*******************************************************************************
Funktion BewegeCursorRechts()
Uebergabe Parameter:    *cursor
Rueckgabe:              -
Beschreibung:           Bewegt den Cursor ein Spielfeld und den entsprechenden
                        Wert der x-Koordinate nach rechts, wenn dieser in der
                        Grenze bleibt.
*******************************************************************************/
void BewegeCursorRechts(CURSOR *cursor)
{
    if(cursor->iAktuelleSpielfeldSpalte < 9)
    {
        // Speichern der aktuellen Cursorposition
        cursor->iX += CURSOR_OFFSET_SPALTE;

        /* Nach je 3 Spielfeldern ist der Block durch zwei Zeichen getrennt,
           daher muss {cursor->iX} noch einmal um 1 erhoeht werden. */
        if(cursor->iAktuelleSpielfeldSpalte % 3 == 0)
        {
            cursor->iX++;
        }

        cursor->iAktuelleSpielfeldSpalte++;

        // Bewege den cursor an die gewuenschte Stelle
        move(cursor->iY, cursor->iX);
    }
}

/*******************************************************************************
Funktion BewegeCursorHoch()
Uebergabe Parameter:    *cursor
Rueckgabe:              -
Beschreibung:           Bewegt den Cursor ein Spielfeld und den entsprechenden
                        Wert der y-Koordinate nach oben, wenn dieser in der
                        Grenze bleibt.
*******************************************************************************/
void BewegeCursorHoch(CURSOR *cursor)
{
    if(cursor->iAktuelleSpielfeldZeile > 1)
    {
        // Speichern der aktuellen Cursorposition
        cursor->iY -= CURSOR_OFFSET_ZEILE;
        cursor->iAktuelleSpielfeldZeile--;

        // Bewege den cursor an die gewuenschte Stelle
        move(cursor->iY, cursor->iX);
    }
}

/*******************************************************************************
Funktion BewegeCursorRunter()
Uebergabe Parameter:    *cursor
Rueckgabe:              -
Beschreibung:           Bewegt den Cursor ein Spielfeld und den entsprechenden
                        Wert der y-Koordinate nach unten, wenn dieser in der
                        Grenze bleibt.
*******************************************************************************/
void BewegeCursorRunter(CURSOR *cursor)
{
    if(cursor->iAktuelleSpielfeldZeile < 9)
    {
        // Speichern der aktuellen Cursorposition
        cursor->iY += CURSOR_OFFSET_ZEILE;
        cursor->iAktuelleSpielfeldZeile++;

        // Bewege den cursor an die gewuenschte Stelle
        move(cursor->iY, cursor->iX);
    }
}