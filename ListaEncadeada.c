#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"
#include "Teste.h"


void preencheLista(ListaHeader *listaGerada, ListaEncad **vetorPonteiros, int opcArq){

    ContTempo temFuncao;
    FILE *file;
    char linInicial[30],*linTemp, *strPart;
    char delimit[]=" .,;:";
    ListaEncad *registro;
    long int i, numRegistros;

    temFuncao.temIni = time(NULL);
    numCopias = 0;
    numItera = 0;

    switch(opcArq){
        case 1: file = fopen("NomeRG10.txt", "r");
                numRegistros = 10;
                numItera++;
                break;
        case 2: file = fopen("NomeRG50.txt", "r");
                numRegistros = 50;
                numItera++;
                break;
        case 3: file = fopen("NomeRG100.txt", "r");
                numRegistros = 100;
                numItera++;
                break;
        case 4: file = fopen("NomeRG1K.txt", "r");
                numRegistros = 1000;
                numItera++;
                break;
        case 5: file = fopen("NomeRG10K.txt", "r");
                numRegistros = 10000;
                numItera++;
                break;
        case 6: file = fopen("NomeRG1M.txt", "r");
                numRegistros = 1000000;
                numItera++;
                break;
        case 7: file = fopen("NomeRG100M.txt", "r");
                numRegistros = 11748444;
                numItera++;
                break;
    }


    //Le a primeira linha do arquivo
    fgets(linInicial, 30, file);
    numCopias++;

    for(i=0; i<numRegistros ; i++){
        numItera++;

        if(listaGerada->qtdElementos == 0){
            numItera++;

            //Aloca Memoria
            vetorPonteiros[0] = malloc(sizeof(ListaEncad));
            registro = malloc(sizeof(ListaEncad));

            //passa as infromações para registro
            /*Atribui vetor a um ponteiro*/
            linTemp = linInicial;
            numCopias++;

            /*Separa a String, pega o nome*/
            strPart = strsep(&linTemp, delimit);
            strcpy(registro->nome, strPart);
            numCopias++;

            /*Separa a String, pega o rg*/
            strPart = strsep(&linTemp, delimit);
            registro->rg = atoi(strPart);
            numCopias++;

            //Arruma referencias
            registro->anterior = 0;
            registro->proximo = 0;

            //Arruma a lista
            listaGerada->qtdElementos = listaGerada->qtdElementos+1;

            listaGerada->primeiro = registro;
            numCopias++;

            listaGerada->ultimo = registro;
            numCopias++;

            //Adiciona no vetor de ponteiros;
            vetorPonteiros[0] = registro;
            numCopias++;
        }
        else{
            numItera++;

            //Aloca Memoria
            vetorPonteiros[i] = malloc(sizeof(ListaEncad));
            registro = malloc(sizeof(ListaEncad));

            //passa as infromações para registro
            /*Atribui vetor a um ponteiro*/
            linTemp = linInicial;
            numCopias++;

            /*Separa a String, pega o nome*/
            strPart = strsep(&linTemp, delimit);
            strcpy(registro->nome, strPart);
            numCopias++;

            /*Separa a String, pega o rg*/
            strPart = strsep(&linTemp, delimit);
            registro->rg = atoi(strPart);
            numCopias++;

            //Arruma referencias
            listaGerada->ultimo->proximo = registro;
            numCopias++;

            registro->anterior = listaGerada->ultimo;
            numCopias++;

            registro->proximo = 0;

            //Arruma a lista
            listaGerada->qtdElementos = listaGerada->qtdElementos+1;

            listaGerada->ultimo = registro;
            numCopias++;

            //Adiciona no vetor de ponteiros;
            vetorPonteiros[i] = registro;
            numCopias++;
        }

        linInicial[0] = '\0';
        fgets(linInicial, 30, file);

    }


    fclose(file);
    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");


}

void imprimeEncad(ListaHeader *lista, ListaEncad **vetorPonteiros){

    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);
    /*Valor a ser impresso*/
    ListaEncad *imprimir;
    /*Contador para impressão*/
    long int i;

    imprimir = lista->primeiro;

    /*for(i=0 ; i<lista->qtdElementos ; i++){
        numItera++;

        //Imprime registro em questão
        printf("%d: %s,%d \n", i+1, imprimir->nome, imprimir->rg);
        //Altera o registro para o próximo
        imprimir = imprimir->proximo;
    }*/

    for(i=0 ; i<lista->qtdElementos ; i++){
        //Imprime registro em questão
        printf("%d: %s,%d \n", i+1, vetorPonteiros[i]->nome, vetorPonteiros[i]->rg);
    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

}

