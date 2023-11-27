#ifndef DECLARACAOFUNCAO_H
#define DECLARACAOFUNCAO_H


typedef struct No{
    int chave; 
    float valor; 
} no;

typedef struct Tempo{
    double chave;
    int seed;
}tempo;

// arquivo usado para a declaração dos protótipos das funções 



// Protótipos das funções 
void criarVetorAleatorio(no *vetor, int size,int c);
void criarVetorOrdenado(no *vetor, int size,int c);
void imprimevetor(no *vetor, int tamanho);
void insertionSort(no *vetor, int tamanho);
void bubbleSort (no *vetor, int tamanho);
void escolhaOrdenada(int tamanho);
void escolhaAleatorio(int tamanho);
void mergeSort(no *vetor , int tamanho);
void merge(no *v , no *c, int i, int m , int f);
void sort(no *v, no *c, int i,int f);
void shellSort(no *vetor , int tamanho);
int particao(no *v, int LI, int LS);
void quickSort(no *v, int LI, int LS);
// protótipos de funções auxiliares
void limparTela();
void limparBuffer();
void imprimevetor(no *vetor, int tamanho);
int lerOpcao(int tamanho);
void pausaEnter();
char validarOpcao();
void mensagemFinal();
void menu();
void voltaMenu();
void escolhaOrdenacao();
void escolhaMetodo();
void escolhaContinuar();
void elseEscolha2();
void criaHeap(no *vet, int i, int f);
void heapSort(no *vet, int N);

   #endif