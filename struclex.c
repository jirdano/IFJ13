/*
   Soubor:  struclex.c
   Datum:   18.10.2013 20:36
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

#include "struclex.h"
#include <string.h>
/*
int TokenInit (tTokenList *t); //Naalokuje seznam pro token a inicializuje
int TokenAdd (tTokenList *t, int id, char *name); //Vlozi novy token
void TokenActNext (tTokenList *t); //Posune aktivitu tokenu na dalsi
void TokenActFirst (tTokenList *t); //Aktivitu na prvni token
void TokenValue (tTokenList *t, int *id, char *name); //Hodnoty aktualniho tokenu
int TokenEnd (tTokenList *t); //Pokud jsem na konci tokenu
void TokenFree (tTokenList *t); //Uvolneni celeho tokenlistu
*/
int TokenInit (tTokenList **t){
  *t = (tTokenList *) malloc(sizeof(tTokenList));
  if(t == NULL){
    return 0;  
  }
  (*t)->First=NULL;
  (*t)->Act=NULL;
  (*t)->Last=NULL;
  return 1; //Spravne alokovano  
}

void TokenFree (tTokenList *t){
  struct tToken *a;
  while(t->First!=NULL){
    a=t->First->rptr;
    if(t->First->name!=NULL){
      free(t->First->name);  
    }
    free(t->First);
    t->First=a;  
  }
  free(t); 
}

int TokenEnd (tTokenList *t){
  return (t->Last==t->Act);  
}

int TokenStart (tTokenList *t){
  return (t->First==t->Act);  
}

void TokenValue (tTokenList *t, int *id, char **name){
  *id=t->Act->id;
  if(*name!=NULL){
    free(*name);  
  }
  *name = (char *) malloc(sizeof(char)*(strlen(t->Act->name)+1));
  if(*name==NULL){
    return;
  }
  strcpy(*name,t->Act->name);
}

int TokenAdd (tTokenList *t, int id, char *name){
  struct tToken *new;
  new = malloc(sizeof(struct tToken));
  if(new == NULL){
    return 0;    
  }
  new->name = malloc(sizeof(char)*(strlen(name)+1));
  if(new->name == NULL){
    return 0;  
  }
  strcpy(new->name,name);
  new->id=id;
  new->lptr=NULL;
  new->rptr=NULL;
  if(t->First == NULL){
    t->First=new;
    t->Last=new;
  }else{
    t->Last->rptr=new;
    new->lptr=t->Last;
    t->Last=new;
  }
  return 1;
}

void TokenActNext (tTokenList *t){
  if(t->Act!=NULL){
    t->Act=t->Act->rptr;  
  }  
}

void TokenActPrev (tTokenList *t){
  if(t->Act!=NULL){
    t->Act=t->Act->lptr;
  }  
}

void TokenActFirst (tTokenList *t){
  if(t->First!=NULL){
    t->Act=t->First;  
  }  
}



/* konec souboru struclex.c */
