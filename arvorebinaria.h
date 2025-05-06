/*  Esqueleto para a função de Arvore Binária de Busca
    Objetivo - Criar Arvore Binária de Busca para buscar prontuarios médicos a partir de cpf (chave que não repete)
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int data, mes, ano;
}Data;


typedef struct 
{
    char nome[100];
    char cpf[12]; //será usado como chave para a árvore, usa char pois há cpfs que começam com 0 e o int "apaga" esse 0 
    Data dataNasc; 
    char historico[1000];
}Prontuario;


typedef struct No
{
    Prontuario dados;
    struct no *esquerda, *direita; 
}No;

typedef struct{
    No *raiz;
}ArvB;

void inicializarArvore(ArvB *arv);

No* insere(No *raiz, Prontuario p);

No* buscar(No *raiz, Prontuario p);

No* remover(No *raiz, Prontuario p);

bool atualizar(No *raiz, const char cpf, const char *novoNome, const char *novoHistorico);

void imprimeTodosInOrder(No *raiz);

void imprimeEspecifico(No *raiz, Prontuario p);

bool data_valida(int dia, int mes, int ano);

bool inserirDataNascimento(Prontuario *prontuario);

Prontuario lerProntuarioDoUsuario();