#ifndef LINK_H
#define LINK_H

#include <iostream>
#include <vector>
#include <string>

class Link{
public:
    std::string value;
    Link(){}
    Link(const std::string& v,Link* p = nullptr, Link* s = nullptr)
        :value(v),_prev(p),_succ(s){}
    ~Link(){ delete _prev; delete _succ; }

    void insert(Link* l);
    void insert(const std::string& s);
    void add(Link* l);
    void add(const std::string& s);
    Link* erase();
    Link* erase(Link* l);
    bool in_link(Link* l);
    Link* find(const std::string& s);

    Link* advance(int n);
    void print_all();

    Link* prev(){ return _prev; }
    Link* succ(){ return _succ; }
    int size();
private:
    Link* _prev;
    Link* _succ;
    std::string nullLink(){return "NULLLINK";}
};

#endif // LINK_H
