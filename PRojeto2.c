#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h> //necessário para usar setlocale
#include <math.h>
#include <ctype.h>

// estrutura do vetor
typedef struct No{
    int chave; 
    float valor; 
} no;

typedef struct Tempo{
    double chave;
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
        
        vetor[i].chave = numero_aleatorio+i*i;
        vetor[i].valor = (float)(rand() + 100); // gera um número aleatório acima de 100 e armazena no valor
       
    }

}


// Função  Ordenação
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
        for (j=1; j<tamanho-i; j++){
            if (vetor[j].chave>vetor[j-1].chave){
                aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor [j] = aux;
        }
        
    }
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

int particao(no *v, int LI, int LS) {
    no aux;
    int e = LI;
    int d = LS - 1; // Ajuste aqui para evitar acessar v[LS], que é o pivô
    no pivo = v[LS];
    while (e <= d) {
        while (e <= d && v[e].chave > pivo.chave) {
            e++;
        }
        while (d >= e && v[d].chave <= pivo.chave) {
            d--;
        }
        if (e < d) {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
    aux = v[e];
    v[e] = v[LS];
    v[LS] = aux;
    return e;
}

void quickSort(no *v, int LI, int LS) {
    if (LI < LS) {
        int p;
        p = particao(v, LI, LS);
        quickSort(v, LI, p - 1);
        quickSort(v, p + 1, LS);
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

void mergeSort(no *v , int n){
    no *c = malloc(sizeof(no)*n);
    sort (v, c, 0, n-1);
    free(c);
    

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
    printf("1. 10e4 (10 MIL)\n");
    printf("2. 5*10e4 (50 MIL)\n");
    printf("3. 10e5 (100 MIL)\n");
    printf("4. 5*10e5 (500 mil)\n");
    printf("5. 5e6 (1 Milhão)\n");
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
        printf("Opcao invalida. Digite apenas s ou n.\n");
    }

  } while(opcao != 's' && opcao != 'n');
    return opcao;

}

void mensagemFinal(){
    printf("\nFIM DO PROGRAMA!\n\n");
    printf("Obrigado por usar nosso software. Ficamos felizes em ajudar.\nAté a próxima vez!\n\n");
}

void escolhaOrdenacao(){
    printf("Como você prefere que a chave de ordenacao seja? \n");
    printf("1. Ordenada\n");
    printf("2. Aleatoria\n");
}

void escolhaMetodo(){
    printf("Qual o metodo de ordenacao?\n");
    printf("1. InsertionSort\n");
    printf("2. BubleSort\n");
    printf("3. ShellSort\n");
    printf("4. MergeSort\n");   
    printf("5. QuickSort\n");
    printf("6. HeapSort\\n");

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
    float media = 0;
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
                //printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                //escolha = lerOpcao(2);

                //if (escolha==1){
                  //  imprimevetor(vetor,tamanho);
                   // }
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;

                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                c++;
                free(vetor);
                }                                                 // libera memoria do vetor
                pausaEnter();
                limparTela();
                for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);

                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                /*if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                } */                                                    
                if(escolha4 != 1){
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

               // printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
               // escolha = lerOpcao(2);

               /* if (escolha==1){
                    imprimevetor(vetor,tamanho);
                    } */
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                free(vetor);                                                 // libera memoria do vetor                
                }
                pausaEnter();
                limparTela();
             for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
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
        case 3:
            do {
                for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorOrdenado(vetor,tamanho,c);
                inicio = clock();
                shellSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                //printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                //escolha = lerOpcao(2);

                //if (escolha==1){
                  //  imprimevetor(vetor,tamanho);
                   // }
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
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
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                /*if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                } */                                                    
                if(escolha4 != 1){
                    voltaMenu();
                    break;}
                    
                }while(escolha4==1);    
            break;

            case 4:
                do {
                 for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorOrdenado(vetor,tamanho,c);
                inicio = clock();
                mergeSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                /*printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                escolha = lerOpcao(2);

                if (escolha==1){
                    imprimevetor(vetor,tamanho);
                    }
                */
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
                printf("Seed : %d\n",22011027+c);
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                c++;
                free(vetor);                                                 // libera memoria do vetor
                 }
                limparTela();
                pausaEnter();
                limparTela();
             for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
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
        case 5:
            do {
                for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorOrdenado(vetor,tamanho,c);
                inicio = clock();
                quickSort(vetor,0,tamanho-1);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                //printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                //escolha = lerOpcao(2);

                //if (escolha==1){
                  //  imprimevetor(vetor,tamanho);
                   // }
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                c++;
                free(vetor);
                }                                                 // libera memoria do vetor
                pausaEnter();
                limparTela();
             for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                /*if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                } */                                                    
                if(escolha4 != 1){
                    voltaMenu();
                    break;}
                    
                }while(escolha4==1);    
                       
        case 6:
            do {
                for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorOrdenado(vetor,tamanho,c);
                inicio = clock();
                heapSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                //printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                //escolha = lerOpcao(2);

                //if (escolha==1){
                  //  imprimevetor(vetor,tamanho);
                   // }
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
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
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                /*if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                } */                                                    
                if(escolha4 != 1){
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
    float media;
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
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                c++;
                free(vetor); 
                }                                                // libera memoria do vetor
                pausaEnter();
                limparTela();
                   for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
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
                criarVetorAleatorio(vetor,tamanho,c);
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
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
                printf("Seed : %d\n\n",c+22011027);
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                c++;
                free(vetor); 
                }                                                // libera memoria do vetor
                pausaEnter();
                limparTela();
                  for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
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
        case 3:
            do {
                for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorAleatorio(vetor,tamanho,c);
                inicio = clock();
                shellSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                //printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                //escolha = lerOpcao(2);

                //if (escolha==1){
                  //  imprimevetor(vetor,tamanho);
                   // }
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                c++;
                free(vetor);
                }                                                 // libera memoria do vetor
                pausaEnter();
                limparTela();
              for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                /*if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                } */                                                    
                if(escolha4 != 1){
                    voltaMenu();
                    break;}
                    
                }while(escolha4==1);    
            break;

                case 4:
                do {
                 for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorAleatorio(vetor,tamanho,c);
                inicio = clock();
                mergeSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                /*printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                escolha = lerOpcao(2);

                if (escolha==1){
                    imprimevetor(vetor,tamanho);
                    }
                */
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                c++;
                free(vetor);                                                 // libera memoria do vetor 
                 }
                pausaEnter();
                limparTela();
             for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                }                                                     
                else if(escolha4 != 1){
                    voltaMenu();
                    escolha4=0;
                    break;}
                    
                }while(escolha4==1);   
                break;
        case 5:
            do {
                for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorAleatorio(vetor,tamanho,c);
                inicio = clock();
                quickSort(vetor,0,tamanho-1);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                //printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                //escolha = lerOpcao(2);

                //if (escolha==1){
                  //  imprimevetor(vetor,tamanho);
                   // }
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
                printf("Seed : %d\n",c+22011027);
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                tempo1[k].chave = tempo_execucao;
                tempo1[k].seed = 22011027+c;
                c++;
                free(vetor);
                }                                                 // libera memoria do vetor
                pausaEnter();
                limparTela();
             for(int m=0;m<10;m++){
                    printf("Tempo do vetor %d : %f\nSemente do vetor %d : %d\n\n",m,tempo1[m].chave,m,tempo1[m].seed);
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                /*if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                } */                                                    
                if(escolha4 != 1){
                    voltaMenu();
                    break;}
                    
                }while(escolha4==1);  
        case 6:
            do {
                for(int k=0;k<10;k++){
                vetor= (no *)malloc(tamanho * sizeof(no));
                criarVetorAleatorio(vetor,tamanho,c);
                inicio = clock();
                heapSort(vetor,tamanho);
                fim  = clock();
                tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Calcula o tempo decorrido em segundos
                //printf("Deseja imprimir o vetor?\n1. Sim\n2. Não\n");
                //escolha = lerOpcao(2);

                //if (escolha==1){
                  //  imprimevetor(vetor,tamanho);
                   // }
                printf("primeiro elemento %d , ultimo elemento %d\n\n",vetor[0].chave,vetor[tamanho-1].chave);
                printf("Tempo de execução em segundos : %f\n",tempo_execucao);
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
                    media = media + tempo1[m].chave;     
                }
                media = media/10;
                printf("\nMedia : %f",media);
                escolhaContinuar();
                escolha4 = lerOpcao(2);
                limparTela();
                /*if (escolha4 == 1){
                    c++;                             // usada para mudar a seed
                } */                                                    
                if(escolha4 != 1){
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
