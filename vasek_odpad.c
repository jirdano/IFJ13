/*
  testovani pro funkce typu shell sort a search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "vasek.h"
#include "ial.h"



void semant(tTokenList *t, tHashTable *tht);
void syntax(tTokenList *t, tHashTable *tht);
void loadFunctions(tTokenList *t, tHashTable *tht);


int main(int argc, char *argv[]){
	tTokenList *t;
	true2(&t);
	TokenActFirst(t);
	tHashTable *tht;
	if(HashInit(&tht)==0){
		printf("Nepodařilo se inicializovat hashovací tabulku");
	}
	
	syntax(t, tht);
	semant(t, tht);
	puts("END");
}

void syntax(tTokenList *t, tHashTable *tht){
	HashAdd(tht, "x", 0, 0);
	HashAdd(tht, "a", 0, 0);
	HashAdd(tht, "vysl", 0, 0);
}

//------funkce procházející uživatelem definované funkce a analyzující jejich parametry----
void loadFunctions(tTokenList *t, tHashTable *tht){
	TokenActFirst(t);
	int id;
	char *name;
	name = NULL;
	char *funct;
	funct = NULL;
	char *var;
	var = NULL;
	TokenValue(t, &id, &name);//načtení tokenu
	
	while(!TokenEnd(t)){//postupně procházíme všechny tokeny - definice funkcí
		if(id == 8 && strcmp(name, "function") == 0){
			TokenActNext(t);//----------posun na jméno funkce
			TokenValue(t, &id, &name);//načtení jména funkce
			funct = name;//uložení jména funkce
			TokenActNext(t);
			TokenValue(t, &id, &name);
			int pc=0;//počet parametrů funkce
			while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
				if(id!=0){
					pc+=1;
				}
				TokenActNext(t);
				TokenValue(t, &id, &name);
			}
			TokenActNext(t);//závorka {
			TokenActNext(t);
			TokenValue(t, &id, &name);
			int in = 1;//proměnná, určující, jestli jsme v těle funkce
			while(in>0){
				if(id == 0 && strcmp(name, "{") == 0){
					in+=1;//přidání úrovně
				}else if(id == 0 && strcmp(name, "}") == 0){
					in-=1;//snížení úrovně
				}
				
				TokenActNext(t);
				TokenValue(t, &id, &name);
				
			}
			
		}
		TokenActNext(t);
		TokenValue(t, &id, &name);
	}

}

void semant(tTokenList *t, tHashTable *tht){

	loadFunctions(t, tht);

	TokenActFirst(t);
	int id;
	char *name;
	name = NULL;
	char *var;
	var = NULL;
	
	TokenActFirst(t);
	while(!TokenEnd(t)){//postupně procházíme všechny tokeny - kontrola proměnných
		TokenValue(t, &id, &name);//načtení tokenu
		if(id == 0 && strcmp(name, "$") == 0){
			/*TokenActNext(t);//----------posun na jméno proměnné
			TokenValue(t, &id, &name);//načtení jména proměnné
			var = name;//---------------uložení jména proměnné
			TokenActNext(t);
			TokenValue(t, &id, &name);
			if(id == 0 && strcmp(name, "=") == 0){//přiřazujeme proměnné hodnotu?
				TokenActNext(t);
				TokenValue(t, &id, &name);
				while(id != 0 || strcmp(name, ";") != 0){//zjišťujeme, co do proměnné přiřazujeme
					if(id == 0 && strcmp(name, "$") == 0){//přiřazujeme proměnnou?
						int type;
						TokenActNext(t);
						TokenValue(t, &id, &name);
						HashType(tht, name, &type, 0);//zjišťujeme typ proměnné
						if(type == 0){
							printf("nedefinovaná proměnná %s - ERROR 5\n", name);
						}else{
							printf("promenna %s typu %d\n", name, type);
						}
					}else if(id == 1){//přiřazujeme funkci?
						if(strcmp(name, "boolval") == 0 || strcmp(name, "doubleval") == 0 || strcmp(name, "intval") == 0 || strcmp(name, "strval") == 0 || strcmp(name, "get_string") == 0 || strcmp(name, "put_string") == 0 || strcmp(name, "strlen") == 0 || strcmp(name, "get_substring") == 0 || strcmp(name, "find_string") == 0 || strcmp(name, "sort_string") == 0){
						//voláme vestavěnou funkci?
							if(strcmp(name, "boolval") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc<2){
									printf("chybejici parametr funkce boolval\n");
								}else if(pc>2){
									printf("prilis mnoho parametru funkce boolval\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce boolval\n");
								}
							}else if(strcmp(name, "doubleval") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc<2){
									printf("chybejici parametr funkce doubleval\n");
								}else if(pc>2){
									printf("prilis mnoho parametru funkce doubleval\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce doubleval\n");
								}
							}else if(strcmp(name, "intval") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc<2){
									printf("chybejici parametr funkce intval\n");
								}else if(pc>2){
									printf("prilis mnoho parametru funkce intval\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce intval\n");
								}
							}else if(strcmp(name, "strval") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc<2){
									printf("chybejici parametr funkce strval\n");
								}else if(pc>2){
									printf("prilis mnoho parametru funkce strval\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce strval\n");
								}
							}else if(strcmp(name, "get_string") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc>1){
									printf("prilis mnoho parametru funkce get_string\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce get_string\n");
								}
							}else if(strcmp(name, "put_string") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc<2){
									printf("chybejici parametr funkce put_string\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce put_string\n");
								}
							}else if(strcmp(name, "strlen") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc<2){
									printf("chybejici parametr funkce strlen\n");
								}else if(pc>2){
									printf("prilis mnoho parametru funkce strlen\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce strlen\n");
								}
							}else if(strcmp(name, "get_substring") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc<4){
									printf("chybejici parametr funkce get_substring\n");
								}else if(pc>4){
									printf("prilis mnoho parametru funkce get_substring\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce get_substring\n");
								}
							}else if(strcmp(name, "find_string") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc<3){
									printf("chybejici parametr funkce find_string\n");
								}else if(pc>3){
									printf("prilis mnoho parametru funkce find_string\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce find_string\n");
								}
							}else if(strcmp(name, "sort_string") == 0){
								int pc = 0;
								while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
									if(id!=0){
										pc+=1;
									}
									TokenActNext(t);
									TokenValue(t, &id, &name);
								}
								if(pc<2){
									printf("chybejici parametr funkce sort_string\n");
								}else if(pc>2){
									printf("prilis mnoho parametru funkce sort_string\n");
								}else{
									printf("prirazujeme vysledek vestavene funkce sort_string\n");
								}
							}
							
						}else if(id == 1 && HashDefined(tht, name, 0) == 0){//byla funkce definována?
							//printf("prirazujeme vysledek nedefinovane funkce %s - ERROR 3\n", name);
						}else if(id == 1){//---------------------------------------kontrola parametrů funkce
							printf("prirazujeme vysledek funkce %s\n", name);
							//teď budeme kontrolovat počet
							int used = HashUsed(tht, name, 0);
							int pc = 0;
							while(id != 0 || strcmp(name, ")") != 0){//procházíme parametry
								if(id!=0){
									pc+=1;
								}
								TokenActNext(t);
								TokenValue(t, &id, &name);
							}
							if(pc<used+1){
								printf("chybejici parametr funkce\n");
							}else if(pc>used+1){
								printf("prilis mnoho parametru funkce\n");
							}else{
								printf("prirazujeme vysledek funkce\n");
							}
							
						}
					}
					
					TokenActNext(t);
					TokenValue(t, &id, &name);
				}
			}else{
				
			}*/
			
		}
		TokenActNext(t);
	}
	
	/*
	TokenActFirst(t);
	while(!TokenEnd(t)){//postupně procházíme všechny tokeny - kontrola funkcí
		TokenValue(t, &id, &name);//načtení tokenu
		if(id == 8 && strcmp(name, "function") == 0){//deklarujeme novou funkci?
			TokenActNext(t);
			TokenValue(t, &id, &name);
			if(HashDefined(tht, name, 0)){//zjistit, jestli je funkce už definovaná
				printf("pokus o redefinici funkce %s - ERROR 3\n", name);
			}else{//jinak kontrolujeme parametry funkce
				TokenActNext(t);
				TokenValue(t, &id, &name);
				while(id != 0 || strcmp(name, ")") != 0){//procházíme tokeny, dokud nenarazíme na )
					if(id == 1){//narazili jsme na proměnnou?
						printf("promenna %s pYco\n", name);
					}
					TokenActNext(t);
					TokenValue(t, &id, &name);
				}
			}
		}
		TokenActNext(t);
	
	}
	TokenActFirst(t);*/
}

