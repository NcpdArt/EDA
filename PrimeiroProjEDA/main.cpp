#include <string>
#include "Info.h"
#include <cstdlib>
#include <ctime>
#include <string>

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



//CODIGO MAIN AINDA ESTÁ PRECISANDO DE ALTERAÇÕES

// ERRO NO NUM DE CAPACIDADE, NUM DE CARROS NO PRINT TO LOOP E ERRO DOS NOMES DOS CARROS NESSE LOOP
int main() {
    srand(time(NULL));
    const int tamanho_marca = contaLinhas("marcas.txt");
    const int tamanho_modelos = contaLinhas("modelos.txt");
    string* marcas = nullptr;
    marcas = new string[tamanho_marca];
    string* modelos = nullptr;
    modelos = new string[tamanho_modelos];
    string nome= " ";
    int et = (rand() % (8 - 3 + 1)) + 3;  //[8,3]
    const int NUM_ETS = et;
    ET* oficina = new ET[NUM_ETS];
    //Carro* garagem = new Carro[50];
    //garagem[tamanho_marca].marca;

    // Inicializar os valores das ET's
    for (int i = 0; i < NUM_ETS; i++) {
        srand(time(NULL) + i);
        oficina[i].id = i + 1;
        oficina[i].capacidade = (rand() % (5 - 2 + 1)) + 2; //[5,2]
        oficina[i].carros = (rand() % (oficina[i].capacidade + 1)); //[capacidade,0]
        oficina[i].faturacao = 0;

        // vetor dinamico para os carros reparados
        oficina[i].reparados = new Carro[oficina[i].capacidade];

        //inicializar valores dos carros
        for (int j = 0; j < oficina[i].carros; j++) {
            srand(time(NULL) + j);
            oficina[i].responsavel.especializacao = ficheiroRandom(marcas, "marcas.txt");
            modelos[i] = ficheiroRandom(modelos, "modelos.txt");
        }
    }

    // Imprimir os dados das ETs
    for (int i = 0; i < NUM_ETS; i++) {
        for (int j = 0; j <= i; i++) {
            cout << "ET " << oficina[i].id << "  ";
            cout << "| Responsavel: ";
            getline(cin, nome);
            oficina[i].responsavel.nome = nome;
            cout << "\033[1A"; // Move cursor up one line
            cout << "\033[2K"; // Erase entire line
            //Apos linha apagada, repeticao das linhas, mas sem o getline
            cout << "ET " << oficina[i].id << "  ";
            cout << "| Responsavel: "; cout <<oficina[i].responsavel.nome << "  "; //cout << nome << "  ";
            cout << "| Capacidade: " << oficina[i].capacidade << "  ";
            cout << "| Carros: " << oficina[i].carros << "  ";
            cout << "| Marca: " << oficina[i].responsavel.especializacao << "  ";
            cout << "| Faturacao: " << oficina[i].faturacao << "  "; //adicionar

            // Imprimir os carros  
            cout << endl;
            for (int j = 0; j < oficina[i].carros; j++) {
                cout << "Carro: ";
                cout << "ID:   | " << oficina[i].responsavel.especializacao << " - " << modelos[i] << endl;
            }
            cout << endl;
        }
    }

    // Liberar a memoria alocada para os vetores dinamicos de carros reparados
    for (int i = 0; i < NUM_ETS; i++) {
        delete[] oficina[i].reparados;
    }return 0;
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
