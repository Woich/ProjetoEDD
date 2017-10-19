#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"
#include "Teste.h"

void preencheVetorPonteiros(ListaHeader *listaGerada, ListaEncad *vetorPonteiros){

    FILE *file = fopen("NomeRG10.txt", "r");
    char linInicial[30],*linTemp, *strPart;
    char delimit[]=" .,;:";
    ListaEncad *registro;

    //Le a primeira linha do arquivo
    fgets(linInicial, 30, file);

    while(linInicial[0] != '\0'){
        if(listaGerada->qtdElementos == 0){
            listaGerada->qtdElementos++;

            //Aloca a memória necessária
            registro = malloc(sizeof(ListaEncad));
            //vetorPonteiros = malloc(sizeof(ListaEncad));

            //Arruma posição
            listaGerada->primeiro = registro;
            listaGerada->ultimo = registro;
            vetorPonteiros[0] = *registro;

            //Arruma referencias
            registro->anterior = NULL;
            registro->proximo = NULL;

            //Atribui vetor a um ponteiro
            linTemp = linInicial;

            //Separa a String, pega o nome
            strPart = strsep(&linTemp, delimit);
            strcpy(registro->nome, strPart);

            //Separa a String, pega o rg
            strPart = strsep(&linTemp, delimit);
            registro->rg = atoi(strPart);
        }
        else{
            //Realoca memória
            vetorPonteiros = realloc(vetorPonteiros, (listaGerada->qtdElementos+1)*sizeof(ListaEncad));

            //Aloca memória para novo registro
            registro = malloc(sizeof(ListaEncad));

            //Aumenta número de elementos da lista
            listaGerada->qtdElementos++;

            //Altera refencia anterior
            listaGerada->ultimo->proximo = registro;

            //Altera o ultimo elemento da lista
            listaGerada->ultimo = registro;

            //Atribui vetor a um ponteiro
            linTemp = linInicial;

            //Separa a String, pega o nome
            strPart = strsep(&linTemp, delimit);
            strcpy(registro->nome, strPart);

            //Separa a String, pega o rg
            strPart = strsep(&linTemp, delimit);
            registro->rg = atoi(strPart);

            //Adiciona elemento na lista
            vetorPonteiros[listaGerada->qtdElementos-1] = *registro;
        }

        linInicial[0] = '\0';
        fgets(linInicial, 30, file);
    }

    fclose(file);
    printf("\n Função Finalizada\n\n");
}
