#include <stdio.h>

#define TAMANHO_TABULEIRO 8 // Tabuleiro de xadrez 8x8

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Nível Novato: Movimentação do Bispo (diagonal)
void moverBispo(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    // Movimentos diagonais do Bispo: para cima e para a direita, para cima e para a esquerda, etc.
    for (int i = 1; i < TAMANHO_TABULEIRO; i++) {
        if (x + i < TAMANHO_TABULEIRO && y + i < TAMANHO_TABULEIRO) {
            tabuleiro[x + i][y + i] = 1; // Marca a posição como possível movimento
        }
        if (x - i >= 0 && y + i < TAMANHO_TABULEIRO) {
            tabuleiro[x - i][y + i] = 1;
        }
        if (x + i < TAMANHO_TABULEIRO && y - i >= 0) {
            tabuleiro[x + i][y - i] = 1;
        }
        if (x - i >= 0 && y - i >= 0) {
            tabuleiro[x - i][y - i] = 1;
        }
    }
}

// Nível Novato: Movimentação da Torre (horizontal e vertical)
void moverTorre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (i != x) tabuleiro[i][y] = 1; // Movimento vertical
        if (i != y) tabuleiro[x][i] = 1; // Movimento horizontal
    }
}

// Nível Novato: Movimentação da Rainha (horizontal, vertical e diagonal)
void moverRainha(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    moverTorre(tabuleiro, x, y);  // Movimentos da Torre
    moverBispo(tabuleiro, x, y);  // Movimentos do Bispo
}

// Nível Aventureiro: Movimentação do Cavalo (em L)
void moverCavalo(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    int movimentos[8][2] = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, 
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
    for (int i = 0; i < 8; i++) {
        int novoX = x + movimentos[i][0];
        int novoY = y + movimentos[i][1];
        if (novoX >= 0 && novoX < TAMANHO_TABULEIRO && novoY >= 0 && novoY < TAMANHO_TABULEIRO) {
            tabuleiro[novoX][novoY] = 1;  // Marca a posição do Cavalo
        }
    }
}

// Nível Mestre: Função Recursiva para movimentação do Bispo
void moverBispoRecursivo(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y, int i) {
    if (i >= TAMANHO_TABULEIRO) return; // Condição de parada
    if (x + i < TAMANHO_TABULEIRO && y + i < TAMANHO_TABULEIRO) tabuleiro[x + i][y + i] = 1;
    if (x - i >= 0 && y + i < TAMANHO_TABULEIRO) tabuleiro[x - i][y + i] = 1;
    if (x + i < TAMANHO_TABULEIRO && y - i >= 0) tabuleiro[x + i][y - i] = 1;
    if (x - i >= 0 && y - i >= 0) tabuleiro[x - i][y - i] = 1;

    moverBispoRecursivo(tabuleiro, x, y, i + 1); // Chamada recursiva
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0}; // Inicializa o tabuleiro com 0 (vazio)
    
    // Testando movimentação das peças (Nível Novato a Aventureiro)

    // Movimentação do Bispo na posição (4, 4)
    moverBispo(tabuleiro, 4, 4);
    printf("Tabuleiro após movimentação do Bispo:\n");
    exibirTabuleiro(tabuleiro);

    // Movimentação da Torre na posição (4, 4)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // Limpa o tabuleiro
        }
    }
    moverTorre(tabuleiro, 4, 4);
    printf("\nTabuleiro após movimentação da Torre:\n");
    exibirTabuleiro(tabuleiro);

    // Movimentação da Rainha na posição (4, 4)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // Limpa o tabuleiro
        }
    }
    moverRainha(tabuleiro, 4, 4);
    printf("\nTabuleiro após movimentação da Rainha:\n");
    exibirTabuleiro(tabuleiro);

    // Movimentação do Cavalo na posição (4, 4)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // Limpa o tabuleiro
        }
    }
    moverCavalo(tabuleiro, 4, 4);
    printf("\nTabuleiro após movimentação do Cavalo:\n");
    exibirTabuleiro(tabuleiro);

    // Testando Bispo recursivo
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // Limpa o tabuleiro
        }
    }
    moverBispoRecursivo(tabuleiro, 4, 4, 1);
    printf("\nTabuleiro após movimentação recursiva do Bispo:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
