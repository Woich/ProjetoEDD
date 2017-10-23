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

ListaEncad** addFinalEncad(ListaEncad **lisOper, ListaHeader *listaFim){
    numCopias = 0;
    numItera = 0;

    ContTempo temFuncao;
    int rgAdd, i;
    char nomeAdd[30];

    ListaEncad *registro, **vetorAux;

    //gera o vetor auxiliar que será passado de volta como retorno
    vetorAux = malloc((listaFim->qtdElementos+1) * sizeof(ListaEncad));

    registro = malloc(sizeof(ListaEncad));

    temFuncao.temIni = time(NULL);

    for(i=0 ; i<listaFim->qtdElementos ; i++){
        vetorAux[i] = lisOper[i];
        numItera++;
        numCopias++;
    }

    /*Pega o nome a tribui ao elemento do Vetor*/
    printf("Digite o nome:\n");
    scanf("%s",nomeAdd);
    getchar();
    /*Pega o rg a tribui ao elemento do Vetor*/
    printf("Digite o RG:\n");
    scanf("%i", &rgAdd);
    getchar();

    //Faz as cópias para registro
    strcpy(registro->nome, nomeAdd);
    printf("%s\n", registro->nome);
    numCopias++;
    registro->rg = rgAdd;
    printf("%d\n", registro->rg);
    numCopias++;

    //Add o elemento gerado em registro
    vetorAux[listaFim->qtdElementos] = registro;
    numCopias++;

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

    free(lisOper);
    return vetorAux;

}

