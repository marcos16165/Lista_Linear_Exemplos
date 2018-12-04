/*
    * Projeto: Fila de Inteiros
    * Autor: Joyce Claine e Marcos Monteiro 
    * Dados: 25/11/2018
    * Versão: 1.1
    * Data da última modificação: 30/11/2018
    * Descrição: Exemplo simpres de fila.
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

typedef struct fila
{
	No *primeiro;
	No *ultimo;
	int tam;
} Fila;


void inicializaFila(Fila *f)
{
	f->primeiro = NULL;
	f->ultimo = NULL;
}

Fila *inserirFila(Fila *f, int k)
{
	No *novo;
	novo = new No;
	novo->info = k;
	
	if (f->primeiro == NULL){
		 f->primeiro = novo;
		 f->ultimo = novo; 
		 novo->prox = NULL; 
		 f->tam ++;	
	}
	else
	{
		novo->prox = f->ultimo->prox;
        f->ultimo->prox = novo;
        f->ultimo = novo; 
	}		
	return f;
}

int FilaVazia(Fila *f)
{
	return f->primeiro == NULL; // Se o inicio apontar para NULL, entao Fila está vazia
}

Fila *removerFila(Fila *f)
{
	No *aux;
	aux = f->primeiro;

	if(aux == NULL)
		cout << "\nFila vazia!" << endl;
	else
	{
		f->primeiro = aux->prox;
		free(aux);
		f->tam --;
	}
	return f;
}

void mostrarFila(Fila *f)
{
	No *copia;
	copia = f->primeiro;
	int cont = 1;
	if (copia == NULL)
	{
		cout << "\nFila vazia!" << endl;
	}
	else
	{
		while(copia != NULL)
		{
			cout << "\nFila[" << cont << "]= " << copia->info << endl;
			copia = copia->prox;
			cont++;
		}
	}

}

void menu()
{
	cout << "\n****** MENU ******\n";
	cout << "1 - Inserir\n";
	cout << "2 - Remover\n";
	cout << "3 - Mostrar\n";
	cout << "0 - Sair\n";
	cout << "******************\n";	
}

int main()
{
	char N;//Variável para voltar para o menu inicial
	Fila *F1;
	F1 = new Fila;
	int op;
	int v;
	inicializaFila(F1);
		
	do
	{		
		menu();
		
		cout << "\nDigite a opcao desejada: ";
		cin >> op;
				
		switch(op)
		{

		case 1:
			// insere();
			system("cls || clear");
			cout << "\nValor que deseja inserir: ";
			cin >> v;
			inserirFila(F1,v);
			system("cls || clear");
			break;

		case 2:
			//Remover();
			removerFila(F1);
			cout << endl;
			cout <<"Removido com sucesso!" << endl;
			system("cls || clear");
			break;

		case 3:
			//Mostrar();
			system("cls || clear");
			mostrarFila(F1);
			cout<<"\nPressione qualquer tecla para limpar e retornar para o menu: ";
			cin>>N;
			system("cls || clear");
			break;
		}
	}
	while(op != 0);

	return 0;
}
