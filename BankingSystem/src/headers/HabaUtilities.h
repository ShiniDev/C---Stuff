#ifndef HABAUTILITIES_H_INCLUDED
#define HABAUTILITIES_H_INCLUDED
#include <windows.h>
#include <iomanip>

inline void printDelayedText(std::string s, long ms){
    for(int i = 0; i < s.size(); ++i){
        std::cout << s[i]; //Prints a string character by character
        Sleep(ms);//delay between each print
    }
}

inline void addToStr(std::string& s, char& ch){
    if(ispunct(ch)){} //Would not include punctuation characters
    else if(int(ch)==8&&s.size()>0){
        s.erase(s.begin()+s.size()-1); //Erases the last character of the string
    }
    else if(int(ch)!=8)s+=ch;
}

inline void printToCenter(const std::string& s, int w){
    int width = (w-s.size())/2;
    std::cout << std::left << std::setw(width) << std::setfill(' ') << ' ';
    std::cout << s;
}

inline void printToDelayedCenter(const std::string& s,int w,long ms){
    int width = (w-s.size())/2;
    std::cout << std::left << std::setw(width) << std::setfill(' ') << ' ';
    printDelayedText(s,ms);
}

inline void prompt(char ch){
    while(true){
        char ch1;
        std::cout << "Enter " << ch << " to quit";
        std::cin >> ch1;
        if(ch1 == ch)break;
    }
}

inline bool isFloatingNumber(std::string sD){
    int pointCount = 0;
    for(int i = 0; i < sD.size(); ++i){
        if(sD[i]=='.')++pointCount;
        if(pointCount>1)return false;
        if(!isdigit(sD[i])&&sD[i]!='.')return false;
    }
    return true;
}

inline bool isNumber(std::string sD){
    for(int i = 0; i < sD.size(); ++i)
        if(!isdigit(sD[i]))return false;
    return true;
}


#endif // HABAUTILITIES_H_INCLUDED
