#include "pong.h"

struct ball condition;

int main() {
  struct ball condition = {11, 11, 11, 39, 1, 1, 0, 0, 1};
  int ifColor = 0;
  if (ifColour(ifColor)) ifColor = 1;
  while (1) {
    if (condition.goalL >= 10 || condition.goalR >= 10) break;

    DrowScore(&condition);
    DrowPole(&condition, ifColor);

    if (condition.lastGoal == 1)
      condition.coordR = right_rocket(condition.coordR);
    else
      condition.coordL = left_rocket(condition.coordL);

    condition.ballX += condition.speedX;
    condition.ballY += condition.speedY;

    ChangeVector(&condition);
    AddScore(&condition);
    printf("\033c");
  }
  DrowGreat(2, ifColor);
  return 0;
}
