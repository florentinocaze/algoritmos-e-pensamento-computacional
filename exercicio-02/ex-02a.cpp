#include <stdio.h>
#include <string.h>

/*
Uma equipe está organizando um sorteio beneficente e precisa analisar os números registrados durante o planejamento da compra dos produtos. Para isso, desenvolva um algoritmo em linguagem C que leia 12 números inteiros e armazene-os em um vetor. Em seguida, o programa deverá:
    a) Contar quantas vezes cada número aparece no vetor.
    b) Os números cuja quantidade de ocorrências for ímpar representarão as quantidades de produtos que deverão ser comprados para o sorteio beneficente.
    c) Os números cuja quantidade de ocorrências for par deverão ser armazenados em um segundo vetor, que deverá ser organizado em ordem decrescente.
    d) Para cada número cuja quantidade de ocorrências for ímpar, o programa deverá solicitar o cadastro dos produtos que serão comprados, informando o nome e o preço unitário de cada produto.
    e) Após o cadastro, os produtos deverão ser apresentados em ordem alfabética pelo nome.
Ao final, o programa deverá apresentar:
    a) Os 12 números informados pelo usuário.
    b) Cada número distinto e a quantidade de vezes que aparece no vetor.
    c) Os produtos cadastrados para compra, com seus respectivos nomes e preços, organizados em ordem alfabética.
    d) Os números cuja quantidade de ocorrências seja par, armazenados em um segundo vetor e apresentados em ordem decrescente.
*/

int ehPar(int valor)
{
    return !(valor % 2);
}

int main()
{
    int numerosRegistrados[12];
    int numerosSecundarios[12];
    int numerosDistintos[12];
    int vezesDistintos[12];
    char produtosRegistrados[12][20];
    float precoProdutos[12];

    int quantidadeProdutos = 0;
    int quantidadeSecundarios = 0;
    int quantidadeDistintos = 0;

    printf("=== SORTEIO BENEFICENTE ===");
    printf("\n\n");

    // Leitura dos 12 números
    for (int i = 0; i < 12; i++)
    {
        printf("Insira o valor %d: ", i + 1);
        scanf("%d", &numerosRegistrados[i]);
    }

    // Contagem das ocorrências
    for (int i = 0; i < 12; i++)
    {
        int quantidade = 1;
        int jaPercorrido = 0;

        // Verifica se o número é repetido
        for (int j = 0; j < i; j++)
        {
            if (numerosRegistrados[i] == numerosRegistrados[j])
            {
                jaPercorrido = 1;
                break;
            }
        }

        if (jaPercorrido)
        {
            continue;
        }

        // Armazena os números distintos e a quantidade deles
        numerosDistintos[quantidadeDistintos] = numerosRegistrados[i];
        quantidadeDistintos++;

        // Conta as ocorrências e verifica a paridade posteriormente
        for (int j = i + 1; j < 12; j++)
        {
            if (numerosRegistrados[j] == numerosRegistrados[i])
            {
                quantidade++;
            }
        }

        if (ehPar(quantidade))
        {
            numerosSecundarios[quantidadeSecundarios] = numerosRegistrados[i];
            quantidadeSecundarios++;
        }
        else
        {
            quantidadeProdutos += quantidade;
        }
    }

    // Organiza o vetor secundário em ordem decrescente

    for (int i = 0; i < quantidadeSecundarios - 1; i++)
    {
        for (int j = 0; j < quantidadeSecundarios - i - 1; j++)
        {
            if (numerosSecundarios[j] < numerosSecundarios[j + 1])
            {
                int auxiliar = numerosSecundarios[j];
                numerosSecundarios[j] = numerosSecundarios[j + 1];
                numerosSecundarios[j + 1] = auxiliar;
            }
        }
    }

    // Conta a quantas vezes que cada número distinto aparece
    for (int i = 0; i < quantidadeDistintos; i++)
    {
        int vezesPorDistinto = 0;
        for (int j = 0; j < 12; j++)
        {
            if (numerosDistintos[i] == numerosRegistrados[j])
            {
                vezesPorDistinto++;
            }
        }

        vezesDistintos[i] = vezesPorDistinto;
    }

    printf("\n");

    // Armazena o nome e o preço dos produtos
    for (int i = 0; i < quantidadeProdutos; i++)
    {
        printf("Insira o nome do produto %d: ", i + 1);
        scanf("%19s", &produtosRegistrados[i]);

        printf("Insira o preço do produto %d: ", i + 1);
        scanf("%f", &precoProdutos[i]);
    }

    // Ordenação alfabética dos nomes dos produtos
    for (int i = 0; i < quantidadeProdutos - 1; i++)
    {
        for (int j = 0; j < quantidadeProdutos - i - 1; j++)
        {
            if (strcmp(produtosRegistrados[j], produtosRegistrados[j + 1]) > 0)
            {
                char auxiliarNome[20];
                float auxiliarPreco;

                strcpy(auxiliarNome, produtosRegistrados[j]);
                strcpy(produtosRegistrados[j], produtosRegistrados[j + 1]);
                strcpy(produtosRegistrados[j + 1], auxiliarNome);

                auxiliarPreco = precoProdutos[j];
                precoProdutos[j] = precoProdutos[j + 1];
                precoProdutos[j + 1] = auxiliarPreco;
            }
        }
    }

    printf("\n== RESULTADO ==");

    printf("\n\nNúmeros registrados: [");
    for (int i = 0; i < 12; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }

        printf("%d", numerosRegistrados[i]);
    }
    printf("]");

    printf("\n\nNúmeros distintos:");
    for (int i = 0; i < quantidadeDistintos; i++)
    {
        printf("\n%d. Número %d: %d ocorrência(s)", i + 1, numerosDistintos[i], vezesDistintos[i]);
    }

    printf("\n\nProdutos cadastrados:");
    for (int i = 0; i < quantidadeProdutos; i++)
    {
        printf("\n%d. %s (R$ %.2f)", i + 1, produtosRegistrados[i], precoProdutos[i]);
    }

    printf("\n\nNúmeros secundários: [");
    for (int i = 0; i < quantidadeSecundarios; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }

        printf("%d", numerosSecundarios[i]);
    }

    printf("]");
}