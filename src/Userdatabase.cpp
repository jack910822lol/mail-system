#include<fstream>
#include<windows.h>
#include<iostream>
#include "UserDatabase.h"
using namespace std;

UserDatabase::UserDatabase() {

}

void UserDatabase::read_out_user_data()//讀使用者資料(user_data.txt)
{
    fstream fin;
    fin.open("user_data.txt",ios::in);
    string tmp_account;
    string tmp_password;
    string tmp_adress;
    while(fin>>tmp_account)
    {
        fin>>tmp_password;
        fin>>tmp_adress;
        User tmp_user(tmp_account, tmp_password, tmp_adress);
        database.push_back(tmp_user);
    }
    fin.close();
}

void UserDatabase::write_in_user_data()
{
    fstream fout;
    fout.open("user_data.txt",ios::out);
    for(int i=0; i<database.size(); i++)
    {
        fout<<database[i].get_account()<<' '<<database[i].get_password()<<' '<<database[i].get_adress()<<endl;
    }
    fout.close();
}

void UserDatabase::create_new_user(string account){//創建新使用者，創建完成接登入。
    string password, adress;
    _reenter:
    int tmp=search_by_account(account);//確認無重複帳戶名
    if(tmp!=-1)//帳戶名已存在
    {
        cout<<"account have been use"<<endl;
        return;
    }
    else if(tmp==-1)
    {
        cout<<"enter your password"<<endl;
        cin>>password;
        cout<<"enter your adress"<<endl;
        cin>>adress;
    }
    User new_user(account, password, adress);
    database.push_back(new_user);
    this->write_in_user_data();
    cout<<"account create success!"<<endl;
    return;
}

int UserDatabase::search_by_account(string account)
{
    int user_exisit=-1;
    for(int i=0; i<database.size(); i++)
    {
        if(account==database[i].get_account())
            return i;
    }
    return user_exisit;
}

bool UserDatabase::check_password(int index, string to_check)
{
    if(database[index].get_password()==to_check)
        return 1;
    else 
        return 0;
}

User UserDatabase::get_user(int index)
{
    return database[index];
}

void UserDatabase::set_user(int user_index, User user)
{
    database[user_index]=user;
}

void UserDatabase::clear_data()
{
    database.clear();
}