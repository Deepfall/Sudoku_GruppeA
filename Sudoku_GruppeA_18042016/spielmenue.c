/*
Autor(en)               : Dominik Elis, Robin Grahl, Dustin Welz, David Fischer,
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
    int iRueckgabe = -1, iKorrekt = -1;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Benutzereingabe anzeigen lassen 
    timeout(-1); // Timeout deaktivieren
	clear(); // Bildschirm leeren

	printw("\nEinloggen\n\n");
	printw("============================================\n\n");
    printw("Bitte geben Sie ihre Daten ein.\n\n");

    // Einlesen des Nicknamen
	printw("Nickname: ");
	getstr(cNickname);

    /* Wir wollen das Passwort niemandem zeigen, also
        Benutzereingabe verstecken */
    noecho();

    // Einlesen des Passwortes
	printw("Passwort: ");
	getstr(cPasswort);

	printw("\n\n============================================");

    // Weitergabe an die Datenbankanbindung
	iRueckgabe = Einloggen(cNickname, cPasswort);  

    if(iRueckgabe == 0)
    {
	    clear(); // Bildschirm leeren
		printw("Erfolgreich eingeloggt.\n\n");
		printw("Druecken Sie eine beliebige Taste...");
        refresh();
        getch();
        Spielmenue(cNickname);
    }
    else
    {
	    clear(); // Bildschirm leeren
		printw("Einloggen ist fehlgeschlagen.\n\n");
		printw("Druecken Sie eine beliebige Taste...");
        refresh();
        getch();
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
	while(iRichtig != 0)
    {
        clear(); // Bildschirm leeren

        // Ausgabe des Registrierungsmenues
	    printw("\nRegistrierung\n\n");
	    printw("============================================\n\n");
	    printw("Bitte fuellen Sie die folgenden Felder aus.\n");

		AusgabeFehlermeldungValideTextlaenge(iRichtig, NACHNAME);
        printw("\nNachname (max. 20 Zeichen): ");
		getstr(cNachname);
		iRichtig = PruefeAufValideStringlaenge(cNachname, 1, 20);
	}

	iRichtig = -10;
	while(iRichtig != 0)
	{
		clear(); // Bildschirm leeren

        // Ausgabe des Registrierungsmenues
	    printw("\nRegistrierung\n\n");
	    printw("============================================\n\n");
	    printw("Bitte fuellen Sie die folgenden Felder aus.\n");
        
		AusgabeFehlermeldungValideTextlaenge(iRichtig, VORNAME);
        printw("\nVorname  (max. 20 Zeichen): ");
		getstr(cVorname);
		iRichtig = PruefeAufValideStringlaenge(cVorname, 1, 20);
	}

	iRichtig = -10;
	while(iRichtig != 0)
	{
		clear(); // Bildschirm leeren
		
        // Ausgabe des Registrierungsmenues
	    printw("\nRegistrierung\n\n");
	    printw("============================================\n\n");
	    printw("Bitte fuellen Sie die folgenden Felder aus.\n");
        
		AusgabeFehlermeldungValideTextlaenge(iRichtig, NICKNAME);
        printw("\nNickname (max. 20 Zeichen): ");
		getstr(cNickname);
		iRichtig = PruefeAufValideStringlaenge(cNickname, 1, 20);
	}

    // Wir wollen das Passwort niemandem zeigen, also Benutzereingabe verstecken
    noecho();

    iRichtig = -10;
	while(iRichtig != 0)
	{
		clear(); // Bildschirm leeren
        
        // Ausgabe des Registrierungsmenues
	    printw("\nRegistrierung\n\n");
	    printw("============================================\n\n");
	    printw("Bitte fuellen Sie die folgenden Felder aus.\n");

		AusgabeFehlermeldungValideTextlaenge(iRichtig, PASSWORT);
		printw("\nPasswort  (min. 6 Zeichen): ");
		getstr(cPasswort);
		printw("\n");
		iRichtig = PruefeAufValideStringlaenge(cPasswort, 6, 20);
	}

    printw("\n\n=============================================\n\n");

    // Weitergabe an die Datenbankanbindung
    if (Registrieren(cNachname, cVorname, cNickname, cPasswort) == 0)
    {
        clear(); // Bildschirm leeren
        printw("Die Registrierung war erfolgreich.\n\n");
		printw("Druecken Sie eine beliebige Taste...");
        refresh();
        getch();
        Startmenue();
    }
    else
    {
        clear(); // Bildschirm leeren
        printw("Die Registrierung ist fehlgeschlagen.\n");
        printw("Der Nickname ist bereits vergeben.\n\n");
		printw("Druecken Sie eine beliebige Taste...");
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
    char cEingabe = -1, cFalscheEingabe = TRUE;

    // Abfangen der unerwuenschten Buchstaben
    while(cFalscheEingabe)
    {
        curs_set(0); // Cursor unsichtbar machen
        clear(); // Bildschirm leeren

        // Ausgabe des Menues fuer die Schwierigkeitsstufen
        printw("\nSchwierigkeitsstufe\n\n");
        printw("============================================\n\n");
        printw("[L] Leicht\n\n");
        printw("[M] Mittel\n\n");
        printw("[S] Schwer\n\n");
        printw("============================================");

        refresh();

        cEingabe = getch();

        switch(cEingabe)
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
void HighscoreSchwierigkeitsStufenMenue()
{
    char cEingabe = -1, cFalscheEingabe = TRUE;

    // Abfangen der unerwuenschten Buchstaben
    while(cFalscheEingabe)
    {
        curs_set(0); // Cursor unsichtbar machen
        clear(); // Bildschirm leeren

        // Ausgabe des Menues fuer die Schwierigkeitsstufen
        printw("\nS U D O K U\n\n");
        printw("(C) HHBK Tendo Research Center\n\n");
        printw("============================================\n\n");
        printw("[L] Leicht\n\n");
        printw("[M] Mittel\n\n");
        printw("[S] Schwer\n\n");
        printw("============================================");

        refresh();

        cEingabe = getch();

        switch(cEingabe)
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
    char cEingabe = -1;

    // Abfangen der unerwuenschten Buchstaben
    while(cEingabe != 'L' && cEingabe != 'l')
    {
	    noecho(); // Benutzereingabe versetecken
        curs_set(0); // Cursor unsichtbar machen
        clear(); // Bildschirm leeren

        // Ausgabe des Spielmenues
        printw("\nSpielmenue\n\n");
        printw("============================================\n\n");
        printw("[N] Neues Spiel\n\n");
        printw("[R] Spielregeln\n\n");
        printw("[B] Bestenliste\n\n");
        printw("[L] Logout\n\n");
        printw("============================================");

        refresh();

        cEingabe = getch();

        switch(cEingabe)
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
	printw("\n");
	printw("\n\n");
	printw("                    ,---.o         |         |              \n");
	printw("                    `---..,---.    |---.,---.|---.,---.,---.\n");
	printw("                        |||---'    |   |,---||   ||---'|   |\n");
	printw("                    `---'``---'    `   '`---^`---'`---'`   '\n");
	printw("                                                            \n");
	printw("                                                            \n");
	printw("                                                            \n");
	printw("                    ,---.,---.. . .,---.,---.,---.,---.,---.\n");
	printw("                    |   ||---'| | ||   ||   ||   ||---'|   |\n");
	printw("                    `---|`---'`-'-'`---'`   '`   '`---'`   '\n");
	printw("                    `---'                                   \n");
	printw("\n");
	printw("\n");
	printw("\n");
	printw("\n");
	printw("                        Deine Zeit betraegt : %s\n", cZeit);
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
    char cEingabe = -1;

    // Abfangen der unerwuenschten Buchstaben
    while(cEingabe != 'X' && cEingabe != 'x')
    {
        noecho(); // Benutzereingabe versetecken
        curs_set(0); // Cursor unsichtbar machen
        clear(); // Bildschirm leeren

        // Ausgabe des Startmenues
        printw("\nS U D O K U\n\n");
        printw("(C) HHBK Tendo Research Center\n\n");
        printw("============================================\n\n");
        printw("[E] Einloggen\n\n");
        printw("[N] Nicht einloggen\n\n");
        printw("[R] Registrieren\n\n");
        printw("[X] Beenden\n\n");
        printw("============================================");

        refresh();

        cEingabe = getch();

        switch(cEingabe)
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
                exit(0);
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
	char cEingabe = -1, cFalscheEingabe = TRUE;
	int iAntwort = -1;
    
	noecho(); // Benutzereingabe versetecken
    curs_set(0); // Cursor unsichtbar machen
    clear(); // Bildschirm leeren

    // Ausgabe des Menues fuer die Schwierigkeitsstufen
    printw("\nS U D O K U\n\n");
    printw("(C) HHBK Tendo Research Center\n\n");
    printw("============================================\n");
    printw("Wollen Sie sich in die Bestenliste eintragen?\n\n");
    printw("[J] Ja\n\n");
    printw("[N] Nein\n\n");
    printw("============================================\n\n");

    refresh();

    // Abfangen der unerwuenschten Buchstaben
    while(cFalscheEingabe)
    {
        cEingabe = getch();

        switch(cEingabe)
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