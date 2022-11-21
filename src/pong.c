#include "pong.h"

int main() {
  int ifColor = 0;
  if (ifColour(ifColor)) ifColor=1;


  while (1) {
    if (goalL >= 10 || goalR >= 10) break;

    DrowScore(p_goalL, p_goalR);
    DrowPole(p_coordL, p_coordR, p_ballX, p_ballY, ifColor);

    coordR = right_rocket(coordR);
    coordL = left_rocket(coordL);

    // вектора мяча
    ballX += speedX;
    ballY += speedY;

    ChangeVector(p_ballX, p_ballY, p_speedX, p_speedY, p_coordL, p_coordR);
    AddScore(p_ballX, p_ballY, p_speedX, p_speedY, p_goalL, p_goalR);
    printf("\033c");
  }
  DrowGreat(2, ifColor);
  return 0;
}

int ifColour (int flag){
  DrowGreat(0, 0);
  if (getchar() == '\n') {
    printf("\033c");
    DrowGreat(1, 0);
    }
    char c = getchar();
  if (c == 'y' || c == 'Y') flag = 1;
    printf("\033c");
  return flag;
}

char DrowGreat(int begining, int flag) {
  for (int x = 0; x <= 80; x++) printf("-");
  printf("\n");
  for (int y = 0; y <= 23; y++) {
    for (int x = 0; x <= 80; x++) {
      if (begining == 0) {
        if (x == 30 && y == 10) printf("IT'S PING PONG GAME");
        if (x == 33 && y == 12) printf("(press enter)");
        if (x == 0 && y == 22) printf("USE A/Z TO PLAY LEFT PLAYER");
        if (x == 26 && y == 22) printf("USE K/M TO PLAY RIGHT PLAYER");
        else printf(" ");
      } else if (begining == 1) {
        if (x == 20 && y == 13) {
          printf("WOULD YOU LOKE TO PLAY IT IN COLOUR?(Y/N)");
        } else printf(" ");
      } else if (begining == 2) {
          if (x == 30 && y == 12) {
          WinScore(p_goalL, p_goalR);
      } else printf(" ");
      }
    }
    printf(" \n");
  }
  for (int x = 0; x <= 80; x++) printf("-");

  printf(" \n");

  return flag;
}


void WinScore(int* goalL, int* goalR) {
  if (*goalL > *goalR)
    printf("AND THE WINNER IS: PLAYER 1");
  else if (*goalL < *goalR)
    printf("AND THE WINNER IS: PLAYER 2");
}

void ChangeVector(int* ballX, int* ballY, int *speedX, int *speedY, int* coordL, int* coordR) {
  if (*ballY == 23 || *ballY == 0) *speedY *= (-1);
  if (*ballX == 5 && (*ballY == *coordL || *ballY == *coordL + 1 || *ballY ==  *coordL - 1)) *speedX *= (-1);
  if (*ballX == 75 && (*ballY ==  *coordR || *ballY == *coordR + 1 || *ballY == *coordR - 1)) *speedX *= (-1);
}

void AddScore(int* ballX, int* ballY, int* speedX, int* speedY, int* goalL,
              int* goalR) {
  if (*ballX == 0) {
    *ballX = 40;
    *ballY = 13;
    *speedY = *speedY * (-1);
    *goalR += 1;
    *speedX *= (-1);
    *speedY *= (-1);
  }
  if (*ballX == 80) {
    *ballX = 40;
    *ballY = 13;
    *speedX = *speedX * (-1);
    *goalL += 1;
    *speedX *= (1);
    *speedY *= (1);
  }
}

// void AddScore(ball b) {
//   if (b.ballX == 0) {
//     b.ballX = 40;
//     b.ballY = 13;
//     b.speedY = b.speedY * (-1);
//     b.goalR += 1;
//     b.speedX *= (-1);
//     b.speedY *= (-1);
//   }
//   if (b.ballX == 80) {
//     b.ballX = 40;
//     b.ballY = 13;
//     b.speedX = b.speedX * (-1);
//     b.goalL += 1;
//     b.speedX *= (1);
//     b.speedY *= (1);
//   }
// }

void DrowScore(int* goalL, int* goalR) {
  printf("P1| SCORE: %d\n", *goalL);
  printf("P2| SCORE: %d\n", *goalR);
}

void DrowPole(int* coordL, int* coordR, int* ballX, int* ballY, int flag) {
  for (int x = 0; x <= 80; x++) printf("-");
  printf("\n");
  for (int y = 0; y <= 23; y++) {
    for (int x = 0; x <= 80; x++) {
        if (x == *ballX && y == *ballY && flag == 0) printf("*");
        else if (x == *ballX && y == *ballY && flag == 1) printf("\033[102m*\033[0m");
      else if (x == 5 && (y == *coordL || y == *coordL + 1 || y == *coordL - 1)) printf("|");
        else if (x == 75 && (y == *coordR || y == *coordR + 1 || y == *coordR - 1)) printf("|");
          else if (flag == 0) printf(" ");
          else printf("\033[102m \033[0m");
        }
    printf(" \n");
  }
  for (int x = 0; x <= 80; x++) printf("-");
  printf(" \n");
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
