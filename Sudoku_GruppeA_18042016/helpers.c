/*
Autor(en)               : Robin grahl, Dustin Welz
Klasse                  : FA11
Programmname            : helpers.c
Datum                   : 20.04.2016
Beschreibung            : 
Version                 : 1.0
Compiler                : Visual Studio 2012
*/

#include "helpers.h"
#include <string.h>
#include <stdio.h>
#include <curses.h>

int generiereSudokuId(int stufe) {
	int sudokuId = -1;

	switch(stufe) {
		case 1: sudokuId = generiereZufallsZahl(1, 10);
				break;
		case 2: sudokuId = generiereZufallsZahl(11, 20);
				break;
		case 3: sudokuId = generiereZufallsZahl(21, 30);
				break;
	}

	return sudokuId;
}

int generiereZufallsZahl(int min_n, int max_n)
{
	srand(time(NULL));
    return rand() % (max_n - min_n + 1) + min_n;
}

void entferneLeerzeichen(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}


