#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
class MyStack{
public:
    MyStack(){
        
    }
    ~MyStack(){
        
    }
    void push(T val){
        qin.push(val);
    }
    void pop(){
        if(!qin.empty())
            move(qin, qout);
        else
            move(qout, qin);
    }
    T top(){
        if(!qin.empty())
            return qin.back();
        else
            return qout.back();
    }
    bool empty(){
        return qin.empty() && qout.empty();
    }
    int size(){
        return qin.size() + qout.size();
    }
    void move(queue<T> &src, queue<T> &dst){
        while(!src.empty()){
            T val = src.front();
            src.pop();
            if(src.empty()) break;
            dst.push(val);
        }
    }
private:
    queue<T> qin, qout;
};
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
    MyStack<int> st;
    for(int i=0; i<10; ++i){
        st.push(i);
    }
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.push(100);
    cout<<st.top()<<endl;
    for(int i=0; i<2; ++i){
        st.pop();
        cout<<st.top()<<endl;
    }
    
    
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
