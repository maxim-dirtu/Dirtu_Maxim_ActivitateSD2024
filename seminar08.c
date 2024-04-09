//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Mesaj Mesaj;
//typedef struct Heap Heap;
//
//struct Mesaj {
//	char* text;
//	int prioritate;
//};
//
//struct Heap {
//	Mesaj* vector;
//	int dimensiune;
//	int dimensiuneTotala;
//};
//
//Mesaj init(const char* text, int prioritate) {
//	Mesaj m;
//	m.text = malloc(sizeof(char) * (1 + strlen(text)));
//	strcpy(m.text, text);
//	m.prioritate = prioritate;
//
//	return m;
//}
//
//void afisareMesaj(Mesaj m) {
//	printf("Mesajul cu textul %s are prioritatea %d\n", m.text, m.prioritate);
//}
//
//Heap initHeap(int dim) {
//	Heap h;
//	h.dimensiune = 0;
//	h.dimensiuneTotala = dim;
//	h.vector = malloc(sizeof(Mesaj) * dim);
//	return h;
//}
//
//void afisareHeap(Heap h) {
//	printf("\n");
//	for (int i = 0; i < h.dimensiune; i++) {
//		afisareMesaj(h.vector[i]);
//	}
//}
//
//void filtrareHeap(Heap h, int poz) {
//	int poz_s = poz * 2 + 1;
//	int poz_d = poz * 2 + 2;
//
//	int poz_m = poz;
//
//	if (poz_s<h.dimensiune && h.vector[poz_s].prioritate >h.vector[poz_m].prioritate) {
//		poz_m = poz_s;
//	}
//
//	if (poz_d<h.dimensiune && h.vector[poz_d].prioritate >h.vector[poz_m].prioritate) {
//		poz_m = poz_d;
//	}
//
//	if (poz_m != poz) {
//		Mesaj aux = h.vector[poz];
//		h.vector[poz] = h.vector[poz_m];
//		h.vector[poz_m] = aux;
//
//		if ((poz_m*2)+1< h.dimensiune) {
//			filtrareHeap(h, poz_m);
//		}
//		
//	}
//}
//
//Mesaj extragereDinHeap(Heap* h) {
//	if (h->dimensiune > 0) {
//		Mesaj aux = h->vector[0];
//		h->vector[0] = h->vector[(*h).dimensiune - 1];
//		h->vector[(*h).dimensiune - 1] = aux;
//		h->dimensiune--;
//		for (int i = (h->dimensiune / 2) - 1; i >= 0; i--)
//		{
//			filtrareHeap((*h), i);
//		}
//		return aux;
//	}
//	
//}
//
//void afisareHeapTotal(Heap h) {
//	printf("\n");
//	for (int i = 0; i < h.dimensiuneTotala; i++) {
//		afisareMesaj(h.vector[i]);
//	}
//}
//
//void dezalocareHeap(Heap* h) {
//	if (h->vector != NULL) {
//		for (int i = 0; i < h->dimensiuneTotala; i++) {
//			free(h->vector[i].text);
//		}
//		free(h->vector);
//		h->dimensiune = 0;
//		h->dimensiuneTotala = 0;
//	}
//}
//
//void main() {
//	Heap h;
//	h = initHeap(6);
//	h.vector[0] = init("Buna", 3);
//	h.vector[1] = init("Salut", 8);
//	h.vector[2] = init("Ce faci", 6);
//	h.vector[3] = init("Esti din ghetto?", 2);
//	h.vector[4] = init("show face", 9);
//	h.vector[5] = init("im indian", 4);
//	h.dimensiune = 6;
//
//	afisareHeap(h);
//
//	for(int i = (h.dimensiune / 2)-1; i >=0 ; i--)
//	{
//		filtrareHeap(h, i);
//	}
//	afisareHeap(h);
//	printf("\nExtragem mesajele: \n");
//	afisareMesaj(extragereDinHeap(&h));
//	afisareMesaj(extragereDinHeap(&h));
//	afisareMesaj(extragereDinHeap(&h));
//	afisareMesaj(extragereDinHeap(&h));
//	afisareMesaj(extragereDinHeap(&h));
//	afisareMesaj(extragereDinHeap(&h));
//
//	printf("\nHeap total");
//	afisareHeapTotal(h);
//
//	dezalocareHeap(&h);
//	printf("\nAfisam heap dupa dezalocare\n");
//	afisareHeap(h);
//}