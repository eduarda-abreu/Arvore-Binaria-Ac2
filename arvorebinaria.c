//Implementação do esqueleto da Arvore binária
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvorebinaria.h"

void inicializarArvore(ArvB *arv){
    arv->raiz = NULL;
}

No* insere(No *raiz, Prontuario p){
    if(raiz == NULL){ //se a raiz é NULL cria um novo nó que é a raiz da árvore
        No* novo = (No*)malloc(sizeof(No));
        novo->dados = p;
        novo->direita = NULL;
        novo->esquerda = NULL;
        return novo;
    }else{ //aqui adiciona abaixo da raiz, seguindo a ordem hierárquica

        //cpf é char e char segue uma regra chamada lexicográfica que funciona como a ordem numérica, ou seja, compara se um número é maior que o outro, o que é o caso dos cpf, por isso a função abaixo compara os cpfs

        if (strcmp(p.cpf, raiz->dados.cpf) < 0){ //quando retorna negativo significa que o número é menor que o nó atual
            raiz->esquerda= insere(raiz->esquerda, p);
        }else if (strcmp(p.cpf, raiz->dados.cpf) > 0){ //quando retorna positivo significa que o número é maior que o nó atual
            raiz->direita = insere(raiz->direita, p);
        }

        return raiz;
    }
}

No* buscar(No *raiz, Prontuario p){
    if (raiz == NULL){
       return 0; //Ou a árvore não existe ou elemento não foi encontrado.
    }else{
        if(strcmp(p.cpf, raiz->dados.cpf)==0){ //se der 0 são iguais
            return raiz;
        }else{
            if (strcmp(p.cpf, raiz->dados.cpf) < 0){ //realiza busca na subarvore a esquerda
                return buscar(raiz->esquerda, p);
            }else if (strcmp(p.cpf, raiz->dados.cpf) > 0){ //realiza busca na subarvore a direita
                return buscar(raiz->direita, p);
            }
        }
    }   
}

