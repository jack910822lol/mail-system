#pragma once
#include<iostream>
#include<vector>
#include"Mail.h"
#include"UserDatabase.h"
class MailDatabase{//郵件資料庫
    private:
        std::vector<Mail> database;
    public:
        MailDatabase();
        void set_new_mail(std::string, std::string, UserDatabase);//cpp檔ok
        void read_out_mail_data();
        void write_in_mail_data();
        void search_mail_by_account(std::string);
        void search_mail_by_id(std::string);
        void push_mail_to_database(Mail);
        void reciver_change_mail_status(std::string);
        void mailman_change_mail_status(std::string);
        int get_mail_index_by_id(std::string);
        void data_clear();
};