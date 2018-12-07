/*
    * Projeto: Fila de Inteiros
    * Autor: Joyce Claine e Marcos Monteiro
    * Dados: 28/11/2018
    * Versão: 1.1
    * Data da ultima modificacao: 28/11/2018
    * Descrição: Agenda eletronica.
		*1. Inclussao de elementos em ordem alfabetica por nome;
		*2. Exclusao de elementos;
		*3. Consulta por nome;
		*4. Impressao de toda a agenda;
		*5. Edicao de conteudo.
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

//-----DECLARACAO DE ESTRUTURAS-----
//Estrutura da agenda
typedef struct dados
{
	char Nome[20];
	char Email[30];
	int Telefone;
} D1;

//Estrutura dos itens da LE(Lista Encadeada)
typedef struct reg
{
	D1 info;
	reg *prox;
	int tamanho;
} Agenda;

//Inicializando lista vazia
Agenda *inicializa(void)
{
	return NULL;
}

//Para testar se a lista esta vazia
int vazia(Agenda* A)
{
	if (A == NULL)
		return 1;//True
	else
		return 0;//False
}

//Cadastrar
Agenda *Insere(Agenda *A)
{
	Agenda  *novo;
	novo = new Agenda;
	cout << "\n----- ADICIONAR DADOS NA AGENDA ----- " << endl;
	cout << "NOME: ";
	cin.ignore();
	cin.getline(novo->info.Nome, 20);
	cout << "E-MAIL: ";
	cin.getline(novo->info.Email, 30);
	cout << "TELEFONE: ";
	cin >> novo->info.Telefone;
	novo->prox = A;
	A = novo;
	return A;
}

//consultar(buscar)
int buscarNome(Agenda *A, char Nome[20])
{
	Agenda *aux;
	for(aux = A; aux != NULL; aux = aux->prox)
	{
		if (strcmp(aux->info.Nome, Nome) == 0)
		{	
			cout << "----------------------------------\n";
			cout << "  NOME: " << aux->info.Nome <<endl;
			cout << "  E-MAIL: " << aux->info.Email	<<endl;
			cout << "  TELEFONE: " << aux->info.Telefone <<endl;
			cout << "----------------------------------\n";
			
			return 1;
		}
	}
	cout<<"\n----- Registro nao encontrado! -----\n";
	return 0;
}

//Excluir
Agenda *removerNome(Agenda *A, char Nome[20])
{
	Agenda *atual, *antes;
	if (A == NULL)
	{
		return NULL;
	}
	atual = A;
	antes = NULL;
	while (atual != NULL)
	{
		if (strcmp(atual->info.Nome, Nome) == 0)
			break;

		antes = atual;
		atual = atual->prox;
	}
	if (antes == NULL)
	{
		A = A->prox;
		cout << "\n----- Excluido com sucesso! -----" << endl;
		free(atual);
	}
	else if(atual != NULL)
	{
		antes->prox = atual->prox; //antes agora aponta para o elemento que sucede o atual
		cout << "\n----- Excluido com sucesso! -----" << endl;
		free(atual);
	}
	return A;
}

//editar(atualizar)
Agenda *editarNome(Agenda *A, char Nome[20])
{
	Agenda *aux;

	for(aux = A; aux != NULL; aux = aux->prox)
	{

		if (strcmp(aux->info.Nome, Nome) == 0)
		{
			int opCampo;
			do
			{
				cout << "\nQual campo deseja atualizar?\n";
				cout << "1 - Nome\n";
				cout << "2 - E-mail\n";
				cout << "3 - Telefone\n";
				cout << "Digite a opcao desejada: ";
				cin >> opCampo;

				if(opCampo == 1)
				{
					cout << "\nNome: ";
					cin.ignore();
					cin.getline(aux->info.Nome, 20);
				}
				else if(opCampo == 2)
				{
					cout << "\nE-mail: ";
					cin >> aux->info.Email;
				}
				else if(opCampo == 3)
				{
					cout << "\nTelefone: ";
					cin >> aux->info.Telefone;
				}
				else
				{
					cout << "\nOpcao Invalida!\n";
				}
			}
			while((opCampo != 1) && (opCampo != 2) && (opCampo != 3));

		}
	}
	free(aux);
	return A;
}

//Mostrar
void Imprimir(Agenda *A)
{
	Agenda *P;
	cout << "\n----- IMPRIMINDO DADOS DA AGENDA -----\n" << endl;
	for(P = A; P != NULL; P = P->prox)
	{
		cout << "NOME: " << P->info.Nome << endl;
		cout << "E-MAIL: " << P->info.Email << endl;
		cout << "TELEFONE: " << P->info.Telefone << endl;
		cout << "---------------------------------------\n";
	}
}

//Menu de opcoes
void menu()
{
	cout << "\n****** MENU ******\n";
	cout << "1 - CADASTRAR\n";
	cout << "2 - EXCLUIR\n";
	cout << "3 - CONSULTAR\n";
	cout << "4 - IMPRIMIR\n";
	cout << "5 - EDITAR\n";
	cout << "6 - SAIR\n";
	cout << "******************\n";
}

int main()
{
	int op;
	char N, nomeBusca[20];
	Agenda *A1;
	A1 = new Agenda;
	A1 = inicializa();

	do
	{
		menu();
		cout << "\nDIGITE UMA OPCAO: ";
		cin >> op;

		switch(op)
		{

			//===== OPCAO 1 CADASTRO =====
		case 1:
			system("cls || clear");
			A1 = Insere(A1);
			cout << "\n----- Contato Salvo -----" << endl;
			cout << "\nPressione qualquer tecla para retornar ao menu: ";
			cin >> N;
			system("cls || clear");
			break;

			//===== OPCAO 2 EXCLUIR =====
		case 2:
			system("cls || clear");
			cout << "\n----- EXCLUIR DADOS DA AGENDA ----- " << endl;
			cout << "\nDigite o nome que deseja excluir: ";
			cin.ignore();
			cin.getline(nomeBusca, 20);

			if (buscarNome(A1, nomeBusca))
			{
				A1 = removerNome(A1, nomeBusca);
				cout << "\nPressione qualquer tecla para retornar ao menu: ";
				cin >> N;
				system("cls || clear");
				break;
			}
			else{
				cout << "\nPressione qualquer tecla para retornar ao menu: ";
				cin >> N;
				system("cls || clear");
				break;
			}
			
			//===== OPCAO 3 CONSULTAR =====
		case 3:
			system("cls || clear");
			cout << "\n----- BUSCAR DADOS DA AGENDA ----- " << endl;
			cout << "\nDigite o nome que deseja buscar: ";
			cin.ignore();
			cin.getline(nomeBusca, 20);
			buscarNome(A1, nomeBusca);
			cout << "\nPressione qualquer tecla para retornar ao menu: ";
			cin >> N;
			system("cls || clear");
			break;

			//===== OPCAO 4 IMPRIMIR =====
		case 4:
			system("cls || clear");
			if(vazia(A1))
			{
				cout << "\nNENHUM CADASTRO ENCONTRADO!\n";
				cout << "\nPressione qualquer tecla para retornar ao menu: ";
				cin >> N;
				system("cls || clear");
				break;
			}
			else
			{
				Imprimir(A1);
				cout << "\nPressione qualquer tecla para retornar ao menu: ";
				cin >> N;
				system("cls || clear");
				break;
			}

			//===== OPCAO 5 EDITAR =====
		case 5:
			system("cls || clear");
			cout << "\n----- EDITAR DADOS DA AGENDA ----- " << endl;
			cout << "\nDigite o nome do contato: ";
			cin.ignore();
			cin.getline(nomeBusca, 20);

			if (buscarNome(A1, nomeBusca))
			{
				A1 = editarNome(A1, nomeBusca);
				cout << "\n----- Contato Atualizado! -----\n";
				cout << "\nPressione qualquer tecla para retornar ao menu: ";
				cin >> N;
				system("cls || clear");
				break;
			}
			else{
				cout << "\nPressione qualquer tecla para retornar ao menu: ";
				cin >> N;
				system("cls || clear");
				break;
			}
			default:
				if(op != 6)
					cout << "\nOpcao invalida\n";
			}
		}
		while(op != 6);
		return 0;
	}
