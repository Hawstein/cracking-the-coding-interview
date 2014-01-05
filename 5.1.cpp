#include <iostream>
#include <vector>
using namespace std;

void print_binary(int n){
    vector<int> v;
    int len = 8 * sizeof(int);
    int mask = 1;
    while(len--){
        if(n&mask) v.push_back(1);
        else v.push_back(0);
        mask <<= 1;
    }
    while(!v.empty()){
        cout<<v.back();
        v.pop_back();
    }
    cout<<endl;
}
int update_bits(int n, int m, int i, int j){
    int ret = (1 << i) -1;
    ret &= n;
    return ((n>>(j+1)) << (j+1)) | (m<<i) | ret;
}
int update_bits1(int n, int m, int i, int j){
    int max = ~0;
    int left = max - ((1 << j+1) - 1);
    int right = ((1 << i) -1);
    int mask = left | right;
    return (n & mask) | (m << i);
}
int main(){
    int n = 1<<10, m = 21;
    int ans = update_bits(n, m, 2, 6);
    print_binary(n);
    print_binary(m);
    print_binary(ans);
    return 0;
}
