//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>
//
//
//
//struct Aeroport {
//	int id;
//	char* nume;
//	int nrTerminale;
//};
//
//struct Aeroport* adaugaAeroport(struct Aeroport* vector, struct Aeroport aeroport, int* dimensiuneVector) {
//	struct Aeroport* copie = (struct Aeroport*)malloc(sizeof(struct Aeroport) * ((*dimensiuneVector) + 1));
//	
//	copie[(*dimensiuneVector)] = aeroport;
//
//	for (int i = 0; i < (*dimensiuneVector); i++) {
//		copie[i] = vector[i];
//	}
//	if (vector) {
//		free(vector);
//	}
//	(*dimensiuneVector)++;
//	return copie;
//
//}
//
//struct Aeroport* citireFisier(const char* numeFisier, int* nrAeroporturi) {
//	struct Aeroport* vectorAeroporturi;
//	vectorAeroporturi = NULL;
//	FILE* f = fopen(numeFisier, "r");
//
//	if (f != NULL) {
//		char buffer[100];
//		(*nrAeroporturi) = 0;
//		while (fgets(buffer, 99, f)) {
//			struct Aeroport aeroport;
//			char delimitator[] = ",\n";
//			char* token = strtok(buffer, delimitator);
//			aeroport.id = atoi(token);
//			token = strtok(NULL, delimitator);
//			aeroport.nume = malloc(strlen(token) + 1);
//			strcpy(aeroport.nume, token);
//			token = strtok(NULL, delimitator);
//			aeroport.nrTerminale = atoi(token);
//			vectorAeroporturi = adaugaAeroport(vectorAeroporturi, aeroport, nrAeroporturi);
//		}
//		fclose(f);
//	}
//	return vectorAeroporturi;
//}
//
//void afisareAeroport(struct Aeroport* aeroport) {
//	printf("Aeroportul cu id: %d are numele %s\n", aeroport->id, aeroport->nume);
//}
//
//void afisareVectorAeroporturi(struct Aeroport* aeroporturi, int dim) {
//	printf("Afisare Vector:\n");
//	for (int i = 0; i < dim; i++) {
//		afisareAeroport(&aeroporturi[i]);
//	}
//}
//void dezalocareVector(struct Aeroport** vectorAeroporturi, int* dim) {
//	for (int i = 0; i < *dim; i++) {
//		free((*vectorAeroporturi)[i].nume);
//	}
//	free(*vectorAeroporturi);
//	(*vectorAeroporturi) = NULL;
//	(*dim) = 0;
//}
//
//
//struct Aeroport cautaAeroport(struct Aeroport* aeroporturi, int dim, int idCautat) {
//	for (int i = 0; i < dim; i++) {
//		if (aeroporturi[i].id == idCautat) {
//			return aeroporturi[i];
//		}
//	}
//	struct Aeroport aeroport;
//	aeroport.id = -1;
//	aeroport.nrTerminale = -1;
//	aeroport.nume = malloc(sizeof(char) * (1 + strlen("N/A")));
//	strcpy(aeroport.nume, "N/A");
//	return aeroport;
//}
//
//void main() {
//	int dimensiune = 3;
//
//	struct Aeroport* aeroporturi = NULL;
//	aeroporturi = citireFisier("aeroporturi.txt", &dimensiune);
//
//	afisareVectorAeroporturi(aeroporturi, dimensiune);
//
//
//	struct Aeroport aeroportCautat = cautaAeroport(aeroporturi, dimensiune, 1);
//	afisareAeroport(&aeroportCautat);
//
//	dezalocareVector(&aeroporturi, &dimensiune);
//
//}