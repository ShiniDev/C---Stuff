#ifndef BANKINTERFACE_H_INCLUDED
#define BANKINTERFACE_H_INCLUDED
#include "Bank.h"
#include <conio.h>
#include <windows.h>

struct BankUI{
    void getConsoleWidth();
    void initializeUI();
    void startupui();
    void save();
    void login();
    void signup();
    void start();
    void adminui();
    void accountui();
    Bank _bank;
    int _current;
    int width;
    bool _init;
};
#endif // BANKINTERFACE_H_INCLUDED
