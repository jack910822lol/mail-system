#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<vector>
#include"Mail.h"
#include"MailDatabase.h"
#include"User.h"
using namespace std;



//==========================================================

/*class Mail{//郵件
    private:
        int id;//編號
        string sender;//寄件
        string recipient;//收件人
        string deliver_time;//送達時間
    public:
        Mail();
        void set_id();
        string get_id();
        void set_sender();
        string get_sender();
        void set_recipient();
        string get_recipient();
        void set_adress();
        string get_adress();
        void set_deliver_time();
        string get_deliver_time();
};*/



//==========================================================



/*class MailDatabase{//郵件資料庫
    private:
        vector<Mail> mail_database;
    public:
        MailDatabase();
        void read_in_mail_data();
        friend class Mailman;

};*/



//==========================================================



/*class User{//使用者
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
};


void User::change_password(){//登入後之選項，更改成功後回到結束程式or重登。
}

void User::mail_check(){//查詢郵件紀錄

}*/



//==========================================================



class UserDatabase{//使用者資料庫
    private:
        vector<User> user_database;
    public:
        void read_in_user_data();
        void create_new_user();
        void access_user();
        friend void login();
        friend class Mailman;
};

void UserDatabase::create_new_user(){//創建新使用者，創建完成接登入。
    string account, password, adress;
    cin >> account >> password>>adress;//檢查。密碼限定7字以上。帳號重複則不予創立。(未完成都是新界在偷懶)
    User new_user(account, password, adress);
    user_database.push_back(new_user);
}

void UserDatabase::access_user(){//查詢使用者

}

void UserDatabase::read_in_user_data()//讀入使用者資料(user_data.txt)
{
    ifstream file;
    file.open("user_data.txt");
    string temp;
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

//==========================================================



class Mailman : public User{//郵差繼承使用者
    public:
        void check_specific_mail();//查詢信件
        void fetch_from_postOffice();//郵差自郵局取信
        void mail_recived();//郵差將信送達
    private:
        
};



//==========================================================



void login(){//密碼錯誤不鎖帳，但每次程式執行只能試三次。
    string account,password;
    cin >> account >> password;
    //帳號不存在則跳是否創新帳，是則跳create_new_user()(Userdatabase函式)，否結束程式。 
}



//==========================================================




void menu(){//使用者登入後主畫面
    /*展示可用操作{
        1.查詢郵件(僅能查詢自己郵件)(根據編號或自行選擇)
        2.確認郵件已送達(收件)
        3.更改使用者密碼
    }*/
    void send_mail();//寄信
    void mail_check();//查詢郵件紀錄
    void change_password();//更改密碼
}



//==========================================================



void mailman_menu(){//郵差登入後介面
    /*展示可用操作{
        1.查詢郵件(可查詢所有郵件)(根據編號)
        2.更改郵件狀態(遞送中,已送達)
        3.更改郵差密碼
    }*/
}



//==========================================================



int main()
{
    UserDatabase userdatabase;
    userdatabase.read_in_user_data();
}