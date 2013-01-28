#include <iostream>
using namespace std;

int count_one0(int x){
    int cnt = 0;
    for(int i=0; i<32; ++i){
        if(x & 1) ++cnt;
        x >>= 1;
    }
    return cnt;
}
int count_one(int x){
    x = (x & (0x55555555)) + ((x >> 1) & (0x55555555));
    x = (x & (0x33333333)) + ((x >> 2) & (0x33333333));
    x = (x & (0x0f0f0f0f)) + ((x >> 4) & (0x0f0f0f0f));
    x = (x & (0x00ff00ff)) + ((x >> 8) & (0x00ff00ff));
    x = (x & (0x0000ffff)) + ((x >> 16) & (0x0000ffff));
    return x;
}
int next(int x){
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;
    for(++x; count_one(x) != num && x != -1; ++x);
    if(x == -1) return -1;
    return x;
}
int previous(int x){
    int num = count_one(x);
    if(num == 0 || x == -1) return -1;
    for(--x; count_one(x) != num && x != -1; --x);
    if(x == -1) return -1;
    return x;
}
int next1(int x){
    int xx = x, bit = 0;
    for(; (x&1) != 1 && bit < 32; x >>= 1, ++bit);
    for(; (x&1) != 0 && bit < 32; x >>= 1, ++bit);
    if(bit == 32) return -1; //11100...00, none satisify
    x |= 1;
    x <<= bit;
    int num1 = count_one(xx) - count_one(x);
    int c = 1;
    for(; num1 > 0; x |= c, --num1, c <<= 1);
    return x;
}
int previous1(int x){
    int xx = x, bit = 0, found = 0;
    for(int i=0; i<32 && x!=0; ++i){
        if(!(x&1) && ((x>>1)&1)){
            found = 1;
            break;
        }
        x >>= 1;
        ++bit;
    }
    if(!found) return -1; //000...111, none satisify
    x ^= 3;
    int num1 = count_one(xx) - count_one(x);
    for(; num1 > 0; x = (x<<1) | 1, --num1, --bit);
    for(; bit > 0; x <<= 1, --bit);
    return x;
}
int main(){
    int a = -8737776;
    cout<<next(a)<<" "<<previous(a)<<endl;
    cout<<next1(a)<<" "<<previous1(a)<<endl;;
    return 0;
}
