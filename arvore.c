/*Árvore de busca binária implementada em C
Autor: Cristofer Alexandre Oswald e Bruno Cesar Puli Dala Rosa
Data: 20/07/2016 */

#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

void printa(ficha_t *ficha){
    if(ficha == NULL){
        printf("ERRO! Ficha == NULL!\n");
    }
    else{
        printf("Código : %d\n %s\n%d anos.", ficha->cod, ficha->nome, ficha->idade);
        if(ficha->sexo){
            printf("Do sexo masculino\n");
        } else{
            printf("Do sexo feminino\n");
        }
        printf("Portado do RG %d\n\n", ficha->rg);
    }
}

void insereRG(arvore_t *tree, arvore_t *a){
    printf("morrerg\n");
    if(tree == NULL){
        tree = a;
        tree->esq = NULL;
        tree->dir = NULL;
    }
    else{
        if(tree->info->rg < a->info->rg){
            insereRG(tree->dir, a);
        }
        else if(tree->info->rg > a->info->rg){
            insereRG(tree->esq, a);
        }
        else{
            printf("RG igual, abortando, registro não inserido\n");
        }
    }
}

void insereCOD(arvore_t *tree, arvore_t *a){
    printf("morre\n");
    if(tree == NULL){
        fflush(stdout);
        printf("null");
        tree = a;
        tree->esq = NULL;
        tree->dir = NULL;
    }
    else{
        printf("n null\n");
        fflush(stdout);
            
        if(tree->info->cod < a->info->cod){
            printf("direita");
            fflush(stdout);

            insereCOD(tree->dir, a);
        }
        else if(tree->info->cod > a->info->cod){
            printf("esquerda");
            fflush(stdout);

            insereCOD(tree->esq, a);
        }
        else{
            printf("Código igual, abortando, registro não inserido\n");
        }
    }
    fflush(stdout);

}

void relatorioRG(arvore_t *tree){
    printf("relatorio\n");
    if(tree == NULL){
        printf("null\n");
    }
    if(tree->esq != NULL){
        relatorioRG(tree->esq);
    }

    printa(tree->info);

    if(tree->dir != NULL){
        relatorioRG(tree->dir);
    }
}

void relatorioCOD(arvore_t *tree){
    if(tree->esq != NULL){
        relatorioCOD(tree->esq);
    }

    printa(tree->info);

    if(tree->dir != NULL){
        relatorioCOD(tree->dir);
    }
}

void preenche(ficha_t *ficha){
    int aux;

    system(CLS);
    printf("Cadastrando uma nova ficha\n");

    do{
        printf("Insira o código: ");
        scanf("%d", &aux);
        if(aux <= 0) printf("Código inválido!\n");
    } while(aux <= 0);
    ficha->cod = aux;

    printf("Insira o nome: ");
    scanf(" %[^\n]", ficha->nome);

    do{
        printf("Insira a idade: ");
        scanf("%d", &aux);
        if(aux <= 0 || aux >= 150) printf("Idade inválida!\n");
    } while(aux <= 0 || aux >= 150);
    ficha->idade = aux;

    do{
        printf("Insira o sexo, 0 para masculino, 1 para feminino");
        scanf("%d", &aux);
        if(aux != 0 && aux != 1) printf("Sexo inválido!\n");
    } while(aux != 0 && aux != 1);
    ficha->sexo = aux;

    do{
        printf("Insira o RG: ");
        scanf("%d", &aux);
        if(aux <= 0) printf("RG inválido!\n");
    } while(aux <= 0);
    ficha->rg = aux;

    printf("Cadastrado completo!\n");
}
