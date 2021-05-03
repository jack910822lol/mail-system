#include<string>
#include"Mail.h"
using namespace std;

Mail::Mail(){}

void Mail::set_id(std::string a){   id=a;   }

void Mail::set_sender(std::string a){   sender=a;    }

void Mail::set_recipient(std::string a){    recipient=a;    }

void Mail::set_sender_adress(std::string a){   sender_adress=a;     }

void Mail::set_recipient_adress(std::string a){     recipient_adress=a;     }

void Mail::set_deliver_time(std::string a){     deliver_time=a;     }

std::string Mail::get_id(){     return id;   }

std::string Mail::get_sender(){     return recipient;   }

std::string Mail::get_recipient(){      return recipient;   }

std::string Mail::get_sender_adress(){    return sender_adress;     }

std::string Mail::get_recipient_adress(){   return recipient_adress;    }

std::string Mail::get_deliver_time(){   return deliver_time;    }