ListaEncad** addMeioEncad(ListaEncad **lisOperMeio, ListaHeader *listaMeio){

    int posiNovo, cont, rgNovo;
    char nomeNovo[30];
    ListaEncad *registro, **vetorAux;
    ContTempo temFuncao;

    //Aloca memória necessária para a efetuação a adição;
    registro = malloc(sizeof(ListaEncad));
    vetorAux = malloc((listaMeio->qtdElementos+1)*sizeof(ListaEncad));

    temFuncao.temIni = time(NULL);
    numCopias = 0;
    numItera = 0;

    /*Pega o local que será adicionado*/
    printf("Qual a posicao?\n");
    scanf("%i",&posiNovo);

    /*Pega o nome a tribui ao elemento do Vetor*/
    printf("Digite o nome:\n");
    scanf("%s", nomeNovo);

    /*Pega o rg a tribui ao elemento do Vetor*/
    printf("Digite o RG:\n");
    scanf("%i", &rgNovo);
    getchar();

    strcpy(registro->nome, nomeNovo);
    numCopias++;

    registro->rg = rgNovo;
    numCopias++;

    for(cont=0; cont<=listaMeio->qtdElementos ; cont++){

        numItera++;

        if(cont < posiNovo-1){
            vetorAux[cont]=lisOperMeio[cont];
            numItera++;
            numCopias++;
        }
        else if(cont == posiNovo-1){
            vetorAux[cont] = registro;
            numItera++;
            numCopias++;
        }
        else{
            vetorAux[cont]=lisOperMeio[cont-1];
            numItera++;
            numCopias++;
        }
    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

    free(lisOperMeio);
    return vetorAux;

}

ListaEncad** addInicioEncad(ListaEncad **lisOperIni, ListaHeader *listaIni){

    int cont, rgNovo;
    char nomeNovo[30];
    ListaEncad *registro, **vetorAux;
    ContTempo temFuncao;

    //Aloca memória necessária para a efetuação a adição;
    registro = malloc(sizeof(ListaEncad));
    vetorAux = malloc((listaIni->qtdElementos+1)*sizeof(ListaEncad));

    temFuncao.temIni = time(NULL);
    numCopias = 0;
    numItera = 0;

    /*Pega o nome a tribui ao elemento do Vetor*/
    printf("Digite o nome:\n");
    scanf("%s", nomeNovo);

    /*Pega o rg a tribui ao elemento do Vetor*/
    printf("Digite o RG:\n");
    scanf("%i", &rgNovo);
    getchar();

    strcpy(registro->nome, nomeNovo);
    numCopias++;

    registro->rg = rgNovo;
    numCopias++;

    vetorAux[0]=registro;

    for(cont=1; cont<=listaIni->qtdElementos ; cont++){

        vetorAux[cont]=lisOperIni[cont-1];
        numItera++;
        numCopias++;

    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

    free(lisOperIni);
    return vetorAux;
}

ListaEncad** removeEncad(ListaEncad **lisOperRemove, ListaHeader *listaRemove){

    int cont, posiRemove;
    ListaEncad **vetorAux;
    ContTempo temFuncao;

    //Aloca memória necessária para a efetuação a adição;
    vetorAux = malloc((listaRemove->qtdElementos-1)*sizeof(ListaEncad));

    temFuncao.temIni = time(NULL);
    numCopias = 0;
    numItera = 0;

    /*Pega o rg a tribui ao elemento do Vetor*/
    printf("Qual posicao a ser removida?:\n");
    scanf("%i", &posiRemove);
    getchar();

    for(cont=0; cont<listaRemove->qtdElementos ; cont++){
        numItera++;

        if(cont == posiRemove-1){
            continue;
            numItera++;
        }
        else if(cont < posiRemove-1){
            vetorAux[cont]=lisOperRemove[cont];
            numItera++;
            numCopias++;
        }
        else{
            vetorAux[cont-1]=lisOperRemove[cont];
            numItera++;
            numCopias++;
        }

    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

    free(lisOperRemove);
    return vetorAux;
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
    int opcAcao = 0, i, opcArq, opcSort, ordem=0;
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
               "(12) Pesquisa Binaria\n"
               "(-1) Sair\n");

        scanf("%i", &opcAcao);
        getchar();

        switch(opcAcao){
            case 1: printf("\n\n");
                    imprimeEncad(&lista, vetor);
                    numItera++;
                    break;

            case 2: vetor = addFinalEncad(vetor, &lista);
                    numItera++;
                    lista.qtdElementos++;
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
                    if(ordem == 1){
                        insertionSortEncad(&lista, vetor);
                    }
                    break;

            case 3: vetor = addMeioEncad(vetor, &lista);
                    numItera++;
                    lista.qtdElementos++;
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
                    if(ordem == 1){
                        insertionSortEncad(&lista, vetor);
                    }
                    break;

            case 4: vetor = addInicioEncad(vetor, &lista);
                    numItera++;
                    lista.qtdElementos++;
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
                    if(ordem == 1){
                        insertionSortEncad(&lista, vetor);
                    }
                    break;

            case 5: vetor = removeEncad(vetor, &lista);
                    numItera++;
                    lista.qtdElementos--;
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
                    if(ordem == 1){
                        insertionSortEncad(&lista, vetor);
                    }
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
                           "(5)Merge Sort\n"
                           "(6)Shell Sort\n");
                    scanf("%d", &opcSort);

                    switch(opcSort){
                        case 1:selecSortEncad(&lista, vetor);
                               ordem = 1;
                               break;

                        case 2:bubbleSortEncad(&lista, vetor);
                               ordem = 1;
                               break;

                        case 3:insertionSortEncad(&lista, vetor);
                               ordem = 1;
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
                                ordem = 1;
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
                                ordem = 1;
                                break;

                        case 6: numCopias=0; numItera=0;
                                temFuncao.temIni = time(NULL);
                                numElementos = lista.qtdElementos-1;
                                shellSortEncad(&lista, vetor);
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
                                ordem = 1;
                                break;
                    }
                    break;

            case 12:numCopias=0; numItera=0;
                    temFuncao.temIni = time(NULL);
                    pesquisaBinariaEncad(&lista, vetor);
                    temFuncao.temFinal = time(NULL);
                    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
                    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
                    printf("\n\n");
                    break;

        }
    }


}

