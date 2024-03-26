#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>

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
    Nod* prev;
};

typedef struct listaDubla listaDubla;
struct listaDubla {
    Nod* head;
    Nod* tail;
};

Biblioteca initializare(const char* nume, int nrCarti, int nrCititori) {
    Biblioteca b;
    b.nume = (char*)malloc(sizeof(char) * (strlen(nume) + 1));
    strcpy(b.nume, nume);
    b.nrCarti = nrCarti;
    b.nrCititori = nrCititori;
    return b;
}

void inserareLaInceput(listaDubla* lista, Biblioteca b) {
    Nod* nodNou = (Nod*)malloc(sizeof(Nod));
    nodNou->info = b;
    nodNou->prev = NULL;
    nodNou->next = lista->head;

    if (lista->head) {
        lista->head->prev = nodNou;
    }
    else {
        lista->tail = nodNou;
    }
    lista->head = nodNou;
}

void afisareListaDeLaInceput(listaDubla lista) {
    while (lista.head) {
        printf("Biblioteca : %s cu %d carti si %d cititori\n", lista.head->info.nume, lista.head->info.nrCarti, lista.head->info.nrCititori);
        lista.head = lista.head->next;
    }
    printf("\n");
    
}

void stergereNodDupaNume(listaDubla* lista, const char* nume) {

    Nod* aux = lista->head;

    while (aux && strcmp(nume, aux->info.nume)!=0) {
        aux = aux->next;
    }
    if (aux)
    {
        if (aux == lista->head)
        {
            if (aux == lista->tail)
            {
                lista->head = NULL;
                lista->tail = NULL;
            }
            else 
            {
                lista->head = lista->head->next;
                lista->head->prev = NULL;
            }
        }
        else
        {
            if (aux == lista->tail)
            {
                lista->tail->prev->next = NULL;
                lista->tail = lista->tail->prev;
            }
            else
            {
                aux->next->prev = aux->prev;
                aux->prev->next = aux->next;
            }
        }
        free(aux->info.nume);
        free(aux);

    }
}

void stergereLista(listaDubla* lista) {

    while (lista->head) {
        free(lista->head->info.nume);
        Nod* aux = lista->head;
        lista->head = lista->head->next;
        free(aux);
    }
    lista->head = NULL;
    lista->tail = NULL;
}

int nrCartiTotal(listaDubla lista) {
    int rez = 0;

    while (lista.tail)
    {
        rez = rez + lista.tail->info.nrCarti;
        lista.tail = lista.tail->prev;
    }

    return rez;
}




void main() {
    Biblioteca b1 = initializare("Mihai Eminescu", 150, 30);
    Biblioteca b2 = initializare("Ioan Slavici", 200, 30);
    Biblioteca b3 = initializare("Tudor Arghezi", 100, 15);

    listaDubla listaDubla;
    listaDubla.head = NULL;
    listaDubla.tail = NULL;

    inserareLaInceput(&listaDubla, b1);
    inserareLaInceput(&listaDubla, b2);
    inserareLaInceput(&listaDubla, b3);

    afisareListaDeLaInceput(listaDubla);

    //stergereNodDupaNume(&listaDubla, "Ioan Slavici");
    //afisareListaDeLaInceput(listaDubla);
    //stergereNodDupaNume(&listaDubla, "Mihai Eminescu");
    //afisareListaDeLaInceput(listaDubla);
    //stergereNodDupaNume(&listaDubla, "Tudor Arghezi");
    //afisareListaDeLaInceput(listaDubla);

    printf("%d", nrCartiTotal(listaDubla));

    stergereLista(&listaDubla);
    afisareListaDeLaInceput(listaDubla);



}