#ifndef TTT_H
#define TTT_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void intro();
void draw();
void horizontal();
void vertical(int);;
void loading();
void instruction();
void game();
char logic();
void score_board();
void final_score();

struct dets
{
    char name[50];
    int score;
};

struct game_data
{
    struct dets pl[2], temp;
    char ch[10];
};

#endif
