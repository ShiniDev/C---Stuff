#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
#include <stdio.h>
#include "HabaUtilities.h"

class Account{
public:
    Account()
        :_name("null"),_pin("0000"),_admin(false),_balance(0){}
    Account(std::string s,std::string pass)
        :_name(s),_pin(pass),_admin(false),_balance(0){}
    Account(std::string s,std::string pass,double money)
        :_name(s),_pin(pass),_admin(false),_balance(money){}
    Account(std::string s,std::string pass,std::string rootPass)
        :_name(s),_pin(pass),_balance(0){
            if(rootPass=="~~code~~")_admin = true;
            else _admin = false;
        }
    Account(std::string s,std::string pass,double money,std::string rootPass)
        :_name(s),_pin(pass),_balance(money){
            if(rootPass=="~~code~~")_admin = true;
            else _admin = false;
        }
    std::string name() const {return _name;}
    std::string password() const {return _pin;}
    void setPassword(std::string s) { _pin = s; }
    bool isAdmin() const {return _admin;}
    double balance() const {return _balance;}
    void addBalance(double d){_balance+=d;}
    void setBalance(double d){_balance=d;}
private:
    std::string _name;
    std::string _pin;
    bool _admin;
    double _balance;
};

inline bool operator==(const Account& a1,const Account& a2){
    return (a1.name()==a2.name())&&(a1.password()==a2.password());
}

inline bool operator!=(const Account& a1,const Account& a2){
    return !(a1==a2);
}


#endif // ACCOUNT_H_INCLUDED
