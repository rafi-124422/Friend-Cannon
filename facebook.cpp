#include "facebook.h"
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
facebook::facebook()
{
    int i,j,k;
    char str[500],ch[100],str1[100];
    tot_id=0;
    ifstream f("tot_ppl.dll");
    while(!f.eof())
    {
        f>>str;
        if(str=="")break;
        all_email.push_back(str);
        f>>str1;
        all_password.push_back(str1);
        people p(str);
        P.push_back(p);
        tot_id++;
    }
    f.close();
}
void facebook ::  gotoXY(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void facebook :: signup()
{
    char str[100],s[100];
    string name,email,d_o_b,password;
    cout<<"enter email         : ";
    cin>>str;
    for(int a=0; a<strlen(str); a++)
    {
        str[a]=tolower(str[a]);
    }
    email.assign(str);
    if(email_check(email))
    {
        cout<<"this email is already used , try new one"<<endl;
        system("cls");
        signup();
    }
    all_email.push_back(email);
    getchar();
    cout<<"enter name          : ";
    getline(cin,name);
    for(int a=0; a<name.size(); a++)
    {
        name[a]=toupper(name[a]);
    }
    cout<<"enter password      : ";
    password=write_pass1(email,name);
    all_password.push_back(password);
    cout<<"\nenter sex           : ";
    getline(cin,sex);
    cout<<"enter date of birth : ";
    getline(cin,d_o_b);
    while(1)
    {
        system("cls");
        cout<<"enter email         : "<<email<<endl;
        cout<<"enter name          : "<<name<<endl;
        cout<<"enter password      : ";
        for(int b=0;b<password.size();b++)
        {
            cout<<"*";
        }
        cout<<"\nenter sex           : "<<sex<<endl;
        cout<<"enter date of birth : "<<d_o_b<<endl;
        string q;
        cout<<"\n\npress 1 to Sign Up or zero(0) to go back : ";
        getline(cin,q);
        if(q=="1")
        {
            strcpy(s,str);
            ofstream f(str);
            f<<email<<endl;
            f<<password<<endl;
            f<<name<<endl;
            f<<sex<<endl;
            f<<d_o_b<<endl;
            f.close();
            ofstream x("tot_ppl.dll",ios::app);
            x<<endl<<s;
            x<<endl<<password;
            x.close();
            strcpy(str,s);
            strcat(str,"-followers");
            ofstream F(str);
            F.close();
            strcpy(str,s);
            strcat(str,"-follow");
            ofstream FP(str);
            FP.close();
            strcpy(str,s);
            strcat(str,"-status");
            ofstream FP1(str);
            FP1.close();
            people p(s);
            P.push_back(p);
            tot_id++;
            cout<<"\n\nyou have signed up successfully .. "<<endl<<endl;
            system("pause");
            break;
        }
        if(q=="0")
        {
            break;
        }
    }

}
bool facebook :: email_check(string email)
{
    int i;
    for(i=0; i<tot_id; i++)
    {
        if(email==all_email[i])return true;
    }
    return false;
}
void facebook :: login()
{
    int i;
    cout<<"enter email    : ";
    cin>>email;
    for(int a=0;a<email.size();a++)
    {
        email[a]=tolower(email[a]);
    }
    cout<<"enter password : ";
    password=write_pass(email);
    i=login_check(email,password);
    if(i)
    {
        system("cls");
        news_feed(email);
    }
    else
    {
        cout<<"\n\nwrong username password"<<endl;
        system("pause");
    }
}
int facebook :: login_check(string email, string password)
{
    int i;
    for(i=0; i<tot_id; i++)
    {
        if(email==all_email[i]&&password==all_password[i])return 1;
    }
    return 0;
}
void facebook::show()
{
    int i;
    for(i=0; i<tot_id; i++)
    {
        cout<<all_email[i]<<endl;
    }
}
int facebook::id_index(string email)
{
    int i;
    for(i=0; i<tot_id; i++)
    {
        if(email==all_email[i])return i;
    }
}
void facebook::news_feed(string email)
{
    int id;
    string choice;
    id=id_index(email);
    while(1)
    {
        cout<<"1. Show Profile\n2. Update Info\n3. People You Follow\n4. Followers\n5. People You May Follow\n6. Search People\n0. Log Out";
        cout<<"\n\nEnter choice : ";
        home_page(id);
        gotoXY(15,8);
        getline(cin,choice);
        system("cls");
        if(choice=="1")
        {
            P[id].view();
        }
        if(choice=="2")
        {
            P[id].settings();
        }
        if(choice=="3")
        {
            people_follow(id);
        }
        if(choice=="4")
        {
            followers(id);
        }
        if(choice=="5")
        {
            people_may_follow(id);
        }
        if(choice=="6")
        {
            search_people(id);
        }
        if(choice=="0")
        {
            break;
        }
        system("cls");
    }
}

void facebook :: home_page(int id)
{
    int i=0,a,b,c=0,r,x,y,j;
    a=P[id].get_num_of_people_follow();
    string str,name,status;
    gotoXY(25,10);
    cout<<"NEWS FEED"<<endl<<endl;
    c=a-1;
    while(i<a)
    {
        if(c<0)break;
        str.assign(P[id].get_follow(c));
        j=id_index(str);
        name = P[j].get_name();
        status = P[j].get_status();
        if(status=="NULL")
        {
            c--;
            i++;
        }
        else
        {
            cout<<name<<endl;
            cout<<"::: "<<status<<endl<<endl;
            c--;
            i++;
        }
    }
}

void facebook :: people_follow(int id)
{
    int i,f,j,c,x,ar[100000],y=0,p;
    string str,name;
    while(1)
    {
        y=1;
        f=P[id].get_num_of_people_follow();
        p=1;
        for(i=0; i<f; i++)
        {
            str.assign(P[id].get_follow(i));
            j=id_index(str);
            name = P[j].get_name();
            cout<<p<<". "<<name<<endl;
            ar[y]=j;
            y++;
            p++;
        }
        cout<<endl<<"enter account number to visit profile or zero(0) to back : ";
        cin>>c;
        if(c==0)
        {
            break;
        }
        if(c>i||c<0)
        {
            system("cls");
            continue;
        }
        x=P[ar[c]].follow_view();
        if(x==1)
        {
            int m,n,o;
            string s,e;
            n=P[ar[c]].get_num_of_followers();
            for(o=0; o<n; o++)
            {
                s.assign(P[ar[c]].get_followers(o));
                e = P[id].get_email();
                if(s==e)break;
            }
            P[id].update_follow(c-1);
            P[ar[c]].update_flwers(o);
        }
        system("cls");
    }

}

void facebook :: people_may_follow(int id)
{
    int i,b,j,k,ar[10000],c,f,x,p[50000];
    bool t;
    srand(time(NULL));
    string em,name;
    for(c=0; c<tot_id; c++)
    {
        k=rand()%(tot_id);
        ar[c]=k;
    }
    while(1)
    {
        b=1;
        for(j=0; j<tot_id; j++)
        {
            f=0;
            k=ar[j];
            if(k==id)continue;
            for(int a=0; a<tot_id; a++)
            {
                if(k==ar[a]&&a!=j)
                {
                    f=1;
                    break;
                }
            }
            if(f==1)continue;
            em=P[k].get_email();
            t=P[id].check_follow(em);
            if(t==true)continue;
            name = P[k].get_name();
            if(name=="")continue;
            p[b]=k;
            cout<<b<<". "<<name<<endl;
            b++;
        }
        cout<<endl<<"enter account number to visit profile or zero(0) to back : ";
        cin>>c;
        if(c==0)
        {
            break;
        }
        if(c>=b||c<0)
        {
            system("cls");
            continue;
        }
        x=P[p[c]].followers_view();
        if(x==1)
        {
            string st;
            bool t;
            system("cls");
            st.assign(P[p[c]].get_email());
            t=P[id].check_follow(st);
            if(t==true)
            {
                cout<<"you already follow this person....!"<<endl<<endl;
            }
            else
            {
                P[p[c]].update_flw(P[id].get_email());
                P[id].update_followers(st);
                cout<<"successfully followed...!"<<endl<<endl;
            }
            system("pause");

        }
        system("cls");
    }
    system("cls");
}
void facebook :: followers(int id)
{
    int i,f,j,c,x,ar[100000],y=0;
    string str,name;
    while(1)
    {
        y=1;
        f=P[id].get_num_of_followers();
        for(i=0; i<f; i++)
        {
            str.assign(P[id].get_followers(i));
            j=id_index(str);
            name = P[j].get_name();
            cout<<i+1<<". "<<name<<endl;
            ar[y]=j;
            y++;
        }
        cout<<endl<<"enter account number to visit profile or zero(0) to back : ";
        cin>>c;
        if(c==0)
        {
            break;
        }
        if(c>i)
        {
            system("cls");
            continue;
        }
        x=P[ar[c]].followers_view();
        if(x==1)
        {
            string st;
            bool t;
            system("cls");
            st.assign(P[ar[c]].get_email());
            t=P[id].check_follow(st);
            if(t==true)
            {
                cout<<"you already follow this person....!"<<endl<<endl;
            }
            else
            {
                P[ar[c]].update_flw(P[id].get_email());
                P[id].update_followers(st);
                cout<<"successfully followed...!"<<endl<<endl;
            }
            system("pause");

        }
        system("cls");
    }

}
void facebook :: search_people(int id)
{
    string em,name;
    int x,c,i,f=0;
    cout<<"enter email to search people : ";
    getline(cin,em);
    for(i=0; i<tot_id; i++)
    {
        if(all_email[i]==em)
        {
            f=1;
            name = P[i].get_name();
            system("cls");
            while(1)
            {
                cout<<"1. "<<name<<endl<<endl;
                cout<<"found !! press 1 to visit profile or zero(0) to back : ";
                cin>>c;
                if(c==1)
                {
                    x=P[i].followers_view();
                    if(x==1)
                    {
                        string st;
                        bool t;
                        system("cls");
                        st.assign(all_email[i]);
                        t=P[id].check_follow(st);
                        if(t==true)
                        {
                            cout<<"you already follow this person....!"<<endl<<endl;
                        }
                        else
                        {
                            P[i].update_flw(P[id].get_email());
                            P[id].update_followers(st);
                            cout<<"successfully followed...!"<<endl<<endl;
                        }
                        system("pause");

                    }
                }
                if(c==0)
                {
                    break;
                }
                system("cls");
            }
        }
    }
    if(f==0)
        cout<<"Not Found !! "<<endl;

    system("pause");
}
facebook :: ~facebook()
{
    int i;
    for(i=0; i<tot_id; i++)
    {
        P[i].load();
    }
}
string facebook :: write_pass(string email)
{
    string str,str1;
    char c;
    int i=0;
    while(1)
    {

        c=getch();
        if(c==13)break;
        system("cls");
        cout<<"enter email    : "<<email<<endl;
        cout<<"enter password : ";
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
string facebook :: write_pass1(string email,string name)
{
    string str,str1;
    char c;
    int i=0;
    while(1)
    {

        c=getch();
        if(c==13)break;
        system("cls");
        cout<<"enter email         : "<<email<<endl;
        cout<<"enter name          : "<<name<<endl;
        cout<<"enter password      : ";

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
