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
Rueckgabe:              0 - Einloggen war erfolgreich
                        1 - Einloggen ist fehlgeschlagen
Beschreibung:           
*******************************************************************************/
int Einloggen(char *cNickname, char *cPasswort)
{
    int iRueckgabe, cols, col;
    char sql[1000];
    const char *data;
    sqlite3_stmt *stmt;

    iRueckgabe = sqlite3_open(DATENBANK_SUDOKU, &db_handle);

    if (iRueckgabe != SQLITE_OK)
    {
        exit(iRueckgabe);
    }

    sprintf(sql, "SELECT Passwort "
                 "FROM Benutzer WHERE Nickname = '%s'", cNickname);

    printw("\n\n%s", sql);

    iRueckgabe = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);
    cols = sqlite3_column_count(stmt);

    printw("\n\n");

    /*for (col = 0; col < cols; col++)
    {
        printw("%20s ", (const char*) sqlite3_column_name(stmt, col));
    }
    */
    printf("\n");
    clear();
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        for(col = 0; col < cols; col++)
        {
            data = (const char *) sqlite3_column_text(stmt, col);
            printw("%s %s", data, cPasswort); 
            if(strcmp(data,cPasswort) == 0)
            { 
                printw("Passwort ist korrekt.");
                printw("Der Benutzer konnte sich erfolgreich einloggen.");
                iRueckgabe = 0;
            }
            else
            {
                printw("Passwort ist inkorrekt.");
                printw("Das eingegebene Passwort ist inkorrekt.");
                iRueckgabe = -1;
            }
            //printw("%20s ", data ? data : "NULL");
        }
        refresh();
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db_handle);

    return iRueckgabe;
    
}

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