#include "funcionario.h"
#include "dinheiro.h"
#include "slot.h"
#include <algorithm>
#include <locale>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;


void imprimir_produtos(slot* maquina, int numSlots)
{
	cout << "	1.  Por ordem alfabética" << endl;
	cout << "	2.  Por preço" << endl;
	cout << "	3.  Por quantidade disponível" << endl;
	cout << "Escolha a sua opção: ";
	int opcao;
	cin >> opcao;
	cout << endl;

	// arrays usados no sort (para não mexer em maquina)
	float* precos = new float[numSlots];
	string* produtos = new string[numSlots];
	int* quantidades = new int[numSlots];

	for (int i = 0; i < numSlots; i++) {
		precos[i] = maquina[i].p.preco;
		produtos[i] = maquina[i].p.name;
		quantidades[i] = maquina[i].quantidade;
	}

	bool swapped = true;

	switch (opcao) {
		// usando bubble sorts
	case 1:
		// ordenado alfabéticamente
		for (int i = 0; i < numSlots - 1 && swapped; i++) {
			swapped = false; 
			for (int j = numSlots - 1; j > i; j--) {
				if (produtos[j] < produtos[j-1]) {
					swap(produtos[j], produtos[j-1]);
					swapped = true;
				}
			}
		}
		break;
	case 2:
		// ordenado pelo preço
		for (int i = 1; i < numSlots - 1 && swapped; i++) {
			swapped = false;
			for (int j = numSlots - 1; j > i; j--) {
				if (precos[j] < precos[j-1]) {
					swap(precos[j], precos[j-1]);
					swap(produtos[j], produtos[j-1]);
					swapped = true;
				}
			}
		}
		break;
	case 3:
		// ordenado pela quantidade disponível
		for (int i = 1; i < numSlots - 1 && swapped; i++) {
			swapped = false;
			for (int j = numSlots - 1; j > i; j--) {
				if (quantidades[j] < quantidades[j-1]) {
					swap(quantidades[j], quantidades[j-1]);
					swap(produtos[j], produtos[j-1]);
					swapped = true;
				}
			}
		}
		break;
	default:
		cout << "Escolheu uma opção inválida. Voltando para o menu anterior." << endl;
		break;
	}

	// Print da lista ordenada
	if (opcao == 1 || opcao == 2 || opcao == 3) {
		for (int i = 0; i < numSlots; i++) {
			if (produtos[i] != "Vazio") {
				cout << produtos[i] << endl;
			}
			// cout << precos[i] << endl;
			// cout << quantidades[i] << endl;
		}
	}

	delete[](produtos);
	delete[](precos);
	delete[](quantidades);
	cout << endl;
}

void alterar_preco(slot* maquina, int numSlots) 
{
	string produtoInserido;
	float novoPreco = 0.01;
	cout << "\nQual é o produto cujo preço deseja alterar?" << endl;
	cin.ignore(); // para limpar lixo que esteja no input

	int posProduto = -1;
	while (posProduto < 0) {
		getline(std::cin, produtoInserido); // ler a linha -- é porcausa disto que precisamos do cin.ignore()
		for (int i = 0; i < numSlots; i++)
		{
			if (produtoInserido == maquina[i].p.name)
			{
				posProduto = i;
				break;
			}
		}
		if (posProduto < 0) {
			cout << "Produto inserido não foi encontrado na máquina. Por favor tente de novo." << endl;
		}
	}

	cout << "O preço atual deste produto é: " << maquina[posProduto].p.preco << EURO << endl;
	cout << "Insira o preço desejado para este produto: " << endl;
	cin >> novoPreco;
	int res = round(novoPreco * 100);
	while (res % 5 != 0 || novoPreco < 0) {
		cout << "O preço inserido tem que ser positivo e múltiplo de 5 cêntimos. Tente de novo." << endl;
		cin >> novoPreco;
		res = round(novoPreco * 100);
	}

	// resultado
	maquina[posProduto].p.preco = novoPreco;
	for (int n = posProduto + 1; n < numSlots; n++) {
		if (produtoInserido == maquina[n].p.name) {
			maquina[n].p.preco = novoPreco;
		}
	}

	cout << "Preço do produto " << maquina[posProduto].p.name << " alterado com sucesso!" << endl;
}

