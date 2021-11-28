#include <bits/stdc++.h>
#include<conio.h>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>
#include<windows.h>
using namespace std;

void ScreenSize(int x, int y){

    COORD coord;
    coord.X = x;
    coord.Y = y;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = x - 1;
    Rect.Right = y - 1;

    // Adjust buffer size:
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!SetConsoleScreenBufferSize(handle, coord))
        throw std::runtime_error("Unable to resize screen buffer.");

    // display as a maximized window
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}



int main()
{
    srand(time(0));
    ScreenSize(1200,1200);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int sz=4;
    string shapes[sz];
    for(int i=0;i<sz;i++)
        shapes[i]=char(i+'0')+".txt";
    deque<string> lines,all;
    for(int i=0;i<=57;i++)
        lines.push_back(""),all.push_back("");
    ifstream file;
    int sp,idx;
    int wait = 1;
    while(1)
    {
        int clr=rand()%15+1;
        SetConsoleTextAttribute(hConsole, clr);
        sp = rand()%70;
        idx=rand()%sz;
        string opn,spc;
        while(sp--)
            spc.push_back(' ');
        opn.push_back(idx+'0');
        opn+=".A3333";
        file.open(opn.c_str());
        string s;
        while(getline(file,s))
            lines.push_back(s);
        file.close();
        while(lines.size())
        {
        //    cout<<wait<<"\n";
            lines.pop_front();
            for(int i=0;i<min(55,int(lines.size()));i++)
                cout<<spc<<lines[i]<<"\n";
            if(kbhit())
            {
                char c=getch();
                if((c=='w' || c=='W') && wait>1)
                    wait/=2;
                else if((c=='s' || c=='S') && wait*2 <= 2000)
                    wait*=2;
                else if(c=='s' || c=='S')
                    getch();

            }
            Sleep(wait);
            system("cls");
        }
        lines=all;
    }

    return 0;
}
