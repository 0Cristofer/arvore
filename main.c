/*Árvore de busca binária implementada em C
Autor: Cristofer Alexandre Oswald e Bruno Cesar Puli Dala Rosa
Data: 18/07/2016 */

#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

int main(){
	int op = 1;
	ficha_t *ficha;
	arvore_t *node_rg, *node_cod, *treeRG, *treeCOD;
	treeRG = NULL;
	treeCOD = NULL;

	while(op != 0){
		//system(CLS);
		printf("Implementação de árvore binária de busca em C\n\n");
		printf("\t1 - Inserir ficha || 2 - Buscar ficha\n\t3 - Relatório || 4 - Remover ficha || 0 - Sair\n\n");
		printf("Selecione o que deseja fazer: ");
		scanf(" %d", &op);
		switch(op){
			case 1:
				ficha = malloc(sizeof(ficha_t));
				preenche(ficha);

				node_rg = malloc(sizeof(arvore_t));
				node_cod = malloc(sizeof(arvore_t));
				node_rg->info = ficha;
				node_cod->info = ficha;

				printf("InsereRG\n");
				insereRG(treeRG, node_rg);
				printf("insereCOD\n");
				insereCOD(treeCOD, node_cod);
				printf("fim\n");
				break;

			case 2:
				break;

			case 3:
				relatorioRG(treeRG);
				relatorioCOD(treeCOD);
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
