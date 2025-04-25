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
        No* novo = (No*)malloc(sizeof(No));// aloca memória para o nó 
        novo->dados = p;
        novo->direita = NULL;
        novo->esquerda = NULL;
        return novo;
    }else{ //aqui adiciona abaixo da raiz, seguindo a ordem hierárquica

        //cpf é char e char segue uma regra chamada lexicografia que funciona como a ordem numérica, ou seja, compara se um número é maior que o outro pela ordem numérica, o que é o caso dos cpf, por isso a função abaixo compara os cpfs

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
       return NULL; //Ou a árvore não existe ou elemento não foi encontrado.
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

No* remover(No *raiz, Prontuario p){
    if (raiz == NULL){
       return NULL; //Ou a árvore não existe ou elemento não foi encontrado para a remoção.
    }else{
        if(strcmp(p.cpf, raiz->dados.cpf)==0){
            if(raiz->esquerda == NULL && raiz->direita == NULL){ //remove nós folhas
                free(raiz); //libera a memória da raiz
                return NULL;
            }else{
                //remove nos com um filho ↓
                if(raiz->esquerda== NULL || raiz->direita == NULL){
                    No *aux;
                    if (raiz->esquerda != NULL){ //se tiver filho a esquerda armazena ele na variável auxiliar
                        aux = raiz->esquerda;
                    }else{
                        aux = raiz->direita; //se tiver filho a direita armazena ele na variável auxiliar
                    }
                    free(raiz); //libera a memória do nó a ser removido
                    return aux; //retorna o nó filho que vai para o lugar do pai
                }else { //removerá nós com dois filhos
                    /*Ao remover um nó com dois filhos, se usar a subávore a esquerda (que é o caso), substituí pelo maior valor dela, ou seja, o nó mais a direita*/
                    No *aux = raiz->esquerda;
                    while (aux->direita == NULL){
                        aux = aux->direita; //percorre a direita até achar o mais à direita 
                    }

                    /*Após achar o nó mais a direita troca os valores do nó a ser removido e o que vai substituir para que ele seja um nó folha ou com um filho só, assim faz recursão de função e chamando o remover para o nó , ai cairá em uma das situações acima e removerá o nó*/
                    raiz->dados = aux->dados;
                    aux->dados = p;
                    raiz->esquerda = remover(raiz->esquerda, p);
                    return raiz;
                }
            }
        }else{
            if (strcmp(p.cpf, raiz->dados.cpf) < 0){ //realiza busca na subarvore a esquerda
                raiz->esquerda= remover(raiz->esquerda, p);
            }else if (strcmp(p.cpf, raiz->dados.cpf) > 0){ //realiza busca na subarvore a direita
                raiz->direita = remover(raiz->direita, p);
            }
            return raiz;
        }
    }  
}

bool atualizar(No *raiz, const char cpf, const char *novoNome, const char *novoHistorico){
    if(raiz == NULL){
        return false; //não encontrou cpf ou não há raiz
    }else{
        if(strcmp(cpf, raiz->dados.cpf)==0){ 
            strcpy(raiz->dados.nome, novoNome); //copia o novo nome na variavel da raiz, alterando o nome
            strcpy(raiz->dados.historico, novoHistorico);//copia o novo histórico na variavel da raiz, alterando o histórico
            return true;
        }else{
              if (strcmp(cpf, raiz->dados.cpf) < 0){ //atualiza na subarvore a esquerda
                return atualizar(raiz->esquerda, cpf, novoNome, novoHistorico );
            }else if (strcmp(cpf, raiz->dados.cpf) > 0){ //atualiza na subarvore a direita
                return atualizar(raiz->direita, cpf, novoNome, novoHistorico );
            }
        }
    }
}

void imprimeTodosInOrder(No *raiz){ //imprime a arvore em ordem ou seja, Esquerda -> Raiz-> Direita
    if(raiz != NULL){
        imprimeTodos(raiz->esquerda);
        printf("\n------Prontário------\n");        
        printf("Nome: %s\n", raiz->dados.nome);
        printf("Cpf: %s\n", raiz->dados.cpf);
        printf("Data de Nascimento %02d/%02d/%04d\n", raiz->dados.dataNasc.data,raiz->dados.dataNasc.mes, raiz->dados.dataNasc. ano );
        printf("Histórico: %s\n", raiz->dados.historico);
        printf("-----------------------\n");
        imprimeTodos(raiz->direita);    
    } 
}

void imprimeEspecifico(No *raiz, Prontuario p){ //imprime um prontuario especifico a partir do cpf
    if (raiz != NULL){   
        if(strcmp(p.cpf, raiz->dados.cpf)==0){
            printf("\n------Prontário------\n");        
            printf("Nome: %s\n", raiz->dados.nome);
            printf("Cpf: %s\n", raiz->dados.cpf);
            printf("Data de Nascimento %02d/%02d/%04d\n", raiz->dados.dataNasc.data,raiz->dados.dataNasc.mes, raiz->dados.dataNasc. ano );
            printf("Histórico: %s\n", raiz->dados.historico);
            printf("-----------------------\n");
        }else{
            if (strcmp(p.cpf, raiz->dados.cpf) < 0){ 
                imprimeEspecifico(raiz->esquerda, p);
            }else if (strcmp(p.cpf, raiz->dados.cpf) > 0){ 
                imprimeEspecifico(raiz->direita, p);
            }
        }
    }   
}

bool data_valida(int dia, int mes, int ano) {
    if (ano < 1900 || ano > 2025) return false; // Anos válidos, para limitar se a data é valida, não há pessoas nascidas depois de 2025
    if (mes < 1 || mes > 12) return false; //como os meses vão de 1 a 12, se for maior que 12 ou menor que 1 é classificada inválida 
    
    // Verifica se os dias correspondem com os dias contidos nos meses, já que nem todos tem a mesma quantidade de dias
    int dias_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // verificação para ano bissexto, ja que é o mes 2 e todo ano bissexto é divisivel por 
    if (mes == 2 && ((ano % 400 == 0) || (ano % 100 != 0 && ano % 4 == 0))) {
        dias_mes[1] = 29;
    }
    
    return (dia >= 1 && dia <= dias_mes[mes-1]); //dia só é valido se for entre 1 e o ultimo dia do do seu mês
}

bool inserirDataNascimento(Prontuario *prontuario) {
    if (prontuario == NULL) {
        printf("Erro: Prontuário inexistente");
        return false;
    }

    int dia, mes, ano;
    
    printf("\n--- Inserção de Data de Nascimento ---\n");
    
    // Pede para inserir até dar uma data válida
    do {
        printf("Dia (1-31): ");
        scanf("%d", &dia);
        
        printf("Mês (1-12): ");
        scanf("%d", &mes);
        
        printf("Ano (1900-2025): ");
        scanf("%d", &ano);
        
        if (!data_valida(dia, mes, ano)) {
            printf("Data inválida! Por favor, insira novamente.\n");
        }
    } while (!data_valida(dia, mes, ano));
    
    // Atribui a data validada ao prontuário
    prontuario->dataNasc.data = dia;
    prontuario->dataNasc.mes = mes;
    prontuario->dataNasc.ano = ano;
    
    printf("Data de nascimento inserida com sucesso: %02d/%02d/%04d\n", 
           dia, mes, ano); //imprime a data
    
    return true;
}