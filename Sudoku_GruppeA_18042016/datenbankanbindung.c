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
#include "helpers.h"

/*******************************************************************************
Funktion Einloggen()
Uebergabe Parameter:    cNickname
cPasswort
Rueckgabe:              0 - Einloggen war erfolgreich
1 - Einloggen ist fehlgeschlagen
Beschreibung:           
*******************************************************************************/
int Einloggen(char *cNickname, char *cPasswort)
{
    int iRueckgabe = -1, iSpalten, iSpalte;
    char sql[1000]; 
    const char *data;
    sqlite3_stmt *stmt;
    sqlite3 *db_handle;

    if (sqlite3_open(DATENBANK_SUDOKU, &db_handle) != SQLITE_OK)
    {
        exit(SQLITE_CANTOPEN);
    }

    sprintf(sql, "SELECT Passwort "
                 "FROM Benutzer WHERE Nickname = '%s';", cNickname);

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
    highscoreAusgeben(1);
    getch();
    return iRueckgabe;

}

/*******************************************************************************
Funktion Registrieren()
Uebergabe Parameter:    cNachname
cVorname
cNickname
cPasswort
Rueckgabe:              0 - Registrierung war erfolgreich
1 - Registrierung ist fehlgeschlagen
Beschreibung:           
*******************************************************************************/
int Registrieren(char *cNachname, char *cVorname,
                 char *cNickname, char *cPasswort)
{
    int iRueckgabe;
    char *sql, *cErrMsg;
    sqlite3 *db_handle;

    iRueckgabe = sqlite3_open(DATENBANK_SUDOKU, &db_handle);

    if (iRueckgabe != SQLITE_OK)
    {
        exit(SQLITE_CANTOPEN);
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
int SudokuBereitstellen(char *cDaten, int iSchwierigkeit)
{
    int iRueckgabe, iSudokuId;
    char sql[1000];
    sqlite3_stmt *stmt;
    sqlite3 *db_handle;

    iRueckgabe = sqlite3_open(DATENBANK_SUDOKU, &db_handle);

    if (iRueckgabe != SQLITE_OK)
    {
        exit(SQLITE_CANTOPEN);
    }

    iSudokuId = generiereSudokuId(iSchwierigkeit);
    sprintf(sql, "SELECT Gefuellt "
                 "FROM Sudoku WHERE Sudoku_ID = '%i' LIMIT 1", iSudokuId);

    iRueckgabe = sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);

    if(sqlite3_step(stmt) == SQLITE_ROW)
    {
        strcpy(cDaten, (const char *) sqlite3_column_text(stmt, 0));
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db_handle);

    return iRueckgabe;
}

/*******************************************************************************
Funktion LoesungsBereitstellen()
Uebergabe Parameter:    -
Rueckgabe:              void
Beschreibung:           
*******************************************************************************/
/*******************************************************************************
Funktion highscoreEintragen()
Uebergabe Parameter:    cSchwierigkeit
                        cNickname
                        cZeit
cVorname
cNickname
cPasswort
Rueckgabe:              0 - Registrierung war erfolgreich
1 - Registrierung ist fehlgeschlagen
Beschreibung:           
*******************************************************************************/
int highscoreEintragen(int iSchwierigkeit,char* cNickname,char* cZeit)
{
    char * cSchwierigkeit;
    int iRueckgabe;
    char *sql, *cErrMsg;
    sqlite3 *db_handle;

    iRueckgabe = sqlite3_open(DATENBANK_SUDOKU, &db_handle);

    if (iRueckgabe != SQLITE_OK)
    {
        exit(SQLITE_CANTOPEN);
    }
    switch(iSchwierigkeit)
    {
    case 1:
        cSchwierigkeit="Leicht";
        break;
    case 2:
        cSchwierigkeit="Mittel";
        break;
    case 3:
        cSchwierigkeit="Schwer";
        break;
    }
    sql = sqlite3_mprintf("insert into Highscore"
                          "(Nickname, Schwierigkeit, Zeit)"
                          "VALUES ('%s', '%s', '%s')",
                          cNickname, cSchwierigkeit,cZeit);

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

/******************************************************************************
Funktion highscoreAusgeben()
Uebergabe Parameter:    iSchwierigkeit
cPasswort
Rueckgabe:              0 - Einloggen war erfolgreich
1 - Einloggen ist fehlgeschlagen
Beschreibung:           
******************************************************************************/
int highscoreAusgeben(int iSchwierigkeit)
{
    int iRueckgabe = -1, iSpalten, iSpalte,iZaehler=0;
    char sql[1000]; 
    char* cSchwierigkeit="";
    char* cText="";
    const char *data;
    sqlite3_stmt *stmt;
    sqlite3 *db_handle;

    if (sqlite3_open(DATENBANK_SUDOKU, &db_handle) != SQLITE_OK)
    {
        exit(SQLITE_CANTOPEN);
    }
  
    switch(iSchwierigkeit)
    {
    case 1:
        cSchwierigkeit="Leicht";
        cText="(Leicht)";
        break;
    case 2:
        cSchwierigkeit="Mittel";
        cText="(Mittel)";
        break;
    case 3:
        cSchwierigkeit="Schwer";
        cText="(Schwer)";
        break;
    }

    getch();

    sprintf(sql, "Select Nickname, Zeit from Highscore "
                 "where Schwierigkeit = '%s' " 
                 "order by Zeit asc limit 5;"
                 , cSchwierigkeit);


    sqlite3_prepare_v2(db_handle, sql, strlen(sql), &stmt, NULL);
    iSpalten = sqlite3_column_count(stmt);

    clear();
    printw("\n");
    printw("\t\t\t\tS U D O K U\n\n");
    printw("\t\t\t     H I G H S C O R E\n\n");
    printw("\t\t%25s\n\n",cText);
    printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
    printw("\t\t============================================\n\n");
    printw("\t\t%4s\t%-20s\t%-8s\n\n","Rang","Nickname","Zeit");
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        for(iSpalte = 0; iSpalte < iSpalten; iSpalte++)
        {
            data = (const char *) sqlite3_column_text(stmt, iSpalte);
            if(iSpalte % 2 == 0)
            {
                printw("\t\t%4d\t%-20s",++iZaehler,data);
            }
            else
            {
                printw("\t%-8s\n\n",data);
            }
           
        }

        refresh();
    }
    printw("\t\t============================================\n\n");
    sqlite3_finalize(stmt);
    sqlite3_close(db_handle);
    return iRueckgabe;

}