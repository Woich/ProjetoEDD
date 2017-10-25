#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"

void preencheListaSequencial(int *numEle, ListaPessoa **vetorPonteiros, int opcArq){

    ContTempo temFuncao;
    FILE *file;
    char linInicial[30],*linTemp, *strPart;
    char delimit[]=" .,;:";
    ListaPessoa *registro;
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

        if(*numEle == 0){
            numItera++;

            //Aloca Memoria
            vetorPonteiros[0] = malloc(sizeof(ListaPessoa));
            registro = malloc(sizeof(ListaPessoa));

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


            //Arruma a lista
            *numEle = *numEle+1;

            //Adiciona no vetor de ponteiros;
            vetorPonteiros[0] = registro;
            numCopias++;
        }
        else{
            numItera++;

            //Aloca Memoria
            vetorPonteiros[i] = malloc(sizeof(ListaPessoa));
            registro = malloc(sizeof(ListaPessoa));

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


            //Arruma a lista
            *numEle = *numEle+1;

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

ListaPessoa** addFinal(ListaPessoa **lisOper, int fim){
    numCopias = 0;
    numItera = 0;

    ContTempo temFuncao;
    int rgAdd, i;
    char nomeAdd[30];

    ListaPessoa *registro, **vetorAux;

    //gera o vetor auxiliar que será passado de volta como retorno
    vetorAux = malloc((fim+1) * sizeof(ListaPessoa));

    registro = malloc(sizeof(ListaPessoa));

    temFuncao.temIni = time(NULL);

    for(i=0 ; i<fim ; i++){
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
    vetorAux[fim] = registro;
    numCopias++;

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

    free(lisOper);
    return vetorAux;

}

ListaPessoa** addMeio(ListaPessoa **lisOperMeio, int fimMeio){

    int posiNovo, cont, rgNovo;
    char nomeNovo[30];
    ListaPessoa *registro, **vetorAux;
    ContTempo temFuncao;

    //Aloca memória necessária para a efetuação a adição;
    registro = malloc(sizeof(ListaPessoa));
    vetorAux = malloc((fimMeio+1)*sizeof(ListaPessoa));

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

    for(cont=0; cont<=fimMeio ; cont++){

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

ListaPessoa** addIni(ListaPessoa **lisOperIni, int fimIni){

    int cont, rgNovo;
    char nomeNovo[30];
    ListaPessoa *registro, **vetorAux;
    ContTempo temFuncao;

    //Aloca memória necessária para a efetuação a adição;
    registro = malloc(sizeof(ListaPessoa));
    vetorAux = malloc((fimIni+1)*sizeof(ListaPessoa));

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

    for(cont=1; cont<=fimIni ; cont++){

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

ListaPessoa** removeItem(ListaPessoa **lisOperRemove, int fimRemove){

    int cont, posiRemove;
    ListaPessoa **vetorAux;
    ContTempo temFuncao;

    //Aloca memória necessária para a efetuação a adição;
    vetorAux = malloc((fimRemove-1)*sizeof(ListaPessoa));

    temFuncao.temIni = time(NULL);
    numCopias = 0;
    numItera = 0;

    /*Pega o rg a tribui ao elemento do Vetor*/
    printf("Qual posicao a ser removida?:\n");
    scanf("%i", &posiRemove);
    getchar();

    for(cont=0; cont<fimRemove ; cont++){
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

void imprimeLista(long int fim, ListaPessoa **vetorPonteiros){

    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);
    /*Contador para impressão*/
    long int i;

    ListaPessoa *registro = malloc(sizeof(ListaPessoa));

    for(i=0 ; i<fim ; i++){
        //Imprime registro em questão
        registro = vetorPonteiros[i];
        printf("%d: %s,%d \n", i+1, registro->nome, registro->rg);
    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

}

void procuraRG(ListaPessoa *pessoas, int tamList){
    numCopias++;/*Contador somado para cada cópia feita na função*/

    int j, numItem, cont=0;
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    printf("Qual o RG?\n");
    scanf("%i", &numItem);

    /*Corre lista inteira*/
    for(j=0 ; j<tamList ; j++){

        numItera++;

        /*Caso seja igual ele imprime*/
        if(pessoas[j].rg == numItem){
            numItera++;
            cont++;
            printf("\n\nPosicao:%i\n"
                   "Nome:%s\n"
                   "RG:%i\n\n", j+1, pessoas[j].nome, pessoas[j].rg);
        }
    }

    /*Caso não ache*/
    if(cont == 0){
        numItera++;
        printf("RG nao existente");
    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);
}

void salvaLista(ListaPessoa *pessoas, int arquivo, int tamList){
    numCopias++;/*Contador somado para cada cópia feita na função*/
    numCopias++;

    int j;
    FILE *file = fopen("NomeRG1M.txt", "w");
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    /*Corre lista e imprime no arquivo*/
    for(j=0 ; j<tamList ; j++){
        numItera++;
        fprintf(file,"%s,%i\n", pessoas[j].nome, pessoas[j].rg);
    }

    printf("Salvo com sucesso");
    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);
}

void mainSequencial(){

    int opcArq=0, opcFun=0, j, numEle=0, opcOrg, ordem=0;
    ListaPessoa **listaSequencial;
    ContTempo temFuncao;//Função

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
        case 1: listaSequencial =malloc(10 * sizeof(ListaPessoa));
                break;
        case 2: listaSequencial =malloc(50 * sizeof(ListaPessoa));
                break;
        case 3: listaSequencial =malloc(100 * sizeof(ListaPessoa));
                break;
        case 4: listaSequencial =malloc(1000 * sizeof(ListaPessoa));
                break;
        case 5: listaSequencial =malloc(10000 * sizeof(ListaPessoa));
                break;
        case 6: listaSequencial =malloc(1000000 * sizeof(ListaPessoa));
                break;
        case 7: listaSequencial =malloc(11748444 * sizeof(ListaPessoa));
                break;
    }

    preencheListaSequencial(&numEle,listaSequencial, opcArq);

    /*Menu de opções*/
    while(opcFun != -1){

        printf("Qual a funcao?\n"
               "(01) Imprimir Lista\n"
               "(02) Adicionar no Final\n"
               "(03) Adicionar no Meio\n"
               "(04) Adicionar no Inicio\n"
               "(05) Remover Item\n"
               "(06) Pesquisar RG\n"
               "(07) Salvar Arquivo\n"
               "(08) Número de IF'S\n"
               "(09) Número de Copias\n"
               "(10) Organização\n"
               "(11) Pesquisa Binaria\n"
               "(-1) Sair\n");
        scanf("%i", &opcFun);
        getchar();

        switch(opcFun){
            case 1: imprimeLista(numEle, listaSequencial);
                    numItera++;
                    printf("\n\n");
                    break;

            case 2: listaSequencial = addFinal(listaSequencial, numEle);
                    numEle++;
                    numItera++;
                    if(ordem == 1){
                        insertionSortSquencial(numEle, listaSequencial);
                    }
                    break;

            case 3: listaSequencial = addMeio(listaSequencial, numEle);
                    numItera++;
                    numEle++;
                    if(ordem == 1){
                        insertionSortSquencial(numEle, listaSequencial);
                    }
                    break;

            case 4: listaSequencial = addIni(listaSequencial, numEle);
                    numItera++;
                    numEle++;
                    if(ordem == 1){
                        insertionSortSquencial(numEle, listaSequencial);
                    }
                    break;

            case 5: listaSequencial = removeItem(listaSequencial, numEle);
                    numItera++;
                    numEle--;
                    if(ordem == 1){
                        insertionSortSquencial(numEle, listaSequencial);
                    }
                    break;

            case 6: procuraRG(listaSequencial, numEle);
                    numItera++;
                    break;

            case 7: salvaLista(listaSequencial, opcArq, numEle);
                    numItera++;
                    break;

            case 8: printf("\nNúmero IF'S: %d\n\n", numItera);
                    numItera++;
                    break;

            case 9: printf("\nNúmero Cópias Feitas: %d\n\n", numCopias);
                    numItera++;
                    break;

            case 10:numItera++;
                    printf("Qual metodo de organizacao?\n"
                           "(1)Selection Sort\n"
                           "(2)Bubble Sort\n"
                           "(3)Insertion Sort\n"
                           "(4)Quick Sort\n"
                           "(5)Merge Sort\n"
                           "(6)Shell Sort\n");
                    scanf("%d", &opcOrg);

                    switch(opcOrg){
                        case 1:selecSortSquencial(numEle, listaSequencial);
                               ordem = 1;
                               break;

                        case 2:bubbleSortSquencial(numEle, listaSequencial);
                               ordem = 1;
                               break;

                        case 3:insertionSortSquencial(numEle, listaSequencial);
                               ordem = 1;
                               break;

                        case 4: numCopias=0; numItera=0;
                                temFuncao.temIni = time(NULL);

                                quickSortSquencial(listaSequencial, 0, numEle);

                                temFuncao.temFinal = time(NULL);
                                temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
                                printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
                                printf("\n\n");
                                ordem = 1;
                                break;

                        case 5: numCopias=0; numItera=0;
                                temFuncao.temIni = time(NULL);

                                mergeSortSquencial(listaSequencial, 0, numEle);

                                temFuncao.temFinal = time(NULL);
                                temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
                                printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
                                printf("\n\n");
                                ordem = 1;
                                break;

                        case 6: numCopias=0; numItera=0;
                                temFuncao.temIni = time(NULL);

                                shellSortSquencial(numEle, listaSequencial);

                                temFuncao.temFinal = time(NULL);
                                temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
                                printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
                                printf("\n\n");
                                ordem = 1;
                                break;
                    }
                    break;

            case 11:numCopias=0; numItera=0;
                    temFuncao.temIni = time(NULL);

                    pesquisaBinariaSquencial(numEle, listaSequencial);

                    temFuncao.temFinal = time(NULL);
                    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
                    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
                    printf("\n\n");
                    break;
        }
    }

}
