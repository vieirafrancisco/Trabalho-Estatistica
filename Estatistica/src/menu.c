#include "../headers/menu.h"
#include "../headers/functions.h"
#include "../headers/support.h"

/* Global variables */
double gDados[SIZE] = {0};
int gTamanho;

/* Menu functions */
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
        rol(gDados, gTamanho);
        printf("ROL -> ");
        printArray(gDados, gTamanho);
        calcular();
        break;

        case '2':
        system(LIMPAR);
        intervaloDeClasses(gDados, gTamanho);
        calcular();
        break;

        case '3':
        system(LIMPAR);
        printf("Media Aritmetica: %.2f\n", mediaArit(gDados, gTamanho));
        calcular();
        break;

        case '4':
        system(LIMPAR);
        printf("Media Ponderada: %.2f\n", mediaPond(gDados, gTamanho));
        calcular();
        break;

        case '5':
        system(LIMPAR);
        printf("Mediana: %.2f\n", mediana(gDados, gTamanho));
        calcular();
        break;

        case '6':
        system(LIMPAR);
        moda(gDados, gTamanho);
        calcular();
        break;

        case '7':
        system(LIMPAR);
        printf("Porcentagem: %.1f%%\n", porcentagem(gDados, gTamanho));
        calcular();
        break;

        case '8':
        system(LIMPAR);
        printf("Quartil: %.2f\n", quartil(gDados, gTamanho));
        calcular();
        break;

        case '9':
        system(LIMPAR);
        printf("Decil: %.2f\n", decil(gDados, gTamanho));
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

        printf("Percentil %.2f: %.2f\n", medida, percentil(gDados, medida, gTamanho));
        calcular();
        break;

        case 'b': // Variancia
        system(LIMPAR);
        printf("Variancia: %.2f\n", variancia(gDados, gTamanho));
        calcular();
        break;

        case 'c':
        system(LIMPAR);
        printf("Desvio Padrao: %.2f\n", desvioPadrao(gDados, gTamanho));
        calcular();
        break;

        case 'd':
        system(LIMPAR);
        printf("Coeficiente de Variacao: %.2f\n", coeficienteDeVariacao(gDados, gTamanho));
        calcular();
        break;

        case 'e':
        system(LIMPAR);
        calcular();
        break;

        case 'f':
        system(LIMPAR);
        double probSucesso;
        int numEnsaios;
        int numSucessos;
        printf("Digite a probabilidade de sucesso:\n");
        scanf("%lf", &probSucesso);
        printf("Digite o numero ensaios:\n");
        scanf("%d", &numEnsaios);
        printf("Digite o numero de sucessos:\n");
        scanf("%d", &numSucessos);
        system(LIMPAR);
        printf("Distribuicao Binomial: %.4f\n", distribuicaoBinomial(probSucesso,numEnsaios,numSucessos));
        calcular();
        break;

        case 'g':
        system(LIMPAR);
        double taxaOcorrencia;
        int k;
        printf("Digite a taxa de ocorrencia:\n");
        scanf("%lf", &taxaOcorrencia);
        printf("Digite o numero de sucessos:\n");
        scanf("%d", &k);
        system(LIMPAR);
        printf("Distribuicao de Poisson: %.4f\n", distribuicaoPoisson(taxaOcorrencia, k));
        calcular();
        break;

        default:
        system(LIMPAR);
        printf("ERRO! Valor inserido nao permitido.\n");
        calcular();
        break;
    }
}
