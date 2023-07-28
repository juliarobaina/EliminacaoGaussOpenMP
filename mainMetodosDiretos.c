#include "metodosDiretos.c"

void randomizaArquivo(FILE *arquivoA, FILE *arquivoB, int tamanhoMatriz);

int main(int argc, char *argv[])
{

    int ordem = atoi(argv[1]);

    FILE *A = fopen("A.txt", "r"), *B = fopen("B.txt", "r"); // carrega arquivos
    double *vetorSolucao = alocarVetor(ordem);

    eliminacaoGauss(A, B, ordem);

    fclose(A), fclose(B), free(vetorSolucao);

    return 0;
}
