#include "FuncoesAuxiliar/declaracaoFuncao.h"

void criaHeap(no* vet, int i, int f){
    no aux = vet[i];
    int j = i * 2 + 1;     // Calcula o índice do primeiro nó filho

    while (j <= f){
        // Verifica se o nó atual tem um segundo filho e se o valor do segundo filho é maior que o primeiro
        if(j < f && vet[j].chave > vet[j + 1].chave){ // Alteração na comparação para ordem decrescente
            j = j + 1; // Avança para o segundo filho
        }
        // Compara o valor do nó atual com o maior dos filhos
        if(aux.chave > vet[j].chave){ // Alteração na comparação para ordem decrescente
            vet[i] = vet[j]; // Move o maior filho para a posição do nó atual
            i = j; // Atualiza o índice do nó atual
            j = 2 * i + 1; // Calcula o índice do próximo nó filho
        }else{
            break; // Se a propriedade de heap for satisfeita, interrompe o loop
        }
    }
    vet[i] = aux; // Coloca o valor de 'aux' na posição correta no heap
}

void heapSort(no *vet, int N){
    int i;
    no aux;
    // Converte o array em um heap
    for(i=(N - 1)/2; i >= 0; i--){
        criaHeap(vet, i, N-1);
    }
    // Extrai os elementos um por um do heap
    for (i = N-1; i >= 1; i--){
        aux = vet[0]; // Armazena o maior elemento (raiz do heap)
        vet[0] = vet[i]; // Move o último elemento para a raiz
        vet[i] = aux; // Armazena o maior elemento na posição correta
        criaHeap(vet, 0, i - 1); // Reconstrói o heap
    }
}
