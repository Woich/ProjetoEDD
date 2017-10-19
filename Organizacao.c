#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"


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

            printf("%s, %d", valPosiAtual->nome, valPosiAtual->rg);
            printf("%s, %d", lista->primeiro->nome, lista->primeiro->rg);
            if(valAvaliado->rg < valPosiAtual->rg){
                //trocaElementos(valPosiAtual, valAvaliado, lista);
                trocaElementosSimples(valPosiAtual, valAvaliado);
                controle++;
            }

            /*valPosiAtual = lista->primeiro;
            for(contPosi = 0; contPosi<0; contPosi--){
                valPosiAtual = valPosiAtual->proximo;
            }*/
        }


        valPosiAtual = valPosiAtual->proximo;
        //posiAtual++;

    }

}

void trocaElementos(ListaEncad *elemento1, ListaEncad *elemento2, ListaHeader *listaAtual){

    ListaEncad *auxProximo, *auxAnterior;

    if(elemento1->rg == listaAtual->primeiro->rg){
        //Aloca memória
        auxProximo = malloc(sizeof(ListaEncad));
        auxAnterior = malloc(sizeof(ListaEncad));

        //Pega os valores do endereço de memória
        auxProximo = elemento1->proximo;

        //Altera referencias do elemento 1
        elemento1->anterior = elemento2->anterior;
        elemento1->proximo = elemento2->proximo;

        elemento2->proximo->anterior = elemento1;
        elemento2->anterior->proximo = elemento1;

        //Altera referencias do elemento 2
        elemento2->anterior = NULL;
        elemento2->proximo = auxProximo;

        elemento2->proximo->anterior = elemento2;

        //Altera a lista
        listaAtual->primeiro = elemento2;


    }

    else if(elemento1->rg == listaAtual->ultimo->rg){

        //Aloca memória
        auxProximo = malloc(sizeof(ListaEncad));
        auxAnterior = malloc(sizeof(ListaEncad));

        //Pega os valores do endereço de memória
        auxAnterior = elemento1->anterior;

        //Altera referencias do elemento 1
        elemento1->anterior = elemento2->anterior;
        elemento1->proximo = elemento2->proximo;

        elemento2->proximo = 0;
        elemento2->proximo = elemento1;
        elemento2->anterior = 0;
        elemento2->anterior = elemento1;

        //Altera referencias do elemento 2
        elemento2->anterior = auxAnterior;
        elemento2->proximo = NULL;

        elemento2->anterior->proximo = elemento2;

        //Altera a lista
        listaAtual->ultimo = elemento2;

    }

    else{
        //Aloca memória
        auxProximo = malloc(sizeof(ListaEncad));
        auxAnterior = malloc(sizeof(ListaEncad));

        //Pega os valores do endereço de memória
        auxAnterior = elemento1->anterior;
        auxProximo = elemento1->proximo;

        //Altera referencias do elemento 1
        elemento1->anterior = elemento2->anterior;
        elemento1->proximo = elemento2->proximo;

        elemento2->proximo = elemento1;
        elemento2->anterior = elemento1;

        //Altera referencias do elemento 2
        elemento2->anterior = auxAnterior;
        elemento2->proximo = auxProximo;

        elemento2->anterior->proximo = elemento2;
        elemento2->proximo->anterior = elemento2;
        }

    free(auxAnterior);
    free(auxProximo);

}

void trocaElementosSimples(ListaEncad *elemento1, ListaEncad *elemento2){

    int rgAux, i;
    char nomeAux[30];

    for(i=0; i<30; i++){
        nomeAux[i] = elemento1->nome[i];
    }

    rgAux = elemento1->rg;

    //Altera elemento 1
    elemento1->rg = elemento2->rg;
    for(i=0; i<30; i++){
        elemento1->nome[i] = elemento2->nome[i];
    }

    //Altera elemento 2
    elemento2->rg = rgAux;
    for(i=0; i<30; i++){
        elemento2->nome[i] = nomeAux[i];
    }

    free(nomeAux);

}

