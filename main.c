/*Árvore de busca binária implementada em C
Autor: Cristofer Alexandre Oswald
Data: 18/07/2016 */

#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

int main(){
	int op = 1;
	arvore_t *a;

	while(op != 0){
		system(CLS);
		printf("Implementação de árvore binária de busca em C\n\n");
		printf("\t1 - Criar nova árvore || 2 - Inserir ficha || 3 - Buscar ficha\n\t4 - Exibir elementos  || 4 - Remover ficha || 0 - Sair\n\n");
		printf("Selecione o que deseja fazer: ");
		scanf(" %d", &op);
		switch(op){
			case 1:
				break;

			case 2:
				break;

			case 3:
				break;

			case 4:
				break;

			case 0:
				break;

			default:
				printf("Escolha inválida, digite novamente\n");
				system(SLEEP " 1");
				break;
	
		}
	}
	system(CLS);

	return 0;
}
