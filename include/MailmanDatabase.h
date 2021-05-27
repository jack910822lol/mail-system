#pragma once
#include<vector>
#include<string>
#include"Mailman.h"

class MailmanDatabase{
    private:
        std::vector<Mailman> database;
    public:
        void read_out_mailman_data();
        void write_in_mailman_data();
        bool check_password(int, std::string);
        int search_by_account(std::string);//存在則回傳位置,不存在回傳-1
        Mailman get_mailman(int index);
        void data_clear();
};