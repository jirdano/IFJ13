/*
  testovani pro funkce typu shell sort a search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "vasek.h"
#include "ial.h"



//void PSA(tTokenList *t, tHashTable *tht);
void SA(tTokenList *t, tHashTable *tht);


int main(int argc, char *argv[]){
	tTokenList *t;
	true2(&t);
	TokenActFirst(t);
	tHashTable *tht;
	if(HashInit(&tht)==0){
		printf("Nepodařilo se inicializovat hashovací tabulku");
	}
	
	SA(t, tht);
	puts("END");
}

void SA(tTokenList *t, tHashTable *tht){
	int id;
	char *name;
	name = NULL;
	TokenActFirst(t);
	while(!TokenEnd(t)){
		TokenValue(t, &id, &name);
		if(strcmp(name, "=") == 0){
			
		}
		
		TokenActNext(t);
	}
}


/*void PSA(tTokenList *t, tHashTable *tht){

	int id;
	char *name;
	name = NULL;
	
	
}*/
