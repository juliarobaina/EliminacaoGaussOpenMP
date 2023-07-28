#include "alocacaoDinamica.h"

double* alocarVetor(int tam){
	
	double* novo = (double*) calloc(tam,sizeof(double));

	return novo;
}

double** alocarMatriz(int ordem){
	
	double** novo = (double**) calloc(ordem,sizeof(double*));
	
	for (int i = 0; i < ordem; i++){
		novo[i] = alocarVetor(ordem);
	}

	return novo;
}

void liberarMatriz(double** matriz,int ordem){

	for(int i = 0;i < ordem;i++){
		free(matriz[i]);
	}

	free(matriz);
}