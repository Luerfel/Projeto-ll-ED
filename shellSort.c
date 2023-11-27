#include "FuncoesAuxiliar/declaracaoFuncao.h"



void shellSort(no *vetor , int tamanho){
    int i,j,h;
    no aux;
    // Define o intervalo inicial 'h' para o algoritmo de Shell
    for (h=1; h<tamanho; h = 3*h+1);

    // Loop principal do algoritmo de Shell
    while(h>0){
        // Atualiza o intervalo 'h' de acordo com a sequência de intervalos de Shell
        h = (h-1)/3;
        // Aplica o algoritmo de inserção com o intervalo 'h'
        for(i=h; i<tamanho; i++){
            // Armazena o valor do elemento atual em 'aux'
            aux = vetor[i];
            j = i;

            // Realiza a comparação e troca os elementos de acordo com o intervalo 'h'
            while (vetor[j-h].chave < aux.chave) {
                vetor[j] = vetor[j - h];
                j -= h;
                // Verifica se o índice está dentro do intervalo 'h'
                if (j < h) break;
            }
            // Coloca o valor de 'aux' na posição correta
            vetor[j] = aux;
        }
    }
}
