#ifndef _ALOCACAODINAMICAINTEIRO_H
#define _ALOCACAODINAMICAINTEIRO_H

#include <stdio.h>
#include <stdlib.h>

	double* alocarVetor(int tam);
	double** alocarMatriz(int ordem);
	void liberarMatriz(double** matriz,int ordem);


#endif