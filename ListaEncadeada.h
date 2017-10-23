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
void imprimeEncad(ListaHeader *lista, ListaEncad **vetorPonteiros);
ListaEncad** addFinalEncad(ListaEncad **lisOper, ListaHeader *listaFim);
ListaEncad** addMeioEncad(ListaEncad **lisOperMeio, ListaHeader *listaMeio);
ListaEncad** addInicioEncad(ListaEncad **lisOperIni, ListaHeader *listaIni);
ListaEncad** removeEncad(ListaEncad **lisOperRemove, ListaHeader *listaRemove);
void pesquisaEncad(ListaHeader *lista);
void salvaEncad(ListaHeader *lista);
void mainListaEncadeada();

#endif // LISTAENCADEADA
