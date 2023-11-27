#include "FuncoesAuxiliar/declaracaoFuncao.h"


void mergeSort(no *v , int n){
    // Aloca memória para um array auxiliar
    no *c = malloc(sizeof(no)*n);
    // Chama a função de ordenação merge sort
    sort(v, c, 0, n-1);
    // Libera a memória alocada para o array auxiliar
    free(c);
}

void merge(no *v , no *c, int i, int m , int f){
    int z, iv = i, ic = m+1;
    // Copia os elementos do array original para o array auxiliar
    for(z = i; z <= f; z++)
    {
        c[z] = v[z];
    }
    z = i;
    // Mescla os elementos ordenados de volta para o array original
    while (iv <= m && ic <= f)
    {
        if (c[iv].chave >= c[ic].chave)
        {
            v[z++] = c[iv++];
        }
        else
        {
            v[z++] = c[ic++];
        }
    }
    // Adiciona os elementos restantes de iv para m
    while (iv <= m)
    {
        v[z++] = c[iv++];
    }
    // Adiciona os elementos restantes de ic para f
    while (ic <= f)
    {
        v[z++] = c[ic++];
    }
}

void sort(no *v, no *c, int i,int f){
    if (i < f)
    {
        // Calcula o ponto médio do array
        int m = (i+f)/2;
        // Ordena a metade esquerda do array
        sort(v, c, i, m);
        // Ordena a metade direita do array
        sort(v, c, m+1, f);
        // Mescla as duas metades ordenadas
        if (v[m].chave < v[m+1].chave)
        {
            merge(v, c, i, m, f);
        }
    }
}

