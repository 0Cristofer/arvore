/*Árvore de busca binária implementada em C
Autor: Cristofer Alexandre Oswald e Bruno Cesar Puli Dala Rosa
Data: 18/07/2016 */

#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

int main(){
	int op = 1;
	int op2;
	int input;
	ficha_t *ficha;
	arvore_t *node_rg, *node_cod, *treeRG, *treeCOD, *node;
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

				insereRG(&treeRG, &node_rg);
				insereCOD(&treeCOD, &node_cod);
				break;

			case 2:
				printf("Você deseja buscar por Código ou RG? (0 - Código / 1 - RG)\n");
				scanf("%d", &op2);
				if (op2) {
					printf("Insira o RG a ser procurado: ");
					scanf("%d", &input);
					node_rg = buscaRG(treeRG, input);

					if (node_rg != NULL) printa(node_rg->info);
					else printf("RG não encontrado!\n");
				}
				else {
					printf("Insira o Código a ser procurado: ");
					scanf("%d", &input);
					node_cod = buscaCOD(treeCOD, input);

					if (node_cod != NULL) printa(node_cod->info);
					else printf("Código não encontrado!\n");
				}
				break;

			case 3:
				printf("\t\t=== Relatório RG ===\n");
				relatorioRG(treeRG);

				printf("\t\t=== Relatório COD ===\n");
				relatorioCOD(treeCOD);
				break;

			case 4:
				printf("Você deseja remover por Código ou RG? (0 - Código / 1 - RG)\n");
				scanf("%d", &op2);

				if (op2) {
					printf("Insira o RG a ser excluído: ");
					scanf("%d", &input);
					node = buscaRG(treeRG, input);
				}
				else{
					printf("Insira o Código a ser excluído: ");
					scanf("%d", &input);
					node = buscaCOD(treeCOD, input);
				}

				ficha = node->info;
				removeNoCOD((&treeCOD), ficha->cod);
				removeNoRG((&treeRG), ficha	->rg);
				free(ficha);
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
