/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Wels, David Fischer,
Jennifer Hermanns
Klasse                  : FA11
Programmname            : .c
Datum                   : 18.04.2016
Beschreibung            : 
Version                 : 
Aenderungen             : 
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "spielmenue.h"


/*******************************************************************************
Funktion LoggInmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Menue für das Einloggen eines Benutzers, 
dafür muessen der Nickname und das Passwort eingegeben 
werden. 
*******************************************************************************/
void LoggInmenue(void)
{
    char cNickname[TEXTLAENGE];
    char cPasswort[TEXTLAENGE];

    int iRueckgabe;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Eingabe anzeigen lassen 
    timeout(-1); //timeout deaktivieren

    clear();
    printw("\n");
    printw("\t\t\t\tS U D O K U\n\n");
    printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
    printw("\t\t============================================\n\n");
    printw("\t\t\tBitte geben Sie ihre Daten ein,\n"
        "\t\t\tum sich erfolgreich anzumelden.\n\n");
    printw("\t\t\tNickname: ");
    getstr(cNickname);
    printw("\t\t\tPasswort: ");
    getstr(cPasswort);
    printw("\t\t============================================\n\n");

    // Weitergabe an die Datenbankanbindung

    iRueckgabe = Einloggen(cNickname, cPasswort); 

    if(iRueckgabe == 0)
    {
        Spielmenue();
    }
    else
    {
        StartMenue();
    }

    noecho();
}

/*******************************************************************************
Funktion Registrierungsmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Menue für die Registrierung eines neuen
Benutzers. Fuer die Registrierung werden Nachname, 
Vorname, Nickname und ein Passwort benötigt.
*******************************************************************************/
void Registrierungsmenue(void)
{
    char cNachname[TEXTLAENGE];
    char cVorname[TEXTLAENGE];
    char cNickname[TEXTLAENGE];
    char cPasswort[TEXTLAENGE];

    int iRueckgabe;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Eingabe anzeigen lassen 
    timeout(-1); //timeout deaktivieren

    // Ausgabe des Registrierungsmenues
    clear();
    printw("\n");
    printw("\t\t\t\tS U D O K U\n\n");
    printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
    printw("\t\t============================================\n\n");
    printw("\t\t\tBitte f\204llen Sie die folgenden Felder aus um.\n");
    printw("\n\t\t\tNachname (max. 20 Zeichen): ");
    getstr(cNachname);

    printw("\n\t\t\tVorname  (max. 20 Zeichen): ");
    getstr(cVorname);

    printw("\n\t\t\tNickname (max. 20 Zeichen): ");
    getstr(cNickname);

    //curs_set(0); // Cursor unsichtbar machen
    printw("\n\t\t\tPasswort  (min. 6 Zeichen): ");
    getstr(cPasswort);
    printw("\n\n\t\t============================================\n\n");


    // Weitergabe an die Datenbankanbindung
    iRueckgabe = Registrieren(cNachname, cVorname, cNickname, cPasswort);

    if (iRueckgabe == 0)
    {
        printf("\nDie Registrierung war erfolgreich.\n\n");
        //timeout(10000);
        StartMenue();
    }
    else
    {
        printf("\nDie Registrierung ist fehlgeschlagen.\n\n");
        timeout(5000);
        StartMenue();
    }

    noecho();
}

/*******************************************************************************
Funktion Schwierigkeitsstufenmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Menue für die 3 Schwierigkeitsstufen.
*******************************************************************************/
void SchwierigkeitsStufenMenue(void)
{
    char cEingabe = -1, cFalscheEingabe = TRUE;

    // Abfangen der unerwuenschten Buchstaben
    while(cFalscheEingabe)
    {
        curs_set(0); // Cursor unsichtbar machen
        clear();

        // Ausgabe des Menues für die Schwierigkeitsstufen
        printw("\n");
        printw("\t\t\t\tS U D O K U\n\n");
        printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
        printw("\t\t============================================\n\n");
        printw("\t\t\t[L]\tLeicht\n\n");
        printw("\t\t\t[M]\tMittel\n\n");
        printw("\t\t\t[S]\tSchwer\n\n");
        printw("\t\t============================================\n\n");

        refresh();

        cEingabe = getch();

        switch(cEingabe)
        {
        case 'L':
        case 'l':
            NeuesSpiel();
            cFalscheEingabe = FALSE;
            break;
        case 'M':
        case 'm':
            NeuesSpiel();
            cFalscheEingabe = FALSE;
            break;
        case 'S':
        case 's':
            NeuesSpiel();
            cFalscheEingabe = FALSE;
            break;
        }
    }
}

/*******************************************************************************
Funktion Spielmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Spielmenue.
*******************************************************************************/
void Spielmenue(void)
{
    char cEingabe = -1;

    // Abfangen der unerwuenschten Buchstaben
    while(cEingabe != 'L' && cEingabe != 'l')
    {
        curs_set(0); // Cursor unsichtbar machen
        clear();

        // Ausgabe des Spielmenues
        printw("\n");
        printw("\t\t\t\tS U D O K U\n\n");
        printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
        printw("\t\t============================================\n\n");
        printw("\t\t\t[N]\tNeues Spiel\n\n");
        printw("\t\t\t[R]\tSpielregeln\n\n");
        printw("\t\t\t[B]\tBestenliste\n\n");
        printw("\t\t\t[L]\tLogout\n\n");
        printw("\t\t============================================\n\n");

        refresh();

        cEingabe = getch();

        switch(cEingabe)
        {
        case 'N': 
        case 'n':
            SchwierigkeitsStufenMenue();
            break;
        case 'R': 
        case 'r':
            SpielregelnAnzeigen();
            break;
        case 'B': 
        case 'b':
            break;
        case 'L': 
        case 'l':
            break;
        }
    }

}

/*******************************************************************************
Funktion StartMenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Startmenü.
*******************************************************************************/
void StartMenue(void)
{
    char cEingabe = -1;

    // Abfangen der unerwuenschten Buchstaben
    while(cEingabe != 'X' && cEingabe != 'x')
    {
        curs_set(0); // Cursor unsichtbar machen
        clear();

        // Ausgabe des Startmenues
        printw("\n");
        printw("\t\t\t\tS U D O K U\n\n");
        printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
        printw("\t\t============================================\n\n");
        printw("\t\t\t[E]\tEinloggen\n\n");
        printw("\t\t\t[N]\tNicht einloggen\n\n");
        printw("\t\t\t[R]\tRegistrieren\n\n");
        printw("\t\t\t[X]\tBeenden\n\n");
        printw("\t\t============================================\n\n");

        refresh();

        cEingabe = getch();

        switch(cEingabe)
        {
        case 'E':
        case 'e':
            LoggInmenue();
            break;
        case 'N':
        case 'n':
            Spielmenue();
            break;
        case 'R':
        case 'r':
            Registrierungsmenue();
            break;
        case 'X':
        case 'x':
            break;
        }
    }
}
/*******************************************************************************
Funktion SpielregelnAnzeigen()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Oeffnen der HTML-Datei, die die Regeln zu dem Spiel
enth\204lt.
*******************************************************************************/
void SpielregelnAnzeigen(void)
{
    system("start firefox.exe file://W:/LF06/Wissemann/Projekt_GruppeA/Regeln.html");
}