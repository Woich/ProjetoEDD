#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"
#include "Teste.h"


void preencheLista(ListaHeader *lista){

    FILE *file = fopen("NomeRG10.txt", "r");
    char linInicial[30],*linTemp, *strPart;
    char delimit[]=" .,;:";
    ListaEncad *registro;
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);
    /*Le primeira linha do arquivo*/
    fgets(linInicial, 30, file);

     while(linInicial[0] != '\0'){
        numItera++;

        if(lista->qtdElementos == 0){
            numItera++;

            /* Aloca a Memória necessária */
            registro = malloc(sizeof(ListaEncad));

            /*Atribui vetor a um ponteiro*/
            linTemp = linInicial;

            /*Separa a String, pega o nome*/
            strPart = strsep(&linTemp, delimit);
            strcpy(registro->nome, strPart);

            /*Separa a String, pega o rg*/
            strPart = strsep(&linTemp, delimit);
            registro->rg = atoi(strPart);

            /*Altera a quantidade de elementos*/
            lista->qtdElementos = lista->qtdElementos+1;

            /*Altera os ponteriros de Proximo e Anterior para nulo*/
            registro->proximo = NULL;
            registro->anterior = NULL;

            /*Altera os ponteriros de Primeiro e Ultimo elementos para o registro, por ele ser o único existente*/
            lista->primeiro = registro;
            lista->ultimo = registro;

        }
        else{
            numItera++;

            /* Aloca a Memória necessária */
            registro = malloc(sizeof(ListaEncad));

            /*Atribui vetor a um ponteiro*/
            linTemp = linInicial;

            /*Separa a String, pega o nome*/
            strPart = strsep(&linTemp, delimit);
            strcpy(registro->nome, strPart);

            /*Separa a String, pega o rg*/
            strPart = strsep(&linTemp, delimit);
            registro->rg = atoi(strPart);

            /*Altera a quantidade de elementos*/
            lista->qtdElementos = lista->qtdElementos+1;

            /*Pega o anterior, altera o anterior para ele ter esse como próximo*/
            registro->anterior = lista->ultimo;
            registro->anterior->proximo = registro;

            /*Altera o ponteiro para o ultimo valor*/
            lista->ultimo = registro;

        }
        /*Pega próxima linha do arquivo*/
        linInicial[0] = '\0';
        fgets(linInicial, 30, file);
    }

    fclose(file);
    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);


}

void imprimeEncad(ListaHeader *lista){

    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);
    /*Valor a ser impresso*/
    ListaEncad *imprimir;
    /*Contador para impressão*/
    int i;

    imprimir = lista->primeiro;

    for(i=0 ; i<lista->qtdElementos ; i++){
        numItera++;

        /*Imprime registro em questão*/
        printf("%i: %s,%i \n", i+1, imprimir->nome, imprimir->rg);
        /*Altera o registro para o próximo*/
        imprimir = imprimir->proximo;
    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);

}

void addFinalEncad(ListaHeader *lista){
    char nome[30];
    int rg;

    ListaEncad *registro;
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    printf("\nQual o Nome?\n");
    scanf("%s", nome);
    getchar();
    printf("\nQual o RG?\n");
    scanf("%i", &rg);
    getchar();


    /* Aloca a Memória necessária */
    registro = malloc(sizeof(ListaEncad));

    /*Separa a String, pega o nome*/
    strcpy(registro->nome, nome);
    numCopias++;

    /*Separa a String, pega o rg*/
    registro->rg = rg;
    numCopias++;

    /*Altera a quantidade de elementos*/
    lista->qtdElementos = lista->qtdElementos+1;

    /*Pega o anterior, altera o anterior para ele ter esse como próximo*/
    registro->anterior = lista->ultimo;
    registro->anterior->proximo = registro;

    /*Altera o ponteiro para o ultimo valor*/
    lista->ultimo = registro;

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos", temFuncao.tempo);

    printf("\n\n");
}

