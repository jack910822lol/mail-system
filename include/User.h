#pragma once
#include<iostream>
#include<string>
using namespace std;

class User{//使用者
    protected:
        string account;
        string password;
        string adress;//地址
    public:
        User(string,string,string);
        void set_account(string);
        void set_password(string);
        void set_adress(string);
        string get_account();
        string get_password();
        string get_adress();
};