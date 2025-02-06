#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

void movements(string (&a)[10][20],char &direction,bool &loss_check,int &x,int &y)
{
    if (a[x][y]=="H") 
    {  
    a[x][y] =" ";  // Replace 'H' with a space
    }
    else if(a[x][y]=="*")
    {
        loss_check=true;
        return;
    }
    if(direction=='w')
    {
        x--;
    }
    else if(direction=='s')
    {
        x++;
    }
    else if(direction=='a')
    {
        y--;
    }
    else if(direction=='d')
    {
        y++;
    }

    if(a[x][y]=="*")
    {
        loss_check=true;
        return;
    }
    a[x][y]="H";
}

char input() 
{
    char direction;
    int timeLimit = 1000; 
    int step = 100;      
    int elapsedTime = 0;
    cout<<"\n enter now \n";
    while (elapsedTime < timeLimit) 
    {
        if (_kbhit()) 
        {  
            direction = _getch(); 
            if (direction == 'w' || direction == 'a' || direction == 's' || direction == 'd') 
            {
                return direction; 
            }
        }
        Sleep(step);
        elapsedTime += step;
    }
    return direction; 
}
void fruits(string (&a)[10][20], int &fruit_count)
{
    int x = rand() % 7+1;
    int y = rand() % 17+1; 

    if (fruit_count == 0)
    {
        a[x][y] = "0";
        fruit_count++;
    }
}

void print(string (&a)[10][20]) {
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int main() 
{
    srand(time(0));
    int fruit_count = 0;
    string a[10][20]{};
    bool loss_check = false;
    for (int i = 0; i < 20; i++)
    {
        a[0][i] = "*";
    }
    for (int i = 1; i < 9; i++)
    {
        a[i][0] = "*";
        for(int j=1;j<19;j++)
        {
            a[i][j]=" ";
        }     
        a[i][19]="*";
    }
    for (int i = 0; i < 20; i++)
    {
        a[9][i] = "*";
    }
    int x=5;
    int y=10;
    a[x][y]="H";
    while(!loss_check)
    {
        /*fruits(a, fruit_count);*/
        print(a);
        Sleep(2000);
        char direction=input();
        Sleep(2000);
        movements(a,direction,loss_check,x,y);
    }
}

