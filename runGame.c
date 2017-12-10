/*Alhamdulillah*/

#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>
#define HEAD 178
#define BODY 177
#define MAXCOORD 1024
#define FOOD '*'

void gotoxy(int x,int y);
void printBorder(void);
void openSnake(void);
void runSnake(void);
void isGameOver(int x,int y,int crdNum);
char getDir(char older);
void typEff(char str[],unsigned long sleepTime);
void getFood(int crdNum);
int eatFood(int x,int y);
void clearStart(void);
int isEmpty(int x,int y,int crdNum,int skip); //As we checking weather current head position is empty or not for G-Over, Head must be skipped (skip=1)
void display(void);
void showHelp(void);
void isLu(void);
void clrInside(int border);
void clrLu(void);


struct position
{
    int x;
    int y;
};

struct position xy[MAXCOORD];
struct position food;
int length=4,lvl=1,score=0;
int lvlScor=0,lvlTar[10]= {10,40,100,200,350,560,840,1200,1650,-1};
int gMode=1,brdr=1,gOv=0,Lu=0;

void runGame(int gameMode,int level,int border)
{
    system("cls");
    srand((unsigned)time(NULL));
    char choice;
    gMode=gameMode;
    brdr=border;
    showHelp();
    for(;;)
    {
        lvl=level;
        score=0;
        gOv=0;
        lvlScor=0;
        while(!gOv)
        {
            openSnake();
            runSnake();
        }

        choice=getch();
        if(!(choice=='r' || choice=='R'))
            break;
        clrInside(brdr);
    }
}

void printBorder(void)
{
    int i;
    if(brdr)
    {
        for(i=0; i<80; i++)
        {
            gotoxy(i,0);
            printf("%c",219);
        }

        for(i=1; i<24; i++)
        {
            gotoxy(0,i);
            printf("%c",219);
            gotoxy(79,i);
            printf("%c",219);
        }
    }

    for(i=0; i<80; i++)
    {
        gotoxy(i,24);
        printf("%c",219);
    }

}

void openSnake(void) //initialize the snake
{
    int i,j;
    char c;
    printBorder();
    display();
    if(score==0)
        showHelp();
    else
        clrInside(brdr);
    gotoxy(38,11);
    printf("%c%c%c%c",BODY,BODY,BODY,HEAD);
    length=4;
    //assigning first 4 part of snake to xy
    for(j=0,i=38; i<42; i++,j++)
    {
        xy[j].x=i;
        xy[j].y=11;
    }
    while(1)
    {
        c=getch();
        if(c=='w' || c=='W' || c=='a' || c=='A' || c=='s' || c=='S' || c=='d' || c=='D')
            break;
    }

    if(Lu)
    {
        Lu=0;
        clrLu();
    }
}

void runSnake(void)
{
    int coordNum=3,i=41,j=11,ersNum=0,bodyCoordNum;
    char dir='R';
    clearStart();
    getFood(coordNum);

    while(!gOv && !Lu)
    {
        gotoxy(0,0); //for full display after maximization on running game
        coordNum++;
        if(coordNum>=MAXCOORD)
            coordNum=0;
        if(kbhit())
            dir=getDir(dir);

        switch(dir)
        {
        case 'R':
            xy[coordNum].x=++i;
            xy[coordNum].y=j;
            break;
        case 'U':
            xy[coordNum].x=i;
            xy[coordNum].y=--j;
            break;
        case 'L':
            xy[coordNum].x=--i;
            xy[coordNum].y=j;
            break;
        case 'D':
            xy[coordNum].x=i;
            xy[coordNum].y=++j;
            break;
        default:
            printf("\a");
        }

        if(!brdr)
        {
            if(j>23 && dir=='D')
            {
                j=0;
                xy[coordNum].y=0;
            }
            if(j<0 && dir=='U')
            {
                j=23;
                xy[coordNum].y=23;
            }
            if(i>79 && dir=='R')
            {
                i=0;
                xy[coordNum].x=0;
            }
            if(i<0 && dir=='L')
            {
                i=79;
                xy[coordNum].x=79;
            }
        }
        gotoxy(xy[coordNum].x,xy[coordNum].y);
        printf("%c",HEAD);
        if(coordNum!=0)
            bodyCoordNum=coordNum-1;
        else
            bodyCoordNum=MAXCOORD-1;
        gotoxy(xy[bodyCoordNum].x,xy[bodyCoordNum].y);
        printf("%c",BODY);
        gotoxy(xy[ersNum].x,xy[ersNum].y);
        printf(" ");
        if(eatFood(i,j))
        {
            length++;
            getFood(coordNum);
        }
        else
        {
            ersNum++;
            if(ersNum>=MAXCOORD)
                ersNum=0;
        }
        isGameOver(i,j,coordNum);
        display();
        Sleep(79+21*(11-lvl));
        if(gMode)
            isLu();
    }
}

