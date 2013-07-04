#include <iostream>
using namespace std;

enum Check{
    ROW, COLUMN, DIAGONAL, REDIAGONAL
};

int CheckRowColumn(int board[], int n, Check check){
    int type = 0;
    for(int i=0; i<n; ++i){
        bool found = true;
        for(int j=0; j<n; ++j){
            int k = 0;
            if(check == ROW)
                k = i * n + j;
            else
                k = i + j * n;
            if(j == 0){
                type = board[k];
            }
            else if(board[k] != type){
                found = false;
                break; // 有一个不满足，检查下一行
            }
        }
        if(found) return type;
    }
    return 0;
}
int CheckDiagonal(int board[], int n, Check check){
    int type = 0;
    bool found = true;
    // 主对角
    for(int i=0; i<n; ++i){
        int k = 0;
        if(check == DIAGONAL)
            k = i + i * n;
        else
            k = i + (n-1-i) * n;
        if(i == 0){
            type = board[k];
        }
        else if(board[k] != type){
            found = false;
            break;
        }
    }
    if(found) return type;

    return 0;
}
int HasWon(int board[], int n){
    int type = 0;
    type = CheckRowColumn(board, n, ROW);
    if(type != 0) return type;
    type = CheckRowColumn(board, n, COLUMN);
    if(type != 0) return type;
    type = CheckDiagonal(board, n, DIAGONAL);
    if(type != 0) return type;
    type = CheckDiagonal(board, n, REDIAGONAL);
    if(type != 0) return type;

    return 0;
}
int main(){
    int n = 3; // 3*3
    int board[] = {
        2, 2, 1,
        2, 1, 1,
        1, 2, 0,
    };
    int type = HasWon(board, n);
    if(type != 0)
        cout<<type<<" won!"<<endl;
    else
        cout<<"nobody won!"<<endl;
    return 0;
}
