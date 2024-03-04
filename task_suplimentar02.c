//#include <stdio.h>
//#include <stdlib.h>
//#include <malloc.h>
//#define _CRT_SECURE_NO_WARNINGS
//
////Maxim Dirtu -> M si D. Articolul 
//
//struct Medic {
//	int aniExperienta;
//	char* specializare;
//	int nrPacienti;
//	char** numePacienti;
//	float salariu;
//};
//
//struct Medic initializare(int aniExperienta, const char* specializare, int nrPacienti, const char** numePacienti, float salariu) {
//	struct Medic m;
//	m.aniExperienta = aniExperienta;
//	m.nrPacienti = nrPacienti;
//	m.salariu = salariu;
//	m.specializare = malloc(sizeof(char) * (strlen(specializare) + 1));
//	strcpy(m.specializare, specializare);
//	m.numePacienti = malloc(sizeof(char*) * nrPacienti);
//	for (int i = 0; i < nrPacienti; i++) {
//		m.numePacienti[i] = malloc(sizeof(char) * (strlen(numePacienti[i]) + 1));
//		strcpy(m.numePacienti[i], numePacienti[i]);
//	}
//
//	return m;
//}
//
//
//void dezalocare(struct Medic* m) {
//	free(m->specializare);
//	m->specializare = NULL;
//	for (int i = 0; i < m->nrPacienti; i++) {
//		free(m->numePacienti[i]);
//		m->numePacienti[i] = NULL;
//	}
//	free(m->numePacienti);
//	m->numePacienti = NULL;
//}
//
//
//void afisare(struct Medic m) {
//	printf("Medicul are %d ani exp., specializat in %s, salariu de %5.2f, cu  urmatorii %d pacienti:\n", m.aniExperienta, m.specializare, m.salariu, m.nrPacienti);
//	for (int i = 0; i < m.nrPacienti; i++) {
//		printf("Nume pacient nr. %d: %s", i, m.numePacienti[i]);
//		printf("\n");
//	}
//	printf("\n");
//}
//
//float salariuPerPacient(struct Medic* m) {
//	float rez;
//	rez = (*m).salariu / (*m).nrPacienti;
//	return rez;
//}
//
//void modificaSalariu(struct Medic* m, float* salariu) {
//	(*m).salariu = (*salariu);
//}
//
//void afisareVector(struct Medic** vectorMedici, int* nrMedici) {
//	for (int i = 0; i < (*nrMedici); i++)
//	{
//		afisare((*vectorMedici)[i]);
//	}
//}
//
//struct Medic* filtreazaMediciDupaExperienta(struct Medic** listaMedici, int* nrMedici, int pragExperienta, int* nrMediciNou) {
//	struct Medic* listaNoua;
//	//variabila pt calcularea nr. de medici ce vor fi in noul vector
//	*nrMediciNou = 0;
//	for (int i = 0; i < *nrMedici; i++) {
//		if ((*listaMedici)[i].aniExperienta > pragExperienta) {
//			(*nrMediciNou)++;
//		}
//	}
//
//	listaNoua = malloc(sizeof(struct Medic) * (*nrMediciNou));
//	int k = 0;
//	for (int i = 0; i < *nrMedici; i++) {
//		if ((*listaMedici)[i].aniExperienta > pragExperienta) {
//			listaNoua[k++] = initializare((*listaMedici)[i].aniExperienta, (*listaMedici)[i].specializare, (*listaMedici)[i].nrPacienti, (*listaMedici)[i].numePacienti, (*listaMedici)[i].salariu);
//		}
//	}
//
//	return listaNoua;
//}
//
//void filtreazaMediciDupaSalariu(struct Medic** listaMedici, int* nrMedici, struct Medic** listaNouaMedici, int* nrNouMedici, int pragSalariu) {
//	*nrNouMedici = 0;
//	for (int i = 0; i < *nrMedici; i++) {
//		if ((*listaMedici)[i].salariu > pragSalariu) {
//			(*nrNouMedici)++;
//		}
//	}
//
//	*listaNouaMedici = malloc(sizeof(struct Medic) * (*nrNouMedici));
//	int k = 0;
//	for (int i = 0; i < *nrMedici; i++) {
//		if ((*listaMedici)[i].salariu > pragSalariu) {
//			*listaNouaMedici[k++] = initializare((*listaMedici)[i].aniExperienta, (*listaMedici)[i].specializare, (*listaMedici)[i].nrPacienti, (*listaMedici)[i].numePacienti, (*listaMedici)[i].salariu);
//		}
//	}
//}
//
//struct Medic* concateneazaVectori(struct Medic** listaMedici1, int* nrMedici1, struct Medic** listaMedici2, int* nrMedici2, int* nrMediciNou) {
//	struct Medic* listaNoua;
//	*nrMediciNou = *nrMedici1 + *nrMedici2;
//
//	listaNoua = malloc(sizeof(struct Medic) * (*nrMediciNou) );
//	int k = 0;
//
//	for (int i = 0; i < *nrMedici1; i++)
//	{
//		listaNoua[k++] = initializare((*listaMedici1)[i].aniExperienta, (*listaMedici1)[i].specializare, (*listaMedici1)[i].nrPacienti, (*listaMedici1)[i].numePacienti, (*listaMedici1)[i].salariu);
//	}
//	for (int i = 0; i < *nrMedici2; i++)
//	{
//		listaNoua[k++] = initializare((*listaMedici2)[i].aniExperienta, (*listaMedici2)[i].specializare, (*listaMedici2)[i].nrPacienti, (*listaMedici2)[i].numePacienti, (*listaMedici2)[i].salariu);
//	}
//
//	return listaNoua;
//}
//
//
//int main() {
//	const char* pacienti[4] = { "adi", "dan", "ion", NULL };
//	struct Medic ionDatornic = initializare(10, "Cardiologie", 3, pacienti, 2100);
//	afisare(ionDatornic);
//
//	//int aniExp;
//	//char specializare[15];
//	//int nrPacienti;
//	//float salariu;
//
//	//printf("Ani experienta: ");
//	//scanf_s("%d", &aniExp);
//	//printf("Specializare: ");
//	//scanf_s("%s", specializare, sizeof(specializare)); // No & needed for arrays
//	//printf("Numar pacienti: ");
//	//scanf_s("%d", &nrPacienti);
//
//	//char* numePacienti[10];
//	//for (int i = 0; i < nrPacienti; i++) {
//	//	char numePacient[15];
//	//	printf("Nume pacient %d: ", i + 1);
//	//	scanf_s("%s", numePacient, sizeof(numePacient));
//	//	numePacienti[i] = malloc(sizeof(char) * strlen(numePacient));
//	//	strcpy(numePacienti[i], numePacient); // Copy the string into dynamically allocated memory
//	//}
//
//	//printf("Salariu: ");
//	//scanf_s("%f", &salariu);
//
//	//struct Medic vladHoinaru = initializare(aniExp, specializare, nrPacienti, numePacienti, salariu);
//	//afisare(vladHoinaru);
//
//	float salariuPerPacientM1 = salariuPerPacient(&ionDatornic);
//	printf("%5.2f\n\n", salariuPerPacientM1);
//
//	float salariuMeritat = 5000;
//	modificaSalariu(&ionDatornic, &salariuMeritat);
//	afisare(ionDatornic);
//
//	//task 2 - sarcina 1 - creati vector alocat dinamic de 5 obiecte
//	const char* pacientiV1[3] = { "dan", "ion", NULL };
//	const char* pacientiV2[4] = { "razvan", "golan", "andi", NULL};
//
//	struct Medic m2 = initializare(10, "kineto", 2, pacientiV1, 9000);
//	struct Medic m3 = initializare(20, "dermatologie", 3, pacientiV2, 35000);
//	struct Medic m4 = initializare(42, "pediatrie", 2, pacientiV1, 12000);
//	struct Medic m5 = initializare(5, "generala", 3, pacientiV2, 1700);
//
//	int nrMedici = 5;
//	struct Medic* listaMedici = (struct Medic*)malloc(sizeof(struct Medic) * nrMedici);
//	listaMedici[0] = ionDatornic;
//	listaMedici[1] = m2;
//	listaMedici[2] = m3;
//	listaMedici[3] = m4;
//	listaMedici[4] = m5;
//
//	afisareVector(&listaMedici, &nrMedici);
//
//	//task2 - sarcina 2 -functie care creeaza un nou vector si copiaza din vector primit ca 
//	//parametru obiectele care implinesc o anumita conditie
//	printf("--------------Task 2, sarcina 2------------------\n");
//	int nrMediciNou = 0;
//	struct Medic* listaMediciNoua = filtreazaMediciDupaExperienta(&listaMedici, &nrMedici, 10, &nrMediciNou);
//	afisareVector(&listaMediciNoua, &nrMediciNou);
//	
//	//task2 - sarcina 3 - functie care multa intr-un vector nou obiectele dupa o cerinta noua
//	printf("--------------Task 2, sarcina 3------------------\n");
//	int nrMediciVectorSalarii = 0;
//	struct Medic* listaMediciDupaSalarii;
//	filtreazaMediciDupaSalariu(&listaMediciNoua, &nrMediciNou, &listaMediciDupaSalarii, &nrMediciVectorSalarii, 15000);
//	afisareVector(&listaMediciDupaSalarii, &nrMediciVectorSalarii);
//	
//	//task 2 - sarcina 4 - functie care concateneaza doi vectori
//	printf("--------------Task 2, sarcina 4------------------\n");
//	int nrMediciVectoriConcatenati = 0;
//	struct Medic* listaMediciConcatenata = concateneazaVectori(&listaMediciNoua, &nrMediciNou, &listaMediciDupaSalarii, &nrMediciVectorSalarii, &nrMediciVectoriConcatenati);
//	afisareVector(&listaMediciConcatenata, &nrMediciVectoriConcatenati);
//
//	//dezalocare(&vladHoinaru);
//	dezalocare(&ionDatornic);
//	dezalocare(&m2);
//	dezalocare(&m3);
//	dezalocare(&m4);
//	dezalocare(&m5);
//	free(listaMedici);
//
//	//dezalocare task2
//	dezalocare(&listaMediciNoua[0]);
//	dezalocare(&listaMediciNoua[1]);
//	free(listaMediciNoua);
//	dezalocare(&listaMediciDupaSalarii[0]);
//	free(listaMediciDupaSalarii);
//
//	return 0;
//}