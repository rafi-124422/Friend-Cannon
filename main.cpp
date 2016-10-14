#include<bits/stdc++.h>
#include "info.h"
#include "people.h"
#include "facebook.h"
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<conio.h>
#include<time.h>

using namespace std;

void loading();
COORD coord= {0,0};
void gotoXY(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
    srand(time(NULL));
    facebook f;
    string i;
    loading();
    while(1)
    {
        cout<<"1. Log In\n2. Sign Up\n0. Exit\n"<<endl;
        cout<<"enter your choice : ";
        getline(cin,i);
        if(i=="1")
        {
            system("cls");
            f.login();
        }
        if(i=="2")
        {
            system("cls");
            f.signup();
        }
        if(i=="0")
        {
            break;
        }
         system("cls");
    }
    return 0;
}

void loading()
{
    gotoXY(15,10);
    cout<<"F";
    Sleep(400);
    cout<<"R";
    Sleep(400);
    cout<<"I";
    Sleep(400);
    cout<<"E";
    Sleep(400);
    cout<<"N";
    Sleep(400);
    cout<<"D";
    Sleep(400);
    cout<<" ";
    Sleep(400);
    cout<<"C";
    Sleep(400);
    cout<<"A";
    Sleep(400);
    cout<<"N";
    Sleep(400);
    cout<<"N";
    Sleep(400);
    cout<<"O";
    Sleep(400);
    cout<<"N";
    Sleep(3000);
    system("cls");

}
