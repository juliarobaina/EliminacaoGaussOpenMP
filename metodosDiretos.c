/*
Trabalho de Métodos Numéricos
Alunos:
-Julia Souza Robaina Gomes
-Lucas Feitosa Damazio
-Fellipe Carreiro de Oliveira
*/
#include "metodosDiretos.h"

void eliminacaoGauss(FILE *matriz, FILE *vetorB, int ordem)
{

    double **A = malloc(ordem * sizeof(double *));
    double *B = malloc(ordem * sizeof(double *));

    for (int i = 0; i < ordem; i++)
    {

        *(A + i) = malloc(ordem * sizeof(double));
        fscanf(vetorB, "%lf", &B[i]);

        for (int j = 0; j < ordem; j++)
            fscanf(matriz, "%lf", &A[i][j]);
    }

    int size = ordem;
    int maxthreads = 4;
    int chunk;
    chunk = size / maxthreads;
    omp_set_num_threads(maxthreads);

    //ETAPA DE ESCALONAMENTO
    double F = 0;
    for (int k = 0; k < ordem - 1; k++)
    {
       /*RODA N - 1 VEZES POR QUE EU NÃO PRECISO 
    	ESCALONAR ATÉ A ÚLTIMA COLUNA PARA TER UMA 
    	MATRIZ TRIANGULAR SUPERIOR. OS 0'S VÃO ATÉ A PENÚLTIMA COLUNA.	< N - 1 -> PERCORRA ATÉ A PENÚLTIMA LINHA */

        //Se A[k][k] é zero, então a matriz dos coeficiente é singular
        //det A = 0
        if (A[k][k] == 0)
        {
            printf("A matriz dos coeficientes é singular\n");
            return;
        }
        else
        {
            
            #pragma omp parallel for shared(A,B) private(F) schedule(static, chunk)
            // realiza o escalonamento
            for (int m = k + 1; m < ordem; m++)
            {
                
                F = -A[m][k] / A[k][k];
                
                A[m][k] = 0; // evita uma iteração
                
                for (int l = k + 1; l < ordem; l++)
                {
                    //Atualização da linha, matriz[k][l] é o elemento da linha do pivô
                    A[m][l] = A[m][l] + F * A[k][l];
                }
               
                B[m] = B[m] + F * B[k];
            }
            
        }
        

    }
    double *x = alocarVetor(ordem);

    // ETAPA DE RESOLUÇÃO DO SISTEMA

    for (int i = ordem - 1; i >= 0; i--)
    {
        x[i] = B[i];
        for (int j = i + 1; j < ordem; j++)
        {
            {
                x[i] = x[i] - x[j] * A[i][j];
            }
        }
        x[i] = x[i] / A[i][i];
    }


    printf("\nVetor solucao - Eliminacao de Gauss\n");

    for (int i = 0; i < ordem; i++)
    {
        printf("x[%d] = %.5lf\n", i, x[i]);
    }

    printf("\n");
    free(x);
    free(B);
    liberarMatriz(A, ordem);
}