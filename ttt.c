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
}gm;


int main()
{
    char try;
    gm.pl[0].score = 0;
    gm.pl[1].score = 0;

    system("clear");
    intro();
    printf("%80sEnter the name of player 1: ", "");
    scanf(" %[^\n]", gm.pl[0].name);
    printf("%80sEnter the name of player 2: ", "");
    scanf(" %[^\n]", gm.pl[1].name);
re_try:
    strcpy(gm.ch, "123456789");
    loading();
    instruction();
    system("clear");
    game();
    system("clear");
invalid:
    printf("%80sDo you want to play again 😡😡? Press Y/N ", "");
    scanf(" %c", &try);
    if(try == 'Y' || try == 'y')
    {
        gm.temp = gm.pl[0];
        gm.pl[0] = gm.pl[1];
        gm.pl[1] = gm.temp;
        goto re_try;
    }
    else if(try == 'N' || try == 'n')
    {
        final_score();
        sleep(5);
        if(gm.pl[0].score > gm.pl[1].score)
        {
            printf("%80s The winner is %s 🥳🥳 ", "", gm.pl[0].name);
            puts("💜");
            return 0;
        }
        else if(gm.pl[0].score < gm.pl[1].score)
        {
            printf("%80s The winner is %s 🥳🥳 ", "", gm.pl[1].name);
            puts("💜");
            return 0;
        }
        else
        {
            printf("%80sThe match draw 🤝🤝 ", "");
            puts("💜");
            return 0;
        }
    }
    else
    {
        printf("\n%80sInvlaid entry!!", "");
        goto invalid;
    }
    system("clear");
}

void intro()
{
    printf("%105s\n", "Welcome to Tik Tac Toe");
    printf("\t%105s", "press ENTER key to continue");
    getchar();
    system("clear");
}

void draw()
{
    for(int i=0; i<=18; i++)
    {
        printf("%80s", "");
        if(i == 0 || i == 6 || i == 12 || i == 18)
            horizontal();
        else
            vertical(i);
        printf("\n");
    }
}

void horizontal()
{
    for(int i=0; i<=30; i++)
    {
        if(i == 0 || i == 10 || i == 20 || i == 30)
            printf("+");
        else
            printf("-");
    }
}

void vertical(int pos)
{
    if(pos%3)
    {
        for(int i=0; i<=30; i++)
        {
            if(i == 0 || i == 10 || i == 20 || i == 30)
                printf("|");
            else
                printf(" ");
        }
    }
    else
    {
        for(int i=0; i<=30; i++)
        {
            if(i == 5 && pos == 3)
                printf("%c", gm.ch[0]);
            else if(i == 15 && pos == 3)
                printf("%c", gm.ch[1]);
            else if(i == 25 && pos == 3)
                printf("%c", gm.ch[2]);
            else if(i == 5 && pos == 9)
                printf("%c", gm.ch[3]);
            else if(i == 15 && pos == 9)
                printf("%c", gm.ch[4]);
            else if(i == 25 && pos == 9)
                printf("%c", gm.ch[5]);
            else if(i == 5 && pos == 15)
                printf("%c", gm.ch[6]);
            else if(i == 15 && pos == 15)
                printf("%c", gm.ch[7]);
            else if(i == 25 && pos == 15)
                printf("%c", gm.ch[8]);
            else if(i == 0 || i == 10 || i == 20 || i == 30)
                printf("|");
            else
                printf(" ");
        }
    }
}

void loading()
{
    system("clear");
    int t=1;
    do
    {
        char str[50] = "loading";
        int k=strlen(str);
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<14; j++)
                printf("\n");
            printf("%*s", 95+k-7, str);
            fflush(stdout);
            str[k++] = '.';
            str[k] = '\0';
            sleep(1);
            system("clear");
        }
    }while(t--);
}

void instruction()
{
    system("clear");
    printf("%80sGame instruction:\n", "");
    draw();
    sleep(5);
    printf("%80spress ENTER key to continue", "");
    getchar();
    getchar();
}

void game()
{
    strcpy(gm.ch, "         ");
    int i=1, check[9], pos;
    char input;

    for(int i=0; i<9; i++)
        check[i] = 0;
    while(i <= 9)
    {
        do
        {
            system("clear");
            score_board();
            draw();
            if(i%2)
            {
                printf("%80s which place do you want to mark? (X) ", gm.pl[1].name);
                input = 'X';
            }
            else
            {
                printf("%80s which place do you want to mark? (O) ", gm.pl[0].name);
                input = 'O';
            }
            fflush(stdin);
            scanf("%d", &pos);
        }while(!(pos >= 1 && pos <= 9) || (check[pos-1] == pos));

        gm.ch[pos-1] = input;
        check[pos-1] = pos;
        system("clear");
        if(logic() == 'O')
        {
            draw();
            printf("\n%80sPlayer %s wins👍", "", gm.pl[0].name);
            getchar();
            getchar();
            gm.pl[0].score++;
            return;
        }
        else if(logic() == 'X')
        {
            draw();
            printf("\n%80sPlayer %s wins👍", "", gm.pl[1].name);
            getchar();
            getchar();
            gm.pl[1].score++;
            return;
        }
        i++;
    }
    printf("%80sMatch tied🤝🤝", "");
    getchar();
    getchar();
    printf("\r");
}

char logic()
{
    if((gm.ch[0] == gm.ch[1]) && (gm.ch[1] == gm.ch[2]) && (gm.ch[0] != ' '))
        return gm.ch[0];
    if((gm.ch[0] == gm.ch[4]) && (gm.ch[0] == gm.ch[8]) && (gm.ch[0] != ' '))
        return gm.ch[0];
    if((gm.ch[0] == gm.ch[3]) && (gm.ch[3] == gm.ch[6]) && (gm.ch[0] != ' '))
        return gm.ch[0];
    if((gm.ch[3] == gm.ch[4]) && (gm.ch[3] == gm.ch[5]) && (gm.ch[3] != ' '))
        return gm.ch[3];
    if((gm.ch[6] == gm.ch[7]) && (gm.ch[6] == gm.ch[8]) && (gm.ch[6] != ' '))
        return gm.ch[6];
    if((gm.ch[1] == gm.ch[4]) && (gm.ch[1] == gm.ch[7]) && (gm.ch[1] != ' '))
        return gm.ch[1];
    if((gm.ch[2] == gm.ch[5]) && (gm.ch[2] == gm.ch[8]) && (gm.ch[2] != ' '))
        return gm.ch[2];
    if((gm.ch[2] == gm.ch[4]) && (gm.ch[2] == gm.ch[6]) && (gm.ch[2] != ' '))
        return gm.ch[2];
    return ' ';
}

void score_board()
{
    printf("%80sPlayer %s score = %d\n", "", gm.pl[0].name, gm.pl[0].score);
    printf("%80sPlayer %s score = %d\n", "", gm.pl[1].name, gm.pl[1].score);
}

void final_score()
{
    system("clear");
    printf("%80sScore:\n", "");
    printf("%80s+-------------------------------------------+\n", "");
    printf("%80s|Player %s score = %d|\n", "", gm.pl[0].name, gm.pl[0].score);
    printf("%80s|Player %s score = %d|\n", "", gm.pl[1].name, gm.pl[1].score);
    printf("%80s+-------------------------------------------+\n", "");
}
