#include<stdio.h>
#include<malloc.h>

typedef struct Biblioteca Biblioteca;
typedef struct Nod Nod;

struct Biblioteca {
    char* nume;
    int nrCarti;
    int nrCititori;
};

struct Nod {
    Biblioteca info;
    Nod* next;
};

Biblioteca init(const char* nume, int nrCarti, int nrCititori) {
    Biblioteca b;

    b.nume = malloc(sizeof(char) * (1 + strlen(nume)));
    strcpy(b.nume, nume);
    b.nrCarti = nrCarti;
    b.nrCititori = nrCititori;

    return b;
}

Nod* inserareInceput(Nod* cap, Biblioteca b) {
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));

    nodNou->info = init(b.nume, b.nrCarti, b.nrCititori);
    nodNou->next = cap;

    return nodNou;

}

void inserareSfarsit(Nod** cap, Biblioteca b) {
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    nodNou->info = init(b.nume, b.nrCarti, b.nrCititori);
    nodNou->next = NULL;
    if (*cap) {
        Nod* nod_aux = *cap;
        while (nod_aux->next) {
            nod_aux = nod_aux->next;
        }
        nod_aux->next = nodNou;
    }
    else {
        (*cap) = nodNou;
    }
}

void afisareLista(Nod* cap) {
    while (cap) {
        printf("Biblioteca %s are %d carti si %d cititori.\n", cap->info.nume, cap->info.nrCarti, cap->info.nrCititori);
        cap = cap->next;
    }
}

char* getBibliotecaMaxCartiPerCititori(Nod* cap) {
    float max = 0;
    char* nume_aux = NULL;
    while (cap) {
        if (cap->info.nrCarti / cap->info.nrCititori > max) {
            max = cap->info.nrCarti / cap->info.nrCititori;
            nume_aux = cap->info.nume;
        }
        cap = cap->next;
    }

    char* nume = (char*)malloc(sizeof(char) * (1 + strlen(nume_aux)));
    strcpy(nume, nume_aux);
    return nume;
}

void stergeLista(Nod** cap) {
    while (*cap) {
        free((*cap)->info.nume);
        Nod* copie = *cap;
        *cap = (*cap)->next;
        free(copie);
    }
}


void main() {
    Nod* cap = NULL;
    Biblioteca b1 = init("Hasdeu", 1000, 20);
    cap = inserareInceput(cap, b1);
    Biblioteca b2 = init("Alba-Iulia", 200, 30);
    cap = inserareInceput(cap, b2);
    Biblioteca b3 = init("Targoviste", 300, 200);
    cap = inserareInceput(cap, b3);

    
    
  
    afisareLista(cap);
    printf("Biblioteca este: %s\n", getBibliotecaMaxCartiPerCititori(cap));


    printf("\n\n");
    Biblioteca b4 = init("Durlesti", 5000, 10);
    inserareSfarsit(&cap, b4);

    afisareLista(cap);
    printf("Biblioteca este: %s\n", getBibliotecaMaxCartiPerCititori(cap));


    stergeLista(&cap);
    afisareLista(cap);
}