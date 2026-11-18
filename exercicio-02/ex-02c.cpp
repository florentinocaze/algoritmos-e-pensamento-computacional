#include <stdio.h>
#include <stdlib.h>

/*
Desenvolva um algoritmo em linguagem C que leia 15 números inteiros e armazene-os em um vetor.
    a) Em seguida, o programa deverá identificar quais números aparecem mais de uma vez e contar a quantidade de ocorrências de cada um.
    b) Para os números que forem primos e apresentarem quantidade ímpar de ocorrências, o programa deverá calcular a soma de todas as ocorrências daquele número e solicitar ao usuário o cadastro de nomes de animais correspondentes a essa soma.
    c) Já para os números que apresentarem quantidade par de ocorrências, o programa deverá utilizar a posição que ocupam no vetor para estabelecer uma correspondência com os nomes dos animais previamente cadastrados pelo usuário.
    d) Ao final, o programa deverá apresentar os nomes dos animais correspondentes às regras identificadas durante o processamento.
*/

int ehPrimo(int valor)
{
    if (valor <= 1)
    {
        return 0;
    }

    for (int i = 2; i <= valor / i; i++)
    {
        if (valor % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int ehPar(int valor)
{
    return valor % 2 == 0;
}

int main()
{
    int valores[15];

    int *valoresDistintos;
    int *posicoesOcorrenciasPares;

    char **nomesAnimais;

    int quantidadeValoresDistintos = 0;
    int quantidadeAnimais = 0;
    int quantidadeOcorrenciasPares = 0;

    int indiceValoresDistintos = 0;
    int indicePosicoesOcorrenciasPares = 0;

    // Leitura dos números
    for (int i = 0; i < 15; i++)
    {
        printf("Insira o valor %d: ", i + 1);
        scanf("%d", &valores[i]);
    }

    // Contagem dos números distintos
    for (int i = 0; i < 15; i++)
    {
        int repetido = 0;

        for (int j = 0; j < i; j++)
        {
            if (valores[j] == valores[i])
            {
                repetido = 1;
                break;
            }
        }

        if (!repetido)
        {
            quantidadeValoresDistintos++;
        }
    }

    // Alocação do vetor de números distintos
    valoresDistintos = (int *)malloc(sizeof(int) * quantidadeValoresDistintos);

    // Armazenamento dos números distintos
    for (int i = 0; i < 15; i++)
    {
        int repetido = 0;

        for (int j = 0; j < indiceValoresDistintos; j++)
        {
            if (valoresDistintos[j] == valores[i])
            {
                repetido = 1;
                break;
            }
        }

        if (!repetido)
        {
            valoresDistintos[indiceValoresDistintos] = valores[i];
            indiceValoresDistintos++;
        }
    }

    // Identificação e classificação dos números
    for (int i = 0; i < indiceValoresDistintos; i++)
    {
        int ocorrencias = 0;

        for (int j = 0; j < 15; j++)
        {
            if (valores[j] == valoresDistintos[i])
            {
                ocorrencias++;
            }
        }

        // Ignora números que aparecem somente uma vez
        if (ocorrencias <= 1)
        {
            continue;
        }

        // Primos com quantidade ímpar de ocorrências
        if (ehPrimo(valoresDistintos[i]) && !ehPar(ocorrencias))
        {
            quantidadeAnimais += valoresDistintos[i] * ocorrencias;
        }

        // Números com quantidade par de ocorrências
        if (ehPar(ocorrencias))
        {
            quantidadeOcorrenciasPares += ocorrencias;
        }
    }

    // Alocação dos vetores auxiliares
    posicoesOcorrenciasPares = (int *)malloc(sizeof(int) * quantidadeOcorrenciasPares);
    nomesAnimais = (char **)malloc(sizeof(char *) * quantidadeAnimais);

    // Armazenamento das posições originais dos números pares
    for (int i = 0; i < indiceValoresDistintos; i++)
    {
        int ocorrencias = 0;

        for (int j = 0; j < 15; j++)
        {
            if (valores[j] == valoresDistintos[i])
            {
                ocorrencias++;
            }
        }

        if (ocorrencias > 1 && ehPar(ocorrencias))
        {
            for (int j = 0; j < 15; j++)
            {
                if (valores[j] == valoresDistintos[i])
                {
                    posicoesOcorrenciasPares[indicePosicoesOcorrenciasPares] = j;
                    indicePosicoesOcorrenciasPares++;
                }
            }
        }
    }

    // Alocação individual dos nomes dos animais
    for (int i = 0; i < quantidadeAnimais; i++)
    {
        nomesAnimais[i] = (char *)malloc(sizeof(char) * 50);
    }

    // Cadastro dos animais
    printf("\n=== CADASTRO DE ANIMAIS ===\n");

    for (int i = 0; i < quantidadeAnimais; i++)
    {
        printf("Insira o nome do animal %d: ", i + 1);
        scanf("%49s", nomesAnimais[i]);
    }

    // Apresentação dos resultados
    printf("\n=== RESULTADOS ===\n");

    for (int i = 0; i < quantidadeAnimais; i++)
    {
        printf("Animal %d: %s", i + 1, nomesAnimais[i]);

        for (int j = 0; j < indicePosicoesOcorrenciasPares; j++)
        {
            if (i == posicoesOcorrenciasPares[j])
            {
                printf(" - CORRESPONDÊNCIA");
                break;
            }
        }

        printf("\n");
    }

    // Liberação da memória
    free(valoresDistintos);
    free(posicoesOcorrenciasPares);

    for (int i = 0; i < quantidadeAnimais; i++)
    {
        free(nomesAnimais[i]);
    }

    free(nomesAnimais);
}