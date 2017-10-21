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

    long int i, numAcoes = 1;// Controladores para o loops
    ListaEncad *pontAux;//Ponteiro Auxiliar
    ContTempo temFuncao;//Tempo da Função

    temFuncao.temIni = time(NULL);
    numCopias=0;
    numItera=0;

    while(numAcoes != 0){
        numAcoes = 0;

        for(i=0; i<lista->qtdElementos ; i++){
            numItera++;

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

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

}

void insertionSortEncad(ListaHeader *lista, ListaEncad **vetorPont){
    long int i, j;//Controladores de loops
    ContTempo temFuncao;//Tempo da Função
    ListaEncad *pontAux;//Ponteiro Auxiliar

    temFuncao.temIni = time(NULL);
    numCopias=0;
    numItera=0;

    for(i=2 ; i<lista->qtdElementos ; i++){//'i' é o que secsiona os pedaços que serão avaliados
        for(j=0 ; j<i ; j++){//'j' é quem corre o vetor sendo limitado por 'i'
            if(vetorPont[i]->rg < vetorPont[j]->rg){
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

void quickSortEncad(ListaHeader *lista, ListaEncad **vetorPont, long int iniComp, long int fimComp){//Esse possui inicio e fim do vetor para limitadores
    long int i=iniComp, j=fimComp, pivo;//'i' e 'j' são controladores de loops, enquanto o pivo é uma medida para a organização
    ListaEncad *pontAux;//Ponteiro Auxiliar

    if(j - i > 1){
        pivo = (vetorPont[i]->rg + vetorPont[j-1]->rg)/2;

        while(i < j){

            //Rodando o i
            while(vetorPont[i]->rg < pivo){
                i++;
                numItera++;
            }
            //Rodando o j
            while(vetorPont[j-1]->rg > pivo){
                j--;
                numItera++;
            }
            if(i<=j){
                numItera++;

                //Atribui valor para o auxiliar
                pontAux = vetorPont[i];
                numCopias++;

                //Troca valor de vetorPont[i]
                vetorPont[i] = vetorPont[j-1];
                numCopias++;

                //troca valor de vetorPont[j]
                vetorPont[j-1] = pontAux;
                numCopias++;
            }

        }
        //Secção baseada no 'j'
        if(j > iniComp){
            quickSortEncad(lista, vetorPont, iniComp, j);
        }
        //Secção baseada no 'i'
        if(i< fimComp){
            quickSortEncad(lista, vetorPont, i, fimComp);
        }

    }
}
