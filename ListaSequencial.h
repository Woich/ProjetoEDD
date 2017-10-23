#ifndef LISTASEQUENCIAL
#define LISTASEQUENCIAL

typedef struct listapessoa{
    char nome[30];
    int rg;
}ListaPessoa;


void addFinal(ListaPessoa *lisOper, int fim);
void addMeio(ListaPessoa *lisOper, int fim);
void addIni(ListaPessoa *lisOper, int fim);
void removeItem(ListaPessoa *lisOper, int fim);
void imprimeLista(ListaPessoa **pessoas, int tamList);
void procuraRG(ListaPessoa *pessoas, int tamList);
void salvaLista(ListaPessoa *pessoas, int arquivo, int tamList);
void mainSequencial();

#endif // LISTASEQUENCIAL
