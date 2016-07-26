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

void removeNoCOD(arvore_t **tree, int cod){
    if((*tree) != NULL){
        if((*tree)->info->cod < cod){
            removeNoCOD(&(*tree)->dir, cod);
        }
        else{
            if((*tree)->info->cod > cod){
                removeNoCOD(&(*tree)->esq, cod);
            }
            else{
                if( ((*tree)->esq != NULL) && ((*tree)->dir != NULL) ){
                    arvore_t *no = minimo((*tree)->dir);
                    (*tree)->info = no->info;
                    removeNoCOD(&(*tree)->dir, (*tree)->info->cod);
                }
                else{
                    arvore_t **no = tree;
                    if((*tree)->esq != NULL){
                        (*tree) = (*tree)->esq;
                    }
                    else{
                        (*tree) = (*tree)->dir;
                    }
                    free((*no));
                }
            }
        }
    }
}

void removeNoRG(arvore_t **tree, int rg){
    if((*tree) != NULL){
        if((*tree)->info->rg < rg){
            removeNoRG(&(*tree)->dir, rg);
        }
        else{
            if((*tree)->info->rg > rg){
                removeNoRG(&(*tree)->esq, rg);
            }
            else{
                if( ((*tree)->esq != NULL) && ((*tree)->dir != NULL) ){
                    arvore_t *no = minimo((*tree)->dir);
                    (*tree)->info = no->info;
                    removeNoRG(&(*tree)->dir, (*tree)->info->rg);
                }
                else{
                    arvore_t **no = tree;
                    if((*tree)->esq != NULL){
                        (*tree) = (*tree)->esq;
                    }
                    else{
                        (*tree) = (*tree)->dir;
                    }
                    free((*no));
                }
            }
        }
    }
}

void relatorioRG(arvore_t *tree){
    if(tree != NULL){
        relatorioRG(tree->esq);
        printa(tree->info);
        relatorioRG(tree->dir);
    }
}

void relatorioCOD(arvore_t *tree){
    if(tree != NULL){
        relatorioCOD(tree->esq);
        printa(tree->info);
        relatorioCOD(tree->dir);
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
            return buscaCOD(tree->dir, cod);
        } else if (tree->info->cod > cod){
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
