#include <iostream>
#include <cstdio>
using namespace std;

int d[20][20];
int search(int m, int n, int x){
    int r = 0, c = n-1;
    while(r<m && c>=0){
        if(d[r][c] == x) return (r * n + c);
        else if(d[r][c] < x) ++r;
        else --c;
    }
    return -1;
}
int main(){
    freopen("9.6.in", "r", stdin);
    int m, n;
    cin>>m>>n;
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin>>d[i][j];

    int k = search(m, n, 13);
    if(k == -1) cout<<"not found"<<endl;
    else cout<<"position: "<<k/n<<" "<<k%n<<endl;
    fclose(stdin);
    return 0;
}
