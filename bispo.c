#include <stdio.h>

void movimentoBispo(int casas, char coluna, int linha, int passo) {
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
        movimentoBispo(casas, coluna, linha, passo + 1);
    }
}

int main() {
    char coluna_inicial = 'c';
    int linha_inicial = 1;
    int total_movimentos = 5;
    
    printf("Bispo: Posição inicial (%c%d)\n", coluna_inicial, linha_inicial);
    movimentoBispo(total_movimentos, coluna_inicial, linha_inicial, 1);
    
    return 0;
}

/*
Tive que apelar para auxilio do DeepSeek para finalizar o movimento do Bispo, finalmente unindo
loop aninhado com recursividade, todos os testes anteriores entravam em loop infinito ou duplicava
a saída
*/