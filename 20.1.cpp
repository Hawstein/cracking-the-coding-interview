#include <iostream>
using namespace std;

int Add1(int a, int b){
    char *c = (char*)a;
    return (int)&c[b]; // c+sizeof(char)*b=a + b
}
int Add2(int a, int b){
    if(b == 0) return a;
    int sum = a ^ b; // 各位相加，不计进位
    int carry = (a & b) << 1; // 记下进位
    return Add2(sum, carry); // 求sum和carry的和
}
int Add3(int a, int b){
    while(b != 0){
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }
    return a;
}
int main(){
    int a = 70, b = -134310;
    cout<<Add1(a, b)<<endl;
    cout<<Add2(a, b)<<endl;
    cout<<Add3(a, b)<<endl;
    return 0;
}
