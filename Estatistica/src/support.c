#include <stdio.h>
#include "../headers/support.h"

/* Support functions */
double maximo(const double arr[], int len){ // Retorna o indice do valor maximo do vetor
    /*  arr: array to the values
        len: length of the array */
    int dado; // Contador para passar pelos dados
    double max; // Valor maximo

    max = arr[0];
    for(dado = 1; dado < len; dado++){
        if(arr[dado] > max){
            max = arr[dado];
        }
    }

    return max;
}

void printArray(const double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
  for(int dado = 0; dado < len; dado++){ // Loop para imprimir o conjunto de dados
    printf("%.2f ", arr[dado]);
  }
  printf("\n");
}

double amplitude(double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    sort(arr, len); // Ordenar o conjunto de dados

    return arr[len - 1] - arr[0];
}

double sort(double arr[], int len){
    /*  arr: array to the values
        len: length of the array*/
    double aux; /* hold value to swap */

    for(int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[i]){
                aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
            }
        }
    }
}

int fatorial(int n){
    /*  n: the value to take the fatorial */
    if(n == 0){
        return 1;
    }
    return fatorial(n - 1) * n;
}

int combinacao(int n, int k){
    /*  n: total numbers in the case
        k: the sample in the case */
    return fatorial(n)/(fatorial(k)*fatorial(n - k));
}
