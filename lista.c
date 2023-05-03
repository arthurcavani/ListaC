#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"



int main(){
    int alt = -1;
	tLista lista;
	inicializar(&lista);
	menu:
    int opcao;
    system("cls");
	printf("\n[1]  - Carregar arquivo");
	printf("\n[2]  - Salvar arquivo");
	printf("\n[3]  - Adicionar cliente");
	printf("\n[4]  - Alterar cliente");
	printf("\n[5]  - Excluir cliente");
	printf("\n[6]  - Pesquisa Cod.");
	printf("\n[7]  - Pesquisa Nome");
	printf("\n[8]  - Relatorio ordenado por Cod.");
	printf("\n[9]  - Relatorio ordenado por Nome");
	printf("\n[10] - Relatorio ordenado por Total Vendas");
	printf("\n[0] - Sair");
	printf("\nOpcao: ");
	scanf("%i", &opcao);
	
if (opcao>1 && opcao<11 && alt!=1){
	system("cls");
	printf("\nBanco ainda nao foi carregado...\n");
	system("pause");
	goto menu;
}

if (opcao>10 || opcao<0){
	system("cls");
	printf("\nOpcao invalida...\n");
	system("pause");
	goto menu;
}

	switch(opcao)
	{
		case 1:
		{
		system("cls");
		inicializar(&lista);
		carregar(&lista);
		alt = 1;
		goto menu;
		}

		case 2:
		{
		 
		system("cls");
		salvar(&lista);
		inicializar(&lista);
		carregar(&lista);
	goto menu;
		}

        case 3:
		{
		system("cls");
		inserir(&lista);
			goto menu;	
		}		
		
	case 4:
		{
		system("cls");
		alterar(&lista);
		goto menu;
	}
	
		case 5:
		{system("cls");
		remover(&lista);
		goto menu;
			
	}
	
		case 6:
		{system("cls");
		pesquisarcod(&lista);
		goto menu;
			
	}
	
		case 7:
		{system("cls");
		pesquisarnome(&lista);
		goto menu;
			
	}
	
		case 8:
		{system("cls");
		relcod(&lista);
		goto menu;
			
	}
	
		case 9:
		{system("cls");
		relnome(&lista);
		goto menu;
			
	}
	
	case 10:
		{system("cls");
		formatar(&lista);
		reltotal(&lista);
		goto menu;
			
	}
	
		case 0:
		{
					exit(0);
				}
		
	}
		
	
	


}
