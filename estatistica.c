#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define LIMPAR "cls"

// Prototipos de funcoes para o menu
void menu(void);
void inserirDados(void);
void calcular(void);

// Prototipos de funcoes para os calculos
void rol(double arr[]);
double intervaloDeClasses(double arr[]); // Falta fazer
double mediaArit(const double arr[]);
double mediaPond(const double arr[]);
void moda(double arr[]);
double mediana(double arr[]);
double quartil(double arr[]);
double decil(double arr[]);
double percentil(double arr[]);
double varianca(const double arr[]);
double desvioPadrao(const double arr[]);
double coeficienteDeVariacao(const double arr[]); // Falta fazer

// Prototipos de funcoes auxiliares
double maximo(const double arr[]);
void printArray(const double arr[]);

// Variaveis globais
double gDados[SIZE] = {0};
int gTamanho;

int main(){
    system(LIMPAR);
    menu();
    return 0;
}

/* =================================================================================
                                FUNÇÕES DO MENU
   ================================================================================= */

void menu(void){ // Menu de opcoes
    printf("====================================\n");
    printf("                 MENU               \n");
    printf("====================================\n");
    printf("[1] Inserir dados\n");
    printf("[2] Calcular\n");
    printf("\n                          [0] Sair\n");
    printf("====================================\n");
    printf(">> ");

    int val;
    scanf("%d", &val);
    switch(val){
        case 0:
        break;

        case 1:
        system(LIMPAR);
        inserirDados();
        break;

        case 2:
        system(LIMPAR);
        calcular();
        break;

        default:
        system(LIMPAR);
        printf("ERRO! Valor inserido nao permitido.\n");
        menu();
        break;
    }
}

void inserirDados(void){ // Inserir os dados
    int dados; // Contador para inserir os dados flutuantes

    printf("=======================================\n");
    printf("                 DADOS                 \n");
    printf("=======================================\n");
    printf("Digite a quantidade de Dados:\n");
    printf("=======================================\n");
    printf(">> ");

    scanf("%d", &gTamanho);
    system(LIMPAR);

    printf("=======================================\n");
    printf("                 DADOS                 \n");
    printf("=======================================\n");
    printf("Inserir Dados::\n");
    printf("=======================================\n");
    printf(">> ");

    for(dados = 0; dados < gTamanho; dados++){
        scanf("%lf", &gDados[dados]);
    }

    system(LIMPAR);
    menu();
}

void calcular(void){ // Calcular dados
    printf("=======================================\n");
    printf("                 CALCULAR              \n");
    printf("=======================================\n");
    printf(" [1] ROL\n");
    printf(" [2] Intervalo de Classes\n");
    printf(" [3] Media Aritmetica\n");
    printf(" [4] Media Ponderada\n");
    printf(" [5] Mediana\n");
    printf(" [6] Moda\n");
    printf(" [7] Porcentagem\n");
    printf(" [8] Quartil\n");
    printf(" [9] Decil\n");
    printf("[10] Percentil\n");
    printf("[11] Variancia\n");
    printf("[12] Desvio Padrao\n");
    printf("[13] Coeficiente de Variacao\n");
    printf("[14] Erro Padrao\n");
    printf("[15] Probabilidade Basica\n");
    printf("[16] Distribuicao Binomial\n");
    printf("[17] Distribuicao de Poisson\n");
    printf("\n                           [0] Voltar\n");
    printf("=======================================\n");
    printf(">> ");

    int val;
    scanf("%d", &val);
    switch(val){
        case 0:
        system(LIMPAR);
        menu();
        break;

        case 1:
        system(LIMPAR);
        rol(gDados);
        printf("ROL -> ");
        printArray(gDados);
        calcular();
        break;

        case 2:
        system(LIMPAR);
        break;

        case 3:
        system(LIMPAR);
        printf("Media Aritmetica: %.2f\n", mediaArit(gDados));
        calcular();
        break;

        case 4:
        system(LIMPAR);
        printf("Media Ponderada: %.2f\n", mediaPond(gDados));
        calcular();
        break;

        case 5:
        system(LIMPAR);
        printf("Mediana: %.2f\n", mediana(gDados));
        calcular();
        break;

        case 6:
        system(LIMPAR);
        moda(gDados);
        calcular();
        break;

        case 7:
        break;

        case 8:
        system(LIMPAR);
        calcular();
        break;

        default:
        system(LIMPAR);
        printf("ERRO! Valor inserido nao permitido.");
        calcular();
        break;
    }
}

