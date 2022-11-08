#include <stdio.h>

int left_rocket();
int right_rocket();

int main() {
    int coordL = 12;
    int coordR = 12;
    int ballX = 40;
    int ballY = 12;
    int speedX = 1;
    int speedY = 1;
    int goalL = 0;
    int goalR = 0;

    while (1) {
        printf("P1| SCORE: %d\n", goalL);
        printf("P2| SCORE: %d\n", goalR);
        for (int x = 0; x <= 80; x++) {
            printf("-");
        }
        printf("\n");
        for (int y = 0; y <= 23; y++) {
            for (int x = 0; x <= 80; x++) {
                if (x == 5 && (y == coordL || y == coordL + 1 || y == coordL - 1)) {
                    printf("|");
                } else {
                    if (x == ballX && y == ballY) {
                        printf("*");
                    } else {
                        if (x == 75 && (y == coordR || y == coordR + 1 || y == coordR -1)) {
                            printf("|");
                        } else {
                            printf(" ");
                        }
                    }
                }
            } printf(" \n");
        }
        for (int x = 0; x <= 80; x++) {
            printf("-");
        }
        // стенки прописаны
        coordR = right_rocket(coordR);
        coordL = left_rocket(coordL);

        // вектора мяча
        ballX += speedX;
        ballY += speedY;

        if (ballY == 23 || ballY == 0) {
            speedY = speedY * (-1);
        }
        if (ballX == 5 && (ballY == coordL || ballY == coordL + 1 || ballY == coordL - 1)) {
            speedX = speedX * (-1);
        }
        if (ballX == 75 && (ballY == coordR || ballY == coordR + 1 || ballY == coordR - 1)) {
            speedX = speedX * (-1);
        }

        if (ballX == 0) {
            ballX = 40;
            ballY = 13;
            speedY = speedY * (-1);
            goalR++;
        }
        if (ballX == 80) {
        ballX = 40;
        ballY = 13;
        speedX = speedX * (-1);
        goalL++;
        }
        printf("\033c");

        if (goalL == 21) {
            printf("Победил игрок PLAYER 1\n");
            break;
        } else if (goalR == 21) {
            printf("Победил игрок PLAYER 2\n");
            break;
        }
    }
}

int left_rocket(int roc_left) {  // управление левым игроком
    char l1 = getchar();
    if ((l1 == 'a' || l1 == 'A') && roc_left != 1) {
        roc_left--;
    } else {
        if ((l1 == 'z' || l1 == 'Z') && roc_left !=22) {
            roc_left++;
        }
    }
    return roc_left;
}

int right_rocket(int roc_right) {  // управление правым игром
    char r1 = getchar();
    if ((r1 == 'k' || r1 == 'K') && roc_right != 1) {
        roc_right--;
    } else {
        if ((r1 == 'm' || r1 == 'M') && roc_right !=22) {
            roc_right++;
        }
    }
    return roc_right;
}

