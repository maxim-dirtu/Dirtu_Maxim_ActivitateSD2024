//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include <string.h>
//
//typedef struct Aeroport Aeroport;
//typedef struct NodLD NodLD;
//typedef struct listaDubla listaDubla;
//
//
//
//struct Aeroport {
//	int id;
//	char* nume;
//	int nrTerminale;
//
//};
//
//struct NodLD {
//	Aeroport info;
//	NodLD* next;
//	NodLD* previous;
//};
//
//struct listaDubla {
//	NodLD* prim;
//	NodLD* ultim;
//};
//
//listaDubla creareListaDublaDinFisier(const char* numeFisier) {
//	listaDubla listaDubla;
//	listaDubla.prim = NULL;
//	listaDubla.ultim = NULL;
//	NodLD* nod;
//	nod = malloc(sizeof(NodLD));
//
//	FILE* f = fopen(numeFisier, "r");
//			if (f != NULL) {
//				char buffer[100];
//				char delimitator[] = ",\n";
//				while (fgets(buffer, 100, f) != NULL) {
//					Aeroport aeroport;
//					char* token;
//					token = strtok(buffer, delimitator);
//					aeroport.id = atoi(token);
//					token = strtok(NULL, delimitator);
//					aeroport.nume = (char*)malloc(strlen(token) + 1);
//					strcpy(aeroport.nume, token);
//					token = strtok(NULL, delimitator);
//					aeroport.nrTerminale = atoi(token);
//
//					nod->next = NULL;
//					nod->info = aeroport;
//					nod->previous = listaDubla.ultim;
//
//					if (listaDubla.ultim) {
//						listaDubla.ultim->next = nod;
//						listaDubla.ultim = nod;
//					}
//					else {
//						listaDubla.prim = nod;
//						listaDubla.ultim = nod;
//					}
//
//				}
//				fclose(f);
//			}
//}
//
//void afisare(Aeroport a) {
//	printf("Aeroportul cu id %d, denumirea - %s si %d terminale\n", a.id, a.nume, a.nrTerminale);
//}
//
//void afisareListaDubla(NodLD* primulNod)
//{
//
//	while (primulNod)
//	{
//		afisare(primulNod->info);
//		primulNod = primulNod->next;
//	}
//}
//
//
//
//void main() {
//	listaDubla lista1 = creareListaDublaDinFisier("aeroporturi.txt");
//	afisareListaDubla(lista1.prim);
//
//}