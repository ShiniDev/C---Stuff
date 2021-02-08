#include "headers/BankInterface.h"

void BankUI::getConsoleWidth(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void BankUI::initializeUI(){
    printToCenter("Enter Bank Name: ",width);
    std::string bankN = "";
    char ch;
    int length = 0;
    while(ch = _getch()){
        if(ch=='\n'||ch=='\r'){
            if(bankN.size()>0)break;
            continue;
        }
        if(int(ch)==8){
            if(length>0){
                std::cout << "\b \b";
                length--;
            }
        }
        else{
            std::cout << ch;
            length++;
        }
        addToStr(bankN,ch);
    }
    std::cout << '\n';
    printToCenter("<Admin Account>",width);
    std::cout << '\n';
    printToCenter("Name: ",width);
    std::string accN = "";
    length = 0;
    while(ch = _getch()){
        if(ch=='\n'||ch=='\r'){
            if(accN.size()>0)break;
            continue;
        }
        if(int(ch)==8){
            if(length>0){
                std::cout << "\b \b";
                length--;
            }
        }
        else{
            std::cout << ch;
            length++;
        }
        addToStr(accN,ch);
    }
    std::string pass = "";
    std::string rpass = "";
    while(true){
        pass = "";
        rpass = "";
        std::cout << std::endl;
        printToCenter("Password: ",width);
        length = 0;
        while(ch = _getch()){
            if(ch=='\n'||ch=='\r'){
                if(pass.size()>0)break;
                continue;
            }
            if(int(ch)==8){
                if(length>0){
                    std::cout << "\b \b";
                    length--;
                }
            }
            else{
                std::cout << '*';
                length++;
            }
            addToStr(pass,ch);
        }
        std::cout << std::endl;
        printToCenter("Confirm Password: ",width);
        length = 0;
        while(ch = _getch()){
            if(ch=='\n'||ch=='\r'){
                if(rpass.size()>0)break;
                continue;
            }
            if(int(ch)==8){
                if(length>0){
                    std::cout << "\b \b";
                    length--;
                }
            }
            else{
                std::cout << '*';
                length++;
            }
            addToStr(rpass,ch);
        }
        std::cout << std::endl;
        bool error = false, whiteSpaceError = false, forbiddenChar = false;
        if(pass.size()<=4){
            printToCenter("Password is too short\n",width);
            error = true;
        }
        if(pass!=rpass){
            printToCenter("Password does not match\n",width);
            error = true;
        }
        for(int i = 0; i < pass.size(); ++i){
            if(pass[i]==' '){
                whiteSpaceError = true;
                error = true;
            }
            if(pass[i]=='*'){
                forbiddenChar = true;
                error = true;
            }
        }
        if(error){
            if(whiteSpaceError)printToCenter("Password contains a whitespace\n",width);
            if(forbiddenChar)printToCenter("Password contains a forbidden character\n",width);
        }else break;
    }
    Bank b(bankN);
    Account a(accN,pass,"~~code~~");
    b.addAccount(a);
    _bank = b;
}

void BankUI::startupui(){
    system("CLS");
    save();
    printToCenter("Welcome to "+_bank.name(),width);
    std::cout << "\n\n";
    printToCenter("[1]Login\n",width);
    printToCenter("[2]Sign-up\n",width);
    printToCenter("[3]Quit\n",width);
    char ch;
    while(true){
        ch = _getch();
        if(ch=='1'){
            login();
            break;
        }else if(ch=='2'){
            signup();
            break;
        }else if(ch=='3'){
            save();
            return;
        }
    }
    startupui();
}

void BankUI::save(){
    _bank.createData("data.txt");
}

void BankUI::login(){
    system("CLS");
    printToCenter("<Login Page>",width);
    std::cout << "\n\n";
    char ch;
    while(true){
        printToCenter("Enter account name: ",width);
        std::string accN = "";
        int length = 0;
        while(ch = _getch()){
            if(ch=='\n'||ch=='\r'){
                if(accN.size()>0)break;
                continue;
            }
            if(int(ch)==8){
                if(length>0){
                    std::cout << "\b \b";
                    length--;
                }
            }
            else{
                std::cout << ch;
                length++;
            }
            addToStr(accN,ch);
        }
        std::string pass = "";
        while(true){
            pass = "";
            std::cout << std::endl;
            printToCenter("Enter password: ",width);
            length = 0;
            while(ch = _getch()){
                if(ch=='\n'||ch=='\r'){
                    if(pass.size()>0)break;
                    continue;
                }
                if(int(ch)==8){
                    if(length>0){
                        std::cout << "\b \b";
                        length--;
                    }
                }
                else{
                    std::cout << '*';
                    length++;
                }
                addToStr(pass,ch);
            }
            break;
        }
        std::cout << std::endl;
        Account a(accN,pass);
        if(_bank.isPresent(a)){
            ch = '~';
            printToDelayedCenter("Login successfully\n",width,100);
            _current = _bank.getIndex(a);
            if(_bank.getAccount(_current).isAdmin()){
                adminui();
            }else accountui();
            break;
        }else{
            printToCenter("Try again?(y/n)\n",width);
            while(true){
                ch = _getch();
                ch = toupper(ch);
                if(ch=='Y')break;
                if(ch=='N')break;
            }
        }
        if(ch=='Y')continue;
        else break;
    }
}

void BankUI::signup(){
    system("CLS");
    printToCenter("<Register Page>",width);
    std::cout << "\n\n";
    char ch;
    printToCenter("Name: ",width);
    std::string accN = "";
    int length = 0;
    while(ch = _getch()){
        if(ch=='\n'||ch=='\r'){
            if(accN.size()>0)break;
            continue;
        }
        if(int(ch)==8){
            if(length>0){
                std::cout << "\b \b";
                length--;
            }
        }
        else{
            std::cout << ch;
            length++;
        }
        addToStr(accN,ch);
    }
    std::string pass = "";
    std::string rpass = "";
    while(true){
        pass = "";
        rpass = "";
        std::cout << std::endl;
        printToCenter("Password: ",width);
        length = 0;
        while(ch = _getch()){
            if(ch=='\n'||ch=='\r'){
                if(pass.size()>0)break;
                continue;
            }
            if(int(ch)==8){
                if(length>0){
                    std::cout << "\b \b";
                    length--;
                }
            }
            else{
                std::cout << '*';
                length++;
            }
            addToStr(pass,ch);
        }
        std::cout << std::endl;
        printToCenter("Confirm Password: ",width);
        length = 0;
        while(ch = _getch()){
            if(ch=='\n'||ch=='\r'){
                if(rpass.size()>0)break;
                continue;
            }
            if(int(ch)==8){
                if(length>0){
                    std::cout << "\b \b";
                    length--;
                }
            }
            else{
                std::cout << '*';
                length++;
            }
            addToStr(rpass,ch);
        }
        std::cout << std::endl;
        bool error = false, whiteSpaceError = false, forbiddenChar = false;
        if(pass.size()<=4){
            printToCenter("Password is too short\n",width);
            error = true;
        }
        if(pass!=rpass){
            printToCenter("Password does not match\n",width);
            error = true;
        }
        for(int i = 0; i < pass.size(); ++i){
            if(pass[i]==' '){
                whiteSpaceError = true;
                error = true;
            }
            if(pass[i]=='*'){
                forbiddenChar = true;
                error = true;
            }
        }
        if(error){
            if(whiteSpaceError)printToCenter("Password contains a whitespace\n",width);
            if(forbiddenChar)printToCenter("Password contains a forbidden character\n",width);
        }else break;
    }
    Account a(accN,pass);
    if(_bank.isPresent(a))printToDelayedCenter("Account exists\n",width,100);
    else _bank.addAccount(a);
}

void BankUI::accountui(){
    std::cin.clear();
    system("CLS");
    if(_bank.getAccount(_current).balance()<0)_bank.getAccount(_current).setBalance(0);
    save();
    printToCenter("<Account>\n",width);
    std::cout << '\n';
    printToCenter("Account Information\n",width);
    printToCenter("Name: "+_bank.getAccount(_current).name()+"\n",width);
    printToCenter("Balance: "+std::to_string(_bank.getAccount(_current).balance())+"\n",width);
    std::cout << '\n';
    printToCenter("Commands\n",width);
    printToCenter("[1] Withdraw\n",width);
    printToCenter("[2] Deposit\n",width);
    printToCenter("[3] Change Password\n",width);
    printToCenter("[4] Delete Account\n",width);
    printToCenter("[5] Logout\n",width);
    char ch;
    while(true){
        ch = _getch();
        if(ch=='1'){
            double temp = _bank.getAccount(_current).balance();
            while(true){
                std::cout << '\n';
                printToCenter("Withdraw Amount: ",width);
                std::string amountS;
                std::cin >> amountS;
                double amount;
                if(isFloatingNumber(amountS))amount = std::stod(amountS);
                else{
                    printToDelayedCenter("Numbers only\n",width,50);
                    continue;
                }
                if(amount<0){
                    printToCenter("Withdrawal amount cannot be less than 0\n",width);
                    continue;
                }else if(amount>temp){
                    std::cout << '\n';
                    printToDelayedCenter("Amount Withdrawn: "+std::to_string(temp),width,50);
                    _bank.getAccount(_current).setBalance(0);
                }else{
                    printToDelayedCenter("Amount Withdrawn: "+std::to_string(amount),width,50);
                    _bank.getAccount(_current).setBalance(temp-amount);
                }
                break;
            }
            break;
        }else if(ch=='2'){
            while(true){
                std::cout << '\n';
                printToCenter("Deposit Amount: ",width);
                double amount;
                std::string amountS;
                std::cin >> amountS;
                if(isFloatingNumber(amountS))amount = std::stod(amountS);
                else{
                    printToDelayedCenter("Numbers only\n",width,50);
                    continue;
                }
                if(amount<0){
                    printToCenter("Deposit amount cannot be less than 0\n",width);
                    continue;
                }else{
                    printToDelayedCenter("Amount Deposited: "+std::to_string(amount)+"\n",width,50);
                    _bank.getAccount(_current).addBalance(amount);
                }
                break;
            }
            break;
        }else if(ch=='3'){
            std::string cpass = "";
            std::string pass = "";
            std::string rpass = "";
            char ch;
            int length = 0;
            while(true){
                cpass = "";
                std::cout << std::endl;
                printToCenter("Current Password: ",width);
                length = 0;
                while(ch = _getch()){
                    if(ch=='\n'||ch=='\r'){
                        if(cpass.size()>0)break;
                        continue;
                    }
                    if(int(ch)==8){
                        if(length>0){
                            std::cout << "\b \b";
                            length--;
                        }
                    }
                    else{
                        std::cout << '*';
                        length++;
                    }
                    addToStr(cpass,ch);
                }
                std::cout << '\n';
                if(cpass==_bank.getAccount(_current).password())break;
                else printToDelayedCenter("Wrong Password",width,50);
            }
            while(true){
                pass = "";
                rpass = "";
                std::cout << std::endl;
                printToCenter("New Password: ",width);
                length = 0;
                while(ch = _getch()){
                    if(ch=='\n'||ch=='\r'){
                        if(pass.size()>0)break;
                        continue;
                    }
                    if(int(ch)==8){
                        if(length>0){
                            std::cout << "\b \b";
                            length--;
                        }
                    }
                    else{
                        std::cout << '*';
                        length++;
                    }
                    addToStr(pass,ch);
                }
                std::cout << std::endl;
                printToCenter("Confirm Password: ",width);
                length = 0;
                while(ch = _getch()){
                    if(ch=='\n'||ch=='\r'){
                        if(rpass.size()>0)break;
                        continue;
                    }
                    if(int(ch)==8){
                        if(length>0){
                            std::cout << "\b \b";
                            length--;
                        }
                    }
                    else{
                        std::cout << '*';
                        length++;
                    }
                    addToStr(rpass,ch);
                }
                std::cout << std::endl;
                bool error = false, whiteSpaceError = false, forbiddenChar = false;
                if(pass.size()<=4){
                    printToDelayedCenter("Password is too short\n",width,50);
                    error = true;
                }
                if(pass!=rpass){
                    printToDelayedCenter("Password does not match\n",width,50);
                    error = true;
                }
                for(int i = 0; i < pass.size(); ++i){
                    if(pass[i]==' '){
                        whiteSpaceError = true;
                        error = true;
                    }
                    if(pass[i]=='*'){
                        forbiddenChar = true;
                        error = true;
                    }
                }
                if(error){
                    if(whiteSpaceError)printToDelayedCenter("Password contains a whitespace\n",width,50);
                    if(forbiddenChar)printToDelayedCenter("Password contains a forbidden character\n",width,50);
                    continue;
                }
                _bank.getAccount(_current).setPassword(pass);
                printToDelayedCenter("Password changed successfully\n",width,50);
                break;
            }
            break;
        }else if(ch=='4'){
            std::string cpass = "";
            char ch;
            int length = 0;
            while(true){
                cpass = "";
                std::cout << std::endl;
                printToCenter("Current Password: ",width);
                length = 0;
                while(ch = _getch()){
                    if(ch=='\n'||ch=='\r'){
                        if(cpass.size()>0)break;
                        continue;
                    }
                    if(int(ch)==8){
                        if(length>0){
                            std::cout << "\b \b";
                            length--;
                        }
                    }
                    else{
                        std::cout << '*';
                        length++;
                    }
                    addToStr(cpass,ch);
                }
                if(cpass==_bank.getAccount(_current).password())break;
                else printToDelayedCenter("Wrong Password",width,50);
            }
            std::cout << '\n';
            printToCenter("Are you sure? (y/n)",width);
            while(true){
                ch = _getch();
                ch = std::tolower(ch);
                if(ch=='y'){
                    _bank.removeAccount(_bank.getAccount(_current));
                    return;
                }else if(ch=='n')break;
            }
            break;
        }else if(ch=='5'){
            save();
            return;
        }
    }
    accountui();
}

void BankUI::adminui(){
    system("CLS");
    save();
    printToCenter("<Admin>",width);
    std::cout << "\n\n";
    printToCenter("[1] Account List\n",width);
    printToCenter("[2] Remove Account\n",width);
    printToCenter("[3] Save to specific file\n",width);
    printToCenter("[4] Logout\n",width);
    char ch;
    while(true){
        ch = _getch();
        if(ch=='1'){
            std::cout << '\n';
            printToDelayedCenter("Accounts:\n\n",width,50);
            for(int i = 0; i < _bank.accs().size(); ++i){
                printToCenter("["+std::to_string(i)+"] "+_bank.accs()[i].name()+"\n",width);
            }
            std::cout << '\n';
            printToCenter("Press enter to continue...\n",width);
            while(true){
                char ch2;
                ch2 = _getch();
                if(ch2=='\n'||ch2=='\r')break;
            }
            break;
        }else if(ch=='2'){
            std::cout << '\n';
            printToCenter("Enter index of account: ",width);
            std::string iS;
            std::cin >> iS;
            int index;
            if(isNumber(iS))index = std::stoi(iS);
            else{
                printToDelayedCenter("Numbers only\n",width,50);
                break;
            }
            if(index<0||index>=_bank.accs().size()){
                printToDelayedCenter("Account Index not found\n",width,50);
                break;
            }
            if(_bank.getAccount(index).isAdmin()){
                printToDelayedCenter("Cannot remove admin account\n",width,50);
                break;
            }
            _bank.removeAccount(_bank.getAccount(index));
            printToDelayedCenter("Account removed successfully\n",width,50);
            break;
        }else if(ch=='3'){
            std::cout << '\n';
            printToCenter("Enter file name: ",width);
            std::string fileN,fileExtension = "";
            std::cin >> fileN;
            for(int i = fileN.size()-1; i>=0; i--){
                if(fileN[i]=='.')break;
                fileExtension+=fileN[i];
            }
            if(fileExtension=="txt"){
                _bank.createData(fileN);
                printToDelayedCenter("Data saved to "+fileN+"\n",width,50);
                break;
            }else{
                printToDelayedCenter("Only .txt files are allowed\n",width,50);
                break;
            }
        }else if(ch=='4'){
            save();
            return;
        }
    }
    adminui();
}

void BankUI::start(){
    _init = true;
    std::cout << "Set console size\n";
    while(true){
        getConsoleWidth();
        std::cout << "Size: " << width << '\n';
        std::cout << "Confirm?(y/n)";
        char ch = _getch();
        ch = tolower(ch);
        if(ch=='y')break;
        std::cout << '\n';
        if(ch=='n')continue;
    }
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    system("CLS");
    _bank = readBankData("data.txt",_init);
    printToDelayedCenter("Loading Data...\n",width,100);
    if(_init){
        printToDelayedCenter("No data found...\n",width,100);
        printToDelayedCenter("Initializing Bank Data\n",width,100);
        initializeUI();
    }else printToDelayedCenter("Data loaded...",width,100);
    save();
    startupui();
}
