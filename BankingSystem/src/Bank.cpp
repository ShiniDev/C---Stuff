#include "headers/Bank.h"

Bank::Bank()
    :_name("null"),_accs(0){}

Bank::Bank(std::string s)
    :_name(s),_accs(0){}

Bank::Bank(std::string s,std::vector<Account> a)
    :_name(s),_accs(a){}

bool Bank::isPresent(const Account& a){
    for(int i = 0; i < _accs.size(); ++i){
        if(a==_accs[i])return true;
    }
    return false;
}

void Bank::addAccount(Account a){
    if(!isPresent(a))_accs.push_back(a); //ispresent() to prevent multiple accounts
}

void Bank::removeAccount(Account a){
    if(isPresent(a)){
        int index = getIndex(a);
        _accs.erase(_accs.begin()+index);
    }//if false do nothing
}

int Bank::getIndex(const Account& a){
    for (int i = 0; i < _accs.size(); ++i){
        if(a==_accs[i])return i;
    }
}

Account& Bank::getAccount(int accI){
    if(accI>=0&&accI<_accs.size())return _accs[accI];
}

void Bank::createData(std::string fileN){
    std::ofstream ofs;
    std::string path = ".\\src\\data\\";
    path+=fileN;
    ofs.open(path.c_str(),std::ios_base::out);
    if(!ofs)throw std::runtime_error(path+" directory does not exist");
    ofs << "!bank {\n\t(" << name() << ")\n}\n";
    for(int i = 0; i < _accs.size(); ++i){
        ofs << "@acc {" << '\n' << "\t%" << _accs[i].name() << "%" << '\n';
        ofs << "\t* " << _accs[i].password() << " *\n";
        ofs << "\t$ " << _accs[i].balance() << " $\n";
        ofs << "\t~";
        if(_accs[i].isAdmin())ofs << "t\n}";
        else ofs << "f\n}";
        ofs << '\n';
    }
    ofs.close();
}

Bank readBankData(std::string fileN,bool& init){
    init = false;
    std::string bankName = "";
    std::vector<Account> accounts;
    std::ifstream ifs;
    std::string path = ".\\src\\data\\";
    path += fileN;
    ifs.open(path.c_str(),std::ios_base::in);
    if (!ifs){
        init = true;
        Bank b;
        return b;
    }
    while(true){
        readBankValues(ifs,bankName);
        if(!ifs){
            ifs.clear();
            break;
        }
    }
    while(true){
        readAccounts(ifs,accounts);
        if(!ifs){
            ifs.clear();
            break;
        }
    }
    ifs.close();
    Bank b(bankName,accounts);
    return b;
}

void readBankValues(std::ifstream& ifs,std::string& bN){
    char ch1;
    ifs >> ch1;
    if(ifs.eof())return;
    if(ch1!='!'){
        ifs.unget(); //unread the text that was readed
        ifs.clear(std::ios::failbit);
        return;
    }
    std::string isBankValue;
    ifs >> isBankValue;
    if(ifs.eof())return;
    if(strcasecmp(isBankValue.c_str(),"bank")!=0)throw std::runtime_error("Invalid bank value initializer");
    ifs >> ch1;
    if(ch1!='{')throw std::runtime_error("Bank Data has no opening parenthesis / {");
    ifs >> ch1;
    if(ch1!='(')throw std::runtime_error("Bank Data has no name data / (");
    ifs >> std::noskipws;
    while((ifs >> ch1)&&ch1!=')'&&!ifs.eof()){
        //Checks if the character is an alphabet or a space and is not a number
        if((isalpha(ch1)||isspace(ch1))&&!(isdigit(ch1)))bN+=ch1;
        else if(ispunct(ch1))throw std::runtime_error("Bank data name has no closing character / )");
    }
    ifs >> std::skipws;
    ifs >> ch1;
    if(ch1!='}')throw std::runtime_error("Bank Data has no closing parenthesis / }");
}

void readAccounts(std::ifstream& ifs,std::vector<Account>& aV){
    char ch1;
    ifs >> ch1;
    if(ifs.eof())return;
    if(ch1!='@'){
        ifs.unget(); //unread the text that was readed
        ifs.clear(std::ios::failbit);
        return;
    }
    std::string isAccountValue;
    ifs >> isAccountValue;
    if(ifs.eof())return;
    if (strcasecmp(isAccountValue.c_str(),"acc")!=0)throw std::runtime_error("Invalid account data initializer");
    ifs >> ch1;
    if(ch1!='{')throw std::runtime_error("Account Data has no opening parenthesis / {");
    ifs >> ch1;
    if(ch1!='%')throw std::runtime_error("Account Data has no name value / %");
    std::string accName = "";
    ifs >> std::noskipws;
    while((ifs >> ch1)&&ch1!='%'&&!ifs.eof()){
        //Checks if the character is an alphabet or a space and is not a number
        if((isalpha(ch1)||isspace(ch1))&&!(isdigit(ch1)))accName+=ch1;
        else if(ispunct(ch1))throw std::runtime_error("Account Data name has no closing character / %");
    }
    ifs >> std::skipws;
    ifs >> ch1;
    if(ch1!='*')throw std::runtime_error("Account Data has no password value / *");
    std::string pass;
    ifs >> pass;
    ifs >> ch1;
    if(ch1!='*')throw std::runtime_error("Account Data password has no closing character / *");
    ifs >> ch1;
    if(ch1!='$')throw std::runtime_error("Account Data has no money value / $");
    double money;
    ifs >> money;
    ifs >> ch1;
    if(ch1!='$')throw std::runtime_error("Account Data money has no closing character / $");
    bool isAdmin;
    ifs >> ch1;
    if(ch1!='~')throw std::runtime_error("Account Data has no admin value / ~");
    std::string adminKey = "";
    ifs >> ch1;
    ch1 = toupper(ch1);
    if(ch1=='T')adminKey = "~~code~~";
    else if(ch1=='F'){}
    else throw std::runtime_error("Account Data has no admin identifier / (t/f)");
    ifs >> ch1;
    if(ch1!='}')throw std::runtime_error("Account Data has no closing parenthesis / }");
    Account acc(accName,pass,money,adminKey);
    if(isAccountPresent(acc,aV)){}
    else aV.push_back(acc);
}

bool isAccountPresent(const Account& acc, const std::vector<Account>& aV){
    for(int i = 0; i < aV.size(); ++i){
        if(acc==aV[i])return true;
    }
    return false;
}

