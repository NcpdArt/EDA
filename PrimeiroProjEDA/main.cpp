#include <fstream>
#include <iostream>
#include "structs.h"
using namespace std;

Carro *LEspera;
ET *ETs;
ifstream inputMarcas;
ifstream inputModelos;
string *marcas;
string *modelos;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

bool aberturaFicheiros(string*& marcas, string*& modelos){
    string linha;
    int aux = 0;
    inputMarcas.open("marcas.txt");
    inputModelos.open("modelos.txt");

    if (inputMarcas.is_open() && inputModelos.is_open()) {
        return false;
    }
    else {
        while (getline(inputMarcas, linha)) {
            aux++;
        }
        inputMarcas.clear(); // clear the eof flag
        inputMarcas.seekg(0, ios::beg); // reset the file pointer
        return true;
    }
}
