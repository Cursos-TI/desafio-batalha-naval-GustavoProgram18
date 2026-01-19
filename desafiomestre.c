#include <stdio.h>

#define TAM 10
#define H 7
#define W 7
#define AGUA 0
#define NAVIO 3
#define EFEITO 5

void construirCone(int m[H][W]) {
    int centro = W / 2;
    int l, c;

    for (l = 0; l < H; l++) {
        for (c = 0; c < W; c++) {
            if (c >= (centro - l) && c <= (centro + l)) {
                m[l][c] = 1;
            } else {
                m[l][c] = 0;
            }
        }
    }
}

void construirCruz(int m[H][W]) {
    int centroL = H / 2;
    int centroC = W / 2;
    int l, c;

    for (l = 0; l < H; l++) {
        for (c = 0; c < W; c++) {
            if (l == centroL || c == centroC) {
                m[l][c] = 1;
            } else {
                m[l][c] = 0;
            }
        }
    }
}

void construirOctaedro(int m[H][W]) {
    int centroL = H / 2;
    int centroC = W / 2;
    int l, c;

    for (l = 0; l < H; l++) {
        for (c = 0; c < W; c++) {
            int dist = (l - centroL);
            if (dist < 0) dist = -dist;

            int distC = (c - centroC);
            if (distC < 0) distC = -distC;

            if (dist + distC <= centroL) {
                m[l][c] = 1;
            } else {
                m[l][c] = 0;
            }
        }
    }
}

void aplicarHabilidade(int tab[TAM][TAM], int hab[H][W], int origemL, int origemC) {
    int l, c;
    int offL = H / 2;
    int offC = W / 2;

    for (l = 0; l < H; l++) {
        for (c = 0; c < W; c++) {
            if (hab[l][c] == 1) {
                int tl = origemL + (l - offL);
                int tc = origemC + (c - offC);

                if (tl >= 0 && tl < TAM && tc >= 0 && tc < TAM) {
                    if (tab[tl][tc] != NAVIO) {
                        tab[tl][tc] = EFEITO;
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    int navioH[3] = {3, 3, 3};
    int navioV[3] = {3, 3, 3};
    int navioD1[3] = {3, 3, 3};
    int navioD2[3] = {3, 3, 3};

    int linhaH = 2, colunaH = 1;
    int linhaV = 5, colunaV = 7;

    int linhaD1 = 0, colunaD1 = 4;
    int linhaD2 = 0, colunaD2 = 9;

    int cone[H][W];
    int cruz[H][W];
    int octaedro[H][W];

    int origemConeL = 3, origemConeC = 3;
    int origemCruzL = 6, origemCruzC = 2;
    int origemOctL = 5, origemOctC = 6;

    int i, l, c;
    int erro = 0;

    for (l = 0; l < TAM; l++) {
        for (c = 0; c < TAM; c++) {
            tabuleiro[l][c] = AGUA;
        }
    }

    if (colunaH + 2 > 9) {
        printf("Erro: navio horizontal nao cabe\n");
        return 1;
    }

    erro = 0;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linhaH][colunaH + i] != AGUA) erro = 1;
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
        if (tabuleiro[linhaV + i][colunaV] != AGUA) erro = 1;
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
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != AGUA) erro = 1;
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
        if (tabuleiro[linhaD2 + i][colunaD2 - i] != AGUA) erro = 1;
    }
    if (erro) {
        printf("Erro: diagonal 2 sobrepoe\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = navioD2[i];
    }

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, origemConeL, origemConeC);
    aplicarHabilidade(tabuleiro, cruz, origemCruzL, origemCruzC);
    aplicarHabilidade(tabuleiro, octaedro, origemOctL, origemOctC);

    printf("\nTABULEIRO (0 = agua, 3 = navio, 5 = area de habilidade)\n\n");

    printf("   ");
    for (c = 0; c < TAM; c++) {
        printf("%d ", c);
    }
    printf("\n");

    for (l = 0; l < TAM; l++) {
        printf("%d: ", l);
        for (c = 0; c < TAM; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }

    printf("\nOrientacao GitHub:\n");
    printf("1) git add .\n");
    printf("2) git commit -m \"feat: adiciona habilidades especiais (cone, cruz e octaedro)\"\n");
    printf("3) git push\n");

    return 0;
}
