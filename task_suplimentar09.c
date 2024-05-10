//arbore = graf conex cu n-1 muchii
//arbore binar = fiecare nod are cel mult 2 fii


//arbore binar de cautare = inf din radacina trb sa fie mai mare decat fiu stanga si mai mica decat fiu dreapta
//          5

//       3     8

//       1   6  10


//fiecare nod trebuie sa contina informatia utila si fii

//putem citi un arbore in 3 moduri 
//radacina stanga dreapta = preordine (radacina e in fata)
//stanga dreapta radacina = postordine (radacina e la final)
//stanga radacina dreapta = inordine (radacina e la mijloc)

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Rezervare Rezervare;
struct Rezervare {
    int id;
    char* numeClient;
    int nrPersoane;
};

typedef struct Nod Nod;
struct Nod {
    Nod* stanga;
    Nod* dreapta;
    Rezervare info;
};


void citireRezervare(FILE* f, Rezervare* rez) {
    fscanf(f, "%d", (&rez->id));

    char aux[30];
    fscanf(f, "%s", &aux);
    rez->numeClient = (char*)malloc(sizeof(char) * strlen(aux) + 1);
    strcpy(rez->numeClient, aux);

    fscanf(f, "%d", (&rez->nrPersoane));
}

Nod* inserareArbore(Nod* arbore, Rezervare rez) {

    if (arbore != NULL) {
        if (arbore->info.id < rez.id) {
            arbore->dreapta = inserareArbore(arbore->dreapta, rez); //aici imi returneaza alta radacina pe care o punem in fiul din dreapta
        }
        else
        {
            arbore->stanga = inserareArbore(arbore->stanga, rez);
        }
    }
    else
    {
        Nod* temp = (Nod*)malloc(sizeof(Nod));
        temp->info = rez; //shallow copy
        temp->dreapta = NULL;
        temp->stanga = NULL;

        arbore = temp;
    }

    return arbore;
}

void citireFisier(const char* numeFisier, Nod** nodRadacina) {
    FILE* f = fopen(numeFisier, "r");

    int nrRezervari = 0;
    fscanf(f, "%d", &nrRezervari);



    for (int i = 0; i < nrRezervari; i++) {
        Rezervare rez;
        citireRezervare(f, &rez);

        *nodRadacina = inserareArbore(*nodRadacina, rez);
    }

}

void afisareRezervare(Rezervare r) {
    if (r.numeClient) {
        printf("Rezervarea %d facuta de %s are %d persoane.\n", r.id, r.numeClient, r.nrPersoane);
    }
}

//putem citi un arbore in 3 moduri 
//radacina stanga dreapta = preordine (radacina e in fata)
//stanga dreapta radacina = postordine (radacina e la final)
//stanga radacina dreapta = inordine (radacina e la mijloc)
void afisareArborePreOrdine(Nod* arbore) {
    if (arbore != NULL) //mereu verficam daca avem arbore
    {
        afisareRezervare(arbore->info);
        afisareArborePreOrdine(arbore->stanga);
        afisareArborePreOrdine(arbore->dreapta);
    }
}


void afisareArboreInOrdine(Nod* arbore) { //sorteaza elementele in ordine crescatare = sortarea binara
    if (arbore != NULL) {
        afisareArboreInOrdine(arbore->stanga);
        afisareRezervare(arbore->info);
        afisareArboreInOrdine(arbore->dreapta);
    }
}

void afisareArboreInPostOrdine(Nod* arbore) {
    if (arbore != NULL) {
        afisareArboreInPostOrdine(arbore->stanga);
        afisareArboreInPostOrdine(arbore->dreapta);
        afisareRezervare(arbore->info);
    }
}


//functie care cauta un nod(adica o rez) dupa id
Rezervare cautareDupaId(Nod* radacina, int id)
{
    if (radacina != NULL) {
        if (radacina->info.id < id)
            return cautareDupaId(radacina->dreapta, id);
        else
            if (radacina->info.id > id)
                return cautareDupaId(radacina->stanga, id);
            else
                return radacina->info; //in acest caz sunt egale
    }
    else
    {
        Rezervare r;
        r.id = -1;
        r.numeClient = NULL;
        r.nrPersoane = -1;

        return r;
    }
}

//suma tuturor pers -> facem suma stanga + suma dreapta + nr de pers din radacina
int calculNrTotalPersoane(Nod* rad) {
    if (rad) {
        int rPersoane = rad->info.nrPersoane; //nr de pers din radacina
        int sPersonae = calculNrTotalPersoane(rad->stanga); //nr de pers stanga
        int dPersonae = calculNrTotalPersoane(rad->dreapta);

        return rPersoane + sPersonae + dPersonae;
    }
    else {
        return 0;
    }
}

Nod* cautareNodMinim(Nod* n) {
    Nod* aux = n;
    while (aux->stanga != NULL) {
        aux = aux->stanga;
    }
    return aux;
}

