#include <iostream>
using namespace std;

class FirstClass {
public:
    virtual void MethodA(int) {
        cout<<"FirstClass::MethodA(int)"<<endl;
    }
    virtual void MethodA(int, int) {
        cout<<"FirstClass::MethodA(int,int)"<<endl;
    }
};

class SecondClass: public FirstClass {
public:
    void MethodA1(int, int, int) {
        cout<<"SecondClass::MethodA(int)"<<endl;
    }
};

int main() {
    SecondClass sc;
    sc.MethodA(0, 0);    
    return 0;
}
