#include <iostream>
#include<stdlib.h>
#include<time.h>
#include "dinheiro.h"
using namespace std;



void fundos() {
	
	int moedasdoiseuros = rand() % 11 + 10; //de 10 a 20
	
	int moedasumeuros = rand() % 11 + 10; //de 10 a 20
	//int moedasumeuros = 2;

	int moedascinquentacents = rand() % 11 + 10; //de 10 a 20
	
	int moedasvintecents = rand() % 11 + 10; //de 10 a 20
	
	int moedasdezcents = rand() % 11 + 10; //de 10 a 20
	
	int moedascincocents = rand() % 11 + 10; //de 10 a 20
	
	/*cout << "2 ->" << moedasdoiseuros<<endl;
	cout << "1-> " << moedasumeuros << endl;
	cout << "0.5 ->" << moedascinquentacents << endl;
	cout << "0.2-> " << moedasvintecents << endl;
	cout << "0.1-> " << moedasdezcents << endl;
	cout << "0.05-> " << moedascincocents << endl;*/ //Para teste!!!!

	if (moedasdoiseuros <= 3 || moedasumeuros <= 3 || moedascinquentacents <= 3 || moedasvintecents <= 3 || moedasdezcents <= 3 || moedascincocents <= 3) { //Este if para dizer apenas uma vez o ***AVISO***
		cout << "***AVISO***" << endl;
		if (moedasdoiseuros <= 3) {
			cout << "Existem apenas " << moedasdoiseuros << " moedas de dois euros"<<endl;
		}
		else if (moedasumeuros <= 3) {
			cout << "Existem apenas " << moedasumeuros << " moedas de um euro"<<endl;
		}
		else if (moedascinquentacents <= 3) {
			cout << "Existem apenas " << moedascinquentacents << " moedas de cinquenta cêntimos"<<endl;
		}
		else if (moedasvintecents <=3) {
			cout << "Existem apenas " << moedasvintecents << " moedas de vinte cêntimos"<<endl;
		}
		else if (moedasdezcents <=3) {
			cout << "Existem apenas " << moedasdezcents << " moedas de dez cêntimos"<<endl;
		}
		else if (moedascincocents <=3) {
			cout << "Existem apenas " << moedascincocents << " moedas de cinco cêntimos" << endl;
		}


	}

}



