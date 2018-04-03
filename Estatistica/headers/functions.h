/* Include guards */
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000
#define LIMPAR "cls"

/* Prototypes of the functions */
void rol(double arr[], int len);
void intervaloDeClasses(double arr[], int len);
double mediaArit(const double arr[], int len);
double mediaPond(const double arr[], int len);
void moda(double arr[], int len);
double porcentagem(const double arr[], int len);
double mediana(double arr[], int len);
double quartil(double arr[], int len);
double decil(double arr[], int len);
double percentil(double arr[], double p, int len);
double variancia(const double arr[], int len);
double desvioPadrao(const double arr[], int len);
double coeficienteDeVariacao(const double arr[], int len);
double erroPadrao(const double arr[]); // Falta fazer
double distribuicaoBinomial(const double arr[]); // Falta fazer
double distribuicaoDePoisson(const double arr[]); // Falta fazer

#endif // FUNCTIONS_H_INCLUDED
