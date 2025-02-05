#include <iostream>
#include <cstdlib> 
#include <ctime>
#include<windows.h>
using namespace std;
void print_layout(string (&a)[50][50])
{
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cout << (a[i][j]);
        }
        cout << endl;
    }
}
int random_x(int m)
{
    int x=(rand() %m)+1;
    return x;
}

int random_y(int m)
{
    int y=(rand() %m)+1;
    return y;
}

int main()
{
    srand(time(0));
    int loss_check=1;
    do
    {
    string a[50][50]{}; 

    for (int i = 0; i < 50; i++)
    {
        a[0][i] = "*";
    }


    for (int i = 1; i < 49; i++)
    {
        a[i][0] = "*";
        for(int j=1;j<49;j++)
        {
            a[i][j]=" ";
        }     
        a[i][49]="*";
    }

    for (int i = 0; i < 50; i++)
    {
        a[49][i] = "*";
    }
    int point_x=random_x(48);
    int point_y=random_y(48);
    a[point_x][point_y]="0";
    Sleep(2000);
    print_layout(a);
    loss_check++;
    }while(loss_check!=10);
    return 0;
}