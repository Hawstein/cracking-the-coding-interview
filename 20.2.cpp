#include <iostream>
#include <cstdlib>
using namespace std;

void Swap(int &a, int &b){// 有可能swap同一变量，不能用异或版本
    int t = a;
    a = b;
    b = t;
}
void RandomShuffle(int a[], int n){
    for(int i=0; i<n; ++i){
        int j = rand() % (n-i) + i;// 产生i到n-1间的随机数
        Swap(a[i], a[j]);
    }
}
int main(){
    srand((unsigned)time(0));
    int n = 9;
    int a[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    RandomShuffle(a, n);
    for(int i=0; i<n; ++i)
        cout<<a[i]<<endl;
    return 0;
}
