#pragma once
#include<iostream>
#include<string>

class User{//使用者
    private:
        std::string account;
        std::string password;
        std::string adress;//地址
    public:
        User(std::string, std::string, std::string);
        void set_account(std::string);
        void set_password(std::string);
        void set_adress(std::string);
        std::string get_account();
        std::string get_password();
        std::string get_adress();
};