/*Árvore de busca binária implementada em C
Autor: Cristofer Alexandre Oswald e Bruno Cesar Puli Dala Rosa
Data: 20/07/2016 */

#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

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
    scanf("%[^\n]", &ficha->nome);

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
