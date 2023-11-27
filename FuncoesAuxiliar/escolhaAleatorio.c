#include "declaracaoFuncao.h"
#include <time.h>
#include <math.h>
#include <ctype.h>



void escolhaAleatorio(int tamanho){
    clock_t inicio, fim;
    double tempo_execucao;
    int escolha3,escolha4;
    tempo tempo1[10];
    no *vetor;
    int c;
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
                    voltaMenu();
                    break;                            
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
