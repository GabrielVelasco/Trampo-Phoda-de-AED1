/*
	Sera usado encadeamento circular
	cabecalho ira guardar a quantidade de soldados restantes

	inicio:
		criar lista
		ler nomes dos soldados ate EOF

*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"

int main(){
	time_t t;
	char nome_sld[20];
	List lst_soldados = _cria_lista();
	// lst aponta para o ultimo node(soldado)
	// entrada dos nomes
	// a cada node aloca um node
	printf("Digite os nomes dos soldados cercados:\n");
	while(scanf("%s", nome_sld) != EOF){
		if(_insere_soldado(&lst_soldados, nome_sld))
			printf("Soldado inserido com sucesso!\n");
		else
			printf("Erro ao inserir soldado na lista\n");
	}
	printf("Lista de soldados em volta da fogueira a beira da morte:\n");
	_printa_lista(lst_soldados);

	int pos, s;
	printf("\n1 - Iniciar contagem a partir do primeiro soldado da lista.\n");
	printf("2 - Iniciar contagem a partir de uma posição sorteada aleatoriamente da lista.\n");
	printf("3 - Iniciar contagem a partir de um soldado específico.\n");
	printf("Posicao para iniciar a contagem: ");
	scanf("%d", &pos);
	srand(time(0));

	switch(pos){
		case 1:
			s = (rand()%4) + 1;
			printf("\nContar [%d] soldado(s) a partir do primeiro(inclusive)\n", s);
			_contador_elimina(&lst_soldados, lst_soldados,s, 0, nome_sld);
			break;
	}
	_printa_lista(lst_soldados);

	return 0;
}