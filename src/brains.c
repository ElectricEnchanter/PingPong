#include "pong.h"

int ifColour(int flag) {
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
        if (x == 26 && y == 22)
          printf("USE K/M TO PLAY RIGHT PLAYER");
        else
          printf(" ");
      } else if (begining == 1) {
        if (x == 25 && y == 10)
          printf("THE GAME WILL GO TO TEN POINTS");
        else if (x == 20 && y == 12)
          printf("WOULD YOU LOKE TO PLAY IT IN COLOUR?(Y/N)");
        else
          printf(" ");
      } else if (begining == 2) {
        if (x == 30 && y == 12) {
          WinScore(&condition);
        } else
          printf(" ");
      }
    }
    printf(" \n");
  }
  for (int x = 0; x <= 80; x++) printf("-");

  printf(" \n");
  return flag;
}

void WinScore(struct ball *condition) {
  if (condition->goalL > condition->goalR)
    printf("AND THE WINNER IS: PLAYER 1");
  else if (condition->goalL < condition->goalR)
    printf("AND THE WINNER IS: PLAYER 2");
}

void ChangeVector(struct ball *condition) {
  if (condition->ballY == 23 || condition->ballY == 0)
    condition->speedY *= (-1);
  if (condition->ballX == 5 && (condition->ballY == condition->coordL ||
                                condition->ballY == condition->coordL + 1 ||
                                condition->ballY == condition->coordL - 1)) {
    condition->speedX *= (-1);
    condition->lastGoal = 1;
  }
  if (condition->ballX == 75 && (condition->ballY == condition->coordR ||
                                 condition->ballY == condition->coordR + 1 ||
                                 condition->ballY == condition->coordR - 1)) {
    condition->speedX *= (-1);
    condition->lastGoal = 2;
  }
}

void setDefault(struct ball *condition) {
  condition->ballX = 40;
  condition->ballY = 12;
  condition->coordR = 12;
  condition->coordL = 12;
}

void AddScore(struct ball *condition) {
  if (condition->ballX == 0) {
    setDefault(condition);
    condition->speedY = condition->speedY * (-1);
    condition->goalR += 1;
    condition->speedX *= (-1);
    condition->speedY *= (-1);
    condition->lastGoal = 1;
  }
  if (condition->ballX == 80) {
    setDefault(condition);
    condition->speedX = condition->speedX * (-1);
    condition->goalL += 1;
    condition->lastGoal = 2;
    condition->speedX *= (1);
    condition->speedY *= (1);
  }
}

void DrowScore(struct ball *condition) {
  printf("P1| SCORE: %d\n", condition->goalL);
  printf("P2| SCORE: %d\n", condition->goalR);
}

void DrowPole(struct ball *condition, int flag) {
  if (flag == 1)
    for (int x = 0; x <= 80; x++) printf("\033[46m-\033[0m");
  else
    for (int x = 0; x <= 80; x++) printf("-");
  printf("\n");
  for (int y = 0; y <= 23; y++) {
    for (int x = 0; x <= 80; x++) {
      if (x == condition->ballX && y == condition->ballY && flag == 0)
        printf("*");
      else if (x == condition->ballX && y == condition->ballY && flag == 1)
        printf("\033[107m*\033[0m");
      else if (x == 40 && flag == 1)
        printf("\033[107m|\033[0m");
      else if (x == 40 && flag == 0)
        printf("|");
      else if (x == 5 &&
               (y == condition->coordL || y == condition->coordL + 1 ||
                y == condition->coordL - 1))
        printf("|");
      else if (x == 75 &&
               (y == condition->coordR || y == condition->coordR + 1 ||
                y == condition->coordR - 1))
        printf("|");
      else if (flag == 0)
        printf(" ");
      else
        printf("\033[42m \033[0m");
    }
    printf(" \n");
  }
  if (flag == 1)
    for (int x = 0; x <= 80; x++) printf("\033[46m-\033[0m");
  else
    for (int x = 0; x <= 80; x++) printf("-");
  printf("\n");
}

int left_rocket(int roc_left) {
  char l1 = getchar();
  if ((l1 == 'a' || l1 == 'A') && roc_left != 1)
    roc_left--;
  else if ((l1 == 'z' || l1 == 'Z') && roc_left != 22)
    roc_left++;
  return roc_left;
}

int right_rocket(int roc_right) {
  char r1 = getchar();
  if ((r1 == 'k' || r1 == 'K') && roc_right != 1)
    roc_right--;
  else if ((r1 == 'm' || r1 == 'M') && roc_right != 22)
    roc_right++;
  return roc_right;
}
