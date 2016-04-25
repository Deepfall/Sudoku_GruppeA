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
Funktion Startmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Startmenue, welches als erstes erscheint,
                        wenn das Programm gestartet wird. Von diesem aus kann
                        der Spieler sich einloggen, registrieren, direkt in das
                        Spielmenue navigieren oder das Programm beenden.
*******************************************************************************/
void Startmenue(void)
{
    int iEingabe = -1;

    // Laeuft bis zum Ende des Programmms
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

        refresh(); // Eigentliches Zeichnen der Ausgabe

        iEingabe = getch(); // Tastendruck einlesen

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
Funktion Spielmenue()
Uebergabe Parameter:    cNickname[]
Rueckgabe:              -
Beschreibung:           Erstellt das Spielmenue von dem der Spieler sich zu 
                        einer neuen Spielrunde, der Bestenliste, den Regeln oder
                        zurueck zum Startmenue navigieren kann.
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
        printw("\t\t\t\t   [L] Logout / Verlassen\n\n");
        printw("\t\t\t\t============================================");

        refresh(); // Eigentliches Zeichnen der Ausgabe

        iEingabe = getch(); // Tastendruck einlesen

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
                cNickname = NULL; // Benutzer ausloggen
                // Schleife bricht ab
                break;
        }
    }
}

