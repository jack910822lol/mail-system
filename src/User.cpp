#include<iostream>
#include<string>
#include"User.h"
using namespace std;

User::User(std::string a, std::string b){
    account=a;
    password=b;
}

void User::set_account(std::string a){
    account=a;
};

void User::set_password(std::string a){
    password=a;
};

void User::set_adress(std::string a){
    adress=a;
};

std::string User::get_account(){
    return account;
};

std::string User::get_password(){
    return password;
};

std::string User::get_adress(){
    return adress;
}

void User::send_mail(){//寄信
}
void User::mail_check(){//查詢郵件紀錄
}
void User::change_password(){//更改密碼
}