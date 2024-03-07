#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>>



struct Aeroport {
	int id;
	char* nume;
	int nrTerminale;
};

struct Aeroport* adaugaAeroport(struct Aeroport* vector, struct Aeroport aeroport, int* dimensiuneVector) {
	struct Aeroport* copie = (struct Aeroport*)malloc(sizeof(struct Aeroport) * ((*dimensiuneVector) + 1));

	copie[(*dimensiuneVector)] = aeroport;

	for (int i = 0; i < (*dimensiuneVector); i++) {
		copie[i] = vector[i];
	}
	if (vector) {
		free(vector);
	}
	(*dimensiuneVector)++;
	return copie;

}

struct Aeroport* citireFisier(const char* numeFisier, int* nrAeroporturi) {
	struct Aeroport* vectorAeroporturi;
	vectorAeroporturi = NULL;
	FILE* f = fopen(numeFisier, "r");

	if (f != NULL) {
		char buffer[100];
		(*nrAeroporturi) = 0;
		while (fgets(buffer, 99, f)) {
			struct Aeroport aeroport;
			char delimitator[] = ",\n";
			char* token = strtok(buffer, delimitator);
			aeroport.id = atoi(token);
			token = strtok(NULL, delimitator);
			aeroport.nume = malloc(strlen(token) + 1);
			strcpy(aeroport.nume, token);
			token = strtok(NULL, delimitator);
			aeroport.nrTerminale = atoi(token);
			vectorAeroporturi = adaugaAeroport(vectorAeroporturi, aeroport, nrAeroporturi);
		}
		fclose(f);
	}
	return vectorAeroporturi;
}

void scrieObiectInFisier(const char* numeFisier, struct Aeroport* aeroport) {
	FILE* f = fopen(numeFisier, "w");
	if (f != NULL) {
		fprintf(f, "%d,%s,%d\n", aeroport->id, aeroport->nume, aeroport->nrTerminale);
	}
	fclose(f);
}

void scrieVectorObiecteInFisier(const char* numeFisier, struct Aeroport* aeroporturi, int* dimensiune) {
	FILE* f = fopen(numeFisier, "w");

	if (f != NULL) {
		for (int i = 0; i < (*dimensiune); i++) {
			fprintf(f, "%d,%s,%d\n", aeroporturi[i].id, aeroporturi[i].nume, aeroporturi[i].nrTerminale);
		}
	}


	fclose(f);
}





void afisareAeroport(struct Aeroport* aeroport) {
	printf("Aeroportul cu id %d are numele %s si are %d terminale\n", aeroport->id, aeroport->nume, aeroport->nrTerminale);
}

void afisareVectorAeroporturi(struct Aeroport* aeroporturi, int dim) {
	printf("Afisare Vector:\n");
	for (int i = 0; i < dim; i++) {
		afisareAeroport(&aeroporturi[i]);
	}
}



void dezalocareVector(struct Aeroport** vectorAeroporturi, int* dim) {
	for (int i = 0; i < *dim; i++) {
		free((*vectorAeroporturi)[i].nume);
	}
	free(*vectorAeroporturi);
	(*vectorAeroporturi) = NULL;
	(*dim) = 0;
}




void main() {
	int dimensiune = 10;

	struct Aeroport* aeroporturi = NULL;
	aeroporturi = citireFisier("aeroporturi.txt", &dimensiune);

	afisareVectorAeroporturi(aeroporturi, dimensiune);

	//task03 - sarcina 3 - scrie un obiect in fisier
	struct Aeroport aeroportOUT;
	aeroportOUT.id = 30;
	aeroportOUT.nrTerminale = 20;
	aeroportOUT.nume = malloc(sizeof(char) * (1 + strlen("aeroportTest")));
	strcpy(aeroportOUT.nume, "aeroportTest");
	
	printf("\n");
	afisareAeroport(&aeroportOUT);

	scrieObiectInFisier("aeroportOUT.txt", &aeroportOUT);

	//task03 - sarcina 04 - scrie un vector de obiecte in fisier
	scrieVectorObiecteInFisier("aeroporturiOUT.txt", aeroporturi, &dimensiune);


	dezalocareVector(&aeroporturi, &dimensiune);
	free(aeroportOUT.nume);
}