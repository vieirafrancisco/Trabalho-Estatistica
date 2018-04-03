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
  for(int dado = 0; dado < len; dado++){ /* loop to print array */
    printf("%.2f ", arr[dado]);
  }
  printf("\n");
}

double amplitude(double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
    sort(arr, len); /* sort the set */

    return arr[len - 1] - arr[0];
}

double sort(double arr[], int len){
    /*  arr: array to the values
        len: length of the array */
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

int unique(const double arr[], int size){
    int difNumbers = 1; /* number os diferent numbers */

    for(int i = 0; i < size - 1; i++){
        if(arr[i] != arr[i + 1]){
            difNumbers++;
        }
    }

    return difNumbers;
}

void frequency(const double arr[], double freq[], int index[], int size){
    int fsize = 1;
    freq[0] = arr[0];
    index[0] = 0;
    for(int i = 0; i < size - 1; i++){
        if(arr[i] != arr[i + 1]){
            freq[fsize] = arr[i + 1];
            index[fsize] = i + 1;
            fsize++;
        }
    }
    int cont = 0;

    for(int i = 0; i < fsize; i++){
        for(int j = 0; j < size; j++){
            if(freq[i] == arr[j]){
                cont++;
            }
        }
        freq[i] = cont;
        cont = 0;
    }
}
