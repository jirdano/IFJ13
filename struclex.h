/*
   Soubor:  struclex.h
   Datum:   18.10.2013 20:37
   Autor:   Jenda
   Projekt: 
   Popis:   

   Copyright (C) 2013 Jenda

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   in a file called COPYING along with this program; if not, write to
   the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
   02139, USA.
*/


#ifndef __STRUCLEX_H__
#define __STRUCLEX_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct tToken {
  int id;
  char* name;  
  struct tToken *lptr;
  struct tToken *rptr;
} *tTokenPtr;

typedef struct {
  tTokenPtr First;
  tTokenPtr Act;
  tTokenPtr Last;
} tTokenList;

int TokenInit (tTokenList **);
int TokenAdd (tTokenList *, int, char *);
void TokenActNext (tTokenList *);
void TokenActFirst (tTokenList *);
void TokenValue (tTokenList *, int *, char **);
int TokenEnd (tTokenList *);
void TokenFree (tTokenList *);
void TokenActPrev (tTokenList *);
void TokenStart (tTokenList *);

#endif

/* konec souboru struclex.h */
