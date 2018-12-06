/*
    * Projeto: Fila de Inteiros
    * Autor:Marcos Monteiro 
    * Dados: 06/11/2018
    * Versão: 1.0
    * Data da última modificação: 06/11/2018
    * Descrição: Exemplo simpres de lista duplamente encadeada.
 		*Inserir No Inicio
		*Inserir No Final
		*Inserir Em Qualquer Lugar
		*Excluir no Inicio
		*Excluir no Final
		*Excluir em quelque lugar(ERRO)
		*Imprimir
*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct Reg
{
	int info;
	Reg *prox, *ant;
} No;

typedef struct Lista
{
	Reg *inicio, *fim;
	int tam;
} Dupla;

Dupla *inicializa(Dupla *LD)
{
	LD->inicio = LD->fim = NULL;
	LD->tam = 0;
	return LD;
}

int ListaVaziaLD(Dupla *LD)
{
	return ((LD->inicio == LD->fim) && (LD->tam == 0));
}

Dupla *insereInicio(Dupla *LD)
{
	int elemento;
	cout << "ESCOLHA O ELEMENTO QUE DESEJA INSERIR: ";
	cin >> elemento;
	No *novo;
	novo = new No;
	novo->info = elemento;
	novo->ant = NULL;
	if(ListaVaziaLD(LD))
	{
		novo->prox = NULL;
		LD->inicio = LD->fim = novo;
		LD->tam++;
	}
	else
	{
		novo->prox = LD->inicio;
		LD->inicio->ant = novo;
		LD->inicio = novo;
		LD->tam++;
	}
	return LD;
}

Dupla *insereFinal(Dupla *LD)
{
	int elemento;
	cout << "ESCOLHA O ELEMENTO QUE DESEJA INSERIR: ";
	cin >> elemento;

	No *novo;
	novo = new No;
	novo->info = elemento;
	novo->prox = NULL;
	if(ListaVaziaLD(LD))
	{
		novo->ant = NULL;
		LD->inicio = LD->fim = novo;
		LD->tam++;
	}
	else
	{
		novo->ant = LD->fim;
		LD->fim->prox = novo;
		LD->fim = novo;
		LD->tam++;
	}
	return LD;
}

Dupla *IserirQQL(Dupla *LD)
{
	int elemento;
	cout << "ESCOLHA O ELEMENTO QUE DESEJA INSERIR: ";
	cin >> elemento;
	No *novo;
	novo = new No;
	novo->info = elemento;
	int posicao;
	cout << "ESCOLHA A POSICAO QUE DESEJA INSERIR O ELEMENTO: " << endl;
	cin >> posicao;

	if(posicao == 1)
	{
		LD = insereInicio(LD);
	}
	else if(posicao > LD->tam)
	{
		LD = insereFinal(LD);
	}
	else
	{
		int aux = 0;
		No *copia;
		copia = LD->inicio;
		while(copia != NULL)
		{
			aux++;
			if(aux == posicao)
			{
				novo->prox = copia;
				novo->ant = copia->ant;
				copia->ant->prox = novo;
				copia->ant = novo;
				break;
			}
			copia = copia->prox;
		}
	}
	return LD;
}

Dupla *excluirInicio(Dupla *LD)
{
	No *CP;
	CP = LD->inicio;
	LD->inicio = CP->prox;
	CP->prox->ant = NULL;
	LD->tam--;
	delete CP;
	cout << " PRIMEIRO ELEMNTO DELETADO COM SUCESSO" << endl;
	return LD;
}

Dupla *excluirFinal(Dupla *LD)
{
	No *CP;
	CP = LD->fim;
	LD->fim = CP->ant;
	CP->ant->prox = NULL;
	LD->tam--;
	delete CP;
	cout << " ULTIMO ELEMNTO DELETADO COM SUCESSO" << endl;
	return LD;
}

// Dupla *ExcluirQQL(Dupla *LD, No *CP){
// 	CP->ant->prox = CP->prox;
// 	CP->prox->ant = CP->ant;
// 	LD->tam--;
// 	return LD;
// }


//ESTA FUNÇÂO ESTA APRESENTADO UM ERRO 
Dupla *excluirQQL(Dupla *LD)
{
	int val;
	cout << "INSIRA O ELEMENTO QUE DESEJA EXLUIR: ";
	cin >> val;
	No *CP;
	CP = LD->inicio;
	while((CP != NULL) && (CP->info != val))
	{
		if(CP == NULL)
		{
			cout << "O ELEMENTO NÂO FOI ENCONTRADO!" << endl;
		}
		else if((CP->ant == NULL) && (CP->prox != NULL))
		{
			excluirInicio(LD);
		}
		else if((CP->prox == NULL) && (CP->ant != NULL))
		{
			excluirFinal(LD);
		}
		else
		{
			if(CP->info == val)
			{
				CP->ant->prox = CP->prox;
				CP->prox->ant = CP->ant;
				LD->tam--;
			}
		}
		CP = CP->prox;
	}
	return LD;
}

void Imprime(Dupla *LD)
{
	No *copia;
	copia = LD->inicio;
	int cont = 1;
	if(ListaVaziaLD(LD))
	{
		cout << "A LISTA ESTA VAZIA!" << endl;
	}
	else
	{
		cout << "\n----- DADOS -----" << endl;
		while(copia != NULL)
		{
			cout << "[" << cont << "]:" << copia->info << endl;
			copia = copia->prox;
			cont++;
		}
		cout << "------------" << endl;
	}
}

void menu()
{
	cout << "\n****** MENU LISTA DUPLAMENTE ENCADEADA ******\n";
	cout << "1 - Inserir No Inicio\n";
	cout << "2 - Inserir No Final\n";
	cout << "3 - Inserir Em Qualquer Lugar\n";
	cout << "4 - Excluir no Inicio\n";
	cout << "5 - Excluir no Final\n";
	cout << "6 - Excluir em quelque lugar(ERRO)\n";
	cout << "7 - Imprimir\n";
	cout << "0 - Sair\n";
	cout << "******************\n";
}

int main()
{
	char N;//Variável para voltar para o menu inicial
	Dupla *LD;
	LD = new Dupla;
	int op;
	int v;
	LD = inicializa(LD);

	do
	{
		menu();

		cout << "\nDigite a opcao desejada: ";
		cin >> op;

		switch(op)
		{

		case 1:
			// insere no inicio();
			system("cls || clear");
			insereInicio(LD);
			system("cls || clear");
			break;

		case 2:
			// insere no final();
			system("cls || clear");
			insereFinal(LD);
			system("cls || clear");
			break;

		case 3:
			// insere em qualquer lugar();
			system("cls || clear");
			IserirQQL(LD);
			system("cls || clear");
			break;

		case 4:
			// excluir inicio();
			system("cls || clear");
			excluirInicio(LD);
			cout << "\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin >> N;
			system("cls || clear");
			break;

		case 5:
			// exluir no final();
			system("cls || clear");
			excluirFinal(LD);
			cout << "\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin >> N;
			system("cls || clear");
			break;

		case 6:
			// excluir em qualquer lugar();
			system("cls || clear");
			excluirQQL(LD);
			cout << "\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin >> N;
			system("cls || clear");
			break;

		case 7:
			//Remover();
			system("cls || clear");
			Imprime(LD);
			cout << "\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin >> N;
			system("cls || clear");
			break;
		}
	}
	while(op != 0);

	return 0;
}
