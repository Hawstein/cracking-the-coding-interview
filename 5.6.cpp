#include <iostream>
#include <string>
using namespace std;

void print_binary(int x){
    string s = "";
    for(int i=0; i<32 && x!=0; ++i, x >>= 1){
        if(x&1) s = "1" + s;
        else s = "0" + s;
    }
    cout<<s<<endl;
}
int swap_bits(int x){
    return ((x & 0x55555555) << 1) | ((x >> 1) & 0x55555555);
}
int swap_bits1(int x){
    return ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1);
}
int main(){
    int x = -7665543;
    print_binary(x);
    print_binary(swap_bits(x));
    print_binary(swap_bits1(x));
    return 0;
}
