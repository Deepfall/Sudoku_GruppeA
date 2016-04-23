/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
Jennifer Hermanns
Klasse                  : FA11
Programmname            : spielmenue.c
Datum                   : 18.04.2016
Beschreibung            : Eine Sammlung der im Projekt verwendeteten
Spielmenues.
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

/*******************************************************************************
Praeprozessoranweisungen
*******************************************************************************/
#include "spielmenue.h"

/*******************************************************************************
Funktion Loginmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Menue fuer das Einloggen eines Benutzers.
Dafuer muessen der Nickname und das Passwort eingegeben
werden.
*******************************************************************************/
void Loginmenue(void)
{
    char cNickname[TEXTLAENGE] = "", cPasswort[TEXTLAENGE] = "";
    int iRueckgabe = -1;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Benutzereingabe anzeigen lassen 
    timeout(-1); // Timeout deaktivieren
    clear(); // Bildschirm leeren

    printw("\n\n\n\t\t\t\t\t\tEinloggen\n\n");
    printw("\t\t\t\t============================================\n\n");
    printw("\t\t\t\t   Falls Sie sich nicht einloggen wollen,\n");
    printw("\t\t\t\t   druecken Sie [Q] um ins Hauptmenue\n");
    printw("\t\t\t\t   zurueckzukehren\n\n");
    printw("\t\t\t\t   Bitte geben Sie ihre Daten ein.\n\n\n");

    // Einlesen des Nicknamen
    printw("\t\t\t\t   Nickname: ");
    getstr(cNickname);

    if (strcmp(cNickname, "Q") != 0 && strcmp(cNickname, "q") != 0)
    {
        /* Wir wollen das Passwort niemandem zeigen, also
        Benutzereingabe verstecken */
        noecho();

        // Einlesen des Passwortes
        printw("\t\t\t\t   Passwort: ");
        getstr(cPasswort);

        printw("\n\n\t\t\t\t============================================\n\n");

        // Weitergabe an die Datenbankanbindung
        iRueckgabe = Einloggen(cNickname, cPasswort);

        if (iRueckgabe == 0)
        {
            printw("\t\t\t\t   Erfolgreich eingeloggt.\n\n");
            printw("\t\t\t\t   Druecken Sie eine beliebige Taste...");
            refresh();
            getch();
            Spielmenue(cNickname);
        }
        else
        {
            printw("\t\t\t\t   Einloggen ist fehlgeschlagen.\n\n");
            printw("\t\t\t\t   Druecken Sie eine beliebige Taste...");
            refresh();
            getch();
        }
    }
}

/*******************************************************************************
Funktion Registrierungsmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Menue fuer die Registrierung eines neuen
Benutzers. Fuer die Registrierung werden ein Nachname,
Vorname, Nickname und ein Passwort benoetigt.
*******************************************************************************/
void Registrierungsmenue(void)
{
    char cNachname[TEXTLAENGE], cVorname[TEXTLAENGE],
        cNickname[TEXTLAENGE], cPasswort[TEXTLAENGE];
    int iRichtig;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Benutzereingabe anzeigen lassen
    timeout(-1); // Timeout deaktivieren
    clear(); // Bildschirm leeren

    iRichtig = -10;
    while (iRichtig != 0)
    {
        clear(); // Bildschirm leeren

                 // Ausgabe des Registrierungsmenues
        printw("\n\n\n\t\t\t\t\t\tRegistrierung\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t Bitte fuellen Sie die folgenden Felder aus.\n");

        AusgabeFehlermeldungValideTextlaenge(iRichtig, NACHNAME);
        printw("\n\t\t\t\t Nachname (max. 20 Zeichen): ");
        getstr(cNachname);
        iRichtig = PruefeAufValideStringlaenge(cNachname, 1, 20);
    }

    iRichtig = -10;
    while (iRichtig != 0)
    {
        clear(); // Bildschirm leeren

                 // Ausgabe des Registrierungsmenues
        printw("\n\n\n\t\t\t\t\t\tRegistrierung\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t Bitte fuellen Sie die folgenden Felder aus.\n");

        AusgabeFehlermeldungValideTextlaenge(iRichtig, VORNAME);
        printw("\n\t\t\t\t Vorname  (max. 20 Zeichen): ");
        getstr(cVorname);
        iRichtig = PruefeAufValideStringlaenge(cVorname, 1, 20);
    }

    iRichtig = -10;
    while (iRichtig != 0)
    {
        clear(); // Bildschirm leeren

                 // Ausgabe des Registrierungsmenues
        printw("\n\n\n\t\t\t\t\t\tRegistrierung\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t Bitte fuellen Sie die folgenden Felder aus.\n");

        AusgabeFehlermeldungValideTextlaenge(iRichtig, NICKNAME);
        printw("\n\t\t\t\t Nickname (max. 20 Zeichen): ");
        getstr(cNickname);
        iRichtig = PruefeAufValideStringlaenge(cNickname, 1, 20);
    }

    // Wir wollen das Passwort niemandem zeigen, also Benutzereingabe verstecken
    noecho();

    iRichtig = -10;
    while (iRichtig != 0)
    {
        clear(); // Bildschirm leeren

                 // Ausgabe des Registrierungsmenues
        printw("\n\n\n\t\t\t\t\t\tRegistrierung\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t Bitte fuellen Sie die folgenden Felder aus.\n");

        AusgabeFehlermeldungValideTextlaenge(iRichtig, PASSWORT);
        printw("\n\t\t\t\t Passwort  (min. 6 Zeichen): ");
        getstr(cPasswort);
        printw("\n");
        iRichtig = PruefeAufValideStringlaenge(cPasswort, 6, 20);
    }

    printw("\n\n\t\t\t\t=============================================\n\n");

    // Weitergabe an die Datenbankanbindung
    if (Registrieren(cNachname, cVorname, cNickname, cPasswort) == 0)
    {
        clear(); // Bildschirm leeren
        printw("\n\n\n\t\t\t\t Die Registrierung war erfolgreich.\n\n");
        printw("\t\t\t\t Druecken Sie eine beliebige Taste...");
        refresh();
        getch();
        Startmenue();
    }
    else
    {
        clear(); // Bildschirm leeren
        printw("\n\n\n\t\t\t\t Die Registrierung ist fehlgeschlagen.\n");
        printw("\t\t\t\t Der Nickname ist bereits vergeben.\n\n");
        printw("\t\t\t\t Druecken Sie eine beliebige Taste...");
        refresh();
        getch();
        Startmenue();
    }
}

