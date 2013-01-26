#include <iostream>
#include <cstdio>
using namespace std;

void zero(int **a, int m, int n)
{
    int *row = new int[m];
    int *col = new int[n];
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(a[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            if(row[i]==1 || col[j]==1)
                a[i][j] = 0;
}
int main()
{
    freopen("1.7.in", "r", stdin);

    int m, n;
    cin>>m>>n;
    int **a;
    a = new int*[m];
    for(int i=0; i<m; ++i)
        a[i] = new int[n];
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            cin>>a[i][j];
    zero(a, m, n);
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    fclose(stdin);
    return 0;
}
