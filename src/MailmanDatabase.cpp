#include<vector>
#include<string>
#include<fstream>
#include"MailmanDatabase.h"
using namespace std;

bool MailmanDatabase::check_password(int index, string to_check)
{
    if(database[index].get_password()==to_check)
        return 1;
    else 
        return 0;
}

void MailmanDatabase::read_out_mailman_data()//讀檔案
{
    fstream fin;
    fin.open("mail_man_data.txt", ios::in);
    string tmp;
    Mailman tmp_mailman;
    while(fin>>tmp)
    {
        tmp_mailman.set_account(tmp);
        fin>>tmp;
        tmp_mailman.set_password(tmp);
        database.push_back(tmp_mailman);
    }
}

void MailmanDatabase::write_in_mailman_data()//寫檔
{
    fstream fout;
    fout.open("mail_man_data.txt", ios::out);
    for(int i=0; i<database.size(); i++)
    {
        fout<<database[i].get_account()<<" "<<database[i].get_password()<<endl;
    }
}

int MailmanDatabase::search_by_account(string account)//回傳資料庫中的位置
{
    int user_exisit=-1;
    for(int i=0; i<database.size(); i++)
    {
        if(account==database[i].get_account())
            return i;
    }
    return user_exisit;
}

Mailman MailmanDatabase::get_mailman(int index)
{
    return database[index];
}

void MailmanDatabase::data_clear()
{
    database.clear();
}