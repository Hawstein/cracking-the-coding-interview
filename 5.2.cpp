#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string print_binary(string val){
    int pos = val.find('.', 0);
    int intpart = atoi(val.substr(0, pos).c_str());
    double decpart = atof(val.substr(pos, val.length()-pos).c_str());
    string intstr = "", decstr = "";
    while(intpart > 0){
        if(intpart&1) intstr = "1" + intstr;
        else intstr = "0" + intstr;
        intpart >>= 1;
    }
    while(decpart > 0){
        if(decstr.length() > 32) return "ERROR";
        decpart *= 2;
        if(decpart >= 1){
            decstr += "1";
            decpart -= 1;
        }
        else
            decstr += "0";
    }
    return intstr + "." + decstr;
}
int main(){
    string val = "19.25";
    cout<<print_binary(val)<<endl;
    return 0;
}
