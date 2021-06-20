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

void SetColor(int color = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}

void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void login(int &who, MailmanDatabase& mailman_database, UserDatabase& user_database, int &user_index, bool& login_success){
    _relogin:
    system("cls");
    bool user_exisit=0;
    string account,password;
    SetColor(174);
    cout<<"______________________________"<<endl;
    cout<<"|                            |"<<endl;
    cout<<"|account:                    |"<<endl;
    cout<<"|password:                   |"<<endl;
    cout<<"|                            |"<<endl;
    cout<<"|____________________________|"<<endl;
    gotoxy(9,2);
    cin>>account;
    gotoxy(10,3);
    int tmp = mailman_database.search_by_account(account);
    if(tmp!= -1)
    {
        bool flag=0;
        for(int i=0; i<=3; i++)
        {
            if(i==3)//login fail
            {
                flag=0;
                break;
            }
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
    //�ϥΪ̿�J���b���D�l�t�A�d�߬O�_���ϥΪ̱b��
    tmp= user_database.search_by_account(account);
    if(tmp==-1)//�L���W�ϥΪ�,�߰ݬO�_�зs�b��
    {
        SetColor();
        system("cls");
        char YN;
        cout<<"there is no account \""<<account<<"\", create new? ( Y / N )"<<endl;
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
        else{
            cout << "No such selection."<< endl;
            return;
        }
    }
    else if(tmp!=-1)//�����W�ϥΪ�,��Ʈw����m��tmp
    {
        bool flag=0;
        for(int i=0; i<=3; i++)
        {
            if(i==3)
            {
                flag=0;
                break;
            }
            gotoxy(10,3);
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
    //�l�t�^��0, �ϥΪ̦^��1(&int who)
}



//==========================================================




int User_menu(int& flag,int index, UserDatabase& userdatabase, MailDatabase& maildatabase){//�ϥΪ̵n�J��D�e��
    /*�i�ܥi�ξާ@{
        1.�d�߶l��(�ȯ�d�ߦۤv�l��)(�ھڽs���Υ���)
        2.�T�{�l��w�e�F(����)
        3.���ϥΪ̱K�X
    }*/
    SetColor();
    system("CLS");
    SetColor(174);
    User tmp=userdatabase.get_user(index);
    cout<<"_____________________________________ "<<endl
        <<"|                                    |"<<endl
        <<"|  Hello!                            |"<<endl
        <<"|  enter 1 to send a mail            |"<<endl
        <<"|  enter 2 to check your mail        |"<<endl
        <<"|  enter 3 to change password        |"<<endl
        <<"|  enter 4 to ensure mail            |"<<endl
        <<"|  enter 5 to logout                 |"<<endl
        <<"|____________________________________|"<<endl;
    SetColor();
    cin>>flag;
};


void send_mail(int user_index, UserDatabase& user_database, MailDatabase& mail_database)//�H�H
{
    string sender_account=user_database.get_user(user_index).get_account();
    string sender_adress=user_database.get_user(user_index).get_adress();
    mail_database.set_new_mail(sender_account, sender_adress, user_database);
    string trash;
    cout<<"enter anything to back to menu"<<endl;
    cin>>trash;
    return;
}


void mail_check(int user_index, UserDatabase& user_database, MailDatabase& mail_database)//�d�߶l��
{
    system("cls");
    cout << "NOW CHECKING MAIL...\n" << endl;
    string choose;
    cout<<"to view all mail please enter 1"<<endl
        <<"to search by mail_id please enter 2"<<endl;
    cin>>choose;
    system("cls");
    if(choose=="1")
    {
        cout << "NOW CHECKING MAIL...\n" << endl;
        mail_database.search_mail_by_account(user_database.get_user(user_index).get_account());
    }
    else if(choose=="2")
    {
        cout << "NOW CHECKING MAIL...\n" << endl;
        string mail_id;
        cout<<"enter your mail_id:"<<endl;
        cin>>mail_id;
        mail_database.search_mail_by_id(mail_id);
    }
    else{
        cout << "NOW CHECKING MAIL...\n" << endl;
        cout<<"no such selection."<<endl;
    }
    string trash;
    cout<<"enter anything to back to menu"<<endl;
    cin>>trash;
    return;
}


void change_password(int user_index, UserDatabase& user_database)//���K�X
{
    system("cls");
    cout << "NOW CHANGING PASSWORD...\n" << endl;
    string new_password;
    cout<<"enter Ur new password: ";
    cin>>new_password;
    cout << endl;
    string tmp_account = user_database.get_user(user_index).get_account();
    string tmp_password = new_password;
    string tmp_adress = user_database.get_user(user_index).get_adress();
    User tmp_user(tmp_account, tmp_password, tmp_adress);
    user_database.set_user(user_index, tmp_user);
    cout<<"Ur new password is "<<user_database.get_user(user_index).get_password();
    cout<<". Change successful!"<<endl;
    string trash;
    cout<<"enter anything to go back to menu"<<endl;
    cin>>trash;
    return;
}


void ensure_mail(int user_index, UserDatabase& user_database, MailDatabase& mail_database)//����
{
    system("cls");
    cout << "NOW ENSURING MAIL...\n" << endl;
    string reciver_account = user_database.get_user(user_index).get_account();
    mail_database.reciver_change_mail_status(reciver_account);
    string trash;
    cout<<"enter anything to back to menu"<<endl;
    cin>>trash;
    return;
}


void logout(UserDatabase& user_database, MailmanDatabase& mailman_database, MailDatabase& mail_database)//�n�X, �g��
{
    user_database.write_in_user_data();
    mailman_database.write_in_mailman_data();
    mail_database.write_in_mail_data();
    cout<<"good bye"<<endl;
    cout<<"shout down in ";
    for(int i = 9; i> 0; i--){
        if(i%3 == 0)
            cout << i/3;
        Sleep(33);
        cout << '.';
        Sleep(300);
    }
}

//==========================================================



void mailman_menu(int& flag, int user_index, MailmanDatabase& mailman_database, MailDatabase& maildata_base){//�l�t�n�J�ᤶ��
    //���l�󪬺A
    //�ھڶl��id�d��
    //�n�X
    SetColor();
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
    system("cls");
    string mail_id;
    cout << "NOW CHANGING MAIL STATUS..." << endl;
    cout<<"please enter the mail_id"<<endl;
    cin>>mail_id;
    int tmpindex=mail_databae.get_mail_index_by_id(mail_id);
    if(tmpindex==-1)
    {
        cout<<"wrong id"<<endl;
        cout<<"back to menu in 2..."<<endl;
        Sleep(1900);
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
    system("cls");
    string choose;
    cout<<"To search mail by mail_id, enter 1"<<endl
        <<"To search mail by sender_account, enter 2"<<endl;
    cin>>choose;
    if(choose=="1")
    {
        system("cls");
        cout << "NOW SEARCHING MAIL BY ID...\n" << endl;
        cout<<"enter mail_id"<<endl;
        string mail_id;
        cin>>mail_id;
        mail_database.search_mail_by_id(mail_id);
    }
    else if(choose=="2")
    {
        system("cls");
        cout << "NOW SEARCHING MAIL BY SENDER ACCOUNT..." << endl;
        cout<<"enter sender_account: "<<endl;
        string mail_sender;
        cin>>mail_sender;
        mail_database.search_mail_by_account(mail_sender);
    }
    else
    {
        cout<<"No such selection."<<endl;
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
    login(who, mailman_database, user_database, user_index, login_success);//�l�t:who=0, �ϥΪ�:who=1;
    if(login_success==0)
    {
        SetColor();
        system("cls");
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
        logout(user_database, mailman_database, mail_database);//�g��
    }
}