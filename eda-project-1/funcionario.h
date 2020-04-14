#pragma once
#include "dinheiro.h"
#include "slot.h"

void menu_funcionario(slot* maquina, int moedas[6], int numSlots);

void imprimir_produtos(slot* maquina, int numSlots);

void alterar_preco(slot* maquina, int numSlots);

void gravarMaquinaSlots(slot* maquina, int numSlots, string fileName);
void gravarMaquinanumSlots(slot* maquina, int numSlots, string fileName);
void gravarMaquinaMoedas(slot* maquina, string fileName, int moedas[]);

int carregarMaquinanumSlots(slot* maquina, int numSlots, string fileName);
void carregarMaquinaMoedas(slot* maquina, string fileName, int moedas[]);
void carregarMaquinaSlots(slot* maquina, int numSlots, string fileName);
