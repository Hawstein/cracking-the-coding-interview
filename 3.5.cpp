#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class MyQueue{
public:
    MyQueue(){
        
    }
    ~MyQueue(){
        
    }
    void push(T val){
        move(sout, sin);
        sin.push(val);
    }
    void pop(){
        move(sin, sout);
        sout.pop();
    }
    T front(){
        move(sin, sout);
        return sout.top();
    }
    T back(){
        move(sout, sin);
        return sin.top();
    }
    int size(){
        return sin.size()+sout.size();
    }
    bool empty(){
        return sin.empty()&&sout.empty();
    }
    void move(stack<T> &src, stack<T> &dst){
        while(!src.empty()){
            dst.push(src.top());
            src.pop();
        }
    }

private:
    stack<T> sin, sout;
};

template <typename T>
class MyQueue1{
public:
public:
    MyQueue1(){
        
    }
    ~MyQueue1(){
        
    }
    void push(T val){
        sin.push(val);
    }
    void pop(){
        move(sin, sout);
        sout.pop();
    }
    T front(){
        move(sin, sout);
        return sout.top();
    }
    T back(){
        move(sout, sin);
        return sin.top();
    }
    int size(){
        return sin.size()+sout.size();
    }
    bool empty(){
        return sin.empty()&&sout.empty();
    }
    void move(stack<T> &src, stack<T> &dst){
        if(dst.empty()){
            while(!src.empty()){
                dst.push(src.top());
                src.pop();
            }
        }
    }

private:
    stack<T> sin, sout;    
};
int main(){
    MyQueue<int> q;
    MyQueue1<int> q1;
    for(int i=0; i<10; ++i){
        q.push(i);
        q1.push(i);
    }

    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q1.front()<<" "<<q1.back()<<endl;
    cout<<endl;
    q.pop();
    q1.pop();
    q.push(10);
    q1.push(10);
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q1.front()<<" "<<q1.back()<<endl;
    cout<<endl;
    cout<<q.size()<<" "<<q.empty()<<endl;
    cout<<q1.size()<<" "<<q1.empty()<<endl;        
    return 0;
}
