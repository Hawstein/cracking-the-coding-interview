#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
using namespace std;

class Median{
private:
    priority_queue<int,vector<int>,less<int> > max_heap;//左边的数
    priority_queue<int,vector<int>,greater<int> > min_heap;//右边的数

public:
    void Insert(int v);
    int GetValue();
};

void Median::Insert(int v){
    if(max_heap.empty() && min_heap.empty())
        max_heap.push(v);
    // max_heap不为空，则往max_heap插入数据，
    // 往min_heap插入数据的话可能导致较小的数放到右边的堆
    else if(!max_heap.empty() && min_heap.empty())
        max_heap.push(v); 
    else if(max_heap.empty() && !min_heap.empty())
        min_heap.push(v);
    else{
        if(v < max_heap.top())
            max_heap.push(v);
        else
            min_heap.push(v);
    }
    //调整，保证两个堆的元素数量差别不大于1
    //不要用hmax_heap.size()-min_heap.size()>1
    //因为size返回的是unsigned类型，当左边相减得到一个负数时，本来为false
    //但会被转为一个大的正数，结果为true，出问题
    while(max_heap.size() > min_heap.size()+1){
        int data = max_heap.top();
        min_heap.push(data);
        max_heap.pop();
    }
    while(min_heap.size() > max_heap.size()+1){
        int data = min_heap.top();
        max_heap.push(data);
        min_heap.pop();
    }
}

int Median::GetValue(){//中位数为int，由于有除法，也可改为float
    if(max_heap.empty() && min_heap.empty())
        return (1<<31); //都为空时，返回int最小值
    if(max_heap.size() == min_heap.size())
        return (max_heap.top()+min_heap.top()) / 2;
    else if(max_heap.size() > min_heap.size())
        return max_heap.top();
    else
        return min_heap.top();
}

int main(){
    srand((unsigned)time(0));
    Median md;
    // vector<int> vi;
    // int num = rand() % 30; //数量是30以内的随机数
    // for(int i=0; i<num; ++i){
    //     int data = rand() % 100; //元素是100内的数
    //     vi.push_back(data);
    //     md.Insert(data);
    // }
    // sort(vi.begin(), vi.end());
    // for(int i=0; i<num; ++i)
    //     cout<<vi.at(i)<<" "; //排序的序列
    md.Insert(3);
    md.Insert(1);
    md.Insert(2);
    cout<<endl<<md.GetValue()<<endl; //中位数
    return 0;
}
