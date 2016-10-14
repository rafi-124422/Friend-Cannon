#ifndef PEOPLE_H
#define PEOPLE_H
#include "info.h"
#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include<conio.h>
#include<time.h>
class people
{
private:
    int num_of_followers,num_of_follow,num_of_status;
    info in;
    char temp[100];
    vector<string>email_follow,email_followers;
    vector<string>status;
    COORD coord= {0,0};
public:
    people(char str[]);
    void show_pro();
    void show_status();
    void post_status();
    void load();
    string people_follow(int i);
    string followers(int i);
    int get_num_of_people_follow();
    int get_num_of_followers();
    string get_status();
    string get_follow(int);
    string get_followers(int);
    string get_name();
    void view();
    void gotoXY(int x,int y);
    int follow_view();
    void update_follow(int i);
    int followers_view();
    bool check_follow(string str);
    string get_email();
    void update_followers(string str);
    void update_flwers(int i);
    void update_flw(string str);
    void settings();
    string write_pass();
};

#endif // PEOPLE_H
