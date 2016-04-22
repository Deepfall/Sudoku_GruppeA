/*
Autor(en)               : Robin grahl, Dustin Welz
Klasse                  : FA11
Programmname            : helpers.c
Datum                   : 20.04.2016
Beschreibung            :
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "helpers.h"

/*******************************************************************************
Funktion GeneriereSudokuId()
Uebergabe Parameter:    iSchwierigkeit
Rueckgabe:              iSudokuId
Beschreibung:           Erzeugt eine Sudoku ID fuer eine Datenbankabfrage
                        anhand der Schwierigkeit des Sudokus.
*******************************************************************************/
int GeneriereSudokuId(int iSchwierigkeit)
{
    int iSudokuId = -1;

    switch (iSchwierigkeit)
    {
    case 1:
        iSudokuId = GeneriereZufallszahlReichweite(1, 10);
        break;
    case 2:
        iSudokuId = GeneriereZufallszahlReichweite(11, 20);
        break;
    case 3:
        iSudokuId = GeneriereZufallszahlReichweite(21, 30);
        break;
    }

    return iSudokuId;
}

/*******************************************************************************
Funktion GeneriereZufallszahlReichweite()
Uebergabe Parameter:    iMinimum, iMaximum
Rueckgabe:              iZufallszahl
Beschreibung:           Erzeugt eine Zufallszahl von {iMinimum} bis {iMaximum}.
*******************************************************************************/
int GeneriereZufallszahlReichweite(int iMinimum, int iMaximum)
{
    int iZufallszahl;

    // Salz streuen
    srand(time(NULL));

    // Berechnen einer Zufallszahl zwischen iMinimum und iMaximum
    iZufallszahl = rand() % (iMaximum - iMinimum + 1) + iMinimum;

    return iZufallszahl;
}

/*******************************************************************************
Funktion EntferneLeerzeichenAusString()
Uebergabe Parameter:    cString[]
Rueckgabe:              cString[]
Beschreibung:           Entfernt alle Leerzeichen aus dem uebergebenen String.
*******************************************************************************/
void EntferneLeerzeichenAusString(char cString[])
{
    char *i = cString;
    char *j = cString;

    while (*j != 0)
    {
        *i = *j++;

        if (*i != ' ')
        {
            i++;
        }
    }

    *i = 0;
}

/*******************************************************************************
Funktion PruefeAufValideStringlaenge()
Uebergabe Parameter:    cString[], uiMindestLaenge, uiMaximalLaenge
Rueckgabe:               0 - Text hat eine valide Laenge
                        -2 - Text ist zu lang
                        -3 - Text ist zu kurz
                        -1 - Text ist falsch
Beschreibung:           Prueft einen String auf seine Laenge.
                        Diese darf mindestens {uiMindestLaenge} und
                        maximal {uiMaximalLaenge} sein.
*******************************************************************************/
int PruefeAufValideStringlaenge(char cString[], 
                                unsigned int uiMindestLaenge, 
                                unsigned int uiMaximalLaenge)
{
    unsigned int iStringLaenge;

    EntferneLeerzeichenAusString(cString);
    iStringLaenge = strlen(cString);

    if (iStringLaenge > uiMaximalLaenge)
    {
        return -2;
    }

    if (iStringLaenge < uiMindestLaenge)
    {
        return -3;
    }
    
    return 0;
}

/*******************************************************************************
Funktion AusgabeFehlermeldungValideTextlaenge()
Uebergabe Parameter:    iFehlerId, ccFeldname[]
Rueckgabe:              -
Beschreibung:           Ausgabe einer Fehlermeldung anhand der {iFehlerId}.
*******************************************************************************/
void AusgabeFehlermeldungValideTextlaenge(int iFehlerId,
                                          const char ccFeldname[])
{
    switch (iFehlerId)
    {
        case -3:
            printw("%s ist zu kurz!\n", ccFeldname);
            break;
        case -2:
            printw("%s ist zu lang!\n", ccFeldname);
            break;
        case -1:
            printw("%s ist falsch!\n", ccFeldname);
            break;
    }
}

/*******************************************************************************
Funktion SpielregelnAnzeigen()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Oeffnen der HTML-Datei, die die Regeln zu dem Spiel
                        enthaelt.
*******************************************************************************/
void SpielregelnAnzeigen(void)
{
    /* Das Programm zum Oeffnen einer HTML-Datei muss fuer andere
       Betriebssysteme angepasst werden */
    char cKommando[_MAX_PATH] = "start iexplore.exe ";
    char cPfad[_MAX_PATH] = "";

    // Erstellen des Kommandos, um die Regeln.html zu oeffnen
    AusgabeAbsoulterPfad(cPfad, "Regeln.html");
    strcat(cKommando, cPfad);

    // Kommando ausfuehren
    system(cKommando);
}

/*******************************************************************************
Funktion AusgabeAbsoulterPfad()
Uebergabe Parameter:    cAusgabe[], ccDateiname[]
Rueckgabe:              cAusgabe[]
Beschreibung:           Ausgeben des absoulten Dateipfades einer Datei, um zu
                        gewaehrleisten, dass diese relativ zur EXE-Datei aus
                        geoeffnet werden kann.
*******************************************************************************/
void AusgabeAbsoulterPfad(char cAusgabe[], const char ccDateiname[])
{
    char cPfad[_MAX_PATH] = "";

    // Hole den aktuellen Pfad und haenge {ccDateiname} an
    _fullpath(cAusgabe, ccDateiname, _MAX_PATH);

    // Pfad in "" setzen, damit Leerzeichen keine Fehler verursachen
    strcat(cPfad, "\"");
    strcat(cPfad, cAusgabe);
    strcat(cPfad, "\"");

    // Fuer die Rueckgabe in {cAusgabe} kopieren
    strcpy(cAusgabe, cPfad);
}