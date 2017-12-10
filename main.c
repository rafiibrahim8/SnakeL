#include <stdio.h>
#include <conio.h>
#include <windows.h>

void runGame(int gameMode,int level,int border);
int getInt(void);
void gotoxy(int x,int y);
void loading(void);
void about(void);

int main()
{
    int i[3]= {0,1,0};
    char choice,c[3];
    SetConsoleTitle("Snake-L");
    system("COLOR 2A");
    //system("COLOR 0A");
    printf("\n Alhamdulillah!\n Done by help of Almighty Allah.");
    printf("\n\n Please the maximize window for smooth playing.\n Game version: 1.51\n\n Press \"A\" for License and Other Information. Press any other key for game.\n\n\t\t\tPress a key to continue...");
    choice=getch();

    system("cls");

    if(choice=='a'||choice=='A')
    {
        about();
        system("cls");
    }

    do
    {
        printf(" Game mode:\n\t1. Classic\n\t2. Campaign\n\n Please, press 1 or 2.\n\n");
        c[0]=getch();
        i[0]=c[0]-49;
    }
    while(!(c[0]=='1'||c[0]=='2'));

    if(c[0]=='1')
    {
        do
        {
            printf("\n Enter Level 1-10: ");
            i[1]=getInt();
            c[1]=i[1];
        }
        while(c[1]<1 || c[1]>10);

        do
        {
            printf("\n Game option:\n\t1. No Border\n\t2. With Border\n\n Please, press 1 or 2.\n\n");
            c[2]=getch();
            i[2]=c[2]-49;
        }
        while(!(c[2]=='1'||c[2]=='2'));

    }

    else
    {
        do
        {
            printf("\n Game option:\n\t1. No Border\n\t2. With Border\n\n Please, press 1 or 2.\n\n");
            c[2]=getch();
            i[2]=c[2]-49;
        }
        while(!(c[2]=='1'||c[2]=='2'));
    }
    loading();
    runGame(i[0],i[1],i[2]);
    return 0;
}
