#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    int navioH[3] = {3, 3, 3};
    int navioV[3] = {3, 3, 3};
    int navioD1[3] = {3, 3, 3};
    int navioD2[3] = {3, 3, 3};

    int linhaH = 2, colunaH = 1;
    int linhaV = 5, colunaV = 7;

    int linhaD1 = 0, colunaD1 = 4;  // corrigido (nao sobrepoe)
    int linhaD2 = 0, colunaD2 = 9;

    int i, l, c;
    int erro = 0;

    for (l = 0; l < 10; l++) {
        for (c = 0; c < 10; c++) {
            tabuleiro[l][c] = 0;
        }
    }

    if (colunaH + 2 > 9) {
        printf("Erro: navio horizontal nao cabe\n");
        return 1;
    }

    erro = 0;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) erro = 1;
    }
    if (erro) {
        printf("Erro: navio horizontal sobrepoe\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }

    if (linhaV + 2 > 9) {
        printf("Erro: navio vertical nao cabe\n");
        return 1;
    }

    erro = 0;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) erro = 1;
    }
    if (erro) {
        printf("Erro: navio vertical sobrepoe\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

    if (linhaD1 + 2 > 9 || colunaD1 + 2 > 9) {
        printf("Erro: diagonal 1 nao cabe\n");
        return 1;
    }

    erro = 0;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) erro = 1;
    }
    if (erro) {
        printf("Erro: diagonal 1 sobrepoe\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = navioD1[i];
    }

    if (linhaD2 + 2 > 9 || colunaD2 - 2 < 0) {
        printf("Erro: diagonal 2 nao cabe\n");
        return 1;
    }

    erro = 0;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) erro = 1;
    }
    if (erro) {
        printf("Erro: diagonal 2 sobrepoe\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = navioD2[i];
    }

    printf("\nTABULEIRO (0 = agua, 3 = navio)\n\n");

    printf("   ");
    for (c = 0; c < 10; c++) {
        printf("%d ", c);
    }
    printf("\n");

    for (l = 0; l < 10; l++) {
        printf("%d: ", l);
        for (c = 0; c < 10; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }

    return 0;
}
