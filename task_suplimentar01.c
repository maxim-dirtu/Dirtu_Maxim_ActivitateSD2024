#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS

//Maxim Dirtu -> M si D. Articolul 

struct Medic {
	int aniExperienta;
	char* specializare;
	int nrPacienti;
	char** numePacienti;
	float salariu;
};

struct Medic initializare(int aniExperienta, const char* specializare, int nrPacienti, const char** numePacienti, float salariu) {
	struct Medic m;
	m.aniExperienta = aniExperienta;
	m.nrPacienti = nrPacienti;
	m.salariu = salariu;
	m.specializare = malloc(sizeof(char) * (strlen(specializare) + 1));
	strcpy(m.specializare, specializare);
	m.numePacienti = malloc(sizeof(char*) * nrPacienti);
	for (int i = 0; i < nrPacienti; i++) {
		m.numePacienti[i] = malloc(sizeof(char) * (strlen(numePacienti[i]) + 1));
		strcpy(m.numePacienti[i], numePacienti[i]);
	}

	return m;
}


void dezalocare(struct Medic* m) {
	free(m->specializare);
	m->specializare = NULL;
	for (int i = 0; i < m->nrPacienti; i++) {
		free(m->numePacienti[i]);
		m->numePacienti[i] = NULL;
	}
	free(m->numePacienti);
	m->numePacienti = NULL;
}


void afisare(struct Medic m) {
	printf("Medicul are %d ani exp., specializat in %s, salariu de %5.2f, cu  urmatorii %d pacienti:\n", m.aniExperienta, m.specializare, m.salariu, m.nrPacienti);
	for (int i = 0; i < m.nrPacienti; i++) {
		printf("Nume pacient nr. %d: %s", i, m.numePacienti[i]);
		printf("\n");
	}
	printf("\n");
}

float salariuPerPacient(struct Medic* m) {
	float rez;
	rez = (*m).salariu / (*m).nrPacienti;
	return rez;
}

void modificaSalariu(struct Medic* m, float* salariu) {
	(*m).salariu = (*salariu);
}




int main() {
	const char* pacienti[4] = { "adi", "dan", "ion", NULL };
	struct Medic ionDatornic = initializare(10, "Cardiologie", 3, pacienti, 2100);
	afisare(ionDatornic);
	


	int aniExp;
	char specializare[15]; 
	int nrPacienti;
	float salariu;

	printf("Ani experienta: ");
	scanf_s("%d", &aniExp);
	printf("Specializare: ");
	scanf_s("%s", specializare, sizeof(specializare)); // No & needed for arrays
	printf("Numar pacienti: ");
	scanf_s("%d", &nrPacienti);

	char* numePacienti[10];
	for (int i = 0; i < nrPacienti; i++) {
		char numePacient[15];
		printf("Nume pacient %d: ", i + 1);
		scanf_s("%s", numePacient, sizeof(numePacient));
		numePacienti[i] = malloc(sizeof(char) * strlen(numePacient));
		strcpy(numePacienti[i], numePacient); // Copy the string into dynamically allocated memory
	}

	printf("Salariu: ");
	scanf_s("%f", &salariu);

	struct Medic vladHoinaru = initializare(aniExp, specializare, nrPacienti, numePacienti, salariu);
	afisare(vladHoinaru);


	float salariuPerPacientM1 = salariuPerPacient(&ionDatornic);
	printf("%5.2f\n\n", salariuPerPacientM1);

	float salariuMeritat = 5000;
	modificaSalariu(&ionDatornic, &salariuMeritat);
	afisare(ionDatornic);

	dezalocare(&vladHoinaru);
	dezalocare(&ionDatornic);

	return 0;
}