/*void semant(tTokenList *t, tHashTable *tht){
	int id;
	char *name;
	name = NULL;
	TokenValue(t, &id, &name);//načtení tokenu
	
	if(id == 1){//pracujeme s proměnnou, nebo funkcí?
	
		//-----------------krok zpět------------------
		TokenActPrev(t);//předchozí token
		TokenValue(t, &id, &name);//načtení tokenu
		if(id == 0 && strcmp(name, "$") == 0){//---------------------pracujeme s proměnnou?
			//printf("děláme s proměnnou\n");
			TokenActNext(t);//posun na půvoní token - název proměnné
			TokenActNext(t);//posun na další token
			TokenValue(t, &id, &name);
			if(id == 0 && strcmp(name, "=") == 0){//přiřazujeme proměnné hodnotu?
				TokenActPrev(t);
				TokenValue(t, &id, &name);
				if(HashExist(tht, name, 0)){//je proměnná deklarována?
					//--------------------------pokud ano, budeme zjišťovat, co do ní přiřazujeme
					
					
					
					HashSet(tht, name, 0, 0, 0, 0);//---potom jí přepíšeme
					printf("prepisujeme promennou %s\n", name);
				}else{//------------------------pokud ne, postup bude stejný
				
				
				
					HashAdd(tht, name, 0, 0, 0);//---a přidáme ji pak do hash tabulky jako nový záznam
					printf("deklarujeme promennou %s\n", name);
				}
			}
			
		}else{//pracujeme s funkcí
			if(id == 8 && strcmp(name, "function") == 0){//--------deklarujeme novou funkci?
				TokenActNext(t);
				TokenValue(t, &id, &name);
				printf("chceme daklarovat funkci %s\n", name);
				if(HashExist(tht, name, 0)){//je funkce již deklarována?
					printf("pokus o redefinici funkce %s - ERROR 3\n", name);
				}else{
					HashAdd(tht, name, 0, 0, 0);//pokud ne, přidáme ji do hash tabulky
					printf("deklarujeme funkci %s\n", name);
				}
			}else{
				TokenActNext(t);
				TokenValue(t, &id, &name);
				if(HashExist(tht, name, 0)){//je funkce již deklarována?
					//teď budeme kontrolovat počet a typ parametrů
					int used = HashUsed(tht, name, 0);
					int parc = 0;//počet parametrů
					int parv[100];//typ parametrů
					while(used>0){
						parv[parc]=used%10;
						used = (used-parv[parc])/10;
						parc++;
					}
					printf("volame funkci %s s %d parametry\n", name, parc);
					for(int i=0; i<parc; i++){
						printf("parametr %d je typu %d\n", i, parv[i]);
					}
					//známe počet a hodnotu parametrů
				
				
				
				}else if(strcmp(name, "boolval") == 0 || strcmp(name, "doubleval") == 0 || strcmp(name, "intval") == 0 || strcmp(name, "strval") == 0 || strcmp(name, "get_string") == 0 || strcmp(name, "put_string") == 0 || strcmp(name, "strlen") == 0 || strcmp(name, "get_substring") == 0 || strcmp(name, "find_string") == 0 || strcmp(name, "sort_string") == 0){
					//voláme vestavěnou funkci?
					printf("volame vestavenou funkci %s\n", name);
					//budeme opět kontrolovat počet a typ parametrů
					
					
					
				}else{
					printf("volame funkci %s, ktera neni definovana - ERROR 3\n", name);
				}
			}
		}
	}
	

}*/

/* end of pokus.c */
