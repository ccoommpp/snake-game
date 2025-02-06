#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

void movements(string (&a)[10][20], char &direction, bool &loss_check, deque<pair<int, int>> &snake, int &fruit_count)
{
    int x = snake.front().first;
    int y = snake.front().second;
    
    
    pair<int, int> tail = snake.back();
    a[tail.first][tail.second] = " ";

    if (direction == 'w') x--;
    else if (direction == 's') x++;
    else if (direction == 'a') y--;
    else if (direction == 'd') y++;

    
    if (a[x][y] == "*" || a[x][y] == "H") 
    {
        loss_check = true;
        return;
    }

    
    if (a[x][y] == "0") 
    {
        fruit_count--;
    } 
    else 
    {
        snake.pop_back();
    }

    
    snake.push_front({x, y});
    a[x][y] = "H";
}

char input(char currentDirection) 
{
    char direction = currentDirection; 
    int timeLimit = 500; 
    int step = 100;     
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
    if (fruit_count == 0) 
    {
        int x, y;
        do {
            x = rand() % 8 + 1;
            y = rand() % 18 + 1;
        } while (a[x][y] != " "); 

        a[x][y] = "0";
        fruit_count++;
    }
}

void print(string (&a)[10][20]) 
{
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
    
    
    for (int i = 0; i < 20; i++) a[0][i] = "*";
    for (int i = 1; i < 9; i++)
    {
        a[i][0] = "*";
        for (int j = 1; j < 19; j++) a[i][j] = " ";
        a[i][19] = "*";
    }
    for (int i = 0; i < 20; i++) a[9][i] = "*";

    
    deque<pair<int, int>> snake;
    snake.push_back({5, 10});
    a[5][10] = "H";

    char direction; 

    while (!loss_check)
    {
        fruits(a, fruit_count);
        print(a);
        Sleep(200);
        direction = input(direction);
        movements(a, direction, loss_check, snake, fruit_count);
    }

    cout << "Game Over!" << endl;
}