void addFinalEncad(ListaHeader *lista, ListaEncad **vetorPonteiros){
    char nome[30];
    int rg;

    numCopias=0;
    numItera=0;

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
    numCopias++;

    /*Pega o anterior, altera o anterior para ele ter esse como próximo*/
    registro->anterior = lista->ultimo;
    numCopias++;
    registro->anterior->proximo = registro;
    numCopias++;

    /*Altera o ponteiro para o ultimo valor*/
    lista->ultimo = registro;
    numCopias++;

    vetorPonteiros = realloc(vetorPonteiros, (lista->qtdElementos * sizeof(ListaEncad)));
    vetorPonteiros[lista->qtdElementos-1] = registro;
    numCopias++;

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");
}

void addMeioEncad(ListaHeader *lista, ListaEncad **vetorPonteiros){

    char nome[30];
    int rg, posicao;
    long int i;

    numCopias=0;
    numItera=0;

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

    registro = malloc(sizeof(ListaEncad));
    lista->qtdElementos = lista->qtdElementos+1;

    //Arruma a quantidade de itens no vetor
    vetorPonteiros = realloc(vetorPonteiros, (lista->qtdElementos * sizeof(ListaEncad)));

    //Adiciona os valores para  o registro
    strcpy(registro->nome, nome);
    numCopias++;
    registro->rg = rg;
    numCopias++;

    //Arruma posição
    auxAnterior = vetorPonteiros[posicao-2];
    numCopias++;
    auxProximo = vetorPonteiros[posicao-1];
    numCopias++;

    for(i=lista->qtdElementos ; i>posicao ; i--){
        vetorPonteiros[i-1] = vetorPonteiros[i-2];
        numItera++;
        numCopias++;
    }

    //Adiciona Referencias ao registro
    registro->proximo =  auxProximo;
    numCopias++;
    registro->anterior = auxAnterior;
    numCopias++;

    //Arruma posições a volta
    auxAnterior->proximo = registro;
    numCopias++;
    auxProximo->anterior = registro;
    numCopias++;

    //Adiciona elemento no vetor
    vetorPonteiros[posicao-1] = registro;
    numCopias++;

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

}

void addInicioEncad(ListaHeader *lista, ListaEncad **vetorPonteiros){

    char nome[30];
    int rg;
    long int i;

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
    lista->qtdElementos= lista->qtdElementos+1;

    vetorPonteiros = realloc(vetorPonteiros, lista->qtdElementos);

    /*Separa a String, pega o nome*/
    strcpy(registro->nome, nome);
    numCopias++;

    /*Separa a String, pega o rg*/
    registro->rg = rg;
    numCopias++;

    //Desce todos os elementos
    for(i=lista->qtdElementos ; i>0 ; i--){
        vetorPonteiros[i] = vetorPonteiros[i-1];
        numCopias++;
        numItera++;
    }

    //Adiciona o elemento no vetor
    vetorPonteiros[0] = registro;
    numCopias++;

    //Arruma referencias do elemento
    registro->anterior = 0;
    registro->proximo = vetorPonteiros[1];
    numCopias++;

    //Arruma referencias da lista
    vetorPonteiros[1]->anterior = vetorPonteiros[0];
    numCopias++;
    lista->primeiro = vetorPonteiros[0];
    numCopias++;


    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
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

        /*---------------Posição--------------------*/
        if(opcBusca == 1){
            numItera++;

            printf("\nQual a Posicao\n");
            scanf("%d", &posicao);
            getchar();

            if(posicao < 1 || posicao > lista->qtdElementos){
                printf("\n Posicao Invalida\n\n");
            }

            else{
                for(i=1 ; i<posicao ; i++){
                    numItera++;
                    /*Corre a lista para encontrar o item desejado*/
                    registro = registro->proximo;
                    numCopias++;
                }

                printf("\nPosicao:%i\n"
                           "Nome:%s\n"
                           "RG:%i\n", i, registro->nome, registro->rg);

                /*Altera o valor para quebrar o loop while*/
                opcBusca = 0;

            }
        }
        /*----------------- RG --------------------*/
        else if(opcBusca == 2){
            numItera++;

            printf("\nQual o RG?\n");
            scanf("%d", &rg);
            getchar();

            for(i=1 ; i<=lista->qtdElementos; i++){
                numItera++;

                if(lista->ultimo->rg == registro->rg && registro->rg != rg){
                    numItera++;
                    printf("\nO RG(%d) nao foi cadastrado\n\n", rg);
                    break;
                }

                if(registro->rg == rg){
                    numItera++;

                    printf("\nPosicao:%i\n"
                           "Nome:%s\n"
                           "RG:%i\n", i, registro->nome, registro->rg);

                    /*Altera o valor para quebrar o loop while*/
                    opcBusca = 0;

                    /*Caso seja igual, sai do loop for*/
                    break;
                }
                else{
                    numItera++;
                    /*Continua correndo o vetor até o rg ser igual*/
                    registro = registro->proximo;
                    numCopias++;
                }
            }
        }

    }


    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

}

