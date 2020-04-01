#pragma once
#include "dinheiro.h"
#include "slot.h"

void menu_funcionario(slot* maquina, int moedas[6], int numSlots);

void imprimir_produtos(slot* maquina, int numSlots);

void alterar_preco(slot* maquina, int numSlots);