#ifndef PONG_H
#define PONG_H

#include <stdio.h>

struct ball {
    int coordL;
    int coordR;
    int ballY;
    int ballX;
    int speedX;
    int speedY;
    int goalR;
    int goalL;
    int lastGoal;
};

extern struct ball condition;

void setDefault(struct ball *condition);
int ifColour(int);
int left_rocket();
int right_rocket();
void WinScore(struct ball *condition);
void DrowScore(struct ball *condition);
void DrowPole(struct ball *condition, int);
char DrowGreat(int, int);
void ChangeVector(struct ball *condition);
void AddScore(struct ball *condition);

#endif