//stergere nod dupa ID
void stergereNodDupaId(Nod** r, int id) {
    Nod* aux = *r;

    Nod* parent = NULL;

    //cautare nod
    while (aux != NULL && aux->info.id != id) {
        parent = aux;
        if (aux->info.id > id) {
            aux = aux->stanga;
        }
        else {
            aux = aux->dreapta;
        }
    }

    //daca e gasit
    if (aux->info.id == id) {
        //caz 1 - nod nu are copii
        if (aux->dreapta == NULL && aux->stanga == NULL) {
            if (parent == NULL) {
                free(aux->info.numeClient);
                free(aux);
                *r = NULL;
            }
            else if (parent->stanga == aux) {
                // If the node to be deleted is the left child of its parent
                free(aux->info.numeClient);
                free(aux);
                parent->stanga = NULL;
            }
            else {
                // If the node to be deleted is the right child of its parent
                free(aux->info.numeClient);
                free(aux);
                parent->dreapta = NULL;
            }
        }
        //caz 2 - nod are doar copil stanga
        else if (aux->dreapta == NULL) {
            if (parent == NULL) {
                // If the node to be deleted is the root
                *r = aux->stanga;
            }
            else if (parent->stanga == aux) {
                // If the node to be deleted is the left child of its parent
                parent->stanga = aux->stanga;
            }
            else {
                // If the node to be deleted is the right child of its parent
                parent->dreapta = aux->stanga;
            }
            free(aux->info.numeClient);
            free(aux);
        }       
        //caz 3 - nod are doar copil dreapta
        else if (aux->stanga == NULL) {
            if (parent == NULL) {
                // If the node to be deleted is the root
                *r = aux->dreapta;
            }
            else if (parent->stanga == aux) {
                // If the node to be deleted is the left child of its parent
                parent->stanga = aux->dreapta;
            }
            else {
                // If the node to be deleted is the right child of its parent
                parent->dreapta = aux->dreapta;
            }
            free(aux->info.numeClient);
            free(aux);
        }
        //caz 4 - nod are ambii copii
        else  {
            Nod* temp = cautareNodMinim(aux->dreapta);
            aux->info.id = temp->info.id;
            free(aux->info.numeClient);
            aux->info.numeClient = malloc(strlen(temp->info.numeClient) + 1);
            strcpy(aux->info.numeClient, temp->info.numeClient);
            aux->info.nrPersoane = temp->info.nrPersoane;
            stergereNodDupaId(&aux->dreapta, temp->info.id);
        }
    }
    //daca nu e gasit
    else {
        printf("\Nodul nu a fost gasit\n");
    }
}

int calculInaltime(Nod* nod) {
    if (nod == NULL) {
        return 0;
    }
    else {
        int inaltimeStanga = calculInaltime(nod->stanga);
        int inaltimeDreapta = calculInaltime(nod->dreapta);

        return 1 + (inaltimeStanga > inaltimeDreapta ? inaltimeStanga : inaltimeDreapta);
    }
}

Nod* cautareRadacinaArboreMaiInalt(Nod* rad) {
    if (rad == NULL) {
        return NULL;
    }

    int inaltimeStanga = calculInaltime(rad->stanga);
    int inaltimeDreapta = calculInaltime(rad->dreapta);

    if (inaltimeStanga > inaltimeDreapta) {
        return rad->stanga;
    }
    else if (inaltimeStanga < inaltimeDreapta) {
        return rad->dreapta;
    }
    else {
        return NULL;
    }

}

int numarNoduriSubarbore(Nod* radacina) {
    if (radacina == NULL) {
        return 0; // Dacă radacina este NULL, subarborele nu conține niciun nod
    }
    else {
        // Numărăm nodul curent și apoi numărăm nodurile din subarborii stâng și drept
        return 1 + numarNoduriSubarbore(radacina->stanga) + numarNoduriSubarbore(radacina->dreapta);
    }
}

Nod* cautareSubarboreCuMaiMulteNoduri(Nod* radacina) {
    int noduriStanga = numarNoduriSubarbore(radacina->stanga);
    int noduriDreapta = numarNoduriSubarbore(radacina->dreapta);

    if (noduriStanga > noduriDreapta) {
        return radacina->stanga;
    }
    else if (noduriDreapta > noduriStanga) {
        return radacina->dreapta;
    }
    else {
        return NULL;
    }
}

void main() {
    Nod* radacina = NULL;

    citireFisier("rezervari.txt", &radacina);

    printf("\n----preordine----\n");
    afisareArborePreOrdine(radacina);
    printf("\n----inordine----\n");
    afisareArboreInOrdine(radacina);
    printf("\n----postordine----\n");
    afisareArboreInPostOrdine(radacina);


    printf("\n---------------------------------\n");
    afisareRezervare(cautareDupaId(radacina, 4));

    printf("\n---------------------------------\nNr total de pers: %d", calculNrTotalPersoane(radacina));

    printf("\n----------Stergere nod cu id 6-----------------------\n");
    stergereNodDupaId(&radacina, 6);
    printf("\n----preordine----\n");
    afisareArborePreOrdine(radacina);
    printf("\n----------Stergere nod cu id 10-----------------------\n");
    stergereNodDupaId(&radacina, 10);
    printf("\n----preordine----\n");
    afisareArborePreOrdine(radacina);
    printf("\n----------Stergere nod cu id 8-----------------------\n");
    stergereNodDupaId(&radacina, 8);
    printf("\n----preordine----\n");
    afisareArborePreOrdine(radacina);


    printf("\n----cautare radacina a subarborelui mai inalt----\n");
    
    afisareRezervare(cautareRadacinaArboreMaiInalt(radacina)->info);

    printf("\n----functie numar de noduri aflate in subordinea radacinii----\n");
    printf("%d\n", numarNoduriSubarbore(radacina));

    printf("\n----functie numar de noduri aflate in subordinea copilului din stanga al radacinii----\n");
    printf("%d\n", numarNoduriSubarbore(radacina->stanga));

    printf("\n----functie returnare radacina pentru suboarbore cu mai multe noduri aflate in subordine----\n");
    afisareRezervare(cautareSubarboreCuMaiMulteNoduri(radacina)->info);



}