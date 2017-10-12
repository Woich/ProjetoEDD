#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"


void mainOrganizacao(ListaHeader *lista){
    int selcOrg;
    printf("Qual tipo de Organizacao?\n"
           "(1)Selection Sort\n"
           "(2)Algo Sort\n");
    scanf("%d", &selcOrg);

    switch(selcOrg){
        case 1: selctionSort(lista); break;
    }
}

void selctionSort(ListaHeader *lista){

    ListaEncad *valPosiAtual, *valAvaliado;
    int controle = 1, i;

    valPosiAtual = lista->primeiro;
    valAvaliado = lista->primeiro;

    while(controle != 0){

        controle = 0;

        for(i=0 ; i < lista->qtdElementos-1 ; i++){
            valAvaliado = valAvaliado->proximo;

            if(valAvaliado->rg < valPosiAtual->rg){
                trocaElementos(&valAvaliado, &valPosiAtual);
                controle++;
            }
        }


        valPosiAtual = valPosiAtual->proximo;

    }

}

void trocaElementos(ListaEncad *elemento1, ListaEncad *elemento2){

    ListaEncad *auxProximo, *auxAnterior;

    //Aloca memória
    auxProximo = malloc(sizeof(ListaEncad));
    auxAnterior = malloc(sizeof(ListaEncad));

    //Pega os valores do endereço de memória
    auxAnterior = elemento1->anterior;
    auxProximo = elemento1->proximo;

    //Altera referencias do elemento 1
    elemento1->anterior = 0;
    elemento1->anterior = elemento2->anterior;
    elemento1->proximo = 0;
    elemento1->proximo = elemento2->proximo;

    elemento2->proximo = 0;
    elemento2->proximo = elemento1;
    elemento2->anterior = 0;
    elemento2->anterior = elemento1;

    //Altera referencias do elemento 2
    elemento2->anterior = auxAnterior;
    elemento2->proximo = auxProximo;

    elemento2->anterior->proximo = 0;
    elemento2->anterior->proximo = elemento2;
    elemento2->proximo->anterior = 0;
    elemento2->proximo->anterior = elemento2;

}

