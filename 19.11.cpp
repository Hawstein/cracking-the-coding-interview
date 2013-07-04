#include <iostream>
#include <algorithm>
using namespace std;

void PrintPairSum(int a[], int n, int sum){
    if(a==NULL || n<2) return;
    
    sort(a, a+n);
    int low = 0, high = n-1;
    while(low < high){
        if(a[low]+a[high] > sum)
            --high;
        else if(a[low]+a[high] < sum)
            ++low;
        else{
            cout<<a[low]<<" "<<a[high]<<endl;
            ++low; --high;
        }
            
    }
}

int main(){
    int n = 6, sum = 6;
    int a[] = {
        1, 2, 3, 4, 5, 6
    };
    PrintPairSum(a, n, sum);
    return 0;
}
