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
Funktion ErstelleNeuesMenueFenster()
Uebergabe Parameter:    -
Rueckgabe:              *menueFenster
Beschreibung:           Erstellt ein neues Fenster fuer ein Menue.
*******************************************************************************/
WINDOW *ErstelleNeuesMenueFenster(void)
{
    int iHoehe = 30, iBreite = 44;
    int iPositionY = 10, iPositionX = (COLS - iBreite) / 2;
    WINDOW *menueFenster = newwin(iHoehe, iBreite, iPositionY, iPositionX);

    return menueFenster;
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
    WINDOW *menueFenster = ErstelleNeuesMenueFenster();
    char cNickname[TEXTLAENGE] = "", cPasswort[TEXTLAENGE] = "";
    int iRueckgabe = -1, iKorrekt = -1;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Benutzereingabe anzeigen lassen 
    timeout(-1); // Timeout deaktivieren
	wclear(menueFenster); // Bildschirm leeren

	wprintw(menueFenster, "Einloggen\n\n");
	wprintw(menueFenster, "============================================\n");
    wprintw(menueFenster, "Bitte geben Sie ihre Daten ein.\n\n");

    // Einlesen des Nicknamen
	wprintw(menueFenster, "Nickname: ");
	wgetstr(menueFenster, cNickname);

    /* Wir wollen das Passwort niemandem zeigen, also
        Benutzereingabe verstecken */
    noecho();

    // Einlesen des Passwortes
	wprintw(menueFenster, "Passwort: ");
	wgetstr(menueFenster, cPasswort);

	wprintw(menueFenster, "\n\n============================================");

    // Weitergabe an die Datenbankanbindung
	iRueckgabe = Einloggen(cNickname, cPasswort);  

    if(iRueckgabe == 0)
    {
	    wclear(menueFenster); // Bildschirm leeren
		wprintw(menueFenster, "Erfolgreich eingeloggt.\n\n");
		wprintw(menueFenster, "Druecken Sie eine beliebige Taste...");
        wrefresh(menueFenster);
        getch();
        Spielmenue(cNickname);
    }
    else
    {
	    wclear(menueFenster); // Bildschirm leeren
		wprintw(menueFenster, "Log In ist fehlgeschlagen.\n\n");
		wprintw(menueFenster, "Druecken Sie eine beliebige Taste...");
        wrefresh(menueFenster);
        getch();
        Startmenue();
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
    WINDOW *menueFenster;
    char cNachname[TEXTLAENGE], cVorname[TEXTLAENGE],
         cNickname[TEXTLAENGE], cPasswort[TEXTLAENGE];
    int iRichtig;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Benutzereingabe anzeigen lassen
    timeout(-1); // Timeout deaktivieren
    menueFenster = ErstelleNeuesMenueFenster();
    wclear(menueFenster); // Bildschirm leeren

    // Ausgabe des Registrierungsmenues
	wprintw(menueFenster, "Registrierung\n\n");
	wprintw(menueFenster, "============================================\n");
	wprintw(menueFenster, "Bitte fuellen Sie die folgenden Felder aus.\n");

    iRichtig = -10;
	while(iRichtig != 0)
    {
        wprintw(menueFenster, "\nNachname (max. 20 Zeichen): ");
		wgetstr(menueFenster, cNachname);
		iRichtig = PruefeAufValideStringlaenge(cNachname, 1, 20);
		AusgabeFehlermeldungValideTextlaenge(menueFenster, iRichtig, NACHNAME);
	}

	iRichtig = -10;
	while(iRichtig != 0)
	{
		wprintw(menueFenster, "\nVorname  (max. 20 Zeichen): ");
		wgetstr(menueFenster, cVorname);
		iRichtig = PruefeAufValideStringlaenge(cVorname, 1, 20);
		AusgabeFehlermeldungValideTextlaenge(menueFenster, iRichtig, VORNAME);
	}

	iRichtig = -10;
	while(iRichtig != 0)
	{
		wprintw(menueFenster, "\nNickname (max. 20 Zeichen): ");
		wgetstr(menueFenster, cNickname);
		iRichtig = PruefeAufValideStringlaenge(cNickname, 1, 20);
		AusgabeFehlermeldungValideTextlaenge(menueFenster, iRichtig, NICKNAME);
	}

    // Wir wollen das Passwort niemandem zeigen, also Benutzereingabe verstecken
    noecho();

    iRichtig = -10;
	while(iRichtig != 0)
	{
		wprintw(menueFenster, "\nPasswort  (min. 6 Zeichen): ");
		wgetstr(menueFenster, cPasswort);
		wprintw(menueFenster, "\n");
		iRichtig = PruefeAufValideStringlaenge(cPasswort, 6, 20);
		AusgabeFehlermeldungValideTextlaenge(menueFenster, iRichtig, PASSWORT);
	}

    wprintw(menueFenster, "\n\n=============================================\n\n");

    // Weitergabe an die Datenbankanbindung
    if (Registrieren(cNachname, cVorname, cNickname, cPasswort) == 0)
    {
        wclear(menueFenster); // Bildschirm leeren
        wprintw(menueFenster, "Die Registrierung war erfolgreich.\n\n");
		wprintw(menueFenster, "Druecken Sie eine beliebige Taste...");
        wrefresh(menueFenster);
        getch();
        Startmenue();
    }
    else
    {
        wclear(menueFenster); // Bildschirm leeren
        wprintw(menueFenster, "Die Registrierung ist fehlgeschlagen.\n");
        wprintw(menueFenster, "Der Nickname ist bereits vergeben.\n\n");
		wprintw(menueFenster, "Druecken Sie eine beliebige Taste...");
        wrefresh(menueFenster);
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
    WINDOW *menueFenster;
    char cEingabe = -1, cFalscheEingabe = TRUE;

    curs_set(0); // Cursor unsichtbar machen
    menueFenster = ErstelleNeuesMenueFenster();

    // Abfangen der unerwuenschten Buchstaben
    while(cFalscheEingabe)
    {
        wclear(menueFenster);

        // Ausgabe des Menues fuer die Schwierigkeitsstufen
        wprintw(menueFenster, "Schwierigkeitsstufe\n\n");
        wprintw(menueFenster, "============================================\n");
        wprintw(menueFenster, "[L] Leicht\n\n");
        wprintw(menueFenster, "[M] Mittel\n\n");
        wprintw(menueFenster, "[S] Schwer\n\n");
        wprintw(menueFenster, "============================================");

        wrefresh(menueFenster);

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
    WINDOW *menueFenster;
    char cEingabe = -1, cFalscheEingabe = TRUE;

    curs_set(0); // Cursor unsichtbar machen
    menueFenster = ErstelleNeuesMenueFenster();

    // Abfangen der unerwuenschten Buchstaben
    while(cFalscheEingabe)
    {
        wclear(menueFenster);

        // Ausgabe des Menues fuer die Schwierigkeitsstufen
        wprintw(menueFenster, "S U D O K U\n\n");
        wprintw(menueFenster, "(C) HHBK Tendo Research Center\n\n");
        wprintw(menueFenster, "============================================\n");
        wprintw(menueFenster, "[L] Leicht\n\n");
        wprintw(menueFenster, "[M] Mittel\n\n");
        wprintw(menueFenster, "[S] Schwer\n\n");
        wprintw(menueFenster, "============================================");

        wrefresh(menueFenster);

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
Uebergabe Parameter:    ccNickname
Rueckgabe:              -
Beschreibung:           Erstellt das Spielmenue.
*******************************************************************************/
void Spielmenue(const char ccNickname[])
{
    WINDOW *menueFenster;
    char cEingabe = -1;

    curs_set(0); // Cursor unsichtbar machen
    menueFenster = ErstelleNeuesMenueFenster();

    // Abfangen der unerwuenschten Buchstaben
    while(cEingabe != 'L' && cEingabe != 'l')
    {
        wclear(menueFenster);

        // Ausgabe des Spielmenues
        wprintw(menueFenster, "Spielmenue\n\n");
        wprintw(menueFenster, "============================================\n");
        wprintw(menueFenster, "[N] Neues Spiel\n\n");
        wprintw(menueFenster, "[R] Spielregeln\n\n");
        wprintw(menueFenster, "[B] Bestenliste\n\n");
        wprintw(menueFenster, "[L] Logout\n\n");
        wprintw(menueFenster, "============================================");

        wrefresh(menueFenster);

        cEingabe = getch();

        switch(cEingabe)
        {
            case 'N': 
            case 'n':
                Schwierigkeitsstufenmenue(ccNickname);
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
				ccNickname = NULL;
				Startmenue();
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
	printw("\n");
	printw("\t\t============================================\n\n");
	printw("\n");
	printw("\n\n");

	noecho();

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
    WINDOW *menueFenster;
    char cEingabe = -1;

    curs_set(0); // Cursor unsichtbar machen
    menueFenster = ErstelleNeuesMenueFenster();

    // Abfangen der unerwuenschten Buchstaben
    while(cEingabe != 'X' && cEingabe != 'x')
    {
        wclear(menueFenster);

        // Ausgabe des Startmenues
        wprintw(menueFenster, "S U D O K U\n\n");
        wprintw(menueFenster, "(C) HHBK Tendo Research Center\n\n");
        wprintw(menueFenster, "============================================\n");
        wprintw(menueFenster, "[E] Einloggen\n\n");
        wprintw(menueFenster, "[N] Nicht einloggen\n\n");
        wprintw(menueFenster, "[R] Registrieren\n\n");
        wprintw(menueFenster, "[X] Beenden\n\n");
        wprintw(menueFenster, "============================================");

        wrefresh(menueFenster);

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

int InBestenlisteEintragenDialog(int iSchwierigkeit, const char ccNickname[], char cZeit[])
{
	char cEingabe = -1, cFalscheEingabe = TRUE;
	int iAntwort = -1;
	char cTest[20];

	strcpy(cTest, ccNickname);

    // Abfangen der unerwuenschten Buchstaben
    while(cFalscheEingabe)
    {
        curs_set(0); // Cursor unsichtbar machen
        clear();

        // Ausgabe des Menues fuer die Schwierigkeitsstufen
        printw("\n");
        printw("\t\t\t\tS U D O K U\n\n");
        printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
        printw("\t\t============================================\n\n");
        printw("\t\tWollen Sie sich in die Bestenliste eintragen?\n\n");
        printw("\t\t\t[J]\tJa\n\n");
        printw("\t\t\t[N]\tNein\n\n");
        printw("\t\t============================================\n\n");

        refresh();

        cEingabe = getch();

        switch(cEingabe)
        {
        case 'J':
        case 'j':
			HighscoreEintragen(iSchwierigkeit, cTest, cZeit);
            HighscoreAusgeben(1);
            cFalscheEingabe = FALSE;
            break;
        case 'N':
        case 'n':
			Spielmenue(ccNickname);
            cFalscheEingabe = FALSE;
            break;
        }
    }


	return 0;
}