void addMeioEncad(ListaHeader *lista){

    char nome[30];
    int rg, posicao, i;

    ListaEncad *registro, *auxAnterior, *auxProximo;

    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    printf("\nQual a Posicao?\n");
    scanf("%i", &posicao);
    getchar();

    printf("\nQual o Nome?\n");
    scanf("%s", nome);
    getchar();

    printf("\nQual o RG?\n");
    scanf("%i", &rg);
    getchar();

    auxAnterior = lista->primeiro;

    for(i=1 ; i<posicao-1 ; i++){
        numItera++;
        /*Corre a lista para encontrar a posição a ser adicionada*/
        auxAnterior = auxAnterior->proximo;
    }

    /*Pega o próximo vetor para poder adicionar um novo no meio*/
    auxProximo = auxAnterior->proximo;

    /* Aloca a Memória necessária */
    registro = malloc(sizeof(ListaEncad));

    /*Separa a String, pega o nome*/
    strcpy(registro->nome, nome);
    numCopias++;

    /*Separa a String, pega o rg*/
    registro->rg = rg;
    numCopias++;

    /*Altera a quantidade de elementos*/
    lista->qtdElementos = lista->qtdElementos+1;

    /*Organização dos ponteiros para o anterior do novo elemento*/
    auxAnterior->proximo = registro;
    registro->anterior = auxAnterior;

    /*Organização dos ponteiros para o proximo do novo elemento*/
    auxProximo->anterior = registro;
    registro->proximo = auxProximo;


    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos", temFuncao.tempo);
    printf("\n\n");

}

void addInicioEncad(ListaHeader *lista){

    char nome[30];
    int rg;

    ListaEncad *registro;
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    printf("\nQual o Nome?\n");
    scanf("%s", nome);
    getchar();
    printf("\nQual o RG?\n");
    scanf("%d", &rg);
    getchar();


    /* Aloca a Memória necessária */
    registro = malloc(sizeof(ListaEncad));

    /*Separa a String, pega o nome*/
    strcpy(registro->nome, nome);
    numCopias++;

    /*Separa a String, pega o rg*/
    registro->rg = rg;
    numCopias++;

    /*Altera a quantidade de elementos*/
    lista->qtdElementos = lista->qtdElementos+1;

    /*Pega o anterior, altera o anterior para ele ter esse como próximo*/
    registro->proximo = lista->primeiro;
    registro->proximo->anterior = registro;

    /*Altera o ponteiro para o ultimo valor*/
    lista->primeiro = registro;

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos", temFuncao.tempo);
    printf("\n\n");

}

void pesquisaEncad(ListaHeader *lista){

    int posicao, i, rg, opcBusca=3;

    ListaEncad *registro;
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    while(opcBusca != 0){
        numItera++;

        printf("\nQual a Opcao de Busca?\n"
               "(1)Posicao\n"
               "(2)RG\n");
        scanf("%d", &opcBusca);
        getchar();

        registro = lista->primeiro;

        if(opcBusca == 1){
            numItera++;

            printf("\nQual a Posicao\n");
            scanf("%d", &posicao);
            getchar();

            for(i=1 ; i<posicao ; i++){
                numItera++;
                /*Corre a lista para encontrar o item desejado*/
                registro = registro->proximo;
            }

            printf("\nPosicao:%i\n"
                       "Nome:%s\n"
                       "RG:%i\n", i, registro->nome, registro->rg);

            /*Altera o valor para quebrar o loop while*/
            opcBusca = 0;
        }
        else if(opcBusca == 2){
            numItera++;

            printf("\nQual o RG?\n");
            scanf("%d", &rg);
            getchar();

            for(i=1 ; i<=lista->qtdElementos; i++){
                numItera++;

                if(registro->rg == rg){
                    numItera++;
                    /*Caso seja igual, sai do loop for*/
                    break;
                }
                else{
                    numItera++;
                    /*Continua correndo o vetor até o rg ser igual*/
                    registro = registro->proximo;
                }
            }

            printf("\nPosicao:%i\n"
                       "Nome:%s\n"
                       "RG:%i\n", i, registro->nome, registro->rg);

            /*Altera o valor para quebrar o loop while*/
            opcBusca = 0;

        }

    }


    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos", temFuncao.tempo);
    printf("\n\n");

}

