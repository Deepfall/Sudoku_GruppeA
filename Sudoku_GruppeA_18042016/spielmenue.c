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

    while(iKorrekt != 0)
    {
		clear(); // Bildschirm leeren

		printw("\n");
		printw("\t\t\t\tEinloggen\n\n");
		printw("\t\t============================================\n\n");
        printw("\t\t\tBitte geben Sie ihre Daten ein,\n");
	    printw("\t\t\tum sich erfolgreich anzumelden.\n\n");

        // Einlesen des Nicknamen
		printw("\t\t\tNickname: ");
		getstr(cNickname);

        /* Wir wollen das Passwort niemandem zeigen, also
           Benutzereingabe verstecken */
        noecho();

        // Einlesen des Passwortes
		printw("\t\t\tPasswort: ");
		getstr(cPasswort);

		printw("\n\t\t============================================\n\n");

		if(PruefeAufValideStringlaenge(cNickname, 1, 20) == 0
           && PruefeAufValideStringlaenge(cPasswort, 6, 20) == 0)
        {
			iKorrekt = 0;
		}
	}

    // Weitergabe an die Datenbankanbindung
	iRueckgabe = Einloggen(cNickname, cPasswort);  

    if(iRueckgabe == 0)
    {
		printf("\nErfolgreich eingeloggt.\n\n");
        Spielmenue(cNickname);
    }
    else
    {
		printf("\nLog In ist fehlgeschlagen.\n\n");
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
    char cNachname[TEXTLAENGE], cVorname[TEXTLAENGE],
         cNickname[TEXTLAENGE], cPasswort[TEXTLAENGE];
    int iRichtig;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Benutzereingabe anzeigen lassen
    timeout(-1); // Timeout deaktivieren
    clear(); // Bildschirm leeren

    // Ausgabe des Registrierungsmenues
	printw("\n");
	printw("\t\t\t               Registrierung                \n\n");
	printw("\t\t\t============================================\n\n");
	printw("\t\t\tBitte fuellen Sie die folgenden Felder aus. \n");

    iRichtig = -10;
	while(iRichtig != 0)
    {
        printw("\n\t\t\tNachname (max. 20 Zeichen): ");
		getstr(cNachname);
		iRichtig = PruefeAufValideStringlaenge(cNachname, 1, 20);
		AusgabeFehlermeldungValideTextlaenge(iRichtig, NACHNAME);
	}

	iRichtig = -10;
	while(iRichtig != 0)
	{
		printw("\n\t\t\tVorname  (max. 20 Zeichen): ");
		getstr(cVorname);
		iRichtig = PruefeAufValideStringlaenge(cVorname, 1, 20);
		AusgabeFehlermeldungValideTextlaenge(iRichtig, VORNAME);
	}

	iRichtig = -10;
	while(iRichtig != 0)
	{
		printw("\n\t\t\tNickname (max. 20 Zeichen): ");
		getstr(cNickname);
		iRichtig = PruefeAufValideStringlaenge(cNickname, 1, 20);
		AusgabeFehlermeldungValideTextlaenge(iRichtig, NICKNAME);
	}

    // Wir wollen das Passwort niemandem zeigen, also Benutzereingabe verstecken
    noecho();

    iRichtig = -10;
	while(iRichtig != 0)
	{
		printw("\n\t\t\tPasswort  (min. 6 Zeichen): ");
		getstr(cPasswort);
		iRichtig = PruefeAufValideStringlaenge(cPasswort, 6, 20);
		AusgabeFehlermeldungValideTextlaenge(iRichtig, PASSWORT);
	}

    printw("\n\n\t\t\t=============================================\n\n");

    // Weitergabe an die Datenbankanbindung
    if (Registrieren(cNachname, cVorname, cNickname, cPasswort) == 0)
    {
        printw("\t\t\tDie Registrierung war erfolgreich.");
        Startmenue();
    }
    else
    {
        printw("\t\t\tDie Registrierung ist fehlgeschlagen.");
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
        clear();

        // Ausgabe des Menues fuer die Schwierigkeitsstufen
        printw("\n");
        printw("\t\t\t\tSchwierigkeitsstufe\n\n");
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
        clear();

        // Ausgabe des Menues fuer die Schwierigkeitsstufen
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
    char cEingabe = -1;

    // Abfangen der unerwuenschten Buchstaben
    while(cEingabe != 'L' && cEingabe != 'l')
    {
        curs_set(0); // Cursor unsichtbar machen
        clear();

        // Ausgabe des Spielmenues
        printw("\n");
        printw("\t\t\t\tSpielmenue\n\n");
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