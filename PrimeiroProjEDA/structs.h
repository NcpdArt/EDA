//
// Created by duart on 21/03/2023.
//

#ifndef UNTITLED_STRUCTS_H
#define UNTITLED_STRUCTS_H

struct Carro {
    std::string marca; // marca do carro
    std::string modelo; // modelo do carro
    int tempoReparacao; // tempo maximo que demora a reparar
    int id; // ID do carro
    bool prioritario; // Indica se o carro tem prioridade sobre os outros (5%)
};

struct Mecanico {
    std::string especializacao; // especializacao do mecanico
    float custo; // custo da reparacao por dia
};

struct ET {
    int id; // ID da estacao de trabalho
    Mecanico responsavel; // mecanico responsavel pela estacao de trabalho
    Carro* garagem;  //apontador para os carros que estao com cada mecanico;
    Carro *reparados; // apontador para o vetor dinamico de carros reparados
    int capacidade; // capacidade maxima da estacao de trabalho
    float faturacao; // faturacao da estacao de trabalho
};

#endif //UNTITLED_STRUCTS_H
