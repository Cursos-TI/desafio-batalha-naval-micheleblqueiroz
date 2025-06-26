#include <stdio.h>
#include <stdlib.h>

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int linhas, int colunas, int tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int linhas, int colunas, int tabuleiro[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para posicionar navios
void posicionarNavio(int tabuleiro[10][10], int linhaInicio, int colunaInicio, int tamanho, char orientacao) {
    if (orientacao == 'H') { // Horizontal
        for (int j = colunaInicio; j < colunaInicio + tamanho; j++) {
            tabuleiro[linhaInicio][j] = 3;
        }
    } else if (orientacao == 'V') { // Vertical
        for (int i = linhaInicio; i < linhaInicio + tamanho; i++) {
            tabuleiro[i][colunaInicio] = 3;
        }
    } else if (orientacao == 'D') { // Diagonal
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linhaInicio + i][colunaInicio + i] = 3;
        }
    }
}

// Função para habilidade especial: Cone
void aplicarCone(int tabuleiro[10][10], int linhaCentro, int colunaCentro) {
    if (linhaCentro - 2 >= 0 && colunaCentro - 2 >= 0 && colunaCentro + 2 < 10) {
        tabuleiro[linhaCentro][colunaCentro] = 1;
        tabuleiro[linhaCentro - 1][colunaCentro - 1] = 1;
        tabuleiro[linhaCentro - 1][colunaCentro] = 1;
        tabuleiro[linhaCentro - 1][colunaCentro + 1] = 1;
        for (int j = colunaCentro - 2; j <= colunaCentro + 2; j++) {
            tabuleiro[linhaCentro - 2][j] = 1;
        }
    }
}

// Função para habilidade especial: Cruz
void aplicarCruz(int tabuleiro[10][10], int linhaCentro, int colunaCentro) {
    for (int i = 0; i < 10; i++) {
        tabuleiro[i][colunaCentro] = 1;
    }
    for (int j = 0; j < 10; j++) {
        tabuleiro[linhaCentro][j] = 1;
    }
}

// Função para habilidade especial: Octaedro
void aplicarOctaedro(int tabuleiro[10][10], int linhaCentro, int colunaCentro) {
    tabuleiro[linhaCentro][colunaCentro] = 1;
    if (linhaCentro - 1 >= 0) tabuleiro[linhaCentro - 1][colunaCentro] = 1;
    if (linhaCentro + 1 < 10) tabuleiro[linhaCentro + 1][colunaCentro] = 1;
    if (colunaCentro - 1 >= 0) tabuleiro[linhaCentro][colunaCentro - 1] = 1;
    if (colunaCentro + 1 < 10) tabuleiro[linhaCentro][colunaCentro + 1] = 1;
}

int main() {
    // Nível Novato: Tabuleiro 5x5 com dois navios
    printf("=== Nivel Novato ===\n");
    int tabuleiro5x5[5][5];
    inicializarTabuleiro(5, 5, tabuleiro5x5);
    
    // Posicionar navio vertical (tamanho 3) em (1,2)
    for (int i = 1; i <= 3; i++) {
        tabuleiro5x5[i][2] = 3;
        printf("Navio vertical em (%d, %d)\n", i, 2);
    }
    
    // Posicionar navio horizontal (tamanho 3) em (3,1)
    for (int j = 1; j <= 3; j++) {
        tabuleiro5x5[3][j] = 3;
        printf("Navio horizontal em (%d, %d)\n", 3, j);
    }
    
    printf("\nTabuleiro Novato:\n");
    exibirTabuleiro(5, 5, tabuleiro5x5);
    
    // Nível Aventureiro: Tabuleiro 10x10 com quatro navios
    printf("=== Nivel Aventureiro ===\n");
    int tabuleiro10x10[10][10];
    inicializarTabuleiro(10, 10, tabuleiro10x10);
    
    // Posicionar quatro navios
    posicionarNavio(tabuleiro10x10, 2, 2, 3, 'D'); // Diagonal
    posicionarNavio(tabuleiro10x10, 5, 5, 3, 'D'); // Diagonal
    posicionarNavio(tabuleiro10x10, 1, 7, 4, 'V'); // Vertical
    posicionarNavio(tabuleiro10x10, 8, 1, 4, 'H'); // Horizontal
    
    printf("Tabuleiro Aventureiro:\n");
    exibirTabuleiro(10, 10, tabuleiro10x10);
    
    // Nível Mestre: Habilidades especiais
    printf("=== Nivel Mestre ===\n");
    
    // Habilidade Cone
    inicializarTabuleiro(10, 10, tabuleiro10x10);
    aplicarCone(tabuleiro10x10, 2, 2);
    printf("Tabuleiro com Habilidade Cone:\n");
    exibirTabuleiro(10, 10, tabuleiro10x10);
    
    // Habilidade Cruz
    inicializarTabuleiro(10, 10, tabuleiro10x10);
    aplicarCruz(tabuleiro10x10, 2, 2);
    printf("Tabuleiro com Habilidade Cruz:\n");
    exibirTabuleiro(10, 10, tabuleiro10x10);
    
    // Habilidade Octaedro
    inicializarTabuleiro(10, 10, tabuleiro10x10);
    aplicarOctaedro(tabuleiro10x10, 2, 2);
    printf("Tabuleiro com Habilidade Octaedro:\n");
    exibirTabuleiro(10, 10, tabuleiro10x10);
    
    return 0;
}