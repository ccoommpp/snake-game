#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

void movements(string (&a)[10][20], char &direction, bool &loss_check, int &x, int &y,int &fruit_count)
{
    if (a[x][y] == "H") 
    {  
        a[x][y] = " ";  
    }
    else if (a[x][y] == "*")
    {
        loss_check = true;
        return;
    }

    if (direction == 'w')
    {
        x--;
    }
    else if (direction == 's')
    {
        x++;
    }
    else if (direction == 'a')
    {
        y--;
    }
    else if (direction == 'd')
    {
        y++;
    }

    if (a[x][y] == "*")
    {
        loss_check = true;
        return;
    }
    else if(a[x][y]=="0")
    {
        fruit_count++;
    }
    a[x][y] = "H";
}

char input(char currentDirection) 
{
    char direction = currentDirection; 

    int timeLimit = 1000; 
    int step = 50;     
    int elapsedTime = 0;

    while (elapsedTime < timeLimit)
    {
        if (_kbhit())  
        {  
            char newDirection = _getch();  
            
         
            if (newDirection == 'w' || newDirection == 'a' || newDirection == 's' || newDirection == 'd') 
            {
                
                if (!((direction == 'w' && newDirection == 's') || 
                      (direction == 's' && newDirection == 'w') ||
                      (direction == 'a' && newDirection == 'd') ||
                      (direction == 'd' && newDirection == 'a')))
                {
                    return newDirection; 
                }
            }
        }
        Sleep(step);
        elapsedTime += step;
    }

    return direction; 
}


void fruits(string (&a)[10][20], int &fruit_count)
{
    int x = rand() % 7 + 1;
    int y = rand() % 17 + 1; 

    if (fruit_count == 0)
    {
        a[x][y] = "0";
        fruit_count--;
    }
}

void print(string (&a)[10][20]) {
    system("cls");
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
        for (int j = 1; j < 19; j++)
        {
            a[i][j] = " ";
        }     
        a[i][19] = "*";
    }
    for (int i = 0; i < 20; i++)
    {
        a[9][i] = "*";
    }

    int x = 5;
    int y = 10;
    a[x][y] = "H";
    char dirt;

while (!loss_check)
{
    fruits(a,fruit_count);
    print(a);
    Sleep(200); 
    dirt = input(dirt);  
    movements(a, dirt, loss_check, x, y,fruit_count);  

}
}