void gravarMaquinaSlots(slot* maquina, int numSlots, string fileName) {
	fstream file;
	file.open(fileName, ios::out);
	if (file.is_open()) {
		for (int i = 0; i < numSlots; i++) {
			file << maquina[i].code << endl;
			file << maquina[i].p.name << endl;
			file << maquina[i].p.preco << endl;
			file << maquina[i].quantidade << endl;
			file << maquina[i].quantidadeMax << endl;
		}
		file.close();
	}
	else
		cout << "Erro ao abrir o ficheiro  guardadoSlots ." << endl;
}

void gravarMaquinanumSlots(slot* maquina, int numSlots, string fileName) {
	fstream file;
	file.open(fileName, ios::out);
	if (file.is_open()) {
		file << numSlots << endl;
		file.close();
	}
	else
		cout << "Erro ao abrir o ficheiro  guardadoNumslots ." << endl;
}

void gravarMaquinaMoedas(slot* maquina, string fileName, int moedas[]) {
	fstream file;
	file.open(fileName, ios::out);
	if (file.is_open()) {
		for (int j = 0; j < 6; j++) {
			file << moedas[j] << endl;
		}
		file.close();
	}
	else
		cout << "Erro ao abrir o ficheiro  guardadoMoedas ." << endl;
}

int carregarMaquinanumSlots(string fileName) {
	ifstream myFile(fileName);
	string line = "";
	if (myFile.is_open())  //verificar se o ficheiro existe
		getline(myFile, line);
	myFile.close();
	return stoi(line);
}

void carregarMaquinaMoedas(slot* maquina, string fileName, int moedas[]) {
	ifstream myFile(fileName);
	string line = "";
	int i = 0;
	if (myFile.is_open()) {  //verificar se o ficheiro existe
		while (getline(myFile, line)) {
			const char* data = line.c_str();
			moedas[i] = stoi(data);
			i++;
		}
	}
	myFile.close();
}

void carregarMaquinaSlots(slot* maquina, int numSlots, string fileName) {
	ifstream myFile(fileName);
	string line = "";
	if (myFile.is_open()) {
		for (int i = 0; i<numSlots ; i++) {
			getline(myFile, line);
			const char* cstr = line.c_str();
			char* coding = const_cast<char*> (cstr);
			maquina[i].code = coding[0];
			getline(myFile, line);
			maquina[i].p.name = line;
			getline(myFile, line);
			maquina[i].p.preco = stof(line);
			getline(myFile, line);
			maquina[i].quantidade = stoi(line);
			getline(myFile, line);
			maquina[i].quantidadeMax = stoi(line);
		}
	}
	myFile.close();
}

void limparSlot(slot* maquina, int numSlots) {
	char c;
	cout << "Qual o slot para remover?" << endl;
	cin >> c;
	int posslot = buscaPos(maquina, numSlots, c);
	if (posslot >= 0) {
		maquina[posslot].p.name = "Vazio";
		maquina[posslot].p.preco = 0;
		maquina[posslot].quantidade = 0;
		imprimeMaquina(maquina, numSlots);
		cout << "O slot foi limpado com sucesso!" << endl << endl;
	}
	else {
		cout << "Slot não encontrado. Retornando ao menu anterior." << endl << endl;
	}
}

void adicionarSlot(slot* maquinaslot, int numSlots) {
	char c;
	do {
		cout << "Indique a letra do slot a adicionar: " << endl;
		cin >> c;
		if (buscaPos(maquinaslot, numSlots, c) >= 0)
			cout << "Insira um código que não exista ainda. Por favor tente de novo." << endl;
	} while (buscaPos(maquinaslot, numSlots, c) >= 0);

	int capSlot;
	cout <<" Indique a capacidade do slot :" << endl;
	cin >> capSlot;

	//slot* maquinaslot = new slot[numSlots+1];
	/*for (int i = 0; i < numSlots; i++) {
		maquinaslot[i].p.name = maquina[i].p.name;
		maquinaslot[i].p.preco = maquina[i].p.preco;
		maquinaslot[i].quantidade = maquina[i].quantidade;
		maquinaslot[i].code = maquina[i].code;
		maquinaslot[i].quantidadeMax = maquina[i].quantidadeMax;
	}*/

	maquinaslot[numSlots].code = c;
	maquinaslot[numSlots].quantidadeMax = capSlot;
	maquinaslot[numSlots].p.name = "Vazio";
	maquinaslot[numSlots].p.preco = 0;
	maquinaslot[numSlots].quantidade = 0;
}


