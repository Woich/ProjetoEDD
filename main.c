#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "ListaSequencial.h"
#include "ListaEncadeada.h"
#include "Organizacao.h"
#include "OrganizacaoEncad.h"

int numItera = 4;
int numCopias = 0;

int main(){
    int opcLista;


    while(opcLista != 1 && opcLista != 2){
        printf("Qual lista? \n(1)Sequencial \n(2)Encadeada\n(3)Número de if's\n");
        scanf("%d", &opcLista);
        getchar();

        if(opcLista == 1){
            mainSequencial();
        }
        else if(opcLista == 2){
            mainListaEncadeada();
        }
        else if(opcLista == 3){
            printf("\nNúmero IF'S: %d\n\n", numItera);
        }
        else{
            printf("\nOpcao nao valida, por favor digite noamente\n");
        }
    }
}
