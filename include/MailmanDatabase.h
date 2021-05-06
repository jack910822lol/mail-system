#pragma once
#include<vector>
#include<string>
#include"Mailman.h"

class MailmanDatabase{
    private:
        std::vector<Mailman> database;
    public:
        void read_in_mailman_data();
        int search_by_account(std::string);
};