#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

void limpatela()
{
    system("cls||clear");
    fflush(stdin);
    return;
}

struct ficha_contato
{
    char nome[200];
    char numero[200];
    char email[200];
};

char aparecer_numero(struct ficha_contato contato[])
{
    int i;
    char nome2[200];
    
    printf("digite o nome da pessoa que deseja ver as informa��es de contato: ");
    scanf("%s", &nome2);
    limpatela();

    for (i = 0; i < 3; i++)
    {
        if (strcmp(contato[i].nome, nome2) == 0)
        {
            printf("n�mero: %s\n", contato[i].numero);
            break;
        }

        printf("contato n�o encontrado");
    }
    return;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct ficha_contato contato[3];
    int i;
    char nome2[200];

    for (i = 0; i < 3; i++)
    {
        printf("digite as informa��es do %d� contato\n", i + 1);
        printf("nome: ");
        scanf("%s", &contato[i].nome);
        system("cls||clear");

        printf("n�mero: ");
        scanf("%s", &contato[i].numero);
        system("cls||clear");

        printf("email: ");
        scanf("%s", &contato[i].email);
        system("cls||clear");
    }

    aparecer_numero(contato);
    return 0;
}
