#ifndef LISTAENCADEADA
#define LISTAENCADEADA


typedef struct encad{
    char nome[30];
    int rg;
    struct encad *proximo,
                 *anterior;
}ListaEncad;

typedef struct head{
    struct encad *primeiro,
                 *ultimo;
    long int qtdElementos;
}ListaHeader;

typedef struct clock{
    float tempo;

    time_t temIni, temFinal;
}ContTempo;

int numItera, numCopias;

void preencheLista(ListaHeader *listaGerada, ListaEncad **vetorPonteiros, int opcArq);
void imprimeEncad(ListaHeader *lista);
void addFinalEncad(ListaHeader *lista, ListaEncad **vetorPonteiros);
void addMeioEncad(ListaHeader *lista, ListaEncad **vetorPonteiros);
void addInicioEncad(ListaHeader *lista, ListaEncad **vetorPonteiros);
void pesquisaEncad(ListaHeader *lista);
void removeEncad(ListaHeader *lista, ListaEncad **vetorPonteiros);
void salvaEncad(ListaHeader *lista);
void mainListaEncadeada();

#endif // LISTAENCADEADA
