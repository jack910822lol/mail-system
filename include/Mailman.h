#pragma once
#include<string>

class Mailman{//郵差
    private: 
        std::string account;
        std::string password;
    public:
        void set_account(std::string);
        void set_password(std::string);
        std::string get_account();
        std::string get_password();
};
