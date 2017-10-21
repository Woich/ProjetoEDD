#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"

void selecSortEncad(ListaHeader *lista, ListaEncad **vetorPont){
    long int i, j;//contadores para o 'for'

    ListaEncad *pontAux;//Ponteiro auxiliar para troca de elementos

    //pontAux = malloc(sizeof(ListaEncad));

    numCopias=0;
    numItera=0;

    for(i=0 ; i<lista->qtdElementos ; i++){

        for(j=0 ; j<lista->qtdElementos ; j++){

            if(vetorPont[j]->rg > vetorPont[i]->rg){
                //Atribui valor para o auxiliar
                pontAux = vetorPont[i];

                //Troca valor de vetorPont[i]
                vetorPont[i] = vetorPont[j];

                //troca valor de vetorPont[j]
                vetorPont[j] = pontAux;

            }
        }

    }

    //Esse for serve para arrumas todas as referencias de todos os pontos do vetor
    for(i=0 ; i<lista->qtdElementos ; i++){

        if(i == 0){
            //Muda o primeiro elemento da lista
            lista->primeiro = vetorPont[i];

            vetorPont[i]->anterior = 0;

            vetorPont[i]->proximo = vetorPont[i+1];
        }
        else if(i == lista->qtdElementos){
            //Muda o ultimo elemento da lista
            lista->ultimo = vetorPont[i];

            vetorPont[i]->proximo = 0;

            vetorPont[i]->anterior = vetorPont[i-1];
        }
        else{
            //Altera os elemento do meio
            vetorPont[i]->anterior = vetorPont[i-1];

            vetorPont[i]->proximo = vetorPont[i+1];

        }

    }


}