void removeEncad(ListaHeader *lista, ListaEncad **vetorPonteiros){

    int posicao;
    long int i;

    ListaEncad *registro, *auxAnterior, *auxProximo;

    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    printf("\nQual a Posicao?\n");
    scanf("%d", &posicao);
    getchar();

    numCopias = 0;
    numItera = 0;

    registro = lista->primeiro;
    if(posicao == 1){
        numItera++;

        /*encontra a referencia e atribui para as variaveir*/
        registro = lista->primeiro;
        numCopias++;

        auxProximo = registro->proximo;
        numCopias++;

        /*Altera referencia do próximo*/
        auxProximo->anterior = NULL;

        /*Altera referencia do primeiro item*/
        lista->primeiro = auxProximo;
        numCopias++;

        //Altera o vetor para que ele fique correto
        for(i=0 ; i<lista->qtdElementos ; i++){

            if(vetorPonteiros[i]->rg != lista->ultimo->rg){

                vetorPonteiros[i] = vetorPonteiros[i+1];
                numCopias++;
                numItera++;
            }

        }

        /*Libera memoria*/
        free(registro);
        vetorPonteiros = realloc(vetorPonteiros, sizeof(ListaEncad) * (lista->qtdElementos-1));
    }

    else if(posicao == lista->qtdElementos){
        numItera++;

        registro = lista->ultimo;
        numCopias++;

        auxAnterior = registro->anterior;
        numCopias++;

        /*Altera referencia do próximo*/
        auxAnterior->proximo = NULL;

        /*Altera referencia do primeiro item*/
        lista->ultimo = auxAnterior;
        numCopias++;

        /*Libera memoria*/
        free(registro);
        vetorPonteiros = realloc(vetorPonteiros, sizeof(ListaEncad) * (lista->qtdElementos-1));
    }
    else{
        numItera++;
        for(i=1 ; i<posicao ; i++){
         numItera++;
            /*Corre a lista para encontrar a posição a ser adicionada*/
            registro = registro->proximo;
            numCopias++;
        }

        /*Pega as referencias dos elementos que estão em torno do que será removido*/
        auxAnterior = registro->anterior;
        numCopias++;

        auxProximo = registro->proximo;
        numCopias++;

        /*Arruma as referencias da lista*/
        auxAnterior->proximo = auxProximo;
        numCopias++;

        auxProximo->anterior = auxAnterior;
        numCopias++;

        //Altera o vetor para que ele fique correto
        for(i=posicao-1 ; i<lista->qtdElementos ; i++){
            numItera++;

            if(vetorPonteiros[i]->rg != lista->ultimo->rg){

                vetorPonteiros[i] = vetorPonteiros[i+1];
                numCopias++;
                numItera++;
            }

        }

        /*Libera a memória em uso*/
        free(registro);
        vetorPonteiros = realloc(vetorPonteiros, sizeof(ListaEncad) * (lista->qtdElementos-1));


    }

    /*Altera a quantidade de elementos*/
    lista->qtdElementos = lista->qtdElementos-1;

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");



}

void salvaEncad(ListaHeader *lista){

    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);
    /*Arquivo*/
    FILE *file = fopen("NomeRG10.txt", "w");

    numCopias = 0;
    numItera = 0;

    /*Valores a serem Salvos*/
    ListaEncad *imprimir;

    /*Contador para impressão*/
    int i;

    imprimir = lista->primeiro;

    for(i=0 ; i<lista->qtdElementos ; i++){
        numItera++;

        /*Imprime registro em questão*/
        fprintf(file,"%s,%d\n", imprimir->nome, imprimir->rg);
        /*Altera o registro para o próximo*/
        imprimir = imprimir->proximo;
        numCopias++;
    }

    fclose(file);

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

}

