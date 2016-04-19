/*
Autor(en)               : Jennifer Hermanns
Klasse                  : FA11
Programmname            : datenbankanbindung.c
Datum                   : 18.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "datenbankanbindung.h"

/*******************************************************************************
Funktion Einloggen()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/

/*******************************************************************************
Funktion Registrieren()
Uebergabe Parameter:    -
Rueckgabe:              0 - Registrierung war erfolgreich
                        1 - Registrierung ist fehlgeschlagen
Beschreibung:           
*******************************************************************************/
int Registrieren(char *cNachname, char *cVorname,
                 char *cNickname, char *cPasswort)
{
    
    int iRueckgabe;
    char *sql, *cErrMsg;

    iRueckgabe = sqlite3_open(DATENBANK_SUDOKU, &db_handle);

    if (iRueckgabe != SQLITE_OK)
    {
        exit(iRueckgabe);
    }

    sql = sqlite3_mprintf("INSERT INTO Benutzer (Name, Vorname, "
        "Nickname, Passwort) "
        "VALUES ('%s', '%s', '%s', '%s')",
        cNachname, cVorname, cNickname, cPasswort);

    iRueckgabe = sqlite3_exec(db_handle, sql, NULL, NULL, &cErrMsg);

    sqlite3_free(sql);
    sqlite3_close(db_handle);

    if (iRueckgabe == SQLITE_OK)
    {
        return 0;
    }
    else
    {
        printf("%s", cErrMsg);
        return -1;
    }
    
}
/*******************************************************************************
Funktion SudokuBereitstellen()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/

/*******************************************************************************
Funktion LoesungsBereitstellen()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/