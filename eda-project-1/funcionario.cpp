#include "funcionario.h"
#include "dinheiro.h"
#include "slot.h"
#include <algorithm>
#include <locale>
#include <iostream>
#include <fstream>
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
	case 1:
		// ordenado alfabéticamente
		sort(produtos, produtos + numSlots);
		break;
	case 2:
		// ordenado pelo preço
		for (int i = 1; i < numSlots && swapped; i++) {
			for (int j = 0; j < i; j++) {
				swapped = false;
				if (precos[i] < precos[j]) {
					swap(precos[i], precos[j]);
					swap(produtos[i], produtos[j]);
					swapped = true;
				}
			}
		}
		break;
	case 3:
		// ordenado pela quantidade disponível
		for (int i = 1; i < numSlots && swapped; i++) {
			for (int j = 0; j < i; j++) {
				swapped = false;
				if (quantidades[i] < quantidades[j]) {
					swap(quantidades[i], quantidades[j]);
					swap(produtos[i], produtos[j]);
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
			cout << produtos[i] << endl;
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
			cout << "Produto inserido não foi encontrado na máquina. Por favor tente denovo." << endl;
		}
	}

	cout << "O preço atual deste produto é: " << maquina[posProduto].p.preco << EURO << endl;
	cout << "Insira o preço desejado para este produto: " << endl;
	cin >> novoPreco;
	while (int(novoPreco * 100) % 5 != 0 && novoPreco > 0) {
		cout << "O preço inserido tem que ser positivo e múltiplo de 5 cêntimos. Tente denovo." << endl;
		cin >> novoPreco;
	}

	// resultado
	maquina[posProduto].p.preco = novoPreco;
	cout << "Preco do produto " << maquina[posProduto].p.name << " alterado com sucesso." << endl;
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
		cout << "Erro ao abrir o ficheiro  guardadoSlots" << endl;
}

void gravarMaquinanumSlots(slot* maquina, int numSlots, string fileName) {
	fstream file;
	file.open(fileName, ios::out);
	if (file.is_open()) {
		file << numSlots << endl;
		file.close();
	}
	else
		cout << "Erro ao abrir o ficheiro  guardadoNumslots" << endl;
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
		cout << "Erro ao abrir o ficheiro  guardadoMoedas" << endl;
}

int carregarMaquinanumSlots(slot* maquina, int numSlots, string fileName) {
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

void menu_funcionario(slot* maquina,int moedas[6], int numSlots) //Por favor vejam se altera alguns codigos!!! PQ ADICIONEI OUTRO ARGUMENTO!!!!
{
	bool sair = false;
	while (!sair) {
		int escolha_funcionario;
		cout << "\n******* Bem-Vindo Funcionário *******" << endl;
		cout << "1. Limpar slots" << endl;
		cout << "2. Limpar máquina" << endl;
		cout << "3. Adicionar produto" << endl;
		cout << "4. Alterar preço" << endl;
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
			cout << "Escolheu limpar slots! " << endl;
			//Qualquer coisa para limpar stock;
		}
		else if (escolha_funcionario == 2) {
			cout << "Escolheu limpar a máquina! " << endl;
			//Qualquer coisa para limpar máquina;
		}
		else if (escolha_funcionario == 3) {
			cout << "Escolheu adicionar produto! " << endl;
			//Qualquer coisa para adicionar produto;
		}
		else if (escolha_funcionario == 4) {
			cout << "Escolheu alterar preço(s)! " << endl;
			alterar_preco(maquina, numSlots);
		}
		else if (escolha_funcionario == 5) {
			cout << "Escolheu adicionar slots! " << endl;
			//Qualquer coisa para adicionar slots;
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
			numSlots = carregarMaquinanumSlots(maquina, numSlots, "guardadoNumslots.txt");
			carregarMaquinaMoedas(maquina, "guardadoMoedas.txt", moedas);
			carregarMaquinaSlots(maquina, numSlots, "guardadoSlots.txt");
			cout << numSlots << endl;
			for (int i = 0; i < numSlots; i++) {
				cout << "Slot : " << maquina[i].code << endl;
				cout << "Produto : " << maquina[i].p.name << endl;
				cout << "Preço : " << maquina[i].p.preco << " " << EURO << endl;
				cout << "Quantidade : " << maquina[i].quantidade << "   | Capacidade : " << maquina[i].quantidadeMax << endl;
				cout << "------------------------------\n" << endl;
			}
		}
		else if (escolha_funcionario == 10) {
			cout << "Escolheu remover os trocos! " << endl;
			remover_fundos(moedas);
		}
		else if (escolha_funcionario == 0) {
			cout << "Escolheu Voltar! " << endl;
			sair = true;
		}
		else
			cout << "Por favor digite uma opção válida!";

		verificarFundos(moedas);
	}
}
