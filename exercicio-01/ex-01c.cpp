#include <stdio.h>

// 3 - Uma loja quer saber a nota média do atendimento dos clientes. Um sistema deve ler a nota de atendimento (de 0 a 10) de 10 clientes e calcular a média geral. Se a média for menor que 7, deve exibir uma mensagem de alerta.

int main() {
    int contagem = 1;
    int quantidadeClientes = 10;
    int nota;
    int somaNotas = 0;
    float mediaNotas;

    while (contagem <= quantidadeClientes) {
        printf("Nota do cliente %d:\n", contagem);
        scanf("%d", &nota);

        if (nota >= 0 && nota <= 10) {
            somaNotas += nota;
            contagem++;
        } else {
            printf("A nota deve ser entre 0 e 10.\n");
        }
    }

    mediaNotas = (float) somaNotas / quantidadeClientes;

    printf("Nota de atendimento média: %.2f.\n", mediaNotas);

    if (mediaNotas < 7) {
        printf("Alerta: Atendimento abaixo da média esperada.");
    }
}