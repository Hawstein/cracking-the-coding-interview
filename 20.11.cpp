#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_N = 100;
int matrix[MAX_N][MAX_N];

struct SubSquare{
    int row, col, size;
};

inline int max(int a, int b){
    return a > b ? a : b;
}

bool IsSquare(int row, int col, int size){
    for(int i=0; i<size; ++i){
        if(matrix[row][col+i] == 1)// 1代表白色，0代表黑色
            return false;
        if(matrix[row+size-1][col+i] == 1)
            return false;
        if(matrix[row+i][col] == 1)
            return false;
        if(matrix[row+i][col+size-1] == 1)
            return false;
    }
    return true;
}

SubSquare FindSubSquare(int n){
    int max_size = 0; //最大边长
    int col = 0;
    SubSquare sq;
    while(n-col > max_size){
        for(int row=0; row<n; ++row){
            int size = n - max(row, col);
            while(size > max_size){
                if(IsSquare(row, col, size)){
                    max_size = size;
                    sq.row = row;
                    sq.col = col;
                    sq.size = size;
                    break;
                }
                --size;
            }
        }
        ++col;
    }
    return sq;
}

int main(){
    freopen("20.11.in", "r", stdin);
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            cin>>matrix[i][j];
    SubSquare sq = FindSubSquare(n);
    cout<<"top:    "<<sq.row<<endl;
    cout<<"bottom: "<<sq.row+sq.size-1<<endl;
    cout<<"left:   "<<sq.col<<endl;
    cout<<"right:  "<<sq.col+sq.size-1<<endl;
    fclose(stdin);
    return 0;
}
