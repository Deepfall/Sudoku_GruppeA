/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
                          Jennifer Hermanns
Klasse                  : FA11
Programmname            : datenbankanbindung.c
Datum                   : 18.04.2016
Beschreibung            : Beinhaltet alle Funktionen die mit der Datenbank
                          kommunizieren.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "datenbankanbindung.h"

/*******************************************************************************
Funktion Einloggen()
Uebergabe Parameter:    *cNickname, *cPasswort
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
    int iRueckgabe = -1;
    char sql[1000]; 
    const char *data;
    sqlite3_stmt *stmt;
    sqlite3 *db_handle;

    DatenbankOeffnen(&db_handle);

    // Aufbauen des Select-Befehls
    sprintf(sql, "SELECT Passwort "
                 "FROM Benutzer WHERE Nickname = '%s';", cNickname);

    // Ausfuehren des Select-Befehls
    sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

    if(sqlite3_step(stmt) == SQLITE_ROW)
    {
        data = (const char *) sqlite3_column_text(stmt, 0);

        // Vergleiche das eingegebene Passwort mit dem ausgelesenen Passwort
        if(strcmp(data, cPasswort) == 0)
        {
            iRueckgabe = 0;
        }
    }

    // Speicher freigeben
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

    // Aufbauen des INSERT-Befehls
    sql = sqlite3_mprintf("INSERT INTO Benutzer (Name, Vorname, "
                          "Nickname, Passwort) "
                          "VALUES ('%s', '%s', '%s', '%s')",
                          cNachname, cVorname, cNickname, cPasswort);

    // Ausfuehren des Select-Befehls
    iRueckgabe = sqlite3_exec(db_handle, sql, NULL, NULL, &cErrMsg);

    // Speicher freigeben
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
Beschreibung:           Es wird ein Sudoku anhand der SudokuId aus der Sudoku-
                        Tabelle selektiert.
*******************************************************************************/
int SudokuBereitstellen(char cSudoku[], char cLoesung[], int iSchwierigkeit)
{
    int iRueckgabe, iSudokuId;
    char sql[1000];
    sqlite3_stmt *stmt;
    sqlite3 *db_handle;

    DatenbankOeffnen(&db_handle);

    iSudokuId = GeneriereSudokuId(iSchwierigkeit);
    // Aufbauen des Select-Befehls
    sprintf(sql, "SELECT Gefuellt, Loesung "
                 "FROM Sudoku WHERE Sudoku_ID = '%i' LIMIT 1", iSudokuId);

    // Ausfuehren des Select-Befehls
    iRueckgabe = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

    if(sqlite3_step(stmt) == SQLITE_ROW)
    {
        // Speichern der Daten in die uebergebenen Parameter
        strcpy(cSudoku, (const char *) sqlite3_column_text(stmt, 0));
        strcpy(cLoesung, (const char *) sqlite3_column_text(stmt, 1));
    }

    // Speicher freigeben
    sqlite3_finalize(stmt);
    sqlite3_close(db_handle);

    return iRueckgabe;
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
  
    // Je nach gewaehlter Schwierigkeit wird der Select-Befehl angepasst
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

    // Aufbauen des Select-Befehls
    sprintf(sql, "SELECT Nickname, Zeit FROM Highscore "
                 "WHERE Schwierigkeit = '%s' " 
                 "ORDER BY Zeit ASC LIMIT 10;"
                 , cSchwierigkeit);

    // Ausfuehren des Select-Befehls
    iRueckgabe = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);
    iSpalten = sqlite3_column_count(stmt);

    clear(); // Bildschirm leeren

    /* Anzeigen der 10 schnellesten Spiele des 
       ausgewaehlten Schwierigkeitsgerades */ 
    printw("\n\n\t\t\t\t\t\tS U D O K U\n\n");
    printw("\t\t\t\t\t     H I G H S C O R E\n\n");
    printw("\t\t\t\t\t\t  (%s)\n\n", cSchwierigkeit);
    printw("\t\t\t\t============================================\n\n");
    printw("\t\t\t\t   %4s\t%-20s\t %-8s\n\n", "Rang", "Nickname", "Zeit");

    // Solange es gelesene Zeilen gibt sollen die Daten ausgelesen werden
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        for(iSpalte = 0; iSpalte < iSpalten; iSpalte++)
        {
            data = (const char *) sqlite3_column_text(stmt, iSpalte);

            // Ausgeben der Ergebnisse des Select-Befehls
            if(iSpalte % 2 == 0)
            {
                printw("\t\t\t\t%4d\t%-20s", iZaehler++, data);
            }
            else
            {
                printw("\t %-8s\n\n", data);
            }
        }
    }

    printw("\t\t\t\t============================================\n\n");
    printw("\t\t\t\t   Druecken Sie eine beliebige Taste...");
    getch();

    // Speicher freigeben
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
    char *sql, *cErrMsg, *cSchwierigkeit = "";
    sqlite3 *db_handle;

    DatenbankOeffnen(&db_handle);

    // Zuordnung der Schwierigkeit fuer das Abspeichern in der Highscore-Tabelle
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

    // Aufbauen des Insert-Befehls
    sql = sqlite3_mprintf("INSERT INTO Highscore "
                          "(Nickname, Schwierigkeit, Zeit)"
                          "VALUES ('%s', '%s', '%s')",
                          ccNickname, cSchwierigkeit, cZeit);

    // Ausfuehren des Insert-Befehls
    iRueckgabe = sqlite3_exec(db_handle, sql, NULL, NULL, &cErrMsg);

    // Speicher freigeben
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
Funktion DatenbankOeffnen()
Uebergabe Parameter:    **db_handle
Rueckgabe:              -
Beschreibung:           Oeffnen einer Datenbankverbindung mit Fehlerbehandlung.   
******************************************************************************/
void DatenbankOeffnen(sqlite3 **db_handle)
{
    // Versuche die Datenbank zu oeffnen
    if(sqlite3_open(DATENBANK_SUDOKU, db_handle) != SQLITE_OK)
    {
        exit(SQLITE_CANTOPEN);
    }
}