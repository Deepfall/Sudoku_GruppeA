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
Uebergabe Parameter:    cNickname[], cPasswort[]
Rueckgabe:              0 - Einloggen war erfolgreich
                        1 - Einloggen ist fehlgeschlagen
Beschreibung:           Es wird mit Hilfe des eingegebenen Nicknamen in der 
                        Datenbank ueber einen Select-Befehl geprueft, ob zum 
                        einen dieser Nickname vorhanden ist und zum anderen das 
                        in der Benutzer-Tabelle gespeicherte Passwort mit dem 
                        eingegebenen uebereinstimmt.
*******************************************************************************/
int Einloggen(char *cNickname, char *cPasswort)
{
    int iRueckgabe = -1, iSpalten, iSpalte;
    char sql[1000]; 
    const char *data;
    sqlite3_stmt *stmt;
    sqlite3 *db_handle;

    DatenbankOeffnen(&db_handle);

    sprintf(sql, "SELECT Passwort "
                 "FROM Benutzer WHERE Nickname = '%s';", cNickname);

    // Ausfuehren des SELECT-Befehls
    sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);
    iSpalten = sqlite3_column_count(stmt);

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        for(iSpalte = 0; iSpalte < iSpalten; iSpalte++)
        {
            data = (const char *) sqlite3_column_text(stmt, iSpalte);

            if(strcmp(data,cPasswort) == 0)
            {
                iRueckgabe = 0;
            }
        }
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db_handle);

    return iRueckgabe;
}

/*******************************************************************************
Funktion Registrieren()
Uebergabe Parameter:    cNachname[], cVorname[], cNickname[], cPasswort[]
Rueckgabe:              0 - Registrierung war erfolgreich
                        1 - Registrierung ist fehlgeschlagen
Beschreibung:           Mit den eingegebenen Daten (Nachname, Vorname, Nickname
                        und Passwort) wird ein neuer Benutzer in der Tabelle 
                        Benutzer angelegt.
*******************************************************************************/
int Registrieren(char cNachname[], char cVorname[],
                 char cNickname[], char cPasswort[])
{
    int iRueckgabe;
    char *sql, *cErrMsg;
    sqlite3 *db_handle;

    DatenbankOeffnen(&db_handle);

    // Ausfuehren des INSERT-Befehls
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
        return -1;
    }

}

/*******************************************************************************
Funktion SudokuBereitstellen()
Uebergabe Parameter:    cSudoku[], cLoesung[], iSchwierigkeit
Rueckgabe:              iRueckgabe
Beschreibung:           
*******************************************************************************/
int SudokuBereitstellen(char cSudoku[], char cLoesung[], int iSchwierigkeit)
{
    int iRueckgabe, iSudokuId;
    char sql[1000];
    sqlite3_stmt *stmt;
    sqlite3 *db_handle;

    DatenbankOeffnen(&db_handle);

    iSudokuId = GeneriereSudokuId(iSchwierigkeit);
    sprintf(sql, "SELECT Gefuellt, Loesung "
                 "FROM Sudoku WHERE Sudoku_ID = '%i' LIMIT 1", iSudokuId);

    iRueckgabe = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

    if(sqlite3_step(stmt) == SQLITE_ROW)
    {
        strcpy(cSudoku, (const char *) sqlite3_column_text(stmt, 0));
        strcpy(cLoesung, (const char *) sqlite3_column_text(stmt, 1));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db_handle);

    return iRueckgabe;
}

