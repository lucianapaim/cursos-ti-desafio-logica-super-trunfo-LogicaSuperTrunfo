#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
typedef struct {
    char estado[3];               // Ex: "SP"
    char codigo[10];             // Código da carta
    char nomeCidade[50];         // Nome da cidade
    int populacao;               // População total
    float area;                  // Área em km²
    float pib;                   // Produto Interno Bruto
    int pontosTuristicos;        // Número de pontos turísticos
    float densidadePopulacional; // População / Área
    float pibPerCapita;          // PIB / População
} Carta;

// Função para calcular os valores derivados: densidade e PIB per capita
void calcularIndicadores(Carta *carta) {
    if (carta->area > 0) {
        carta->densidadePopulacional = carta->populacao / carta->area;
    } else {
        carta->densidadePopulacional = 0;
    }

    if (carta->populacao > 0) {
        carta->pibPerCapita = carta->pib / carta->populacao;
    } else {
        carta->pibPerCapita = 0;
    }
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta) {
    printf("Cidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: R$ %.2f\n", carta.pibPerCapita);
    printf("---------------------------------\n");
}

int main() {
    // Cadastro de duas cartas (valores fictícios)
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 750.50, 15};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6700000, 1182.30, 400.75, 10};

    // Cálculo de densidade e PIB per capita
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibição das cartas
    printf("=== Carta 1 ===\n");
    exibirCarta(carta1);

    printf("=== Carta 2 ===\n");
    exibirCarta(carta2);

    // Comparação com base em um único atributo: POPULAÇÃO
    printf(">>> Comparação de cartas (Atributo: População)\n");
    printf("Carta 1 - %s: %d habitantes\n", carta1.nomeCidade, carta1.populacao);
    printf("Carta 2 - %s: %d habitantes\n", carta2.nomeCidade, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta1.populacao < carta2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}

//teste

