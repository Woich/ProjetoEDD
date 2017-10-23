#ifndef ORGANIZACAO
#define ORGANIZACAO

void selecSortSquencial(ListaHeader *lista, ListaPessoa **vetorPont);
void bubbleSortSquencial(ListaHeader *lista, ListaPessoa **vetorPont);
void insertionSortSquencial(ListaHeader *lista, ListaPessoa **vetorPont);
void quickSortSquencial(ListaPessoa **vetorPont, long int iniComp, long int fimComp);
void mergeSortSquencial(ListaHeader *lista, ListaPessoa **vetorPont, long int iniComp, long int fimComp);
void shellSortSquencial(ListaHeader *lista, ListaPessoa **vetorPont);
void pesquisaBinariaSquencial(ListaHeader *lista, ListaPessoa **vetorPont);

#endif // ORGANIZACAO
