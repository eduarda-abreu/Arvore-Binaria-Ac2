/*  Esqueleto para a função de Arvore Binária de Busca
    Objetivo - Criar Arvore Binária de Busca para buscar prontuarios médicos a partir de cpf (chave que não repete)
*/

typedef struct {
    int data, mes, ano;
}Data;


typedef struct 
{
    char nome[100];
    char cpf[15];
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