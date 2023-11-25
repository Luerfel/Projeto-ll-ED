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
void shellSort(no *vetor , int tamanho);
void merge(no *v , no *c, int i, int m , int f);
void sort(no *v, no *c, int i,int f);
void mergesort(no *v , int n);



int main(){
    setlocale(LC_ALL, "Portuguese");
    // declaração dos vetores
    int escolha,tamanho,escolha2;
    char tipo = 'a';
    clock_t inicio, fim;
    double tempo_execucao;
    int c = 0;
    no *vetor;

    tamanho = 100000;
    vetor= (no *)malloc(tamanho * sizeof(no));
    criarVetorAleatorio(vetor,tamanho,c);
    inicio = clock();
    mergesort(vetor,tamanho);
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
        
        vetor[i].chave = (int)(rand()); // chave aleatoria
        
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
for (i=0; i<tamanho; i++){
    for (j=1; j<tamanho; j++){
        if (vetor[j].chave>vetor[j-1].chave){
            aux = vetor[j-1];
            vetor[j-1] = vetor[j];
            vetor [j] = aux;
        }
        
    }
}
    
}

void shellSort(no *vetor , int tamanho){
    int i,j,h;
    no aux;
    for (h=1; h<tamanho; h = 3*h+1);

    while(h>0){
        h = (h-1)/3;
        for(i=h; i<tamanho; i++){
            aux = vetor[i];
            j = i;

            while (vetor[j-h].chave < aux.chave) {
                vetor[j] = vetor[j - h];
                j -= h;
                if (j<h) break;
            }
            vetor[j] = aux;
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

void merge(no *v , no *c, int i, int m , int f){
    int z, iv = i, ic = m+1;
    for(z = i; z <= f; z++)
    {
        c[z] = v[z];
    }
    z = i;
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
    while (iv <= m)
    {
        v[z++] = c[iv++];
    }
    while (ic <= f)
    {
        v[z++] = c[ic++];
    }
}

void sort(no *v, no *c, int i,int f){
    if (i < f)
    {
        int m = (i+f)/2;
        sort(v, c, i, m);
        sort(v, c, m+1, f);
        if (v[m].chave < v[m+1].chave)
        {
            merge(v, c, i, m, f);
        }
    }
}

void mergesort(no *v , int n){

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end;
    double cpu_time_used;

    //parte da função merge sort
    no *c = malloc(sizeof(no)*n);
    sort (v, c, 0, n-1);
    free(c);

    //parte para da biblioteca time.h para marcar o tempo de execução e verificar a ordenação
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort): %f\n", cpu_time_used);
    
    printf("primeira chave: %d\n", v[0].chave);
    printf("ultima chave: %d\n", v[n-1].chave);

}
