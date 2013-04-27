#include <iostream>
#include <queue>
using namespace std;

int mini(int a, int b){
    return a < b ? a : b;
}
int mini(int a, int b, int c){
    return mini(mini(a, b), c);
}
int get_num(int k){
    if(k <= 0) return 0;
    int res = 1, cnt = 1;
    queue<int> q3, q5, q7;
    q3.push(3); q5.push(5); q7.push(7);
    for(; cnt<k; ++cnt){
        int v3 = q3.front();
        int v5 = q5.front();
        int v7 = q7.front();
        res = mini(v3, v5, v7);
        if(res == v7){
            q7.pop();
        }
        else{
            if(res == v5){
                q5.pop();
            }
            else{
                if(res == v3){
                    q3.pop();
                    q3.push(3*res);
                }
            }
            q5.push(5*res);
        }
        q7.push(7*res);
    }
    return res;
}
int main(){
    for(int i=1; i<20; ++i)
        cout<<get_num(i)<<endl;
    return 0;
}
