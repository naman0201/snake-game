#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "snakeheader.h"
int width=20,height=20;
int CountTail=0;
void setup()
{

    gameover=0;
    x=width/2;
    y=height/2;

    label1:
    fruitX=rand()%20;
    if(fruitX==0)
        goto label1;
    label2:
    fruitY=rand()%20;
    if(fruitY==0)
        goto label2;
    score=0;
}
void draw()
{
    clrscr();
    int i,j,k;
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            if(i==0 || i==height-1 || j==0 || j==width-1)
            {
                printf("*");
            }
            else
            {
                if(i==x && j==y)
                {
                    textcolor(GREEN);
                    printf("O");
                    textcolor(WHITE);
                }
                else if(i==fruitX && j==fruitY)
                {
                    textcolor(LIGHTBLUE);
                    printf("%d",CountTail+1);
                    textcolor(WHITE);
                }
                else
                {
                    int true=0;
                    for(k=0;k<CountTail;k++)
                    {
                        if(i==tailX[k] && j==tailY[k])
                        {
                            textcolor(LIGHTCYAN);
                            printf("~");
                            textcolor(WHITE);
                            true=1;
                        }
                    }
                    if(true==0)
                        printf(" ");
                }
            }
        }
        printf("\n");
    }
    return;
}

void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'w' :
            flag=1;
            break;
        case 'a' :
            flag=2;
            break;
        case 's' :
            flag=3;
            break;
        case 'd' :
            flag=4;
            break;
        case '9':
            gameover=1;
            break;
        }
    }
}
void InputLogic()
{
    int i;
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2X, prev2Y;
    tailX[0]=x;
    tailY[0]=y;
    for(i=1;i<CountTail;i++)
    {
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(flag)
    {
        case 1:
            x--;
            break;
        case 2:
            y--;
            break;
        case 3:
            x++;
            break;
        case 4:
            y++;
        default:
            break;
    }
    if(x<0 || x>width || y<0 || y>height)
    {
        gameover=1;
    }
        for(i=0;i<CountTail;i++)
        {
            if(x==tailX[i] && y==tailY[i])
            {
                gameover=1;
            }
        }
        if(x==fruitX && y==fruitY)
        {
            label3:
        fruitX=rand()%20;
        if(fruitX==0)
            goto label3;
        label4:
        fruitY=rand()%20;
        if(fruitY==0)
        {
            goto label4;
        }
            CountTail++;
        }
        score=CountTail;
}