/*******************************************************************************
Funktion Schwierigkeitsstufenmenue()
Uebergabe Parameter:    ccNickname[]
Rueckgabe:              -
Beschreibung:           Erstellt das Menue fuer die 3 Schwierigkeitsstufen
                        eines Sudokus.
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
        printw("\n\n\n\t\t\t\t\t     Schwierigkeitsstufe\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t   [L] Leicht\n\n");
        printw("\t\t\t\t   [M] Mittel\n\n");
        printw("\t\t\t\t   [S] Schwer\n\n");
        printw("\t\t\t\t============================================");

        refresh(); // Eigentliches Zeichnen der Ausgabe

        iEingabe = getch(); // Tastendruck einlesen

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
                        Auswahl der anzuzeigenden Highscores.
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

        refresh(); // Eigentliches Zeichnen der Ausgabe

        iEingabe = getch(); // Tastendruck einlesen

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
Funktion Loginmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Menue fuer das Einloggen eines Benutzers.
                        Dafuer muessen der Nickname und das Passwort eingegeben
                        werden.
*******************************************************************************/
void Loginmenue(void)
{
    char cNickname[TEXTLAENGE + 1] = "", cPasswort[TEXTLAENGE + 1] = "";
    int iRueckgabe = -1;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Benutzereingabe anzeigen lassen 
    timeout(-1); // Timeout deaktivieren
    clear(); // Bildschirm leeren

    // Ausgabe des Menues zum Einloggen
    printw("\n\n\n\t\t\t\t\t\tEinloggen\n\n");
    printw("\t\t\t\t============================================\n\n");
    printw("\t\t\t\t   Falls Sie sich nicht einloggen wollen,\n");
    printw("\t\t\t\t   druecken Sie [Q] um ins Hauptmenue\n");
    printw("\t\t\t\t   zurueckzukehren\n\n");
    printw("\t\t\t\t   Bitte geben Sie ihre Daten ein.\n\n\n");

    printw("\t\t\t\t   Nickname: ");
    getnstr(cNickname, TEXTLAENGE); // Einlesen des Nicknamenn

    if (strcmp(cNickname, "Q") != 0 && strcmp(cNickname, "q") != 0)
    {
        /* Wir wollen das Passwort niemandem zeigen, also
        Benutzereingabe verstecken */
        noecho();

        printw("\t\t\t\t   Passwort: ");
        getnstr(cPasswort, TEXTLAENGE); // Einlesen des Passwortes

        printw("\n\n\t\t\t\t============================================\n\n");

        // Weitergabe an die Datenbankanbindung
        iRueckgabe = Einloggen(cNickname, cPasswort);

        if (iRueckgabe == 0)
        {
            // Ausgabe der Erfolgsmeldung
            printw("\t\t\t\t   Erfolgreich eingeloggt.\n\n");
            printw("\t\t\t\t   Druecken Sie eine beliebige Taste...");

            refresh(); // Eigentliches Zeichnen der Ausgabe
            getch(); // Tastendruck einlesen

            Spielmenue(cNickname);
        }
        else
        {
            // Ausgabe der Fehlermeldung
            printw("\t\t\t\t   Einloggen ist fehlgeschlagen.\n\n");
            printw("\t\t\t\t   Druecken Sie eine beliebige Taste...");

            refresh(); // Eigentliches Zeichnen der Ausgabe
            getch(); // Tastendruck einlesen
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
    char cNachname[TEXTLAENGE + 1], cVorname[TEXTLAENGE + 1],
         cNickname[TEXTLAENGE + 1], cPasswort[TEXTLAENGE + 1];
    int iRichtig;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Benutzereingabe anzeigen lassen
    timeout(-1); // Timeout deaktivieren
    clear(); // Bildschirm leeren

    iRichtig = -10; // Zuruecksetzen der Kontrollvariable
    while (iRichtig != 0)
    {
        clear(); // Bildschirm leeren

        // Ausgabe des Menues zum Registrieren
        printw("\n\n\n\t\t\t\t\t\tRegistrierung\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t Bitte fuellen Sie die folgenden Felder aus.\n");

        AusgabeFehlermeldungValideTextlaenge(iRichtig, NACHNAME);
        printw("\n\t\t\t\t Nachname (max. 20 Zeichen): ");
        getnstr(cNachname, TEXTLAENGE); // Einlesen des Nachnamens
        iRichtig = PruefeAufValideStringlaenge(cNachname, 1, TEXTLAENGE);
    }

    iRichtig = -10; // Zuruecksetzen der Kontrollvariable
    while (iRichtig != 0)
    {
        clear(); // Bildschirm leeren

        // Ausgabe des Menues zum Registrieren
        printw("\n\n\n\t\t\t\t\t\tRegistrierung\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t Bitte fuellen Sie die folgenden Felder aus.\n");

        AusgabeFehlermeldungValideTextlaenge(iRichtig, VORNAME);
        printw("\n\t\t\t\t Vorname  (max. 20 Zeichen): ");
        getnstr(cVorname, TEXTLAENGE); // Einlesen des Vornamens
        iRichtig = PruefeAufValideStringlaenge(cVorname, 1, TEXTLAENGE);
    }

    iRichtig = -10; // Zuruecksetzen der Kontrollvariable
    while (iRichtig != 0)
    {
        clear(); // Bildschirm leeren

        // Ausgabe des Menues zum Registrieren
        printw("\n\n\n\t\t\t\t\t\tRegistrierung\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t Bitte fuellen Sie die folgenden Felder aus.\n");

        AusgabeFehlermeldungValideTextlaenge(iRichtig, NICKNAME);
        printw("\n\t\t\t\t Nickname (max. 20 Zeichen): ");
        getnstr(cNickname, TEXTLAENGE); // Einlesen des Nicknamens

        // Verhindern, dass man den Benutzer "Q" oder "q" registrieren kann
        if (strcmp(cNickname, "Q") == 0 || strcmp(cNickname, "q") == 0)
        {
            iRichtig = -1;
        }
        else
        {
            iRichtig = PruefeAufValideStringlaenge(cNickname, 1, TEXTLAENGE);
        }
    }

    // Wir wollen das Passwort niemandem zeigen, also Benutzereingabe verstecken
    noecho();

    iRichtig = -10; // Zuruecksetzen der Kontrollvariable
    while (iRichtig != 0)
    {
        clear(); // Bildschirm leeren

        // Ausgabe des Menues zum Registrieren
        printw("\n\n\n\t\t\t\t\t\tRegistrierung\n\n");
        printw("\t\t\t\t============================================\n\n");
        printw("\t\t\t\t Bitte fuellen Sie die folgenden Felder aus.\n");

        AusgabeFehlermeldungValideTextlaenge(iRichtig, PASSWORT);
        printw("\n\t\t\t\t Passwort  (min. 6 Zeichen): ");
        getnstr(cPasswort, TEXTLAENGE); // Einlesen des Passwortes
        iRichtig = PruefeAufValideStringlaenge(cPasswort, 6, TEXTLAENGE);
    }

    printw("\n\n\t\t\t\t=============================================\n\n");

    // Weitergabe an die Datenbankanbindung
    if (Registrieren(cNachname, cVorname, cNickname, cPasswort) == 0)
    {
        clear(); // Bildschirm leeren
        printw("\n\n\n\t\t\t\t Die Registrierung war erfolgreich.\n\n");
        printw("\t\t\t\t Druecken Sie eine beliebige Taste...");
        refresh(); // Eigentliches Zeichnen der Ausgabe
        getch(); // Tastendruck einlesen
    }
    else
    {
        clear(); // Bildschirm leeren
        printw("\n\n\n\t\t\t\t Die Registrierung ist fehlgeschlagen.\n");
        printw("\t\t\t\t Der Nickname ist bereits vergeben.\n\n");
        printw("\t\t\t\t Druecken Sie eine beliebige Taste...");
        refresh(); // Eigentliches Zeichnen der Ausgabe
        getch(); // Tastendruck einlesen
    }
}

/*******************************************************************************
Funktion SpielGewonnenMenue()
Uebergabe Parameter:    ccZeit[]
Rueckgabe:              -
Beschreibung:           Erstellt den Bildschirm, der nach einem gewonnenen
                        Sudoku erscheint.
*******************************************************************************/
void SpielGewonnenMenue(const char ccZeit[])
{
    noecho(); // Benutzereingabe verstecken
    curs_set(0); // Cursor unsichtbar machen
    timeout(-1); // Timeout deaktivieren
    clear(); // Bildschirm leeren

    // Ausgabe des Gewinnerbildschrimes
    printw("\n\t\t\t\t============================================\n\n");
    printw("\t\t\t          ,---.o         |         |              \n");
    printw("\t\t\t          `---..,---.    |---.,---.|---.,---.,---.\n");
    printw("\t\t\t              |||---'    |   |,---||   ||---'|   |\n");
    printw("\t\t\t          `---'``---'    `   '`---^`---'`---'`   '\n");
    printw("\t\t\t                                                  \n");
    printw("\t\t\t                                                  \n");
    printw("\t\t\t                                                  \n");
    printw("\t\t\t          ,---.,---.. . .,---.,---.,---.,---.,---.\n");
    printw("\t\t\t          |   ||---'| | ||   ||   ||   ||---'|   |\n");
    printw("\t\t\t          `---|`---'`-'-'`---'`   '`   '`---'`   '\n");
    printw("\t\t\t          `---'                                   \n\n\n\n");
    printw("\t\t\t                 Ihre Zeit betraegt: %s\n\n", ccZeit);
    printw("\t\t\t\t============================================\n\n");
    printw("\t\t\t\t   Druecken Sie eine beliebige Taste...");

    getch(); // Tastendruck einlesen
}



/*******************************************************************************
Funktion InBestenlisteEintragenDialog()
Uebergabe Parameter:    iSchwierigkeit, ccNickname[], ccZeit[]
Rueckgabe:              -
Beschreibung:           Erstellt das Menue zur Abfrage eines eingeloggten 
                        Spielers, ob dieser sich in die Bestenliste eintragen
                        lassen moechte.
*******************************************************************************/
void InBestenlisteEintragenDialog(int iSchwierigkeit, const char ccNickname[],
                                  const char ccZeit[])
{
    int iEingabe = -1, cFalscheEingabe = TRUE;

    noecho(); // Benutzereingabe versetecken
    curs_set(0); // Cursor unsichtbar machen
    clear(); // Bildschirm leeren

    // Ausgabe des Menues fuer die Schwierigkeitsstufen
    printw("\n\n\t\t\t\t\t\tS U D O K U\n\n");
    printw("\t\t\t\t\t     H I G H S C O R E\n\n");
    printw("\t\t\t\t============================================\n\n");
    printw("\t\t\t\t   Wollen Sie sich in die Bestenliste\n");
    printw("\t\t\t\t   eintragen?\n\n");
    printw("\t\t\t\t   [J] Ja\n\n");
    printw("\t\t\t\t   [N] Nein\n\n");
    printw("\t\t\t\t============================================\n\n");

    refresh(); // Eigentliches Zeichnen der Ausgabe

    // Abfangen der unerwuenschten Buchstaben
    while (cFalscheEingabe)
    {
        iEingabe = getch(); // Tastendruck einlesen

        switch(iEingabe)
        {
            case 'J':
            case 'j':
                HighscoreEintragen(iSchwierigkeit, ccNickname, ccZeit);
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