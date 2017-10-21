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
    ContTempo temFuncao;//Função
    ListaEncad *pontAux;//Ponteiro auxiliar para troca de elementos

    //pontAux = malloc(sizeof(ListaEncad));
    temFuncao.temIni = time(NULL);
    numCopias=0;
    numItera=0;

    for(i=0 ; i<lista->qtdElementos ; i++){

        numItera++;

        for(j=0 ; j<lista->qtdElementos ; j++){
            numItera++;

            if(vetorPont[j]->rg > vetorPont[i]->rg){
                numItera++;

                //Atribui valor para o auxiliar
                pontAux = vetorPont[i];
                numCopias++;

                //Troca valor de vetorPont[i]
                vetorPont[i] = vetorPont[j];
                numCopias++;

                //troca valor de vetorPont[j]
                vetorPont[j] = pontAux;
                numCopias++;

            }
        }

    }

    //Esse for serve para arrumas todas as referencias de todos os pontos do vetor
    for(i=0 ; i<lista->qtdElementos ; i++){
        numItera++;
        if(i == 0){
            numItera++;
            //Muda o primeiro elemento da lista
            lista->primeiro = vetorPont[i];
            numCopias++;

            vetorPont[i]->anterior = 0;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;
        }
        else if(i == lista->qtdElementos){
            numItera++;
            //Muda o ultimo elemento da lista
            lista->ultimo = vetorPont[i];
            numCopias++;

            vetorPont[i]->proximo = 0;

            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;
        }
        else{
            numItera++;
            //Altera os elemento do meio
            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;

        }

    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");


}

void bubbleSortEncad(ListaHeader *lista, ListaEncad **vetorPont){

    long int i, numAcoes = 1;
    ListaEncad *pontAux;

    while(numAcoes != 0){
        numAcoes = 0;

        for(i=0; i<lista->qtdElementos ; i++){

            if(i!=lista->qtdElementos-1 && vetorPont[i]->rg > vetorPont[i+1]->rg){
                numItera++;
                numAcoes++;

                //Atribui valor para o auxiliar
                pontAux = vetorPont[i];
                numCopias++;

                //Troca valor de vetorPont[i]
                vetorPont[i] = vetorPont[i+1];
                numCopias++;

                //troca valor de vetorPont[j]
                vetorPont[i+1] = pontAux;
                numCopias++;

            }
        }
    }

    //Esse for serve para arrumas todas as referencias de todos os pontos do vetor
    for(i=0 ; i<lista->qtdElementos ; i++){
        numItera++;
        if(i == 0){
            numItera++;
            //Muda o primeiro elemento da lista
            lista->primeiro = vetorPont[i];
            numCopias++;

            vetorPont[i]->anterior = 0;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;
        }
        else if(i == lista->qtdElementos){
            numItera++;
            //Muda o ultimo elemento da lista
            lista->ultimo = vetorPont[i];
            numCopias++;

            vetorPont[i]->proximo = 0;

            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;
        }
        else{
            numItera++;
            //Altera os elemento do meio
            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;

        }
    }

}
