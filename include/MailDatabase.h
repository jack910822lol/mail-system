#pragma once
#include<iostream>
#include<vector>
#include"Mail.h"

class MailDatabase{//郵件資料庫
    private:
        std::vector<Mail> mail_database;
    public:
        MailDatabase();
        void set_new_mail();//cpp檔還沒建
        void read_in_mail_data();
        int search_by_id(string);
        friend class Mailman;
};