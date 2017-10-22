#ifndef ORGANIZACAOENCAD
#define ORGANIZACAOENCAD

void selecSortEncad(ListaHeader *lista, ListaEncad **vetorPont);
void bubbleSortEncad(ListaHeader *lista, ListaEncad **vetorPont);
void insertionSortEncad(ListaHeader *lista, ListaEncad **vetorPont);
void quickSortEncad(ListaHeader *lista, ListaEncad **vetorPont, long int iniComp, long int fimComp);
void mergeSortEncad(ListaHeader *lista, ListaEncad **vetorPont, long int iniComp, long int fimComp);
void shellSortEncad(ListaHeader *lista, ListaEncad **vetorPont, long int iniComp, long int fimComp);

#endif // ORGANIZACAOENCAD
