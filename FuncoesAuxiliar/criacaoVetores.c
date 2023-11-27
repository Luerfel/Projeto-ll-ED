#include "declaracaoFuncao.h"
#include <time.h>
#include <math.h>

void criarVetorAleatorio(no *vetor, int size,int c) {
    int i;
    srand(22011027+c); // A semente é a mudada a cada execução com o +C, a primeira execução é a semente 22011027 e a ultima é 22011036

    for(i = 0; i < size; i++) 
    {
        vetor[i].chave = (int)(rand())+100; // chave aleatoria
        vetor[i].valor = (float)(rand()); // gera um número aleatório acima de 100 e armazena no valor  
    }

}

void criarVetorOrdenado(no *vetor, int size,int c) {
    int numero_aleatorio = rand();
    numero_aleatorio = numero_aleatorio/1000;
    int i;
    srand(22011027+c); // Semente

    for(i = 0; i < size; i++) 
    {
        
        vetor[i].chave = numero_aleatorio+i*i; // criei essa conta para a ordenar ele, achei melhor do que usar simplesmente i 
        vetor[i].valor = (float)(rand() + 100); // gera um número aleatório acima de 100 e armazena no valor
       
    }

}
