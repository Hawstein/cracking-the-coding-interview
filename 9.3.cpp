#include <iostream>
using namespace std;

int search(int a[], int low, int high, int x){
    while(low <= high){
        //cout<<low<<" "<<high<<endl;
        //++cnt;
        int mid = (low+high)>>1;
        if(a[mid] == x) return mid;
        if(a[mid] < x){
            if(a[mid] < a[low]){
                if(a[low] <= x) high = mid - 1;
                else low = mid + 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(a[mid] < a[low]){
                high = mid - 1;
            }
            else{
                if(a[low] <= x) high = mid - 1;
                else low = mid + 1;
            }
        }
    }
    return -1;
}
int main(){
    int a[12] = {
        15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14
    };
    int b[19] = {
        2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2
    };
    cout<<search(a, 0, 11, 3)<<endl;
    return 0;
}
