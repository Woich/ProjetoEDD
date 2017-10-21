#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"
#include "Teste.h"

void preencheVetorPonteiros(ListaHeader *listaGerada, ListaEncad **vetorPonteiros){

    FILE *file = fopen("NomeRG10.txt", "r");
    char linInicial[30],*linTemp, *strPart;
    char delimit[]=" .,;:";
    ListaEncad *registro;
    int i;

    //vetorPonteiros = malloc(10 * sizeof(ListaEncad));

    //Le a primeira linha do arquivo
    fgets(linInicial, 30, file);

    for(i=0; i<10 ; i++){
        if(listaGerada->qtdElementos == 0){
            //Aloca Memoria
            vetorPonteiros[0] = malloc(sizeof(ListaEncad));
            registro = malloc(sizeof(ListaEncad));

            //passa as infromações para registro
            /*Atribui vetor a um ponteiro*/
            linTemp = linInicial;

            /*Separa a String, pega o nome*/
            strPart = strsep(&linTemp, delimit);
            strcpy(registro->nome, strPart);

            /*Separa a String, pega o rg*/
            strPart = strsep(&linTemp, delimit);
            registro->rg = atoi(strPart);

            //Arruma referencias
            registro->anterior = 0;
            registro->proximo = 0;

            //Arruma a lista
            listaGerada->qtdElementos = listaGerada->qtdElementos+1;
            listaGerada->primeiro = registro;
            listaGerada->ultimo = registro;

            //Adiciona no vetor de ponteiros;
            vetorPonteiros[0] = registro;

            printf("Nome:%s \n RG:%d", vetorPonteiros[0]->nome,vetorPonteiros[0]->rg);
        }
        else{
            //Aloca Memoria
            vetorPonteiros[i] = malloc(sizeof(ListaEncad));
            registro = malloc(sizeof(ListaEncad));

            //passa as infromações para registro
            /*Atribui vetor a um ponteiro*/
            linTemp = linInicial;

            /*Separa a String, pega o nome*/
            strPart = strsep(&linTemp, delimit);
            strcpy(registro->nome, strPart);

            /*Separa a String, pega o rg*/
            strPart = strsep(&linTemp, delimit);
            registro->rg = atoi(strPart);

            //Arruma referencias
            listaGerada->ultimo->proximo = registro;
            registro->anterior = listaGerada->ultimo;
            registro->proximo = 0;

            //Arruma a lista
            listaGerada->qtdElementos = listaGerada->qtdElementos+1;
            listaGerada->ultimo = registro;

            //Adiciona no vetor de ponteiros;
            vetorPonteiros[i] = registro;

            printf("Nome:%s ||| RG:%d", vetorPonteiros[0]->nome,vetorPonteiros[0]->rg);
        }

        linInicial[0] = '\0';
        fgets(linInicial, 30, file);

    }



    fclose(file);
    printf("\n Função Finalizada\n\n");
}
