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


int main(){
    setlocale(LC_ALL, "Portuguese");
    // declaração dos vetores
    int escolha,tamanho,escolha2;
    char tipo = 'a';
    clock_t inicio, fim;
    double tempo_execucao;
    int c = 0;
    no *vetor;

    tamanho = 10000;
    vetor= (no *)malloc(tamanho * sizeof(no));
    criarVetorAleatorio(vetor,tamanho,c);
    inicio = clock();
    bubbleSort(vetor,tamanho);
    fim  = clock();
     imprimevetor(vetor,tamanho);
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
    printf("Tempo : %f\n",tempo_execucao);
                


  
    printf("fim do programa");








    }
   

 // Funções de ordenação e criação vetor

void criarVetorAleatorio(no *vetor, int size,int c) {
    int i;
    srand(22011027+c); // Semente

    for(i = 0; i < size; i++) 
    {
        
        vetor[i].chave = (int)(rand()+100); // chave aleatoria
        
        vetor[i].valor = (float)(rand() + 100); // gera um número aleatório acima de 100 e armazena no valor
       
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

void insertionSort(no *vetor, int tamanho){
    int i, j;
    no aux;
    for (i = 1; i<tamanho; i++){
       for(j = i; j>0; j--){
            if (vetor[j-1].chave<vetor[j].chave){
            aux = vetor[j-1];
            vetor[j-1] = vetor[j];
            vetor [j] = aux;        } 
       }
    }



}

void bubbleSort (no *vetor, int tamanho){
int i, j;
no aux;
for (i=0; i<tamanho-1; i++){
    for (j=1; j<tamanho-1; j++){
        if (vetor[j].chave>vetor[j-1].chave){
            aux = vetor[j-1];
            vetor[j-1] = vetor[j];
            vetor [j] = aux;
        }
        
    }
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

