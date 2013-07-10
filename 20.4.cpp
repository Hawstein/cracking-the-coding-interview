#include <iostream>
using namespace std;

int Count2(int n){
    int count = 0;
    while(n > 0){
        if(n%10 == 2)
            ++count;
        n /= 10;
    }
    return count;
}

int Count2s1(int n){
    int count = 0;
    for(int i=0; i<=n; ++i)
        count += Count2(i);
    return count;

}

int Count2s(int n){
    int count = 0;
    int factor = 1;
    int low = 0, cur = 0, high = 0;

    while(n/factor != 0){
        low = n - (n/factor) * factor;//低位数字
        cur = (n/factor) % 10;//当前位数字
        high = n / (factor*10);//高位数字

        switch(cur){
        case 0:
        case 1:
            count += high * factor;
            break;
        case 2:
            count += high * factor + low + 1;
            break;
        default:
            count += (high + 1) * factor;
            break;
        }

        factor *= 10;
    }

    return count;
}

int Countis(int n, int i){
    if(i<1 || i>9) return -1;//i只能是1到9

    int count = 0;
    int factor = 1;
    int low = 0, cur = 0, high = 0;

    while(n/factor != 0){
        low = n - (n/factor) * factor;//低位数字
        cur = (n/factor) % 10;//当前位数字
        high = n / (factor*10);//高位数字

        if(cur < i)
            count += high * factor;
        else if(cur == i)
            count += high * factor + low + 1;
        else
            count += (high + 1) * factor;

        factor *= 10;
    }

    return count;
}
int main(){
    for(int i=1; i<1000; ++i)
        cout<<Count2s1(i)<<" "<<Count2s(i)<<" "<<Countis(i, 2)<<endl;
    // int n = 999;
    // for(int i=1; i<10; ++i)
    //     cout<<Countis(n, i)<<endl;
    return 0;
}
