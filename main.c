#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "snakeheader.h"
int main()
{
    char c;
    label5:
    clrscr();
    setup();
    while(!gameover)
    {
        draw();
        input();
        InputLogic();
        for(int m=0;m<10000;m++)
        {
            for(int n=0;n<12000;n++)
            {

            }
        }
    }
    textcolor(LIGHTRED);
    printf("\nGame Over! You have scored %d \nYou have one last chance.\nPress Y to Continue again: \nAnd any other key to exit:-",score);
    textcolor(DARKGRAY);
    scanf("%c",&c);
    if(c=='y' || c=='Y')
    {
        goto label5;
    }
    return 0;
}
