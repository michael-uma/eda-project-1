#pragma once
#include "dinheiro.h"
#include "slot.h"
extern int numSlots; // para reconhecimento da variável global

void menu_funcionario(slot* maquina, int moedas[6], int numSlots);

void imprimir_produtos(slot* maquina, int numSlots);

void alterar_preco(slot* maquina, int numSlots);

void gravarMaquinaSlots(slot* maquina, int numSlots, string fileName);
void gravarMaquinanumSlots(slot* maquina, int numSlots, string fileName);
void gravarMaquinaMoedas(slot* maquina, string fileName, int moedas[]);

int carregarMaquinanumSlots(int numSlots, string fileName);
void carregarMaquinaMoedas(slot* maquina, string fileName, int moedas[]);
void carregarMaquinaSlots(slot* maquina, int numSlots, string fileName);

void limparSlot(slot* maquina, int numSlots);
void adicionarSlot(slot* maquina, int numslots);
void limparMaquina(slot* maquina, int numSlots);

