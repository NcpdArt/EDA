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

int main() {
    int tamanho = 0;
    const int tamanho_marca = contaLinhas("marcas.txt");
    string* marcas = nullptr;
    marcas = new string[tamanho_marca];

    srand(time(0));
    string nome= " ";
    int et = (rand() % (8 - 3 + 1)) + 3;
    const int NUM_ETS = et;
    ET* oficina = new ET[NUM_ETS];
    //Carro* garagem = new Carro[tamanho_marca];
    //garagem[tamanho_marca].marca;

    // Preencher as ETs com valores de exemplo
    for (int i = 0; i < NUM_ETS; i++) {
        oficina[i].id = i + 1;
        oficina[i].responsavel.especializacao = "Mecanico " + to_string(i + 1);
        oficina[i].capacidade = (rand() % (5 - 2 + 1)) + 2;
        oficina[i].carros = (rand() % (oficina[i].capacidade + 1));
        oficina[i].faturacao = 0;

        // Alocar um vetor dinamico de carros reparados
        oficina[i].reparados = new Carro[oficina[i].capacidade];

        // Preencher os carros reparados com valores de exemplo
        for (int j = 0; j < oficina[i].capacidade; j++) {
            marcas[i] = ficheiroRandom(marcas, tamanho, "marcas.txt");
            oficina[i].reparados[j].marca = marcas[i];
        }
    }

    // Imprimir os dados das ETs
    for (int i = 0; i < NUM_ETS; i++) {
        cout << "ET " << oficina[i].id << "  ";
        cout << "| Responsavel: ";  //oficina[i].responsavel.especializacao << "  ";
        getline(cin, nome); 
        cout << "\033[1A"; // Move cursor up one line
        cout << "\033[2K"; // Erase entire line
        //Apos linha apagada, repeticao das linhas, mas sem o getline
        cout << "ET " << oficina[i].id << "  ";
        cout << "| Responsavel: ";  //oficina[i].responsavel.especializacao << "  ";
        cout << nome << "  ";
        cout << "| Capacidade: " << oficina[i].capacidade << "  ";
        cout << "| Carros: " << (rand() % (oficina[i].capacidade + 1)) << "  ";
        cout << "| Marca: " << marcas[i] << "  ";
        cout << "| Faturacao: " << oficina[i]. faturacao << "  "; //adicionar

        // Imprimir os carros  
        cout << endl;
        for (int j = 0; j < oficina[i].capacidade; j++) {
            cout << "Carro: ";
            cout << oficina[i].reparados[j].marca /*alternativa => marcs[i]*/ << " " << oficina[i].reparados[j].modelo << endl;
        }
        cout << endl;
    }

    // Liberar a memoria alocada para os vetores dinamicos de carros reparados
    for (int i = 0; i < NUM_ETS; i++) {
        delete[] oficina[i].reparados;
    }
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
