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

    int iRueckgabe=-1, iKorrekt = -1;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Eingabe anzeigen lassen 
    timeout(-1); //timeout deaktivieren

    while(iKorrekt != 0) {
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

		if(isValid(cNickname, 1, 20) == 0 && isValid(cPasswort, 6, 20) == 0) {
			iKorrekt = 0;
		}
	}

    // Weitergabe an die Datenbankanbindung
 
	iRueckgabe = Einloggen(cNickname, cPasswort);  

    if(iRueckgabe == 0)
    {
		printf("\nErfolgreich eingeloggt.\n\n");
        timeout(50000);
        Spielmenue(cNickname);
    }
    else
    {
		printf("\nLog In ist fehlgeschlagen.\n\n");
        timeout(5000);
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

	int iKorrekt = -1;
    int iRueckgabe= -1;
    int iRichtig = -10;

    curs_set(1); // Cursor sichtbar machen
    echo(); // Eingabe anzeigen lassen 
    timeout(-1); //timeout deaktivieren

    // Ausgabe des Registrierungsmenues
    
	while (iKorrekt != 0) 
	{
		clear();
		printw("\n");
		printw("\t\t\t\tS U D O K U\n\n");
		printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
		printw("\t\t============================================\n\n");
		printw("\t\t\tBitte fuellen Sie die folgenden Felder aus.\n");    
		printw("\n\t\t\tNachname (max. 20 Zeichen): ");
		while(iRichtig != 0)
		{
			if (iRichtig != -10)
			{
				printw("\n\t\t\tNachname (max. 20 Zeichen): ");
			}
			getstr(cNachname);
			iRichtig = isValid(cNachname,1,20);
			Fehlermeldung(iRichtig, NACHNAME);
		}
		iRichtig = -10;
		while(iRichtig != 0)
		{
			printw("\n\t\t\tVorname  (max. 20 Zeichen): ");
			getstr(cVorname);
			iRichtig = isValid(cVorname,1,20);
			Fehlermeldung(iRichtig, VORNAME);
		 }
		iRichtig = -10;
		while(iRichtig != 0)
		{
			printw("\n\t\t\tNickname (max. 20 Zeichen): ");
			getstr(cNickname);
			iRichtig = isValid(cNickname,1,20);
			Fehlermeldung(iRichtig, NICKNAME);
		}
		iRichtig = -10;
		//curs_set(0); // Cursor unsichtbar machen
		while(iRichtig != 0)
		{
			printw("\n\t\t\tPasswort  (min. 6 Zeichen): ");
			getstr(cPasswort);
			iRichtig = isValid(cPasswort,6,20);
			Fehlermeldung(iRichtig, PASSWORT);
		}
		if(isValid(cNachname, 1, 20) == 0 && isValid(cVorname, 1, 20) == 0 &&
			isValid(cNickname, 1, 20) == 0 && isValid(cPasswort, 6, 20) == 0) 
		{
			iKorrekt = 0;
		}	
	}

    printw("\n\n\t\t============================================\n\n");
    // Weitergabe an die Datenbankanbindung
 
   iRueckgabe = Registrieren(cNachname, cVorname, cNickname, cPasswort);
  /* switch ()
           {
               case 0:
                     
                     printw("\n\t\t\tAlle Felder muessen ausgefuellt sein.");
                   break;         
               case 1:
                   printw("\n\t\t\tAlle Felder muessen ausgefuellt sein.");
                   break;
               case 2:
                   printw("\n\t\t\tDie Felder sind zu lang.");
                   break;
           }*/
    getch();

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
void SchwierigkeitsStufenMenue(char *Nickname)
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
            NeuesSpiel(1);
            cFalscheEingabe = FALSE;
            break;
        case 'M':
        case 'm':
            NeuesSpiel(2);
            cFalscheEingabe = FALSE;
            break;
        case 'S':
        case 's':
            NeuesSpiel(3);
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
void Spielmenue(char *Nickname)
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
            SchwierigkeitsStufenMenue(Nickname);
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