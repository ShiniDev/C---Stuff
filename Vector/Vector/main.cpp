#include "Link.h"

void prompt(char c){
    char ch;
    while(true){
        std::cout << "Please enter \'" << c << '\'';
        std::cin >> ch;
        if(ch==c)break;
    }
}

//Chapter 17 Drills and Exercises -- Start
void cp17_drill();
char* to_lower(char* s);
char* strdup(const char*);
char* findx(const char* s, const char* x);
void cp17_e7();/*Write a program that reads characters from cin into an array that you
allocate on the free store. Read individual characters until an
exclamation mark (!) is entered. Do not use a std::string. Do not
worry about memory exhaustion.*/
//Chapter 17 -- End
int main()
{
    cp17_e7();
    prompt('|');
    return 0;
}
