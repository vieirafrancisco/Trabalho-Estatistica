#include "../headers/functions.h"
#include "../headers/support.h"

/* Main functios */
void rol(double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    sort(arr, len);
}

void intervaloDeClasses(double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    rol(arr, len); /* sort the set */
    double amp = amplitude(arr, len);
    int k; /* number of classes */
    double h;
    double limInferior;
    double limSuperior;

    printf("Digite o numero de classes:\n");
    scanf("%d", &k);
    system(LIMPAR);

    h = round((amp / k) * 100)/100; /* class amplitude */
    limInferior = arr[0];
    limSuperior = limInferior + h;

    for(int i = 0; i < (int)k; i++){
        printf("%.2f |--- %.2f\n", limInferior, limSuperior);
        limInferior = limSuperior;
        limSuperior = limInferior + h;
    }
}

double mediaArit(const double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    double soma; /* sum */

    for(int dado = 0; dado < len; dado++){
        soma += arr[dado];
    }

    return soma/len;
}

double mediaPond(const double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    int pesos[len];
    int somaPesos = 0;
    double somaValores = 0;

    for(int p = 0; p < len; p++){
        printf(">> Digite o peso do valor %.2f:\n>> ", arr[p]);
        scanf("%d", &pesos[p]); /* add weight to a array */
        system(LIMPAR); /* clean screen */
        somaPesos += pesos[p]; /* receive sum of weights */
        somaValores += arr[p] * pesos[p]; /* receive the values multiplied for their weights */
    }

    return somaValores/somaPesos;
}

void moda(double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    rol(arr, len); /* sort the set */
    int freqLength;
    int cont = 0;
    double max;

    freqLength = unique(arr, len); /* return number of the diferent values int the array */

    double frequencia[freqLength]; /* array of frequency */
    int indice[freqLength]; /* array of index */
    frequency(arr, frequencia, indice, len); /* store the frequency in the frequencia array */
    max = maximo(frequencia, freqLength); /* receive the biggest value of the frequency array */

    printf("Moda: ");
    for(int i = 0; i < freqLength; i++){ /* find the mode and print */
        if(frequencia[i] == max){
            printf("(%.0f) %.2f ", frequencia[i], arr[indice[i]]);
        }
    }
    printf("\n");
}

double porcentagem(const double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    double n1, n2; // Variaveis para valores dados pelo unsuario
    double porc; // Porcentagem
    int cont = 0; // Contador

    printf("====================================\n");
    printf("[1] Menor\n");
    printf("[2] Maior\n");
    printf("[3] Igual\n");
    printf("[4] Intervalo\n");
    printf("====================================\n");
    printf(">> ");

    char escolha;
    scanf(" %c", &escolha);

    system(LIMPAR);
    if(escolha == '1'){
        printf("Digite um valor para saber a porcentagem dos valores menores que ele:\n");
        printf(">> ");
        scanf("%lf", &n1);
        for(int i = 0; i < len; i++){
            if(arr[i] < n1){
                cont++;
            }
        }
    } else if(escolha == '2'){
        printf("Digite um valor para saber a porcentagem dos valores maiores que ele:\n");
        printf(">> ");
        scanf("%lf", &n1);
        for(int i = 0; i < len; i++){
            if(arr[i] < n1){
                cont++;
            }
        }
    } else if(escolha == '3'){
        printf("Digite um valor para saber a porcentagem dos valores iguais a ele:\n");
        printf(">> ");
        scanf("%lf", &n1);
        for(int i = 0; i < len; i++){
            if(arr[i] == n1){
                cont++;
            }
        }
    } else if(escolha == '4'){
        printf("Digite os valorres de um intervalo para saber a porcentagem dos valores presentes nele:\n");
        printf(">> ");
        scanf("%lf%lf", &n1, &n2);
        for(int i = 0; i < len; i++){
            if(arr[i] >= n1 && arr[i] <= n2){
                cont++;
            }
        }
    }
    porc = (cont * 100)/len;
    system(LIMPAR);

    return porc;
}

