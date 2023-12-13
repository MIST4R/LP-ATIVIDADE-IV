#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct ficha_aluno
{
    char nome[200];
    char nascimento[8];
    float nota[2];
    float media;
};

void limpatela()
{
    system("cls||clear");
    fflush(stdin);
    return;
}

void situacao(struct ficha_aluno aluno[])
{
    int j;

    if (aluno[j].media > 7)
    {
        printf("aprovado");
    }
    else if (aluno[j].media >= 5 && aluno[j].media < 7)
    {
        printf("recuperação");
    }
    else
    {
        printf("reprovado");
    }
    return;
}

float calcular_media(struct ficha_aluno aluno[])
{
    float soma = 0;
    int i;
    int j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            soma = aluno[j].nota[i];
            aluno[j].media = soma / i;
        }
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct ficha_aluno aluno[5];
    int j;
    int i;

    for (j = 0; j < 5; j++)
    {
        printf("dados do %d° aluno\n", j + 1);
        printf("nome: ");
        scanf("%s", &aluno[j].nome);
        limpatela();

        printf("data de nascimento: ");
        scanf("%s", &aluno[j].nascimento);
        limpatela();

        for (i = 0; i < 2; i++)
        {
            printf("%d° nota: ", i + 1);
            scanf("%f", &aluno[j].nota[i]);
            limpatela();
        }
    }

    calcular_media(aluno);

    for (j = 0; j < 5; j++)
    {
        printf("dados do %d° aluno\n", j + 1);
        printf("nome: %s\n", aluno[j].nome);
        printf("data de nascimento: %s\n", aluno[j].nascimento);

        for (i = 0; i < 2; i++)
        {
            printf("%d° nota: %.1f\n", i + 1, aluno[j].nota[i]);
        }
        printf("media: %.1f\n\n", aluno[j].media);
    }
    return 0;
}
