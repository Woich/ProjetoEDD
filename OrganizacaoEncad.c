#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"

void mainOrgEncad(ListaHeader *listaAvaliada){
    int opcSort;

    printf("Qual a opção de Troca de lemento que você deseja usar?"
           "(1)Selection Sort");

    scanf("%d", &opcSort);

    switch(opcSort){

    case 1: selecSort(listaAvaliada);

    }


}

void selecSort(ListaHeader *listaAval){

    ListaEncad *avaliado, *atual;
    int i, numAlte=1;

    avaliado = listaAval->primeiro;
    atual = listaAval->primeiro;

    while(numAlte != 0){

        for(i=0 ; i<listaAval->qtdElementos ; i++){
            atual = atual->proximo;

            if(atual->rg < avaliado->rg){
                trocaSimples(atual, avaliado);
                numAlte++;
            }
        }

        avaliado = avaliado->proximo;

    }


}

void trocaSimples(ListaEncad *elemento1, ListaEncad *elemento2){
    int rgAux, i;
    char nomeAux[30];

    rgAux = elemento1->rg;

    elemento1->rg = elemento2->rg;

    elemento2->rg = rgAux;


    for(i=0; i<30 ; i++){
        nomeAux[i] = elemento1->nome[i];
    }

    for(i=0; i<30 ; i++){
        elemento1->nome[i] = elemento2->nome[i];
    }

    for(i=0; i<30 ; i++){
        elemento2->nome[i] = nomeAux[i];
    }
}