void limparMaquina(slot* maquina, int numSlots) {
	for (int i = 0; i < numSlots; i++) {
		maquina[i].p.name = "Vazio";
		maquina[i].p.preco = 0;
		maquina[i].quantidade = 0;
	}
	cout << "A maquina foi limpada com sucesso!" << endl;
	cout << endl;
}

void adicionarProduto(slot* maquina, int numSlots) {
	char slot;
	int num;
	string nome;

	// verificação do código do slot
	do {
		cout << "Qual o código do slot para adicionar um produto?" << endl;
		cin >> slot;
		if (buscaPos(maquina, numSlots, slot) < 0) {
			cout << "Código de slot não presente na máquina." << endl;
		}
	} while (buscaPos(maquina, numSlots, slot) < 0);
	cout << endl;
	int posicao = buscaPos(maquina, numSlots, slot);

	// input do número de produtos
	cout << "Qual o número de produtos a repor?" << endl;
	cin >> num;
	cout << endl;


	// NOTA: Este bloco de código tem o propósito de escrever os produto do ficheiro produto.txt.
	// Mas, o utilizador pode inserir qualquer produto, mesmo que não esteja no produtos.txt; 
	// Logo, este bloco de código ficará comentado para referência futura/debugging.
	/*
	// verificar se o nome do produto inserido é coerente com o produtos.txt
	string* listaprodutos = new string[NUM_PRODUTOS];
	lerFicheiroProdutos(listaprodutos);
	cout << "\n** Lista de produtos possíveis **" << endl;
	cout << " -> | ";
	for (int i = 0; i < NUM_PRODUTOS; i++) {
		cout << listaprodutos[i] << " | ";
	}
	cout << endl << endl;
	
	cin.ignore(); // limpa a consola para nao repetir infinitamente
	bool existeProduto = false;
	do {
		cout << "Qual o nome do produto a adicionar?" << endl;
		getline(std::cin, nome);

		for (int i = 0; i < NUM_PRODUTOS; i++) {
			if (nome == listaprodutos[i]) {
				existeProduto = true;
			}
		}
		if (!existeProduto) {
			cout << "Produto não reconhecido. Por favor introduza outro produto." << endl;
		}
		else if (nome != maquina[posicao].p.name && (maquina[posicao].p.name != "Vazio") ) {
			cout << "Nome do produto inserido não corresponde ao nome do produto neste slot." << endl;
		}
	} while (!existeProduto || (nome != maquina[posicao].p.name && maquina[posicao].p.name != "Vazio") );

	delete[](listaprodutos); */

	cin.ignore(); // limpa a consola para nao repetir infinitamente
	do {
		cout << "Qual o nome do produto a adicionar?" << endl;
		getline(std::cin, nome);
		if (nome != maquina[posicao].p.name && (maquina[posicao].p.name != "Vazio")) {
			cout << "Nome do produto inserido não corresponde ao nome do produto neste slot. Tente denovo." << endl;
		}
	} while (nome != maquina[posicao].p.name && maquina[posicao].p.name != "Vazio");

	cout << endl;

	// decidindo o que fazer com os produtos inseridos
	if (maquina[posicao].quantidadeMax >= maquina[posicao].quantidade + num) {
		maquina[posicao].p.preco = precoDesteProduto(maquina, numSlots, nome);
		maquina[posicao].p.name = nome;
		maquina[posicao].quantidade += num;
	}
	else {
		int escolhafunc = -1;
		do {
			cout << "1. Para alterar o tamanho do slot para poderem caber os produtos adicionados" << endl;
			cout << "2. Para adicionar o produto até à quantidade máxima do slot" << endl;
			if (temVazio(maquina, numSlots)) {
				cout << "3. Inserir os produtos a mais num slot que esteja vazio" << endl;
			}
			cin >> escolhafunc;
			if (!((temVazio(maquina, numSlots) && escolhafunc == 3) || escolhafunc == 2 || escolhafunc == 1)) {
				cout << "Por favor insira uma opção definida." << endl;
			}
		} while ( !((temVazio(maquina, numSlots) && escolhafunc == 3) || escolhafunc == 2 || escolhafunc == 1) );
		switch (escolhafunc)
		{
		case 1:
			maquina[posicao].quantidadeMax = maquina[posicao].quantidade + num;
			maquina[posicao].quantidade += num;
			break;
		case 2:
			num = maquina[posicao].quantidadeMax - maquina[posicao].quantidade;
			maquina[posicao].quantidade += num;
			break;
		case 3:
			//um a um, vai aumentar a quantidade até chegar ao máximo
			while (maquina[posicao].quantidadeMax != maquina[posicao].quantidade && num!=0) {
				num = num - 1;
				maquina[posicao].quantidade += 1;
			}
			//o resto  do num vai para o slot vazio
			for (int i = 0; i < numSlots; i++) {
				if (maquina[i].p.name == "Vazio") {
					while (maquina[i].quantidadeMax != maquina[i].quantidade && num != 0) {
						num = num - 1;
						maquina[i].quantidade += 1;
					}
					maquina[i].p.name = nome;
					maquina[i].p.preco = precoDesteProduto(maquina, numSlots, nome);
				}
			}
			break;
		}
	}
	cout << "Produto adicionado com sucesso!" << endl;
}


