#include <stdio.h>
#include <time.h>
#include <windows.h>


float calculoFrete(int regiao, float peso) {

    float frete;

    if (regiao == 1) {
        frete = 30;

        if (peso > 2) {
            frete = 50;
        }

    } else if (regiao == 2) {
        frete = 25;

        if (peso > 2) {
            frete = 45;
        }

    } else if (regiao == 3) {
        frete = 35;

        if (peso > 2) {
            frete = 55;
        }

    } else {
        frete = 40;

        if (peso > 2) {
            frete = 60;
        }
    }

    return frete;
}


const char* mostrarRegiao(int regiao) {

    if (regiao == 1) {
        return "Sul";

    } else if (regiao == 2) {
        return "Sudeste";

    } else if (regiao == 3) {
        return "Norte";

    } else {
        return "Nordeste";
    }
}


void Resumo(
    int codigo,
    char nome[],
    float peso,
    float preco,
    float frete,
    float total,
    int regiao,
    struct tm dataCompra,
    struct tm dataEntrega) {

    printf("\n--- RESUMO DA COMPRA ---\n");

    printf("Codigo: %d\n", codigo);

    printf("Produto: %s\n", nome);

    printf("Peso: %.2f kg\n", peso);

    printf("Preco: R$ %.2f\n", preco);

    printf("Local de entrega: %s\n", mostrarRegiao(regiao));

    printf("Frete: R$ %.2f\n", frete);

    printf("Total da compra: R$ %.2f\n", total);

    printf("Data e hora da compra: %02d/%02d/%d %02d:%02d:%02d\n",
           dataCompra.tm_mday,
           dataCompra.tm_mon + 1,
           dataCompra.tm_year + 1900,
           dataCompra.tm_hour,
           dataCompra.tm_min,
           dataCompra.tm_sec);

    printf("Data prevista de entrega: %02d/%02d/%d\n",
           dataEntrega.tm_mday,
           dataEntrega.tm_mon + 1,
           dataEntrega.tm_year + 1900);
}


int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int codigo, regiao;
    char nome[50];
    float peso, frete, total, preco;

    printf("\n--- CALCULADORA ---\n");

    printf("Código do produto: ");
    scanf("%d", &codigo);

    printf("Nome do produto: ");
    scanf(" %[^\n]", nome);

    printf("Peso do produto (Kg): ");
    scanf("%f", &peso);

    printf("Preço do produto (R$): ");
    scanf("%f", &preco);

    printf("\nRegião de entrega:\n");

    printf("[1] Sul\n");
    printf("[2] Sudeste\n");
    printf("[3] Norte\n");
    printf("[4] Nordeste\n");

    printf("Opção: ");
    scanf("%d", &regiao);


    if (regiao < 1 || regiao > 4) {
        printf("\nOpção inválida. Digite um número entre 1 e 4!\n");

        return 0;
    }


    frete = calculoFrete(regiao, peso);

    total = preco + frete;


    time_t agora;
    time(&agora);

    struct tm dataCompra = *localtime(&agora);
    struct tm dataEntrega = dataCompra;

    dataEntrega.tm_mday += 3;

    mktime(&dataEntrega);


    Resumo(
        codigo,
        nome,
        peso,
        preco,
        frete,
        total,
        regiao,
        dataCompra,
        dataEntrega
    );

    return 0;
}
