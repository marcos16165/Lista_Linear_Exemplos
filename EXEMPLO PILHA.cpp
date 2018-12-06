/*
    * Projeto: Fila de Inteiros
    * Autor: Marcos Monteiro 
    * Dados: 30/11/2018
    * Versão: 1.0
    * Data da última modificação: 30/11/2018
    * Descrição: Exemplo simpres de pilha.
		*Inserir 
    	*Remover
    	*Buscar
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct Reg
{
	int info;
	Reg *prox;
} No;

typedef struct TipoPilha
{
	No * Topo;
	int tamanho;
} Pilha;

Pilha *IniciaPilha(Pilha *PL)
{
	PL->Topo = NULL;
	PL->tamanho = 0;
	return PL;
}

int PilhaVazia(Pilha *PL)
{
	return(PL->Topo == NULL);
}

Pilha *Empilhar(Pilha *PL, int k)
{
	No *novo;
	novo = new No;
	novo->info = k;
	novo->prox = PL->Topo;
	PL->Topo = novo;
	PL->tamanho++;
	return PL;
}

Pilha *Desempilhar(Pilha *PL)
{
	No *aux;
	int sai;
	if (PilhaVazia(PL))
		cout << "\nA PILHA ESTA VAZIA!" << endl;
	else
	{
		aux = PL->Topo;
		PL->Topo = aux->prox;
		sai = aux->info;
		cout <<"\n"<< sai << " Retirando da pilha com sucesso! " << endl;
		PL->tamanho--;
		delete aux;
	}
	return PL;
}

void ImprimirPilha(Pilha *PL)
{
	No *copia;
	copia = PL->Topo;
	int cont = 1;
	if(PilhaVazia(PL))
		cout << "PILHA VAZIA!" << endl;
	else
		while (copia != NULL)
		{
			cout << "PILHA[" << cont << "]=" << copia->info << endl;
			copia = copia->prox;
			cont++;
		}
}

void menu()
{
	cout << "\n****** MENU PILHA ******\n";
	cout << "1 - Inserir\n";
	cout << "2 - Remover\n";
	cout << "3 - Mostrar\n";
	cout << "0 - Sair\n";
	cout << "******************\n";
}

int main()
{
	char N;//Variável para voltar para o menu inicial
	Pilha *PL;
	PL = new Pilha;
	int op, v;
	IniciaPilha(PL);

	do
	{
		menu();

		cout << "\nDigite a opcao desejada: ";
		cin >> op;

		switch(op)
		{

			//===== OPCAO 1 CADASTRO =====
		case 1:
			system("cls || clear");
			cout << "\nValor que deseja inserir: ";
			cin >> v;
			Empilhar(PL, v);
			system("cls || clear");
			break;

			//===== OPCAO 2 EXCLUIR =====
		case 2:
			system("cls || clear");
			Desempilhar(PL);
			cout << endl;
			cout << "\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin >> N;
			system("cls || clear");
			break;
		
			//===== OPCAO 3 CONSULTAR =====
		case 3:
			system("cls || clear");
			ImprimirPilha(PL);
			cout << "\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin >> N;
			system("cls || clear");
			break;
		}
	}
	while(op != 0);

	return 0;
}

