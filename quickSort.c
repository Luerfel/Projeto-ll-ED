#include "FuncoesAuxiliar/declaracaoFuncao.h"


void quickSort(no *v, int LI, int LS) {
    // Verifica se o índice da esquerda é menor que o índice da direita
    if (LI < LS) {
        int p;
        // Encontra o pivô e particiona o array
        p = particao(v, LI, LS);
        // Chama recursivamente o quicksort para a parte esquerda do pivô
        quickSort(v, LI, p - 1);
        // Chama recursivamente o quicksort para a parte direita do pivô
        quickSort(v, p + 1, LS);
    }
}

//Limite superior

/*int particao(no *v, int LI, int LS) {
    no aux;
    int e = LI;
    int d = LS - 1; // Ajuste aqui para evitar acessar v[LS], que é o pivô
    no pivo = v[LS]; // Define o pivô como o último elemento do array
    // Enquanto os índices não se cruzarem
    while (e <= d) {
        // Encontra um elemento à esquerda do pivô que é maior que o pivô
        while (e <= d && v[e].chave > pivo.chave) {
            e++;
        }
        // Encontra um elemento à direita do pivô que é menor ou igual ao pivô
        while (d >= e && v[d].chave <= pivo.chave) {
            d--;
        }
        // Troca os elementos encontrados de posição
        if (e < d) {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
    // Coloca o pivô na posição correta
    aux = v[e];
    v[e] = v[LS];
    v[LS] = aux;
    return e; // Retorna a posição do pivô
} */


// Limite Inferior
int particao(no *v, int LI, int LS) { 
    no aux;
    int e = LI + 1; // Define o início da busca um elemento à frente do limite inferior
    int d = LS; // Define o fim da busca como o limite superior
    no pivo = v[LI]; // Define o pivô como o primeiro elemento do array
    // Enquanto os índices não se cruzarem
    while (e <= d) {
        // Encontra um elemento à esquerda do pivô que é maior ou igual ao pivô
        while (e <= d && v[e].chave <= pivo.chave) {
            e++;
        }
        // Encontra um elemento à direita do pivô que é menor que o pivô
        while (d >= e && v[d].chave > pivo.chave) {
            d--;
        }
        // Troca os elementos encontrados de posição
        if (e < d) {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
    // Coloca o pivô na posição correta
    aux = v[d];
    v[d] = v[LI];
    v[LI] = aux;
    return d; // Retorna a posição do pivô
}
