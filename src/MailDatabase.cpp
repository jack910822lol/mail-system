#include<iostream>
#include<fstream>
#include<string>
#include <windows.h>
#include"MailDatabase.h"
using namespace std;

MailDatabase::MailDatabase(){}

void MailDatabase::read_in_mail_data()
{
    std::ifstream file;
    file.open("mail_data.txt");
    std::string temp;
    if(!file)
    {
        cout << "Plz Retry." << endl;
        Sleep(3/2*1000);
        return;
    }
    else 
    {
        file>>temp;
    }
}