void removeEncad(ListaHeader *lista){

    int posicao, i;

    ListaEncad *registro, *auxAnterior, *auxProximo;

    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    printf("\nQual a Posicao?\n");
    scanf("%d", &posicao);
    getchar();

    registro = lista->primeiro;
    if(posicao == 1){
        numItera++;

        /*encontra a referencia e atribui para as variaveir*/
        registro = lista->primeiro;
        auxProximo = registro->proximo;

        /*Altera referencia do próximo*/
        auxProximo->anterior = NULL;

        /*Altera referencia do primeiro item*/
        lista->primeiro = auxProximo;

        /*Libera memoria*/
        free(registro);
    }

    else if(posicao == lista->qtdElementos){
        numItera++;

        registro = lista->ultimo;
        auxAnterior = registro->anterior;

        /*Altera referencia do próximo*/
        auxAnterior->proximo = NULL;

        /*Altera referencia do primeiro item*/
        lista->ultimo = auxAnterior;

        /*Libera memoria*/
        free(registro);
    }
    else{
        numItera++;
        for(i=1 ; i<posicao ; i++){
         numItera++;
            /*Corre a lista para encontrar a posição a ser adicionada*/
            registro = registro->proximo;
        }

        /*Pega as referencias dos elementos que estão em torno do que será removido*/
        auxAnterior = registro->anterior;
        auxProximo = registro->proximo;

        /*Arruma as referencias da lista*/
        auxAnterior->proximo = auxProximo;
        auxProximo->anterior = auxAnterior;

        /*Libera a memória em uso*/
        free(registro);


    }
    /*Altera a quantidade de elementos*/
    lista->qtdElementos = lista->qtdElementos-1;

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos", temFuncao.tempo);
    printf("\n\n");



}

void salvaEncad(ListaHeader *lista){

    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);
    /*Arquivo*/
    FILE *file = fopen("NomeRG10.txt", "w");

    /*Valores a serem Salvos*/
    ListaEncad *imprimir;

    /*Contador para impressão*/
    int i;

    imprimir = lista->primeiro;

    for(i=0 ; i<lista->qtdElementos ; i++){
        numItera++;

        /*Imprime registro em questão*/
        fprintf(file,"%s,%i \n", imprimir->nome, imprimir->rg);
        /*Altera o registro para o próximo*/
        imprimir = imprimir->proximo;
    }

    fclose(file);

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);

}

void mainListaEncadeada(){

    ListaHeader lista;
    ListaEncad **vetor;
    int opcAcao = 0, i;

    lista.primeiro = NULL;
    lista.ultimo = NULL;
    lista.qtdElementos = 0;

    vetor = malloc(10 * sizeof(ListaEncad));

    //preencheLista(&lista);
    preencheVetorPonteiros(&lista, vetor);

    while(opcAcao != -1){
        numItera++;

         printf("Qual a funcao?\n"
               "(01) Imprimir Lista\n"
               "(02) Adicionar no Final\n"
               "(03) Adicionar no Meio\n"
               "(04) Adicionar no Inicio\n"
               "(05) Remover Item\n"
               "(06) Pesquisar Pessoa\n"
               "(07) Salvar Arquivo\n"
               "(08) Quantidade de Elementos\n"
               "(09) Numero de IF'S\n"
               "(10) Numero de Copias\n"
               "(11) Organizar\n"
               "(-1) Sair\n");

        scanf("%i", &opcAcao);
        getchar();

        switch(opcAcao){
            case 1: printf("\n\n");
                    imprimeEncad(&lista);
                    printf("\n\n");
                    for(i=0 ; i<10 ; i++){
                        printf("Nome:%s||RG:%d\n", vetor[i]->nome, vetor[i]->rg);
                    }
                    printf("\n\n");
                    numItera++;
                    break;

            case 2: addFinalEncad(&lista);
                    numItera++;
                    break;

            case 3: addMeioEncad(&lista);
                    numItera++;
                    break;

            case 4: addInicioEncad(&lista);
                    numItera++;
                    break;

            case 5: removeEncad(&lista);
                    numItera++;
                    break;

            case 6: pesquisaEncad(&lista);
                    numItera++;
                    break;

            case 7: salvaEncad(&lista);
                    numItera++;
                    break;

            case 8: printf("\nQuantidade de Elementos:%i\n\n", lista.qtdElementos);
                    numItera++;
                    break;

            case 9: printf("\nNumero IF'S: %d\n\n", numItera);
                    numItera++;
                    break;

            case 10: printf("\nNumero Copias Feitas: %d\n\n", numCopias);
                    numItera++;
                    break;

            case 11:mainOrgEncad(&lista);
                    numItera++;
                    break;

        }
    }


}

