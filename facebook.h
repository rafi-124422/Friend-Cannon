#ifndef FACEBOOK_H
#define FACEBOOK_H
#include "info.h"
#include "people.h"
#include<bits/stdc++.h>
using namespace std;
class facebook
{
private:
    vector<people>P;
    vector<string>all_email,all_password;
    string email,password,name,d_o_b,sex;
    int tot_id;
    COORD coord= {0,0};
public:
    facebook();
    void login();
    int login_check(string email, string password);
    void signup();
    bool email_check(string);
    void show();
    int id_index(string email);
    void news_feed(string email);
    void followers(int id);
    void people_may_follow(int id);
    void people_follow(int id);
    void home_page(int id);
    void gotoXY(int x,int y);
    void search_people(int);
    string write_pass(string);
    string write_pass1(string,string);
    ~facebook();
};
#endif // FACEBOOK_H
