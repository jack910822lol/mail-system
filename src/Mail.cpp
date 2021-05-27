#include<string>
#include<time.h>
#include<stdio.h>
#include"Mail.h"
using namespace std;

Mail::Mail(){}

void Mail::set_id2(){
    time_t t = time(0);
	char tmp[64];
	strftime( tmp, sizeof(tmp), "%Y%m%d%X%A",localtime(&t) );
	string tmp2="";
	for(int i=0; i<sizeof(tmp); i++)
	{
		if(isdigit(tmp[i]))
		{
			tmp2+=tmp[i];
		}
	}
    id = tmp2;
}

void Mail::set_id(string a){	id=a;	}

void Mail::set_sender(std::string a){   sender=a;    }

void Mail::set_recipient(std::string a){    recipient=a;    }

void Mail::set_sender_adress(std::string a){   sender_adress=a;     }

void Mail::set_recipient_adress(std::string a){     recipient_adress=a;     }

void Mail::set_status(int a){     status=a;     }

std::string Mail::get_id(){     return id;   }

std::string Mail::get_sender(){     return sender;   }

std::string Mail::get_recipient(){      return recipient;   }

std::string Mail::get_sender_adress(){    return sender_adress;     }

std::string Mail::get_recipient_adress(){   return recipient_adress;    }

int Mail::get_status(){   return status;    }
