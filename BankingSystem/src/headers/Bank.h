#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#include <vector>
#include "Account.h"

class Bank{
public:
    Bank();
    Bank(std::string);
    Bank(std::string,std::vector<Account>);
    bool isPresent(const Account&);
    void addAccount(Account);
    void removeAccount(Account);
    void createData(std::string);
    int getIndex(const Account&);
    Account& getAccount(int);
    std::string name(){return _name;}
    std::vector<Account> accs() {return _accs;}
private:
    std::vector<Account> _accs;
    std::string _name;
};

Bank readBankData(std::string,bool&);
void readBankValues(std::ifstream&,std::string&);
void readAccounts(std::ifstream&,std::vector<Account>&);
bool isAccountPresent(const Account&,const std::vector<Account>&);


#endif // BANK_H_INCLUDED