double mediana(double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    rol(arr, len); // Ordenar o conjunto
    int indice; // Indice do valor da mediana

    if(len % 2 == 0){
        indice = (int)(len + 1)/2;
        return (arr[indice - 1] + arr[indice])/2; // Como o intervalo do array começa de 0, então reduzimos um valor ao indice
    } else if(len % 2 == 1){
        indice = (len + 1)/2;
        return arr[indice - 1]; // Como o intervalo do array começa de 0, então reduzimos um valor ao indice
    }
}

double quartil(double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
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
        per = percentil(arr, 0.25, len);
    } else if(v == '2'){
        per = percentil(arr, 0.50, len);
    } else if(v == '3'){
        per = percentil(arr, 0.75, len);
    } else{
        printf("ERRO! Valor inserido nao permitido.\n");
    }

    return per;
}

double decil(double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    double per; // Valor do percentil

    printf("====================================\n");
    printf("Digite qual Decil(de 1 a 9)\n");
    printf("====================================\n");
    printf(">> ");

    int v;
    scanf("%d", &v);
    system(LIMPAR);

    if(v >= 1 && v <= 9){
        per = percentil(arr, 0.1*v, len);
    } else{
        printf("ERRO! Valor inserido nao permitido.\n");
    }

    return per;
}

double percentil(double arr[], double p, int len){
    /*  arr: array to the values
        p: percentile
        len: length of the array */
    rol(arr, len); // Ordenar conjunto de dados
    double per = p * (len + 1);
    int indice = (int) per;

    if(indice >= len){ // Caso o valor do indice esteja acima do ultimo valor do indice
        return arr[len - 1]; // Retornar o último valor do conjunto
    } else if(indice == 0){ // Caso a valor do indice esteja abaixo do primeiro valor do conjunto
        return arr[indice]; // Retornar o primeiro valor do conjunto
    }else if(indice == per){ // Caso o valor do percentil já seja um valor inteiro
        return arr[indice - 1];;
    }else{
        return (arr[indice - 1] + arr[indice])/2;
    }
}

double variancia(const double arr[], char type, int len){
    /*  arr: array to the values
        len: length of the array */
    double X = mediaArit(arr, len); // Média do conjunto de dados
    double soma = 0;

    for(int i = 0; i < len; i++){
        soma += (arr[i] - X) * (arr[i] - X);
    }

    if(type == 'a'){ /* If is a sample */
        return soma/(len - 1);
    } else if(type == 'p'){ /* If is a population */
        return soma/len;
    }
}

double desvioPadrao(const double arr[], char type, int len){
    /*  arr: array to the values
        len: length of the array */
    double var = variancia(arr, type, len); // Variancia

    return pow(var, 0.5); // Raiz quadrada da variancia
}

double coeficienteDeVariacao(const double arr[], char type, int len){
    /*  arr: array to the values
        len: length of the array */
    double s = desvioPadrao(arr, type, len); // Desvio padrão
    double X = mediaArit(arr, len); // Média do conjunto

    return (s/X) * 100;
}

double erroPadrao(double arr[], int type, int len){
    /*  arr: array to the values
        len: length of the array */
    int tamanho;
    rol(arr, len);

    printf("Digite o tamanho da amostra:\n");
    scanf("%d", &tamanho);

    return desvioPadrao(arr, type, len)/pow(tamanho, 0.5);
}

double distribuicaoBinomial(double p, int n, int k){
    /*  p: the probability of success
        n: number of essay
        k: number of success */
    return combinacao(n,k) * (pow(p,k)) * (pow(1 - p, n - k));
}

double distribuicaoPoisson(double lamb, int k){
    /*  lamb: ocurrence rate
        k; number of success */
    double e = 2.718281828;

    return ((pow(e, lamb * -1)) * (pow(lamb, k)))/ fatorial(k);
}
