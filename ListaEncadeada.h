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
    int qtdElementos;
}ListaHeader;

typedef struct clock{
    float tempo;

    time_t temIni, temFinal;
}ContTempo;

int numItera, numCopias;

void preencheLista(ListaHeader *lista);
void imprimeEncad(ListaHeader *lista);
void addFinalEncad(ListaHeader *lista);
void addMeioEncad(ListaHeader *lista);
void addInicioEncad(ListaHeader *lista);
void pesquisaEncad(ListaHeader *lista);
void removeEncad(ListaHeader *lista);
void salvaEncad(ListaHeader *lista);
void mainListaEncadeada();

#endif // LISTAENCADEADA
