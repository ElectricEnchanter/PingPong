#include "pong.h"

int main() {
  while (1) {
    if (goalL >= 5 || goalR >= 5) break;

    DrowScore(p_goalL, p_goalR);
    drowPole(p_coordL, p_coordR, p_ballX, p_ballY);

    // стенки прописаны
    coordR = right_rocket(coordR);
    coordL = left_rocket(coordL);

    // вектора мяча
    ballX += speedX;
    ballY += speedY;

    ChangeVector(p_ballX, p_ballY, p_speedX, p_speedY, p_coordL, p_coordR);
    AddScore(p_ballX, p_ballY, p_speedX, p_speedY, p_goalL, p_goalR);
    printf("\033c");
  }
  WinScore(goalL, goalR);
}

void WinScore(int goalL, int goalR) {
  if (goalL > goalR)
    printf("Победил игрок PLAYER 1\n");
  else if (goalL < goalR)
    printf("Победил игрок PLAYER 2\n");
}

void ChangeVector(int* ballX, int* ballY, int *speedX, int *speedY, int* coordL, int* coordR) {
  if (*ballY == 23 || *ballY == 0) *speedY = *speedY * (-1);
  if (*ballX == 5 && (*ballY == *coordL || *ballY == *coordL + 1 || *ballY ==  *coordL - 1)) *speedX = *speedX * (-1);
  if (*ballX == 75 && (*ballY ==  *coordR || *ballY == *coordR + 1 || *ballY == *coordR - 1)) *speedX = *speedX * (-1);
}

void AddScore(int* ballX, int* ballY, int* speedX, int* speedY, int* goalL,
              int* goalR) {
  if (*ballX == 0) {
    *ballX = 40;
    *ballY = 13;
    *speedY = *speedY * (-1);
    *goalR = *goalR + 1;
  }
  if (*ballX == 80) {
    *ballX = 40;
    *ballY = 13;
    *speedX = *speedX * (-1);
    *goalL = *goalL + 1;
  }
}

void DrowScore(int* goalL, int* goalR) {
  printf("P1| SCORE: %d\n", *goalL);
  printf("P2| SCORE: %d\n", *goalR);
}

void drowPole(int* coordL, int* coordR, int* ballX, int* ballY) {
  for (int x = 0; x <= 80; x++) printf("-");
  printf("\n");
  for (int y = 0; y <= 23; y++) {
    for (int x = 0; x <= 80; x++) {
        if (x == *ballX && y == *ballY) printf("\033[102m*\033[0m");
      else if (x == 5 && (y == *coordL || y == *coordL + 1 || y == *coordL - 1)) printf("|");
        else if (x == 75 && (y == *coordR || y == *coordR + 1 || y == *coordR - 1)) printf("|");
          else printf("\033[102m \033[0m");
        }
    printf(" \n");
  }
  for (int x = 0; x <= 80; x++) printf("-");
}

int left_rocket(int roc_left) {  // управление левым игроком
  char l1 = getchar();
  if ((l1 == 'a' || l1 == 'A') && roc_left != 1) {
    roc_left--;
  } else {
    if ((l1 == 'z' || l1 == 'Z') && roc_left != 22) {
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
    if ((r1 == 'm' || r1 == 'M') && roc_right != 22) {
      roc_right++;
    }
  }
  return roc_right;
}
