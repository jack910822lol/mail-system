#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<vector>
#include"MailDatabase.h"
#include"User.h"
#include"UserDatabase.h"
#include"Mailman.h"
#include"MailmanDatabase.h"
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



/*class UserDatabase{//使用者資料庫
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
}*/
//==========================================================

/*class MailmanDatabase{
    private:
        vector<Mailman> database;
    public:
        void read_in_mailman_data();
        void search_by_id();
};*/

//==========================================================



/*class Mailman{//郵差
    private: 
        string account;
        string password;
    public:
        void set_account(string);
        void set_password(string);
        string get_account();
        string get_password();
};*/



//==========================================================



void login(int &who, MailmanDatabase& mailman_database, UserDatabase& user_database, int &user_index, bool& login_success){//密碼錯誤不鎖帳，但每次程式執行只能試三次。
    _relogin:
    system("cls");
    bool user_exisit=0;
    string account,password;
    cout<<"please enter ur account"<<endl;
    cin >> account;
    int tmp = mailman_database.search_by_account(account);
    if(tmp!= -1)//有這名郵差，資料庫位置為tmp
    {
        bool flag=0;
        for(int i=0; i<=3; i++)
        {
            if(i==3)//login fail
            {
                flag=0; 
                break;
            }
            cout<<"please enter your password"<<endl;
            cin>>password;
            if(mailman_database.check_password(tmp, password))//login success with identity : mailman
            {
                flag=1;
                break;
            }
        }
        if(flag==0)//login fail
        {   
            login_success=0;
            return;
        }
        else if(flag==1)//login success with identity : mailman
        {
            who= 0;
            user_index= tmp;
            login_success=1;
            return;
        }
    }
    //使用者輸入的帳號非郵差，查詢是否為使用者帳號
    tmp= user_database.search_by_account(account);
    if(tmp==-1)//無此名使用者,詢問是否創新帳號
    {
        char YN;
        cout<<"no user name is "<<account<<" ,create a new account?(enter Y or N)"<<endl;
        cin>>YN;
        if(YN=='N')
        {
            login_success=0;
            return;
        }
        else if(YN=='Y')
        {
            string tmp2;
            cout<<"enter your account"<<endl;
            cin>>tmp2;
            int ensure=mailman_database.search_by_account(tmp2);
            if(ensure!=-1)
            {
                cout<<"account have been use"<<endl;
                cout<<"please relogin"<<endl<<"back to login in 2 sec";
                Sleep(2000);
                goto _relogin;
            }
            user_database.create_new_user(tmp2);
            cout<<"please relogin"<<endl<<"back to login in 2 sec";
            user_database.write_in_user_data();
            user_database.clear_data();
            user_database.read_out_user_data();
            Sleep(2000);
            goto _relogin;//relogin
        }
    }
    else if(tmp!=-1)//有此名使用者,資料庫中位置為tmp
    {
        bool flag=0;
        for(int i=0; i<=3; i++)
        {
            if(i==3)
            {
                flag=0; 
                break;
            }
            cout<<"please enter your password"<<endl;
            cin>>password;
            if(user_database.check_password(tmp, password))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            login_success=0;
            return;
        }
        else if(flag==1)
        {
            login_success=1;
            who=1;
            user_index=tmp;
            return;
        }
    } 
    //郵差回傳0, 使用者回傳1(&int who)
}



//==========================================================




int User_menu(int& flag,int index, UserDatabase& userdatabase, MailDatabase& maildatabase){//使用者登入後主畫面
    /*展示可用操作{
        1.查詢郵件(僅能查詢自己郵件)(根據編號或全部)
        2.確認郵件已送達(收件)
        3.更改使用者密碼
    }*/
    system("CLS");
    User tmp=userdatabase.get_user(index);
    cout<<"Hello! "<<tmp.get_account()<<endl
    <<"enter 1 to send a mail"<<endl
    <<"enter 2 to check your mail"<<endl
    <<"enter 3 to change password"<<endl
    <<"enter 4 to ensure mail"<<endl
    <<"enter 5 to logout"<<endl;
    cin>>flag;
};


void send_mail(int user_index, UserDatabase& user_database, MailDatabase& mail_database)//寄信
{
    string sender_account=user_database.get_user(user_index).get_account();
    string sender_adress=user_database.get_user(user_index).get_adress();
    mail_database.set_new_mail(sender_account, sender_adress, user_database);
    string trash;
    cout<<"enter anything to back to menu"<<endl;
    cin>>trash;
    return;
}


void mail_check(int user_index, UserDatabase& user_database, MailDatabase& mail_database)//查詢郵件
{
    int choose;
    cout<<"to view all mail please enter 1"<<endl
        <<"to search by mail_id please enter 2"<<endl;
    cin>>choose;
    if(choose==1)
    {
        mail_database.search_mail_by_account(user_database.get_user(user_index).get_account());
    }
    else if(choose==2)
    {
        string mail_id;
        cout<<"enter your mail_id"<<endl;
        cin>>mail_id;
        mail_database.search_mail_by_id(mail_id);
    }
    else
        cout<<"u idiot"<<endl;
    string trash;
    cout<<"enter anything to back to menu"<<endl;
    cin>>trash;
    return;
}


