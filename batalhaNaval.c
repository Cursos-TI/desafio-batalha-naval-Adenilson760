#include <stdio.h>

#define SIZE 10
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = 0; // Água
        }
    }
}

// Função para posicionar um navio horizontal
int posicionarNavioHorizontal(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
    if (coluna + 2 < SIZE) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // Verifica sobreposição
            tabuleiro[linha][coluna + i] = NAVIO;
        }
        return 1;
    }
    return 0;
}

// Função para posicionar um navio vertical
int posicionarNavioVertical(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
    if (linha + 2 < SIZE) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0; // Verifica sobreposição
            tabuleiro[linha + i][coluna] = NAVIO;
        }
        return 1;
    }
    return 0;
}

// Função para criar a área de habilidade em forma de cone
void aplicarHabilidadeCone(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1 && linha + i < SIZE && coluna + j < SIZE) {
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

// Função para criar a área de habilidade em forma de cruz
void aplicarHabilidadeCruz(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1 && linha + i < SIZE && coluna + j < SIZE) {
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

// Função para criar a área de habilidade em forma de octaedro
void aplicarHabilidadeOctaedro(int tabuleiro[SIZE][SIZE], int linha, int coluna) {
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1 && linha + i < SIZE && coluna + j < SIZE) {
                tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("0 "); // Água
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("3 "); // Navio
            } else if (tabuleiro[i][j] == HABILIDADE) {
                printf("5 "); // Habilidade
            }
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[SIZE][SIZE];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posiciona os navios
    if (!posicionarNavioHorizontal(tabuleiro, 2, 2)) {
        printf("Falha ao posicionar navio horizontal!\n");
    }
    if (!posicionarNavioVertical(tabuleiro, 5, 5)) {
        printf("Falha ao posicionar navio vertical!\n");
    }

    // Aplica habilidades
    aplicarHabilidadeCone(tabuleiro, 1, 1);
    aplicarHabilidadeCruz(tabuleiro, 4, 4);
    aplicarHabilidadeOctaedro(tabuleiro, 6, 6);

    // Exibe o tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}
