/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : spielfeld.c
Datum                   : 18.04.2016
Beschreibung            : Dieses Modul enthaelt alle Funktionen die mit dem
                          Spielfeld zu tun haben.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "spielfeld.h"

/*******************************************************************************
Funktion BefuelleSpielfelder()
Uebergabe Parameter:    spielfelder[], iSchwierigkeit
Rueckgabe:              -
Beschreibung:           Befuellt die Spielfelder mit Werten aus der Datenbank
                        und speichert die Loesungen und Vorbelegungen in der
                        Struktur.
*******************************************************************************/
void BefuelleSpielfelder(SUDOKUFELD spielfelder[], int iSchwierigkeit)
{
    char cSudoku[1000], cLoesung[1000], *cSudokuWert, *cLoesungWert;
    const char *ccTrenner = ";";
    int i, iWert;

    // Sudoku und Loesung aus der Datenbank auslesen
    SudokuBereitstellen(cSudoku, cLoesung, iSchwierigkeit);

    // Teile den String anhand der ";" auf um die einzelnen Werte zu erfassen
    cSudokuWert = strtok(cSudoku, ccTrenner);

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        // Standardwerte setzen
        spielfelder[i].iWert = 0;
        spielfelder[i].iIstVorbefuellt = FALSE;

        // Nur Zahlen annehmen
        if(cSudokuWert != NULL && cSudokuWert[0] >= '1'
           && cSudokuWert[0] <= '9')
        {
            // ASCII-Char zu integer
            iWert = (int) cSudokuWert[0] - 48;

            // Feld befuellen
            spielfelder[i].iWert = iWert;
            spielfelder[i].iIstVorbefuellt = TRUE;
        }

        // Den naechsten Wert holen
        cSudokuWert = strtok(NULL, ccTrenner);
    }

    // Teile den String anhand der ";" auf um die einzelnen Werte zu erfassen
    cLoesungWert = strtok(cLoesung, ccTrenner);

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        // Standardwerte setzen
        spielfelder[i].iLoesung = 0;

        // Nur Zahlen annehmen
        if(cLoesungWert != NULL && cLoesungWert[0] >= '1'
           && cLoesungWert[0] <= '9')
        {
            // ASCII-Char zu integer und Feld befuellen
            spielfelder[i].iLoesung = (int) cLoesungWert[0] - 48;
        }

        // Den naechsten Wert holen
        cLoesungWert = strtok(NULL, ccTrenner);
    }
}

/*******************************************************************************
Funktion SchreibeZahlInFeld()
Uebergabe Parameter:    *sudokufeld, cursor, iZahl
Rueckgabe:              -
Beschreibung:           Schreibt eine Zahl an die aktuelle Cursorpostition und
                        speichert diese im Feld.
*******************************************************************************/
void SchreibeZahlInFeld(SUDOKUFELD *sudokufeld, CURSOR cursor, int iZahl)
{
    if(!sudokufeld->iIstVorbefuellt)
    {
        // Setz den Wert
        sudokufeld->iWert = iZahl;

        // Zeichne den neuen Wert in das Feld
        mvprintw(cursor.iY, cursor.iX, "%i", iZahl);
    }
}

/*******************************************************************************
Funktion LoescheZahlAusFeld()
Uebergabe Parameter:    *sudokufeld, cursor
Rueckgabe:              -
Beschreibung:           Loescht die Zahl an der aktuellen Cursorposition und
                        setzt das Feld auf 0.
*******************************************************************************/
void LoescheZahlAusFeld(SUDOKUFELD *sudokufeld, CURSOR cursor)
{
    if(!sudokufeld->iIstVorbefuellt)
    {
        // Setz den Wert zurueck
        sudokufeld->iWert = 0;

        // Ueberschreibe den Wert mit einem Leerzeichen
        mvprintw(cursor.iY, cursor.iX, " ");
    }
}

/*******************************************************************************
Funktion HilfeBenutzen()
Uebergabe Parameter:    cursor, sudokufelder[], *iAnzahlHilfeGenutzt
Rueckgabe:              -
Beschreibung:           Fuellt das Feld an der aktuellen Cursorposition mit dem
                        Loesungwert, addiert die definierte Anzahl von
                        Strafsekunden auf das Konto des Benutzers und blockiert
                        die Eingabe fuer dieses Feld.
*******************************************************************************/
void HilfeBenutzen(CURSOR cursor, SUDOKUFELD sudokufelder[],
                   int *iAnzahlHilfeGenutzt)
{
    // Berechne Index des aktuell ausgewaehlten Feldes anhand der Cursorposition
    int iFeld = cursor.iAktuelleSpielfeldSpalte 
                + ((cursor.iAktuelleSpielfeldZeile - 1) * 9) - 1;

    if(!sudokufelder[iFeld].iIstVorbefuellt)
    {
        // Wenn Farbmodus aktiv
        if(has_colors())
        {
            attron(COLOR_PAIR(2)); // Faerbe Wert Gelb - Start
        }

        SchreibeZahlInFeld(&sudokufelder[iFeld], cursor,
                           sudokufelder[iFeld].iLoesung);

        // Inkrementiere Anzahl genutzter Hilfen
        (*iAnzahlHilfeGenutzt)++;

        // Blockiere Benutzereingabe fuer das Feld
        sudokufelder[iFeld].iIstVorbefuellt = TRUE;

        // Wenn Farbmodus aktiv
        if(has_colors())
        {
            attroff(COLOR_PAIR(2)); // Faerbe Wert Gelb - Ende
        }
    }
}

/*******************************************************************************
Funktion FelderKorrektAusgefuellt()
Uebergabe Parameter:    sudokufelder[]
Rueckgabe:              TRUE - Alle Felder stimmen mit der Loesung ueberein
                        FALSE - Ein Feld stimmt nicht mit der Loesung ueberein
Beschreibung:           Ueberprueft, ob alle Felder mit der Loesung
                        uebereinstimmen.
*******************************************************************************/
int FelderKorrektAusgefuellt(SUDOKUFELD sudokufelder[])
{
    int i;

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        // Wenn nur ein Feld falsch ist, ist auch das Sudoku falsch ausgefuellt
        if(sudokufelder[i].iWert != sudokufelder[i].iLoesung)
        {
            return FALSE;
        }
    }

    return TRUE;
}

/*******************************************************************************
Funktion AlleFelderGefuellt()
Uebergabe Parameter:    sudokufelder[]
Rueckgabe:              TRUE - Alle Felder sind gefuellt
                        FALSE - Mindestens 1 Feld ist noch nicht gefuellt
Beschreibung:           Ueberprueft, ob alle Felder gefuellt sind.
*******************************************************************************/
int AlleFelderGefuellt(SUDOKUFELD sudokufelder[]) 
{
    int i;

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        // Wenn nur ein Feld nicht ausgefuellt ist, ist es auch das Sudoku nicht
        if(sudokufelder[i].iWert == 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}