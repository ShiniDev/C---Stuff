#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <cmath>
#include <iomanip>


void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void getConsoleSize(int& w,int& h){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    w = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    h = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
struct S_Char{
    int xpos;
    int ypos;
    char ch;
    S_Char()
        :xpos(0),ypos(0),ch('~'){}
    S_Char(int x,int y,char c)
        :xpos(x),ypos(y),ch(c){}
    S_Char(int x,int y,std::string s)
        :xpos(x),ypos(y),ch(s[0]){}
};

const std::ostream& operator<<(const std::ostream& os,const S_Char& s){
    gotoxy(s.xpos,s.ypos);
    std::cout << s.ch;
    return os;
}

void moveCharRightLeft(int w,int h,int speed,int index,std::vector<S_Char>& v,bool left){
    int xpos = v[index].xpos;
    if(left){
        for(;xpos>=w;--xpos){
            v[index].xpos = xpos;
            for(auto x : v)
                std::cout << x;
            Sleep(speed);
            system("CLS");
        }
    }
    else {
        for(;xpos<w;++xpos){
            v[index].xpos = xpos;
            for(auto x : v)
                std::cout << x;
            Sleep(speed);
            system("CLS");
        }
    }
}

void moveCharDownUp(int w,int h,int speed,int index,std::vector<S_Char>& v, bool up){
    int ypos = v[index].ypos;
    if(up){
        for(;ypos>=h;--ypos){
            v[index].ypos = ypos;
            for(auto x : v)
                std::cout << x;
            Sleep(speed);
            system("CLS");
        }
    }
    else {
        for(;ypos<h;++ypos){
            v[index].ypos = ypos;
            for(auto x : v)
                std::cout << x;
            Sleep(speed);
            system("CLS");
        }
    }
}

void moveCharbyChar(std::string s,int speed){
    int w,h;
    getConsoleSize(w,h);
    h+=1;
    if(s.size()>=h){
        std::cout << "Too long\n";
        return;
    }
    std::vector<S_Char> v;
    for(int i = 0; i < s.size(); ++i){
        S_Char sC(i,0,s[i]);
        v.push_back(sC);
    }
    for(int i = s.size() - 1; i > -1; --i){
        int delim = std::abs(i-int(s.size()-1));
        int maxW = w-delim;
        moveCharRightLeft(maxW,0,speed,i,v,false);
    }
    for(int i = s.size() - 1; i > -1; --i){
        int delim = std::abs(i-int(s.size()-1));
        int maxW = w-delim;
        int maxH = h-delim;
        moveCharDownUp(0,maxH,speed,i,v,false);
        if(i!=0){
            moveCharRightLeft(maxW+delim,0,speed,i-1,v,false);
        }
    }
    for(int i = s.size() - 1; i > -1; --i){
        int delim = std::abs(i-int(s.size()-1));
        int minW = 0+delim;
        int maxH = h-delim;
        moveCharRightLeft(minW,0,speed,i,v,true);
        if(i!=0){
            moveCharDownUp(0,maxH+delim,speed,i-1,v,false);
        }
    }
    for(int i = s.size() - 1; i > -1; --i){
        int delim = std::abs(i-int(s.size()-1));
        int minW = 0+delim;
        int minH = 0+delim;
        moveCharDownUp(0,minH,speed,i,v,true);
        if(i!=0){
            moveCharRightLeft(minW-delim,0,speed,i-1,v,true);
        }
    }
}

void ui(){
    std::string word;
    int speed;
    std::cout << "Move the word!\n";
    std::cout << "Enter word: ";
    std::getline(std::cin,word);
    std::cout << "Enter speed: ";
    std::cin >> speed;
    moveCharbyChar(word,speed);
}

int main(int argc, char *argv[])
{
    try{
        ui();
    }catch(std::exception& e){
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
