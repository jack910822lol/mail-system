#pragma once
#include<vector>
#include"User.h"

class UserDatabase{//使用者資料庫
    private:
        std::vector<User> database;
    public:
        UserDatabase();
        void read_out_user_data();
        void write_in_user_data();
        void create_new_user(std::string);
        int search_by_account(std::string);//存在則回傳位置,不存在回傳-1
        bool check_password(int, std::string);//
        User get_user(int);
        void set_user(int, User);
        void clear_data();
};