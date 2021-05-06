#pragma once
#include<vector>
#include"User.h"
using namespace std;

class UserDatabase{//使用者資料庫
    private:
        std::vector<User> user_database;
    public:
        void read_in_user_data();
        void create_new_user();
        void access_user(int);
        friend void login();
        friend class Mailman;
};