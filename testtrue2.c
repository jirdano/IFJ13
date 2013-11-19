/*
   Soubor:  test-true1.c
   Datum:   19.10.2013 11:27
   Autor:   Jenda
   Projekt: 
   Popis:   

   Copyright (C) 2002 Jenda

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

#include "testtrue2.h"

void true2(tTokenList **t){
  TokenInit(t);
  TokenAdd(*t,0,"$");
  TokenAdd(*t,1,"a");
  TokenAdd(*t,0,"=");
  TokenAdd(*t,4,"5");
  TokenAdd(*t,0,";");
  TokenAdd(*t,0,"$");
  TokenAdd(*t,1,"b");
  TokenAdd(*t,0,"=");
  TokenAdd(*t,4,"7");
  TokenAdd(*t,0,";");
  TokenAdd(*t,0,"$");
  TokenAdd(*t,1,"c");
  TokenAdd(*t,0,"=");
  TokenAdd(*t,4,"2");
  TokenAdd(*t,0,";");
  TokenAdd(*t,0,"$");
  TokenAdd(*t,1,"x");
  TokenAdd(*t,0,"=");
  TokenAdd(*t,0,"$");
  TokenAdd(*t,1,"a");
  TokenAdd(*t,0,"+");
  TokenAdd(*t,0,"$");
  TokenAdd(*t,1,"b");
  TokenAdd(*t,0,"-");
  TokenAdd(*t,0,"$");
  TokenAdd(*t,1,"c");
  TokenAdd(*t,0,";");
  TokenAdd(*t,8,"if");
  TokenAdd(*t,0,"(");
  TokenAdd(*t,0,"$");
  TokenAdd(*t,1,"c");
  TokenAdd(*t,0,"=");
  TokenAdd(*t,4,"10");
  TokenAdd(*t,0,")");
  TokenAdd(*t,0,"{");
  TokenAdd(*t,0,"$");
  TokenAdd(*t,1,"d");
  TokenAdd(*t,0,"=");
  TokenAdd(*t,4,"1");
  TokenAdd(*t,0,";");
  TokenAdd(*t,0,"}");
}



/* konec souboru test-true1.c */
