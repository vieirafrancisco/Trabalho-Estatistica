#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1000
#define LIMPAR "cls"

// Prototipos de funcoes para o menu
void menu(void);
void inserirDados(void);
void calcular(void);

// Prototipos de funcoes para os calculos
void rol(double arr[]);
double intervaloDeClasses(double arr[]);
double mediaArit(const double arr[]);
double mediaPond(const double arr[]);
void moda(double arr[]);
void porcentagem(double arr[]); // Falta fazer
double mediana(double arr[]);
double quartil(double arr[]);
double decil(double arr[]);
double percentil(double arr[], double p);
double variancia(const double arr[]);
double desvioPadrao(const double arr[]);
double coeficienteDeVariacao(const double arr[]);
double erroPadrao(const double arr[]); // Falta fazer
double distribuicaoBinomial(const double arr[]); // Falta fazer
double distribuicaoDePoisson(const double arr[]); // Falta fazer

// Prototipos de funcoes auxiliares
double maximo(const double arr[]);
void printArray(const double arr[]);
double amplitude(double arr[]);

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

    char val;
    scanf(" %c", &val);
    switch(val){
        case '0':
        break;

        case '1':
        system(LIMPAR);
        inserirDados();
        break;

        case '2':
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
    printf("Inserir Dados:\n");
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
    printf("[1] ROL\n");
    printf("[2] Intervalo de Classes\n");
    printf("[3] Media Aritmetica\n");
    printf("[4] Media Ponderada\n");
    printf("[5] Mediana\n");
    printf("[6] Moda\n");
    printf("[7] Porcentagem\n");
    printf("[8] Quartil\n");
    printf("[9] Decil\n");
    printf("[a] Percentil\n");
    printf("[b] Variancia\n");
    printf("[c] Desvio Padrao\n");
    printf("[d] Coeficiente de Variacao\n");
    printf("[e] Erro Padrao\n");
    printf("[f] Distribuicao Binomial\n");
    printf("[g] Distribuicao de Poisson\n");
    printf("\n                           [0] Voltar\n");
    printf("=======================================\n");
    printf(">> ");

    char val;
    scanf(" %c", &val);
    switch(val){
        case '0':
        system(LIMPAR);
        menu();
        break;

        case '1':
        system(LIMPAR);
        rol(gDados);
        printf("ROL -> ");
        printArray(gDados);
        calcular();
        break;

        case '2':
        system(LIMPAR);
        printf("Intervalo de Classes: %.2f\n", intervaloDeClasses(gDados));
        calcular();
        break;

        case '3':
        system(LIMPAR);
        printf("Media Aritmetica: %.2f\n", mediaArit(gDados));
        calcular();
        break;

        case '4':
        system(LIMPAR);
        printf("Media Ponderada: %.2f\n", mediaPond(gDados));
        calcular();
        break;

        case '5':
        system(LIMPAR);
        printf("Mediana: %.2f\n", mediana(gDados));
        calcular();
        break;

        case '6':
        system(LIMPAR);
        moda(gDados);
        calcular();
        break;

        case '7':
        system(LIMPAR);
        calcular();
        break;

        case '8':
        system(LIMPAR);
        printf("Quartil: %.2f\n", quartil(gDados));
        calcular();
        break;

        case '9':
        system(LIMPAR);
        printf("Decil: %.2f\n", decil(gDados));
        calcular();
        break;

        case 'a':
        system(LIMPAR);
        printf("============================================================\n");
        printf("Digite a medida do percentil: (ex: 0.24 = 24%%, 0.38 = 38%%)\n");
        printf(">> ");

        float medida;
        scanf("%f", &medida);
        system(LIMPAR);

        printf("Percentil %.2f: %.2f\n", medida, percentil(gDados, medida));
        calcular();
        break;

        case 'b': // Variancia
        system(LIMPAR);
        printf("Variancia: %.2f\n", variancia(gDados));
        calcular();
        break;

        case 'c':
        system(LIMPAR);
        printf("Desvio Padrao: %.2f\n", desvioPadrao(gDados));
        calcular();
        break;

        case 'd':
        system(LIMPAR);
        printf("Coeficiente de Variacao: %.2f\n", coeficienteDeVariacao(gDados));
        calcular();
        break;

        default:
        system(LIMPAR);
        printf("ERRO! Valor inserido nao permitido.\n");
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

double intervaloDeClasses(double arr[]){
    double amp = amplitude(arr);
    double k = round(sqrt(gTamanho));
    double h;

    h = amp / k;

    return h;
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

double quartil(double arr[]){
    double per; // Valor do percentil

    printf("====================================\n");
    printf("[1] Primeiro Quartil\n");
    printf("[2] Segundo Quartil\n");
    printf("[3] Terceiro Quartil\n");
    printf("====================================\n");
    printf(">> ");

    char v; // Variavel do tipo char para escolher uma das opções anteriores
    scanf(" %c", &v);
    system(LIMPAR);

    if(v == '1'){
        per = percentil(arr, 0.25);
    } else if(v == '2'){
        per = percentil(arr, 0.50);
    } else if(v == '3'){
        per = percentil(arr, 0.75);
    } else{
        printf("ERRO! Valor inserido nao permitido.\n");
    }

    return per;
}

double decil(double arr[]){
    double per; // Valor do percentil

    printf("====================================\n");
    printf("Digite qual Decil(de 1 a 9)\n");
    printf("====================================\n");
    printf(">> ");

    int v;
    scanf("%d", &v);
    system(LIMPAR);

    if(v >= 1 && v <= 9){
        per = percentil(arr, 0.1*v);
    } else{
        printf("ERRO! Valor inserido nao permitido.\n");
    }

    return per;
}

double percentil(double arr[], double p){
    rol(arr); // Ordenar conjunto de dados
    double per = p * (gTamanho + 1);
    int indice = (int) per;

    if(indice == per){
        return arr[indice - 1];
    } else if(indice == 0){
        return arr[indice];
    }else{
        return (arr[indice - 1] + arr[indice])/2;
    }
}

double variancia(const double arr[]){
    double X = mediaArit(arr); // Média do conjunto de dados
    double soma = 0;
    char c;

    for(int i = 0; i < gTamanho; i++){
        soma += (arr[i] - X) * (arr[i] - X);
    }

    printf("====================================\n");
    printf("[1] Amostra\n");
    printf("[2] Populacao\n");
    printf("====================================\n");
    printf(">> ");

    scanf(" %c", &c);
    system(LIMPAR);

    if(c == '1'){
        return soma/(gTamanho - 1);
    } else if(c == '2'){
        return soma/gTamanho;
    } else{
        printf("ERRO! Valor inserido nao permitido.\n");
        return 0;
    }
}

double desvioPadrao(const double arr[]){
    double var = variancia(arr); // Variancia

    return pow(var, 0.5); // Raiz quadrada da variancia
}

double coeficienteDeVariacao(const double arr[]){
    double s = desvioPadrao(arr); // Desvio padrão
    double X = mediaArit(arr); // Média do conjunto

    return (s/X) * 100;
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

double amplitude(double arr[]){
    rol(arr); // Ordenar o conjunto de dados

    return arr[gTamanho - 1] - arr[0];
}
