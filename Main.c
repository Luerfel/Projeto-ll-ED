#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

// declaração do cabecalho
#include "FuncoesAuxiliar/declaracaoFuncao.h"
#include "FuncoesAuxiliar/FuncoesAuxiliares.c"
#include "FuncoesAuxiliar/criacaoVetores.c"
#include "FuncoesAuxiliar/escolhaAleatorio.c"
#include "FuncoesAuxiliar/escolhaOrdenada.c"
#include "insertionSort.c"
#include "bubbleSort.c"
#include "quickSort.c"
#include "heapSort.c"
#include "mergeSort.c"
#include "shellSort.c"



int main(){
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








    }


