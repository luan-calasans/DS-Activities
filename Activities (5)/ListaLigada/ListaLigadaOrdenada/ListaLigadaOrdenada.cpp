#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

NO* posicaoElemento(int numero)
{
	NO* anterior = NULL;
	NO* atual = primeiro;
	while (atual != NULL && atual->valor < numero)
	{
		anterior = atual;
		atual = atual->prox;
	}

	if (atual != NULL && atual->valor == numero)
	{
		return atual;
	}
	else
	{
		return NULL;
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL)
	{
		// se a lista estiver vazia, o novo elemento sera o primeiro
		primeiro = novo;
	}
	else if (novo->valor < primeiro->valor)
	{
		// se o novo elemento for menor que o primeiro, ele sera o novo primeiro
		novo->prox = primeiro;
		primeiro = novo;
	}
	else
	{
		// procura a posicao de insercao na lista
		NO* anterior = primeiro;
		NO* atual = primeiro->prox;
		while (atual != NULL && atual->valor < novo->valor)
		{
			anterior = atual;
			atual = atual->prox;
		}

		// verifica se o novo elemento nao e duplicado
		if (atual != NULL && atual->valor == novo->valor)
		{
			cout << "Elemento ja existe na lista \n";
			free(novo);
			return;
		}

		// insere o novo elemento na posicao correta
		anterior->prox = novo;
		novo->prox = atual;
	}
}

void excluirElemento()
{
	if (primeiro == NULL)
	{
		cout << "Lista vazia \n";
		return;
	}

	int numero;
	cout << "Digite o elemento a ser excluido: ";
	cin >> numero;

	NO* anterior = NULL;
	NO* atual = primeiro;
	while (atual != NULL && atual->valor != numero)
	{
		anterior = atual;
		atual = atual->prox;
	}

	if (atual == NULL)
	{
		cout << "Elemento nao encontrado na lista \n";
		return;
	}

	if (anterior == NULL)
	{
		// se o elemento a ser excluido for o primeiro, atualiza o primeiro
		primeiro = atual->prox;
	}
	else
	{
		anterior->prox = atual->prox;
	}

	free(atual);
	cout << "Elemento excluido com sucesso \n";
}

void buscarElemento()
{
	if (primeiro == NULL)
	{
		cout << "Lista vazia \n";
		return;
	}

	int numero;
	cout << "Digite o elemento a ser buscado: ";
	cin >> numero;

	NO* posicao = posicaoElemento(numero);
	if (posicao == NULL)
	{
		cout << "Elemento nao encontrado na lista \n";
	}
	else
	{
		cout << "Elemento encontrado na lista \n";
	}
}
