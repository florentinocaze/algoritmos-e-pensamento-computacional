#include <stdio.h>

// Um condomínio quer monitorar o consumo de água de cada morador. Escreva um programa que leia o consumo mensal de água (em m³) de 5 moradores. Para cada morador, informe se o consumo está dentro da média (até 20 m³) ou acima. Ao final, mostre o consumo médio geral.

int main() {
    int quantidadeMoradores = 5;
    int consumoMensal;
    int somaConsumoMensal = 0;
    float consumoMensalMedio;

    for (int i = 0; i < quantidadeMoradores; i++) {
        printf("Insira o consumo mensal do morador %d:\n", i + 1);
        scanf("%d", &consumoMensal);

        somaConsumoMensal += consumoMensal;

        if (consumoMensal <= 20) {
            printf("Classificação: dentro da média.\n");
        } else if (consumoMensal > 20) {
            printf("Classificação: acima da média.\n");
        } else {
            printf("Valor de consumo mensal inválido.\n");
        }
    }

    consumoMensalMedio = (float) somaConsumoMensal / quantidadeMoradores;

    printf("Consumo mensal médio dos moradores: %.2f m³.", consumoMensalMedio);
}