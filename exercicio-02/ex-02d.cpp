#include <stdio.h>

/*
Cinco apostadores desejam tentar a sorte em uma competição que premiará os três melhores resultados. Para participar, cada apostador deverá informar seu nome e um valor inteiro positivo.
    a) Desenvolva um algoritmo em linguagem C que receba os dados dos cinco apostadores e calcule a soma da sequência de Fibonacci correspondente ao valor informado por cada participante.
    b) Após calcular os resultados, o programa deverá determinar os três vencedores, obedecendo aos seguintes critérios:
        i) 1º lugar – Maior número primo: será premiado o apostador que obtiver o maior resultado primo entre os cinco participantes.
        ii) 2º lugar – Maior número par: será premiado o apostador que obtiver o maior resultado par entre os participantes que ainda não receberam premiação.
        iii) 3º lugar – Maior resultado acima da média: será premiado o apostador que apresentar o maior resultado acima da média dos cinco participantes, desde que ainda não tenha recebido outra premiação.
    c) Requisitos do algoritmo:
        i) Cadastre o nome dos cinco apostadores e solicite um número inteiro positivo para cada um.
        ii) Desenvolva uma função para calcular a soma dos termos da sequência de Fibonacci até a quantidade de termos indicada pelo apostador.
        iii) Armazene os resultados calculados em um vetor.
        iv) Desenvolva uma função para verificar se determinado resultado é primo.
        v) Identifique o maior resultado primo e atribua o primeiro lugar.
        vi) Identifique o maior resultado par entre os apostadores que ainda não foram premiados e atribua o segundo lugar.
        vii) Calcule a média dos cinco resultados e identifique o maior resultado acima dela, considerando apenas os participantes ainda não premiados, para atribuir o terceiro lugar.
        viii) Garanta que nenhum apostador receba mais de uma premiação.
        ix) Caso não exista participante que atenda a algum critério, o respectivo prêmio deverá ficar sem vencedor.
        x) Ao final, apresente somente os nomes dos apostadores vencedores e suas respectivas colocações, em ordem decrescente de classificação.
*/

int ehPar(int valor)
{
    return valor % 2 == 0;
}

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

int fibonacci(int valor)
{
    if (valor == 0)
    {
        return 0;
    }

    if (valor == 1)
    {
        return 1;
    }

    return fibonacci(valor - 1) + fibonacci(valor - 2);
}

int somaFibonacci(int valor)
{
    int soma = 0;

    for (int i = 1; i <= valor; i++)
    {
        soma += fibonacci(i);
    }

    return soma;
}

int main()
{
    char apostador[5][50];
    int aposta[5];
    int somaFibonacciJogadores[5];

    int indicePrimeiroLugar = -1;
    int indiceSegundoLugar = -1;
    int indiceTerceiroLugar = -1;

    int maiorPrimo = 0;
    int maiorPar = 0;
    float mediaSomaFibonacciJogadores = 0;
    int maiorAcimaMedia = 0;

    printf("\n=== COMPETIÇÃO ===\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\n--- JOGADOR %d ---\n", i + 1);
        printf("Insira seu nome: ");
        scanf("%49s", apostador[i]);

        printf("Insira sua aposta: ", i + 1);
        do
        {
            scanf("%d", &aposta[i]);

            if (aposta[i] > 0)
            {
                break;
            }

            printf("Somente são aceitos valores inteiros positivos. Tente novamente: ");
        } while (1);

        somaFibonacciJogadores[i] = somaFibonacci(aposta[i]);
        mediaSomaFibonacciJogadores += somaFibonacciJogadores[i];
    }

    mediaSomaFibonacciJogadores /= 5;

    for (int i = 0; i < 5; i++)
    {
        if (ehPrimo(somaFibonacciJogadores[i]) && somaFibonacciJogadores[i] > maiorPrimo)
        {
            maiorPrimo = somaFibonacciJogadores[i];
            indicePrimeiroLugar = i;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (i != indicePrimeiroLugar && ehPar(somaFibonacciJogadores[i]) && somaFibonacciJogadores[i] > maiorPar)
        {
            maiorPar = somaFibonacciJogadores[i];
            indiceSegundoLugar = i;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (i != indicePrimeiroLugar && i != indiceSegundoLugar && somaFibonacciJogadores[i] > mediaSomaFibonacciJogadores && somaFibonacciJogadores[i] > maiorAcimaMedia)
        {
            maiorAcimaMedia = somaFibonacciJogadores[i];
            indiceTerceiroLugar = i;
        }
    }

    printf("\n=== RESULTADO ===\n");
    printf("3º lugar: %s\n", (maiorAcimaMedia != -1) ? apostador[indiceTerceiroLugar] : "Nenhum vencedor");
    printf("2º lugar: %s\n", (maiorPar != -1) ? apostador[indiceSegundoLugar] : "Nenhum vencedor");
    printf("1º lugar: %s\n", (maiorPrimo != -1) ? apostador[indicePrimeiroLugar] : "Nenhum vencedor");
}