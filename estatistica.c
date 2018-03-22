#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define LIMPAR "cls"

// Prototipos de funcoes para o menu
void menu(void);
void inserirDados(void);
void calcular(void);
void qualitativo(void);
void quantitativo(void);

// Prototipos de funcoes para os calculos
void rol(double arr[]);
double mediaArit(const double arr[]);
double mediaPond(double arr[]);
double mediana(double arr[]);
double moda(double arr[]);

// Prototipos de funcoes auxiliares
double maximo(const double arr[]);
void printArray(const double arr[]);

// Variaveis globais
char gTipo;
double gDadosQuant[SIZE] = {0};
char gDadosQuali[SIZE][SIZE];
int gTamanho;

int main(){
    system(LIMPAR);
    menu();
    return 0;
}

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
        break;
    }
}

void inserirDados(void){ // Inserir os dados
    printf("=====================================\n");
    printf("                 DADOS               \n");
    printf("=====================================\n");
    printf("[1] Qualitativo\n");
    printf("[2] Quantitativo\n");
    printf("=======================================\n");
    printf(">> ");

    int val;
    scanf("%d", &val);
    switch(val){
        case 1:
        system(LIMPAR);
        break;

        case 2:
        system(LIMPAR);
        quantitativo();
        break;

        default:
        break;
    }

}


void qualitativo(void){ // Inserir dados quanlitativos
    gTipo = 'l';

    printf("=======================================\n");
    printf("                 DADOS                 \n");
    printf("=======================================\n");
    printf("[1] Nominal\n");
    printf("[2] Ordinal\n");
    printf("=======================================\n");
    printf(">> ");

    int val;
    scanf("%d", &val);
    switch(val){
        case 1:
        system(LIMPAR);
        break;

        case 2:
        system(LIMPAR);
        break;

        default:
        break;
    }
}

void quantitativo(void){ // Inserir dados quantitativos
    gTipo = 't';
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
        scanf("%lf", &gDadosQuant[dados]);
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
        rol(gDadosQuant);
        printf("ROL -> ");
        printArray(gDadosQuant);
        calcular();
        break;

        case 2:
        system(LIMPAR);
        break;

        case 3:
        system(LIMPAR);
        printf("Media Aritmetica: %.2f\n", mediaArit(gDadosQuant));
        calcular();
        break;

        case 4:
        system(LIMPAR);
        calcular();
        break;

        case 5:
        system(LIMPAR);
        printf("Mediana: %.2f\n", mediana(gDadosQuant));
        calcular();
        break;

        case 6:
        system(LIMPAR);
        printf("Moda: %.2f\n", moda(gDadosQuant));
        calcular();
        break;

        default:
        break;
    }
}

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

double mediaPond(double arr[]){ // Retorna a media ponderada de um conjunto de dados flutuantes
  // SOME CODE
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

double moda(double arr[]){
    rol(arr); // Ordenar os dados
    int i; // Contador para percorrer o conjunto
    int frequencia[gTamanho];
    int indice;
    int cont = 0; // Contador de vezes que um número se repete
    int max = 0;

    for(i = 0; i < gTamanho; i++){
        cont++;
        if(i == gTamanho - 1 || arr[i] != arr[i + 1]){
            frequencia[i] = cont;
            cont = 0;
        }
    }

    for(i = 0; i < gTamanho; i++){
        if(frequencia[i] > max){
            max = frequencia[i];
            indice = i;
        }
    }

    return arr[indice];
}

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
