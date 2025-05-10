#include <stdio.h>

// Coordenas do Tabuleiro: Colunas (a, b, c, d, e, f, g, h). Linhas (1, 2, 3, 4, 5, 6, 7, 8).

int main() { 
    int i;
    char coluna = 'a';
    int linha = 1;

    // Torre: Move-se 5 casas à direita (coluna aumenta).
    i = 1;
    coluna = 'a';
    printf("Torre: Posição inicial (a1)\n");
    while (i <= 5) {
        coluna++; // Move a colua de 'a' para 'b', 'c', ...
        printf("Direita -> %c%d\n", coluna, linha);
        i++;
    }

    printf("\n");

    // Bispo: Move-se 5 casas na diagonal (coluna e linha aumentam).
    i = 1;
    coluna = 'c';
    linha = 1;
    printf("Bispo: Posição inicial (c1)\n");
    do {
        coluna++; // Move a colua de 'c' para 'd', 'e', ...
        linha++; // Move a linha de 1 para 2, 3, ...
        printf("Cima, Direita -> %c%d\n", coluna, linha);
        i++;
    } while (i <= 5);

    printf("\n");

    // Rainha: Move-se 7 casas à esquerda (coluna diminui).
    coluna = 'h';
    linha = 3;
    printf("Rainha: Posição inicial (h3)\n");
    for (i = 1; i <= 7; i++) {
        coluna--; // Move a colua de 'h' para 'g', 'f', ...
        printf("Esquerda -> %c%d\n", coluna, linha);
    }

    printf("\n");

    return 0;
}