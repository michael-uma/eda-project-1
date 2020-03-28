#pragma once
#include <string>
using namespace std;

struct produto {
	string name;
	float price;
};

struct slot {
	produto p;
	int quantity;
	char code;
};