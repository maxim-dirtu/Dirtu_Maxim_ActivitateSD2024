#include <stdio.h>
#include<malloc.h>
typedef struct Nod Nod;
typedef struct HashTable HashTable;
typedef struct Cladire Cladire;

typedef struct Cladire {
	int id;
	int anConstructie;
	int nrEtaje;
};


typedef struct Nod {
	Cladire info;
	Nod* next;
};

typedef struct HashTable {
	Nod** lista;
	int dimensiune;
};

int hash(int anConstructie, int dimensiune) {
	int rez = 0;
	rez = anConstructie % dimensiune;
	return rez;
}

Cladire init(int id, int anConstructie, int nrEtaje) {
	Cladire c;
	c.id = id;
	c.anConstructie = anConstructie;
	c.nrEtaje = nrEtaje;
	return c;
}

HashTable initializareHashTable(int dimensiune) {
	HashTable hashTable;
	hashTable.dimensiune = dimensiune;
	hashTable.lista = malloc(sizeof(Nod*) * dimensiune);
	for (int i = 0; i < dimensiune; i++) {
		hashTable.lista[i] = NULL;
	}
	return hashTable;
}


void inserareLaFinalLista(Nod** lista, Cladire c) {
	Nod* nod = malloc(sizeof(Nod));
	nod->info = c;
	nod->next = NULL;
	if ((*lista) == NULL) {
		(*lista) = nod;
	}
	else {
		Nod* aux = (*lista);
		while (aux->next) {
			aux = aux->next;
		}
		aux->next = nod;
	}
}

void inserareCladireInTabel(HashTable hashTable, Cladire c) {
	int hashCode = hash(c.anConstructie, hashTable.dimensiune);
	inserareLaFinalLista(&hashTable.lista[hashCode], c);

	//if (hashTable.lista[hashCode] == NULL) {
	//}
	//else {
	//	//avem coliziune
	//	inserareLaFinalLista(&hashTable.lista[hashCode], c);
	//}
}

void afisareCladire(Cladire c) {
	printf("\n Cladirea %d construita in %d cu %d etaje", c.id, c.anConstructie, c.nrEtaje);
}

void afisareHashTable(HashTable ht) {
	for (int i = 0; i < ht.dimensiune; i++) {
		Nod* aux = ht.lista[i];
		printf("\n\nPozitia %d:", i);
		while (aux) {
			afisareCladire(aux->info);
			aux = aux->next;
		}
	}
}

void afisareHashTableDupaAn(HashTable ht, int anCautat) {
	for (int i = 0; i < ht.dimensiune; i++) {
		Nod* aux = ht.lista[i];
		while (aux) {
			if (aux->info.anConstructie == anCautat) {

				afisareCladire(aux->info);
			}
			aux = aux->next;
		}
	}
}

//3. Implementati o functie care sterge o cladire pentru care se primeste id - ul si anul construirii.


void stergeCladireDupaIdSiAn(HashTable* ht, int id, int anC) {
	int hashCode = hash(anC, (*ht).dimensiune);
	Nod* aux = (*ht).lista[hashCode];
	while (aux) {
		if (aux->info.id == id) {
			(*ht).lista[hashCode] = aux->next;
			free(aux);
			printf("\nA fost stearsa o cladire\n");
			break;
		}
		Nod* temp = aux->next;

		if (temp->info.id == id) {
			aux->next = temp->next;
			free(temp);
			printf("\nA fost stearsa o cladire\n");
			break;
		}
		aux = aux->next;
	}
}

//4. Implementati o functie care sterge o cladire pentru care se primeste doar id - ul cladirii.
void stergeCladireDupaId(HashTable* ht, int id) {
	Nod* aux = NULL;
	for (int i = 0; i < ht->dimensiune; i++) {
		aux = (*ht).lista[i];
		while (aux) {
			if (aux->info.id == id) {
				(*ht).lista[i] = aux->next;
				free(aux);
				printf("\nA fost stearsa o cladire\n");
				break;
			}

			Nod* temp = aux->next;
			if (temp == NULL) {
				break;
			}

			if (temp->info.id == id) {
				aux->next = temp->next;
				free(temp);
				printf("\nA fost stearsa o cladire\n");
				break;
			}
			aux = aux->next;
		}
	}
}

//5. Observatii diferenta dintre functia implementata la 4 si functia de la 5.
// stergerea dupa id si an, poti accesa direct clusterul dupa an (obtii hash din an), 
//insa la stergerea dupa id, trebuie sa parcurgi tot tabelul.


void stergeLista(Nod** n) {
	Nod* aux = *n;
	while (aux) {
		Nod* temp = aux->next;
		free(aux);
		aux = temp;
	}
	*n = NULL;
}

void stergeHashTable(HashTable* ht) {
	for (int i = 0; i < ht->dimensiune; i++) {
		stergeLista(&ht->lista[i]);
	}
	free(ht->lista);
	ht->lista = NULL;
	ht->dimensiune = 0;
}





void main() {
	HashTable hashTable = initializareHashTable(10);

	inserareCladireInTabel(hashTable, init(1, 1984, 10));
	inserareCladireInTabel(hashTable, init(2, 1975, 9));
	inserareCladireInTabel(hashTable, init(3, 2015, 16));
	inserareCladireInTabel(hashTable, init(4, 1984, 3));
	inserareCladireInTabel(hashTable, init(5, 1987, 8));


	afisareHashTable(hashTable);

	printf("\n\nAfisare cladiri din acelasi cluster:\n");
	afisareHashTableDupaAn(hashTable, 1975);

	printf("\n\n------ Stergere cladire dupa id si an: ---------\n");
	stergeCladireDupaIdSiAn(&hashTable, 3, 2015);
	afisareHashTable(hashTable);

	printf("\n\n------ Stergere cladire dupa id: ---------\n");
	stergeCladireDupaId(&hashTable, 4);
	afisareHashTable(hashTable);


	stergeHashTable(&hashTable);
	printf("\n\t\t%d", hashTable.dimensiune);


}
