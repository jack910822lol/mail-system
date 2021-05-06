#pragma once
#include<vector>
#include"User.h"

class UserDatabase{//使用者資料庫
    private:
        std::vector<User> user_database;
    public:
        void read_in_user_data();
        void create_new_user();
        int search_by_account(std::string);
        friend void login();
        friend class Mailman;
};