void mainListaEncadeada(){

    ListaHeader lista;
    ListaEncad **vetor;
    int opcAcao = 0, i, opcArq, opcSort;
    long int numRegistros, numElementos;
    ContTempo temFuncao;

    lista.primeiro = NULL;
    lista.ultimo = NULL;
    lista.qtdElementos = 0;

    printf("Qual arquivo deve ser lido?\n"
           "(1)10 registros\n"
           "(2)50 registros\n"
           "(3)100 registros\n"
           "(4)1K registros\n"
           "(5)10K registros\n"
           "(6)1M registros\n"
           "(7)10M registros\n");
    scanf("%d", &opcArq);

    switch(opcArq){
        case 1: numRegistros = 10;
                break;
        case 2: numRegistros = 50;
                break;
        case 3: numRegistros = 100;
                break;
        case 4: numRegistros = 1000;
                break;
        case 5: numRegistros = 10000;
                break;
        case 6: numRegistros = 1000000;
                break;
        case 7: numRegistros = 11748444;
                break;
    }

    vetor = malloc(numRegistros * sizeof(ListaEncad));

    preencheLista(&lista, vetor, opcArq);
    //preencheVetorPonteiros(&lista, vetor);

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
                    imprimeEncad(&lista, vetor);
                    numItera++;
                    break;

            case 2: addFinalEncad(&lista, vetor);
                    numItera++;
                    break;

            case 3: addMeioEncad(&lista, vetor);
                    numItera++;
                    break;

            case 4: addInicioEncad(&lista, vetor);
                    numItera++;
                    break;

            case 5: removeEncad(&lista, vetor);
                    numItera++;
                    break;

            case 6: pesquisaEncad(&lista);
                    numItera++;
                    break;

            case 7: salvaEncad(&lista);
                    numItera++;
                    break;

            case 8: printf("\nQuantidade de Elementos:%d\n\n", lista.qtdElementos);
                    numItera++;
                    break;

            case 9: printf("\nNumero IF'S: %d\n\n", numItera);
                    numItera++;
                    break;

            case 10:printf("\nNumero Copias Feitas: %d\n\n", numCopias);
                    numItera++;
                    break;

            case 11:numItera++;
                    printf("Qual metodo de organizacao?\n"
                           "(1)Selection Sort\n"
                           "(2)Bubble Sort\n"
                           "(3)Insertion Sort\n"
                           "(4)Quick Sort\n"
                           "(5)Merge Sort\n");
                    scanf("%d", &opcSort);

                    switch(opcSort){
                        case 1:selecSortEncad(&lista, vetor);
                               break;

                        case 2:bubbleSortEncad(&lista, vetor);
                               break;

                        case 3:insertionSortEncad(&lista, vetor);
                               break;

                        case 4: numCopias=0; numItera=0;
                                temFuncao.temIni = time(NULL);
                                numElementos = lista.qtdElementos;
                                quickSortEncad(&lista, vetor, 0, numElementos);
                                //Esse for serve para arrumas todas as referencias de todos os pontos do vetor
                                for(i=0 ; i<lista.qtdElementos ; i++){
                                    numItera++;
                                    if(i == 0){
                                        numItera++;
                                        //Muda o primeiro elemento da lista
                                        lista.primeiro = vetor[i];
                                        numCopias++;

                                        vetor[i]->anterior = 0;

                                        vetor[i]->proximo = vetor[i+1];
                                        numCopias++;
                                    }
                                    else if(i == lista.qtdElementos){
                                        numItera++;
                                        //Muda o ultimo elemento da lista
                                        lista.ultimo = vetor[i];
                                        numCopias++;

                                        vetor[i]->proximo = 0;

                                        vetor[i]->anterior = vetor[i-1];
                                        numCopias++;
                                    }
                                    else{
                                        numItera++;
                                        //Altera os elemento do meio
                                        vetor[i]->anterior = vetor[i-1];
                                        numCopias++;

                                        vetor[i]->proximo = vetor[i+1];
                                        numCopias++;

                                    }
                                }
                                temFuncao.temFinal = time(NULL);
                                temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
                                printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
                                printf("\n\n");
                                break;

                        case 5: numCopias=0; numItera=0;
                                temFuncao.temIni = time(NULL);
                                numElementos = lista.qtdElementos-1;
                                mergeSortEncad(&lista, vetor, 0, numElementos);
                                //Esse for serve para arrumas todas as referencias de todos os pontos do vetor
                                for(i=0 ; i<lista.qtdElementos ; i++){
                                    numItera++;
                                    if(i == 0){
                                        numItera++;
                                        //Muda o primeiro elemento da lista
                                        lista.primeiro = vetor[i];
                                        numCopias++;

                                        vetor[i]->anterior = 0;

                                        vetor[i]->proximo = vetor[i+1];
                                        numCopias++;
                                    }
                                    else if(i == lista.qtdElementos){
                                        numItera++;
                                        //Muda o ultimo elemento da lista
                                        lista.ultimo = vetor[i];
                                        numCopias++;

                                        vetor[i]->proximo = 0;

                                        vetor[i]->anterior = vetor[i-1];
                                        numCopias++;
                                    }
                                    else{
                                        numItera++;
                                        //Altera os elemento do meio
                                        vetor[i]->anterior = vetor[i-1];
                                        numCopias++;

                                        vetor[i]->proximo = vetor[i+1];
                                        numCopias++;

                                    }
                                }
                                temFuncao.temFinal = time(NULL);
                                temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
                                printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
                                printf("\n\n");
                                break;
                    }
                    break;

        }
    }


}