/*******************************************************************************
Funktion HighscoreEintragen()
Uebergabe Parameter:    iSchwierigkeit, ccNickname[], cZeit[]
Rueckgabe:              0 - Eintragen war erfolgreich
                        1 - Eintragen ist fehlgeschlagen
Beschreibung:           Es wird mit der Schwierigkeitsstufe des Sudokus, dem
                        Nicknamen und der gemessenen Zeit ein neuer Highscore
                        in die Highscore-Tabelle gemacht.
*******************************************************************************/
int HighscoreEintragen(int iSchwierigkeit, const char ccNickname[],
                       char cZeit[])
{
    int iRueckgabe;
    char *sql, *cErrMsg, *cSchwierigkeit;
    sqlite3 *db_handle;

    DatenbankOeffnen(&db_handle);

    switch(iSchwierigkeit)
    {
        case 1:
            cSchwierigkeit = "Leicht";
            break;
        case 2:
            cSchwierigkeit = "Mittel";
            break;
        case 3:
            cSchwierigkeit = "Schwer";
            break;
    }

    sql = sqlite3_mprintf("INSERT INTO Highscore "
                          "(Nickname, Schwierigkeit, Zeit)"
                          "VALUES ('%s', '%s', '%s')",
                          ccNickname, cSchwierigkeit, cZeit);

    iRueckgabe = sqlite3_exec(db_handle, sql, NULL, NULL, &cErrMsg);

    sqlite3_free(sql);
    sqlite3_close(db_handle);

    if (iRueckgabe == SQLITE_OK)
    {
        return 0;
    }
    else
    {
        return -1;
    }

}

/******************************************************************************
Funktion HighscoreAusgeben()
Uebergabe Parameter:    iSchwierigkeit
Rueckgabe:              iRueckgabe
Beschreibung:           Die Highscores werden entsprechend der Schwierigkeits-
                        stufe ueber einen Select-Befehl aus der Highscore-
                        Tabelle geordnet nach der kleinsten Zeit rausgelesen
                        und dann in der Sodoku-Anwendung angezeigt.   
******************************************************************************/
int HighscoreAusgeben(int iSchwierigkeit)
{
    int iRueckgabe = -1, iSpalten, iSpalte, iZaehler = 1;
    char sql[1000], *cSchwierigkeit = "";
    const char *data;
    sqlite3_stmt *stmt;
    sqlite3 *db_handle;

    DatenbankOeffnen(&db_handle);
  
    switch(iSchwierigkeit)
    {
        case 1:
            cSchwierigkeit = "Leicht";
            break;
        case 2:
            cSchwierigkeit = "Mittel";
            break;
        case 3:
            cSchwierigkeit = "Schwer";
            break;
    }

    sprintf(sql, "SELECT Nickname, Zeit FROM Highscore "
                 "WHERE Schwierigkeit = '%s' " 
                 "ORDER BY Zeit ASC LIMIT 5;"
                 , cSchwierigkeit);

    iRueckgabe = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);
    iSpalten = sqlite3_column_count(stmt);

    clear();

    printw("\n");
    printw("\t\t\t\tS U D O K U\n\n");
    printw("\t\t\t     H I G H S C O R E\n\n");
    printw("\t\t\t\t  (%s)\n\n", cSchwierigkeit);
    printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
    printw("\t\t============================================\n\n");
    printw("\t\t%4s\t%-20s\t%-8s\n\n", "Rang", "Nickname", "Zeit");

    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        for(iSpalte = 0; iSpalte < iSpalten; iSpalte++)
        {
            data = (const char *) sqlite3_column_text(stmt, iSpalte);

            if(iSpalte % 2 == 0)
            {
                printw("\t\t%4d\t%-20s", iZaehler++, data);
            }
            else
            {
                printw("\t%-8s\n\n", data);
            }
        }
    }

    printw("\t\t============================================\n\n");
    printw("\t<Zum Fortfahren eine beliebige Taste druecken>");
    
    getch();
    refresh();

    sqlite3_finalize(stmt);
    sqlite3_close(db_handle);

    return iRueckgabe;
}

void DatenbankOeffnen(sqlite3 **db_handle)
{
    if(sqlite3_open(DATENBANK_SUDOKU, db_handle) != SQLITE_OK)
    {
        exit(SQLITE_CANTOPEN);
    }
}