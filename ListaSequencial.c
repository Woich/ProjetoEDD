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
            printf("%s\n",registro->nome);

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

void addFinal(ListaPessoa **lisOper, int *fim){
    numCopias = 0;
    numItera = 0;

    ContTempo temFuncao;
    int rgAdd;
    char nomeAdd[30];

    ListaPessoa *registro = malloc(sizeof(ListaPessoa));

    temFuncao.temIni = time(NULL);

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

    //Realoca a memória necessária
    lisOper = realloc(lisOper, (*fim+1)*sizeof(ListaPessoa));
    //Add o elemento gerado em registro
    lisOper[*fim] = registro;
    printf("%s,%d\n", lisOper[*fim]->nome, lisOper[*fim]->rg);
    //Adiciona mais um elemento no calculo
    *fim = *fim+1;
    printf("%d\n", *fim);

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

}

void addMeio(ListaPessoa *lisOper, int fim){
    numCopias++;/*Contador somado para cada cópia feita na função*/

    int posiNovo, cont;
    char nomeNovo[30];
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    /*Pega o local que será adicionado*/
    printf("Qual a posicao?\n");
    scanf("%i",&posiNovo);

    /*Corre a lista para chgar ao elemento correto. Vai descendo a lista em uma linha no meio da lista*/
    for(cont=fim+1; cont> posiNovo-1 ; cont--){
        numItera++;

        strcpy(lisOper[cont].nome, lisOper[cont-1].nome);
        numCopias++;

        /*Copia o RG anterior*/
        lisOper[cont].rg = lisOper[cont-1].rg;
        numCopias++;
    }

    /*Pega o nome a tribui ao elemento do Vetor*/
    printf("Digite o nome:\n");
    scanf("%s", nomeNovo);
    strcpy(lisOper[posiNovo-1].nome, nomeNovo);

    /*Pega o rg a tribui ao elemento do Vetor*/
    printf("Digite o RG:\n");
    scanf("%i", &lisOper[posiNovo-1].rg);
    getchar();

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);

}

void addIni(ListaPessoa *lisOper, int fim){
    numCopias++;/*Contador somado para cada cópia feita na função*/

    int  cont;
    char nomeNovo[30];
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    /*Corre vetor até o inicio, Vai copiando os valores para descer a lista inteira em uma linha*/
    for(cont=fim+1; cont> 0 ; cont--){
        numItera++;

        strcpy(lisOper[cont].nome, lisOper[cont-1].nome);
        numCopias++;

        lisOper[cont].rg = lisOper[cont-1].rg;
        numCopias++;
    }

    /*Pega o nome a tribui ao elemento do Vetor*/
    printf("Digite o nome:\n");
    scanf("%s", nomeNovo);
    strcpy(lisOper[0].nome, nomeNovo);
    numCopias++;

    /*Pega o rg a tribui ao elemento do Vetor*/
    printf("Digite o RG:\n");
    scanf("%i", &lisOper[0].rg);
    getchar();

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);
}

void removeItem(ListaPessoa *lisOper, int fim){
    numCopias++;/*Contador somado para cada cópia feita na função*/

    int posiRem, cont;
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    /*Pega a posição que será removida*/
    printf("Qual a posicao?\n");
    scanf("%d",&posiRem);

    /*Corre vetor até achar o elemento que será removido e sobe a lista inteira após a posição*/
    for(cont=fim-1 ; cont>posiRem-1 ; cont--){
        numItera++;
        strcpy(lisOper[cont-1].nome, lisOper[cont].nome);
        numCopias++;

        lisOper[cont-1].rg = lisOper[cont].rg;
        numCopias++;
    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);


}

void imprimeLista(ListaPessoa **pessoas, int tamList){
    numCopias = 0;
    numItera = 0;

    int j, numItem;
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    printf("\n\n");

    /*Roda lista e imprime o valor dela*/
    for(j=0 ; j<tamList ; j++){
        numItera++;
        numItem = j+1;
        printf("%i : %s , %i", numItem, pessoas[j]->nome, pessoas[j]->rg);
        printf("\n");
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

    int opcArq=0, opcFun=0, j, numEle=0;
    ListaPessoa **listaSequencial;

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
               "(1) Imprimir Lista\n"
               "(2) Adicionar no Final\n"
               "(3) Adicionar no Meio\n"
               "(4) Adicionar no Inicio\n"
               "(5) Remover Item\n"
               "(6) Pesquisar RG\n"
               "(7) Salvar Arquivo\n"
               "(8) Número de IF'S\n"
               "(9) Número de Copias\n"
               "(-1) Sair\n");
        scanf("%i", &opcFun);
        getchar();

        switch(opcFun){
            case 1: imprimeLista(listaSequencial, numEle);
                    numItera++;
                    printf("\n\n");
                    break;

            case 2: addFinal(listaSequencial, &numEle);
                    numItera++;
                    break;

            case 3: addMeio(listaSequencial, numEle);
                    numItera++;
                    numEle++;
                    break;

            case 4: addIni(listaSequencial, numEle);
                    numItera++;
                    numEle++;
                    break;

            case 5: removeItem(listaSequencial, numEle);
                    numItera++;
                    numEle--;
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
        }
    }

}
