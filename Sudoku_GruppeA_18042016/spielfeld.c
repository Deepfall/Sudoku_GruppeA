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

    SudokuBereitstellen(cSudoku, cLoesung, iSchwierigkeit);

    cSudokuWert = strtok(cSudoku, ccTrenner);

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        spielfelder[i].iWert = 0;
        spielfelder[i].iIstVorbefuellt = FALSE;

        if(cSudokuWert != NULL && cSudokuWert[0] >= '1'
           && cSudokuWert[0] <= '9')
        {
            iWert = (int) cSudokuWert[0] - 48;
            spielfelder[i].iWert = iWert;
            spielfelder[i].iIstVorbefuellt = TRUE;
        }

        cSudokuWert = strtok(NULL, ccTrenner);
    }

    cLoesungWert = strtok(cLoesung, ccTrenner);

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        spielfelder[i].iLoesung = 0;

        if(cLoesungWert != NULL && cLoesungWert[0] >= '1'
           && cLoesungWert[0] <= '9')
        {
            spielfelder[i].iLoesung = (int) cLoesungWert[0] - 48;
        }

        cLoesungWert = strtok(NULL, ccTrenner);
    }
}

/*******************************************************************************
Funktion SchreibeZahlInFeld()
Uebergabe Parameter:    *sudokufeld
Rueckgabe:              -
Beschreibung:           Schreibt eine Zahl an die aktuelle Cursorpostition und
                        speichert diese im Feld.
*******************************************************************************/
void SchreibeZahlInFeld(SUDOKUFELD *sudokufeld, CURSOR cursor, int iZahl)
{
    if(!sudokufeld->iIstVorbefuellt)
    {
        sudokufeld->iWert = iZahl;
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
        sudokufeld->iWert = 0;
        mvprintw(cursor.iY, cursor.iX, " ");
    }
}

/*******************************************************************************
Funktion HilfeBenutzen()
Uebergabe Parameter:    cursor, sudokufelder[],
                        *iStrafSekunden, *iAnzahlHilfeGenutzt
Rueckgabe:              sudokufelder[], *iStrafSekunden, *iAnzahlHilfeGenutzt
Beschreibung:           Fuellt das Feld an der aktuellen Cursorposítion mit dem
                        Loesungwert, addiert die definierte Anzahl von
                        Strafsekunden auf das Konto des Benutzers und blockiert
                        die Eingabe fuer dieses Feld.
*******************************************************************************/
void HilfeBenutzen(CURSOR cursor, SUDOKUFELD sudokufelder[],
                   int *iStrafSekunden, int *iAnzahlHilfeGenutzt)
{
    int iFeld = cursor.iAktuelleSpielfeldSpalte 
                + ((cursor.iAktuelleSpielfeldZeile - 1) * 9) - 1;

    if(!sudokufelder[iFeld].iIstVorbefuellt)
    {
        SchreibeZahlInFeld(&sudokufelder[iFeld], cursor,
                           sudokufelder[iFeld].iLoesung);

        *iStrafSekunden += HILFE_STRAFZEIT;
        (*iAnzahlHilfeGenutzt)++;
        sudokufelder[iFeld].iIstVorbefuellt = TRUE;
    }
}

/*******************************************************************************
Funktion PruefeFelderManuell()
Uebergabe Parameter:    sudokufelder[]
Rueckgabe:              TRUE - Feld stimmt nicht mit Loesung ueberein
                        FALSE - Feld stimmt mit Loesung ueberein
Beschreibung:           Ueberprueft, ob das Feld mit der Loesung uebereinstimmt.
                        Wenn dies nicht der Fall ist, gibt die Funktion TRUE
                        zurueck.
*******************************************************************************/
int PruefeFelderManuell(SUDOKUFELD sudokufelder[])
{
    int i;

    for(i = 0; i < ANZAHL_SPIELFELDER; i++)
    {
        if(sudokufelder[i].iWert != sudokufelder[i].iLoesung)
        {
            return TRUE;
        }
    }

    return FALSE;
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
        if(sudokufelder[i].iWert == 0)
        {
            return FALSE;
        }
    }

    return TRUE;
}