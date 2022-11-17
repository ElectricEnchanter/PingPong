#include <stdio.h>

int coordL = 12, coordR = 12, ballY = 12;
int ballX = 40;
int speedX = 1, speedY = 1;
int goalL = 0, goalR = 0;
// char colour;

int *p_coordL = &coordL, *p_coordR = &coordR, *p_ballY = &ballY,
    *p_ballX = &ballX, *p_speedX = &speedX, *p_speedY = &speedY,
    *p_goalL = &goalL, *p_goalR = &goalR;

int left_rocket();
int right_rocket();
void WinScore();
void DrowScore(int*, int*);
void drowPole(int*, int*, int*, int*, int);
char DrowGreat();
void ChangeVector(int*, int*, int*, int*, int*, int*);
void AddScore(int*, int*, int*, int*, int*, int*);
