//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<malloc.h>>
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
//	/*copie[(*dimensiuneVector)].id = aeroport.id;
//	copie[(*dimensiuneVector)].nume = malloc(sizeof(char) * (1 + strlen(aeroport.nume));
//	strcpy(copie[(*dimensiuneVector)].nume, aeroport.nume);
//	copie[(*dimensiuneVector)].nrTerminale = aeroport.nrTerminale;*/
//
//	if (vector!= NULL) {
//		for (int i = 0; i < (*dimensiuneVector); i++) {
//			copie[i] = vector[i];
//		}
//	}
//
//	copie[*dimensiuneVector] = aeroport;
//	/*if (vector) {
//		free(vector);
//	}*/
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
//int aflaNrMaximTerminale(struct Aeroport* aeroporturi, int dimensiune) {
//	int aux = 0;
//	for (int i = 0; i < dimensiune; i++) {
//		if (aux < aeroporturi[i].nrTerminale) {
//			aux = aeroporturi[i].nrTerminale;
//		}
//	}
//	return aux;
//}
//
//
//struct Aeroport** creeazaMatrice(struct Aeroport* aeroporturi, int** dimensiuni, int nrAeroporturi, int nrCategorii) {
//	struct Aeroport** matrice;
//	matrice = malloc(sizeof(struct Aeroport*) * nrCategorii);
//	
//	*dimensiuni = malloc(sizeof(int) * nrCategorii);
//	for (int i = 0; i < nrCategorii; i++) {
//		(*dimensiuni)[i] = 0;
//		matrice[i] = NULL;
//	}
//
//	for (int i = 0; i < nrAeroporturi; i++) {
//		int index = (aeroporturi[i].nrTerminale / 5) - 1;
//		if ((aeroporturi[i].nrTerminale % 5) != 0) {
//			index++;
//		}
//		matrice[index] = adaugaAeroport(matrice[index], aeroporturi[i], &((*dimensiuni)[index]));
//	}
//
//	return matrice;
//}
//
//
//
//void afisareAeroport(struct Aeroport* aeroport) {
//	printf("Aeroportul cu id %d are numele %s si are %d terminale\n", aeroport->id, aeroport->nume, aeroport->nrTerminale);
//}
//
//void afisareVectorAeroporturi(struct Aeroport* aeroporturi, int dim) {
//	for (int i = 0; i < dim; i++) {
//		afisareAeroport(&aeroporturi[i]);
//	}
//}
//
//void afisareMatrice(struct Aeroport** matriceAeroporturi, int* dimensiuni, int nrCategorii) {
//	for (int i = 0; i < nrCategorii; i++) {
//		printf("Randul %d din matrice, cu %d-%d terminale:\n", i, i*5, (i+1)*5);
//		afisareVectorAeroporturi(matriceAeroporturi[i], dimensiuni[i]);
//		printf("\n");
//	}
//}
//
//
//
//struct Aeroport** sorteazaMatrice(struct Aeroport** matrice, int* dimensiuni, int** dimensiuniCopieMatrice, int nrCategorii) {
//	struct Aeroport** copieMatrice;
//	copieMatrice = malloc(sizeof(struct Aeroport*) * nrCategorii);
//
//	*dimensiuniCopieMatrice = malloc(sizeof(int) * nrCategorii);
//	for (int i = 0; i < nrCategorii; i++) {
//		(*dimensiuniCopieMatrice)[i] = 0;
//		copieMatrice[i] = NULL;
//	}
//
//	for (int i = 0; i < nrCategorii - 1; i++) {
//		if (dimensiuni[i] < dimensiuni[i + 1]) {
//			for (int j = 0; j < dimensiuni[i + 1]; j++) {
//				copieMatrice[i] = adaugaAeroport(copieMatrice[i], matrice[i + 1][j], &((*dimensiuniCopieMatrice)[i + 1]));
//			}
//			for (int j = 0; j < dimensiuni[i]; j++) {
//				copieMatrice[i + 1] = adaugaAeroport(copieMatrice[i + 1], matrice[i][j], &((*dimensiuniCopieMatrice)[i]));
//			}
//		}
//		else {
//			for (int j = 0; j < dimensiuni[i]; j++) {
//				copieMatrice[i] = adaugaAeroport(copieMatrice[i], matrice[i][j], &((*dimensiuniCopieMatrice)[i]));
//			}
//			for (int j = 0; j < dimensiuni[i + 1]; j++) {
//				copieMatrice[i + 1] = adaugaAeroport(copieMatrice[i + 1], matrice[i + 1][j], &((*dimensiuniCopieMatrice)[i + 1]));
//			}
//		}
//	}
//
//	afisareMatrice(copieMatrice, (*dimensiuniCopieMatrice), nrCategorii);
//
//	return copieMatrice;
//}
//
//
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
//
//
//void main() {
//	int dimensiune = 10;
//	struct Aeroport* aeroporturi = NULL;
//	aeroporturi = citireFisier("aeroporturi.txt", &dimensiune);
//	afisareVectorAeroporturi(aeroporturi, dimensiune);
//
//	//Creati o functie care sa copieze (deep copy) elementele din vector
//	//intr-o matrice alocată dinamic. Asezarea in matrice pe linii a obiectelor 
//	//o faceti dupa un criteriu aplicat unui atribut. 
//	//Astfel veti obține mai multe clustere reprezentate de liniile matricei.
//
//	int nrTerminale = aflaNrMaximTerminale(aeroporturi, dimensiune);
//	int nrCategorii = nrTerminale / 5;
//	
//	int* dimensiuniMatrice = 0;
//
//	struct Aeroport** matriceAeroporturi = creeazaMatrice(aeroporturi, &dimensiuniMatrice, dimensiune, nrCategorii);
//	printf("\n\n\n");
//	afisareMatrice(matriceAeroporturi, dimensiuniMatrice, nrCategorii);
//
//	for (int i = 0; i < nrCategorii; i++) {
//		printf("Dimensiune linia %d: %d \n", i, dimensiuniMatrice[i]);
//	}
//	
//	//Scrieti o functie care muta liniile din matrice, astfel incat 
//	//acestea sa fie sortate dupa numarul de elemente de pe linie.
//
//	int* dimensiuniMatriceSortata = 0;
//	struct Aeroport** matriceSortata = sorteazaMatrice(matriceAeroporturi, dimensiuniMatrice, &dimensiuniMatriceSortata, nrCategorii);
//	printf("\n\n -------------Matrice sortata:------------\n");
//	/*afisareMatrice(matriceSortata, dimensiuniMatriceSortata, nrCategorii);*/
//
//
//
//	dezalocareVector(&aeroporturi, &dimensiune);
//
//	//for (int i = 0; i < nrCategorii; i++) {
//	//	dezalocareVector(&(matriceAeroporturi[i]), &(dimensiuniMatrice[i]));
//	//}
//
//	free(matriceAeroporturi);
//	free(dimensiuniMatrice);
//}
//
