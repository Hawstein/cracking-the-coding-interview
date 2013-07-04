#include <iostream>
using namespace std;

int Rand5(){
    int x = ~(1<<31); // max int
    while(x > 5)
        x = Rand7();
    return x;
}



int main(){
    return 0;
}