/*******************************************************************************
Funktion Schwierigkeitsstufenmenue()
Uebergabe Parameter:    ccNickname[]
Rueckgabe:              -
Beschreibung:           Erstellt das Menue fuer die 3 Schwierigkeitsstufen.
*******************************************************************************/
void Schwierigkeitsstufenmenue(const char ccNickname[])
{
    int iEingabe = -1, cFalscheEingabe = TRUE;

    // Abfangen der unerwuenschten Buchstaben
    while (cFalscheEingabe)
    {
        curs_set(0); // Cursor unsichtbar machen
        clear(); // Bildschirm leeren

                 // Ausgabe des Menues fuer die Schwierigkeitsstufen
        printw("\n\n\n\t\t\t\t\t   Schwierigkeitsstufe\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t   [L] Leicht\n\n");
        printw("\t\t\t\t   [M] Mittel\n\n");
        printw("\t\t\t\t   [S] Schwer\n\n");
        printw("\t\t\t\t============================================");

        refresh();

        iEingabe = getch();

        switch(iEingabe)
        {
        case 'L':
        case 'l':
            NeuesSpiel(1, ccNickname);
            cFalscheEingabe = FALSE;
            break;
        case 'M':
        case 'm':
            NeuesSpiel(2, ccNickname);
            cFalscheEingabe = FALSE;
            break;
        case 'S':
        case 's':
            NeuesSpiel(3, ccNickname);
            cFalscheEingabe = FALSE;
            break;
        }
    }
}

/*******************************************************************************
Funktion HighscoreSchwierigkeitsStufenMenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Menue fuer die 3 Schwierigkeitsstufen zur
Auwahl der anzuzeigenden Highscore.
*******************************************************************************/
void HighscoreSchwierigkeitsStufenMenue(void)
{
    int iEingabe = -1, cFalscheEingabe = TRUE;

    // Abfangen der unerwuenschten Buchstaben
    while (cFalscheEingabe)
    {
        curs_set(0); // Cursor unsichtbar machen
        clear(); // Bildschirm leeren

                 // Ausgabe des Menues fuer die Schwierigkeitsstufen
        printw("\n\n\t\t\t\t\t\tS U D O K U\n\n");
        printw("\t\t\t\t\t     H I G H S C O R E\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t   [L] Leicht\n\n");
        printw("\t\t\t\t   [M] Mittel\n\n");
        printw("\t\t\t\t   [S] Schwer\n\n");
        printw("\t\t\t\t============================================");

        refresh();

        iEingabe = getch();

        switch(iEingabe)
        {
        case 'L':
        case 'l':
            HighscoreAusgeben(1);
            cFalscheEingabe = FALSE;
            break;
        case 'M':
        case 'm':
            HighscoreAusgeben(2);
            cFalscheEingabe = FALSE;
            break;
        case 'S':
        case 's':
            HighscoreAusgeben(3);
            cFalscheEingabe = FALSE;
            break;
        }
    }
}

