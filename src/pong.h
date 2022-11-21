#include <stdio.h>
//#include <ncurses.h>
#include <termios.h>

int coordL = 12, coordR = 12, ballY = 12;
int ballX = 40;
int speedX = 1, speedY = 1;
int goalL = 0, goalR = 0;

int *p_coordL = &coordL, *p_coordR = &coordR, *p_ballY = &ballY,
    *p_ballX = &ballX, *p_speedX = &speedX, *p_speedY = &speedY,
    *p_goalL = &goalL, *p_goalR = &goalR;


typedef struct{
    int coordL;
    int coordR;
    int ballY;
    int ballX;
    int speedX;
    int speedY;
    int goalR;
    int goalL;
} ball;

ball b = {12, 12, 12, 40, 1, 1, 0, 0};


int ifColour(int);
int left_rocket();
int right_rocket();
void WinScore(int*, int*);
void DrowScore(int*, int*);
void DrowPole(int*, int*, int*, int*, int);
char DrowGreat(int, int);
void ChangeVector(int*, int*, int*, int*, int*, int*);
void AddScore(int*, int*, int*, int*, int*, int*);
//void AddScore(ball b);

