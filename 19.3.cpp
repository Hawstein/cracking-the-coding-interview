#include <iostream>
using namespace std;

int NumZeros(int n){
    if(n < 0) return -1;
    int num = 0;
    while((n /= 5) > 0){
        num += n;
    }
    return num;
}
int NumZeros1(int n){
    if(n < 0) return -1;
    int num = 0;
    for(int i = 5; n/i > 0; i *= 5)
        num += n/i;
    return num;
}
int main(){
    for(int i=1; i<100; ++i){
        if(NumZeros(i) == NumZeros1(i))
            cout<<i<<endl;
    }
    return 0;
}
