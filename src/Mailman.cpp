#include<string>
#include<iostream>
#include"Mailman.h"
using namespace std;

void Mailman::set_account(string acc)
{
    account=acc;
}

void Mailman::set_password(string pass)
{
    password=pass;
}

string Mailman::get_account()
{
    return account;
}

string Mailman::get_password()
{
    return password;
}