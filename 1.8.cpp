#include <iostream>
#include <string>
using namespace std;

bool isRotation(string s1, string s2)
{
    if(s1.length() != s2.length() || s1.length()<=0)
        return false;
    s1 += s1;
    if(s1.find(s2) >= 0) return true;
    else return false;
}

int main()
{
    string s1 = "a";
    string s2 = "a";
    cout<<isRotation(s1, s2);
    return 0;
}
