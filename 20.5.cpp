#include <iostream>
using namespace std;

const int kMaxInt = ~(1<<31);

int ShortestDist(string text[], int n, string word1, string word2){
    int min = kMaxInt / 2;
    int pos1 = -min;
    int pos2 = -min;

    for(int pos=0; pos<n; ++pos){
        if(text[pos] == word1){
            pos1 = pos;
            int dist = pos1 - pos2;
            if(dist < min)
                min = dist;
        }
        else if(text[pos] == word2){
            pos2 = pos;
            int dist = pos2 - pos1;
            if(dist < min)
                min = dist;
        }
    }

    return min;
}
int main(){
    string text[] = {
        "What","is","your","name","My","name","is","Hawstein"
    };
    int len = 8;
    cout<<ShortestDist(text, len, "is", "name")<<endl;
    return 0;
}
