/*
	Soubor:  3ac.h
	Datum:   19.11.2013 11:10
	Autor:   Václav Jireš
	Projekt: IFJ13
	Popis:   tříadresný kód pro parser a interpret

	Copyright (C) 2013 Václav Jireš
*/

#ifndef __3AC_H__
#define __3AC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{//typy instrukcí pro 3AC
	ASSIGN,//přiřazení
	ADD,//součet
	SUB,//rozdíl
	MUL,//součin
	DIV,//podíl
	CALL,//volání funkce
	PUSH//uložení na zásobník
}OP;

typedef struct inst{//instrukce
	OP type;//typ instrukce
	char *returnTo;//návratové místo
	char *operand;//s čím pracujeme
	struct inst *lptr;//předchozí instrukce
	struct inst *rptr;//následující instrukce
}*instPtr;

typedef struct{//seznam instrukcí
	instPtr First;//první instrukce
	instPtr Act;//aktuální instrukce
	instPtr Last;//poslední instrukce
}instList;         


#endif

/* konec souboru 3ac.h */