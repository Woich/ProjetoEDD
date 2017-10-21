#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"

void addFinal(ListaPessoa *lisOper, int fim){
    numCopias++;/*Contador somado para cada cópia feita na função*/

    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    /*Pega o nome a tribui ao elemento do Vetor*/
    printf("Digite o nome:\n");
    scanf("%s",lisOper[fim].nome);
    getchar();
    /*Pega o rg a tribui ao elemento do Vetor*/
    printf("Digite o RG:\n");
    scanf("%i", &lisOper[fim].rg);
    getchar();

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);

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

void imprimeLista(ListaPessoa *pessoas, int tamList){
    numCopias++;/*Contador somado para cada cópia feita na função*/

    int j, numItem;
    ContTempo temFuncao;

    temFuncao.temIni = time(NULL);

    printf("\n\n");

    /*Roda lista e imprime o valor dela*/
    for(j=0 ; j<tamList ; j++){
        numItera++;
        numItem = j+1;
        printf("%i : %s , %i", numItem, pessoas[j].nome, pessoas[j].rg);
        printf("\n");
    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n\n", temFuncao.tempo);
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

    char *split, *linTemp, linIni[30];

    const char delimit[]=" .,;:";

    FILE *file = fopen("NomeRG1M.txt", "r");

    unsigned long int i=0;

    ListaPessoa **lista;

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
        case 1: file = fopen("NomeRG10.txt", "r");
                lista =malloc(10 * sizeof(lista));
                break;
        case 2: file = fopen("NomeRG50.txt", "r");
                lista =malloc(50 * sizeof(lista));
                break;
        case 3: file = fopen("NomeRG100.txt", "r");
                lista =malloc(100 * sizeof(lista));
                break;
        case 4: file = fopen("NomeRG1K.txt", "r");
                lista =malloc(1000 * sizeof(lista));
                break;
        case 5: file = fopen("NomeRG10K.txt", "r");
                lista =malloc(10000 * sizeof(lista));
                break;
        case 6: file = fopen("NomeRG1M.txt", "r");
                lista =malloc(1000000 * sizeof(lista));
                break;
        case 7: file = fopen("NomeRG100M.txt", "r");
                lista =malloc(11748444 * sizeof(lista));
                break;
    }

    fgets(linIni, 30, file);
    numCopias++;

    /*Copia a lista inteira enquanto não chegar o caracter de fim('\0')*/
     while(linIni[0] != '\0'){
            numItera++;

            numEle++;

            linTemp = linIni;
            numCopias++;

            split = strsep(&linTemp, delimit);
            numCopias++;

            for(j=0 ; j<30 ; j++){
                numItera++;
                lista[i].nome[j]=split[j];
                numCopias++;
            }

            split = strsep(&linTemp, delimit);
            numCopias++;

            lista[i].rg = atoi( split );
            numCopias++;

            linIni[0] = '\0';
            i++;
            fgets(linIni, 30, file);
            numCopias++;
    }

    fclose(file);

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
            case 1: imprimeLista(lista, numEle);
                    numItera++;
                    printf("\n\n");
                    break;

            case 2: addFinal(lista, numEle);
                    numItera++;
                    numEle++;
                    break;

            case 3: addMeio(lista, numEle);
                    numItera++;
                    numEle++;
                    break;

            case 4: addIni(lista, numEle);
                    numItera++;
                    numEle++;
                    break;

            case 5: removeItem(lista, numEle);
                    numItera++;
                    numEle--;
                    break;

            case 6: procuraRG(lista, numEle);
                    numItera++;
                    break;

            case 7: salvaLista(lista, opcArq, numEle);
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
