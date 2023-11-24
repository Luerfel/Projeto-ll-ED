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

typedef struct Tempo{
    int chave;
    int seed;
}tempo;

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
void elseEscolha2();

int main(){
    setlocale(LC_ALL, "Portuguese");
    // declaração dos vetores
    int escolha,tamanho,escolha2;

  do {
        menu();
        escolha = lerOpcao(6);
        switch (escolha) {

            case 1:
                tamanho = 10000;
                limparTela();
                escolhaOrdenacao();
                escolha2 = lerOpcao(2);
                limparTela();
                if (escolha2 == 1){
                    escolhaOrdenada(tamanho);

                }
                else if(escolha2==2){
                    escolhaAleatorio(tamanho);
                }
                else{
                    elseEscolha2();
                    break;
                }
                break;

            case 2:
                tamanho = 50000;
                limparTela();
                escolhaOrdenacao();
                escolha2 = lerOpcao(2);
                limparTela();
                if (escolha2 == 1){

                    escolhaOrdenada(tamanho);

                }

                else if(escolha2==2){
                    escolhaAleatorio(tamanho);
                }
                else{
                    elseEscolha2();

                    break;
                }
                break;
            case 3:
                tamanho = 100000;
                limparTela();
                escolhaOrdenacao();
                escolha2 = lerOpcao(2);
                limparTela();
                if (escolha2 == 1){
                    escolhaOrdenada(tamanho);
                }
                else if(escolha2==2){
                    escolhaAleatorio(tamanho);
                }
                else{
                    elseEscolha2();
                    break;
                }
                break;
            case 4:
                tamanho = 500000;
                limparTela();
                escolhaOrdenacao();
                escolha2 = lerOpcao(2);
                limparTela();
                if (escolha2 == 1){
                    escolhaOrdenada(tamanho);
                }
                else if(escolha2==2){
                    escolhaAleatorio(tamanho);
                }
                else{
                    elseEscolha2();

                    break;
                }
            case 5:
                tamanho = 1000000;
                limparTela();
                escolhaOrdenacao();
                escolha2 = lerOpcao(2);
                limparTela();
                if (escolha2 == 1){
                    escolhaOrdenada(tamanho);
                }
                else if(escolha2==2){
                    escolhaAleatorio(tamanho);
                }
                else{
                    elseEscolha2();

                    break;
                }
                break;
            case 6:
                limparTela();
                mensagemFinal();
                break;
            default:
                elseEscolha2();
                break;
        }
    } while (escolha != 6);




  
    printf("fim do programa");

//     tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos







    }
   

 // Funções de ordenação e criação vetor

