#include<iostream>
#include<vector>
#include"Mail.h"
using namespace std;

class MailDatabase{//郵件資料庫
    private:
        std::vector<Mail> mail_database;
    public:
        MailDatabase();
        void read_in_mail_data();
        friend class Mailman;
};