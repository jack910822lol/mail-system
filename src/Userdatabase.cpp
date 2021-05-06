#pragma once
#include"UserDatabase.h"
#include<fstream>
#include<windows.h>
#include<iostream>
using namespace std;

void UserDatabase::read_in_user_data()//讀入使用者資料(user_data.txt)
{
    std::ifstream file;
    file.open("user_data.txt");
    std::string temp;
    if(!file){
        cout << "Plz Retry." << endl;
        Sleep(3/2*1000);
        return;
    }
    else 
    {
        file>>temp;
    }
}

void UserDatabase::create_new_user(){//創建新使用者，創建完成接登入。
    string account, password, adress;
    cin >> account >> password>>adress;//檢查。密碼限定7字以上。帳號重複則不予創立。(未完成都是新界在偷懶)
    User new_user(account, password, adress);
    user_database.push_back(new_user);
}

int UserDatabase::search_by_account(string account)
{

}