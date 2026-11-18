#include <stdio.h>
#include <stdlib.h>

/*
Desenvolva um algoritmo em linguagem C que leia 10 valores inteiros e identifique quais são positivos e pares e quais são negativos e ímpares. Os valores que atenderem a cada uma dessas condições deverão ser armazenados em vetores distintos. Ao final, o programa deverá apresentar os dois conjuntos de valores, organizados em ordem crescente.
*/

int ehPar(int valor)
{
    return !(valor % 2);
}

int ehPositivo(int valor)
{
    return valor > 0;
}

void ordemCrescente(int vetor[], int quantidade)
{
    for (int i = 0; i < quantidade - 1; i++)
    {
        for (int j = 0; j < quantidade - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                int auxiliar = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = auxiliar;
            }
        }
    }
}

int main()
{
    int valores[10];
    int *paresPositivos;
    int *imparesNegativos;

    int quantidadeParesPositivos = 0;
    int quantidadeImparesNegativos = 0;
    int indiceParesPositivos = 0;
    int indiceImparesNegativos = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &valores[i]);

        if (ehPar(valores[i]) && ehPositivo(valores[i]))
        {
            quantidadeParesPositivos++;
        }

        if (!ehPar(valores[i]) && !ehPositivo(valores[i]))
        {
            quantidadeImparesNegativos++;
        }
    }

    paresPositivos = (int *)malloc(sizeof(int) * quantidadeParesPositivos);
    imparesNegativos = (int *)malloc(sizeof(int) * quantidadeImparesNegativos);

    for (int i = 0; i < 10; i++)
    {
        if (ehPar(valores[i]) && ehPositivo(valores[i]))
        {
            paresPositivos[indiceParesPositivos] = valores[i];
            indiceParesPositivos++;
        }

        if (!ehPar(valores[i]) && !ehPositivo(valores[i]))
        {
            imparesNegativos[indiceImparesNegativos] = valores[i];
            indiceImparesNegativos++;
        }
    }

    ordemCrescente(paresPositivos, quantidadeParesPositivos);
    ordemCrescente(imparesNegativos, quantidadeImparesNegativos);

    printf("\nPares positivos:");
    for (int i = 0; i < quantidadeParesPositivos; i++)
    {
        printf("\n%d. %d", i + 1, paresPositivos[i]);
    }

    printf("\n\nÍmpares negativos:");
    for (int i = 0; i < quantidadeImparesNegativos; i++)
    {
        printf("\n%d. %d", i + 1, imparesNegativos[i]);
    }

    free(paresPositivos);
    free(imparesNegativos);
}