/*******************************************************************************
Funktion Spielmenue()
Uebergabe Parameter:    cNickname
Rueckgabe:              -
Beschreibung:           Erstellt das Spielmenue.
*******************************************************************************/
void Spielmenue(char cNickname[])
{
    int iEingabe = -1;

    // Abfangen der unerwuenschten Buchstaben
    while(iEingabe != 'L' && iEingabe != 'l')
    {
        noecho(); // Benutzereingabe versetecken
        curs_set(0); // Cursor unsichtbar machen
        clear(); // Bildschirm leeren

                 // Ausgabe des Spielmenues
        printw("\n\n\n\t\t\t\t\t\tSpielmenue\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t   [N] Neues Spiel\n\n");
        printw("\t\t\t\t   [R] Spielregeln\n\n");
        printw("\t\t\t\t   [B] Bestenliste\n\n");
        printw("\t\t\t\t   [L] Logout\n\n");
        printw("\t\t\t\t============================================");

        refresh();

        iEingabe = getch();

        switch(iEingabe)
        {
        case 'N':
        case 'n':
            Schwierigkeitsstufenmenue(cNickname);
            break;
        case 'R':
        case 'r':
            SpielregelnAnzeigen();
            break;
        case 'B':
        case 'b':
            HighscoreSchwierigkeitsStufenMenue();
            break;
        case 'L':
        case 'l':
            cNickname = NULL;
            // Schleife bricht ab
            break;
        }
    }
}

/*******************************************************************************
Funktion SpielGewonnenMenue()
Uebergabe Parameter:    cZeit
Rueckgabe:              -
Beschreibung:           Erstellt das Spielmenue.
*******************************************************************************/
void SpielGewonnenMenue(char cZeit[])
{
    noecho(); // Benutzereingabe versetecken
    curs_set(0); // Cursor unsichtbar machen
    timeout(-1);
    clear(); // Bildschirm leeren

    printw("\n\t\t============================================\n\n");
    printw("                  ,---.o         |         |              \n");
    printw("                  `---..,---.    |---.,---.|---.,---.,---.\n");
    printw("                      |||---'    |   |,---||   ||---'|   |\n");
    printw("                  `---'``---'    `   '`---^`---'`---'`   '\n");
    printw("                                                          \n");
    printw("                                                          \n");
    printw("                                                          \n");
    printw("                  ,---.,---.. . .,---.,---.,---.,---.,---.\n");
    printw("                  |   ||---'| | ||   ||   ||   ||---'|   |\n");
    printw("                  `---|`---'`-'-'`---'`   '`   '`---'`   '\n");
    printw("                  `---'                                   \n");
    printw("\n\n\n");
    printw("                       Deine Zeit betraegt : %s\n", cZeit);
    printw("\t\t============================================\n\n");

    getch();
}

/*******************************************************************************
Funktion Startmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Startmenue.
*******************************************************************************/
void Startmenue(void)
{
    int iEingabe = -1;

    // Abfangen der unerwuenschten Buchstaben
    while(iEingabe != 'X' && iEingabe != 'x')
    {
        noecho(); // Benutzereingabe versetecken
        curs_set(0); // Cursor unsichtbar machen
        clear(); // Bildschirm leeren

                 // Ausgabe des Startmenues
        printw("\n\t\t\t\t\t\tS U D O K U\n\n");
        printw("\t\t\t\t\t(C) HHBK Tendo Research Center\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t   [E] Einloggen\n\n");
        printw("\t\t\t\t   [N] Nicht einloggen\n\n");
        printw("\t\t\t\t   [R] Registrieren\n\n");
        printw("\t\t\t\t   [X] Beenden\n\n");
        printw("\t\t\t\t============================================");

        refresh();

        iEingabe = getch();

        switch(iEingabe)
        {
        case 'E':
        case 'e':
            Loginmenue();
            break;
        case 'N':
        case 'n':
            Spielmenue("");
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
Funktion InBestenlisteEintragenDialog()
Uebergabe Parameter:    iSchwierigkeit, ccNickname, cZeit[]
Rueckgabe:              -
Beschreibung:
*******************************************************************************/
void InBestenlisteEintragenDialog(int iSchwierigkeit, const char ccNickname[],
    char cZeit[])
{
    int iEingabe = -1, cFalscheEingabe = TRUE;

    noecho(); // Benutzereingabe versetecken
    curs_set(0); // Cursor unsichtbar machen
    clear(); // Bildschirm leeren

             // Ausgabe des Menues fuer die Schwierigkeitsstufen
    printw("\n\t\t\t\tS U D O K U\n\n");
    printw("\t\t\t\t(C) HHBK Tendo Research Center\n\n");
    printw("\t\t\t\t============================================\n");
    printw("\t\t\t\t   Wollen Sie sich in die Bestenliste eintragen?\n\n");
    printw("\t\t\t\t   [J] Ja\n\n");
    printw("\t\t\t\t   [N] Nein\n\n");
    printw("\t\t\t\t============================================\n\n");

    refresh();

    // Abfangen der unerwuenschten Buchstaben
    while (cFalscheEingabe)
    {
        iEingabe = getch();

        switch(iEingabe)
        {
        case 'J':
        case 'j':
            HighscoreEintragen(iSchwierigkeit, ccNickname, cZeit);
            HighscoreAusgeben(iSchwierigkeit);
            cFalscheEingabe = FALSE;
            break;
        case 'N':
        case 'n':
            cFalscheEingabe = FALSE;
            break;
        }
    }
}