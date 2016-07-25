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
        printf("Código : %d\n%s , %d anos.\n", ficha->cod, ficha->nome, ficha->idade);
        if(ficha->sexo){
            printf("Do sexo feminino\n");
        } else{
            printf("Do sexo masculino\n");
        }
        printf("Portado do RG %d\n\n", ficha->rg);
    }
}

void insereRG(arvore_t **tree, arvore_t **a){
    if(*(tree) == NULL){
        (*a)->esq = NULL;
        (*a)->dir = NULL;
        *tree = *a;
    }
    else{
        if((*tree)->info->rg < (*a)->info->rg){
            insereRG(&(*tree)->dir, a);
        }
        else if((*tree)->info->rg > (*a)->info->rg){
            insereRG(&(*tree)->esq, a);
        }
        else{
            printf("RG igual, abortando, registro não inserido\n");
        }
    }
}

void insereCOD(arvore_t **tree, arvore_t **a){
    if(*(tree) == NULL){
        (*a)->esq = NULL;
        (*a)->dir = NULL;
        *tree = *a;
    }
    else{
        if((*tree)->info->cod < (*a)->info->cod){
            insereCOD(&(*tree)->dir, a);
        }
        else if((*tree)->info->cod > (*a)->info->cod){
            insereCOD(&(*tree)->esq, a);
        }
        else{
            printf("Código igual, abortando, registro não inserido\n");
        }
    }
}

arvore_t *minimo(arvore_t *tree){
    if(tree->esq != NULL){
        return minimo(tree->esq);
    }
    return tree;
}

void removeNoCOD(arvore_t **cod){
    if((*cod)->esq == NULL){
        arvore_t *temp;
        temp = (*cod);
        *cod = (*cod)->dir;
        free(temp);
    }
    else if((*cod)->dir == NULL){
        arvore_t *temp;
        temp = (*cod);
        *cod = (*cod)->esq;
        free(temp);
    }
    else{
        arvore_t *d;
        d = minimo((*cod)->dir);
        (*cod)->info = d->info;
        arvore_t *no = buscaCOD( (*cod)->dir, d->info->cod);
        removeNoCOD(&no);
    }
}

void removeNoRG(arvore_t **rg){
    arvore_t *temp;
    if((*rg)->esq == NULL){
        temp = (*rg)->dir;
        free((*rg));
        *rg = temp;
    }
    else if((*rg)->dir == NULL){
        temp = (*rg)->esq;
        free((*rg));
        *rg = temp;
    }
    else{
        arvore_t *d;
        d = minimo((*rg)->dir);
        (*rg)->info = d->info;
        arvore_t *no = buscaRG( (*rg)->dir, d->info->rg);
        removeNoRG(&no);
    }
}

void relatorioRG(arvore_t *tree){
    if(tree != NULL){
        relatorioRG(tree->esq);
        printa(tree->info);
        relatorioRG(tree->dir);
    }
}

void relatorioRG2(arvore_t *tree){
    if(tree != NULL){
        printa(tree->info);
        relatorioRG2(tree->esq);
        relatorioRG2(tree->dir);
    }
}

void relatorioCOD(arvore_t *tree){
    if(tree != NULL){
        relatorioCOD(tree->esq);
        printa(tree->info);
        relatorioCOD(tree->dir);
    }
}

void relatorioCOD2(arvore_t *tree){
    if(tree != NULL){
        printa(tree->info);
        relatorioCOD2(tree->esq);
        relatorioCOD2(tree->dir);
    }
}

arvore_t* buscaRG(arvore_t *tree, int rg){
    if(tree != NULL){
        if (tree->info->rg < rg){
             return buscaRG(tree->dir, rg);
        } else if (tree->info->rg > rg){
            return buscaRG(tree->esq, rg);
        } else{
            return tree;
        }
    } else{
        return NULL;
    }
}

arvore_t* buscaCOD(arvore_t *tree, int cod){
    if(tree != NULL){
        if (tree->info->cod < cod){
            printf("entrando dir\n");
            return buscaCOD(tree->dir, cod);
        } else if (tree->info->cod > cod){
            printf("entrando esq\n");
            return buscaCOD(tree->esq, cod);
        } else{
            return tree;
        }
    } else{
        return NULL;
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
