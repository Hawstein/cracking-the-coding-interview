#include <iostream>
using namespace std;

class Bitmap{
public:
    Bitmap(int size = 32){
        bits = new int[size/32 + 1];
    }
    ~Bitmap(){
        delete[] bits;
    }
    bool get(int pos){// true if bit is 1, else: false
        return (bits[pos/32] & (1<<(pos&0x1f))) != 0;
    }
    void set(int pos){
        bits[pos/32] |= (1<<(pos&0x1f));
    }
private:
    int *bits;
};

void print_duplicates(int a[], int n, int bitsize){
    Bitmap bm(bitsize);
    for(int i=0; i<n; ++i){
        if(bm.get(a[i]-1)) // bitmap starts at 0, number starts at 1
            cout<<a[i]<<endl;
        else
            bm.set(a[i]-1);
    }
}
int main(){
    int a[] = {
        1,2,3,4,5,32000,7,8,9,10,11,1,2,13,15,16,32000,11,5,8
    };
    print_duplicates(a, 20, 32000);
    return 0;
}
