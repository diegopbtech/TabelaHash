#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Tipo de dado que será armazenado nas listas
struct Objeto {
    string chave;
    string valor;

    Objeto(string c, string v) : chave(c), valor(v) {}
};

class SegundoNivel {
    private:
        // Vetor de uma lista encadeada do tipo Objeto
        // O tipo 'Objeto' é estruturado com duas strings com 'Chave' e 'Valor'    
        // List é uma classe de Lista Encadeada implementada na Biblioteca 'List'
        vector<list<Objeto>> tabela;
        // Tamanho da tabela
        int tamanho;

        // Função hash do nível 2
        // Transforma a string chave em um índice numérico que vai de 0 até tamanho - 1
        // Esse índice vem da soma dos valores numéricos dos caracteres da chave (ASCII)
        int hash2(string chave) {
            int soma = 0;
            // Um loop somando os valores ASCII de cada caracter presente na string
            for (char c : chave){
                soma += c;
            }
            // Faz um hash simples retornando a posição
            return soma % tamanho;
        }
    
    public:
        // Construtor da classe para o segundo nível
        // Tamanho está sendo inicializado antes de entrar no corpo do construtor
        SegundoNivel(int n) : tamanho(n / 10) {
            // resize está redefinindo o vetor para ter o tamanho presente na variável "tamanho"
            tabela.resize(tamanho);
        }
        
        // Função de inserção de novos objetos
        void inserir(string chave, string valor) {
            // Chama a função hash para retornar a posição da chave
            int idx = hash2(chave);
            // Adiciona o valor ao final do vetor presente na tabela[idx]
            tabela[idx].emplace_back(chave, valor);
        }
        
        // Função que irá buscar o endereço de memória (Ponteiro) do tipo estruturado através da chave
        Objeto* buscar(string chave) {
            // Calcula o hash
            int idx = hash2(chave);
            // Loop de intervalo que permite iterar sobre todos os elementos do vetor
            for (auto& obj : tabela[idx]) {
                if (obj.chave == chave){
                    // Retorna o ponteiro do objeto caso encontrado
                    return &obj;
                }
            }
            return nullptr;
        }
};