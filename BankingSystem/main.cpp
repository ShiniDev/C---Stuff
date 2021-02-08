#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

#include "src/headers/Bank.h"
#include "src/headers/BankInterface.h"

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType);

BankUI ui; //Global variable needed to have save function before quitting console

int main(){
    try{
        SetConsoleCtrlHandler(CtrlHandler, TRUE);
        ui.start();
    }catch(std::exception& e){
        std::cerr << "Error: " << e.what() << '\n';
        prompt('~');
        return 1;
    }
    return 0;
}

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType){
    switch (fdwCtrlType){
        case CTRL_CLOSE_EVENT:
            if(ui._init){}
            else ui.save();
            return TRUE;
        default:
            return FALSE;
    }
}
