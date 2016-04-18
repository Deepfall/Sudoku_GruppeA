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
#define _CRT_SECURE_NO_DEPRECATE    1

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include "sudoku.h"

// Allgemein
#define TRUE                        1
#define FALSE                       0

/*******************************************************************************
Funktionsprototypen
*******************************************************************************/
void startMenue(void);
void Spielmenue(void);
void SchwierigkeitsStufenMenue(void);

/*******************************************************************************
Funktion main()
*******************************************************************************/
int main(void)
{
    system("MODE CON: COLS=160");
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    timeout(1000);

    startMenue();


    endwin();

    return EXIT_SUCCESS;
}
/*******************************************************************************
Funktion Schwierigkeitsstufenmenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Menue für die 3 Schwierigkeitsstufen.
*******************************************************************************/
void SchwierigkeitsStufenMenue(void)
{
    char cEingabe;
    curs_set(0); // Cursor unsichtbar machen

    clear();
    printw("\n");
    printw("\t\t\t\tS U D O K U\n\n");
    printw("\t\t\t(C) HHBK Tendo Research Center\n\n");
    printw("\t\t============================================\n\n");
    printw("\t\t\t[L]\tLeicht\n\n");
    printw("\t\t\t[M]\tMittel\n\n");
    printw("\t\t\t[S]\tSchwer\n\n");
    printw("\t\t============================================\n\n");
   
    refresh();

    // Abfangen der unerwuenschten Buchstaben
    while(1){

        cEingabe = getch();
        switch(cEingabe)
        {
        case 'L': 
        case 'l': NeuesSpiel(); break;
        case 'M': 
        case 'm': NeuesSpiel(); break;
        case 'S': 
        case 's': NeuesSpiel(); break;
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
    char cEingabe;
    curs_set(0); // Cursor unsichtbar machen

    clear();
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

    // Abfangen der unerwuenschten Buchstaben
    while(1){

        cEingabe = getch();
        switch(cEingabe)
        {
        case 'N': 
        case 'n': SchwierigkeitsStufenMenue(); break;
        case 'R': 
        case 'r': SpielregelnAnzeigen(); break;
        case 'B': 
        case 'b': break;
        case 'L': 
        case 'l': break;
        }
    }
    
}

/*******************************************************************************
Funktion startMenue()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Startmenü.
*******************************************************************************/
void startMenue(void)
{
    char cEingabe;

    curs_set(0); // Cursor unsichtbar machen

    clear();
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

    // Abfangen der unerwuenschten Buchstaben
    while(1){
        cEingabe = getch();
        switch(cEingabe)
        {
        case 'E': 
        case 'e': break;
        case 'N': 
        case 'n': Spielmenue(); break;
        case 'R': 
        case 'r': break;
        case 'X': 
        case 'x': break;
        }
    }
}
/*******************************************************************************
Funktion SPielregelnAnzeigen()
Uebergabe Parameter:    -
Rueckgabe:              -
Beschreibung:           Erstellt das Startmenü.
*******************************************************************************/
void SpielregelnAnzeigen(void)
{
    FILE *fp;

    fp = fopen("W:\LF06\Wissemann\Projekt_GruppeA\Regeln.html","r");

    if(fp != NULL)
    {
        fclose(fp);
    }
    
}