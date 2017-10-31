#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"

void selecSortEncad(ListaHeader *lista, ListaEncad **vetorPont){
    long int i, j;//contadores para o 'for'
    ContTempo temFuncao;//Função
    ListaEncad *pontAux;//Ponteiro auxiliar para troca de elementos

    temFuncao.temIni = time(NULL);
    numCopias=0;
    numItera=0;

    for(i=0 ; i<lista->qtdElementos ; i++){

        numItera++;

        for(j=i+1 ; j<lista->qtdElementos ; j++){
            numItera++;

            if(vetorPont[j]->rg < vetorPont[i]->rg){
                numItera++;

                //Atribui valor para o auxiliar
                pontAux = vetorPont[i];
                numCopias++;

                //Troca valor de vetorPont[i]
                vetorPont[i] = vetorPont[j];
                numCopias++;

                //troca valor de vetorPont[j]
                vetorPont[j] = pontAux;
                numCopias++;

            }
        }

    }

    //Esse for serve para arrumas todas as referencias de todos os pontos do vetor
    for(i=0 ; i<lista->qtdElementos ; i++){
        numItera++;
        if(i == 0){
            numItera++;
            //Muda o primeiro elemento da lista
            lista->primeiro = vetorPont[i];
            numCopias++;

            vetorPont[i]->anterior = 0;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;
        }
        else if(i == lista->qtdElementos){
            numItera++;
            //Muda o ultimo elemento da lista
            lista->ultimo = vetorPont[i];
            numCopias++;

            vetorPont[i]->proximo = 0;

            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;
        }
        else{
            numItera++;
            //Altera os elemento do meio
            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;

        }

    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");


}

void bubbleSortEncad(ListaHeader *lista, ListaEncad **vetorPont){

    long int i, numAcoes = 1;// Controladores para o loops
    ListaEncad *pontAux;//Ponteiro Auxiliar
    ContTempo temFuncao;//Tempo da Função

    temFuncao.temIni = time(NULL);
    numCopias=0;
    numItera=0;

    while(numAcoes != 0){
        numAcoes = 0;

        for(i=0; i<lista->qtdElementos ; i++){
            numItera++;

            if(i!=lista->qtdElementos-1 && vetorPont[i]->rg > vetorPont[i+1]->rg){
                numItera++;
                numAcoes++;

                //Atribui valor para o auxiliar
                pontAux = vetorPont[i];
                numCopias++;

                //Troca valor de vetorPont[i]
                vetorPont[i] = vetorPont[i+1];
                numCopias++;

                //troca valor de vetorPont[j]
                vetorPont[i+1] = pontAux;
                numCopias++;

            }
        }
    }

    //Esse for serve para arrumas todas as referencias de todos os pontos do vetor
    for(i=0 ; i<lista->qtdElementos ; i++){
        numItera++;
        if(i == 0){
            numItera++;
            //Muda o primeiro elemento da lista
            lista->primeiro = vetorPont[i];
            numCopias++;

            vetorPont[i]->anterior = 0;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;
        }
        else if(i == lista->qtdElementos){
            numItera++;
            //Muda o ultimo elemento da lista
            lista->ultimo = vetorPont[i];
            numCopias++;

            vetorPont[i]->proximo = 0;

            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;
        }
        else{
            numItera++;
            //Altera os elemento do meio
            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;

        }
    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");

}

void insertionSortEncad(ListaHeader *lista, ListaEncad **vetorPont){
    long int i, j;//Controladores de loops
    ContTempo temFuncao;//Tempo da Função
    ListaEncad *pontAux;//Ponteiro Auxiliar

    temFuncao.temIni = time(NULL);
    numCopias=0;
    numItera=0;

    for(i=2 ; i<lista->qtdElementos ; i++){//'i' é o que secsiona os pedaços que serão avaliados
        for(j=0 ; j<i ; j++){//'j' é quem corre o vetor sendo limitado por 'i'
            if(vetorPont[i]->rg < vetorPont[j]->rg){
                numItera++;

                //Atribui valor para o auxiliar
                pontAux = vetorPont[i];
                numCopias++;

                //Troca valor de vetorPont[i]
                vetorPont[i] = vetorPont[j];
                numCopias++;

                //troca valor de vetorPont[j]
                vetorPont[j] = pontAux;
                numCopias++;
            }
        }
    }

    //Esse for serve para arrumas todas as referencias de todos os pontos do vetor
    for(i=0 ; i<lista->qtdElementos ; i++){
        numItera++;
        if(i == 0){
            numItera++;
            //Muda o primeiro elemento da lista
            lista->primeiro = vetorPont[i];
            numCopias++;

            vetorPont[i]->anterior = 0;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;
        }
        else if(i == lista->qtdElementos){
            numItera++;
            //Muda o ultimo elemento da lista
            lista->ultimo = vetorPont[i];
            numCopias++;

            vetorPont[i]->proximo = 0;

            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;
        }
        else{
            numItera++;
            //Altera os elemento do meio
            vetorPont[i]->anterior = vetorPont[i-1];
            numCopias++;

            vetorPont[i]->proximo = vetorPont[i+1];
            numCopias++;

        }
    }

    temFuncao.temFinal = time(NULL);
    temFuncao.tempo = difftime(temFuncao.temFinal, temFuncao.temIni);
    printf("\n Tempo da Funcao: %f segundos\n Numero Iteracoes:%d\n Numero Copias:%d", temFuncao.tempo, numItera, numCopias);
    printf("\n\n");
}

void quickSortEncad(ListaHeader *lista, ListaEncad **vetorPont, long int iniComp, long int fimComp){//Esse possui inicio e fim do vetor para limitadores
    long int i=iniComp, j=fimComp, pivo;//'i' e 'j' são controladores de loops, enquanto o pivo é uma medida para a organização
    ListaEncad *pontAux;//Ponteiro Auxiliar
    int meio;

    //Seleção do pivo
    meio = (i+j)/2;
    pivo = vetorPont[meio]->rg;
    //Enquanto i e j não coinciderem em valor continua rodando as trocas
    while(i < j){

        //Rodando o i
        while(vetorPont[i]->rg < pivo){
            i++;
            numItera++;
        }
        //Rodando o j
        while(vetorPont[j-1]->rg > pivo){
            j--;
            numItera++;
        }
        if(i < j){
            numItera++;

            //Atribui valor para o auxiliar
            pontAux = vetorPont[i];
            numCopias++;

            //Troca valor de vetorPont[i]
            vetorPont[i] = vetorPont[j-1];
            numCopias++;

            //troca valor de vetorPont[j]
            vetorPont[j-1] = pontAux;
            numCopias++;

            i++;
            j--;
        }

    }
    //Secção baseada no 'j'
    if(j > iniComp){
        quickSortEncad(lista, vetorPont, iniComp, j);
    }
    //Secção baseada no 'i'
    if(i< fimComp){
        quickSortEncad(lista, vetorPont, i, fimComp);
    }

}

void mergeSortEncad(ListaHeader *lista, ListaEncad **vetorPont, long int iniComp, long int fimComp){
    //Pega o meio da lista para fazer a divisão mais tarde
    long int meio, i, j, k;//Controladores de tamanho
    ListaEncad **vetorTemp;

    if(iniComp == fimComp){
        numItera++;
        return;
    }
    //Enquanto foi pissível ele faz a divisão das listas
    meio = (iniComp + fimComp)/2;
    mergeSortEncad(lista, vetorPont, iniComp, meio);
    mergeSortEncad(lista, vetorPont, meio+1, fimComp);

    //Inicia variaveis
    i = iniComp;
    j = meio+1;
    k = 0;

    //Inicia vetor temporario
    vetorTemp = malloc(sizeof(ListaEncad) * (fimComp-iniComp+1));

    while(i <= meio && j <= fimComp){


        if(vetorPont[i]->rg < vetorPont[j]->rg){
            vetorTemp[k] = vetorPont[i];
            i++;
            k++;
            numCopias++;
            numItera++;
        }
        else{
            vetorTemp[k] = vetorPont[j];
            j++;
            k++;
            numCopias++;
            numItera++;
        }

        numItera = numItera+2;

    }

    while(i<= meio){
        vetorTemp[k] = vetorPont[i];
        i++;
        k++;
        numCopias++;
        numItera++;
    }

    while(j<= fimComp){
        vetorTemp[k] = vetorPont[j];
        j++;
        k++;
        numCopias++;
        numItera++;
    }
    k=0;
    for(i=iniComp ; i<=fimComp ; i++){
        vetorPont[i]=vetorTemp[k];
        k++;
        numCopias++;
        numItera++;
    }
    free(vetorTemp);
}

void shellSortEncad(ListaHeader *lista, ListaEncad **vetorPont){
    long int i, j;//Controladores
    long int salto, tam;//tamanho do salto que deve ser dado, tamanho do vetor passado
    ListaEncad *auxilar;

    //inicializa variaveis
    tam = lista->qtdElementos;
    salto = 1;

    //Esse calculo foi criado com base em um estudo, faz a divisão inicial de 'x' em 'x', sendo selecionado com base no tamanho da lista
    while(salto<tam){
        salto = (salto)*3+1;
    }

    while(salto > 1){
        //Isso é necessesário para impedor que se pegue um valor acima dos quue existe, impede acesso a memória inexistente
        //Depois se usa apenas para reduzir o salto gradualmente
        salto /= 3;

        //Aqui se gera um valor para percorrer o vetor de traz para a frente, com o elemento inicial sendo um dos ultimos elementos da lista
        for(i=salto ; i<tam ; i++){
            numItera++;
            // se gera uma referencia para o auxiliar sendo o elemento base a ser avaliado
            auxilar = vetorPont[i];
            numCopias++;
            //se inicializa 'j' com a próxima posição após o 'i'
            j = i-salto;

            //Compara para ver se já foi todos os elementos daquela linha de saltos já foram usados e se os valor do rg salvo no ponteiro auxilar ainda continua menor
            //para poder colocar ele na sua posição "correta" naquele momento
            while(j >= 0 && auxilar->rg < vetorPont[j]->rg){
                numItera++;
                vetorPont[j+salto] = vetorPont[j];
                numCopias++;
                //Reduz o 'j' gradualmente
                j -= salto;
            }

            //Coloca a refereancia do inicial na sua posição "correta" no momento
            vetorPont[j+salto] = auxilar;
            numCopias++;

        }

    }

}

void pesquisaBinariaEncad(ListaHeader *lista, ListaEncad **vetorPont){

    long int posicao,//posição a ser avaliada
             inicio,//pisião inicial da lista ser avaliada
             fim;// posição final da lista a ser avaliada

    int rgBuscado=0;

    printf("Qual rg que voce procura?\n");
    scanf("%d", &rgBuscado);

    inicio=0;
    fim=lista->qtdElementos-1;

    while(inicio <= fim){
        posicao = (fim + inicio)/2;
            numItera++;
        //caso ache pare o loop
        if(vetorPont[posicao]->rg == rgBuscado){
            numItera++;
            break;
        }

        if(vetorPont[posicao]->rg > rgBuscado){
            numItera++;
            fim = posicao-1;
        }
        else{
            numItera++;
            inicio = posicao+1;
        }
    }

    if(inicio>fim){
        numItera++;
        printf("\n\n----RG nao encontrado----\n");
    }
    else{
        numItera++;
        printf("\n\nPosicao:%d \nRG:%d \nNome:%s\n\n", posicao, vetorPont[posicao]->rg, vetorPont[posicao]->nome);
    }

}
