#include<windows.h>
#include<string.h>
#include<stdio.h>
//int x=0;
void gotoxy(int x,int y)
{
    COORD coord = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


/* gotoxy() copied from:
https://stackoverflow.com/posts/20727827/revisions
at https://stackoverflow.com/questions/9782287/undefined-reference-to-gotoxy-in-c
*/

int getInt(void) //gets an integer from user
{
    char str[40];
    gets(str);
    int i,sum=0,len=strlen(str);
    for(i=0; i<len; ++i)
    {
        if(str[i]>47 && str[i]<58)
        {
            sum=sum*10+str[i]-48;
        }

        else
        {
            sum=0;
            break;
        }

    }
    return sum;
}

void showHelp(void)
{
    gotoxy(20,17);
    printf("Control Keys:");
    gotoxy(40,18); //37+3
    printf("W");
    gotoxy(37,19);
    printf("A");
    gotoxy(40,19);
    printf("S");
    gotoxy(43,19);
    printf("D");
    gotoxy(20,21);
    printf("Press a control key to start.");
}

void clrInside(int border) //clears everything inside border (if present) or whole playing area
{
    int i=border,j,r=24,c=80-border;

    for(;i<c;i++)
    {
        for(j=border;j<r;j++)
        {
            gotoxy(i,j);
            printf(" ");
        }
    }
}

void clrLu(void) //clears the level up text
{
    gotoxy(35,28);
    printf("           ");
}

void loading(void)
{
    int j;
    system("cls");
    gotoxy(34,12);
    printf("Loading...");
    gotoxy(0,24);
    for(j=0; j<80; j++)
    {
        printf("%c",176);
        Sleep(15);
    }
}

void typEff(char str[],unsigned long sleepTime)
{
    int i,len=strlen(str);
    for(i=0; i<len; i++)
    {
        if(!(str[i]==' ' || str[i]=='\n'))
            Sleep(sleepTime);
        printf("%c",str[i]);
    }
}