void change_password(int user_index, UserDatabase& user_database)//更改密碼
{
    string new_password;
    cout<<"please enter new password"<<endl;
    cin>>new_password;
    string tmp_account = user_database.get_user(user_index).get_account();
    string tmp_password = new_password;
    string tmp_adress = user_database.get_user(user_index).get_adress();
    User tmp_user(tmp_account, tmp_password, tmp_adress);
    user_database.set_user(user_index, tmp_user);
    cout<<"your new password is "<<user_database.get_user(user_index).get_password();
    cout<<"change successful!"<<endl;
    string trash;
    cout<<"enter anything to back to menu"<<endl;
    cin>>trash;
    return;
}


void ensure_mail(int user_index, UserDatabase& user_database, MailDatabase& mail_database)//收件
{
    string reciver_account = user_database.get_user(user_index).get_account();
    mail_database.reciver_change_mail_status(reciver_account);
    string trash;
    cout<<"enter anything to back to menu"<<endl;
    cin>>trash;
    return;
}


void logout(UserDatabase& user_database, MailmanDatabase& mailman_database, MailDatabase& mail_database)//登出, 寫檔
{
    user_database.write_in_user_data();
    mailman_database.write_in_mailman_data();
    mail_database.write_in_mail_data();
    cout<<"bye bye"<<endl;
    cout<<"shout down in 5 second"<<endl;
    Sleep(5000);
}

//==========================================================



void mailman_menu(int& flag, int user_index, MailmanDatabase& mailman_database, MailDatabase& maildata_base){//郵差登入後介面
    //更改郵件狀態
    //根據郵件id查詢
    //登出
    system("CLS");
    Mailman tmp = mailman_database.get_mailman(user_index);
    cout<<"Hello! "<<tmp.get_account()<<endl
        <<"enter 1 to change mail status"<<endl
        <<"enter 2 to check mail"<<endl
        <<"enter 3 to logout"<<endl;
    cin>>flag;
}


void change_mail_status(MailDatabase& mail_databae)
{
    string mail_id;
    cout<<"please enter the mail_id"<<endl;
    cin>>mail_id;
    int tmpindex=mail_databae.get_mail_index_by_id(mail_id);
    if(tmpindex==-1)
    {
        cout<<"wrong id"<<endl;
        cout<<"back to menu in 2 sec"<<endl;
        Sleep(2000);
        return;
    }
    mail_databae.mailman_change_mail_status(mail_id);
    cout<<"change the mail status to \"this mail is arrived, recipient not check yet!\""<<endl;
    string trash;
    cout<<"enter anything to back to menu"<<endl;
    cin>>trash;
    return;
}


void mailman_check_mail(MailDatabase& mail_database)
{
    int choose;
    cout<<"search mail by mail_id enter 1"<<endl
        <<"search mail by sender_account enter 2"<<endl;
    cin>>choose;
    if(choose==1)
    {
        cout<<"enter mail_id"<<endl;
        string mail_id;
        cin>>mail_id;
        mail_database.search_mail_by_id(mail_id);
    }
    else if(choose==2)
    {
        cout<<"enter sender_account"<<endl;
        string mail_sender;
        cin>>mail_sender;
        mail_database.search_mail_by_account(mail_sender);
    }
    else 
    {
        cout<<"u idiot"<<endl;
    }
    string trash;
    cout<<"enter anything to back to menu"<<endl;
    cin>>trash;
    return;
}
//==========================================================



int main()
{
    UserDatabase user_database;
    MailmanDatabase mailman_database;
    MailDatabase mail_database;
    user_database.read_out_user_data();
    mailman_database.read_out_mailman_data();
    mail_database.read_out_mail_data();
    int who;
    int user_index;
    bool login_success;
    login(who, mailman_database, user_database, user_index, login_success);//郵差:who=0, 使用者:who=1;
    if(login_success==0)
    {
        cout<<"login failed"<<endl;
        Sleep(2000);
        return 0;
    }
    if(login_success==1)
    {
        if(who==0)
        {
            int flag = 1;
            while(flag!=3)
            {
                user_database.write_in_user_data();
                user_database.clear_data();
                user_database.read_out_user_data();
                mailman_database.write_in_mailman_data();
                mailman_database.data_clear();
                mailman_database.read_out_mailman_data();
                mail_database.write_in_mail_data();
                mail_database.data_clear();
                mail_database.read_out_mail_data();
                mailman_menu(flag, user_index, mailman_database, mail_database);
                if(flag==1)
                    change_mail_status(mail_database);
                else if(flag==2)
                    mailman_check_mail(mail_database);
                else if(flag==3)
                    break;
            }
        }
        else if(who==1)
        {
            int flag=1;
            while(flag!=5)
            {
                user_database.write_in_user_data();
                user_database.clear_data();
                user_database.read_out_user_data();
                mailman_database.write_in_mailman_data();
                mailman_database.data_clear();
                mailman_database.read_out_mailman_data();
                mail_database.write_in_mail_data();
                mail_database.data_clear();
                mail_database.read_out_mail_data();
                User_menu(flag, user_index, user_database, mail_database);
                if(flag==1)
                    send_mail(user_index, user_database, mail_database);
                else if(flag==2)
                    mail_check(user_index, user_database, mail_database);
                else if(flag==3)
                    change_password(user_index, user_database);
                else if(flag==4)
                    ensure_mail(user_index, user_database, mail_database);
                else if(flag==5)
                    break;
            }
        }
        logout(user_database, mailman_database, mail_database);//寫檔
    }
}