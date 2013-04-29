#include <iostream>
using namespace std;

int search(string s[], int low, int high, string x){
    if(x == "") return -1;
    while(low <= high){
        int mid = (low+high)>>1;
        int t = mid;
        while(s[t] == "" && t <= high) ++t;
        if(t > high) high = mid - 1;
        else{
            if(s[t] == x) return t;
            else if(s[t] < x) low = t + 1;
            else high = mid - 1; //or t-1, (mid, t)为空字符串
        }
    }
    return -1;
}
int main(){
    string s[13] = {
        "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
    };
    cout<<search(s, 0, 12, "ball")<<endl;
    return 0;
}
