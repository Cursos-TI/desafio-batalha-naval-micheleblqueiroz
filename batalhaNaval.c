#include <stdio.h>


void inicializarTabuleiro(int tabuleiro[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    
    int tabuleiro[5][5];
    inicializarTabuleiro(tabuleiro);
    
   
    for (int i = 1; i <= 3; i++) {
        tabuleiro[i][2] = 3;
        printf("Navio vertical em (%d, %d)\n", i, 2);
    }
    

    for (int j = 1; j <= 3; j++) {
        tabuleiro[3][j] = 3;
        printf("Navio horizontal em (%d, %d)\n", 3, j);
    }
    
    printf("\nTabuleiro Novato:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}