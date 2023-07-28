#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizaArquivo(FILE *arquivoA, FILE *arquivoB, int tamanhoMatriz)
{

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            fprintf(arquivoA, "%lf ", (double)(rand() % 10000));
        }
        fprintf(arquivoA, "\n");
    }

    for (int i = 0; i < tamanhoMatriz; i++)
        fprintf(arquivoB, "%lf\n", (double)(rand() % 10000));
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    FILE *matrizA = fopen("G.txt", "w"),
         *vetorB = fopen("H.txt", "w");

    randomizaArquivo(matrizA, vetorB, atoi(argv[1]));

    fclose(matrizA), fclose(vetorB);

    return 0;
}