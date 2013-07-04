#include <iostream>
using namespace std;

int Count2s(int n){
    int count = 0;
    int factor = 1;
    int low = 0, cur = 0, high = 0;

    while(n/factor != 0){
        low = n - (n/factor) * factor;
        cur = (n/factor) % 10;
        high = n / (factor*10);

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
int main(){
    for(int i=1; i<1000; ++i)
        cout<<i<<" "<<Count2s(i)<<endl;
    return 0;
}
