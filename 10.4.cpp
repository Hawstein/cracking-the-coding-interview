#include <iostream>
using namespace std;

const int INF = ~(1<<31);

void swap(int &a, int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}
int flipsign(int a){
    int d = a < 0 ? 1 : -1;
    int opa = 0;
    while(a != 0){
        a += d;
        opa += d;
    }
    return opa;
}
int abs(int a){
    if(a < 0) a = flipsign(a);
    return a;
}
bool opsign(int a, int b){
    return (a>0 && b<0) || (a<0 && b>0);
}
int times(int a, int b){
    int aa = abs(a), bb = abs(b);
    int res = 0;
    if(aa < bb) swap(aa, bb);
    for(int i=0; i<bb; ++i, res += aa);
    if(opsign(a, b)) res = flipsign(res);
    return res;
}
int minuss(int a, int b){
    return a + flipsign(b);
}
int divide(int a, int b){
    if(b == 0) return INF;
    int aa = abs(a), bb = abs(b);
    int res = 0;
    for(; (aa -= bb)>=0; ++res);
    if(opsign(a, b)) res = flipsign(res);
    return res;
}
int main(){
    int a[] = {
        8, 0, -8, -5, 9
    };
    int b[] = {
        3, 5, 3, 0, -3
    };
    for(int i=0; i<5; ++i){
        cout<<times(a[i], b[i])<<" "<<minuss(a[i], b[i])<<" "<<divide(a[i], b[i])<<endl;
    }
    return 0;
}
