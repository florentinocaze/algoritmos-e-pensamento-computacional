#include <stdio.h>

// 4 - Um aplicativo quer acompanhar a meta diária de passos de um usuário. Faça um programa que leia a quantidade de passos dados por um usuário a cada hora. O programa deve parar quando o total atingir ou ultrapassar 10.000 passos e então informar quantas horas foram necessárias.

int main() {
    int passosPorHora;
    int somaPassos = 0;
    int limitePassos = 10000;
    int horas = 0;

    while (somaPassos <= limitePassos) {
        printf("Insira a quantidade de passos na última hora:\n");
        scanf("%d", &passosPorHora);

        somaPassos += passosPorHora;
        horas++;
    }

    printf("Limite de passos atingido.\n");
    printf("Passos totais: %d.\n", somaPassos);
    printf("Tempo necessário: %d horas.\n", horas);
}