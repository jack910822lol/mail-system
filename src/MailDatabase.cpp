#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>
#include"MailDatabase.h"
#include"UserDatabase.h"
#include"Mail.h"
using namespace std;

MailDatabase::MailDatabase(){}

void MailDatabase::set_new_mail(string Sender_account, string Sender_adress, UserDatabase user_database)
{
    string sender_account=Sender_account;
    string sender_adress=Sender_adress;
    string reciver_account;
    Mail tmp_mail;
    cout<<"enter whom to send"<<endl;
    cin>>reciver_account;
    int tmp=user_database.search_by_account(reciver_account);
    if(tmp==-1)
    {
        cout<<"theres no user "<<reciver_account<<endl;
        return;
    }
    else
    {
        string reciver_adress=user_database.get_user(tmp).get_adress();
        tmp_mail.set_id2();
        //cout<<"setid"<<endl;
        tmp_mail.set_recipient(reciver_account);
        //cout<<"setre"<<endl;
        tmp_mail.set_recipient_adress(reciver_adress);
        //cout<<"setreadress"<<endl;
        tmp_mail.set_sender(sender_account);
        //cout<<"setsender"<<endl;
        tmp_mail.set_sender_adress(sender_adress);
        //cout<<"setsenderadress"<<endl;
        tmp_mail.set_status(1);
        //cout<<"setststus"<<endl;
        database.push_back(tmp_mail);
        //cout<<"pushbacked"<<endl;
        int tmp=database.size();
        cout<<"new mail id: "<<tmp_mail.get_id()<<endl
            <<"         sender: "<<tmp_mail.get_sender()<<endl
            <<"         sender adress: "<<tmp_mail.get_sender_adress()<<endl
            <<"         resipient: "<<tmp_mail.get_recipient()<<endl
            <<"         resipient adress: "<<tmp_mail.get_recipient_adress()<<endl;
        cout<<"new mail set successful!"<<endl;
        return;
    }
}

void MailDatabase::read_out_mail_data()
{
    fstream fin;
    fin.open("mail_data.txt", ios::in);
    string tmp;
    int tmp_int;
    Mail tmp_mail;
    while(fin>>tmp)
    {
        tmp_mail.set_id(tmp);
        fin>>tmp;
        tmp_mail.set_sender(tmp);
        fin>>tmp;
        tmp_mail.set_recipient(tmp);
        fin>>tmp;
        tmp_mail.set_sender_adress(tmp);
        fin>>tmp;
        tmp_mail.set_recipient_adress(tmp);
        fin>>tmp_int;
        tmp_mail.set_status(tmp_int);
        database.push_back(tmp_mail);
    }
}

void MailDatabase::write_in_mail_data()
{
    fstream fout;
    fout.open("mail_data.txt", ios::out);
    for(int i=0; i<database.size(); i++)
    {
        fout<<database[i].get_id()<<' ';
        fout<<database[i].get_sender()<<' ';
        fout<<database[i].get_recipient()<<' ';
        fout<<database[i].get_sender_adress()<<' ';
        fout<<database[i].get_recipient_adress()<<' ';
        fout<<database[i].get_status()<<endl;
    }
}

void MailDatabase::search_mail_by_account(string searching_account)
{
    bool flag=0;
    for(int i=0; i<database.size(); i++)
    {
        if(database[i].get_sender()==searching_account)
        {
            cout<<"id:"<<database[i].get_id()<<endl
                <<"sender: "<<database[i].get_sender()<<endl
                <<"sender adress: "<<database[i].get_sender_adress()<<endl
                <<"recipient: "<<database[i].get_recipient()<<endl
                <<"recipient adress: "<<database[i].get_recipient_adress()<<endl;
            if(database[i].get_status()==1)
                cout<<"this mail is on the way!"<<endl;
            else if(database[i].get_status()==2)
                cout<<"this mail is arrived, recipient not check yet!"<<endl;
            else if(database[i].get_status()==3)
                cout<<"this mail is arrived, recipient checked already!"<<endl;
            cout<<endl<<endl;
            flag=1;
        }
    }
    if(flag==0)
        cout<<"not sent any mail yet"<<endl;
}

void MailDatabase::search_mail_by_id(string searching_id)
{
    bool flag=0;
    for(int i=0; i<database.size(); i++)
    {
        if(database[i].get_id()==searching_id)
        {
            cout<<"sender: "<<database[i].get_sender()<<endl
                <<"sender adress: "<<database[i].get_sender_adress()<<endl
                <<"recipient: "<<database[i].get_recipient()<<endl
                <<"recipient adress: "<<database[i].get_recipient_adress()<<endl;
            if(database[i].get_status()==1)
                cout<<"this mail is on the way!"<<endl;
            else if(database[i].get_status()==2)
                cout<<"this mail is arrived, recipient not check yet!"<<endl;
            else if(database[i].get_status()==3)
                cout<<"this mail is arrived, recipient checked already!"<<endl;
            flag=1;
        }
    }
    if(flag==0)
        cout<<"no match mail!"<<endl;
}

void MailDatabase::push_mail_to_database(Mail mail)
{
    database.push_back(mail);
}

void MailDatabase::reciver_change_mail_status(string reciver_account)
{
    int counter=1;
    bool flag=0;
    for(int i=0; i<database.size(); i++)
    {
        if(database[i].get_recipient()==reciver_account&&database[i].get_status()==2)
        {
            flag=1;
            cout<<"the "<<counter<<" mail is send from "<<database[i].get_sender()<<endl;
            cout<<"send from "<<database[i].get_sender_adress()<<endl;
            database[i].set_status(3);
            break;
        }
    }
    if(flag==1)
        cout<<"all "<<counter<<" mails"<<" above already checked!"<<endl;
    else if(flag==0)
        cout<<"no mail need to check!"<<endl;
    return;
}

void MailDatabase::mailman_change_mail_status(string mail_id)
{
    for(int i=0; i<database.size(); i++)
    {
        if(database[i].get_id()==mail_id)
        {
            database[i].set_status(2);
            break;
        }
    }
    return;
}

int MailDatabase::get_mail_index_by_id(string mail_id)
{
    int tmp=-1;
    for(int i=0; i<database.size(); i++)
    {
        if(database[i].get_id()==mail_id)
            return i;
    }
    return tmp;
}

void MailDatabase::data_clear()
{
    database.clear();
}