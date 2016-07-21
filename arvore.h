/*Arquivo header da implementação de árvore binária
Autor: Cristofer Alexandre Oswald
Data: 18/07/2016 */

#ifndef arvore
#define arvore

#define CLS "clear"
#define SLEEP "sleep"

typedef struct ficha ficha_t;
struct ficha{
	int cod, idade, rg;
	int sexo; //0 para homem, 1 para mulher
	char nome[80];
};

typedef struct arv arvore_t;
struct arv{
	arvore_t *dir, *esq;
	ficha_t *info;
};

void preenche(ficha_t *ficha);
void printa(ficha_t *ficha);
void insereRG(arvore_t *tree, arvore_t *a);
void insereCOD(arvore_t *tree, arvore_t *a);
void relatorioRG(arvore_t *tree);
void relatorioCOD(arvore_t *tree);


#endif
