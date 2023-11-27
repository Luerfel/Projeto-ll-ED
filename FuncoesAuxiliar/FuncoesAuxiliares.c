#include "declaracaoFuncao.h"


// essas funções serve para auxiliar na execução do programas, aqui tem funçoes como limpar o Buffer ou apagar a tela e as mensagens do menu

void elseEscolha2(){
    limparTela();
    printf("Opção invalida!\n");
    voltaMenu();
    limparTela();
}

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
    printf("2. BubbleSort\n");
    printf("3. ShellSort\n");
    printf("4. MergeSort\n");   
    printf("5. QuickSort\n");
    printf("6. HeapSort\n");

}

void escolhaContinuar(){
    printf("Deseja continuar executando com uma nova Seed?\n");
    printf("1. Sim\n");
    printf("2. Não\n");

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

void imprimevetor(no *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++)
    {

        printf("Chave: %d, Valor: %.2f\n", vetor[i].chave, vetor[i].valor); // imprime a chave e o valor
    }
    printf("Primeiro elemento : %d\nUltimo elemento : %d\n",vetor[0].chave,vetor[tamanho-1].chave);
}
