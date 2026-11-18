#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Uma organização está desenvolvendo um sistema para cadastrar quatro participantes de uma competição. Cada participante deverá possuir um identificador (ID) calculado a partir de sua idade. O sistema também deverá registrar valores numéricos, calcular médias ponderadas e classificar os participantes de acordo com uma comparação geométrica. Desenvolva um algoritmo em linguagem C que execute as seguintes operações:
    a) Cadastro dos participantes:
        i) Solicite o nome e a idade de quatro participantes.
        ii) Calcule o ID de cada participante utilizando o fatorial da idade dividido por 2.
        iii) Os IDs deverão ser únicos.
        iv) Caso dois ou mais participantes obtenham o mesmo ID, o cálculo deverá ser refeito utilizando o fatorial da metade da idade do participante, elevado à quantidade de valores capturados.
        v) Caso ainda exista duplicidade, repita o procedimento até obter um ID exclusivo.
    b) Captura dos valores:
        i) Solicite ao usuário a quantidade de valores que serão registrados para cada participante.
        ii) Armazene os valores em uma matriz, na qual cada linha representa um participante e cada coluna representa um valor informado.
        iii) Os valores poderão ser positivos, negativos ou iguais a zero.
    c) Organização dos participantes:
        i) Após realizar os cadastros, organize os quatro participantes em ordem alfabética pelo nome, mantendo corretamente associados seus IDs e respectivos valores armazenados na matriz.
    d) Cálculo da média ponderada:
        i) Desenvolva uma função para calcular a média ponderada dos valores capturados para cada participante. Considere como pesos a sequência crescente de números naturais, começando em 1. Assim, o primeiro valor terá peso 1, o segundo peso 2, o terceiro peso 3 e assim sucessivamente.
    e) Cálculo da diagonal do retângulo:
        i) O programa deverá identificar os dois primeiros valores não negativos informados pelo usuário durante a entrada dos dados. Esses valores representarão os lados de um retângulo.
        ii) Calcule o comprimento da diagonal desse retângulo utilizando o Teorema de Pitágoras.
        iii) Caso não sejam encontrados dois valores não negativos, o programa deverá informar que não foi possível calcular a diagonal.
    f) Classificação dos participantes:
        i) Compare a média ponderada de cada participante com o comprimento da diagonal calculada.
        ii) Classifique os participantes em três categorias:
            1) Acima da diagonal: média ponderada maior que o comprimento da diagonal.
            2) Abaixo da diagonal: média ponderada menor que o comprimento da diagonal.
            3) Sobre a diagonal: média ponderada igual ao comprimento da diagonal.
    g) Saída do programa:
        i) Ao final, apresente os nomes dos quatro participantes em ordem alfabética, acompanhados de sua classificação em relação à diagonal do retângulo.
*/

// Calcula o fatorial de um número.
float fatorial(int valor)
{
    float resultado = 1;

    for (int i = 1; i <= valor; i++)
    {
        resultado *= i;
    }

    return resultado;
}

// Verifica se um ID já foi utilizado.
int idExiste(float ids[], int quantidade, float id)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (ids[i] == id)
        {
            return 1;
        }
    }

    return 0;
}

// Calcula um ID exclusivo para o participante.
float calcularID(int idade, int quantidadeValores, float ids[], int quantidadeIDs)
{
    float id = fatorial(idade) / 2.0;

    int metadeIdade = idade / 2;

    while (idExiste(ids, quantidadeIDs, id))
    {
        id = pow(fatorial(metadeIdade), quantidadeValores);

        metadeIdade /= 2;
    }

    return id;
}

// Calcula a média ponderada dos valores.
float calcularMediaPonderada(float valores[], int quantidade)
{
    float somaPonderada = 0;
    int somaPesos = 0;

    for (int i = 0; i < quantidade; i++)
    {
        int peso = i + 1;

        somaPonderada += valores[i] * peso;
        somaPesos += peso;
    }

    return somaPonderada / somaPesos;
}

