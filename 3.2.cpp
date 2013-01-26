#include <iostream>
using namespace std;

const int MAX_INT = ~(1<<31);//2147483647

typedef struct node{
    int val, min;
}node;

class StackWithMin{
public:
    StackWithMin(int size=1000){
        buf = new node[size];
        buf[0].min = MAX_INT;
        cur = 0;
    }
    ~StackWithMin(){
        delete[] buf;
    }
    void push(int val){
        buf[++cur].val = val;
        if(val<buf[cur-1].min) buf[cur].min = val;
        else buf[cur].min = buf[cur-1].min;
    }
    void pop(){
        --cur;
    }
    int top(){
        return buf[cur].val;
    }
    bool empty(){
        return cur==0;
    }
    int min(){
        return buf[cur].min;
    }

private:
    node *buf;
    int cur;
};

class stack{
public:
    stack(int size=1000){
        buf = new int[size];
        cur = -1;
    }
    ~stack(){
        delete[] buf;
    }
    void push(int val){
        buf[++cur] = val;
    }
    void pop(){
        --cur;
    }
    int top(){
        return buf[cur];
    }
    bool empty(){
        return cur==-1;
    }

private:
    int *buf;
    int cur;
};

class StackWithMin1{
public:
    StackWithMin1(){
        
    }
    ~StackWithMin1(){
        
    }
    void push(int val){
        s1.push(val);
        if(val<=min())
            s2.push(val);
    }
    void pop(){
        if(s1.top()==min())
            s2.pop();
        s1.pop();
    }
    int top(){
        return s1.top();
    }
    bool empty(){
        return s1.empty();
    }
    int min(){
        if(s2.empty()) return MAX_INT;
        else return s2.top();
    }

private:
    stack s1, s2;
};
int main(){
    //cout<<MIN_INT<<endl;
    StackWithMin1 mystack;
    for(int i=0; i<20; ++i)
        mystack.push(i);
    cout<<mystack.min()<<" "<<mystack.top()<<endl;
    mystack.push(-100);
    mystack.push(-100);
    cout<<mystack.min()<<" "<<mystack.top()<<endl;
    mystack.pop();
    cout<<mystack.min()<<" "<<mystack.top()<<endl;
    return 0;
}
