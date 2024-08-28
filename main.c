#include <stdio.h>

char board[3][3];
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return 1;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return 1;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return 1;
    return 0;
}

int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void makeMove(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
    } else {
        printf("Posição já ocupada! Tente novamente.\n");
    }
}

int main() {
    int row, col;
    initializeBoard();
    while (1) {
        printBoard();
        printf("Jogador %c, insira a linha e coluna (0, 1, 2): ", currentPlayer);
        scanf("%d %d", &row, &col);
        makeMove(row, col);
        if (checkWin()) {
            printBoard();
            printf("Jogador %c venceu!\n", currentPlayer);
            break;
        }
        if (checkDraw()) {
            printBoard();
            printf("Empate!\n");
            break;
        }
        switchPlayer();
    }
    return 0;
}
