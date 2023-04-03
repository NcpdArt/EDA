#include <iostream>
#include "Info.h"
#include <fstream>
#include <string>
using namespace std;


int contaLinhas(string fileName) {
	fstream ficheiro;
	int tamanho = 0;
	ficheiro.open(fileName, ios::in);
	string line;
	while (getline(ficheiro, line))
		tamanho++;
	ficheiro.close();
	return tamanho;
}

string ficheiroRandom(string arr[], int tamanho, string filename) {
	srand(time(0));
	int i = 0;
	tamanho = contaLinhas(filename);
	int random = rand() % (tamanho + 1); //[0,tamanho] do file
	fstream file;
	file.open(filename, ios::in);
	string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			arr[i] = line;  //guardar o .txt num array
			i++;
		}
		file.close();
	}
	return  arr[random];  // cout do array com linha random

}
