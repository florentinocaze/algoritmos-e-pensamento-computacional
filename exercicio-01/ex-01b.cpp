#include <stdio.h>

// 2 - Um jovem quer juntar dinheiro e acompanhar o saldo do seu cofrinho. Faça um programa que simule um cofrinho digital. O usuário pode adicionar moedas de R$0,50, R$1,00 ou R$2,00 quantas vezes quiser. Quando decidir parar, o programa deve mostrar o total acumulado.

int main() {
    float saldoCofrinho = 0;
    int quantidadeMoedas;
    int valorMoeda;
    int contagem = 1;

    printf("Quantas moedas você deseja adicionar?\n");
    scanf("%d", &quantidadeMoedas);

    while (contagem <= quantidadeMoedas) {
        printf("Qual o valor da moeda?\n");
        printf("1 - R$ 0,50\n");
        printf("2 - R$ 1,00\n");
        printf("3 - R$ 2,00\n");
        printf("Insira o valor:\n");
        scanf("%d", &valorMoeda);

        switch (valorMoeda) {
        case 1:
            saldoCofrinho += 0.5;
            contagem++;
            break;
        
        case 2:
            saldoCofrinho += 1;
            contagem++;
            break;

        case 3:
            saldoCofrinho += 2;
            contagem++;
            break;

        default:
            printf("Valor de moeda inválido.\n");
            break;
        }
    }

    printf("Saldo total do cofrinho: R$ %.2f.", saldoCofrinho);
}