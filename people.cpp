#include "people.h"
#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
using namespace std;

void people ::  gotoXY(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
people::people(char st[])
{
    strcpy(temp,st);
    char c[100];
    strcpy(c,st);
    in.set_info(c);
    num_of_followers=0;
    num_of_follow=0;
    num_of_status=0;
    char str[500];
    string str1;
    strcpy(str,st);
    strcat(str,"-followers");
    ifstream f(str);
    while(1)
    {
        getline(f,str1);
        if(str1=="")break;
        email_followers.push_back(str1);
        num_of_followers++;
    }
    f.close();
    strcpy(str,st);
    strcat(str,"-follow");
    ifstream fp(str);
    while(1)
    {
        getline(fp,str1);
        if(str1=="")break;
        email_follow.push_back(str1);
        num_of_follow++;
    }
    fp.close();
    strcpy(str,st);
    strcat(str,"-status");
    ifstream fp1(str);
    while(1)
    {
        getline(fp1,str1);
        if(str1=="")break;
        status.push_back(str1);
        num_of_status++;
    }
    fp1.close();
}

string people :: people_follow(int i)
{
    return email_follow[i];
}
string  people :: followers(int i)
{
    return email_followers[i];
}
int people :: get_num_of_people_follow()
{
    return num_of_follow;
}
int people:: get_num_of_followers()
{
    return num_of_followers;
}
void people :: show_status()
{
    int r;
    for(int i=num_of_status-1; i>=0; i--)
    {
        cout<<"::: ";
        cout<<status[i]<<endl<<endl;
    }
}

void people :: post_status()
{
    string str;
    int c;
    cout<<"Whats on your mind ???(press ENTER to post)"<<endl;
    getline(cin,str);
    while(1)
    {
        system("cls");
        cout<<"Whats on your mind ???(press ENTER to post)"<<endl<<str;
        cout<<"\n\npress 1 to post or zero(0) to go back : ";
        cin>>c;
        if(c==1)
        {
            status.push_back(str);
            num_of_status++;
            cout<<"\n\nPosted\n\n";
            system("pause");
            break;
        }
        if(c==0)
        {
            break;
        }
    }
}
string people :: get_status()
{
    if(num_of_status==0)return "NULL";
    return status[num_of_status-1];
}
void people :: load()
{
    char str[100];
    strcpy(str,temp);
    strcat(str,"-status");
    ofstream f(str);
    for(int i=0; i<num_of_status; i++)
    {
        f<<status[i]<<endl;
    }
    f.close();
    strcpy(str,temp);
    strcat(str,"-follow");
    ofstream fp(str);
    for(int i=0; i<num_of_follow; i++)
    {
        fp<<email_follow[i]<<endl;
    }
    fp.close();
    strcpy(str,temp);
    strcat(str,"-followers");
    ofstream fp1(str);
    for(int i=0; i<num_of_followers; i++)
    {
        fp1<<email_followers[i]<<endl;
    }
    fp1.close();
}

string people :: get_follow(int r)
{
    string str;
    str.assign("NULL");
    if(email_follow[r]=="")return str;
    return email_follow[r];
}
string people :: get_followers(int r)
{
    string str;
    str.assign("NULL");
    if(email_followers[r]=="")return str;
    return email_followers[r];
}
string people :: get_name()
{
    return in.get_name();
}
string people :: get_email()
{
    return in.get_email();
}
void people :: view()
{
    string i;
    while(1)
    {
        cout<<"1. Post Status\n2. View Info\n0. Back\n"<<endl;
        cout<<"Enter your choice : ";
        gotoXY(0,6);
        cout<<get_name()<<endl;
        gotoXY(40,7);
        cout<<"WALL"<<endl<<endl;
        show_status();
        gotoXY(21,4);
        getline(cin,i);
        if(i=="1")
        {
            system("cls");
            post_status();
        }
        if(i=="2")
        {
            system("cls");
            in.show_info();
        }
        if(i=="0")
        {
            system("cls");
            break;
        }
        system("cls");
    }

}

int people :: follow_view()
{
    system("cls");
    string i;
    while(1)
    {
        cout<<"1. Unfollow\n2. View Info\n0. Back\n"<<endl;
        cout<<"Enter your choice : ";
        gotoXY(0,6);
        cout<<get_name()<<endl;
        gotoXY(40,7);
        cout<<"WALL"<<endl<<endl;
        show_status();
        gotoXY(21,4);
        getline(cin,i);
        if(i=="1")
        {
            system("cls");
            cout<<"successfully unfollowed"<<endl<<endl;
            system("pause");
            return 1;
        }
        if(i=="2")
        {
            system("cls");
            in.show_info();
        }
        if(i=="0")
        {
            system("cls");
            break;
        }
        system("cls");
    }
    return 0;
}
void people :: settings()
{
    string ch;
    string str;
    while(1)
    {

        cout<<"1. Name\n2. Password\n3. Address\n4. Date Of Birth\n5. Interest\n6. Languages\n7. Mobile Number\n8. Current City\n9. Religion\n10.About\n11.Work\n12.Education\n13.Relationship status\n0. Back"<<endl;
        cout<<endl<<"\nWhich Information do you want to update? ==> ";
        getline(cin,ch);
        system("cls");
        if(ch=="1")
        {
            cout<<"Enter new name : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new name : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_name(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;

                }
                if(c==0)
                {
                    break;

                }
            }

        }
        else if(ch=="2")
        {
            cout<<"Enter new password : ";
            str=write_pass();
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new password : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_password(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;
                }
                if(c==0)
                {
                    break;
                }
            }

        }
        else if(ch=="3")
        {
            cout<<"Enter new address : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new address : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_address(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;

                }
                if(c==0)
                {
                    break;
                }
            }

        }
        else if(ch=="4")
        {
            cout<<"Enter new date of birth : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new date of birth : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_d_o_b(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;
                }
                if(c==0)
                {
                    break;

                }
            }

        }
        else if(ch=="5")
        {
            cout<<"Enter new interest : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new interest : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_interested_in(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;
                }
                if(c==0)
                {
                    break;
                }
            }

        }
        else if(ch=="6")
        {
            cout<<"Enter new languages : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new languages : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_languages(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");

                    break;
                }
                if(c==0)
                {
                    break;

                }
            }
        }
        else if(ch=="7")
        {
            cout<<"Enter new mobile no : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new mobile no : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_mbl_no(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;
                }
                if(c==0)
                {
                    break;

                }
            }

        }
        else if(ch=="8")
        {
            cout<<"Enter new current city : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new current city : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {

                    in.update_curr_city(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;

                }
                if(c==0)
                {
                    break;

                }
            }

        }
        else if(ch=="9")
        {
            cout<<"Enter new religion : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new religion : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_religion(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;

                }
                if(c==0)
                {
                    break;
                }
            }

        }
        else if(ch=="10")
        {
            cout<<"Enter new about : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new about : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {

                    in.update_about(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;

                }
                if(c==0)
                {
                    break;

                }
            }

        }
        else if(ch=="11")
        {
            cout<<"Enter new work : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new work : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_work(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;

                }
                if(c==0)
                {
                    break;
                }
            }

        }
        else if(ch=="12")
        {
            cout<<"Enter new education : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new education : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_education(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;

                }
                if(c==0)
                {
                    break;
                }
            }

        }
        else if(ch=="13")
        {
            cout<<"Enter new relationship status : ";
            getline(cin,str);
            int c;
            while(1)
            {
                system("cls");
                cout<<"Enter new relationship status : "<<str<<endl;
                cout<<"\n\npress 1 to update or zero(0) to go back : ";
                cin>>c;
                if(c==1)
                {
                    in.update_relation_status(str);
                    cout<<"\n\nupdated!!!!\n"<<endl;
                    system("pause");
                    break;
                }
                if(c==0)
                {
                    break;
                }
            }

        }
        else if(ch=="0")
        {
            break;
        }
        system("cls");
    }
}
int people :: followers_view()
{
    system("cls");
    string i;
    while(1)
    {
        cout<<"1. Follow\n2. View Info\n0. Back\n"<<endl;
        cout<<"Enter your choice : ";
        gotoXY(0,6);
        cout<<get_name()<<endl;
        gotoXY(40,7);
        cout<<"WALL"<<endl<<endl;
        show_status();
        gotoXY(21,4);
        getline(cin,i);
        if(i=="1")
        {
            return 1;
        }
        if(i=="2")
        {
            system("cls");
            in.show_info();
        }
        if(i=="0")
        {
            system("cls");
            break;
        }
        system("cls");
    }
    return 0;
}

void people::update_follow(int i)
{
    email_follow.erase(email_follow.begin()+i);
    num_of_follow--;
}
void people::update_followers(string str)
{
    email_follow.push_back(str);
    num_of_follow++;
}
void people::update_flwers(int i)
{
    email_followers.erase(email_followers.begin()+i);
    num_of_followers--;
}
void people :: update_flw(string str)
{
    email_followers.push_back(str);
    num_of_followers++;
}
bool people :: check_follow(string str)
{
    int i;
    for(i=0; i<num_of_follow; i++)
    {
        if(str==email_follow[i])return true;
    }
    return false;
}

string people :: write_pass()
{
    string str,str1;
    char c;
    int i=0;
    while(1)
    {

        c=getch();
        if(c==13)break;
        system("cls");
        cout<<"Enter new password : ";
        if(c==8)
        {
            if(str.size()==0)continue;
            str1.erase(str1.begin()+i-1);
            str.erase(str.begin()+i-1);
            i--;
        }
        else
        {
            str1.push_back('*');
            str.push_back(c);
            i++;
        }
        cout<<str1;
    }
    return str;
}
