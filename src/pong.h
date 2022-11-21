#include <stdio.h>

typedef struct{
    int coordL;
    int coordR;
    int ballY;
    int ballX;
    int speedX;
    int speedY;
    int goalR;
    int goalL;
    int lastGoal;
} ball;

ball condition = {11, 11, 11, 39, 1, 1, 0, 0, 1};

void setDefault(ball *condition);
int ifColour(int);
int left_rocket();
int right_rocket();
void WinScore(ball *condition);
void DrowScore(ball *condition);
void DrowPole(ball *condition, int);
char DrowGreat(int, int);
void ChangeVector(ball *condition);
void AddScore(ball *condition);

