#include "info.h"
#include<bits/stdc++.h>
using namespace std;
void info:: update_name(string str)
{
    for(int a=0;a<str.size();a++)
    {
        str[a]=toupper(str[a]);
    }
    name.clear();
    name.assign(str);
}
void info:: update_address(string str)
{
    address.clear();
    address.assign(str);

}
void info:: update_religion(string str)
{
   religion.clear();
   religion.assign(str);
}
void info:: update_interested_in(string str)
{
    interested_in.clear();
    interested_in.assign(str);
}
void info:: update_languages(string str)
{
    languages.clear();
    languages.assign(str);
}
void info:: update_mbl_no(string str)
{
    mbl_no.clear();
    mbl_no.assign(str);
}
void info:: update_curr_city(string str)
{
    curr_city.clear();
    curr_city.assign(str);
}
void info:: update_password(string str)
{
    password.clear();
    password.assign(str);

}
void info:: update_relation_status(string str)
{
    relation_status.clear();
    relation_status.assign(str);
}
void info:: update_work(string str)
{
    work.clear();
    work.assign(str);

}
void info:: update_education(string str)
{
    education.clear();
    education.assign(str);
}
void info:: update_d_o_b(string str)
{
    d_o_b.clear();
    d_o_b.assign(str);
}
void info:: update_about(string str)
{
    about.clear();
    about.assign(str);
}
void info :: set_info(char str[])
{
    string s;
    strcpy(temp,str);
    ifstream f(str);
    getline(f,s);
    email.assign(s);
    getline(f,s);
    password.assign(s);
    getline(f,s);
    name.assign(s);
    getline(f,s);
    sex.assign(s);
    getline(f,s);
    d_o_b.assign(s);
    getline(f,s);
    religion.assign(s);
    getline(f,s);
    education.assign(s);
    getline(f,s);
    work.assign(s);
    getline(f,s);
    curr_city.assign(s);
    getline(f,s);
    address.assign(s);
    getline(f,s);
    relation_status.assign(s);
    getline(f,s);
    interested_in.assign(s);
    getline(f,s);
    languages.assign(s);
    getline(f,s);
    mbl_no.assign(s);
    getline(f,s);
    about.assign(s);
    f.close();
}

void info::show_info()
{
    cout<<"profile view         "<<endl<<endl;
    cout<<"name                : "<<name<<endl;
    cout<<"religion            : "<<religion<<endl;
    cout<<"sex                 : "<<sex<<endl;
    cout<<"current city        : "<<curr_city<<endl;
    cout<<"mobile number       : "<<mbl_no<<endl;
    cout<<"languages           : "<<languages<<endl;
    cout<<"interested in       : "<<interested_in<<endl;
    cout<<"relationship status : "<<relation_status<<endl;
    cout<<"date of birth       : "<<d_o_b<<endl;
    cout<<"education           : "<<education<<endl;
    cout<<"work                : "<<work<<endl;
    cout<<"address             : "<<address<<endl;
    cout<<"email               : "<<email<<endl;
    cout<<"about               : "<<about<<endl<<endl<<endl;

    system("pause");
}

string info :: get_name()
{
    return name;
}string info :: get_email()
{
    return email;
}
info :: ~info()
{
    string s;
    char str[100];
    strcpy(str,temp);
    ofstream f(str);
    f<<temp<<endl;
    f<<password<<endl;
    f<<name<<endl;
    f<<sex<<endl;
    f<<d_o_b<<endl;
    f<<religion<<endl;
    f<<education<<endl;
    f<<work<<endl;
    f<<curr_city<<endl;
    f<<address<<endl;
    f<<relation_status<<endl;
    f<<interested_in<<endl;
    f<<languages<<endl;
    f<<mbl_no<<endl;
    f<<about<<endl;
    f.close();
}
