#include <stdio.h>

#define TAB_NOVATO 5
#define TAB_AVENTUREIRO 10
#define TAB_MESTRE 5

// Função para imprimir matriz
void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// ==================== Nível Novato ====================
void nivelNovato() {
    int tabuleiro[TAB_NOVATO][TAB_NOVATO] = {0};

    // Posicionar navio vertical (3 posições)
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][1] = 1; // 1 indica navio
    }

    // Posicionar navio horizontal (2 posições)
    for (int j = 2; j < 4; j++) {
        tabuleiro[3][j] = 1;
    }

    printf("=== Nível Novato ===\n");
    imprimirMatriz(TAB_NOVATO, TAB_NOVATO, tabuleiro);
}

// ==================== Nível Aventureiro ====================
void nivelAventureiro() {
    int tabuleiro[TAB_AVENTUREIRO][TAB_AVENTUREIRO] = {0};

    // Navio horizontal
    for (int j = 0; j < 4; j++) tabuleiro[0][j] = 3;
    // Navio vertical
    for (int i = 1; i <= 4; i++) tabuleiro[i][5] = 3;
    // Navio diagonal descendente
    for (int i = 0; i < 4; i++) tabuleiro[i][i+6] = 3;
    // Navio diagonal ascendente
    for (int i = 0; i < 4; i++) tabuleiro[9-i][i] = 3;

    printf("=== Nível Aventureiro ===\n");
    imprimirMatriz(TAB_AVENTUREIRO, TAB_AVENTUREIRO, tabuleiro);
}

// ==================== Nível Mestre ====================
void nivelMestre() {
    int cone[TAB_MESTRE][TAB_MESTRE] = {0};
    int cruz[TAB_MESTRE][TAB_MESTRE] = {0};
    int octaedro[TAB_MESTRE][TAB_MESTRE] = {0};

    // Habilidade Cone (padrão triangular)
    cone[0][2] = 1;
    cone[1][1] = cone[1][2] = cone[1][3] = 1;
    for (int j = 0; j < 5; j++) cone[2][j] = 1;

    // Habilidade Cruz
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1; // linha central
        cruz[i][2] = 1; // coluna central
    }

    // Habilidade Octaedro
    octaedro[0][2] = 1;
    octaedro[1][1] = octaedro[1][2] = octaedro[1][3] = 1;
    octaedro[2][2] = 1;

    printf("=== Nível Mestre: Cone ===\n");
    imprimirMatriz(TAB_MESTRE, TAB_MESTRE, cone);

    printf("=== Nível Mestre: Cruz ===\n");
    imprimirMatriz(TAB_MESTRE, TAB_MESTRE, cruz);

    printf("=== Nível Mestre: Octaedro ===\n");
    imprimirMatriz(TAB_MESTRE, TAB_MESTRE, octaedro);
}

int main() {
    nivelNovato();
    nivelAventureiro();
    nivelMestre();

    return 0;
}
