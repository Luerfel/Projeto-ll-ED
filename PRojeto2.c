#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h> //necessário para usar setlocale
typedef struct No{
    int chave; // chave para ordenação do vetor
    float valor; // valor do nó 
} no;

// funções 
void criarVetorAleatorio(no *vetor, int size);
void chaveAleatorio(no *vetor , int size);
void imprimevetor(no *vetor, int tamanho);
void menu();
void menuTamanho();
no insertionSort(no *vetor, int tamanho);


int main(){
    setlocale(LC_ALL, "Portuguese");
    // declaração dos vetores

    no vetor10Mil[10000]; // vetor 10⁴
    no vetor50Mil[50000]; // vetor 5*10⁴
    no vetor100Mil[100000]; // vetor 10⁵
    no vetor500Mil[500000];  // vetor 5*10⁵
    no vetor1Milhao [1000000];  // vetor 10*6

    // declaração das variaveis

    char tipo = 'a';
    clock_t inicio, fim;
    double tempo_execucao;
    int escolha;


    /* VETOR DE 10 MIL 
    criarVetorAleatorio(vetor10Mil, 10000);
    inicio = clock(); // Marca o início da execução

    insertionSort(vetor10Mil,10000);

    fim = clock(); // Marca o fim da execução
    imprimevetor(vetor10Mil, 10000);
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
   */

    criarVetorAleatorio(vetor50Mil,50000);
    inicio = clock(); // Marca o início da execução

    insertionSort(vetor50Mil,50000);
    fim = clock(); // Marca o fim da execução
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
    printf("Tempo de execução: %f segundos\n", tempo_execucao);






    //printf("Tempo de execução: %f segundos\n", tempo_execucao);



    }
   



void criarVetorAleatorio(no *vetor, int size) {
    int i;
    srand(22011027); // Semente

    for(i = 0; i < size; i++) 
    {
        
        vetor[i].chave = i+1;
        
        vetor[i].valor = (float)(rand() + 100); // gera um número aleatório acima de 100 e armazena no valor
       
    }

}
void imprimevetor(no *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++)
    {

        printf("Chave: %d, Valor: %.2f\n", vetor[i].chave, vetor[i].valor); // imprime a chave e o valor
    }
}
void chaveAleatorio(no *vetor , int size){
    int i;
    for (i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = vetor[i].chave;
        vetor[i].chave = vetor[j].chave;
        vetor[j].chave = temp;
    }
}
no insertionSort(no *vetor, int tamanho){
    int i, j;
    no aux;
    for (i = 1; i<tamanho; i++){
       for(j = i; j>0; j--){
            if (vetor[j-1].chave<vetor[j].chave){
            aux = vetor[j-1];
            printf("%d\n",i);
            vetor[j-1] = vetor[j];
            vetor [j] = aux;        } 
       }
    }
}