// Organiza os participantes em ordem alfabetica.
void ordenarParticipantes(char nomes[][100], float ids[], float valores[][100], int quantidadeValores)
{
    char nomeAuxiliar[100];
    float idAuxiliar;
    float valoresAuxiliares[100];

    for (int i = 0; i < 4 - 1; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {

            if (strcmp(nomes[i], nomes[j]) > 0)
            {
                // Troca os nomes.
                strcpy(nomeAuxiliar, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], nomeAuxiliar);

                // Troca os IDs.
                idAuxiliar = ids[i];
                ids[i] = ids[j];
                ids[j] = idAuxiliar;

                // Troca os valores correspondentes.
                for (int k = 0; k < quantidadeValores; k++)
                {
                    valoresAuxiliares[k] = valores[i][k];
                    valores[i][k] = valores[j][k];
                    valores[j][k] = valoresAuxiliares[k];
                }
            }
        }
    }
}

// Calcula a diagonal de um retangulo.
float calcularDiagonal(float lado1, float lado2)
{
    return sqrt(pow(lado1, 2) + pow(lado2, 2));
}

// Classifica o participante em relação à diagonal.
const char *classificarParticipante(float media, float diagonal)
{
    if (media > diagonal)
    {
        return "Acima da diagonal";
    }
    else if (media < diagonal)
    {
        return "Abaixo da diagonal";
    }
    else
    {
        return "Sobre a diagonal";
    }
}

int main()
{
    char nomes[4][100];
    int idades[4];
    float ids[4];
    float valores[4][100];
    float medias[4];

    float lado1, lado2;
    float diagonal = 0;
    int quantidadeValores;
    int quantidadeLados = 0;

    printf("=== CADASTRO DOS PARTICIPANTES ===\n");

    printf("Quantidade de valores por participante: ");
    scanf("%d", &quantidadeValores);

    while (quantidadeValores <= 0 || quantidadeValores > 100)
    {
        printf("Informe uma quantidade entre 1 e 100: ");
        scanf("%d", &quantidadeValores);
    }

    getchar();

    for (int i = 0; i < 4; i++)
    {

        printf("\n--- Participante %d ---\n", i + 1);

        printf("Nome: ");
        fgets(nomes[i], 100, stdin);

        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        printf("Idade: ");
        scanf("%d", &idades[i]);

        while (idades[i] < 0)
        {
            printf("Informe uma idade não negativa: ");
            scanf("%d", &idades[i]);
        }

        getchar();

        ids[i] = calcularID(idades[i], quantidadeValores, ids, i);

        printf("ID gerado: %.2f\n", ids[i]);
    }

    printf("\n=== CAPTURA DOS VALORES ===\n");

    for (int i = 0; i < 4; i++)
    {
        printf("\nValores de %s:\n", nomes[i]);

        for (int j = 0; j < quantidadeValores; j++)
        {

            printf("Valor %d: ", j + 1);
            scanf("%f", &valores[i][j]);

            // Identifica os dois primeiros valores não negativos.
            if (valores[i][j] >= 0 && quantidadeLados < 2)
            {

                if (quantidadeLados == 0)
                {
                    lado1 = valores[i][j];
                }
                else
                {
                    lado2 = valores[i][j];
                }

                quantidadeLados++;
            }
        }
    }

    printf("\n=== DIAGONAL DO RETÂNGULO ===\n");

    if (quantidadeLados == 2)
    {

        diagonal = calcularDiagonal(lado1, lado2);

        printf("Lado 1: %.2f\n", lado1);
        printf("Lado 2: %.2f\n", lado2);
        printf("Diagonal: %.2f\n", diagonal);
    }
    else
    {

        printf("Não foi possível calcular a diagonal.\n");
    }

    ordenarParticipantes(nomes, ids, valores, quantidadeValores);

    for (int i = 0; i < 4; i++)
    {
        medias[i] = calcularMediaPonderada(valores[i], quantidadeValores);
    }

    printf("\n=== CLASSIFICAÇÃO FINAL ===\n");

    for (int i = 0; i < 4; i++)
    {
        printf("\nParticipante: %s\n", nomes[i]);
        printf("ID: %.2f\n", ids[i]);
        printf("Média ponderada: %.2f\n", medias[i]);

        if (quantidadeLados == 2)
        {
            printf("Classificação: %s\n", classificarParticipante(medias[i], diagonal));
        }
        else
        {
            printf("Classificação: Indeterminada (sem diagonal)\n");
        }
    }
}