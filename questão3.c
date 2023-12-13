#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

struct ficha_produto
{
    char nome[200];
    float preco;
    int quantidade;
};

void limpatela()
{
    system("cls||clear");
    fflush(stdin);
    return;
}

float calcular_valorTotal(struct ficha_produto produto[], int tamanho)

{
    float valorTotal = 0;
    int i;

    for (i = 0; i < tamanho; i++)
    {
        valorTotal += produto[i].preco * produto[i].quantidade;
    }

    printf("valor total do estoque: %.2f\n\n", valorTotal);
    return valorTotal;
}

void comprar(struct ficha_produto produto[], int tamanho, char itemDesejado[])
{
    int encontrado = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (strcmp(itemDesejado, produto[i].nome) == 0 && produto[i].quantidade > 0)
        {
            produto[i].quantidade--;
            encontrado = 1;
            printf("Item vendido:\n");
            printf("Nome: %s\n", produto[i].nome);
            printf("Quantidade: 1\n");
            printf("Valor da compra: %.2f\n\n", produto[i].preco);
            break;
        }
    }

    if (!encontrado)
    {
        printf("Item não encontrado ou sem estoque\n");
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct ficha_produto produto[999];
    int menu;
    int menu2;
    int i = 0;
    int tamanho = 0;
    int j;
    float valorTotal;
    char itemDesejado[200];

    do
    {
        printf("digite '1' para adicionar ao estoque\n");
        printf("digite '2' para ir para pagina de usuario: ");
        scanf("%d", &menu);
        limpatela();

        switch (menu)
        {
        case 1:
            printf("acesso restrito 'estoque'\n");
            printf("adicione os produtos ao estoque: \n");
            printf("%d° produto\n", i + 1);
            printf("nome: ");
            scanf("%199s", &produto[tamanho].nome);
            limpatela();

            printf("preço: ");
            scanf("%f", &produto[tamanho].preco);
            limpatela();

            printf("quantidade: ");
            scanf("%d", &produto[tamanho].quantidade);
            limpatela();

            i++;
            tamanho++;

            break;

        default:
            break;
        }

    } while (menu != 2);

    do
    {
        printf("digite '1' para comprar\n");
        printf("digite '2' para ver o estoque\n");
        printf("digite 3 para sair: ");
        scanf("%d", &menu2);
        limpatela();

        switch (menu2)
        {
        case 1:
            printf("qual item deseja comprar: ");
            scanf("%199s", &itemDesejado);
            limpatela();
            comprar(produto, tamanho, itemDesejado);
            break;

        case 2:
            for (j = 0; j < tamanho; j++)
            {
                i = 0;
                printf("%d° produto\n", j + 1);
                printf("nome: %s\n", produto[j].nome);
                printf("preço: %.2f\n", produto[j].preco);
                printf("quantidade: %d\n\n", produto[j].quantidade);
            }

            calcular_valorTotal(produto, tamanho);
            break;

        default:
            break;
        }
    } while (menu2 != 3);

    return 0;
}
