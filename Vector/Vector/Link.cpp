#include "Link.h"

int Link::size(){
    if(this==nullptr||value==nullLink())return 0;
    int pSize = 0,sSize = 0;
    Link* p = _prev;
    Link* s = _succ;
    while(p){
        ++pSize;
        p=p->_prev;
    }
    while(s){
        ++sSize;
        s=s->_succ;
    }
    return pSize+sSize+1;
}

void Link::insert(Link* l){ //This function adds an element directly beside the current link
    if(in_link(l))return;
    if(l==nullptr)return;
    if(this==nullptr||value==nullLink())return;
    if(_prev){
        Link* p = _prev;
        _prev = l;
        _prev->_succ = this;
        _prev->insert(p);
    }else{
        _prev = l;
        _prev->_succ = this;
    }
}

void Link::insert(const std::string &s){
    insert(new Link(s));
}

void Link::add(Link *l){
    if(in_link(l))return;
    if(l==nullptr)return;
    if(this==nullptr||value==nullLink())return;
    if(_succ){
        Link* s = _succ;
        _succ = l;
        _succ->_prev = this;
        _succ->add(s);
    }else{
        _succ = l;
        _succ->_prev = this;
    }
}

void Link::add(const std::string &s){
    add(new Link(s));
}

Link* Link::erase(){//Erases the current Link
    Link* current = this;
    if(current==nullptr||current->value==nullLink())return current;
    if(current->_succ)current->_succ->_prev = _prev;
    if(current->_prev)current->_prev->_succ = _succ;
    if(current->_succ)current=current->_succ;
    else if(current->_prev)current=current->_prev;
    else{
        current->value = nullLink();
        value = nullLink();
    }
    return current;
}

Link* Link::erase(Link* l){
    if(this==nullptr||value==nullLink())return this;
    Link* p = _prev;
    Link* s = _succ;
    if(value==l->value){
        return erase();
    }
    while(p){
        if(p->value==l->value){
            if(p->_succ)p->_succ->_prev = p->_prev;
            if(p->_prev)p->_prev->_succ = p->_succ;
            return this;
        }
        if(p->_prev)p=p->_prev;
        else break;
    }
    while(s){
        if(s->value==l->value){
            if(s->_succ)s->_succ->_prev = s->_prev;
            if(s->_prev)s->_prev->_succ = s->_succ;
            return this;
        }
        if(s->_succ)s=s->_succ;
        else break;
    }
    return this;
}

bool Link::in_link(Link* l){
    if(this==nullptr||value==nullLink())return false;
    if(value==l->value)return true;
    Link* s = this->_succ;
    Link* p = this->_prev;
    while(s){
        if(s->_succ){
            if(s->value==l->value)return true;
            s=s->_succ;
        }
        else break;
    }
    while(p){
        if(p->_prev){
            if(p->value==l->value)return true;
            p=p->_prev;
        }
        else break;
    }
    return false;
}

Link* Link::find(const std::string& s){
    if(this==nullptr||value==nullLink())return this;
    if(value==s)return this;
    Link* pre = this->_prev;
    Link* next = this->_succ;
    while(pre){
        if(pre->value==s)return pre;
        if(pre->_prev)pre=pre->_prev;
        else break;
    }
    while(next){
        if(next->value==s)return next;
        if(next->_succ)next=next->_succ;
        else break;
    }
    return this;
}

Link* Link::advance(int n){
    if(this==nullptr||value==nullLink())return this;
    Link* current = this;
    if(n<0){
        current = current->_prev->advance(n+1);
    }
    else if(n>0){
        current = current->_succ->advance(n-1);
    }
    return current;
}

void Link::print_all(){
    if(this==nullptr||value==nullLink())return;
    Link* l = this;
    while(true){
        if(l->_prev)l=l->_prev; //Go to the first element
        else break;
    }
    std::cout << "{ ";
    while(l){
        std::cout << l->value;
        if(l->_succ){
            std::cout << ", ";
            l=l->_succ;
        }else break;
    }
    std::cout << " }";
}
