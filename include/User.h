#include<iostream>
#include<string>
using namespace std;

class User{//使用者
    protected:
        string account;
        string password;
        string adress;//地址
    public:
        User(string,string);
        void set_account(string);
        void set_password(string);
        void set_adress(string);
        string get_account();
        string get_password();
        string get_adress();

        void send_mail();//寄信
        void mail_check();//查詢郵件紀錄
        void change_password();//更改密碼
};