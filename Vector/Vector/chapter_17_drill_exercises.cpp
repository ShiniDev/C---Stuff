#include "Link.h"

template <class T> std::ostream& print_elems(std::ostream& os,T* e,int size){
    os << "{ ";
    for(int i = 0; i < size; i++){
        if(i+1<size)os << e[i] << ", ";
        else os << e[i];
    }
    os << " }";
    return os;
}

template <class T> T* init_pointer(int size,int starting){
    T* n = new T[size];
    for(int i = 0; i < size; i++)
        n[i] = starting+i;
    return n;
}

template <class T> std::vector<T> init_vector(int size,int starting){
    std::vector<T> v(size);
    for(int i = 0; i < size; i++)
        v[i] = starting+i;
    return v;
}

template <class T> std::ostream& print_vector(std::ostream& os,std::vector<T> v){
    os << "{ ";
    for(int i = 0; i < v.size(); i++){
        if(i+1<v.size())os << v[i] << ", ";
        else os << v[i];
    }
    os << " }";
    return os;
}



void cp17_drill(){
    int* nums = new int[10];
    print_elems(std::cout,nums,10);
    delete[] nums;
    int* nums1 = init_pointer <int> (10,100);
    int* nums2 = init_pointer <int> (11,100);
    int* nums3 = init_pointer <int> (20,100);
    std::cout << '\n';
    print_elems(std::cout,nums1,10);
    delete[] nums1;
    std::cout << '\n';
    print_elems(std::cout,nums2,11);
    delete[] nums2;
    std::cout << '\n';
    print_elems(std::cout,nums3,20);
    delete[] nums3;
    std::vector<int> vec1 = init_vector <int> (10,100);
    std::vector<int> vec2 = init_vector <int> (11,100);
    std::vector<int> vec3 = init_vector <int> (20,100);
    std::cout << '\n';
    print_vector(std::cout,vec1);
    std::cout << '\n';
    print_vector(std::cout,vec2);
    std::cout << '\n';
    print_vector(std::cout,vec3);
    std::cout << '\n';
    //Second Part
    int* p1 = new int[]{7};
    std::cout << p1 << ", " << *p1 << '\n';
    int* p2 = new int[]{1,2,4,8,16,32,64};
    std::cout << p2 << ", " << *p2 << '\n';
    print_elems(std::cout,p2,7);
    std::cout << '\n';
    int* p3 = p2;
    p2 = p1;
    p2 = p3;
    std::cout << p1 << ", " << *p1 << '\n';
    std::cout << p2 << ", " << *p2 << '\n';
    delete[] p1,p2,p3;
    p1 = new int[10]{1,2,4,8,16,32,64,128,256,512};
    p2 = new int[10];
    p2 = p1;
    print_elems(std::cout,p2,10);
    std::cout << '\n';
    delete[] p1,p2;
    std::vector<int> v1{1,2,4,8,16,32,64,128,256,512};
    std::vector<int> v2 = v1;
    print_vector(std::cout,v2);
    std::cout << '\n';
}

char* to_lower(char* s){
    static const int low = 'a' - 'A';
    int size = 0;
    for(int i = 0;;i++){
        size++;
        if(s[i]=='\0')break;
    }
    char* b = new char[size];
    for(int i = 0; i < size; i++){
        if(s[i]>='A'&&s[i]<='Z')b[i] = char(s[i]+low);
        else b[i] = s[i];
    }
    return b;
}

char* strdup(const char* s){
    int size = 0;
    for(int i = 0;;i++){
        size++;
        if(s[i]=='\0')break;
    }
    char* b = new char[size];
    for(int i = 0; i < size; i++)
        b[i] = s[i];
    return b;
}

char* findx(const char* s, const char* x){
    int sSize = 0,xSize = 0, fI = 0, lI = 0;
    for(int i = 0;;i++){
        if(s[i]=='\0')break;
        sSize++;
    }
    for(int i = 0;;i++){
        if(x[i]=='\0')break;
        xSize++;
    }
    if(xSize>sSize)throw std::runtime_error("findx() 2nd parameter is larger than the first");
    for(int i = 0; i < sSize-xSize; i++){
        if(s[i]==x[0]){
            bool noerror = true;
            for(int j = i, k = 0; k < xSize; ++j,++k){
                if(s[j]!=x[k])noerror = false;
                lI = j;
            }
            if(noerror){
                std::cout << "Reached\n";
                fI = i;
                break;
            }
            else lI = 0;
        }
    }
    char* firstOccur = nullptr;
    std::cout << "First Index: " << fI << ", Last Index: " << lI << '\n';
    std::cout << "Size: " << xSize << '\n';
    if(lI-fI==xSize-1){
        firstOccur = new char[xSize];
        for(int i = 0; i < xSize; i++)
            firstOccur[i] = s[fI+i];
    }
    return firstOccur;
}

void cp17_e7(){ // No Memory Leaks, Hehehe
    char ch;
    char* cString = nullptr;
    char* prevcString = nullptr;
    int size = 0;
    std::cout << "Enter word: ";
    while(true){
        std::cin >> ch;
        if(ch=='!')break;
        if(cString)delete[] cString;
        size++;
        if(size==1){
            cString = new char[]{ch};
            prevcString = new char[]{ch};
        }else{
            cString = new char[size];
            for(int i = 0; i < size; i++){
                if(i+1>=size)cString[i] = ch;
                else cString[i] = prevcString[i];
            }
            delete[] prevcString;
            prevcString = new char[size];
            for(int i = 0; i < size; i++)
                prevcString[i] = cString[i];
        }
    }
    delete[] prevcString;
    std::cout << "Word: ";
    for(int i = 0; i < size; i++)
        std::cout << cString[i];
    std::cout << '\n';
}