/* =================================================================================
                                FUNÇÕES PARA CALCULAR
   ================================================================================= */

void rol(double arr[]){ // Funcao de ordenação
    int i;
    int j;
    double aux; // Segurar valor para a troca

    for(i = 0; i < gTamanho - 1; i++){
        for(j = i + 1; j < gTamanho; j++){
            if(arr[j] < arr[i]){
                aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
            }
        }
    }
}

double mediaArit(const double arr[]){ // Retorna a media aritmetica de um conjunto de dados flutuantes
    double soma; // Soma de todos os valores do conjunto de dados
    int dado; // Contador para a soma dos dados do vetor

    for(dado = 0; dado < gTamanho; dado++){
        soma += arr[dado];
    }

    return soma/gTamanho;
}

double mediaPond(const double arr[]){ // Retorna a media ponderada de um conjunto de dados flutuantes
  int pesos[gTamanho];
  int somaPesos = 0;
  double somaValores = 0;

  for(int p = 0; p < gTamanho; p++){
      printf(">> Digite o peso do valor %.2f:\n>> ", arr[p]);
      scanf("%d", &pesos[p]); // Adicionar pesos em uma lista
      system(LIMPAR); // Limpar a tela
      somaPesos += pesos[p]; // Recebe a soma dos pesos
      somaValores += arr[p] * pesos[p]; // Recebe soma dos valores multiplicados por seus respectivos pesos
  }

  return somaValores/somaPesos;
}

void moda(double arr[]){
    rol(arr); // Ordenar os dados
    double frequencia[gTamanho]; // Lista de frequencia
    int cont = 0;
    double max;

    for(int f = 0; f < gTamanho; f++){ // Calcula a frequencia
        cont++;
        if(f == (gTamanho - 1) || arr[f] != arr[f + 1]){
            frequencia[f] = (double)cont;
            cont = 0;
        }
    }

    max = maximo(frequencia); // Recebe o maior valor do conjunto de dados

    printf("Moda: ");
    for(int i = 0; i < gTamanho; i++){ // Encontra a(s) moda(s) e depois imprime
        if(frequencia[i] == max){
            printf("(%.0f) %.2f ", frequencia[i], arr[i]);
        }
    }
    printf("\n");
}

double mediana(double arr[]){
    rol(arr); // Ordenar o conjunto
    int indice; // Indice do valor da mediana

    if(gTamanho % 2 == 0){
        indice = (int)(gTamanho + 1)/2;
        return (arr[indice - 1] + arr[indice])/2; // Como o intervalo do array começa de 0, então reduzimos um valor ao indice
    } else if(gTamanho % 2 == 1){
        indice = (gTamanho + 1)/2;
        return arr[indice - 1]; // Como o intervalo do array começa de 0, então reduzimos um valor ao indice
    }
}

/* =================================================================================
                                FUNÇÕES AUXILIARES
   ================================================================================= */

double maximo(const double arr[]){ // Retorna o indice do valor maximo do vetor
    int dado; // Contador para passar pelos dados
    double max; // Valor maximo

    max = arr[0];
    for(dado = 1; dado < gTamanho; dado++){
        if(arr[dado] > max){
            max = arr[dado];
        }
    }

    return max;
}

void printArray(const double arr[]){
  int dado; // Contador para percorrer os dados

  for(dado = 0; dado < gTamanho; dado++){ // Loop para imprimir o conjunto de dados
    printf("%.2f ", arr[dado]);
  }
  printf("\n");
}
