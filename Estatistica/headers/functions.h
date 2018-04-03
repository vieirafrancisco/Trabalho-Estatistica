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
double variancia(const double arr[], char type, int len);
double desvioPadrao(const double arr[], char type, int len);
double coeficienteDeVariacao(const double arr[], char type, int len);
double erroPadrao(double arr[], int type, int len);
double distribuicaoBinomial(double p, int n, int k);
double distribuicaoPoisson(double lamb, int k);

#endif // FUNCTIONS_H_INCLUDED
