#include "metodosDiretos.c"

void randomizaArquivo(FILE *arquivoA, FILE *arquivoB, int tamanhoMatriz);

int main(int argc, char *argv[])
{

    int ordem = atoi(argv[1]);

    FILE *A = fopen("E.txt", "r"), *B = fopen("F.txt", "r"); // carrega arquivos
    double *vetorSolucao = alocarVetor(ordem);

    eliminacaoGauss(A, B, ordem);

    fclose(A), fclose(B), free(vetorSolucao);

    return 0;
}