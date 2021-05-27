#pragma once
#include<string>

class Mail{//郵件
    private:
        std::string id;//編號
        std::string sender;//寄件
        std::string recipient;//收件人
        std::string sender_adress;//寄件人地址
        std::string recipient_adress;//收件人地址
        int status;//狀態 
    public:
        Mail();
        void set_id2();
        void set_id(std::string a);
        void set_sender(std::string);
        void set_recipient(std::string);
        void set_sender_adress(std::string);
        void set_recipient_adress(std::string);
        void set_status(int);//1為寄送中  2為已送達  3為收件人已確認送達
        std::string get_id();
        std::string get_sender();
        std::string get_recipient();
        std::string get_sender_adress();
        std::string get_recipient_adress();
        int get_status();
};