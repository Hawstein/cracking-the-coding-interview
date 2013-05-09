#include <iostream>
#include <cstdio>
using namespace std;


int main(){
    // freopen("12.3.in", "w", stdout);
    // int miss = 12345;
    // for(int i=0; i<20000; ++i){
    //     if(i == miss) continue;
    //     cout<<i<<endl;
    // }
    // fclose(stdout);
    
    freopen("12.3.in", "r", stdin);
    
    int int_len = sizeof(int) * 8;
    int bit_len = 0xFFFFFFFF / int_len;
    int* bit = new int[bit_len];
    int v;
    while(scanf("%d", &v) != EOF){
        bit[v/int_len] |= 1<<(v%int_len);
    }
    bool found = false;
    for(int i=0; i<bit_len; ++i){
        for(int j=0; j<int_len; ++j){
            if((bit[i] & (1<<j)) == 0){
                cout<<i*int_len + j<<endl;
                found = true;
                break;
            }
                
        }
        if(found) break;
    }
    
    delete[] bit;
    fclose(stdin);
    return 0;
}
