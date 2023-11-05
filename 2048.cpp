#include<windows.h>
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int a[4][4];
string ans[4][4];
int flag;
void gotoxy(int x, int y)
{
    COORD coord;
    HANDLE hscr;
    coord.X=x;
    coord.Y=y;
    hscr=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hscr, coord);
}
void color(short x)
{
    if(x>=0 && x<=15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
string oi(int x)
{
    switch(x)
    {
        case 0:return "   ";
        case 1:return "WT ";
        case 2:return "CE ";
        case 4:return "RE ";
        case 8:return "UKE";
        case 16:return  "MLE";
        case 32:return "TLE";
        case 64:return "OLE";
        case 128:return "WA ";
        case 256:return "PC ";
        case 512:return "AC ";
        case 1024:return "AU ";
        case 2048:return "AK ";
    }
}
//string oi(int x)
//{
//    switch(x)
//    {
//        case 0:return    "    ";
//        case 1:return    "1   ";
//        case 2:return    "2   ";
//        case 4:return    "4   ";
//        case 8:return    "8   ";
//        case 16:return   "16  ";
//        case 32:return   "32  ";
//        case 64:return   "64  ";
//        case 128:return  "128 ";
//        case 256:return  "256 ";
//        case 512:return  "512 ";
//        case 1024:return "1024";
//        case 2048:return "2048";
//    }
//}
void pt(string x)
{
    int l=x.length();
    for(int i=0;i<l;i++)
    {
        cout<<x[i];
        Sleep(10);
    }
    Sleep(30);
    cout<<endl;
}
void _rand()
{
    int x,y;
    do x=rand()%4,y=rand()%4;
    while(a[x][y]);
    if(rand()%2) a[x][y]=1;
    else a[x][y]=2;
}
void play()
{
    while(!flag)
    {
        flag=2;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                if(ans[i][j]!=oi(a[i][j]))
                {
                    ans[i][j]=oi(a[i][j]);
                    gotoxy(j*4,i);
                    cout<<ans[i][j];
                }
                if(a[i][j]==2048) flag=1;
                if(!a[i][j]) flag=0;
            }
        if(flag) break;
        char c;
        do c=getch();
        while(c!='a'&&c!='w'&&c!='s'&&c!='d');
        switch(c)
        {
            case 'a':
                for(int j=1;j<4;j++)
                    for(int i=0;i<4;i++)
                    {
                        int x=i,y=j;
                        while(a[i][j]&&y>=1&&!a[x][y-1])
                            y--;
                        if(y>=1&&a[x][y-1]==a[i][j]) a[x][y-1]+=a[i][j],a[i][j]=0;
                        else if(y!=j) a[x][y]=a[i][j],a[i][j]=0;
                    }
                break;
            case 'w':
                for(int i=1;i<4;i++)
                    for(int j=0;j<4;j++)
                    {
                        int x=i,y=j;
                        while(a[i][j]&&x>=1&&!a[x-1][y])
                            x--;
                        if(x>=1&&a[x-1][y]==a[i][j]) a[x-1][y]+=a[i][j],a[i][j]=0;
                        else if(x!=i) a[x][y]=a[i][j],a[i][j]=0;
                    }
                break;
            case 's':
                for(int i=2;i>=0;i--)
                    for(int j=0;j<4;j++)
                    {
                        int x=i,y=j;
                        while(a[i][j]&&x<=2&&!a[x+1][y])
                            x++;
                        if(x<=2&&a[x+1][y]==a[i][j]) a[x+1][y]+=a[i][j],a[i][j]=0;
                        else if(x!=i) a[x][y]=a[i][j],a[i][j]=0;
                    }
                break;
            case 'd':
                for(int j=2;j>=0;j--)
                    for(int i=0;i<4;i++)
                    {
                        int x=i,y=j;
                        while(a[i][j]&&y<=2&&!a[x][y+1])
                            y++;
                        if(y<=2&&a[x][y+1]==a[i][j]) a[x][y+1]+=a[i][j],a[i][j]=0;
                        else if(y!=j) a[x][y]=a[i][j],a[i][j]=0;
                    }
                break;
        }
        _rand();
    }
    if(flag==1) MessageBox(NULL,"��AK��IOI��","",MB_OK);
    else MessageBox(NULL,"�����ˣ�","",MB_OK);
}
void Init()
{
    flag=0;
    memset(a,0,sizeof(a));
    int x,y;
    do x=rand()%4,y=rand()%4;
    while(a[x][y]);
    a[x][y]=1;
    do x=rand()%4,y=rand()%4;
    while(a[x][y]);
    a[x][y]=1;
}
int main()
{
    system("color f0");
    CONSOLE_CURSOR_INFO cursor_info={1,0}; 
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
    srand((unsigned)time(NULL));
    system("mode con cols=22 lines=12");
    pt("_____________________");
    pt(" |     *******   |  ");
    pt(" |    ***  ***   |  ");
    pt(" |    ***   **   |  ");
    pt(" |     ****      |  ");
    pt(" |        ****   |  ");
    pt(" |    **    **   |  ");
    pt(" |    ***   **   |  ");
    pt(" |    *******    |  ");
    pt("----$$$��������$$$----");
    pt("----------------------");
    Sleep(5000);
    system("cls");
    system("mode con cols=16 lines=4");
    ST:Init();
    play();
    goto ST;
    return 0;
}
/*
��ɫ����SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),ǰ��ɫ | ����ɫ | ǰ����ǿ | ������ǿ);
    ǰ��ɫ������0-15 �� FOREGROUND_XXX ��ʾ  ������XXX����BLUE��RED��GREEN��ʾ�� 
    ǰ����ǿ������8 �� FOREGROUND_INTENSITY ��ʾ
    ����ɫ������16 32 64 �� BACKGROUND_XXX ������ɫ��ʾ 
    ������ǿ�� ����128 �� BACKGROUND_INTENSITY ��ʾ
��ҪӦ�ã��ı�ָ�����������뱳������ɫ
ǰ����ɫ��Ӧֵ�� 
����0=��ɫ                8=��ɫ����
  ��1=��ɫ                9=����ɫ        ʮ������        ����                        
����2=��ɫ                10=����ɫ       0xa        ����
����3=����ɫ              11=��ǳ��ɫ     0xb��
����4=��ɫ                12=����ɫ       0xc����
����5=��ɫ                13=����ɫ       0xd        ����
����6=��ɫ                14=����ɫ       0xe        ����
����7=��ɫ                15=����ɫ       0xf 
����Ҳ���԰���Щֵ���óɳ�����
*/
