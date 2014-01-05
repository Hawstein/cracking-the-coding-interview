#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100;
struct person{
    int h, w;
};
person p[maxn];
int d[maxn];

bool cmp(person p1, person p2){
    if(p1.h == p2.h) return p1.w < p2.w;
    else return p1.h < p2.h;
}
int lis(person p[], int n){
    int k = 1;
    d[0] = p[0].w;
    for(int i=1; i<n; ++i){
        if(p[i].w > d[k-1]) d[k++] = p[i].w;
        else{
            int j;
            for(j=k-1; j>=0 && d[j]>p[i].w; --j);//用二分可将复杂度降到O(nlogn)
            d[j+1] = p[i].w;
        }
    }
    return k;
}
int lis1(person p[], int n) {
    int k = 1;
    person d[n];
    d[0] = p[0];
    for(int i=1; i<n; ++i) {
        if(p[i].w>d[k-1].w && p[i].h>d[k-1].h) d[k++] = p[i];
        else {
            int j;
            for(j=k-1; j>=0 && (p[i].w<))
        }
    }
}
int main(){
    freopen("9.7.in", "r", stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>p[i].h>>p[i].w;
    sort(p, p+n, cmp);
    cout<<lis(p, n)<<endl;
    fclose(stdin);
    return 0;
}
