#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

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

int main() {
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

    while(!loss_check)
    {
        fruits(a, fruit_count);
        print(a);
        Sleep(2000);
        system("cls");
    }
}

