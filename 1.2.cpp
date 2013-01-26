#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a, char &b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

void reverse2(char *s)
{
    int n = strlen(s);
    for(int i=0; i<n/2; ++i)
        swap(s[i], s[n-i-1]);
}

void reverse(char *s)
{
    char *end = s;
    char tmp;
    if(s)
    {
        while(*end)
            ++end;
        --end;
        while(s < end)
        {
            tmp = *s;
            *s++ = *end;
            *end-- = tmp;
        }
    }
}
int main()
{
    char s[] = "1234567890";
    reverse2(s);
    cout<<s<<endl;
    return 0;
    
}
