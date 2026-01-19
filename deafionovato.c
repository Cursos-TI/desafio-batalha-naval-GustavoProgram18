#include <stdio.h>

int main() {
    // TABULEIRO 10x10 (0 = agua, 3 = navio)
    int tabuleiro[10][10];

    // NAVIOS (vetores 1D) tamanho fixo 3
    int navioH[3] = {3, 3, 3}; // horizontal
    int navioV[3] = {3, 3, 3}; // vertical

    // COORDENADAS INICIAIS (definidas no codigo)
    // (linha e coluna vao de 0 ate 9)
    int linhaH = 2, colunaH = 1; // navio horizontal começa aqui
    int linhaV = 5, colunaV = 7; // navio vertical começa aqui

    int i, l, c;
    int erro = 0;

    // 1) Inicializa o tabuleiro com 0
    for (l = 0; l < 10; l++) {
        for (c = 0; c < 10; c++) {
            tabuleiro[l][c] = 0;
        }
    }

    // 2) Validar se o navio horizontal cabe (coluna + 2 nao pode passar de 9)
    if (colunaH < 0 || colunaH > 9 || linhaH < 0 || linhaH > 9) {
        printf("Erro: coordenadas do navio horizontal fora do tabuleiro.\n");
        return 1;
    }
    if (colunaH + 2 > 9) {
        printf("Erro: navio horizontal nao cabe no tabuleiro.\n");
        return 1;
    }

    // 3) Colocar navio horizontal (e checar sobreposicao)
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            erro = 1; // ja tinha algo ali
        }
    }
    if (erro == 1) {
        printf("Erro: navio horizontal iria sobrepor outro navio.\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioH[i]; // copia o 3 do vetor pro tabuleiro
    }

    // 4) Validar se o navio vertical cabe (linha + 2 nao pode passar de 9)
    if (colunaV < 0 || colunaV > 9 || linhaV < 0 || linhaV > 9) {
        printf("Erro: coordenadas do navio vertical fora do tabuleiro.\n");
        return 1;
    }
    if (linhaV + 2 > 9) {
        printf("Erro: navio vertical nao cabe no tabuleiro.\n");
        return 1;
    }

    // 5) Colocar navio vertical (e checar sobreposicao)
    erro = 0;
    for (i = 0; i < 3; i++) {
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            erro = 1;
        }
    }
    if (erro == 1) {
        printf("Erro: navio vertical iria sobrepor outro navio.\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

    // 6) Mostrar tabuleiro
    printf("\nTABULEIRO (0 = agua, 3 = navio)\n\n");

    // imprime numeracao de colunas (so pra ficar mais facil ver)
    printf("   ");
    for (c = 0; c < 10; c++) {
        printf("%d ", c);
    }
    printf("\n");

    for (l = 0; l < 10; l++) {
        printf("%d: ", l); // numero da linha
        for (c = 0; c < 10; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n");
    }

    return 0;
}