void criarVetorAleatorio(no *vetor, int size,int c) {
    int i;
    srand(22011027+c); // Semente

    for(i = 0; i < size; i++) 
    {
        
        vetor[i].chave = (int)(rand()%1000000)+100; // chave aleatoria
        
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


// Funções auxiliares
void imprimevetor(no *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++)
    {

        printf("Chave: %d, Valor: %.2f\n", vetor[i].chave, vetor[i].valor); // imprime a chave e o valor
    }
    printf("Primeiro elemento : %d\nUltimo elemento : %d\n",vetor[0].chave,vetor[tamanho-1].chave);
}

void menu(){
    printf("Digite o tamanho do seu vetor:\n");
    printf("1. 10⁴ (10 MIL)\n");
    printf("2. 5*10⁴ (50 MIL)\n");
    printf("3. 10⁵ (100 MIL)\n");
    printf("4. 5*10⁵ (500 mil)\n");
    printf("5. 5⁶ (1 Milhão)\n");
    printf("6. Finalizar Programa\n\n");
}

void voltaMenu()
{

    char opcao;
    printf("Deseja voltar para o menu principal? S/N\n");
    opcao = validarOpcao();

    if (tolower(opcao) == 's')
    {
        limparTela();
        return;
    }
    else if (tolower(opcao == 'n'))
    {
        limparTela();
        mensagemFinal();
        exit(0);
    }
}

void limparTela()
{
    // essa função assim como todo os programas foi pensando para que ele funciona em qualquer sistema operacional
#if defined(_WIN32)
    system("cls");
#elif defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

void limparBuffer()
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int lerOpcao(int tamanho) {
    int codigo;
  
    do {
        printf("Digite a opção desejada : ");

    if(scanf("%d", &codigo) == 1) {
        limparBuffer();
        return codigo;
    }
    else if (codigo >= 1 && codigo <=tamanho)
    {
        limparBuffer();
        limparTela();
        return 99;
    }
    }while(1); }

void pausaEnter() {

    printf("Pressione ENTER para continuar...\n");

    int ch = getchar();
    while(ch != '\n' && ch != EOF) {
        ch = getchar();
  }

}

char validarOpcao() {

    char opcao;

    do {
        opcao = tolower(getchar());
        limparBuffer(); 
    if(opcao != 's' && opcao != 'n') {
        printf("Opção inválida. Digite apenas s ou n.\n");
    }

  } while(opcao != 's' && opcao != 'n');
    return opcao;

}

void mensagemFinal(){
    printf("\nFIM DO PROGRAMA!\n\n");
    printf("Obrigado por usar nosso software. Ficamos felizes em ajudar.\nAté a próxima vez!\n\n");
}

void escolhaOrdenacao(){
    printf("Como você prefere que a chave de ordenação seja? \n");
    printf("1. Ordenada\n");
    printf("2. Aleatoria\n");
}

void escolhaMetodo(){
    printf("Qual o metodo de ordenação?\n");
    printf("1. InsertionSort\n");
    printf("2. BubleSort\n");
    printf("3. ShellSort\n");
    printf("4. MergeSort\n");   
    printf("5. QuickSort\n");
    printf("6. SEXO\\n");

}

void escolhaContinuar(){
    printf("Deseja continuar executando com uma nova Seed?\n");
    printf("1. Sim\n");
    printf("2. Não\n");

}

void escolhaOrdenada(int tamanho){
    char tipo = 'a';
    clock_t inicio, fim;
    double tempo_execucao;
    int escolha,escolha2,escolha3,escolha4;
    int c = 0;
    no *vetor;
    tempo tempo1[10];
    escolhaMetodo();
    escolha3 = lerOpcao(6);
    limparTela();
    switch(escolha3){
    
        case 1:
            do {
                for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorOrdenado(vetor,tamanho,c);
                inicio = clock();
                insertionSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                //escolha = lerOpcao(2);

                //if (escolha==1){
                  //  imprimevetor(vetor,tamanho);
                   // }

                printf("Tempo de execução em segundos : %f\n\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                c++;
                free(vetor);
                }                                                 // libera memoria do vetor
                pausaEnter();
                limparTela();
                for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                }
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                }                                                     
                else if(escolha4 != 1){
                    voltaMenu();
                    break;}
                    
                }while(escolha4==1);    
                
            case 2:
            do {
                for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorOrdenado(vetor,tamanho,c);
                inicio = clock();
                bubbleSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                escolha = lerOpcao(2);

               /* if (escolha==1){
                    imprimevetor(vetor,tamanho);
                    } */

                printf("Tempo de execução em segundos : %f\n\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                free(vetor);                                                 // libera memoria do vetor
                pausaEnter();                
                limparTela();
                }
                for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                }
                
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                }                                                     
                else if(escolha4 != 1){
                    voltaMenu();
                    break;}
                    
                }while(escolha4==1);    


                break;

                default:
                    limparTela();
                    printf("Opção INVALIDA!\n\n");
                    pausaEnter();
                    limparTela();
                    voltaMenu();
                    break;
    }
                    
}

void escolhaAleatorio(int tamanho){
    char tipo = 'a';
    clock_t inicio, fim;
    double tempo_execucao;
    int escolha,escolha2,escolha3,escolha4;
    int c = 0;
    tempo tempo1[10];
    no *vetor;
    escolhaMetodo();
    escolha3 = lerOpcao(6);
    limparTela();
    switch(escolha3){

        case 1:
            do {
                 for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorAleatorio(vetor,tamanho,c);
                inicio = clock();
                insertionSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                /*printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                escolha = lerOpcao(2);

                if (escolha==1){
                    imprimevetor(vetor,tamanho);
                    }
                */
                printf("Tempo de execução em segundos : %f\n\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                free(vetor);                                                 // libera memoria do vetor
                pausaEnter();
                 }
                limparTela();
                for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                }
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                }                                                     
                else if(escolha4 != 1){
                    voltaMenu();
                    break;}
                    
                }while(escolha4==1);   
                case 2:
                do {
                for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorOrdenado(vetor,tamanho,c);
                imprimevetor(vetor,tamanho);
                pausaEnter();
                inicio = clock();
                bubbleSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                /*
                printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                escolha = lerOpcao(2);

                if (escolha==1){
                    imprimevetor(vetor,tamanho);
                    }
                */
                printf("Tempo de execução em segundos : %f\n\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                free(vetor); 
                }                                                // libera memoria do vetor
                pausaEnter();
                limparTela();
                for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                }
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                }                                                     
                else if(escolha4 != 1){
                    voltaMenu();
                    break;}
                    
                }while(escolha4==1);  
                break; 

                default:
                    limparTela();
                    printf("Opção INVALIDA!\n\n");
                    pausaEnter();
                    limparTela();
                    voltaMenu();
                    break;
    }
                    
}

void elseEscolha2(){
    limparTela();
    printf("Opção invalida!\n");
    voltaMenu();
    limparTela();
}
