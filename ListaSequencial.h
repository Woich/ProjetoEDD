#ifndef LISTASEQUENCIAL
#define LISTASEQUENCIAL

typedef struct listapessoa{
    char nome[30];
    int rg;
}ListaPessoa;


ListaPessoa** addFinal(ListaPessoa **lisOper, int fim);
ListaPessoa** addMeio(ListaPessoa **lisOperMeio, int fimMeio);
ListaPessoa** addIni(ListaPessoa **lisOperIni, int fimIni);
ListaPessoa** removeItem(ListaPessoa **lisOperRemove, int fimRemove);
void imprimeLista(long int fim, ListaPessoa **vetorPonteiros);
void procuraRG(ListaPessoa **pessoas, int tamList);
void salvaLista(ListaPessoa **pessoas, int arquivo, int tamList);
void mainSequencial();

#endif // LISTASEQUENCIAL
