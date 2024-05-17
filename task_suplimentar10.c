//arbore avl
//diferenta de inaltime intre subarborele stang si cel drept trebuie sa fie de maxim 1 = grad de echilibru
//noi facem stanga - dreapta => daca am 2 - 0 = 2 (pozitiv) => dezechilibru in stanga

//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//typedef struct Rezultat Rezultat;
//struct Rezultat {
//	int scor;
//	char* nume;
//};
//
//typedef struct Nod Nod;
//
//struct Nod {
//	Nod* stanga;
//	Nod* dreapta;
//	Rezultat info;
//};
//
//typedef struct NodLS NodLS;
//struct NodLS {
//	Rezultat info;
//	NodLS* next;
//};
//
//typedef struct NodLD NodLD;
//struct NodLD {
//	Rezultat info;
//	NodLD* next;
//	NodLD* prev;
//};
//
//void afisareRezultat(Rezultat r) {
//	printf("Rezultatul pentru studentul %s este: %d\n", r.nume, r.scor);
//}
//
//Rezultat citireRezultat(FILE* f, Rezultat* r) {
//	fscanf(f, "%d", &r->scor);
//
//	char aux[20];
//	fscanf(f, "%s", &aux);
//	r->nume = malloc(sizeof(char) * (strlen(aux) + 1));
//	strcpy(r->nume, aux);
//
//}
//
//Nod* inserareArbore(Nod* radacina, Rezultat rez);
//
//void citireFisier(const char* fileName, Nod** radacina) {
//	FILE* f = fopen(fileName, "r");
//
//	int nrRezultate = 0;
//	fscanf(f, "%d", &nrRezultate);
//
//	for (int i = 0; i < nrRezultate; i++) {
//		Rezultat rez;
//
//		citireRezultat(f, &rez);
//
//		*radacina = inserareArbore(*radacina, rez);
//	}
//	fclose(f);
//}
//
//
////	pt. arbore binar de cautare, la inserare se compara nodurile arborelui cu ce vrem sa inseram
////in functie de un id/scor si se foloseste recursiv pe partea stanga sau dreapta in functie de rezultatul comparatiei
////	in plus, in cazul AVL, se calculeaza si un grad de echilibru dupa inserare (ce este, in fapt diferenta de inaltimi intre subarbore-S si subarbore-D)
////si daca se observa un dezechilibru se recurge la rotiri
//  
//int calculInaltimeArbore(Nod* radacina) {
//	// se calculeaza inaltimea recursiv
//	if (radacina) {
//		int inaltimeStanga = calculInaltimeArbore(radacina->stanga);
//		int inaltimeDreapta = calculInaltimeArbore(radacina->dreapta);
//		return 1 + (inaltimeStanga > inaltimeDreapta ? inaltimeStanga : inaltimeDreapta);
//	}
//	else return 0;
//	
//}
//
//int calculGradEchilibru(Nod* radacina) {
//	if (radacina) {
//		int inaltimeStanga = calculInaltimeArbore(radacina->stanga);
//		int inaltimeDreapta = calculInaltimeArbore(radacina->dreapta);
//
//		return inaltimeStanga - inaltimeDreapta;
//	}
//	else return 0;	
//}
//
//Nod* rotireLaStanga(Nod* radacina) {
//	if (radacina) {
//		printf("\t***Rotire la stanga pentru radacina %d***\n", radacina->info.scor);
//
//		Nod* aux = radacina->dreapta;
//		radacina->dreapta = aux->stanga;
//		aux->stanga = radacina;
//		return aux;
//	}
//	else return NULL;
//}
//
//Nod* rotireLaDreapta(Nod* radacina) {
//	if (radacina) {
//		printf("\t***Rotire la dreapta pentru radacina %d***\n", radacina->info.scor);
//		Nod* aux = radacina->stanga;
//		radacina->stanga = aux->dreapta;
//		aux->dreapta = radacina;
//		return aux;
//	}
//	else return NULL;
//
//}
//
//Nod* inserareArbore(Nod* radacina, Rezultat rez) {
//
//	if (radacina) {
//		//pas 1. - inseram in arbore
//		if (rez.scor < radacina->info.scor) {
//			//mai mic - deci inseram in stanga
//			radacina->stanga = inserareArbore(radacina->stanga, rez);
//		}
//		else {
//			//mai mare - deci inseram pe ramura dreapta
//			radacina->dreapta = inserareArbore(radacina->dreapta, rez);
//		}
//
//		//pas 2. - echilibram  arborele (AVL)
//
//		int gradEchilibru = calculGradEchilibru(radacina);
//		if (gradEchilibru == 2) { //daca == 2 avem dezechilibru pe ramura stanga
//			if (calculGradEchilibru(radacina->stanga) == 1) { // avem dezechilibru usor pe ramura stanga iar
//				//deci rotim o data LA DREAPTA
//				radacina = rotireLaDreapta(radacina);
//			}
//			else if(calculGradEchilibru(radacina->stanga)==-1){ // avem dezechilibru usor pe ramura dreapta a nodului din stanga
//				//1 rotire la stanga - echilibrarea ramurii stangi a radacinii pe partea dreapta si rotire la dreapta - echilibrare a arborelui complet
//				//deci rotim o data LA STANGA si o data LA DREAPTA  
//				radacina->stanga = rotireLaStanga(radacina->stanga);
//				radacina = rotireLaDreapta(radacina);
//			}
//		}
//		else if (gradEchilibru == -2) {//daca == -2 avem dezechilibru pe ramura dreapta
//			//cand avem dezechilibru pe partea dreapta, conform exemplului de mai sus:
//			//mereu o sa fie nevoie sa rotim minim o data LA STANGA,
//			//deci verificam doar daca este envoie de o dubla rotire, iar rotirea LA STANGA o facem in orice caz
//			if (calculGradEchilibru(radacina->dreapta) == 1) {
//				//rotim LA DREAPTA
//				radacina->dreapta = rotireLaDreapta(radacina->dreapta);
//			}
//			//rotim LA STANGA
//			radacina = rotireLaStanga(radacina);
//
//		}
//	}
//	else {
//		Nod* nou = malloc(sizeof(Nod));
//		nou->info.scor = rez.scor;
//		nou->info.nume = malloc(sizeof(char) * (strlen(rez.nume) + 1));
//		strcpy(nou->info.nume, rez.nume);
//
//		nou->dreapta = NULL;
//		nou->stanga = NULL;
//
//		radacina = nou;
//	}
//
//	return radacina;
//}
//
////citim arborele in 3 moduri
////preordine - RSD
////postordine - SDR
////inordine - SRD
//
//void afisareArborePreordine(Nod* radacina, Nod* radacinaReala) {
//	if (radacina) {
//		afisareRezultat(radacina->info);
//		if (radacina == radacinaReala) {
//			printf("Subarbore stang\n");
//		}
//
//		afisareArborePreordine(radacina->stanga, radacinaReala);
//		
//		if (radacina == radacinaReala) {
//			printf("Subarbore drept\n");
//		}
//		afisareArborePreordine(radacina->dreapta, radacinaReala);
//	}
//}
//
//
////sarcini aditionale
////Sa se realizeze functia de cautare a unui  nod in arborele AVL, pe baza unui id, sau a cheii de cautare din arbore.
//Rezultat cautareRezultatDupaScor(Nod* radacina, int scor) {
//	if (radacina) {
//		if (radacina->info.scor < scor) {
//			cautareRezultatDupaScor(radacina->dreapta, scor);
//		}
//		else if (radacina->info.scor > scor) {
//			cautareRezultatDupaScor(radacina->stanga, scor);
//		}
//		else return radacina->info;
//	}
//	else {
//		Rezultat r;
//		r.scor = -1;
//		r.nume = NULL;
//		return r;
//	}
//
//}
//int calculareNumarNoduri(Nod* radacina) {
//	if (radacina == NULL) {
//		return 0;
//	}
//	else {
//		return 1 + calculareNumarNoduri(radacina->stanga) + calculareNumarNoduri(radacina->dreapta);
//	}
//}
//
////task 2
//
//void creareVectorDinArborePreordine(Nod* radacina, Rezultat* vector, int* index) {
//	if (radacina) {
//		vector[*index] = radacina->info;
//		(*index)++;
//		creareVectorDinArborePreordine(radacina->stanga, vector, index);
//		creareVectorDinArborePreordine(radacina->dreapta, vector, index);
//	}
//};
//
//void creareVectorDinArborePostordine(Nod* radacina, Rezultat* vector, int* index) {
//	if (radacina) {
//		creareVectorDinArborePostordine(radacina->stanga, vector, index);
//		creareVectorDinArborePostordine(radacina->dreapta, vector, index);
//		vector[*index] = radacina->info;
//		(*index)++;
//	}
//};
//void creareVectorDinArboreInordine(Nod* radacina, Rezultat* vector, int* index) {
//	if (radacina) {
//		creareVectorDinArboreInordine(radacina->stanga, vector, index);
//		vector[*index] = radacina->info;
//		(*index)++;
//		creareVectorDinArboreInordine(radacina->dreapta, vector, index);
//	}
//};
//
//void afisareVector(Rezultat* vector, int dim) {
//	for (int i = 0; i < dim; i++) {
//		Rezultat r = vector[i];
//		afisareRezultat(r);
//	}
//}
//
////task3
//void adaugaInListaSimpla(NodLS** cap, Rezultat r) {
//    NodLS* deInserat = malloc(sizeof(NodLS));
//    deInserat->info = r;
//    deInserat->next = NULL;
//
//    if (*cap == NULL) {
//        *cap = deInserat;
//    } else {
//        NodLS* aux = *cap;
//        while (aux->next) {
//            aux = aux->next;
//        }
//        aux->next = deInserat;
//    }
//}
//
//
//
//void creareListaSimplaDinArborePreordine(Nod* radacina, NodLS** cap) {
//	if (radacina) {
//		adaugaInListaSimpla(cap, radacina->info);
//		creareListaSimplaDinArborePreordine(radacina->stanga, cap);
//		creareListaSimplaDinArborePreordine(radacina->dreapta, cap);
//	}
//};
//
//void afisareListaSimpla(NodLS* cap) {
//	NodLS* aux = cap;
//	while (aux) {
//		afisareRezultat(aux->info);
//		aux = aux->next;
//	}
//}
//
////task 4
////Sa se realizeze o functie care salveaza nodurile din arborele AVL intr - o lista dublu inlantuita, prin parcurgerea preordine, inordine, postordine.
//
//void adaugaInListaDubla(NodLD** cap, Rezultat r) {
//	if (*cap!=NULL) {
//		NodLD* aux = *cap;
//		while (aux->next) {
//			aux = aux->next;
//		}
//		NodLD* deInserat = malloc(sizeof(NodLD));
//		deInserat->info = r;
//		deInserat->prev = aux;
//		deInserat->next = NULL;
//		aux->next = deInserat;
//	}
//	else {
//		NodLD* nou = malloc(sizeof(NodLD));
//		nou->info = r;
//		nou->next = NULL;
//		nou->prev = NULL;
//		*cap = nou;
//	}
//}
//
//void afisareListaDubla(NodLD* cap) {
//	NodLD* aux = cap;
//	while (aux->next) {
//		afisareRezultat(aux->info);
//		aux = aux->next;
//	}
//	afisareRezultat(aux->info);
//
//}
//
//void creareListaDublaDinArborePreordine(Nod* radacina, NodLD** cap) {
//	if (radacina){
//		adaugaInListaDubla(cap, radacina->info);
//		creareListaDublaDinArborePreordine(radacina->stanga, cap);
//		creareListaDublaDinArborePreordine(radacina->dreapta, cap);
//	}
//};
//
//
//
//
//void main() {
//	//creare arbore
//	Nod* radacina = NULL;
//	citireFisier("punctaje.txt", &radacina);
//	printf("Afisare arbore preordine\n");
//	afisareArborePreordine(radacina, radacina);
//
//	//adauagre noduri noi
//	Rezultat r1;
//	r1.scor = 14;
//	r1.nume = malloc(sizeof(char) * (strlen("Maria") + 1));
//	strcpy(r1.nume, "Maria");
//	printf("\nInseram un nod cu scor 14\n");
//	radacina =inserareArbore(radacina, r1);
//	printf("Afisare arbore preordine\n");
//	afisareArborePreordine(radacina, radacina);
//
//	Rezultat r2;
//	r2.scor = 19;
//	r2.nume = malloc(sizeof(char) * (strlen("Ion") + 1));
//	strcpy(r2.nume, "Ion");
//	printf("\nInseram un nod cu scor 19\n");
//	radacina =inserareArbore(radacina, r2);
//	printf("Afisare arbore preordine\n");
//	afisareArborePreordine(radacina, radacina);
//	
//	Rezultat r3;
//	r3.scor = 51;
//	r3.nume = malloc(sizeof(char) * (strlen("Noul venit") + 1));
//	strcpy(r3.nume, "Noul venit");
//	printf("\nInseram un nod cu scor 51\n");
//	radacina=inserareArbore(radacina, r3);
//	printf("Afisare arbore preordine\n");
//	afisareArborePreordine(radacina, radacina);
//
//	//task1
//	printf("Cautare Nod cu scor 19\n");
//	afisareRezultat(cautareRezultatDupaScor(radacina, 19));
//
//	//task2
//	//Sa se realizeze o functie care salveaza nodurile din arborele AVL intr - un vector, prin parcurgerea preordine, inordine, postordine.
//	int numarNoduri = calculareNumarNoduri(radacina);
//	Rezultat* vector = malloc(sizeof(Rezultat) * numarNoduri);
//
//	// Preordine
//	int index = 0;
//	creareVectorDinArborePreordine(radacina, vector, &index);
//	printf("\nVector preordine:\n");
//	afisareVector(vector, numarNoduri);
//
//	//Inordine
//	// Resetare index pentru următoarea parcurgere
//	index = 0;
//	creareVectorDinArboreInordine(radacina, vector, &index);
//	printf("\nVector inordine:\n");
//	afisareVector(vector, numarNoduri);
//
//	//task3
//	//Sa se realizeze o functie care salveaza nodurile din arborele AVL intr-un vector, prin parcurgerea preordine, inordine, postordine.
//	NodLS* cap = NULL;
//	creareListaSimplaDinArborePreordine(radacina, &cap);
//	printf("\nAfisare lista simpla:\n");
//	afisareListaSimpla(cap);
//
//
//	//task 4
//	NodLS* capLD = NULL;
//	creareListaDublaDinArborePreordine(radacina, &capLD);
//	printf("\nAfisare lista dubla:\n");
//	afisareListaDubla(capLD);
//}
