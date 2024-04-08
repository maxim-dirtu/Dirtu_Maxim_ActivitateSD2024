#include<stdlib.h>
#include<stdio.h>

typedef struct Pacient Pacient;
typedef struct Heap Heap;

struct Pacient {
	char* nume;
	int anNastere;
	int gradPrioritate;
};

struct Heap {
	Pacient* vector;
	int dimensiune;
};

Pacient init(const char* nume, int anNastere, int gradPrioritate) {
	Pacient p;
	p.nume = malloc(sizeof(char) * (1 + strlen(nume)));
	strcpy(p.nume, nume);
	p.anNastere = anNastere;
	p.gradPrioritate = gradPrioritate;

	return p;
}

void afisarePacient(Pacient p) {
	printf("Pacientul %s are prioritatea %d\n", p.nume, p.gradPrioritate);
}

Heap initHeap(int dim) {
	Heap h;
	h.dimensiune = dim;
	h.vector = malloc(sizeof(Pacient) * dim);
	return h;
}

void afisareHeap(Heap h) {
	printf("\n");
	for (int i = 0; i < h.dimensiune; i++) {
		afisarePacient(h.vector[i]);
	}
}

void filtrareHeap(int pozitieRadacina, Heap h) {
	int pozitieFiuDreapta = 2 * pozitieRadacina + 2;
	int pozitieFiuStanga = 2 * pozitieRadacina + 1;

	int indexMaxim = pozitieRadacina;

	if (pozitieFiuDreapta < h.dimensiune &&
		h.vector[indexMaxim].gradPrioritate < h.vector[pozitieFiuDreapta].gradPrioritate) {
		indexMaxim = pozitieFiuDreapta;
	}

	if (pozitieFiuStanga < h.dimensiune &&
		h.vector[indexMaxim].gradPrioritate < h.vector[pozitieFiuStanga].gradPrioritate) {
		indexMaxim = pozitieFiuStanga;
	}

	if (pozitieRadacina != indexMaxim) {
		Pacient pacientDeMutat = h.vector[indexMaxim];
		h.vector[indexMaxim] = h.vector[pozitieRadacina];
		h.vector[pozitieRadacina] = pacientDeMutat;
		if (2 * indexMaxim + 1 < h.dimensiune) {
			filtrareHeap(indexMaxim, h);
		}
	}
}

void inserarePacientInHeap(Pacient p, Heap* h) {
	Pacient* vectorTemp = malloc(sizeof(Pacient) * (h->dimensiune + 1));
	for (int i = 0; i < h->dimensiune; i++) {
		vectorTemp[i] = h->vector[i];
	}
	vectorTemp[h->dimensiune] = p;
	h->dimensiune++;
	free(h->vector);
	h->vector = vectorTemp;
	for (int i = ((*h).dimensiune - 1) / 2; i >= 0; i--) {
		filtrareHeap(i, (*h));
	}
}

struct Pacient extragePacientGrav(struct Heap* heap) {
	struct Pacient aux = heap->vector[0];
	heap->vector[0] = heap->vector[heap->dimensiune - 1];
	heap->vector[heap->dimensiune - 1] = aux;
	heap->dimensiune--;
	for (int i = (heap->dimensiune - 1) / 2; i >= 0; i--) {
		filtrareHeap(i, *heap);
	}
	return aux;
}


void main() {
	Heap h;
	h = initHeap(7);
	h.vector[0] = init("Popescu Dan", 2002, 5);
	h.vector[1] = init("Galescu Ion", 1994, 6);
	h.vector[2] = init("Rusu Victor", 1945, 7);
	h.vector[3] = init("Olteanu Oana", 2000, 2);
	h.vector[4] = init("Ecuadoriana Banana", 2015, 4);
	h.vector[5] = init("Durlesti Castana", 1991, 1);
	h.vector[6] = init("Kalian Leila", 2001, 9);

	afisareHeap(h);

	//determinam ultimul parinte si filtram Heap-ul pe baza lui
	for (int i = (h.dimensiune - 2) / 2; i >= 0; i--) {
		filtrareHeap(i, h);
	}

	printf("\n ---- Heap filtrat ----\n");
	afisareHeap(h);

	inserarePacientInHeap(init("UnPacientGrav", 2004, 8), &h);
	inserarePacientInHeap(init("UnPacientMediu", 2004, 5), &h);
	inserarePacientInHeap(init("UnPacientOK", 2004, 2), &h);
	printf("\n ---- Heap cu pacienti adaugati ----\n");
	afisareHeap(h);

	printf("\n ---- Extragem 3 pacienti gravi si ii afisam ----\n");
	
	afisarePacient(extragePacientGrav(&h));
	afisarePacient(extragePacientGrav(&h));
	afisarePacient(extragePacientGrav(&h));

	printf("\nafisam heap din nou");
	afisareHeap(h);




}