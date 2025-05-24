#include <stdio.h>

// Coordenas do Tabuleiro: Colunas (a, b, c, d, e, f, g, h). Linhas (1, 2, 3, 4, 5, 6, 7, 8).
// Código anterior movido para xadrez.c

// Torre: move-se cinco casas para a direita
void torre(int casas, char coluna, int linha) {
    if (casas > 0) {
        coluna++; // Move a peça uma coluna à direita
        printf("Direita -> %c%d\n", coluna, linha);
        torre(casas - 1, coluna, linha);
    }
}

void bispo(int casas, char coluna, int linha, int passo) {
    // Loop aninhado para controle horizontal
    for (int h = 1; h <= casas; h++) {
        // Condição para movimento diagonal (h == passo)
        if (h == passo) {
            char nova_coluna = coluna + h;
            int nova_linha = linha + passo;
            printf("Cima, Direita -> %c%d\n", nova_coluna, nova_linha);
        }
    }

    // Parte recursiva (controle vertical)
    if (passo < casas) {
        bispo(casas, coluna, linha, passo + 1);
    }
}

// Obs. Se mover a rainha 8 casas como solicitado, vai ultrapassar os limites do tabuleiro
void rainha(int casas, char coluna, int linha) { // 7 casas para a esquerda
    if (casas > 0) {
        coluna--; // Move a peça uma coluna à esquerda
        printf("Esquerda -> %c%d\n", coluna, linha);
        rainha(casas -1, coluna, linha);
    }

}

// Cavalo: move-se 2 casas para cima e 1 casa à direita (coluna aumenta).
void cavalo(int casas, char coluna, int linha) {
    if (casas > 0) {

        for (int i = 1; i <= 2; i++) { // for para loop externo - while para loop interno
            linha++; // move para cima
            printf("Cima -> %c%d\n", coluna, linha);

            int j = 1;
            while (j <= 1) {
                if (i != 2) {  // Só move na segunda iteração vertical
                    j++;
                    continue;  // Pula para próxima iteração
                }
                
                coluna++; // Move para direita
                printf("Direita -> %c%d\n", coluna, linha);
                break; // Força a saída após mover
            }
        }
    }   
}    

int main() {
    printf("Torre: Posição inicial (a1)\n"); // Posição inicial da peça
    torre(5, 'a', 1); // Quantidade de casas a mover, e coordenadas da posição inicial da peça

    printf("\n"); // Pula uma linha antes do início do movimento da peça
    printf("Bispo: Posição inicial (c1)\n");
    bispo(5, 'c', 1, 1);

    printf("\n");
    printf("Rainha: Posição inicial (h3)\n");
    rainha(7, 'h', 3);

    printf("\n");
    printf("Cavalo: Posição inicial (f8)\n");
    cavalo(2, 'f', 8);
    printf("\n");

    return 0;
}