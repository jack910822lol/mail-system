#include<iostream>
#include<string>
#include"User.h"
using namespace std;

User::User(std::string a, std::string b, std::string c){
    account=a;
    password=b;
    adress=c;
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