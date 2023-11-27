#include "FuncoesAuxiliar/declaracaoFuncao.h"

void insertionSort(no *vetor, int tamanho){
    int i, j;
    no aux;
    // Começa a percorrer o vetor a partir do segundo elemento
    for (i = 1; i < tamanho; i++){
        // Armazena o valor do elemento atual em 'aux'
        aux = vetor[i];
        // Começa a comparar o elemento atual com os elementos anteriores
        for(j = i; j > 0; j--){
            // Compara o elemento atual com o elemento anterior
            if(vetor[j-1].chave < vetor[j].chave){
                // Se o elemento anterior for maior, troca os elementos de posição
                aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