char getDir(char older) //gets direction from user
{
    char c=getch();
    if((older!='L')&&(c=='d'||c=='D'))
        return 'R';
    else if((older!='D')&&(c=='w'||c=='W'))
        return 'U';
    else if((older!='R')&&(c=='a'||c=='A'))
        return 'L';
    else if((older!='U')&&(c=='s'||c=='S'))
        return 'D';
    else
        return older;
}

void isGameOver(int x,int y,int crdNum) //checks for game over
{
    int i,j,govA=0,govB=0;
    gOv=0;
    if(brdr && (x==0 || x==79 || y==0 || y==24))
        govA=1;

    govB=!isEmpty(x,y,crdNum,1);
    if(govA || govB)
    {
        for(j=11; j<17; j++)
        {
            gotoxy(30,j);
            for(i=0; i<12; i++)
                printf(" ");
        }
        gotoxy(32,12);
        typEff("Game Over!",150);
        gotoxy(32,14);
        printf("Score: %d",score);

        gotoxy(13,16);
        printf("Press R to play again. Any other key to exit.");

        gOv=1;
    }
}

void getFood(int crdNum) //generate food
{
    int okay;
    do
    {
        food.x=rand()%(80-brdr*2)+brdr;
        food.y=rand()%(24-brdr)+brdr;
        okay=isEmpty(food.x,food.y,crdNum,0);
    }
    while(!okay);

    gotoxy(food.x,food.y);
    printf("%c",FOOD);
}

int eatFood(int x,int y) //checks for food eating
{
    int r=0;
    if(food.x==x && food.y==y)
    {
        score+=lvl;
        lvlScor+=lvl;
        r=1;
    }
    return r;
}

void clearStart(void) //clears the help text
{
    int i,j;
    for(i=20; i<50; i++)
    {
        for(j=17; j<22; j++)
        {
            gotoxy(i,j);
            printf(" ");
        }
    }
}

int isEmpty(int x,int y,int crdNum,int skip) //checks whether a location is empty from snake body or not
{
    int i,k=crdNum-skip,r=1,n=length-skip;
    for(i=0; i<n; i++)
    {
        if(xy[k].x==x && xy[k].y==y)
        {
            r=0;
            break;
        }
        k--;
        if(k<0)
            k+=MAXCOORD;
    }
    return r;
}

void display(void) //display score and other things
{
    switch(gMode)
    {
    case 0:
        gotoxy(3,27);
        printf("Level: %5d",lvl);
        gotoxy(3,28);
        printf("Score: %5d",score);
        break;
    case 1:
        gotoxy(3,27);
        printf("Level      : %5d",lvl);
        gotoxy(3,28);
        printf("Total Score: %5d",score);
        gotoxy(61,27);
        if(lvl<10)
            printf("Level Target: %4d",lvlTar[lvl-1]);
        else
            printf("Level Target: inf ");
        gotoxy(61,28);
        printf("Level Score : %4d",lvlScor);
        break;

    default:
        printf("\a");
        break;
    }
}

void isLu(void) //checks for level up
{
    if(lvlScor>=lvlTar[lvl-1] && lvl<10)
    {
        lvl++;
        lvlScor=0;
        gotoxy(35,28);
        typEff("Level up!!",150);
        Lu=1;
        while(kbhit()) //if user press key while typeEff()
            getch();
    }
}

