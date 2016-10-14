#ifndef INFO_H
#define INFO_H
#include<bits/stdc++.h>
using namespace std;

class info
{
private:
    string email,password,name,address,religion,interested_in,languages;
    char temp[100];
    string mbl_no,curr_city,sex,relation_status,work,education,d_o_b,about;
public:
    void set_info(char str[]);
    void update_name(string str);
    void update_address(string str);
    void update_religion(string str);
    void update_interested_in(string str);
    void update_languages(string str);
    void update_mbl_no(string str);
    void update_curr_city(string str);
    void update_password(string str);
    void update_relation_status(string str);
    void update_work(string str);
    void update_education(string str);
    void update_d_o_b(string str);
    void update_about(string str);
    void show_info();
    string get_name();
    string get_email();
    ~info();
};

#endif // INFO_H