void menu_funcionario(slot* maquina,int moedas[6], int numSlots) //Por favor vejam se altera alguns codigos!!! PQ ADICIONEI OUTRO ARGUMENTO!!!!
{
	bool sair = false;
	while (!sair) {
		int escolha_funcionario;
		cout << "\n******* Bem-Vindo Funcionário *******" << endl;
		cout << "1. Limpar slot" << endl;
		cout << "2. Limpar máquina" << endl;
		cout << "3. Adicionar produto" << endl;
		cout << "4. Alterar preço(s)" << endl;
		cout << "5. Adicionar slot" << endl;
		cout << "6. Carregar moedas" << endl;
		cout << "7. Imprimir produtos" << endl;
		cout << "8. Gravar máquina" << endl;
		cout << "9. Carregar máquina" << endl;
		cout << "10. Remover trocos" << endl;
		cout << "0. Voltar" << endl;
		cout << "Digite a sua opção: " << endl;

		cin >> escolha_funcionario;

		if (escolha_funcionario == 1) {
			cout << "Escolheu limpar slot! " << endl;
			limparSlot(maquina, numSlots);
		}
		else if (escolha_funcionario == 2) {
			cout << "Escolheu limpar a máquina! " << endl;
			limparMaquina(maquina,numSlots);
			imprimeMaquina(maquina, numSlots);
		}
		else if (escolha_funcionario == 3) {
			cout << "Escolheu adicionar produto! " << endl;
			adicionarProduto(maquina, numSlots);
			imprimeMaquina(maquina, numSlots);
		}
		else if (escolha_funcionario == 4) {
			cout << "Escolheu alterar preço(s)! " << endl;
			alterar_preco(maquina, numSlots);
			imprimeMaquina(maquina, numSlots);
		}
		else if (escolha_funcionario == 5) {
			cout << "Escolheu adicionar slot! " << endl;
			adicionarSlot(maquina, numSlots);
			::numSlots += 1; // atualização da variável global
			numSlots += 1; // atualização da variável local
			imprimeMaquina(maquina, numSlots);
		}
		else if (escolha_funcionario == 6) {
			cout << "Escolheu carregar moedas! " << endl;
			carregar_moedas(moedas);
		}
		else if (escolha_funcionario == 7) {
			cout << "Escolheu imprimir produtos! " << endl;
			imprimir_produtos(maquina, numSlots);
		}
		else if (escolha_funcionario == 8) {
			cout << "Escolheu gravar máquina" << endl;
			gravarMaquinaSlots(maquina, numSlots, "guardadoSlots.txt");
			gravarMaquinanumSlots(maquina, numSlots, "guardadoNumslots.txt");
			gravarMaquinaMoedas(maquina,"guardadoMoedas.txt",moedas);
		}
		else if (escolha_funcionario == 9) {
			cout << "Escolheu carregar máquina! " << endl;

			::numSlots = carregarMaquinanumSlots("guardadoNumslots.txt"); // atualização da variável global
			numSlots = carregarMaquinanumSlots("guardadoNumslots.txt"); // atualização da variável local

			carregarMaquinaMoedas(maquina, "guardadoMoedas.txt", moedas);
			carregarMaquinaSlots(maquina, numSlots, "guardadoSlots.txt");
			imprimeMaquina(maquina, numSlots);
		}
		else if (escolha_funcionario == 10) {
			cout << "Escolheu remover trocos! " << endl;
			remover_fundos(moedas);
		}
		else if (escolha_funcionario == 0) {
			cout << "Escolheu voltar! " << endl;
			sair = true;
		}
		else
			cout << "Por favor digite uma opção válida!";

		verificarFundos(moedas);
	}
}
