#include "FuncoesAuxiliar/declaracaoFuncao.h"

void bubbleSort (no *vetor, int tamanho){
    int i, j;
    no aux;
    // Percorre o vetor
    for (i=0; i<tamanho-1; i++){
        // Compara os elementos e os reorganiza
        for (j=1; j<tamanho-i; j++){
            // Compara o elemento atual com o próximo elemento
            if(vetor[j].chave > vetor[j-1].chave){
                // Se o próximo elemento for maior, troca os elementos de posição
                aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
