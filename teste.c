#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h> //necessário para usar setlocale
#include <math.h>
#include <ctype.h>

// estrutura do vetor
typedef struct No{
    int chave; // chave para ordenação do vetor
    float valor; // valor do nó 
} no;

// Protótipos das funções 
void criarVetorAleatorio(no *vetor, int size,int c);
void criarVetorOrdenado(no *vetor, int size,int c);
void imprimevetor(no *vetor, int tamanho);
void insertionSort(no *vetor, int tamanho);
void bubbleSort (no *vetor, int tamanho);
void escolhaOrdenada(int tamanho);
void escolhaAleatorio(int tamanho);
void criaHeap(no *vet, int i, int f);
void heapSort(no *vet, int N);

// protótipos de funções auxiliares
void limparTela();
void limparBuffer();
void imprimevetor(no *vetor, int tamanho);
int lerOpcao(int tamanho);
void pausaEnter();
char validarOpcao();
void voltaMenu();
void escolhaOrdenacao();
void escolhaMetodo();
void escolhaContinuar();
void quickSort (no *vetor, int LI, int LS);
int particao (no *vetor , int LI, int LS);




int main(){
    setlocale(LC_ALL, "Portuguese");
    // declaração dos vetores
    int escolha,tamanho,escolha2;
    char tipo = 'a';
    clock_t inicio, fim;
    double tempo_execucao;
    int c = 0;
    no *vetor;

    tamanho = 1e6;
    vetor= (no *)malloc(tamanho * sizeof(no));
    criarVetorAleatorio(vetor,tamanho,c);
    inicio = clock();
    heapSort(vetor,tamanho);
    fim  = clock();
    imprimevetor(vetor,tamanho);
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
    printf("Tempo : %f\n",tempo_execucao);
    printf("chave primeiro elemento : %d\nChave ultimo elemento %d\n",vetor[0].chave,vetor[tamanho-1].chave);
                


  
    printf("fim do programa");








    }
   

 // Funções de ordenação e criação vetor

void criarVetorAleatorio(no *vetor, int size,int c) {
    int i;
    srand(22011027+c); // Semente

    for(i = 0; i < size; i++) 
    {
        
        vetor[i].chave = rand(); // chave aleatoria
        
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
        
        vetor[i].chave = numero_aleatorio+i*i;
        vetor[i].valor = (float)(rand() + 100); // gera um número aleatório acima de 100 e armazena no valor
       
    }

}




// Funções auxiliares
void imprimevetor(no *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++)
    {

        printf("Chave: %d, Valor: %.2f\n", vetor[i].chave, vetor[i].valor); // imprime a chave e o valor
    }
}

int particao(no *v, int LI, int LS) {
    no aux;
    int e = LI;
    int d = LS-1;
    no pivo = v[LS];
    while (e < d) {
        while (v[e].chave >= pivo.chave && e < LS) {
            e++;
        }
        while (v[d].chave < pivo.chave && d > LI) {
            d--;
        }
        if (e < d) {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
    aux = v[LI];
    v[LI] = v[d];
    v[d] = aux;
    return d;
}

void quickSort(no *v, int LI, int LS) {
    if (LI < LS) {
        int p;
        p = particao(v, LI, LS);
        quickSort(v, LI, p - 1);
        quickSort(v, p + 1, LS);
    }
}

void criaHeap(no* vet, int i, int f){
    no aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f && vet[j].chave > vet[j + 1].chave){ // Alteração na comparação para ordem decrescente
            j = j + 1;
        }
        if(aux.chave > vet[j].chave){ // Alteração na comparação para ordem decrescente
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else{
            break;
        }
    }
    vet[i] = aux;
}

void heapSort(no *vet, int N){
    int i;
    no aux;
    for(i=(N - 1)/2; i >= 0; i--){
        criaHeap(vet, i, N-1);
    }
    for (i = N-1; i >= 1; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i - 1);
    }
}
